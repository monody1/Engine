cmake_minimum_required(VERSION 3.0.0)
project(Engine VERSION 0.1.0)

add_library(VulkanRHI ./VulkanGraphicsManager.cpp)

# target_include_directories(
#     helloVulkan
#     PRIVATE
#     ${CMAKE_SOURCE_DIR}/Externals/VulkanSDK/include
# )

target_link_libraries(
        VulkanRHI
        PRIVATE
        # GlfwApplication
        ${CMAKE_SOURCE_DIR}/Externals/VulkanSDK/lib/libvulkan.1.2.148.dylib
        # Common
)
