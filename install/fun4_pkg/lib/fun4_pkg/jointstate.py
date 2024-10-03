#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped
import roboticstoolbox as rtb
from spatialmath import SE3
from math import pi
import numpy as np
from example_interfaces.msg import Int64

class JointstateNode(Node):
    def __init__(self):
        super().__init__('jointstate_node')
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        self.create_subscription(PoseStamped, '/target', self.target_callback, 10)
        self.toggle_publisher = self.create_publisher(Int64, '/toggle_mode', 10)
        self.create_subscription(Int64, '/toggle_mode', self.toggle_callback, 10)

        self.freq = 100.0
        self.create_timer(1.0/self.freq, self.sim_loop)
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.current_position = [0.0, 0.0, 0.0]
        self.target_position = [0.0, 0.0, 0.0]
        self.init_q = [0.0, 0.0, 0.0]
        self.q = [0.0, 0.0, 0.0]
        self.kp = 1
        self.can_do = False  # ใช้ควบคุมให้หยุดคำนวณเมื่อถึงเป้าหมาย
        self.count = 0
        self.mode = 0
        self.must_do = False

    def toggle_callback(self,msg : Int64):
        if msg.data == 1:
            self.mode = 1
            self.must_do = True

        elif msg.data == 3:
            self.mode = 3
            self.must_do = True
        else:
            self.must_do = False
    
    def target_callback(self, msg: PoseStamped):
        self.target_position = [msg.pose.position.x, msg.pose.position.y, msg.pose.position.z]
        self.can_do = True

    def robot_description(self):
        """ Define the robot description using DH parameters """
        L1 = 0.200
        L2 = 0.120
        L3 = 0.100
        L4 = 0.250
        L5 = 0.280

        robot = rtb.DHRobot(
            [
                rtb.RevoluteMDH(alpha=0.0, a=0.0, d=L1, offset=0.0),
                rtb.RevoluteMDH(alpha=-pi/2, a=0.0, d=-L2, offset=-pi/2),
                rtb.RevoluteMDH(alpha=0.0, a=L4, d=L3, offset=0.0),
            ], 
            tool=SE3([
                [0, 0, 1, L5],
                [1, 0, 0, 0],
                [0, 1, 0, 0],
                [0, 0, 0, 1]]),
            name="RRR_Robot"
        )
        return robot

    def sim_loop(self):
        if self.must_do:
            if self.can_do:  # ตรวจสอบว่าให้คำนวณได้หรือไม่
                p_0e = self.robot_description().fkine(self.init_q).t[:3]  # ตำแหน่งปัจจุบัน

                error = np.array(self.target_position) - p_0e  # ข้อผิดพลาดระหว่างตำแหน่งเป้าหมายกับตำแหน่งปัจจุบัน
                self.get_logger().info(f"Error: {error}")

                # ตรวจสอบว่า error น้อยกว่าค่าที่กำหนด (0.01) ในทุกแกนเพื่อหยุดการเคลื่อนไหว

                # คำนวณ Jacobian และการเปลี่ยนแปลงมุมข้อต่อ (q_dot)
                matrix_3x6 = self.robot_description().jacob0(self.init_q)
                matrix_3x3 = matrix_3x6[:3, :3]
                
                q_dot = np.linalg.pinv(matrix_3x3).dot(error)
                self.init_q += q_dot * 1/self.freq  # อัปเดตมุมข้อต่อ

                if np.linalg.norm(error < 0.01) and self.can_do : 
                    self.get_logger().info("Target reached, stopping movement.")
                    self.can_do = False  # หยุดการคำนวณเมื่อถึงตำแหน่งเป้าหมาย
                    if self.mode == 3:
                        msg = Int64()
                        msg.data = 3
                        self.toggle_publisher.publish(msg)
                        self.mode = 0  



                # ส่งค่า JointState ที่อัพเดตแล้วไปยัง ROS
                self.msg = JointState()
                for i in range(len(q_dot)):
                    self.q[i] += q_dot[i] * (1 / self.freq)
                    self.msg.position.append(self.q[i])  # เพิ่มค่ามุมข้อต่อ
                    self.msg.name.append(self.name[i])  # ชื่อข้อต่อ
                
                self.msg.header.stamp = self.get_clock().now().to_msg()
                self.joint_pub.publish(self.msg)

def main(args=None):
    rclpy.init(args=args)
    node = JointstateNode()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
