#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cmath>
#include <string>
using namespace std;

double arithmetic(double num1, double num2, char op);

int main(int argc, char* argv[])
{
    double num1, num2, result;
    char op;
    if (argc == 3)
    {
        string s;
        s = argv[1];
        num1 = atof(argv[2]);
        if (s == "cos")
            cout << cos(num1);
        if (s == "sqrt")
            cout << sqrt(num1);
        if (s == "sin")
            cout << sin(num1);
        if (s == "tan")
            cout << tan(num1);
        if (s != "cos" && s != "sqrt" && s != "sin" && s != "tan")
            cout << "tham so khong hop le!";
        exit(1);
    }
    if (argc != 3 && argc != 4)
    {
        cout << "so tham so khong hop le!";
        exit(1);
    }
    num1 = atof(argv[1]);
    op = argv[2][0];
    num2 = atof(argv[3]);

    cout << arithmetic(num1, num2, op) << endl;

    return 0;
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
    case '%':
        if (num1 != (int)num1 || num2 != (int)num2 || num2 == 0)
        {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return (int)num1 % (int)num2;
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
}
