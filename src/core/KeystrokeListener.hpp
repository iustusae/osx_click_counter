#pragma once

#include "Listener.hpp"
#include <Carbon/Carbon.h>
#include <CoreGraphics/CGEventTypes.h>
#include <CoreGraphics/CGRemoteOperation.h>
#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <unordered_map>

namespace KL {

static const std::unordered_map<int, char> keyMap = {
    {0x00, 'A'},  {0x01, 'S'}, {0x02, 'D'},  {0x03, 'F'}, {0x04, 'H'},
    {0x05, 'G'},  {0x06, 'Z'}, {0x07, 'X'},  {0x08, 'C'}, {0x09, 'V'},
    {0x0B, 'B'},  {0x0C, 'Q'}, {0x0D, 'W'},  {0x0E, 'E'}, {0x0F, 'R'},
    {0x10, 'Y'},  {0x11, 'T'}, {0x12, '1'},  {0x13, '2'}, {0x14, '3'},
    {0x15, '4'},  {0x16, '6'}, {0x17, '5'},  {0x18, '='}, {0x19, '9'},
    {0x1A, '7'},  {0x1B, '-'}, {0x1C, '8'},  {0x1D, '0'}, {0x1E, ']'},
    {0x1F, 'O'},  {0x20, 'U'}, {0x21, '['},  {0x22, 'I'}, {0x23, 'P'},
    {0x25, 'L'},  {0x26, 'J'}, {0x27, '\''}, {0x28, 'K'}, {0x29, ';'},
    {0x2A, '\\'}, {0x2B, ','}, {0x2C, '/'},  {0x2D, 'N'}, {0x2E, 'M'},
    {0x2F, '.'},  {0x32, '`'}, {0x41, '.'},  {0x43, '*'}, {0x45, '+'},
    {0x47, 'C'},  {0x4B, '/'}, {0x4C, '\n'}, {0x4E, '-'}, {0x51, '='},
    {0x52, '0'},  {0x53, '1'}, {0x54, '2'},  {0x55, '3'}, {0x56, '4'},
    {0x57, '5'},  {0x58, '6'}, {0x59, '7'},  {0x5B, '8'}, {0x5C, '9'}};

constexpr char none = ' ';

[[nodiscard]] inline auto mapCodeToChar(CGKeyCode code) -> const char & {

  return keyMap.find(code) != std::end(keyMap) ? keyMap.at(code) : none;
}

using historgram_t = std::map<char, int>;
struct KL_Data {
  uint32_t total_keystrokes{};
  historgram_t map{};
};
static KL_Data data{};
inline void print_map() {
  std::cout << "{ \n";
  for (const auto &[k, v] : data.map) {
    printf("\t\t{%c, %i}, \n", k, v);
  }
  std::cout << "}\n";
}
static constexpr CGEventMask kl_mask{1 << kCGEventKeyDown};
} // namespace KL

class KeystrokeListener : Listener<KL::kl_mask> {

private:
  static CGEventRef keystrokeCallbackOnEvent(CGEventTapProxy proxy,
                                             CGEventType type, CGEventRef event,
                                             void *userInfo) {
    auto key_code = static_cast<CGKeyCode>(
        CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode));

    auto curr_char = KL::mapCodeToChar(key_code);

    ++KL::data.total_keystrokes;
    ++KL::data.map[curr_char];
    std::clog << "Pressed the " << curr_char << " Key."
              << "\n\t Total Count is:  " << KL::data.total_keystrokes
              << " \n\t Whole historgram_t: \t";

    KL::print_map();
    return event;
  }

public:
  KeystrokeListener() : Listener(keystrokeCallbackOnEvent) {}
};
