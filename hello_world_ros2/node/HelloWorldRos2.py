#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

class TestHelloWorldRos2(Node):
  def __init__(self):
    self.count = 0
  
  def GenHelloWorld(self, node):
    res = "hello world %s" % node.get_clock().now() + (str)(self.count)
    self.count += 1 
    node.get_logger().info(res)
    return res