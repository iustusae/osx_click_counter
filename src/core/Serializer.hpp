
#ifndef SERIALIZER_CC_HPP
#define SERIALIZER_CC_HPP
#include "ListenerDataTypes.h"
#include <chrono>
#include <fstream>
#include <nlohmann/json.hpp>
#include <sstream>

namespace Serializer {

    inline void serialize(const WholeData &wholedata) {
        nlohmann::json j{};
        j.push_back(wholedata.m_data);

        std::ofstream file("click_count.json");
        file << j.dump(4);
    }
} // namespace Serializer

#endif
