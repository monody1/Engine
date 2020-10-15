# add_library(
#     glfwApplication
#     glfwApplication.cpp
# )

# target_link_libraries(
#     glfwApplication
#     PRIVATE
#     glfw
# )

add_executable(
    Empty
    EmptyApp.cpp
    GlfwApplication.cpp
)

target_link_libraries(
    Empty
    PRIVATE
    glfw
    common
)

add_executable(
    VulkanApp
    VulkanApp.cpp
    GlfwApplication.cpp
)

target_link_libraries(
    VulkanApp
    PRIVATE
    glfw
    common
    VulkanRHI
)