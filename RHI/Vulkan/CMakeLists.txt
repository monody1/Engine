cmake_minimum_required(VERSION 3.0.0)
project(OpenMc VERSION 0.1.0)

add_executable(helloVulkan ./helloVulkan.cpp)

target_include_directories(
    helloVulkan
    PRIVATE
    ${CMAKE_SOURCE_DIR}/Externals/VulkanSDK/include
)

target_link_libraries(
    helloVulkan
    PRIVATE
    ${CMAKE_SOURCE_DIR}/Externals/VulkanSDK/lib/libvulkan.1.2.148.dylib
    common
    glfw
)