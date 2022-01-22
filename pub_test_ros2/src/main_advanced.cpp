#include "pub_advanced_test_ros2_lib.h"

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
  string strNodeNm = "pub_test_advanced_ros2_node_multiarray";
  auto node = Node::make_shared(strNodeNm);

  // setting the class object
  PubAdvTestRos2 pubAdvMultiArrRos2(strNodeNm);

  // Tell ROS2 how fast to run this node.
  WallRate loopRate(30);

  // Main loop.
  while (ok())
  {
    // main function
    pubAdvMultiArrRos2.MainLoop();

    // using callback loop and sleep feature
    spin_some(node);
    loopRate.sleep();
  }

  // releasing the class object
  pubAdvMultiArrRos2.~PubAdvTestRos2();  

  return 0;
}  // end main()