cmake_minimum_required(VERSION 3.0.0)
project(jce VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(runTest test.cpp)
target_link_libraries(runTest PUBLIC jce)
