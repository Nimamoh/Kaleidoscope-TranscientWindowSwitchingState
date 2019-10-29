// -*- mode: c++ -*-
// Kaleidoscope-TranscientWindowSwitchingState -- Add a toggle-able state keep alt pressed until escape or key release happen.
// Copyright (C) 2019 Nimamoh
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <Kaleidoscope.h>

// Helper defining set of keys for disableOnReleaseKeys
#define TWSS_KEYS(...) { __VA_ARGS__, Key_NoKey }

namespace kaleidoscope {
namespace plugin {

class TranscientWindowSwitchingState : public kaleidoscope::Plugin {
  public:

    // Disable plugin when these defined keys are released
    const kaleidoscope::Key *disableOnReleaseKeys;

    // Basic plugin status functions.
    static void enable();
    static void disable();
    static bool active();

    // Event handlers. Delete what you don't need.
    EventHandlerResult onKeyswitchEvent(Key &mapped_key, byte row, byte col,
                                        uint8_t key_state);
    EventHandlerResult beforeReportingState();

  private:
    static bool disabled_;
};


}  // namespace plugin
}  // namespace kaleidoscope

extern kaleidoscope::plugin::TranscientWindowSwitchingState TranscientWindowSwitchingState;
