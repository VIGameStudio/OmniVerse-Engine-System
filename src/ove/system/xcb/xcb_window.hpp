#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <xcb/xcb.h>

#include <ove/system/window.hpp>

namespace ove {
namespace system {

    struct xcb_window_t : public window_t {
    public:
        virtual void create();

    private:
        xcb_connection_t* c;
        xcb_screen_t* screen;
        xcb_drawable_t win;
        xcb_gcontext_t foreground;
        xcb_gcontext_t background;
        xcb_generic_event_t* e;
        uint32_t mask = 0;
        uint32_t values[2];
    };

}
}
