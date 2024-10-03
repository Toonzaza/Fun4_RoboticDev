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
- [**teleop_twist_keyboard**](https://index.ros.org/p/teleop_twist_keyboard/)

## System Architecture
![image](https://media.discordapp.net/attachments/1281153207296327754/1291333087606603807/image.png?ex=66ffb727&is=66fe65a7&hm=c6ca543ee7bd96b8a27e4fc71bc47357ad2b3571ff5c87ce20bcf2c42edec5bb&=&format=webp&quality=lossless&width=2391&height=1106)

## Installation
Install & upgrade **python3-pip**.

    sudo apt-get install python3-pip
    python3 -m pip install --upgrade pip
    pip3 install -U pip

Install Robotics Toolbox for Python using pip3.

    pip3 install roboticstoolbox-python
For use Robotics Toolbox for Python have to use numpy < 1.25.0

    pip3 install numpy==1.24.4
    
Clone this workspace in to your terminal.

     git clone https://github.com/Toonzaza/Fun4_RoboticDev.git

Go to the project directory.

    cd Fun4_RoboticDev

Build and source this project.
   
    colcon build && source install/setup.bash

## Part 1: Setup Environment
For finding robot workspace of RRR robot.
1. Create the DH parameter of the RRR robot.
2. limit of q1 q2 q3 and sample all possible data that q1 q2 q3 can go to that position.
3. Use Loop for plot position to a graph.

![image](https://media.discordapp.net/attachments/1281153207296327754/1291447925762953387/image.png?ex=6700221b&is=66fed09b&hm=f476bcdee5872d488ca534de4784175faa4a606f26f54e58ba9a8238568cc50b&=&format=webp&quality=lossless&width=1113&height=1106)

You can try it by running the code. : work_space.py

    cd Fun4_RoboticDev/src/RoboticsDev2024/scripts

    code .

You can see position of target and position of end-effector in this picture.


![image](https://media.discordapp.net/attachments/1281153207296327754/1291454596128182332/image.jpg?ex=67002851&is=66fed6d1&hm=5624c44519fadc6153df7ffe34d6fbd7238651b1b4dbc1792db1b2d7f2161a98&=&format=webp&width=2208&height=1106)

## Part 2: Controller

Custom service

    Name : /set_mode
    
    Request : mode --> Enter mode 1-3.
                x  --> Enter qx
                y  --> Enter qy
                z  --> Enter qz
                
    Respond : state  --> Show current status

1. Inverse Pose Kinematics (IPK)

First you must run this command to open the launch file.

        ros2 launch fun4_pkg fun.launch.py

For IPK you must open new terminal and enter mode: 1 and enter qx qy qz in x y z.

        ros2 service call /set_mode fun4_interfaces/srv/Mode "mode: 1
        x: 0.0
        y: 0.05
        z: 0.3"

If you find the answer in taskspace.

![image](https://media.discordapp.net/attachments/1281153207296327754/1291465889253953556/image.png?ex=670032d6&is=66fee156&hm=e2e8d05ad3eef4e71f6cc1f9d13eadcf833ee3b0433ca556d52cd99df0fa581b&=&format=webp&quality=lossless&width=2462&height=622)

If answer not in taskspace.

2. Teleoperation

If you want to play this mode you must open new terminal and run this command

        ros2 run teleop_twist_keyboard teleop_twist_keyboard 

Commanding /cmd_vel in Teleoperation mode can be commanded in 2 modes:

Reference End-effector

        ros2 service call /set_mode fun4_interfaces/srv/Mode "mode: 2
        x: 0.0
        y: 0.0
        z: 0.0" 

Reference Base

        ros2 service call /set_mode fun4_interfaces/srv/Mode "mode: 2
        x: 1.0
        y: 0.0
        z: 0.0" 

And if while ordering the robot It then detects that the robot is approaching the Singularity condition.



