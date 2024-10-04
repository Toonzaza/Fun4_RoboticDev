#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import JointState
from geometry_msgs.msg import PoseStamped,Twist
import roboticstoolbox as rtb
from spatialmath import SE3
from math import pi
import numpy as np
from example_interfaces.msg import Int64
from tf2_ros import TransformListener, Buffer

class JointstateNode(Node):
    def __init__(self):
        super().__init__('jointstate_node')
        self.joint_pub = self.create_publisher(JointState, "/joint_states", 10)
        # self.toggle_publisher = self.create_publisher(Int64, '/toggle_mode', 10)
        self.create_subscription(Int64, '/toggle_mode', self.toggle_callback, 10)
        self.create_subscription(Twist,'/cmd_vel', self.cmd_vel_callback,10)

        self.freq = 100.0
        self.create_timer(1.0/self.freq, self.timer_callback)
        self.name = ["joint_1", "joint_2", "joint_3"]
        self.current_position = [0.0, 0.0, 0.0]
        self.target_position = [0.0, 0.0, 0.0]
        self.init_q = [0.0, 0.0, 0.0]
        self.q = [0.0, 0.0, 0.0]
        self.kp = 1
        self.must_do = False  
        self.count = 0
        self.mode = 0
        self.p_dot = [0.0, 0.0, 0.0]
        self.singularity_thres = 0.000001
        self.diff = 0.0
        # self.robot

    def toggle_callback(self,msg : Int64):
        if msg.data == 21: # respect to base
            self.mode = 1
            self.msg = JointState()
            self.q = [0.2, 0.3, 0.4]
            self.joint_pub.publish(self.msg)
            self.must_do = True
        elif msg.data == 22: # respect to end-effctor
            self.mode = 2 
            self.msg = JointState()
            self.q = [0.2, 0.3, 0.4]
            self.joint_pub.publish(self.msg)
            self.must_do = True
        else:
            self.must_do = False

    def cmd_vel_callback(self, msg:Twist):
        self.p_dot = [msg.linear.x, msg.linear.y,msg.linear.z]
    
    def robot_description(self):
        """ Define the robot description using DH parameters """
        L1 = 0.200
        L2 = 0.120
        L3 = 0.100
        L4 = 0.250
        L5 = 0.280

        self.robot = rtb.DHRobot(
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
        return self.robot


    def timer_callback(self):
        p_0e = self.robot_description().fkine(self.init_q).t[:3]
        T_0e = self.robot_description().fkine(self.init_q)
        r_0e = T_0e.R
        matrix_3x6 = self.robot_description().jacob0(self.init_q)
        matrix_3x3 = matrix_3x6[:3, :3]
        J_full = self.robot.jacob0(self.q)
        manipulability = np.linalg.det(J_full @ J_full.T)
        # self.get_logger().info(f"Manipulability: {manipulability}")
        
        
        self.J_pos = J_full[0:3, :]
        self.det_J = np.linalg.det(self.J_pos)
        self.det_threshold = 1e-5
        # self.get_logger().info(str(self.det_J))



        if self.must_do:
            
            if abs(self.det_J) < self.det_threshold:
                self.get_logger().info(f"Near a singularity")
                self.p_dot = [0.0, 0.0, 0.0]
            
            if self.mode == 1:
                q_dot = np.linalg.pinv(matrix_3x3).dot(self.p_dot)
                self.init_q += q_dot * 1/self.freq
                self.msg = JointState()
                for i in range(len(q_dot)):
                    self.q[i] += q_dot[i] * (1 / self.freq)
                    self.msg.position.append(self.q[i])
                    self.msg.name.append(self.name[i])

                self.msg.header.stamp = self.get_clock().now().to_msg()
                self.joint_pub.publish(self.msg)

            elif self.mode == 2:
                q_dot = np.linalg.pinv(matrix_3x3).dot(r_0e @ self.p_dot)
                self.init_q += q_dot * 1/self.freq
                self.msg = JointState()
                for i in range(len(q_dot)):
                    self.q[i] += q_dot[i] * (1 / self.freq)
                    self.msg.position.append(self.q[i])
                    self.msg.name.append(self.name[i])

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
