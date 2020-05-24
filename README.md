# 4-wheel-differential-car-ros
A four-wheel differential drive car in Gazebo with navigation, SLAM, and voice control<br>
## Environment
Ubuntu 16.04<br>
## Download
git clone https://github.com/Wangbaiyue007/4-wheel-differential-car-ros.git <br>
## Open robot in Gazebo and take control
catkin_make<br>
roslaunch carmodel_description 02-drive.launch<br>
roslaunch carmodel_teleop carmodel_teleop_key.launch<br>
## Reference
https://github.com/ROSClub/mrobot.git<br>
