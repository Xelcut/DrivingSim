#include "../include/glad/glad.h"

#include "headers/car.h"

float vertices[] = {
  -0.5f, -0.5f, 0.0f,
  0.5f, -0.5f, 0.0f,
  0.0f,  0.5f, 0.0f
};

int VBO, VAO;

void loadCar() {
  genBuffers();
}

void genBuffers() {
  unsigned int VBO;
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

void drawCar() {
  glBindVertexArray(VAO);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

