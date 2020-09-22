cmake_minimum_required(VERSION 3.0.0)
project(OpenMc VERSION 0.1.0)

add_executable(openGLApplication ./openGLApplication.cpp)

target_link_libraries(
    openGLApplication
    PRIVATE
    ${OPENGL}
    common
    glfw
    glad
)