// test_inc.cpp"
// #include <cassert>
#include <iostream>
#include "inc.h"
#include <cassert>
// COMPLETE Include any additional necessary headers here

int main(void) {
    double a = 1.0;
    inc(a);
    assert(a == 2.0);
    inc(a);
    assert(a == 3.0);

    a = 1.0;
    inc(&a);
    assert(a == 2.0);
    inc(&a);
    assert(a == 3.0);

    return 0;
}