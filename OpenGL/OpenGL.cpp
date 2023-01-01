// OpenGL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#define GLEW_STATIC     //Can set on C++ preprocessor //GLOW_BUILD
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define EXIT_FAILURE_OPENGL -1
#define EXIT_FAILURE_GLEW -2

using namespace std;
int main()
{

    //std::cout << "Hello World!\n";
    GLFWwindow* window;
    if ( !glfwInit() ) return EXIT_FAILURE_OPENGL;
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) { glfwTerminate(); return EXIT_FAILURE_OPENGL; }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) { cout << "GLEW Error!" << endl; return EXIT_FAILURE_GLEW; } //GLEW will set only here

    while ( !glfwWindowShouldClose(window) )
    {
        glClear(GL_COLOR_BUFFER_BIT);   // add opengl32.lib
        glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
        glBegin(GL_TRIANGLES);// -1 ... 1
        glVertex2f(0.0f, 0.75f);
        glVertex2f(-0.25f, -0.5f); glVertex2f(0.25f, -0.5f);
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
