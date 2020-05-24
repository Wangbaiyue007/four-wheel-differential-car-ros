#include <string>
#include <ros/ros.h>
#include <sensor_msgs/JointState.h>
#include <tf/transform_broadcaster.h>

int main(int argc, char** argv) {
    ros::init(argc, argv, "state_publisher");
    ros::NodeHandle n;
    ros::Publisher joint_pub = n.advertise<sensor_msgs::JointState>("joint_states", 1);
    tf::TransformBroadcaster broadcaster;
    ros::Rate loop_rate(30);

    const double degree = M_PI/180;

    // robot state
    double start=0, speed=0, maxspeed=300;

    // message declarations
    geometry_msgs::TransformStamped odom_trans;
    sensor_msgs::JointState joint_state;
    odom_trans.header.frame_id = "odom";
    odom_trans.child_frame_id = "base_link";
    int mode=0;
    double cv=speed;
    while (ros::ok()) {
        //update joint_state
        joint_state.header.stamp = ros::Time::now();
        joint_state.name.resize(4);
        joint_state.velocity.resize(4);
        joint_state.name[0] ="joint_base_wheel1";
        joint_state.name[1] ="joint_base_wheel2";
        joint_state.name[2] ="joint_base_wheel3";
        joint_state.name[3] ="joint_base_wheel4";
	joint_state.velocity[0]=cv;
	joint_state.velocity[1]=cv;
	joint_state.velocity[2]=cv;
	joint_state.velocity[3]=cv;

        // update transform
        // (moving in a circle with radius=2)

        //send the joint state and transform
        joint_pub.publish(joint_state);
        broadcaster.sendTransform(odom_trans);

        // Create new robot state
        if(mode ==0){
		mode=1;
		cv=maxspeed;
	}
	else{
	mode=0;
	cv=speed;
}

        // This will adjust as needed per iteration
        loop_rate.sleep();
    }


    return 0;
}
