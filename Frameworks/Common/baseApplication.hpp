//
// Created by Chen.Zr on 2020/3/20.
//

#ifndef BASE_APPLICATION_HPP
#define BASE_APPLICATION_HPP

#include "IAppliction.hpp"
#include "GfxConfiguration.hpp"

namespace engine {
    class BaseApplication: implements IApplication{
    public:
        BaseApplication(const GfxConfiguration &config);

        BaseApplication() = delete;

        int Initialize() override ;

        void Finalize() override;

        void Tick() override;

        bool IsQuit() override;

        engine::GfxConfiguration m_config;
        static bool m_quit;
    };
}


#endif //BASE_APPLICATION_HPP
