#include "pub_basic_test_ros2_lib.h"

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
  string strNodeNm = "pub_test_basic_ros2_node";
  auto node = Node::make_shared(strNodeNm);

  // setting the class object
  PubBasicTestRos2 pubBasicRos2(strNodeNm);

  // Tell ROS2 how fast to run this node.
  WallRate loopRate(30);

  // Main loop.
  while (ok())
  {
    // main function
    pubBasicRos2.MainLoop();

    // using callback loop and sleep feature
    spin_some(node);
    loopRate.sleep();
  }

  // releasing the class object
  pubBasicRos2.~PubBasicTestRos2();  

  // closing the rclcpp
  rclcpp::shutdown();  

  return 0;
}  // end main()