//
// Created by Chen.Zr on 2020/3/20.
//

#ifndef GAME_ENGINE_APPLICTION_HPP
#define GAME_ENGINE_APPLICTION_HPP

#include "interface.hpp"
#include "runtime_module.hpp"

namespace engine{
    Interface IApplication: implements IRuntimeModule{
    public:
        virtual int Initialize() = 0;
        virtual void Finalize() = 0;
        virtual void Tick() = 0;
        virtual bool IsQuit() = 0;
    };
}

#endif //GAME_ENGINE_APPLICTION_HPP
