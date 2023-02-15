#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    char op;

    cin >> num1 >> op >> num2;
    
    if (op=='+') {cout << num1+num2;}
    if (op=='-') {cout << num1-num2;}
    if (op=='*')  {cout << num1*num2;}
    if (op=='/' && num2!=0) {cout << num1/num2;}
    if (op=='%' && num2!=0) {cout << num1%num2;}
    if (op!='+' && op!='-' && op!='*' && op!='/' && op !='%') {cout << "Invalid operator";}
    if (op=='/' && num2==0) {cout << "Invalid divisor";}
    if (op=='%' && num2==0) {cout << "Invalid divisor";}
    return 0;
}
