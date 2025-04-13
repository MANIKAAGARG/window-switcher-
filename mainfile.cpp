#include <iostream>
#include "WindowSwitcher.h"
using namespace std;

int main() {
    WindowSwitcher switcher;
    string command;

    cout << "=== Window Switcher (C++ DSA Project) ===\n";

    while (true) {
        cout << "\nOptions: open, next, prev, close, reopen, current, exit\n>> ";
        cin >> command;

        if (command == "open") {
            string app;
            cout << "Enter app name: ";
            cin.ignore(); // clear buffer
            getline(cin, app);
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
            cout << "Exiting Window Switcher.\n";
            break;
        } else {
            cout << "Unknown command.\n";
        }
    }

    return 0;
}
