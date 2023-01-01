// docs https://docs.gl/
#include <iostream>
#define GLEW_STATIC     //Can set on C++ preprocessor, for Dll set GLOW_BUILD
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define EXIT_FAILURE_OPENGL -1
#define EXIT_FAILURE_GLEW -2

using namespace std;
int main()
{
    GLFWwindow* window;
    if ( !glfwInit() ) return EXIT_FAILURE_OPENGL;
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window) { glfwTerminate(); return EXIT_FAILURE_OPENGL; }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) { cout << "GLEW Error!" << endl; return EXIT_FAILURE_GLEW; } //GLEW will set only here
    cout << "Gl version: " << glGetString(GL_VERSION) << endl;

    float positions[] = 
    {
        -0.5f, -0.5f
        , 0.0f, 0.5f
        , 0.5f, -0.5f
    };   //6 floats, our buffer, each line vertex (point)
    int vertexAttributeSize = 2;

    unsigned int buffer;
    glGenBuffers(1, &buffer);   //select buffer to use
    glBindBuffer(GL_ARRAY_BUFFER, buffer);    //buffer of memory, using the one we generated
    glBufferData(GL_ARRAY_BUFFER, sizeof(positions), positions, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);

    glVertexAttribPointer(0, vertexAttributeSize, GL_FLOAT, GL_FALSE, sizeof(float) * vertexAttributeSize,  0); // 0 start 2 jumppby, type, normalize?, stride (distance between each vertex), pointer (number of attribute) sizeof(float) * (place -1)

    glBindBuffer(GL_ARRAY_BUFFER, 0);


    while ( !glfwWindowShouldClose(window) )
    {
        glClear(GL_COLOR_BUFFER_BIT);   // add opengl32.lib
        glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
        //glBegin(GL_TRIANGLES);// -1 ... 1
        //glVertex2f(0.0f, 0.75f);
        //glVertex2f(-0.25f, -0.5f); glVertex2f(0.25f, -0.5f);
        //glEnd();
        glDrawArrays(GL_TRIANGLES, 0, 3); // 0begin - objects    // will draw our buffer, bined to position
        //glDrawElements(GL_TRIANGLES, 3, );



        //glBegin(GL_TRIANGLES);
        //glVertex2f(-0.25f, 0.5f); 
        //glVertex2f(0.25f, 0.5f);
        //glVertex2f(0.0f, -0.75f);
        //glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    glfwTerminate();
    return EXIT_SUCCESS;
}
