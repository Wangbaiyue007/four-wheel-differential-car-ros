steps to use voice control:
1. cd ~/<WORKSPACE>/src/4-wheel-differential-car-ros/carmodel_voice/libs/x64/
    (replace <WORKSPACE> with your workspace name)
    (if your Ubuntu is 32-bit, replace x64 with x86)
2. sudo cp libmsc.so /usr/lib/
3. cd ~/<WORKSPACE>
    (replace <WORKSPACE> with your workspace name)
4. catkin_make
5. source devel/setup.bash
6. roscore
7. roslaunch carmodel_description 02-drive.launch
8. rosrun carmodel_voice iat_publish
    (This program can recognize your voice in Chinese or English. This program can do one time recognition per 5 seconds.)
9. rosrun carmodel_voice voice_cmd
    (This program can receive the message from iat_publish and recognize the valid command, then send message to Gazebo. The valid command starts with "Robot", contains following operation: "forward", "back", "left", "right" or "stop", and do not contains "don't" or "not".)
