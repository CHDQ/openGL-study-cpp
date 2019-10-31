//
// Created by root on 2019/10/31.
//
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Executor.h"

#ifndef OPENGL_OPENWINDOW_H
#define OPENGL_OPENWINDOW_H


class OpenWindow {
public:
    OpenWindow(Executor* excutor);

    ~OpenWindow();

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void processInput(GLFWwindow *window);


};

#endif //OPENGL_OPENWINDOW_H