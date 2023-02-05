#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int num1, num2;
    char op;
    cout << 1.7*pow(10,308) + 100000000 << endl;
    cin >> num1 >> op >> num2;
    switch (op)
    {
    case '+':
        cout << num1 + num2 << endl;
        break;
    case '-':
        cout << num1 - num2 << endl;
        break;
    case '*':
        cout << num1 * num2 << endl;
        break;
    case '/':
        if (num2 == 0)
            cout << "Invalid divisor" << endl;
        else
            cout << num1 / num2 << endl;
        break;
    case '%':
        if (num2 == 0)
            cout << "Invalid divisor" << endl;
        else
            cout << num1 % num2 << endl;
        break;
    default:
        cout << "Invalid operator" << endl;
    }
    return 0;
}
