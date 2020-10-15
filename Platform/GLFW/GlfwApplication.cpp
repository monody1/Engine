/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-10-07
 */

#include "GlfwApplication.hpp"
#include "VulkanGraphicsManager.hpp"

namespace engine
{
    extern GraphicsManager *g_pGraphicsManager;

    int GlfwApplication::Initialize() 
    {
        int res = BaseApplication::Initialize();
        if(glfwInit() == GLFW_FALSE){
            throw std::runtime_error("failed to init glfw");
        };

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
        
        m_pWindow = glfwCreateWindow(
            m_config.screen_width, 
            m_config.screen_height, 
            m_config.window_title.c_str(), 
            nullptr, nullptr
        );

        if(m_pWindow == nullptr){
            throw std::runtime_error("failed to create window");
        }

        glfwSetWindowCloseCallback(m_pWindow, CloseCallback);
        g_pGraphicsManager -> Initialize();
        return res;
    }

    void GlfwApplication::Tick() 
    {
        g_pGraphicsManager -> Tick();
        glfwPollEvents();      
    }

    void GlfwApplication::Finalize() 
    {   
        g_pGraphicsManager -> Finalize();
        glfwDestroyWindow(m_pWindow);
        glfwTerminate();
    }
    
    bool GlfwApplication::IsQuit() 
    {
        return m_quit;
    }

    void GlfwApplication::CloseCallback(GLFWwindow *window) {
        BaseApplication::m_quit = true;
    }
}