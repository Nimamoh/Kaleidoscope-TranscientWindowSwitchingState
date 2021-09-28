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

#include <Kaleidoscope-TranscientWindowSwitchingState.h>

namespace kaleidoscope {
namespace plugin {

bool TranscientWindowSwitchingState::disabled_ = true;
// Press this key as long as this plugin is active
kaleidoscope::Key keyToHold = Key_LeftAlt;

void TranscientWindowSwitchingState::enable() { disabled_ = false; }

void TranscientWindowSwitchingState::disable() { disabled_ = true; }

bool TranscientWindowSwitchingState::active() { return !disabled_; }

// Event handlers.
EventHandlerResult TranscientWindowSwitchingState::onKeyswitchEvent(Key &mapped_key, KeyAddr key_addr
                                                                                   , uint8_t key_state) {
  if(disabled_) 
    return EventHandlerResult::OK;

  int i = 0;
  bool check_stopping_keys = true;
  while(check_stopping_keys) {

    check_stopping_keys = disableOnReleaseKeys[i] != Key_NoKey; 

    if (mapped_key == disableOnReleaseKeys[i] && keyToggledOff(key_state)) {
      this->disable();
      check_stopping_keys = false;
    }

    i++;
  }

  return EventHandlerResult::OK;
}

EventHandlerResult TranscientWindowSwitchingState::beforeReportingState() {
  if(disabled_) 
    return EventHandlerResult::OK;

  handleKeyswitchEvent(Key_LeftAlt, KeyAddr(KeyAddr::invalid_state), IS_PRESSED | INJECTED);
  return EventHandlerResult::OK;
}

}  // namespace plugin
}  // namespace kaleidoscope

kaleidoscope::plugin::TranscientWindowSwitchingState TranscientWindowSwitchingState;
