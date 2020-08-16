cmake_minimum_required(VERSION 3.0.0)
project(OpenMc VERSION 0.1.0)

include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_FLAGS, -std==c++17)

if (CMAKE_BUILD_TYPE MATCHES "Debug" )
    add_definitions(-DMY_DEBUG)
endif ()

include_directories(
        ${CMAKE_SOURCE_DIR}/Frameworks/Common/
        ${CMAKE_SOURCE_DIR}/Frameworks/Interface/
        # ${CMAKE_SOURCE_DIR}/external/crossguid
)

include_directories(
    ${CMAKE_SOURCE_DIR}/Externals/glfw/include
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
include(CPack)
