cmake_minimum_required(VERSION 3.16)

# set the project name
project(gh-activity)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(third_party/CLI11)

add_subdirectory(src)

# add the executable
# add_executable(gh-activity src/main.cc) # without adding src as a subdirectory
# add_executable(gh-activity main.cc)
#
# target_link_libraries(gh-activity PRIVATE CLI11::CLI11)

# # include CLI11 header files only for gh-activity
# target_include_directories(gh-activity PRIVATE
#     ${CMAKE_SOURCE_DIR}/third_part/CLI11/include
# )

# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
