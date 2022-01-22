// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <chrono>
#include <functional>
#include <memory>
#include <random>

// essential header for ROS2 operation
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/vector3_stamped.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>

#define MINRANGE -100.0
#define MAXRANGE 100.0

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;

class PubAdvTestStdStyleRos2 : public Node
{
public:
  PubAdvTestStdStyleRos2(string strNodeNm);
  ~PubAdvTestStdStyleRos2();

private:
  Publisher<geometry_msgs::msg::Vector3Stamped>::SharedPtr pubVec3Stamp_;
	Publisher<geometry_msgs::msg::PointStamped>::SharedPtr pubPt_;
  rclcpp::TimerBase::SharedPtr timerVec3_;
	rclcpp::TimerBase::SharedPtr timerPt_;
	void CbPubTimerVec3();
	void CbPubTimerPt();

	Time prevTimeVec3_;
	Time prevTimePt_;

  size_t count_;

	std::random_device rd_{};
	std::mt19937 gen_{rd_()};	
};