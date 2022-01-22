#include "sub_basic_test_ros2_lib.h"

using namespace std;
using namespace rclcpp;

/*--------------------------------------------------------------------
 * main()
 * Main function to set up ROS node.
 *------------------------------------------------------------------*/

int main(int argc, char** argv)
{
  // Set up ROS2
  init(argc, argv);

  // setting the node (nodeHandler)
  string strNodeNm = "sub_test_basic_ros2_node";
  auto node = Node::make_shared(strNodeNm);

  // using callback loop and sleep feature
  spin(std::make_shared<SubBasicTestRos2>(strNodeNm));

  // closing the rclcpp
  rclcpp::shutdown();

  return 0;
}  // end main()