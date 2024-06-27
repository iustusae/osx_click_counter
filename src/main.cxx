#include "core/KeystrokeListener.hpp"
#include "core/Listener.hpp"
#include "core/MouseClickListener.hpp"
#include <type_traits>
auto main() -> int {
  MouseClickListener listener{};
  KeystrokeListener k_listener{};

  core::listenToEvents();
}
