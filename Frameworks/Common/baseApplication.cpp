//
// Created by Chen.Zr on 2020/3/20.
//

#include "baseApplication.hpp"

bool engine::BaseApplication::quit_ = false;

int engine::BaseApplication::Initialize() {
    std::cout << config_;
    return 0;
}

void engine::BaseApplication::Finalize() {

}

void engine::BaseApplication::Tick() {

}

bool engine::BaseApplication::IsQuit() {
    return quit_;
}

engine::BaseApplication::BaseApplication(const engine::GfxConfiguration &config)
: config_(config) {}
