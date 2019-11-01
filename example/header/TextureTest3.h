//
// Created by root on 2019/11/1.
//

#ifndef OPENGL_TEXTURETEST3_H
#define OPENGL_TEXTURETEST3_H


#include "../../base/Executor.h"

/**
*@author qiong.duan
*/
class TextureTest3: public Executor {
public:
    void beforeRender() override;

    void doRender() override;

private:
    unsigned int shaderProgram;
    unsigned int VAO;
    unsigned int texture;
};


#endif //OPENGL_TEXTURETEST3_H
