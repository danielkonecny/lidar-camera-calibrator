cmake_minimum_required(VERSION 3.16)
project(Calibrator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(/opt/pylon/include)
link_directories(/opt/pylon/lib)

set(sample_dir src/)
set(target example_tutorial_)

set(sample_pnplib
        ${sample_dir}CsvReader.cpp
        ${sample_dir}CsvWriter.cpp
        ${sample_dir}ModelRegistration.cpp
        ${sample_dir}Mesh.cpp
        ${sample_dir}Model.cpp
        ${sample_dir}PnPProblem.cpp
        ${sample_dir}Utils.cpp
        ${sample_dir}RobustMatcher.cpp
)

add_executable(${target}pnp_registration
        ${sample_dir}main_registration.cpp
        ${sample_pnplib}
)
add_executable(${target}pnp_detection
        ${sample_dir}main_detection.cpp
        ${sample_pnplib}
)

target_link_libraries(
        ${target}pnp_registration PRIVATE
        ${OpenCV_LIBS}
)

target_link_libraries(
        ${target}pnp_detection PRIVATE
        ${OpenCV_LIBS}
)
