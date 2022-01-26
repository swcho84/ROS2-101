#include "sub_advanced_test_ros2_lib.h"

using namespace std;
using namespace rclcpp;
using std::placeholders::_1;

SubAdvancedTestRos2::SubAdvancedTestRos2(string strNodeNm) : Node(strNodeNm)
{
	auto qos = rclcpp::QoS(rclcpp::KeepLast(1)).best_effort();
	subF64MtArr_ = this->create_subscription<std_msgs::msg::Float64MultiArray>("/pub_advanced_float64_multiarray", qos, std::bind(&SubAdvancedTestRos2::CbF64Mt, this, _1));
	pubF64_ = this->create_publisher<std_msgs::msg::Float64>("/pub_advanced_float64", 1);
}

SubAdvancedTestRos2::~SubAdvancedTestRos2()
{
}

void SubAdvancedTestRos2::CbF64Mt(const std_msgs::msg::Float64MultiArray::SharedPtr msg)
{
	RCLCPP_INFO(this->get_logger(), "[CallBack](%.4lf, %.4lf, %.4lf)", msg->data[0], msg->data[1], msg->data[2]);	

	auto msgF64 = std_msgs::msg::Float64();
	msgF64.data = msg->data[0];
	pubF64_->publish(msgF64);
}
