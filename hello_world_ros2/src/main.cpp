#include "hello_world_ros2_lib.h"

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
  auto node = Node::make_shared("hello_world_ros2_node");

  // setting the class object
  HelloWorldRos2 helloWorldRos2;

  // Tell ROS2 how fast to run this node.
  WallRate loopRate(30);

  // Main loop.
  while (ok())
  {
    // main function
    helloWorldRos2.MainLoop();

    // using callback loop and sleep feature
    spin_some(node);
    loopRate.sleep();
  }

  // releasing the class object
  helloWorldRos2.~HelloWorldRos2();  

  return 0;
}  // end main()