#pragma once

#include <X11/Xlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ove/system/window.hpp>

namespace ove {
namespace system {

    struct x11_window_t : public window_t {
    public:
        virtual void create();

    private:
        Display* d;
        Window w;
        XEvent e;
    };

}
}
