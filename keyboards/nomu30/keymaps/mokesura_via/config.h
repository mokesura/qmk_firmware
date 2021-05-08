#pragma once

// place overrides here
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

// LED Setting: if you have KUMO you can use RGBLIGHT_ENABLE = yes
#ifdef RGBLIGHT_ENABLE
  #define RGB_DI_PIN B5
  #define RGBLED_NUM 5

  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_LAYERS
  #define RGBLIGHT_MAX_LAYERS 4
  #define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#endif

#ifdef MIDI_ENABLE
  #define MIDI_ADVANCED
#endif
