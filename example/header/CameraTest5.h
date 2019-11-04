//
// Created by chdq on 2019/11/2.
//

#ifndef OPENGL_CAMERATEST5_H
#define OPENGL_CAMERATEST5_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../base/Executor.h"
#include "../../base/MyShader.h"

class CameraTest5 : public Executor {
public:
    void beforeRender() override;

    void doRender() override;

    void doInputProcess(GLFWwindow *window) override;

    virtual ~CameraTest5();

    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;

private:
    MyShader *myShader;
    unsigned int VAO;
    unsigned int texture0;
    unsigned int texture1;
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    float deltaTime;
    float lastFrame;
};


#endif //OPENGL_CAMERATEST5_H
