//
// Created by Ayman Ougri on 7/1/24.
//
#include "KeystrokeListener.hpp"



KeystrokeListener::KeystrokeListener() : Listener(keystrokeCallbackOnEvent) {}

KeystrokeListener::KeystrokeListener(WholeData &whole_data)
    :Listener(keystrokeCallbackOnEvent) {
}
