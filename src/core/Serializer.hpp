#pragma once

#include "KeystrokeListener.hpp"
#include "MouseClickListener.hpp"

namespace Serializer {

struct WholeData {
  int date;
  MCL::MCL_Data *mcl_data;
  KL::KL_Data *kl_data;

  void flush() {
    *mcl_data = {};
    *kl_data = {};
  }
};

void serialize() {
  WholeData data{0, &MCL::data, &KL::data};

  /**
   *Do serialization shit w nlohmann
   *
   */

  data.flush();
}

} // namespace Serializer
