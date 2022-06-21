cmake_minimum_required(VERSION 3.0.0)
project(jce VERSION 0.1.0)

include(CTest)
enable_testing()

file (GLOB_RECURSE Files
    "include/*"
    "src/*"
)

find_package(jce REQUIRED)

add_executable(optimize optimize.cpp ${Files})
target_link_libraries(optimize PUBLIC jce)
target_include_directories(optimize PUBLIC "include/")
