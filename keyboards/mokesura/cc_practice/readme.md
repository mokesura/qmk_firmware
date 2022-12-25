# CC Practice

![mokesura/cc_practice](imgur.com image replace me!)

This is a simple card-sized keyboard.  
In order to play TTRPG online, we have added the ability to do die rolls.  
If you want to use the dice roll feature on this keyboard, please compile it with the key codes USER00 - USER08.  
Note that these key codes were created assuming that the language setting of your computer is Japanese.

* Keyboard Maintainer: [Chinatsu Chiba (azulee/mokesura)](https://github.com/mokesura)
* Hardware Supported: CC Practice PCB rev1
* Hardware Availability: [GitHub](https://github.com/mokesura/cc_practice)

Make example for this keyboard (after setting up your build environment):

    make mokesura/cc_practice:default

Flashing example for this keyboard:

    make mokesura/cc_practice:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `RESET` if it is available
