#include "../include/glad/glad.h"
#include "headers/shaders.h"
#include "headers/car.h"
#include <GLFW/glfw3.h>
#include <stdio.h>

#include "headers/window.h"

int createWindow() {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window = glfwCreateWindow(800, 600, "DrivingSim", NULL, NULL);
  if (window == NULL) {
    printf("Failed to create GLFW window\n");
    glfwTerminate();

    return -1;
  }
  glfwMakeContextCurrent(window);
  glfwSwapInterval(1);
  glfwShowWindow(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    printf("Failed to initialize GLAD\n");

    return -1;
  }

  glViewport(0, 0, 800, 600);

  void framebuffer_size_callback(GLFWwindow * window, int width, int height);

  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

  createShaders();

  loadCar();

  while (!glfwWindowShouldClose(window)) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // processInput(window);

    useShader();

    drawCar();

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}



void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

int processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, 1);
}
