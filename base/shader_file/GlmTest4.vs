#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor; // 颜色变量的属性位置值为 1
layout (location = 2) in vec2 aTexCoord;
out vec3 ourColor; // 向片段着色器输出一个颜色;
out vec2 TexCoord;
uniform mat4 transform;
void main()
{
    gl_Position = transform * vec4(aPos, 1.0);
    ourColor = aColor; // 把输出变量设置为暗红色
    TexCoord = aTexCoord;
}