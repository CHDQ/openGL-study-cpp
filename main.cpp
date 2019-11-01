#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "base/OpenWindow.h"
#include "example/header/TextureTest3.h"

int main() {
    TextureTest3 textureTest3;
    OpenWindow openWindow(&textureTest3);
    return 0;
}

