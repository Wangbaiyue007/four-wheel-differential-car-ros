# 4-wheel-differential-car-ros

A four-wheel differential drive car in Gazebo with navigation, SLAM, and voice control

## Environment

Ubuntu 16.04

## Download

    git clone https://github.com/Wangbaiyue007/4-wheel-differential-car-ros.git

## Open robot in Gazebo and take control

    catkin_make  
    roslaunch carmodel_description 02-drive.launch  
    roslaunch carmodel_teleop carmodel_teleop_key.launch

![coordinate](/carmodel/coordsystems_img.png)

### SLAM

Close all.

    roslaunch carmodel_slam carmodel_slam.launch
    roslaunch carmodel_teleop carmodel_teleop_key.launch

Drive the robot around and draw a map.

    cd $(where you save your map)
    rosrun map_server map_saver -f $(YOUR_MAP_NAME)

The map with **YOUR_MAP_NAME** will be saved as a **.pgm** and a **.yaml** file.

### Navigation

#### 1. Fake navigation

Close all.

    roslaunch carmodel_nav fake_carmodel.launch
    roslaunch carmodel_nav fake_amcl.launch

Or you can choose the saved map:

    roslaunch carmodel_nav fake_amcl.launch map:=$(YOUR_MAP_NAME).yaml

#### 2. Gazebo navigation

Close all.

    roslaunch carmodel_description 02-drive.launch
    roslaunch carmodel_nav nav_mymap_demo.launch

Use the 2D navigation arrow to navigate the robot in the *turtlebot map*.  
![navigation](/carmodel/navigation.png)

## Reference

[mrobot](https://github.com/ROSClub/mrobot.git)  
[turtlebot](https://github.com/ROBOTIS-GIT/turtlebot3.git)  
[rbx1](https://github.com/pirobot/rbx1.git)
