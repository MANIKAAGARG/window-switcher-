#ifndef WINDOWNODE_H
#define WINDOWNODE_H

#include <string>

class WindowNode {
public:
    std::string appName;
    WindowNode* prev;
    WindowNode* next;

    WindowNode(const std::string& name) {
        appName = name;
        prev = nullptr;
        next = nullptr;
    }
};

#endif
