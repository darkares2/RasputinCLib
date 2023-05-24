cmake_minimum_required(VERSION 3.10)

message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

# set the project name
project(HelloWorld)


set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions(-DRASP_MEMORY_DEBUG)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/memory)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/unity)

add_subdirectory(src/memory)

# specify the directory where your test files are
add_subdirectory(test)

add_executable(HelloWorld main.c)

target_link_libraries(HelloWorld rasp_mem)
