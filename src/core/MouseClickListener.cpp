//
// Created by Ayman Ougri on 7/1/24.
//
#include "MouseClickListener.hpp"

MouseClickListener::MouseClickListener() : Listener(mouseClickedCallback) {
    last_serialize_time = std::chrono::steady_clock::now();
}

MouseClickListener::MouseClickListener(WholeData &whole_data)
    : Listener(mouseClickedCallback) {
    last_serialize_time = std::chrono::steady_clock::now();
}