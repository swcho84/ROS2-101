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

using namespace std;
using namespace rclcpp;

class SubAdvancedTestRos2 : public Node
{
public:
  SubAdvancedTestRos2(string strNodeNm);
  ~SubAdvancedTestRos2();

private:
  Subscription<std_msgs::msg::Float64MultiArray>::SharedPtr subF64Mt_;
  void CbF64Mt(const std_msgs::msg::Float64MultiArray::SharedPtr msg);
};