add_executable(glfw_application ./Glfw_Application.cpp)

target_include_directories(
    glfw_application  
    PUBLIC
    ${CMAKE_SOURCE_DIR}
)

target_link_libraries(
    glfw_application
    PRIVATE
    glfw common "-framework opengl"
)