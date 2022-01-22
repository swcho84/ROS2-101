# ROS2-101
ROS2-101 class - from basic to advanced

## 충북대학교
- 강의일시: 2022년 1월 24일-26일(3일), 10:00-17:00
- 강의명: ROS2 기반 프로그래밍 이론 및 실습​
- 강의장소: 충북대학교
- 수강대상: 학부생 및 대학원생 
- 강의주제: ROS2 Galactic C/C++ 활용 및 예제, 실습위주
- 실습주제: ROS2 Galactic manual page 참고하여 Python3 으로 같은 기능 구현하기

## hello_world_ros2
- hello world 를 terminal 에서 확인하도록 하는 pkg
- ros pkg 의 기본구조 학습

## pub_test_ros2
- ros2 의 publisher 예제
- basic: string data 를 publish 하는 pkg, while loop 와 timer callback 을 이용하는 방법
- advanced: Float64MultiArray, geometric msg data 를 publish 하는 pkg, while loop 와 timer callback 을 이용하는 방법

## sub_test_ros2
- ros2 의 subscriber 예제
- basic: string data 를 subscribe 하는 pkg, callback 을 이용
- advanced: Float64MultiArray 를 subscribe 하여 Float64 를 다시 publish 하는 pkg, timer callback 을 이용
- synced: time stamp 를 갖고 있는 topic 들을 subscribe 하는 pkg, sync 관련 기능 이용