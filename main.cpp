#include <iostream>
#include <GLFW/glfw3.h>
#include "window/OpenWindow.h"

using namespace std;
using namespace Openw67Render;

int main()
{

    std::cout << "Hello, World!" << std::endl;
    if (!glfwInit())
    {
        std::cerr << "Initialization failed of GLFW." << std::endl;
    }
    OpenWindow window = OpenWindow("Test", 640, 480, OpenMonitor());
    glfwMakeContextCurrent(window.getWindowReference());
    int a = 0;
    while (!glfwWindowShouldClose(window.getWindowReference()))
    {
        glfwSwapBuffers(window.getWindowReference());
        glfwPollEvents();
        a++;
        string s = "Lol: " + to_string(a);
        window.setTitle(s.c_str());
    }
    glfwTerminate();
    delete &window;
    return 0;
}