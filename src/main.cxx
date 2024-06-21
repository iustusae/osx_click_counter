#include "core/KeystrokeListener.hpp"
#include "core/Listener.hpp"
#include "core/MouseClickListener.hpp"
#include <vector>

int main() {
  MouseClickListener listener{};
  KeystrokeListener k_listener{};

  core::listenToEvents();
}
