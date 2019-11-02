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
    explicit OpenWindow(Executor *executor);

    ~OpenWindow();

    static void framebuffer_size_callback(GLFWwindow *window, int width, int height);

    void processInput(GLFWwindow *window);

private:
    Executor *executor;


};

#endif //OPENGL_OPENWINDOW_H