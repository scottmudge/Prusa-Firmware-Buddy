//screen_watchdog.hpp
#pragma once
#include "gui.hpp"
#include "window_text.hpp"
#include "screen_reset_error.hpp"

class screen_usbfault_data_t : public AddSuperWindow<screen_reset_error_data_t> {
    window_text_t text;

public:
    screen_usbfault_data_t();
};
