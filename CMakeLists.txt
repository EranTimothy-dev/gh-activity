cmake_minimum_required(VERSION 3.16)

# set the project name
project(gh-activity)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add_subdirectory(third_party/CLI11)

include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.6.2
)

FetchContent_MakeAvailable(CLI11)

find_package(CURL QUIET)

if (CURL_FOUND)
    message(STATUS "CURL found, using system library")
else()
    message(STATUS "CURL not found, fetching and building libcurl with FetchContent")
    FetchContent_Declare(
        CURL
        URL https://github.com/curl/curl/releases/download/curl-8_18_0/curl-8.18.0.tar.gz
        URL_HASH SHA256=e9274a5f8ab5271c0e0e6762d2fce194d5f98acc568e4ce816845b2dcc0cf88f
    )
    set(BUILD_CURL_EXE OFF CACHE BOOL "Don't build curl executable" FORCE)
    set(BUILD_STATIC_LIBS ON CACHE BOOL "Build static libraries for curl" FORCE)
    FetchContent_MakeAvailable(CURL) 
    add_library(CURL::libcurl ALIAS libcurl_static)
endif()

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


if (CMAKE_EXPORT_COMPILE_COMMANDS)
    execute_process(
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${CMAKE_BINARY_DIR}/compile_commands.json ${CMAKE_SOURCE_DIR}/compile_commands.json
    )
endif()
