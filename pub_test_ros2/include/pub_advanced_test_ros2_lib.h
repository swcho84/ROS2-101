// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <random>

// essential header for ROS2 operation
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/multi_array_dimension.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

#define MINRANGE -100.0
#define MAXRANGE 100.0

using namespace std;
using namespace rclcpp;

class PubAdvancedTestRos2 : public Node
{
public:
  PubAdvancedTestRos2(string strNodeNm);
  ~PubAdvancedTestRos2();

  void MainLoop();

private:
  Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr pubF64MtArr_;

	std::random_device rd_{};
	std::mt19937 gen_{rd_()};
};