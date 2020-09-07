//
// Created by Chen.Zr on 2020/3/22.
//

#ifndef GAME_ENGINE_OSX_APPLICATION_HPP
#define GAME_ENGINE_OSX_APPLICATION_HPP

#include "baseApplication.hpp"
#include <GLFW/glfw3.h>

namespace engine {

    class GlfwApplication: implements BaseApplication {
    private:
        GLFWwindow * m_pWindow = nullptr;
    public:
        GlfwApplication(const GfxConfiguration &Config);

        int Initialize() override;

        void Finalize() override;

        void Tick() override;

        bool IsQuit() override;

        void InitGlfw();
        void FinalizeGlfw();
        static void CloseCallback(GLFWwindow* window);
    };
}


#endif //GAME_ENGINE_OSX_APPLICATION_HPP
