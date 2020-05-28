cmake_minimum_required(VERSION 3.2)

project(yaml_test)

add_definitions(-std=c++11)
find_package(yaml-cpp REQUIRED)

include_directories(include)
set(SRCS yaml_read.cpp)
add_executable(yaml_read ${SRCS})

target_link_libraries(yaml_read yaml-cpp)
