
#ifndef MOUSECLICKLISTENER_HPP
#define MOUSECLICKLISTENER_HPP

#include "Datetime.hpp"
#include "Listener.hpp"
#include "ListenerDataTypes.h"
#include "Serializer.hpp"
#include "whd.h"
#include <CoreFoundation/CFBase.h>
#include <CoreFoundation/CFMachPort.h>
#include <CoreFoundation/CFRunLoop.h>
#include <CoreGraphics/CGEvent.h>
#include <CoreGraphics/CGEventTypes.h>
#include <iostream>

class MouseClickListener;

namespace MCL {

    static constexpr CGEventMask mcl_mask{1 << kCGEventRightMouseDown |
                                          1 << kCGEventLeftMouseDown};
}// namespace MCL

class MouseClickListener : Listener<MCL::mcl_mask> {
    static inline std::chrono::steady_clock::time_point last_serialize_time {};


private:
    static CGEventRef mouseClickedCallback(CGEventTapProxy proxy,
                                           CGEventType type, CGEventRef event,
                                           void *userInfo) {

        if (type == kCGEventRightMouseDown) {
            ++whd::global.m_data.first.r_click_count;
        } else if (type == kCGEventLeftMouseDown) {
            ++whd::global.m_data.first.l_click_count;
        }

        ++whd::global.m_data.first.click_count;

        std::clog << "Another Click. \r\n\t Click Count: " << whd::global.m_data.first.click_count
                  << '\n';

        auto now = std::chrono::steady_clock::now();
        if (now - last_serialize_time > std::chrono::seconds(5)) { // Serialize every 5 minutes
            Serializer::serialize(whd::global);
            last_serialize_time = now;
        }

        return event;
    }


public:
    MouseClickListener(MouseClickListener &&) = delete;

    MouseClickListener(const MouseClickListener &) = delete;

    explicit MouseClickListener();

    explicit MouseClickListener(WholeData &whole_data);
};

#endif
