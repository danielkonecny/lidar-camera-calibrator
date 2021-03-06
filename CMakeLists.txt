cmake_minimum_required(VERSION 3.16)
project(Calibrator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
        Calibrator
        src/main.cpp src/main.h
        src/ArgumentsParser.cpp src/ArgumentsParser.h
        src/Point.cpp src/Point.h src/PointCloud.cpp src/PointCloud.h src/PointCloudLoader.cpp src/PointCloudLoader.h src/IMU.cpp src/IMU.h src/IMUPoints.cpp src/IMUPoints.h src/IMUPointsLoader.cpp src/IMUPointsLoader.h)

target_link_libraries(
        Calibrator
        ${OpenCV_LIBS}
)
