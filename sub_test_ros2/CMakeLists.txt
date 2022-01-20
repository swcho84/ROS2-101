cmake_minimum_required(VERSION 3.8)
project(sub_test_ros2)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
  src
  lib
)

add_executable(sub_test_basic_ros2_node lib/sub_basic_test_ros2_lib.cpp include/sub_basic_test_ros2_lib.h src/main_basic.cpp)
ament_target_dependencies(sub_test_basic_ros2_node rclcpp std_msgs)

add_executable(sub_test_advanced_multiarray_ros2_node lib/sub_advanced_test_ros2_lib.cpp include/sub_advanced_test_ros2_lib.h src/main_advanced.cpp)
ament_target_dependencies(sub_test_advanced_multiarray_ros2_node rclcpp std_msgs)

install(TARGETS
  sub_test_basic_ros2_node
  sub_test_advanced_multiarray_ros2_node
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
