#include "sub_basic_test_ros2_lib.h"

using namespace std;
using namespace rclcpp;
using std::placeholders::_1;

SubBasicTestRos2::SubBasicTestRos2(string strNodeNm) : Node(strNodeNm)
{
	subStr_ = this->create_subscription<std_msgs::msg::String>("/pub_basic_string", 1, std::bind(&SubBasicTestRos2::CbStr, this, _1));
}

SubBasicTestRos2::~SubBasicTestRos2()
{
}

void SubBasicTestRos2::CbStr(const std_msgs::msg::String::SharedPtr msg) const
{
	RCLCPP_INFO(this->get_logger(), "[CallBack]I heard: '%s'", msg->data.c_str());	
}
