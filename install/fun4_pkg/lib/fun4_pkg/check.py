#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from example_interfaces.msg import Int64

class Check_Node(Node):
    def __init__(self):
        super().__init__('check_target')
        self.pose_end_pub = self.create_publisher(PoseStamped, "/target", 10)
        self.create_subscription(Int64, '/toggle_mode', self.toggle_callback, 10)
        self.toggle_publisher = self.create_publisher(Int64, '/toggle_mode', 10)
        self.create_subscription(PoseStamped, '/IPK_pose', self.IPK_pose_callback, 10)
        self.create_subscription(PoseStamped, '/random_pose', self.random_pose_callback, 10)
        self.dt = 0.01
        self.create_timer(self.dt, self.check_target)
        self.x = 0.0
        self.y = 0.0
        self.z = 0.0
        self.mode = 0
        self.current_mode = None  

    
    def toggle_callback(self,msg:Int64):
        self.mode = msg.data


    def toggle_callback(self, msg: Int64):
        # อัพเดตค่า current_mode
        if msg.data == 1:
            self.get_logger().info("Receiving IPK pose data...")
        elif msg.data == 3:
            self.get_logger().info("Receiving random pose data...")
        self.current_mode = msg.data  # เก็บค่า mode ที่ได้รับ

    def IPK_pose_callback(self, msg: PoseStamped):
        # เช็คว่า current_mode คือ 1 หรือไม่
        if self.current_mode == 1:
            self.x = msg.pose.position.x
            self.y = msg.pose.position.y
            self.z = msg.pose.position.z
            self.get_logger().info(f"IPK Pose: x={self.x}, y={self.y}, z={self.z}")

    def random_pose_callback(self, msg: PoseStamped):
        if self.current_mode == 3:
            self.x = msg.pose.position.x
            self.y = msg.pose.position.y
            self.z = msg.pose.position.z
            self.get_logger().info(f"Random Pose: x={self.x}, y={self.y}, z={self.z}")

    def check_target(self):
        r_min = 0.03
        r_max = 0.530

        distance_squared = self.x**2 + self.y**2 + (self.z-0.2)**2

        if r_min**2 <= distance_squared <= r_max**2:
            msg = PoseStamped()
            msg.header.stamp = self.get_clock().now().to_msg()
            msg.header.frame_id = "link_0"

            msg.pose.position.x = self.x
            msg.pose.position.y = self.y
            msg.pose.position.z = self.z

            msg.pose.orientation.x = 0.0
            msg.pose.orientation.y = 0.0
            msg.pose.orientation.z = 0.0
            msg.pose.orientation.w = 1.0  

            self.pose_end_pub.publish(msg)
            self.get_logger().info(f"Published target pose: x={self.x}, y={self.y}, z={self.z}")
        else:
            if self.mode == 1:
                self.get_logger().info(f"OUT OF WORKSPACE")
            else:
                msg = Int64()
                msg.data = 3
                self.toggle_publisher.publish(msg)
                self.mode = 0


def main(args=None):
    rclpy.init(args=args)
    node = Check_Node()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
