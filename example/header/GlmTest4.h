//
// Created by root on 2019/11/1.
//

#ifndef OPENGL_GLMTEST4_H
#define OPENGL_GLMTEST4_H


#include "../../base/Executor.h"

/**
*@author qiong.duan
*/
class GlmTest4 : public Executor {
public:
    void beforeRender() override;

    void doRender() override;

private:
    unsigned int shaderProgram;
    unsigned int VAO;
    unsigned int texture;
};


#endif //OPENGL_GLMTEST4_H
