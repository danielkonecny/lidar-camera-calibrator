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
)

target_link_libraries(
        Calibrator
        ${OpenCV_LIBS}
)
