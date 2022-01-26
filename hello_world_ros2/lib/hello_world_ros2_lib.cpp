#include "hello_world_ros2_lib.h"

using namespace std;
using namespace rclcpp;

HelloWorldRos2::HelloWorldRos2() : Node("hello_world_ros2_node")
{
	string strTemp;
	int nTemp;
	vector<double> vecTemp;
	this->declare_parameter("my_str");
	this->declare_parameter("my_int");
	this->declare_parameter("my_double_array");
	this->get_parameter("my_str", strTemp);
	this->get_parameter("my_int", nTemp);
	this->get_parameter("my_double_array", vecTemp);
	cout << "param(my_str):" << strTemp << std::endl;
	cout << "param(my_int):" << nTemp << std::endl;
	cout << "param(my_double_array):" << vecTemp[0] << ", " << vecTemp[1] << ", " << vecTemp[2] << std::endl;	
}

HelloWorldRos2::~HelloWorldRos2()
{
}

void HelloWorldRos2::MainLoop()
{
  HelloFunction();
}

void HelloWorldRos2::HelloFunction()
{
	// standard type
	// RCLCPP_INFO(this->get_logger(), "[INFO]Hello, world! ROS2!");
	// RCLCPP_DEBUG(this->get_logger(), "[DEBUG]Hello, world! ROS2!");
	// RCLCPP_WARN(this->get_logger(), "[WARN]Hello, world! ROS2!");
	// RCLCPP_ERROR(this->get_logger(), "[ERROR]Hello, world! ROS2!");
	// RCLCPP_FATAL(this->get_logger(), "[FATAL]Hello, world! ROS2!");

	// throttle type
	auto steadyClock = rclcpp::Clock();  // [milliseconds]
	RCLCPP_INFO_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[INFO]Hello, world! ROS2!");
	RCLCPP_DEBUG_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[DEBUG]Hello, world! ROS2!");
	RCLCPP_WARN_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[WARN]Hello, world! ROS2!");
	RCLCPP_ERROR_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[ERROR]Hello, world! ROS2!");
	RCLCPP_FATAL_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[FATAL]Hello, world! ROS2!");				
}