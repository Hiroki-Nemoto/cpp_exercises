#include <iostream>
#include "stack.h"

int main(void) {
    Stack stack;

    stack.push("Good morning!");
    stack.push("Hello!");

    std::cout <<  stack.top() << std::endl;

    stack.pop();

    std::cout <<  stack.top() << std::endl;

    stack.pop();
    stack.pop();

    stack.push("Good evening!");

    std::cout <<  stack.top() << std::endl;

    return 0;
}
