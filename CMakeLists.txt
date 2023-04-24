cmake_minimum_required(VERSION 3.21)
project(Vulkan)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc -static")

find_package(Vulkan REQUIRED)

add_executable(Vulkan main.cpp)

target_sources(Vulkan PRIVATE main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw-3.3.7)

target_link_libraries(Vulkan PRIVATE Vulkan::Vulkan glfw)
