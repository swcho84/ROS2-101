#include "pub_advanced_test_ros2_stdstyle_lib.h"

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
  rclcpp::executors::SingleThreadedExecutor::SharedPtr exec 
    = std::make_shared<rclcpp::executors::SingleThreadedExecutor>();
  string strNodeNm = "pub_test_advanced_ros2_stdstyle_node";
  std::shared_ptr<PubAdvTestStdStyleRos2> pubNode 
    = std::make_shared<PubAdvTestStdStyleRos2>(strNodeNm);
  exec->add_node(pubNode);
  exec->spin();

  // closing the rclcpp
  rclcpp::shutdown();

  return 0;
}  // end main()