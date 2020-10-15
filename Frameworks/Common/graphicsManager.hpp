/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-09-07
 */

#ifndef __GRAPHICSMANAGER_HPP__
#define __GRAPHICSMANAGER_HPP__
#include "IRuntimeModule.hpp"

namespace engine
{
    class GraphicsManager : implements IRuntimeModule
    {
    public:
        int Initialize() override;
        void Tick() override;
        void Finalize() override;
        virtual ~GraphicsManager(){};
    };
} // namespace engine

#endif