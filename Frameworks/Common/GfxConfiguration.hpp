//
// Created by Chen.Zr on 2020/3/22.
//

#ifndef GFXCONFIGURATION_HPP
#define GFXCONFIGURATION_HPP

#pragma once

#include <cstdint>
#include <string>
#include <iostream>

namespace engine {
    struct GfxConfiguration {
        GfxConfiguration(uint32_t r = 8, uint32_t g = 8, uint32_t b = 8, uint32_t a = 8,
                        uint32_t s = 0, uint32_t d = 32, uint32_t msaa = 0,
                        uint32_t screenWidth = 1440, uint32_t screenHeight = 900,
                        const std::string& title = "default")
            : red_bits(r), green_bits(g), blue_bits(b), alpha_bits(a), depth_bits(d),
            stencil_bits(s), msaa_samples(msaa), screen_width(screenWidth),
            screen_height(screenHeight), window_title(title) {}

        uint32_t red_bits;
        uint32_t green_bits;
        uint32_t blue_bits;
        uint32_t alpha_bits;
        uint32_t depth_bits;
        uint32_t stencil_bits;
        uint32_t msaa_samples;
        uint32_t screen_width;
        uint32_t screen_height;
        std::string window_title;

        // void SetTitle(const std::string& title){
        //     window_title = title;
        // }

        friend std::ostream& operator<<(std::ostream& out, const GfxConfiguration& config){
            out << "GfxConfiguration: " <<
                "  R: " << config.red_bits <<
                ", G: " << config.green_bits <<
                ", B: " << config.blue_bits      <<
                ", A: "<< config.alpha_bits     <<
                ", D: "<< config.depth_bits     <<
                ", S: "<< config.stencil_bits   <<
                ", M: "<< config.msaa_samples   <<
                ", W: "<< config.screen_width   <<
                ", H: "<< config.screen_height  <<
                std::endl;
            return out;
        }
    };
}

#endif //GFXCONFIGURATION_HPP
