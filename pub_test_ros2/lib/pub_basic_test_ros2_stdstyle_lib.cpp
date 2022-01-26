#include "pub_basic_test_ros2_stdstyle_lib.h"

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;

PubBasicTestStdStyleRos2::PubBasicTestStdStyleRos2(string strNodeNm) : Node(strNodeNm)
{
	pubStr_ = this->create_publisher<std_msgs::msg::String>("/pub_basic_string_stdstyle", 1);
	timer_ = this->create_wall_timer(30ms, bind(&PubBasicTestStdStyleRos2::CbPubTimer, this));	
	count_ = 0;
}

PubBasicTestStdStyleRos2::~PubBasicTestStdStyleRos2()
{
}

void PubBasicTestStdStyleRos2::CbPubTimer()
{
	auto msg = std_msgs::msg::String();
	msg.data = "Hello, world! " + std::to_string(count_++);
	RCLCPP_INFO(this->get_logger(), "[CbTimer]Publishing: '%s'", msg.data.c_str());
	pubStr_->publish(msg);
}