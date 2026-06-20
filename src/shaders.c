#include "../include/glad/glad.h"
#include <stdio.h>

#include "headers/shaders.h"

int shaderProgram;

void createShaders() {
  const char *vertexShaderSource = 
    "#version 330 core \n"
    "layout (location = 0) in vec3 aPos; \n"
    "void main() \n"
    "{\ngl_position = vec4(aPos.x, aPos.y, 0, 1.0);\n}\0";

  const char *fragmentShaderSource = 
  "#version 330 core \n"
  "out vec4 FragColor; \n"
  "void main() \n"
  "{\nFragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}\0";

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
  glCompileShader(vertexShader);

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);

  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  // glUseProgram(shaderProgram);

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}

void useShader() {
  glUseProgram(shaderProgram);
}

