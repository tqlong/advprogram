#include <bits/stdc++.h>

using namespace std;

double arithmetic (double num1, double num2, char op);
double getFunc (string func, double num1);

int main (int argc, char* argv[]) {
    double num1, num2, result;
    string func;
    char op;

    if (argc == 4) {
        stringstream s (argv[1]);
        s >> num1;
        op = argv[2][0];
        stringstream s2 (argv[3]);
        s2 >> num2;

        result = arithmetic(num1, num2, op);

        cout << result << endl;

        return 0;
    } else if (argc == 3) {
        func = argv[1];
        stringstream s (argv[2]);
        s >> num1;

        result = getFunc(func, num1);

        cout << result << endl;

        return 0;
    } else {
        cout << "Invalid parameters";
        exit(1);
    }
} 

double arithmetic (double num1, double num2, char op) {
    if (op == '+') {
        return num1 + num2;
    } else if (op == '-') {
        return num1 - num2;
    } else if (op == 'x') {
        return num1 * num2;
    } else if (op == '/') {
        if (num2 == 0) {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return num1 / num2;
    } else if (op == '%') {
        if (num2 == 0) {
            cout << "Invalid divisor" << endl;
            exit(1);
        } else {
            if ((int)num1 == num1 && (int) num2 == num2) {
                return (int)num1 % (int)num2;
            } else {
                cout << "Modulo can't be used on real number" << endl;
                exit(1);
            }
        }
    } else {
        cout << "Invalid operator" << endl;
        exit(1);
    }
}

double getFunc (string func, double num1) {
    if (func == "cos") {
        return cos (num1);
    } else if (func == "sin") {
        return sin (num1);
    } else if (func == "tan") {
        if (cos(num1) == 0) {
            cout << "Invalid parameters" << endl;
            exit (1);
        } else {
            return tan (num1);
        }
    } else if (func == "cot") {
        if (sin(num1) == 0) {
            cout << "Invalid parameters" << endl;
            exit(1);
        } else {
            return cos(num1) / sin(num1);
        }
    } else if (func == "sqrt") {
        if (num1 < 0) {
            cout << "Invalid parameters" << endl;
            exit(1);
        } else {
            return sqrt(num1);
        }
    } else {
        cout << "Invalid operator" << endl;
        exit(1);
    }
}