//
// Created by root on 2019/11/1.
//

#ifndef OPENGL_SHADERTEST2_H
#define OPENGL_SHADERTEST2_H


#include "../../base/Executor.h"

/**
*@author qiong.duan
*/
class ShaderTest2 : public Executor {
public:
    void beforeRender();

    void doRender();

private:
    unsigned int shaderProgram;
    unsigned int VAO;
};


#endif //OPENGL_SHADERTEST2_H
