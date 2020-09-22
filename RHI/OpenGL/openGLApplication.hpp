/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-09-10
 */

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "baseApplication.hpp"

#ifndef __OPENGLAPPLICATION_HPP__
#define __OPENGLAPPLICATION_HPP__

namespace engine{
    class OpenGLApplication: public BaseApplication
    {
    public:
        OpenGLApplication(const GfxConfiguration& config): BaseApplication(config){};
        
        void InitOpenGL();

        int Initialize() override;
        void Finalize() override;
        void Tick() override;
        bool IsQuit() override;

        static void CloseCallback(GLFWwindow* window);

    private:
        GLFWwindow* m_pWindow;
    };
}

#endif