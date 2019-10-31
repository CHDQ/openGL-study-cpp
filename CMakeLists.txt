cmake_minimum_required(VERSION 3.15)
project(opengl)

set(CMAKE_CXX_STANDARD 14)
include_directories(D:/temp/glfw-3.3/include
        D:/temp/glad/include)

link_directories(D:/temp/glfw-3.3/build/src/Debug)
link_libraries(glfw3dll)
add_executable(opengl main.cpp glad.c base/OpenWindow.cpp base/OpenWindow.h example/DrawTriangle_1.cpp example/header/DrawTriangle.h base/Executor.h)


