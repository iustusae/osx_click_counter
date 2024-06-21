#pragma once

#include "Listener.hpp"
#include <CoreGraphics/CGEventTypes.h>
#include <iostream>

static constexpr CGEventMask kl_mask{1 << kCGEventKeyDown};

class KeystrokeListener : Listener<kl_mask> {

private:
  static CGEventRef keystrokeCallbackOnEvent(CGEventTapProxy proxy,
                                             CGEventType type, CGEventRef event,
                                             void *userInfo) {
    std::clog << "A key has been pressed.\n";
    return event;
  }

public:
  KeystrokeListener() : Listener<kl_mask>(keystrokeCallbackOnEvent) {}
};
