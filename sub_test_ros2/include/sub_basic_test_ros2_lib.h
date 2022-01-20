// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>

// essential header for ROS2 operation
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std;
using namespace rclcpp;

class SubBasicTestRos2 : public Node
{
public:
  SubBasicTestRos2(string strNodeNm);
  ~SubBasicTestRos2();

private:
  Subscription<std_msgs::msg::String>::SharedPtr subStr_;
  void CbStr(const std_msgs::msg::String::SharedPtr msg) const;
};