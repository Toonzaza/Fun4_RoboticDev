#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from example_interfaces.msg import Int64
import numpy as np

class Random(Node):
    def __init__(self):
        super().__init__('random_node')
        self.pose_pub = self.create_publisher(PoseStamped, "/random_pose", 10)
        self.create_subscription(Int64, '/toggle_mode', self.toggle_callback, 10)

    def toggle_callback(self, msg: Int64):
        if msg.data == 3:
            self.sim_loop() 

    def sim_loop(self):
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = "link_0"

        # สุ่มค่าตำแหน่ง x, y, z
        position = self.generate_random_position()

        msg.pose.position.x = position[0]
        msg.pose.position.y = position[1]
        msg.pose.position.z = position[2]

        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0
        msg.pose.orientation.w = 0.0

        # ส่งข้อความ PoseStamped
        self.pose_pub.publish(msg)

    def generate_random_position(self):
        r_min = 0.03
        r_max = 0.530

        x = np.random.uniform(-r_max, r_max)
        y = np.random.uniform(-r_max, r_max)
        z = np.random.uniform(-r_max, r_max)
        return [x, y, z]

def main(args=None):
    rclpy.init(args=args)
    node = Random()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
