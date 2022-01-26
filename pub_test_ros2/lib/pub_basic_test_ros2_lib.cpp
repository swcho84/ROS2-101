#include "pub_basic_test_ros2_lib.h"

using namespace std;
using namespace rclcpp;

PubBasicTestRos2::PubBasicTestRos2(string strNodeNm) : Node(strNodeNm)
{
	pubStr_ = this->create_publisher<std_msgs::msg::String>("/pub_basic_string", 1);
}

PubBasicTestRos2::~PubBasicTestRos2()
{
}

void PubBasicTestRos2::MainLoop()
{
	auto msgStr = std_msgs::msg::String();
	msgStr.data = "Hello, world! " + std::to_string(count_++);
	RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msgStr.data.c_str());
	pubStr_->publish(msgStr);	
}
