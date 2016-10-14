#include <iostream>
#include <GLFW/glfw3.h>
#include "window/OpenWindow.h"
#include "graphics/Color.h"
#include "graphics/OpenGraphics.h"
#include "OpenUtils.h"

using namespace std;
using namespace Openw67Render;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main()
{

    std::cout << "Hello, World!" << std::endl;
    if (!glfwInit())
    {
        std::cerr << "Initialization failed of GLFW." << std::endl;
    }
    glfwSetErrorCallback(error_callback);
    OpenWindow window = OpenWindow("Test", 640, 480, OpenMonitor());
    glfwMakeContextCurrent(window.getWindowReference());
    glfwSwapInterval(1);
    OpenGraphics graphics = OpenGraphics();
    int x(20), y(20), width(100), height(100);
    setViewport(0, 0, 640, 480);
    while (!glfwWindowShouldClose(window.getWindowReference()))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        //glClearColor(1, 1, 1, 1);

        // ENABLE 2D RENDER
        glMatrixMode(GL_PROJECTION);
        glPushMatrix(); // preserve perspective view
        glLoadIdentity(); // clear the perspective matrix
        glOrtho( // turn on 2D mode
                //// viewportX,viewportX+viewportW, // left, right
                //// viewportY,viewportY+viewportH, // bottom, top !!!
                0, 640, // left, right
                480, 0, // bottom, top
                -500, 500); // Zfar, Znear
        // clear the modelview matrix
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix(); // Preserve the Modelview Matrix
        glLoadIdentity(); // clear the Modelview Matrix
        // disable depth test so further drawing will go over the current scene
        glDisable(GL_DEPTH_TEST);

        Color color = Color(71, 97, 141);
        graphics.setColor(color);
        graphics.beginDraw(DRAW_TYPE_QUADS);
        graphics.vertex2f(x, y);
        graphics.vertex2f(x, y + height);
        graphics.vertex2f(x + width, y + height);
        graphics.vertex2f(x + width, y);
        graphics.endDraw();

        graphics.drawLine2D(250, 250, 350, 350);

        glfwSwapBuffers(window.getWindowReference());
        glfwPollEvents();
    }
    window.destroy();
    glfwTerminate();
    return 0;
}