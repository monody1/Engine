/**
 * Copyright (c) 2020, chen.zr. All rights reserved.
 * 
 * @author chen.zr
 * @date 2020-10-07
 */


#include "GlfwApplication.hpp"
// #include "vulkanApplication.hpp"
// #include "D3d/D3d12GraphicsManager.hpp"
// #include "MemoryManager.hpp"
// #include "AssetLoader.hpp"
// #include "SceneManager.hpp"
// #include ""

using namespace engine;

namespace engine {
    GfxConfiguration config(8, 8, 8, 8, 32, 0, 0, 960, 540, "Enpty Engine!");
    IApplication *g_pApp = static_cast<IApplication*>(new GlfwApplication(config));
    // GraphicsManager* g_pGraphicsManager = static_cast<GraphicsManager*>(new D3d12GraphicsManager);
    // MemoryManager*   g_pMemoryManager   = static_cast<MemoryManager*>(new MemoryManager);
    // AssetLoader*     g_pAssetLoader     = static_cast<AssetLoader*>(new AssetLoader);
    // SceneManager*    g_pSceneManager    = static_cast<SceneManager*>(new SceneManager);
}