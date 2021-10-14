#include <iostream>
#include "stack.h"

using namespace std;

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

void Stack::push(string data) {
    if(full()){
        cout << "Error: Stack is full!" << endl;
    } else {
        _data[++_top] = data;
    }
}


void Stack::pop() {
    if(empty()){
        cout<<"Error: Stack is empty!" << endl;
    } else {
        _data[--_top];
    }
}

string Stack::top() {
    return _data[_top];
}