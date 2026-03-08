cmake_minimum_required(VERSION 3.16)

# set the project name
project(gh-activity)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# add the executable
add_executable(gh-activity src/main.cc)
