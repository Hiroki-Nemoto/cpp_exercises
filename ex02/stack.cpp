#include <iostream>
#include "stack.h"

bool Stack::empty() {
    if(_top == -1) {
        return true;
    } else return false;
}

bool Stack::full() {
    if(_top + 1 == _max_size) {
        return true;
    } else return false;
}

int Stack::size() {
    return _top;
}

void Stack::push(std::string data) {
    if(full()){
        std::cout << "Error: Stack is full!" << std::endl;
    } else {
        _data[++_top] = data;
    }
}


void Stack::pop() {
    if(empty()){
        std::cout<<"Error: Stack is empty!" << std::endl;
    } else {
        _data[--_top];
    }
}

std::string Stack::top() {
    return _data[_top];
}
