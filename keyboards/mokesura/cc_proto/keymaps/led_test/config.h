#pragma once

/* RGB Light*/
#define RGB_DI_PIN D3
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 1
#    define RGBLIGHT_EFFECT_RGB_TEST
#endif
