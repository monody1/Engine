//
// Created by Chen.Zr on 2020/3/20.
//

#ifndef GAME_ENGINE_RUNTIME_MODULE_HPP
#define GAME_ENGINE_RUNTIME_MODULE_HPP

#include "interface.hpp"
// why use custom Init and final replace constructor and destructor
// Chapter 5
namespace engine{
    Interface IRuntimeModule{
    public:
        virtual ~IRuntimeModule() {};
        //Init module
        virtual int Initialize() = 0;
        //clean up module
        virtual void Finalize() = 0;
        //drive module do its work in particular cycle
        virtual void Tick() = 0;

    };
}

#endif //GAME_ENGINE_RUNTIME_MODULE_HPP
