//
// Created by root on 2019/10/31.
//
#include "../../base/Executor.h"

#ifndef OPENGL_DRAWTRIANGLE_H
#define OPENGL_DRAWTRIANGLE_H


/**
*@author qiong.duan
*/
class DrawTriangle : public Executor {
public:
    void doRender() override;

    void beforeRender() override;

private:
    unsigned int shaderProgram;
    unsigned int VAO;
};


#endif //OPENGL_DRAWTRIANGLE_H
