cmake_minimum_required(VERSION 3.22)
project(Blend2D_Emscripten_Bug_Demo)

if(NOT EMSCRIPTEN)
    message(FATAL_ERROR "This repository MUST be built with Emscripten")
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXECUTABLE_SUFFIX ".html")

add_executable(${PROJECT_NAME} main.cpp)

include(FetchContent)

set(BLEND2D_NO_JIT ON)
FetchContent_Declare(Blend2D
    URL https://blend2d.com/download/blend2d-0.11.4.tar.gz
    URL_HASH SHA256=07f7d99d2ebb7b42a707a4f0035745b781faf9083933f944084f66e6246bb01c
)
FetchContent_MakeAvailable(Blend2D)
target_link_libraries(${PROJECT_NAME} PRIVATE blend2d)
