//
// Created by root on 2019/10/31.
//

#ifndef OPENGL_EXECUTOR_H
#define OPENGL_EXECUTOR_H

#include "glad/glad.h"
#include <GLFW/glfw3.h>

/**
*@author qiong.duan
*/
class Executor {
public:
    virtual void beforeRender() = 0;

    virtual void doRender() = 0;

    virtual void doInputProcess(GLFWwindow *window) = 0;

};


#endif //OPENGL_EXECUTOR_H
