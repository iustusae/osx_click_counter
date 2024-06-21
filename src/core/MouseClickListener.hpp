
#pragma once
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFMachPort.h>
#include <CoreFoundation/CFRunLoop.h>
#include <CoreGraphics/CGEvent.h>
#include <CoreGraphics/CGEventTypes.h>
#include <atomic>
#include <cstdint>
#include <iostream>

#include "Listener.hpp"

class MouseClickListener;

namespace core {
inline std::atomic<uint32_t> click_count{0};

}

static constexpr CGEventMask mcl_mask{1 << kCGEventRightMouseDown |
                                      1 << kCGEventLeftMouseDown};

class MouseClickListener : Listener<mcl_mask> {

private:
  static CGEventRef mouseClickedCallback(CGEventTapProxy proxy,
                                         CGEventType type, CGEventRef event,
                                         void *userInfo) {
    ++core::click_count;
    std::clog << "Another Click. \r\n\t Click Count: " << core::click_count
              << '\n';
    return event;
  }

public:
  MouseClickListener() : Listener(mouseClickedCallback) {}

  void listen() const noexcept { CFRunLoopRun(); }
};
