//
// Created by root on 2019/11/1.
//

#ifndef OPENGL_MYSHADER_H
#define OPENGL_MYSHADER_H

#include <iostream>
#include <glm/mat4x4.hpp>

/**
*@author qiong.duan
*/
class MyShader {
public:

    // 构造器读取并构建着色器
    MyShader(const char *vertexPath, const char *fragmentPath);

    // 使用/激活程序
    void use();

    unsigned int getShaderId() const;

    void setInt(const char *name, int value) const;

    void setMat4(const char *name, glm::mat4 &mat) const;

    void setMat4(const std::string &name, const glm::mat4 &mat) const;

    void setMat3(const std::string &name, const glm::mat3 &mat) const;

    void setMat2(const std::string &name, const glm::mat2 &mat) const;

    void setVec4(const std::string &name, float x, float y, float z, float w);

    void setVec4(const std::string &name, const glm::vec4 &value) const;

    void setVec3(const std::string &name, float x, float y, float z) const;

    void setVec3(const std::string &name, const glm::vec3 &value) const;

    void setVec2(const std::string &name, float x, float y) const;

    void setVec2(const std::string &name, const glm::vec2 &value) const;

    void setFloat(const std::string &name, float value) const;

    void setInt(const std::string &name, int value) const;

    void setBool(const std::string &name, bool value) const;

private:
    unsigned int shaderId;

};


#endif //OPENGL_MYSHADER_H
