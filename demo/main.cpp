#include <ove/system/x11/x11_window.hpp>

#include <iostream>
#include <iostream>

using namespace ove::system;

void cursor_pos_fn(window_t*win, double x, double y)
{
    printf("x:%.0f, y:%.0f\n", x, y);
    std::cout << "x:" << x << ", y:" << y << std::endl;
}

void key_fn(window_t*win, int key, int scanCode, int action, int mods)
{
    std::cout << "k:" << key << std::endl;
}

int main()
{
    window_t* window = new ove::system::x11_window_t();

    if (!window->create("Demo", 640, 480))
    {
        std::cerr << "Failed to create window!" << std::endl;
        return EXIT_FAILURE;
    }

    window->setCursorPosCallback(cursor_pos_fn);
    window->setKeyCallback(key_fn);

    while(!window->shouldClose())
    {
        unsigned int width, height;
        window->getSize(width, height);

        glEnable(GL_DEPTH_TEST);
        glViewport(0, 0, width, height);
        glClearColor(1.f, 1.f, 1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

        window->swapBuffers();
        window->pollEvents();

        //printf("update\n");
        fflush(stdout);
    }

    return EXIT_SUCCESS;
}
