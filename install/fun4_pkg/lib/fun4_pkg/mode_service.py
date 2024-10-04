#!/usr/bin/python3

import rclpy
from rclpy.node import Node
from fun4_interfaces.srv import Mode
from geometry_msgs.msg import PoseStamped
from example_interfaces.msg import Int64
from std_msgs.msg import String 
import sys

class ModeService(Node):
    def __init__(self):
        super().__init__('mode_service')
        self.srv = self.create_service(Mode, '/set_mode', self.mode_callback)
        self.toggle_publisher = self.create_publisher(Int64, '/toggle_mode', 10)
        self.pose_publisher = self.create_publisher(PoseStamped,'/IPK_pose', 10)
        self.pose_end_pub = self.create_publisher(PoseStamped, "/target", 10)
        self.freq = 100.0


        self.x =0.0
        self.y =0.0
        self.z =0.0
        self.can_do = False

    def mode_callback(self, request, response):

        state_msg = String()
        if request.mode == 1:
            msg = Int64()
            msg.data = 1
            self.toggle_publisher.publish(msg)

            self.x = request.x
            self.y = request.y
            self.z = request.z

            r_min = 0.03
            r_max = 0.530
            distance_squared = self.x**2 + self.y**2 + (self.z-0.2)**2

            if r_min**2 <= distance_squared <= r_max**2:
                msg_pos = PoseStamped()
                msg_pos.pose.position.x = request.x
                msg_pos.pose.position.y = request.y
                msg_pos.pose.position.z = request.z

                self.pose_publisher.publish(msg_pos)

                self.get_logger().info(f"Published target pose: x={self.x}, y={self.y}, z={self.z}")
                state_msg.data = "True : Mode 1: IPK"
            else:
                state_msg.data = "False : OUT OF WORKSPACE"
        
        elif request.mode == 2 and request.x == 1.0:
            msg = Int64()  
            msg.data = 21
            self.toggle_publisher.publish(msg)  
            state_msg.data = "Mode 2: Teleop End-Effector"

        elif request.mode == 2 and request.x == 0.0:
            msg = Int64()  
            msg.data = 22
            self.toggle_publisher.publish(msg)  
            state_msg.data = "Mode 2: Teleop Base"
        
        elif request.mode == 3:
            msg = Int64()
            msg.data = 3
            self.toggle_publisher.publish(msg)
            state_msg.data = "Mode 3: Auto"
        
        else:
            state_msg.data = "NOT HAVE THIS MODE"
        
        response.state = state_msg
        return response
    


def main(args=None):
    rclpy.init(args=args)
    node = ModeService()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
