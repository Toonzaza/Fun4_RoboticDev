# 3 DOF Robot Controller Simulation : Hello World
This repository features a simulation of a 3 Degrees of Freedom (DOF) robotic arm controller. The objective of the project is to simulate the control of a 3 DOF robotic arm,
enabling it to reach a desired setpoint by regulating the joint velocities using Jacobian matrices.

## Project Overview
- This simulation project uses the Robotics Toolbox for Python to modeland control a 3 DOF robot.
- Generating a robot model using the xacro urdf file.
- Visualized the robot model in RVIZ2.
- Controlling the robot's end-effector by computing joint velocities using the Jacobian.

## Features
- Controlling the robot's end-effector by Jacobian.
- The robot can be controlled in 3 modes:
    - Control by specifying a target position
    - Control using teleop_twist_keyboard
    - Control by random target position selection

## Prerequisites
To run this project, ensure you have the following installed:
- [**ROS2 Humble** (or your preferred ROS2 distribution)](https://docs.ros.org/en/humble/Installation.html)
- **Colcon build system**
- **Python 3.8+**
- [**Robotics Toolbox for Python**](https://petercorke.github.io/robotics-toolbox-python/)
- [**RVIZ2**](https://docs.ros.org/en/humble/Tutorials/Intermediate/RViz/RViz-Main.html)
- [**geometry2 tf2_ros**](https://github.com/ros2/geometry2)
- [**robot_state_publisher package**](https://github.com/ros/robot_state_publisher)

## System Architecture
![image](https://media.discordapp.net/attachments/1281153207296327754/1291333087606603807/image.png?ex=66ffb727&is=66fe65a7&hm=c6ca543ee7bd96b8a27e4fc71bc47357ad2b3571ff5c87ce20bcf2c42edec5bb&=&format=webp&quality=lossless&width=2391&height=1106)

## Installation

