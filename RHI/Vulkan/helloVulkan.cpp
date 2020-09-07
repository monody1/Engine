//
// Created by Chen.Zr on 2020/3/22.
//


#include <glm/glm.hpp>
#include <vulkan/vulkan.hpp>
#include "glfwApplication.hpp"

namespace engine{
    GfxConfiguration config;
    GlfwApplication g_App = GlfwApplication(config);
    IApplication *g_pApp = &g_App;
}

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
    glfwSwapBuffers(m_pWindow);
}

bool engine::GlfwApplication::IsQuit() {
    return quit_;
}

engine::GlfwApplication::GlfwApplication(const engine::GfxConfiguration &Config) : BaseApplication(Config) {}

void engine::GlfwApplication::InitGlfw(){
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    m_pWindow = glfwCreateWindow(config.screen_width, config.screen_height, config.window_title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_pWindow);
    glfwSetWindowCloseCallback(m_pWindow, GlfwApplication::CloseCallback);
}

void engine::GlfwApplication::FinalizeGlfw(){
    glfwDestroyWindow(m_pWindow);
    glfwTerminate();
}

void engine::GlfwApplication::CloseCallback(GLFWwindow *window) {
    BaseApplication::quit_ = true;
}
