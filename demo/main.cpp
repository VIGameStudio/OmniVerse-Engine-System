#include <ove/system/x11/x11_window.hpp>
#include <ove/system/xcb/xcb_window.hpp>

using namespace ove::system;

int main()
{
    window_t* window;

    //window = new ove::system::x11_window_t();
    window = new ove::system::xcb_window_t();

    window->create();

    return 0;
}
