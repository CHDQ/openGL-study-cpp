//
// Created by root on 2019/11/1.
//

#ifndef OPENGL_MYSHADER_H
#define OPENGL_MYSHADER_H

#include <iostream>
#include <glad/glad.h>

/**
*@author qiong.duan
*/
class MyShader {
public:

    // 构造器读取并构建着色器
    MyShader(const GLchar *vertexPath, const GLchar *fragmentPath);

    // 使用/激活程序
    void use();

    unsigned int getShaderId() const;

private:
    unsigned int shaderId;

};


#endif //OPENGL_MYSHADER_H
