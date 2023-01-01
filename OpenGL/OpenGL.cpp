// OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define EXIT_FAILURE_OPENGL -1
#include <iostream>
#include <GLFW/glfw3.h>
int main()
{
    //std::cout << "Hello World!\n";
    GLFWwindow* window;
    if ( !glfwInit() ) return EXIT_FAILURE_OPENGL;
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) { glfwTerminate(); return EXIT_FAILURE_OPENGL; }
    glfwMakeContextCurrent(window);
    
    while ( !glfwWindowShouldClose(window) )
    {
        glClear(GL_COLOR_BUFFER_BIT);   // add opengl32.lib
        glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);// -1 ... 1
        glVertex2f(-0.25f, -0.5f); glVertex2f(0.25f, -0.5f);
        glVertex2f(0.0f, 0.75f);
        glEnd();

        glBegin(GL_TRIANGLES);
        glVertex2f(-0.25f, 0.5f); glVertex2f(0.25f, 0.5f);
        glVertex2f(0.0f, -0.75f);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return EXIT_SUCCESS;
}
