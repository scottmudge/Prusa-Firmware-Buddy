//wdt.h - watchdog timers (IWDG, WWDG)
#pragma once

typedef void(wdt_iwdg_warning_cb_t)(void); // IWDG warning callback prototype

#if defined(__cplusplus)
extern "C" {
#endif //defined(__cplusplus)

extern wdt_iwdg_warning_cb_t *wdt_iwdg_warning_cb; // IWDG warning callback
extern volatile int wdt_iwdg_is_usb_fault;

// IWDG refresh, called from C code
extern void wdt_iwdg_refresh(void); 

// @brief IWDG refresh from HCD SOF callback
// @param state of USB host-controller interrupt - 1 == active, 0 == inactive
extern void wdt_iwdg_refresh_hcd(const int hcint_st); 

extern void wdt_wwdg_init(void);

// timer tick (IWDG warning), called from HAL_TIM_PeriodElapsedCallback/timer6
extern void wdt_tick_1ms(void); 

#if defined(__cplusplus)
} //extern "C"

void watchdog_init(); // initialization - called from marlin during setup (C++)

void HAL_watchdog_refresh(); // IWDG refresh - called from marlin thermal management (C++)

#endif //defined(__cplusplus)
