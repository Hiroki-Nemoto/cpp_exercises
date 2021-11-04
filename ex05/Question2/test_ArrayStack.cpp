// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void) {
    // ...
    // insert the code from question 1
    // ...
    ArrayStack stack1;

    stack1.push(1.0);
    stack1.push(2.0);
    stack1.push(3.0);
    stack1.push(4.0);
    stack1.push(5.0);

    ArrayStack stack2;

    stack2.push(1.0);
    stack2.push(2.0);
    stack2.push(3.0);
    stack2.push(4.0);
    stack2.push(5.0);
    stack2.push(6.0);
    stack2.push(7.0);
    stack2.push(8.0);
    stack2.push(9.0);
    stack2.push(10.0);

    // Copy
    ArrayStack stack3(stack1);
    ArrayStack stack4 = stack2;

    // Assignment
    ArrayStack stack5;
    stack5 = stack1;
    ArrayStack stack6(10);
    stack6 = stack6;

    // COMPLETE 
    // Show the content of the stacks 'stack1', 'stack3' and 'stack4' by calls to pop() and top() 
    // (use a loop and the method ArrayStack::empty() for the termination condition)
    while(!stack1.empty()){
        std::cout <<  stack1.top() << std::endl;
        stack1.pop();
    }

    while(!stack3.empty()){
        std::cout <<  stack3.top() << std::endl;
        stack3.pop();
    }
    while(!stack4.empty()){
        std::cout <<  stack4.top() << std::endl;
        stack4.pop();
    }

    return 0;
}