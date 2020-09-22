//
// Created by Chen.Zr on 2020/3/22.
//

#include "glfwApplication.hpp"

// namespace engine{
//     GfxConfiguration config;
//     GlfwApplication g_App = GlfwApplication(config);
//     IApplication *g_pApp = &g_App;
// }

int engine::GlfwApplication::Initialize() {
    int res = BaseApplication::Initialize();
    InitGlfw();
    return res;
}

void engine::GlfwApplication::Finalize() {
    FinalizeGlfw();
}

void engine::GlfwApplication::Tick() {
    glfwPollEvents();
    // glfwSwapBuffers(m_pWindow);
}

bool engine::GlfwApplication::IsQuit() {
    return m_quit;
}

void engine::GlfwApplication::InitGlfw(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_pWindow = glfwCreateWindow(m_config.screen_width, m_config.screen_height, m_config.window_title.c_str(), nullptr, nullptr);
    // glfwMakeContextCurrent(m_pWindow);
    glfwSetWindowCloseCallback(m_pWindow, GlfwApplication::CloseCallback);
}

void engine::GlfwApplication::FinalizeGlfw(){
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
}

void engine::GlfwApplication::CloseCallback(GLFWwindow *window) {
    BaseApplication::m_quit = true;
}


