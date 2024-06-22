
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

namespace MCL {

struct MCL_Data {
  uint32_t click_count{0};
  uint32_t r_click_count{0};
  uint32_t l_click_count{0};
};

MCL_Data data{};
static constexpr CGEventMask mcl_mask{1 << kCGEventRightMouseDown |
                                      1 << kCGEventLeftMouseDown};
} // namespace MCL

class MouseClickListener : Listener<MCL::mcl_mask> {

private:
  static CGEventRef mouseClickedCallback(CGEventTapProxy proxy,
                                         CGEventType type, CGEventRef event,
                                         void *userInfo) {

    if (type == kCGEventRightMouseDown) {
      ++MCL::data.r_click_count;
    } else if (type == kCGEventLeftMouseDown) {
      ++MCL::data.l_click_count;
    }
    ++MCL::data.click_count;
    std::clog << "Another Click. \r\n\t Click Count: " << MCL::data.click_count
              << '\n';
    return event;
  }

public:
  MouseClickListener() : Listener(mouseClickedCallback) {}

  void listen() const noexcept { CFRunLoopRun(); }
};
