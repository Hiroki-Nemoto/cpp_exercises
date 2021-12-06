#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>

using namespace std;

double evaluate(const string data){
    double x, y, z;
    char flag;
    stringstream ss(data);
    stack<double> operand;
    stack<char> operat;
    string d;

    map<char, int> judge;
    judge['+'] = 1;
    judge['-'] = 1;
    judge['*'] = 2;
    judge['/'] = 2;
    judge['('] = 0;
    judge[')'] = 0;

    operat.push('\0');

    while(ss >> d){
        if(d == "+" || d == "-" || d == "*" || d == "/"){
            flag = *d.c_str();
            operat.push(flag);
            continue;
        }

        else if(d == "("){
            continue;
        }

        else if(d == ")"){
            if(operat.top() == '+'){
                operat.pop();
                y = operand.top();
                operand.pop();
                x = operand.top();
                operand.pop();
                operand.push(x + y);
            }

            else if(operat.top() == '-'){
                operat.pop();
                y = operand.top();
                operand.pop();
                x = operand.top();
                operand.pop();
                operand.push(x - y);
            }

            else if(operat.top() == '*'){
                operat.pop();

                y = operand.top();
                operand.pop();
                x = operand.top();
                operand.pop();
                operand.push(x * y);
            }

            else if(operat.top() == '/'){
                operat.pop();
                y = operand.top();
                operand.pop();
                x = operand.top();
                operand.pop();
                operand.push(x / y);
            }
            continue;
        }

        else{
            operand.push(stod(d));
            continue;
        }
    }

    while(operat.top() != '\0'){
        if(judge[operat.top()] == 2){
            if(operat.top() == '*'){
                operat.pop();
                y = operand.top();
                operand.pop();
                x = operand.top();
                operand.pop();
                operand.push(x * y);
            }

            else if(operat.top() == '/'){
                operat.pop();
                y = operand.top();
                operand.pop();
                x = operand.top();
                operand.pop();
                operand.push(x / y);
            }
        }

        else if(judge[operat.top()] == 1){
            flag = operat.top();
            operat.pop();
            if(judge[operat.top()] == 1 || operat.top() == '\0'){
                if(flag == '+'){
                    y = operand.top();
                    operand.pop();
                    x = operand.top();
                    operand.pop();
                    operand.push(x + y);
                }

                else if(flag == '-'){
                    y = operand.top();
                    operand.pop();
                    x = operand.top();
                    operand.pop();
                    operand.push(x - y);
                }
            }

            else if(judge[operat.top()] == 2){
                z = operand.top();
                operand.pop();
                if(operat.top() == '*'){
                    operat.pop();
                    operat.push(flag);
                    y = operand.top();
                    operand.pop();
                    x = operand.top();
                    operand.pop();
                    operand.push(x * y);
                    operand.push(z);
                    continue;
                }

                else if(operat.top() == '/'){
                    operat.pop();
                    operat.push(flag);
                    y = operand.top();
                    operand.pop();
                    x = operand.top();
                    operand.pop();
                    operand.push(x / y);
                    operand.push(z);
                    continue;
                }
            }
            continue;
        }
    }
    return operand.top();
}

int main(){
    string data1 = "3 + 5 * 6 - 7 * ( 8 + 5 )";
    string data2 = "25.0 * 12.0 / 5.0 - 8.0";
    string data3 = "( 10.0 / 5.0 ) * 5 + 5 - ( 6.0 - 1.0 )";

    cout <<  fixed << setprecision(1);

    cout << "Input: " << data1 << endl;
    cout << "Output: "<< evaluate(data1) << endl;

    cout << "Input: " << data2 << endl;
    cout << "Output: "<< evaluate(data2) << endl;

    cout << "Input: " << data3 << endl;
    cout << "Output: "<< evaluate(data3) << endl;
    return 0;

}