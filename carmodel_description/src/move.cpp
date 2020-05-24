#include "ros/ros.h"  
#include "geometry_msgs/Twist.h"  
 
  
int main(int argc, char **argv)  
{  
    ros::init(argc,argv,"move");  
    ros::NodeHandle n;  
    // 需要发布一个 /cmd_vel主题 根据实际情况来定
    ros::Publisher vel_pub = n.advertise<geometry_msgs::Twist>("/cmd_vel",1);  
  
    unsigned char rate;  
    rate = 50;  
    ros::Rate loop_rate(rate);  
    geometry_msgs::Twist msg;  
  
    // 让小车一直前进,x有值，剩下的都是0
    while (ros::ok())  
    {                   
        msg.linear.x = 0.2; 
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        msg.angular.x = 0.0;
        msg.angular.y = 0.0;
        msg.angular.z = 0.0;
        
        vel_pub.publish(msg);  
        ros::spinOnce();  
        loop_rate.sleep();
        ROS_INFO("%s", "running the robot ...");          
    }     
    return 0;  
}  
