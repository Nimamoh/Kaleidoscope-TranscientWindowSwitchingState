# Kaleidoscope-TranscientWindowSwitchingState

Have you tried to re-create 【<kbd>Alt</kbd>+<kbd>Tab</kbd>】 on keyboard.io (remapping it on 【<kbd>Fn</kbd>+<kbd>d</kbd>】 for instance)

It is not easy.

This plugin allows you to 
 - Enable a state where <kbd>Alt</kbd> key is hold. (The transcient window switching state)
 - Disable the TWSS when user defined keys are released.

# How to use

git clone on your sketchbook directory. (see [https://github.com/keyboardio/Kaleidoscope/wiki/Installing-Plugins#installing-third-party-plugins](https://github.com/keyboardio/Kaleidoscope/wiki/Installing-Plugins#installing-third-party-plugins))

Include directive:
```c++
#include "Kaleidoscope-TranscientWindowSwitchingState.h"
```

Initialize the plugin
```c++
KALEIDOSCOPE_INIT_PLUGINS(
    ...
    TranscientWindowSwitchingState,
    ...
)
```

Define the keys which exits the TWSS on setup function, (Use the `TWSS_KEYS` helper macro for that):

```c++
static const kaleidoscope::Key stoppingKeys[] = TWSS_KEYS(Key_Escape, ShiftToLayer(2));
TranscientWindowSwitchingState.disableOnReleaseKeys = stoppingKeys; 
```

*The TWSS is disabled by default, you can enable it by enabling the plugin*

Define a macro which enable the plugin:

```c++
static void windowSwitch(uint8_t keyState) {
  TranscientWindowSwitchingState.enable();
  kaleidoscope::hid::pressKey(Key_Tab, keyToggledOn(keyState));
}
```

Assign your macro and you are good to go

# Gotchas

- Try to stick to the guide above, this plugin is quite specific (and certainly too complex for what it aims for), *do not forget to define at least one stopping key* to prevent being stuck to the TWSS.
- This is my first plugin with kaleidoscope and I didn't write cpp for a long time. PR and ideas of improvment are welcome.