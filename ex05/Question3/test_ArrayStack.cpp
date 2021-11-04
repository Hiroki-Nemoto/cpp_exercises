// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void) {
    // ...
    // here is the code from question 1 and 2
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

  // Move
    ArrayStack stack7 = std::move(stack5);

    stack6 = std::move(stack2);

    // COMPLETE
    // Show the content of the stacks 'stack5', 'stack7', 'stack6' and 'stack2'
    // (use the same method as in question 2)
    while(!stack5.empty()){
        std::cout <<  stack5.top() << std::endl;
        stack5.pop();
    }

    while(!stack7.empty()){
        std::cout <<  stack7.top() << std::endl;
        stack7.pop();
    }

    while(!stack6.empty()){
        std::cout <<  stack6.top() << std::endl;
        stack6.pop();
    }

    while(!stack2.empty()){
        std::cout <<  stack2.top() << std::endl;
        stack2.pop();
    }

    return 0;
}