#version 330 core
out vec4 FragColor;
in vec3 ourColor; // 从顶点着色器传来的输入变量（名称相同、类型相同）
in vec2 TexCoord;
uniform sampler2D ourTexture;
void main()
{
   FragColor = texture(ourTexture, TexCoord);//全局变量
}