import roboticstoolbox as rtb
import numpy as np
from spatialmath import SE3
from math import pi
import matplotlib.pyplot as plt

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

num_samples = 20000
workspace_points = []

joint_limits = [
    (-np.pi, np.pi),  # Joint 1
    (-np.pi, np.pi),  # Joint 2
    (-np.pi, np.pi),  # Joint 3
    (-np.pi, np.pi),  # Joint 4
    (-np.pi, np.pi),  # Joint 5
    (-np.pi, np.pi),  # Joint 6
]

for i in range(num_samples):
    q_random = [np.random.uniform(*joint_limits[j]) for j in range(robot.n)]
    T = robot.fkine(q_random)
    x, y, z = T.t[0], T.t[1], T.t[2]
    workspace_points.append([x, y, z])

workspace_points = np.array(workspace_points)

radii = np.linalg.norm(workspace_points, axis=1)

max_radius = np.max(radii)
min_radius = np.min(radii)

print(f"Max Radius: {max_radius}")
print(f"Min Radius: {min_radius}")

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.scatter(workspace_points[:, 0], workspace_points[:, 1], workspace_points[:, 2], s=1, c='b', alpha=0.5)
ax.set_xlabel('X axis')
ax.set_ylabel('Y axis')
ax.set_zlabel('Z axis')
ax.set_title('Robot Workspace')

plt.show()