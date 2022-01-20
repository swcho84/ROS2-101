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

class PubBasicTestRos2 : public Node
{
public:
  PubBasicTestRos2(string strNodeNm);
  ~PubBasicTestRos2();

  void MainLoop();

private:
  Publisher<std_msgs::msg::String>::SharedPtr pubStr_;
  size_t count_;
};