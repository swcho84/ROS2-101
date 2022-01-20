#!/usr/bin/env python3
import rclpy
import time
from HelloWorldRos2 import TestHelloWorldRos2

def MainHelloWorldRos2(args=None):
  rclpy.init(args=args)
  node = rclpy.create_node("hello_world_ros2")
  testHelloWorld = TestHelloWorldRos2()
  try:
    while rclpy.ok():
      strHelloWorld = testHelloWorld.GenHelloWorld(node)
      time.sleep(1)
  except KeyboardInterrupt:
    pass
    node.get_logger().info("Keyboard Interrupt(SIGINT)")
  finally:
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
  MainHelloWorldRos2()
