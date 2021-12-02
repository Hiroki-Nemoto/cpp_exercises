#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string data) {
    string d = data;

    transform(d.begin(), d.end(), d.begin(),
        [](unsigned char c) { return tolower(c); });

    d.erase(remove(d.begin(), d.end(), ' '), d.end());
    d.erase(remove(d.begin(), d.end(), ','), d.end());
    d.erase(remove(d.begin(), d.end(), '\''), d.end());
    d.erase(remove(d.begin(), d.end(), '?'), d.end());
    d.erase(remove(d.begin(), d.end(), '.'), d.end());
    d.erase(remove(d.begin(), d.end(), '!'), d.end());
    d.erase(remove(d.begin(), d.end(), '\"'), d.end());
    d.erase(remove(d.begin(), d.end(), ';'), d.end());
    d.erase(remove(d.begin(), d.end(), ':'), d.end());
    d.erase(remove(d.begin(), d.end(), '-'), d.end());

    if (equal(d.begin(), d.begin() + d.size() / 2, d.rbegin())) {
        cout << data << ": palindrome" << endl;
        return true;
    }
    else {
        cout << data << ": Not palindrome" << endl;
        return false;
    }
}


int main() {
    string data1 = "Don't nod";
    string data2 = "Pull up if I pull up";
    string data3 = "Hello";
    string data4 = "My name is Hiroki";
    isPalindrome(data1);
    isPalindrome(data2);
    isPalindrome(data3);
    isPalindrome(data4);

    return 0;
}