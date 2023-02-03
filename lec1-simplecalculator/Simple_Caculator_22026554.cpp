#include <bits/stdc++.h>
using namespace std;

double arithmetic(double num1, double num2, char op)
{
    switch (op) {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case 'x':
         return num1 * num2;
    case '/':
        if (num2 == 0) {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return num1 / num2;
    case '%':
        if (num2 == 0 || num2 != (int)num2 || num1 != (int)num1) {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else{
            return (int)num1 % (int)num2;
        }
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
}

double luonggiac(double num, string n)
{
    if (n == "cos"){
        return cos(num);
    }
    else if (n == "sin"){
        return sin(num);
    }
    else if (n == "tan"){
        return tan(num);
    }
    else if (n == "cot"){
        return (1/tan(num));
    }
}

int main(int argc, char* argv[])
{
    if(argc == 4){
        double  num1, num2;
        char op;
        num1 = atof(argv[1]);
        op = argv[2][0];
        num2 = atof(argv[3]);
        cout<< arithmetic(num1, num2, op);
    }
    else if (argc == 3){
        string n = argv[1];
        int s = n.length();
        if (s == 3){
            if ((n != "cos") && (n != "sin") && (n != "tan" && n != "cot")){
                cout<< "Invalid operator";
                exit(1);
            }
        }
        if (s == 4){
            if (n != "sqrt"){
                cout<< "Invalid operator";
                exit(1);
            }
        }
        double num;
        num = atof(argv[2]);
        cout<< luonggiac(num, n);
    }
    else {
        cout<< "Invalid operator";
        exit(1);
    }
    return 0;
}