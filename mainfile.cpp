#include <iostream>
#include "WindowSwitcher.h"

int main() {
    WindowSwitcher switcher;
    std::string command;

    std::cout << "=== Window Switcher (C++ DSA Project) ===\n";

    while (true) {
        std::cout << "\nOptions: open, next, prev, close, reopen, current, exit\n>> ";
        std::cin >> command;

        if (command == "open") {
            std::string app;
            std::cout << "Enter app name: ";
            std::cin.ignore(); // clear buffer
            std::getline(std::cin, app);
            switcher.openWindow(app);
        } else if (command == "next") {
            switcher.switchNext();
        } else if (command == "prev") {
            switcher.switchPrev();
        } else if (command == "close") {
            switcher.closeCurrent();
        } else if (command == "reopen") {
            switcher.reopenLastClosed();
        } else if (command == "current") {
            switcher.displayCurrent();
        } else if (command == "exit") {
            std::cout << "Exiting Window Switcher.\n";
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}
C:\Users\GOVIND\manika\WindowNode.h
