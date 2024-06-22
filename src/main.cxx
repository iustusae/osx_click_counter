#include "core/KeystrokeListener.hpp"
#include "core/Listener.hpp"
#include "core/MouseClickListener.hpp"

int main() {
  MouseClickListener listener{};
  KeystrokeListener k_listener{};

  core::listenToEvents();
}
