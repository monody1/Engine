/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-09-10
 */

#include "openGLApplication.hpp"

namespace engine{
    GfxConfiguration config;
    // config -> SetTitle("1");
    IApplication *g_pApp = static_cast<IApplication*>(new OpenGLApplication(config));
}
void engine::OpenGLApplication::InitOpenGL(){
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwMakeContextCurrent(m_pWindow);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return;
    }
}

int engine::OpenGLApplication::Initialize(){
    int res = BaseApplication::Initialize();
    glfwInit();
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_pWindow = glfwCreateWindow(m_config.screen_width, m_config.screen_height, m_config.window_title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_pWindow);
    glfwSetWindowCloseCallback(m_pWindow, CloseCallback);

    InitOpenGL();
    return res;
}
void engine::OpenGLApplication::Finalize(){
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
    BaseApplication::Finalize();
}
void engine::OpenGLApplication::Tick(){
    BaseApplication::Tick();
    glfwPollEvents();
}

void engine::OpenGLApplication::CloseCallback(GLFWwindow *window) {
    BaseApplication::m_quit = true;
}

bool engine::OpenGLApplication::IsQuit() {
    return m_quit;
}