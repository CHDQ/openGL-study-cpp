//
// Created by root on 2019/10/31.
//
#include "../../base/Executor.h"

#ifndef OPENGL_DRAWTRIANGLE_H
#define OPENGL_DRAWTRIANGLE_H


/**
*@author qiong.duan
 *
 *--------------------------------------------------------------
 * run in main function
 *
 * #include "base/OpenWindow.h"
 * #include "example/header/DrawTriangle.h"
 *
 *int main() {
 *  DrawTriangle drawTriangle;
 *  OpenWindow openWindow(&drawTriangle);
 *  return 0;
 *}
 *  ------------------------------------------------------------
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
