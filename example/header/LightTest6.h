//
// Created by chdq on 2019/11/2.
//

#ifndef OPENGL_LIGHTTEST6_H
#define OPENGL_LIGHTTEST6_H


#include "../../base/Executor.h"
#include "../../base/MyShader.h"
#include "../../base/Camera.h"

class LightTest6 : public Executor {
    void beforeRender() override;

    void doRender() override;

    void doInputProcess(GLFWwindow *window) override;

public:
    virtual ~LightTest6();

    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
private:
    MyShader *objectShader;
    MyShader *lightShader;
    unsigned int VAO;
    unsigned int lightVAO;
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    float deltaTime;
    float lastFrame;
};


#endif //OPENGL_LIGHTTEST6_H
