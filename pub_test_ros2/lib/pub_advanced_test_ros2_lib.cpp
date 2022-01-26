#include "pub_advanced_test_ros2_lib.h"

using namespace std;
using namespace rclcpp;

PubAdvTestRos2::PubAdvTestRos2(string strNodeNm) : Node(strNodeNm)
{
	pubF64MtArr_ = this->create_publisher<std_msgs::msg::Float64MultiArray>("/pub_advanced_float64_multiarray", 1);
}

PubAdvTestRos2::~PubAdvTestRos2()
{
}

void PubAdvTestRos2::MainLoop()
{
	auto msgF64MtArr = std_msgs::msg::Float64MultiArray();
	std::uniform_real_distribution<double> distr(MINRANGE, MAXRANGE);

	msgF64MtArr.layout.dim.push_back(std_msgs::msg::MultiArrayDimension());
	msgF64MtArr.layout.dim[0].size = 3;
	msgF64MtArr.layout.dim[0].label = "random_number";
	msgF64MtArr.data.resize(3);
	msgF64MtArr.data[0] = distr(gen_);
	msgF64MtArr.data[1] = distr(gen_);
	msgF64MtArr.data[2] = distr(gen_);		
	pubF64MtArr_->publish(msgF64MtArr);

	auto steadyClock = rclcpp::Clock();  // [milliseconds]
	RCLCPP_INFO_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[RandDouble]published...");
}

