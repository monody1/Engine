cmake_minimum_required(VERSION 3.0.0)
project(OpenMc VERSION 0.1.0)

add_executable(OpenGLApplication ./OpenGLApplication.cpp)

target_link_libraries(
    OpenGLApplication
    PRIVATE
    ${OPENGL}
    common
    glfw
    glad
)