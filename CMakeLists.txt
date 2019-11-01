cmake_minimum_required(VERSION 3.15)
project(opengl)

set(CMAKE_CXX_STANDARD 14)
include_directories(D:/temp/glfw-3.3/include
        D:/temp/glad/include
        D:/temp/glm
        )

link_directories(D:/temp/glfw-3.3/build/src/Debug)
link_libraries(glfw3dll)
add_executable(opengl main.cpp glad.c base/OpenWindow.cpp base/OpenWindow.h stb_image.h
        example/DrawTriangle1.cpp example/header/DrawTriangle1.h base/Executor.h example/ShaderTest2.cpp example/header/ShaderTest2.h example/TextureTest3.cpp example/header/TextureTest3.h example/GlmTest4.cpp example/GlmTest4.cpp example/header/GlmTest4.h)


