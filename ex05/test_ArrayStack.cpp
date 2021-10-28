// test_ArrayStack.cpp
#include "ArrayStack.h"

int main(void) {
// Create an instance of ArrayStack named stack1
//   using the default constructor
    ArrayStack stack1;
// Push 1.0, 2.0, 3.0, 4.0, 5.0 in this stack
    stack1.push(1.0);
    stack1.push(2.0);
    stack1.push(3.0);
    stack1.push(4.0);
    stack1.push(5.0);
// Create another instance of ArrayStack named stack2
    ArrayStack stack2;
//   using the other constructor, specify an original size of 5
// Push 1.0, 2.0, ..., 10.0 in this stack
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
return 0;
}