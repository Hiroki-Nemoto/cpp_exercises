#include <iostream>
#include "stack.h"

using namespace std;

int main(void) {
    Stack stack;

    stack.push("Good morning!");
    stack.push("Hello!");

    cout <<  stack.top() << endl;

    stack.pop();

    cout <<  stack.top() << endl;

    stack.pop();
    stack.pop();

    stack.push("Good evening!");

    cout <<  stack.top() << endl;

    return 0;
}