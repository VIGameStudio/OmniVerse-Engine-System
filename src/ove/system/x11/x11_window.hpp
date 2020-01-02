#pragma once

#include <GL/gl.h>
#include <GL/glx.h>
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ove/system/window.hpp>

namespace ove {
namespace system {

    struct x11_window_t : public window_t {
    public:
        virtual bool create(const char* title, core::u32 width, core::u32 height);

        virtual void close();

        virtual bool shouldClose();

        virtual void pollEvents();

        virtual void swapBuffers();

        virtual void setTitle(const char* title);

        virtual void setSize(core::u32 width, core::u32 height);

        virtual const char* getTitle();

        virtual void getSize(core::u32& width, core::u32& height);

    private:
        Display* m_pDisplay;
        Window m_root;
        XEvent m_event;
        GLXContext m_context;
        Window m_window;
        XWindowAttributes m_attribs;
        Atom m_wmDeleteMessage;

        const char* m_title;
        bool m_shouldClose;
    };

}
}
