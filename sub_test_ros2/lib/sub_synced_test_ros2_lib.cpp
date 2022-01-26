#include "sub_synced_test_ros2_lib.h"

using namespace std;
using namespace rclcpp;

SubSyncedTestRos2::SubSyncedTestRos2(string strNodeNm) : Node(strNodeNm)
{
	// define quality of service: all messages that you want to receive must have the same
  rmw_qos_profile_t qos = rmw_qos_profile_default;
  qos.depth = 1;
  qos.reliability = rmw_qos_reliability_policy_t::RMW_QOS_POLICY_RELIABILITY_BEST_EFFORT;
  qos.history = rmw_qos_history_policy_t::RMW_QOS_POLICY_HISTORY_KEEP_LAST;
  qos.durability = rmw_qos_durability_policy_t::RMW_QOS_POLICY_DURABILITY_VOLATILE;

  subVec3Stamp_.reset(
      new message_filters::Subscriber<geometry_msgs::msg::Vector3Stamped>(this, "/pub_vec3stamp", qos));
  subPtStamp_.reset(
      new message_filters::Subscriber<geometry_msgs::msg::PointStamped>(this, "/pub_ptstamp", qos));

  sync_.reset(new Sync(mySyncPolicy(10), *subVec3Stamp_, *subPtStamp_));
  sync_->registerCallback(&SubSyncedTestRos2::CbSyncData, this);

	prevTime_ = this->get_clock()->now();	
}

SubSyncedTestRos2::~SubSyncedTestRos2()
{
}

void SubSyncedTestRos2::CbSyncData(const geometry_msgs::msg::Vector3Stamped::SharedPtr msgVec3Stamp,
                                  const geometry_msgs::msg::PointStamped::SharedPtr msgPtStamp)
{
	auto currTime = this->get_clock()->now();
	double dt = (currTime - prevTime_).seconds();	
	RCLCPP_INFO(this->get_logger(), "[CallBackSync]dt(%.4lf)Vec3Stamp(%.4lf, %.4lf, %.4lf),PtStamp(%.4lf, %.4lf, %.4lf)", 
							dt, msgVec3Stamp->vector.x, msgVec3Stamp->vector.y, msgVec3Stamp->vector.z,
							msgPtStamp->point.x, msgPtStamp->point.y, msgPtStamp->point.z);	
	prevTime_ = this->get_clock()->now();
}