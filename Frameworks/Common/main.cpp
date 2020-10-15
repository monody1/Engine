
#include <iostream>
#include "IAppliction.hpp"

using namespace engine;

namespace engine {
    extern IApplication *g_pApp;
}

int main() {
    int ret;

    if ((ret = g_pApp -> Initialize() != 0)){
        std::cout << "App Initialize failed, will exit now." << std::endl;
        return ret;
    }
    while(!g_pApp -> IsQuit()) {
        g_pApp->Tick();
    }

    g_pApp->Finalize();

    return 0;
}
