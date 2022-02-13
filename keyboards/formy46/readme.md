# formy46

[formy46](https://imgur.com/a/a3PWhZx)

## Description
A compact and multifunctional split keyboard.

* Keyboard Maintainer: [marby3](https://github.com/yourusername)
* Hardware Supported: *Formy46PCB, ProMicro, MX Switch, Choc Switch*
* Hardware Availability: *Links to where you can find this hardware*

## Build
Make example for this keyboard (after setting up your build environment):

    qmk compile -kb formy46 -km default

Flashing example for this keyboard:

    qmk flash -kb formy46 -km default

IF you want to use VIA(I have disabled the LED on VIA because of the large firmware size):

    qmk flash -kb formy46 -km via

If you are using Elite-C(DFU bootloader):
    qmk flash -kb formy46 -km default -bl dfu

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader
Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
