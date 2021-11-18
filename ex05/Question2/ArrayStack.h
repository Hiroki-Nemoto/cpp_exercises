// ArrayStack.h

#include <string>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

class ArrayStack {
private:
    int _num_items; // number of items in the stack
    double* _items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size) {
        if (max_size==0) max_size++;

        // Move stack to a new array of size max
        _allocated_size = max_size;
        double* temp = new double[max_size];
        // Copy 
        for (int i = 0; i < _num_items; ++i) {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
        /* COMPLETE ... init _num_items to 0, _allocated_size to 0, and
     * set _items to the null pointer, 
     */
    ArrayStack() : _num_items(0),_items(nullptr),_allocated_size(0) {}
    
    ArrayStack(const ArrayStack& a) {
        _num_items = a._num_items;
        _allocated_size = a._allocated_size;
        _items = new double[a._allocated_size];
        _items = a._items;
        std::cout << "Copy Constructor" << std::endl;
    }
    
    ArrayStack& operator=(const ArrayStack& b){
        _num_items = b._num_items;
        _allocated_size = b._allocated_size;
        _items = new double[b._allocated_size];
        _items = b._items;
        std::cout << "Assignment Operator" << std::endl;
        return *this;
    }

    explicit ArrayStack(int allocated_size) {
        _num_items = 0;
        double* items = new double[allocated_size];
        _allocated_size = allocated_size;
        _items = items;
    /* COMPLETE ... init _num_items to 0, 
     * pre-allocate memory for an array of size allocated_size
     * and make _items point to it */
    }

    // Destructor:
    ~ArrayStack() {
        delete[] _items;
        // COMPLETE
    }

    void push(double item) {
        if (_num_items == _allocated_size) resize(2*_allocated_size);
        _items[_num_items++] = item;
    }

    void pop() {
        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size/4) resize(_allocated_size/2);
    }

    double top() {
        return _items[_num_items-1];
    }

    bool empty() const { return _num_items == 0; }

    int size() const { return _num_items; }
};

#endif // ARRAY_STACK_H
