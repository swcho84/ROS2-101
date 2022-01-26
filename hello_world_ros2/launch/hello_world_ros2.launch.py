import os
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
  config = os.path.join(
      get_package_share_directory('hello_world_ros2'),
      'config',
      'params.yaml'
      )

  ld = LaunchDescription()   
  hello_world_node = Node(
          package='hello_world_ros2',
          executable='hello_world_ros2_node',
          name='hello_world_ros2_test',
          output="screen",
          emulate_tty=True,          
          parameters=[
                {'my_str': 'Hello Cpp'},
                {'my_int': 12},
                {'my_double_array': [3.3, 4.4, 5.5]}
            ],
      )
  ld.add_action(hello_world_node)
  return ld