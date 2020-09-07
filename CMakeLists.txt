cmake_minimum_required(VERSION 3.0.0)
project(OpenMc VERSION 0.1.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS, -std==c++17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/Out/Bin)   
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/Out/Bin) 

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Out/Bin)       #设置可执行文件的输出目录

SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/Out/Lib)           #设置库文件的输出目录


if (CMAKE_BUILD_TYPE MATCHES "Debug" )
    add_definitions(-DMY_DEBUG)
endif ()

include_directories(
        ${CMAKE_SOURCE_DIR}/Frameworks/Common/
        ${CMAKE_SOURCE_DIR}/Frameworks/Interface/
        ${CMAKE_SOURCE_DIR}/Platform/Third_party/
        # ${CMAKE_SOURCE_DIR}/external/crossguid
)

include_directories(
    ${CMAKE_SOURCE_DIR}/Externals/glfw/include
    ${CMAKE_SOURCE_DIR}/Externals/glm
    # ${CMAKE_SOURCE_DIR}/Externals/
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/Frameworks/
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/Platform/
)

add_subdirectory(
    ${CMAKE_SOURCE_DIR}/Externals/
)

#test
add_subdirectory(
    ${CMAKE_SOURCE_DIR}/Playground/
)



# add_subdirectory(
#         ${CMAKE_SOURCE_DIR}/rhi/
# )

# add_subdirectory(${CMAKE_SOURCE_DIR}/test)

# target_include_directories(
#     OpenMc
#     PRIVATE
#     ./Externals/glfw/include
# )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
