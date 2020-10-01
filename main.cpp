#undef GLFW_DLL
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
    if (!glfwInit()) {
        cerr << "Can't initialize GLFW" << endl;
        exit (EXIT_FAILURE);
    }


    GLFWwindow *win;
    win = glfwCreateWindow (640, 480, "Hello", NULL, NULL);
    glfwMakeContextCurrent(win);

    if (glewInit() != GLEW_OK){
        cerr << "Can't initialize GLEW" << endl;
        exit (EXIT_FAILURE);
    }

    // OpenGL verzia
    cout << glGetString(GL_VERSION);

    while (!glfwWindowShouldClose(win)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // skusobny trojuholnik
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f,-0.5f);
        glVertex2f(0.0f,0.5f);
        glVertex2f(0.5f,-0.5f);
        glEnd();

        glfwSwapBuffers(win);

        glfwWaitEvents();
    }
    glfwDestroyWindow(win);
    glfwTerminate();
    return 0;
}