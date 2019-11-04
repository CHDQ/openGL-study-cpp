//
// Created by root on 2019/11/1.
//
#include <glad/glad.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "MyShader.h"

MyShader::MyShader(const char *vertexPath, const char *fragmentPath) {
    // 1. 从文件路径中获取顶点/片段着色器
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // 保证ifstream对象可以抛出异常：
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        // 打开文件
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // 读取文件的缓冲内容到数据流中
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // 关闭文件处理器
        vShaderFile.close();
        fShaderFile.close();
        // 转换数据流到string
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);//创建顶点着色器;
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);//创建片段着色器
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);
    int success;
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);//查看着色器是否编译成功
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);//不成功的时候获取错误信息
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    shaderId = glCreateProgram();
    glAttachShader(shaderId, vertexShader);
    glAttachShader(shaderId, fragmentShader);
    glLinkProgram(shaderId);
    glDeleteShader(vertexShader);//删除已经链接的shader
    glDeleteShader(fragmentShader);
    use();
}

void MyShader::use() {
    glUseProgram(shaderId);
}

unsigned int MyShader::getShaderId() const {
    return shaderId;
}

void MyShader::setInt(const char *name, int value) const {
    glUniform1i(glGetUniformLocation(shaderId, name), value);
}

void MyShader::setMat4(const char *name, glm::mat4 &value) const {
    glUniformMatrix4fv(glGetUniformLocation(shaderId, name), 1, GL_FALSE, &value[0][0]);
}

void MyShader::setBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(shaderId, name.c_str()), (int) value);
}

// ------------------------------------------------------------------------
void MyShader::setInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(shaderId, name.c_str()), value);
}

// ------------------------------------------------------------------------
void MyShader::setFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(shaderId, name.c_str()), value);
}

// ------------------------------------------------------------------------
void MyShader::setVec2(const std::string &name, const glm::vec2 &value) const {
    glUniform2fv(glGetUniformLocation(shaderId, name.c_str()), 1, &value[0]);
}

void MyShader::setVec2(const std::string &name, float x, float y) const {
    glUniform2f(glGetUniformLocation(shaderId, name.c_str()), x, y);
}

// ------------------------------------------------------------------------
void MyShader::setVec3(const std::string &name, const glm::vec3 &value) const {
    glUniform3fv(glGetUniformLocation(shaderId, name.c_str()), 1, &value[0]);
}

void MyShader::setVec3(const std::string &name, float x, float y, float z) const {
    glUniform3f(glGetUniformLocation(shaderId, name.c_str()), x, y, z);
}

// ------------------------------------------------------------------------
void MyShader::setVec4(const std::string &name, const glm::vec4 &value) const {
    glUniform4fv(glGetUniformLocation(shaderId, name.c_str()), 1, &value[0]);
}

void MyShader::setVec4(const std::string &name, float x, float y, float z, float w) {
    glUniform4f(glGetUniformLocation(shaderId, name.c_str()), x, y, z, w);
}

// ------------------------------------------------------------------------
void MyShader::setMat2(const std::string &name, const glm::mat2 &mat) const {
    glUniformMatrix2fv(glGetUniformLocation(shaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------
void MyShader::setMat3(const std::string &name, const glm::mat3 &mat) const {
    glUniformMatrix3fv(glGetUniformLocation(shaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

// ------------------------------------------------------------------------
void MyShader::setMat4(const std::string &name, const glm::mat4 &mat) const {
    glUniformMatrix4fv(glGetUniformLocation(shaderId, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}


