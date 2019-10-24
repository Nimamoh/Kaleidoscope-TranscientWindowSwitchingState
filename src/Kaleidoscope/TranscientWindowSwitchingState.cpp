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

// TranscientWindowSwitchingState

// Member variables.
bool TranscientWindowSwitchingState::disabled_ = false;

// Basic plugin status functions.

// Enable the plugin.
void TranscientWindowSwitchingState::enable() {
  disabled_ = false;
}

// Disable the plugin.
void TranscientWindowSwitchingState::disable() {
  disabled_ = true;
}

// Returns true if the plugin is enabled.
bool TranscientWindowSwitchingState::active() {
  return !disabled_;
}

// Event handlers.

// Runs once, when the plugin is initialized during Kaleidoscope.setup().
EventHandlerResult TranscientWindowSwitchingState::onSetup() {
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run as the first thing at the start of each cycle.
EventHandlerResult TranscientWindowSwitchingState::beforeEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Run for every non-idle key, in each cycle the key isn't idle in. If a key
// gets pressed, released, or is held, it is not considered idle, and this
// event handler will run for it too.
EventHandlerResult TranscientWindowSwitchingState::onKeyswitchEvent(Key &mapped_key, byte row,
                                              byte col, uint8_t key_state) {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs each cycle right before sending the various reports (keys pressed, mouse
// events, etc) to the host.
EventHandlerResult TranscientWindowSwitchingState::beforeReportingState() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

// Runs at the very end of each cycle.
EventHandlerResult TranscientWindowSwitchingState::afterEachCycle() {
  if(disabled_) {
    return EventHandlerResult::OK;
  }
  // Code goes here.
  return EventHandlerResult::OK;
}

}  // namespace plugin
}  // namespace kaleidoscope

kaleidoscope::plugin::TranscientWindowSwitchingState TranscientWindowSwitchingState;