//
// Created by Chen.Zr on 2020/3/20.
//

#ifndef BASE_APPLICATION_HPP
#define BASE_APPLICATION_HPP

#include "appliction.hpp"
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

    protected:
        static bool quit_;
        engine::GfxConfiguration config_;
    };
}


#endif //BASE_APPLICATION_HPP
