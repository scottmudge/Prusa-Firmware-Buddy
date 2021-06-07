// screen_usbfault.cpp

#include "screen_usbfault.hpp"
#include "config.h"
#include "ScreenHandler.hpp"
#include "bsod.h"
#include "sound.hpp"

screen_usbfault_data_t::screen_usbfault_data_t()
    : AddSuperWindow<screen_reset_error_data_t>()
    , text(this, Rect16(10, 70, 220, 48), is_multiline::yes)
{

    ClrOnSerialClose();
    ClrMenuTimeoutClose();
    SetBackColor(COLOR_RED);

    Sound_Stop();
    Sound_Play(eSOUND_TYPE::CriticalAlert);

    text.font = resource_font(IDR_FNT_BIG);
    static const char usb_fault[] = "USB FAULT\nCHECK DRIVE";
    text.SetText(string_view_utf8::MakeCPUFLASH((const uint8_t *)usb_fault));
    text.SetAlignment(Align_t::Center());

}
