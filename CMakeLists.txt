cmake_minimum_required(VERSION 3.17)

# vcpkg setup
set(CMAKE_TOOLCHAIN_FILE
        ${CMAKE_CURRENT_SOURCE_DIR}/flipl/external/vcpkg/scripts/buildsystems/vcpkg.cmake
        CACHE STRING "Vcpkg toolchain file"
)

project(flipl)

set(CMAKE_CXX_STANDARD 14)

find_package(unofficial-graphicsmagick CONFIG REQUIRED)
find_package(yaml-cpp CONFIG REQUIRED)

set(FLIPL_INCLUDE_DIR flipl/include)
set(FLIPL_SOURCE_DIR flipl/src)
set(FLIPL_SOURCES
        ${FLIPL_SOURCE_DIR}/main.cpp
        ${FLIPL_SOURCE_DIR}/timeline.cpp
)

add_executable(flipl ${FLIPL_SOURCES})
target_include_directories(flipl PRIVATE ${FLIPL_INCLUDE_DIR})
target_link_libraries(flipl PRIVATE unofficial::graphicsmagick::graphicsmagick yaml-cpp)
target_compile_definitions(flipl PRIVATE MAGICK_DLLS=\"${CMAKE_BINARY_DIR}\")
