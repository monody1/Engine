/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-10-07
 */

#ifndef __GLFWAPPLICATION_HPP__
#define __GLFWAPPLICATION_HPP__

#include <GLFW/glfw3.h>
#include "BaseApplication.hpp"

namespace engine{
    class GlfwApplication: public BaseApplication
    {
    public:
        GlfwApplication(const GfxConfiguration &Config): BaseApplication(Config){};
        int Initialize() override;
        void Tick() override;
        void Finalize() override;
        bool IsQuit() override;
        
        GLFWwindow *m_pWindow;
        //Glfw help func
        static void CloseCallback(GLFWwindow* window);
    };
}

#endif