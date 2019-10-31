#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "base/OpenWindow.h"
#include "example/header/DrawTriangle.h"

int main() {
    DrawTriangle drawTriangle;
    OpenWindow openWindow(&drawTriangle);
    return 0;
}

