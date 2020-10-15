//
// Created by Chen.Zr on 2020/3/20.
//

#include "BaseApplication.hpp"

bool engine::BaseApplication::m_quit = false;

int engine::BaseApplication::Initialize() {
    std::cout << m_config;
    return 0;
}

void engine::BaseApplication::Finalize() {

}

void engine::BaseApplication::Tick() {

}

bool engine::BaseApplication::IsQuit() {
    return m_quit;
}

engine::BaseApplication::BaseApplication(const engine::GfxConfiguration &config)
: m_config(config) {}
