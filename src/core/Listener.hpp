

#pragma once

#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFMachPort.h>
#include <CoreFoundation/CFRunLoop.h>
#include <CoreGraphics/CGEvent.h>
#include <CoreGraphics/CGEventTypes.h>
#include <stdexcept>

template <CGEventMask mask> class Listener {
private:
  CFMachPortRef m_tap;
  CFRunLoopSourceRef m_loop_source;

public:
  Listener(CGEventTapCallBack callback)
      : m_tap(
            CGEventTapCreate(kCGSessionEventTap, kCGHeadInsertEventTap,
                             kCGEventTapOptionDefault, mask, callback, nullptr)

                ),
        m_loop_source(
            CFMachPortCreateRunLoopSource(CFAllocatorGetDefault(), m_tap, 0)) {
    if (!m_tap)
      throw std::runtime_error("Could not create tap.");

    CFRunLoopAddSource(CFRunLoopGetMain(), m_loop_source,
                       kCFRunLoopDefaultMode);
    CGEventTapEnable(m_tap, true);
  }

  void listen() const noexcept { CFRunLoopRun(); }

  ~Listener() {
    CFRelease(m_loop_source);
    CFRelease(m_tap);
  }
};

namespace core {
inline void listenToEvents() { CFRunLoopRun(); }
} // namespace core
