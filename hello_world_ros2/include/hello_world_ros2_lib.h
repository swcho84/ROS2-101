// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>

// essential header for ROS-OpenCV operation
#include <rclcpp/rclcpp.hpp>

using namespace std;
using namespace rclcpp;

class HelloWorldRos2 : public Node
{
public:
  HelloWorldRos2();
  ~HelloWorldRos2();

  void MainLoop();  

private:
  void HelloFunction();
};