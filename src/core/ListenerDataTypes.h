//
// Created by Ayman Ougri on 7/1/24.
//

#ifndef CLICK_COUNTER_LISTENERDATATYPES_H
#define CLICK_COUNTER_LISTENERDATATYPES_H

#include <chrono>
#include <cstddef>
#include <map>
#include <nlohmann/json.hpp>
#include <nlohmann/ordered_map.hpp>
using historgram_t = std::map<char, int>;
struct KL_Data {
  uint32_t total_keystrokes{};
  historgram_t map{};
};

inline auto to_json(nlohmann::json &j, const KL_Data &data) -> void {
  j = {{"total_keystrokes", data.total_keystrokes},
       {"keys_histogram", data.map}};
}

inline auto from_json(const nlohmann::json &j, KL_Data &to) -> void {
  j.at("total_keystrokes").get_to(to.total_keystrokes);
  j.at("keys_histogram").get_to(to.map);
}

struct MCL_Data {
  uint32_t click_count{0};
  uint32_t r_click_count{0};
  uint32_t l_click_count{0};
};

inline auto to_json(nlohmann::json &j, const MCL_Data &data) -> void {
  j = {{"click_count", data.click_count},
       {"right_click", data.r_click_count},
       {"left_click", data.l_click_count}};
}

inline auto from_json(const nlohmann::json &j, MCL_Data &to) -> void {
  j.at("click_count").get_to(to.click_count);
  j.at("right_click").get_to(to.r_click_count);
  j.at("left_click").get_to(to.l_click_count);
}

using listener_pair_t = std::pair<MCL_Data, KL_Data>;
inline auto to_json(nlohmann::json &j, const listener_pair_t &data) -> void {
  j = {{"click_data", data.first}, {"keyboard_data", data.second}};
}

inline auto from_json(const nlohmann::json &j, listener_pair_t &to) -> void {
  j.at("click_data").get_to(to.first);
  j.at("keyboard_data").get_to(to.second);
}

struct WholeData {
  std::chrono::year_month_day m_date{};
  listener_pair_t m_data{};
};

inline auto to_json(nlohmann::json &j, const WholeData &data) -> void {
  j = {{"data", data.m_data}};
}

inline auto from_json(const nlohmann::json &j, WholeData &data) -> void {
  j.at("data").get_to(data.m_data);
}

#endif // CLICK_COUNTER_LISTENERDATATYPES_H
