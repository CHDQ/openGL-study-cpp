//
// Created by root on 2019/10/31.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "OpenWindow.h"

/**
 * @author qiong.duan
 * @return
 */

OpenWindow::OpenWindow(Executor *executor) {
    this->executor = executor;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);//openGL版本为3.3，大版本
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);//小版本
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);//使用的openGL为核心版本

    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return;
    }
    glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);//设置窗口变化回调
    executor->beforeRender();
    while (!glfwWindowShouldClose(window)) {//循环防止程序关闭
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);//设置清屏颜色
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清屏
        executor->doRender();
        processInput(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

}

OpenWindow::~OpenWindow() {
    glfwTerminate();//释放资源
};

/**
 * 窗口变化回调
 * @param window 窗口
 * @param width  宽度
 * @param height 高度
 */
void OpenWindow::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

/**
 * 处理键盘输入
 * @param window 窗口
 */
void OpenWindow::OpenWindow::processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    executor->doInputProcess(window);
}