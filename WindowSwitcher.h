#ifndef WINDOWSWITCHER_H
#define WINDOWSWITCHER_H

#include <iostream>
#include <stack>
#include "WindowNode.h"
using namespace std;

class WindowSwitcher {
private:
    WindowNode* head;
    WindowNode* tail;
    WindowNode* current;
    stack<string> closedStack;

public:
    WindowSwitcher() {
        head = tail = current = nullptr;
    }

    void openWindow(const std::string& name) {
        WindowNode* newNode = new WindowNode(name);
        if (!head) {
            head = tail = current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "[Opened] " << name <<endl;
    }

    void switchNext() {
        if (current && current->next) {
            current = current->next;
        } else {
            cout << "Already at the last window.\n";
        }
        displayCurrent();
    }

    void switchPrev() {
        if (current && current->prev) {
            current = current->prev;
        } else {
            cout << "Already at the first window.\n";
        }
        displayCurrent();
    }

    void closeCurrent() {
        if (!current) {
            cout << "No windows to close.\n";
            return;
        }

        cout << "[Closed] " << current->appName <<endl;
        closedStack.push(current->appName);

        if (current == head && current == tail) {
            delete current;
            head = tail = current = nullptr;
            return;
        }

        if (current == head) {
            head = head->next;
            head->prev = nullptr;
            delete current;
            current = head;
        } else if (current == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete current;
            current = tail;
        } else {
            WindowNode* temp = current;
            current->prev->next = current->next;
            current->next->prev = current->prev;
            current = current->next;
            delete temp;
        }
    }

    void reopenLastClosed() {
        if (closedStack.empty()) {
            cout << "No recently closed windows.\n";
            return;
        }
        string name = closedStack.top();
        closedStack.pop();
        openWindow(name);
        current = tail;
        cout << "[Reopened] " << name <<endl;
    }

    void displayCurrent() {
        if (current) {
            cout << "[Current Window] " << current->appName <<endl;
        } else {
            cout << "No active windows.\n";
        }
    }
};

#endif
