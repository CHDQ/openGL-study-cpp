//
// Created by root on 2019/10/31.
//

#ifndef OPENGL_EXECUTOR_H
#define OPENGL_EXECUTOR_H


/**
*@author qiong.duan
*/
class Executor {
public:
    virtual void beforeRender() = 0;

    virtual void doRender() = 0;
};


#endif //OPENGL_EXECUTOR_H
