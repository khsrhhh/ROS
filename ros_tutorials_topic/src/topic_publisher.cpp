#include "ros/ros.h"
#include "ros_tutorials_topic/MsgTutorial.h"

int main(int argc, char** argv)
{
	ros::init(argc, argv, "topic_publisher");
	ros::NodeHandle nh;

	//publisher declare. Using MsgTutorial file of ros_tutorials_topic
	//publisher: ros_tutorial_pub
	//topic name: ros_tutorial_msg"
	//set publisher queue size to 100
	ros::Publisher ros_tutorial_pub = nh.advertise<ros_tutorials_topic::MsgTutorial>("ros_tutorial_msg", 100);

	//10 means 10Hz, 1/10 second
	ros::Rate loop_rate(10);

	//declare msg, MsgTutorial type
	ros_tutorials_topic::MsgTutorial msg;
	int count = 0;

	while(ros::ok())
	{
		msg.stamp = ros::Time::now();
		msg.data = count;

		ROS_INFO("send msg = %d", msg.stamp.sec);
		ROS_INFO("send msg = %d", msg.stamp.nsec);
		ROS_INFO("send msg = %d", msg.data);

		ros_tutorial_pub.publish(msg);	//publish msg

		loop_rate.sleep();

		++count;

	}

	return 0;
}
