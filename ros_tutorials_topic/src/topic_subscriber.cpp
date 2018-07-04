#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

//declare message callback function.
//callback when recieve ros_turotial_msg topic
//input message: MsgTutorial message of ros_tutorials_topic
void msgCallback(const ros_tutorials_topic::MsgTutorial::ConstPtr& msg)
{
	ROS_INFO("recieve msg = %d", msg->stamp.sec);
	ROS_INFO("recieve msg = %d", msg->stamp.nsec);
	ROS_INFO("recieve msg = %d", msg->data);
}

int main(int argc, char** argv)
{
	ros::init(argc, argv, "topic_subscriber");
	ros::NodeHandle nh;

	//declare subscriber. Using MsgTutorial message file of ros_tutorials_topic
	//subscriber: ros_tutorial_sub
	//topic name: ros_tutorial_msg
	//set subscriver queue size to 100
	ros::Subscriber ros_tutorial_sub = nh.subscribe("ros_tutorial_msg", 100, msgCallback);

	//wait until recieve message, and after recieve, start callback function
	ros::spin();

	return 0;
}
