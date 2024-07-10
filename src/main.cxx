#include "KeystrokeListener.hpp"
#include "Listener.hpp"
#include "ListenerDataTypes.h"
#include "MouseClickListener.hpp"
#include <thread>
#include <chrono>
#include <iostream>
#include <mutex> // Include the mutex header




int main() {
    // Create instances of event listeners

    WholeData wholeData{}; // Global instance of WholeData
    KeystrokeListener kl = KeystrokeListener(wholeData);
    MouseClickListener mcl = MouseClickListener(wholeData);

    // Start listening to events in the main program
    core::listenToEvents();



    return 0;
}
