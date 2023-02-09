#include <iostream>
#include <cstdlib>
#include <math.h>
#include <string>

using namespace std;

double arithmetic(double num1, double num2, char op);
double arithmetic2(string func, double num);
int main(int argc, char* argv[])
{
    
    if (argc == 4) {
        double num1, num2, result;
        char op;

        num1 = atof(argv[1]);
        op = argv[2][0];
        num2 = atof(argv[3]);

        cout << arithmetic(num1, num2, op) << endl;
    } else if (argc == 3) {
        int num, result;
        string func;
        num = atof(argv[2]);
        func = argv[1];

        cout << arithmetic2(func, num) << endl;
    }
   

    return 0;
}

double arithmetic2(string func, double num) {
    if (func == "sin") {
        return sin(num);
    } else if (func == "cos") {
        return cos(num);
    } else if (func == "sqrt") {
        return sqrt(num);
    } else {
        cout << "Invalid function" << endl;
        exit(1);
    }
}

double arithmetic(double num1, double num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case 'x':
        return num1 * num2;
    case '/':
        if (num2 == 0)
        {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return num1 / num2;
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
}