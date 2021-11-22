#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

double evaluateFP(string data) {
    stack<double> operand;
    stack<string> operat;
    stringstream ss(data);
    string d;

    while(ss >> d) {
        if(d == "+" || d == "-" || d == "*" || d == "/"){
            operat.push(d);
        }
        else if(d == "(" ) {
        }
        else if(d == ")" ) {
            double a1 = operand.top();
            operand.pop();
            double a2 = operand.top();
            operand.pop();
            string a3 = operat.top();
            if(a3 == "+") {
                operat.pop();
                double b1 = a2 + a1;
                operand.push(b1);
            } else if(a3 == "-") {
                operat.pop();
                double b2 = a2 - a1;
                operand.push(b2);
            } else if(a3 == "*") {
                operat.pop();
                double b3 = a2 * a1;
                operand.push(b3);
            } else if(a3 == "/") {
                operat.pop();
                double b4 = a1 / a2;
                operand.push(b4);
            }
        }
        else operand.push(stod(d));
    }
    return operand.top();
}


int main() {
    string data1 = "( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )";
    string data2  = "( ( ( 2.0 * ( 3.0 - 1.0 ) ) - 5.0 ) * 3.0 )";
    string data3 = "( 1 + ( ( 1 + 1 ) * ( 1 * 1 ) ) )";

    cout << fixed << setprecision(1);

    cout << "Input: " << data1 << endl;
    cout << "output: " << evaluateFP(data1) << endl;
    cout << "Input: " << data2 << endl;
    cout << "output: " << evaluateFP(data2) << endl;
    cout << "Input: " << data3 << endl;
    cout << "output: " << evaluateFP(data3) << endl;
}
