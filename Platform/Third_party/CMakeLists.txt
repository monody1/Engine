add_executable(glfwApplication ./glfwApplication.cpp)

target_include_directories(
    glfwApplication  
    PUBLIC
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(
    glfwApplication
    PRIVATE
    glfw common "-framework opengl"
)