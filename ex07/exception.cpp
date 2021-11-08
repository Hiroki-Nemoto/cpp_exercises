 // exception.cpp
#include <stdexcept>
#include <cstdio>
#include <iostream>
#include <memory>

using namespace std;

void doSomeComputation() {
    throw runtime_error("failure during doing some computation");
}

void example() {
    FILE* logfile = fopen("logfile.txt", "w+");

    try {
        if (!logfile) {
            throw runtime_error("failed to open file");
        }
        fputs("log - 1", logfile);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        fclose(logfile);
        throw;
    }

  // Call a function that performs some computation and may throw
  // an exception
    try {
    doSomeComputation();
    }
    catch (const runtime_error& e) {
        cout<< e.what() << endl;
    }
    try {
        if (!logfile) {
            throw runtime_error("failed to open file");
        }
        fputs("log - 2", logfile);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
        fclose(logfile);
        throw;
    }
    cout << "closing logfile" << endl;
    fclose(logfile);
}

int main(void) {
    cout << "Calling example()" << endl;
    example();
    cout << "After calling example()" << endl;
    return 0;
}