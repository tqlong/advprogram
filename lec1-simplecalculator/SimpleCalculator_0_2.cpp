// Lương Ngọc Tuấn - K67CC - 22021146

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>

using namespace std;

double arithmetic(double num1, double num2, char op) {
    switch(op){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case 'x':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                cout << "invalid divisor";
                exit(1);
            }
            else return num1 / num2;
        case '%':
            if (num2 == 0) {
                cout << "invalid divisor";
                exit(1);
            }
            else {
                if (num1 != (int)num1 || num2 != (int)num2) {
                    cout << "invalid number";
                    exit(1);
                }
                else return (int)num1 % (int)num2;
            }
            
        default:
            cout << "invalid calculation";
            exit(1);
    }
}

double calculus(double num, string op) {
    if (op == "sqrt") {
        if (num < 0) {
            cout << "invalid number";
            exit(1);
        }
        else return sqrt(num);
    }
    else if (op == "sin") return sin(num);
    else if (op == "cos") return cos(num);
    else if (op == "tan") return tan(num);
    else if (op == "cot") return 1.0/tan(num);
    else {
        cout << "invalid calculation";
        exit(1);
    }
}

int main(int argc, char* argv[]) {
    if (argc > 4 || argc < 3) cout << "invalid number of arguments";
    else {
        if (argc == 4) {
            double num1 = atoi(argv[1]);
            double num2 = atoi(argv[3]);
            char op = argv[2][0];
            cout << arithmetic(num1, num2, op);
        }
        else {
            if (argv[2][0] < '0' || argv[2][0] > '9') cout << "invalid calculation";
            else {
            double num = atoi(argv[2]);
            string op = argv[1];
            cout << calculus(num, op);
            }
        }
    }
    return 0;
}
