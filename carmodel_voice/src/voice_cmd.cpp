#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/String.h>
#include <pthread.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
ros::Publisher pub;
geometry_msgs::Twist vel_cmd;
pthread_t pth_[5];

void *vel_ctr(void *arg)
{
    while (true)
    {
        pub.publish(vel_cmd);
        //cout << "linear.x: " << vel_cmd.linear.x << endl;
        //cout << "angular.z: " << vel_cmd.angular.z << endl;
        ros::spinOnce();
        sleep(1);
    }
    return 0;
}

int operation(string str)
{
    string str1 = "Robot";
    string str2 = "forward";
    string str3 = "back";
    string str4 = "left";
    string str5 = "right";
    string str6 = "stop";
    string str7 = "not";
    string str8 = "don't";
    if (str.find(str1) != string::npos && str.find(str7) == string::npos && str.find(str8) == string::npos)
    {
        if (str.find(str2) != string::npos)
            return 1;
        else if (str.find(str3) != string::npos)
            return 2;
        else if (str.find(str4) != string::npos)
            return 3;
        else if (str.find(str5) != string::npos)
            return 4;
        else if (str.find(str6) != string::npos)
            return 5;
        else
            return 0;
    }
    else
        return 0;
}

//void callback(const package_name::type_name & msg)
void callback(const std_msgs::String::ConstPtr &msg)
{
    cout << "收到：" << msg->data.c_str() << endl;
    string str = msg->data.c_str();
    int op = operation(str);
    if (op == 1)
    {
        cout << "go forward" << endl;
        vel_cmd.linear.x = 0.1;
        vel_cmd.angular.z = 0;
        pthread_create(&pth_[0], NULL, vel_ctr, NULL);
    }
    else if (op == 2)
    {
        cout << "go back" << endl;
        vel_cmd.linear.x = -0.1;
        vel_cmd.angular.z = 0;
        pthread_create(&pth_[1], NULL, vel_ctr, NULL);
    }
    else if (op == 3)
    {
        cout << "turn left" << endl;
        vel_cmd.linear.x = 0.2;
        vel_cmd.angular.z = 1;
        pthread_create(&pth_[2], NULL, vel_ctr, NULL);
    }
    else if (op == 4)
    {
        cout << "turn right" << endl;
        vel_cmd.linear.x = 0.2;
        vel_cmd.angular.z = -1;
        pthread_create(&pth_[3], NULL, vel_ctr, NULL);
    }
    else if (op == 5)
    {
        cout << "stop" << endl;
        vel_cmd.linear.x = 0;
        vel_cmd.angular.z = 0;
        pthread_create(&pth_[4], NULL, vel_ctr, NULL);
    }
    else if (op == 0)
        cout << "invalid command" << endl;
}

int main(int argc, char **argv)
{

    ros::init(argc, argv, "sub_word");
    ros::NodeHandle n;
    //pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop",10);
    //pub = n.advertise<geometry_msgs::Twist>("/mobile_base/mobile_base_controller/cmd_vel",1000);
    pub = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

    ros::Subscriber sub = n.subscribe("/voiceWords", 10, callback);
    //    ros::Subscriber sub = n.subscribe("read",10,callback);
    //ros::Publisher pub = n.advertise<geometry_msgs::Twist>("/cmd_vel_mux/input/teleop", 10);

    cout << "您好！你可以语音控制啦！" << endl;

    ros::spin();
}
