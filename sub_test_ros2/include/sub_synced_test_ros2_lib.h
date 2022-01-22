// using vector type data
#include <iostream>
#include <string>
#include <stdio.h>
#include <ctime>
#include <vector>

// essential header for ROS2 operation
#include <rclcpp/rclcpp.hpp>
#include <rclcpp/time.hpp>

#include <std_msgs/msg/string.hpp>
#include <std_msgs/msg/multi_array_dimension.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>

#include <geometry_msgs/msg/vector3_stamped.hpp>
#include <geometry_msgs/msg/point_stamped.hpp>

#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/synchronizer.h>

using namespace std;
using namespace rclcpp;

class SubSyncedTestRos2 : public Node
{
public:
  SubSyncedTestRos2(string strNodeNm);
  ~SubSyncedTestRos2();

private:
  std::unique_ptr<message_filters::Subscriber<geometry_msgs::msg::Vector3Stamped> > subVec3Stamp_;
  std::unique_ptr<message_filters::Subscriber<geometry_msgs::msg::PointStamped> > subPtStamp_;

  typedef message_filters::sync_policies::ApproximateTime<geometry_msgs::msg::Vector3Stamped,
                                                          geometry_msgs::msg::PointStamped> mySyncPolicy;
  typedef message_filters::Synchronizer<mySyncPolicy> Sync;
  std::shared_ptr<Sync> sync_;

  void CbSyncData(const geometry_msgs::msg::Vector3Stamped::SharedPtr msgVec3Stamp,
                                  const geometry_msgs::msg::PointStamped::SharedPtr msgPtStamp);

  Time prevTime_;
};