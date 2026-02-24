cmake_minimum_required(VERSION 3.10...4.0)
project(OpenStud LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)
FetchContent_Declare(SDL3 GIT_REPOSITORY https://github.com/libsdl-org/SDL.git GIT_TAG main)
FetchContent_Declare(Luau GIT_REPOSITORY https://github.com/luau-lang/luau.git GIT_TAG 0.709)
FetchContent_Declare(Diligent GIT_REPOSITORY https://github.com/DiligentGraphics/DiligentEngine.git GIT_TAG master)
FetchContent_MakeAvailable(SDL3 Luau Diligent)
add_executable(${PROJECT_NAME} src/OpenStud.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE 
    SDL3::SDL3 
    Luau.VM 
    Luau.Compiler
    Diligent-GraphicsEngineVulkan-static
    Diligent-Common
)