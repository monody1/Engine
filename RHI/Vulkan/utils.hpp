#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include <fstream>
#include <string>

static char g_kProjectPath[] = "/Users/chen.zr/workspace/Engine/";

static char* ReadFile(const std::string& fileName, size_t* rBufferSize){
    auto path = g_kProjectPath + fileName;
    std::ifstream file(path, std::ios::ate | std::ios::binary);
    if(!file.is_open()){
        throw std::runtime_error("failed to open " + fileName);
    }
    size_t fileSize = file.tellg();
    auto rBuffer = new char[fileSize];
    *rBufferSize = fileSize;
    file.seekg(0);
    file.read(rBuffer, fileSize);
    file.close();
    return rBuffer;
}

#endif // __UTILS_HPP__