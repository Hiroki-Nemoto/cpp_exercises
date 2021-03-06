// stringToInt.cpp
#include <string>
#include <sstream>
#include <iostream>
#include <stdexcept>

using namespace std;

int stringToInt(const string& input) {
    stringstream instream;
    instream << input;
    int number;
    instream >> number;

    if (instream.fail()) {
    // Error: the input can not be converted
    throw invalid_argument("input can not be converted to an int");
    }
    char left;
    instream >> left;
    if (!instream.fail()) {
        // Error: there are some characters left after the int
        throw invalid_argument("input can not be converted to an int");
    }
    // everything went fine: returns the int
    return number;
    }

    int main(void) {
        try {
    string test1 = "-1";
    cout << stringToInt(test1) << endl;
        }
        catch(invalid_argument const &ex) {
            cout << ex.what() << endl;
        }

        try{
    string test2 = "cc11";
    cout << stringToInt(test2) << endl;
        }
        catch(invalid_argument const &ex){
            cout << ex.what() << endl;
        }

        try{
    string test3 = "11cc";
    cout << stringToInt(test3) << endl;
        }
        catch(invalid_argument const &ex){
            cout << ex.what() << endl;
        }
    return 0;
}