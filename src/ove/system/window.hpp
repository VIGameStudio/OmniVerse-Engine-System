#pragma once

namespace ove {
namespace system {

    struct window_t {
        window_t();
        ~window_t();

        virtual void create() = 0;
    };

}
}
