//
// Created by root on 2019/10/31.
//
#include <iostream>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <cmath>
#include "header/DrawTriangle1.h"


using namespace std;

void DrawTriangle1::doRender() {
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);//设置绘制模式，填充或者划线GL_LINE
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
//    glDrawArrays(GL_TRIANGLES, 0, 3); //画三角形
//EBO不能单独使用必须和VBO配合使用，VBO可以单独使用
    float timeValue = glfwGetTime();
    float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
    glUseProgram(shaderProgram);//创建uniform之前不需要调用，但是更新之前一定要调用
    glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);//画正方形，当使用索引缓冲对象的时候，最后一个参数为0，否则是一个索引数组
//    glBindVertexArray(0);
}

void DrawTriangle1::beforeRender() {
//    float vertices[] = { 绘制三角形
//            -0.5f, -0.5f, 0.0f,
//            0.5f, -0.5f, 0.0f,
//            0.0f, 0.5f, 0.0f
//    };
    float vertices[] = {//绘制正方形
            0.5f, 0.5f, 0.0f,   // 右上角
            0.5f, -0.5f, 0.0f,  // 右下角
            -0.5f, -0.5f, 0.0f, // 左下角
            -0.5f, 0.5f, 0.0f   // 左上角
    };

    unsigned int indices[] = { // 注意索引从0开始!
            0, 1, 3, // 第一个三角形
            1, 2, 3  // 第二个三角形
    };
    glGenVertexArrays(1, &VAO);
    unsigned int VBO;
    glGenBuffers(1, &VBO);//生成缓冲对象
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);//绑定缓冲区
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//绑定缓冲区

    /**
     * GL_STATIC_DRAW ：数据不会或几乎不会改变。
     * GL_DYNAMIC_DRAW：数据会被改变很多。
     * GL_STREAM_DRAW ：数据每次绘制时都会改变。
     */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);//将顶点复制到缓冲区，第二个参数以字节为单位,三角形
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);//将顶点复制到缓冲区，第二个参数以字节为单位，正方形
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);//创建顶点着色器
    const char *vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "out vec4 vertexColor; // 为片段着色器指定一个颜色输出\n"
                                     "void main()\n"
                                     "{\n"
                                     "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "    vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // 把输出变量设置为暗红色\n"
                                     "}";
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);//查看着色器是否编译成功
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);//不成功的时候获取错误信息
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    const char *fragmentShaderSource = "#version 330 core\n"
                                       "out vec4 FragColor;\n"
                                       "in vec4 vertexColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）\n"
                                       "uniform vec4 ourColor;//设置全局变量\n"
                                       "void main()\n"
                                       "{\n"
                                       // "    FragColor = vertexColor;\n"//颜色有上一个shader传递过来，只需要类型和名称一致就可以
                                       "    FragColor = ourColor;\n"//全局变量
                                       "} ";
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);//创建片段着色器
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//查看着色器是否编译成功
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);//不成功的时候获取错误信息
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);


    glGetShaderiv(shaderProgram, GL_LINK_STATUS, &success);//查看着色器是否编译成功
    if (!success) {
        glGetShaderInfoLog(shaderProgram, 512, NULL, infoLog);//不成功的时候获取错误信息
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);//删除已经链接的shader
    glDeleteShader(fragmentShader);
    glUseProgram(shaderProgram);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
}