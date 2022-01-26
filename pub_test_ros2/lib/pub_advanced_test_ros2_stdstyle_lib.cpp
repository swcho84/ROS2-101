#include "pub_advanced_test_ros2_stdstyle_lib.h"

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;

PubAdvTestStdStyleRos2::PubAdvTestStdStyleRos2(string strNodeNm) : Node(strNodeNm)
{
	pubVec3Stamp_ = this->create_publisher<geometry_msgs::msg::Vector3Stamped>("/pub_vec3stamp", 1);
	timerVec3_ = this->create_wall_timer(30ms, bind(&PubAdvTestStdStyleRos2::CbPubTimerVec3, this));	

	pubPt_ = this->create_publisher<geometry_msgs::msg::PointStamped>("/pub_ptstamp", 1);
	timerPt_ = this->create_wall_timer(10ms, bind(&PubAdvTestStdStyleRos2::CbPubTimerPt, this));	

	count_ = 0;
	prevTimeVec3_ = this->get_clock()->now();
	prevTimePt_ = this->get_clock()->now();
}

PubAdvTestStdStyleRos2::~PubAdvTestStdStyleRos2()
{
}

void PubAdvTestStdStyleRos2::CbPubTimerVec3()
{
	auto currTime = this->get_clock()->now();
	double dt = (currTime - prevTimeVec3_).seconds();
	auto msgVec3Stamp = geometry_msgs::msg::Vector3Stamped();
	std::uniform_real_distribution<double> distr(MINRANGE, MAXRANGE);

	msgVec3Stamp.header.stamp = this->get_clock()->now();
	msgVec3Stamp.vector.x = distr(gen_);
	msgVec3Stamp.vector.y = distr(gen_);
	msgVec3Stamp.vector.z = distr(gen_);		
	pubVec3Stamp_->publish(msgVec3Stamp);

	auto steadyClock = rclcpp::Clock();  // [milliseconds]
	cout << "[RandVec3]dt:" << dt << "[sec]" << std::endl;
	RCLCPP_INFO_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[RandVec3]published...");	
	prevTimeVec3_ = this->get_clock()->now();
}

void PubAdvTestStdStyleRos2::CbPubTimerPt()
{
	auto currTime = this->get_clock()->now();	
	double dt = (currTime - prevTimePt_).seconds();	
	auto msgPtStamp = geometry_msgs::msg::PointStamped();
	std::uniform_real_distribution<double> distr(MINRANGE, MAXRANGE);

	msgPtStamp.header.stamp = this->get_clock()->now();
	msgPtStamp.point.x = distr(gen_);
	msgPtStamp.point.y = distr(gen_);
	msgPtStamp.point.z = distr(gen_);		
	pubPt_->publish(msgPtStamp);

	auto steadyClock = rclcpp::Clock();  // [milliseconds]
	cout << "[RandPt]dt:" << dt << "[sec]" << std::endl;	
	RCLCPP_INFO_STREAM_THROTTLE(this->get_logger(), steadyClock, 1000, "[RandPt]published...");
	prevTimePt_ = this->get_clock()->now();
}