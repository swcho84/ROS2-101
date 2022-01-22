// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>
#include <chrono>
#include <functional>
#include <memory>

// essential header for ROS2 operation
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std;
using namespace rclcpp;
using namespace std::chrono_literals;

class PubBasicTestStdStyleRos2 : public Node
{
public:
  PubBasicTestStdStyleRos2(string strNodeNm);
  ~PubBasicTestStdStyleRos2();

private:
  Publisher<std_msgs::msg::String>::SharedPtr pubStr_;
  rclcpp::TimerBase::SharedPtr timer_;
	void CbPubTimer();

  size_t count_;
};