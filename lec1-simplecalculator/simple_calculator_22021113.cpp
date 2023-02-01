//simple_calculator.cpp
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>

using namespace std;

double calc(const char* func, const double& num);
double calc(const char& op, const double& num1, const double& num2);
void invalidHandle(const int &code);

int main(int argc, char* argv[])
{
    if (argc == 3)      //sin x, cos x, tan x, tg x, cot x, cotg x, sqrt x
    {
        auto *func = argv[1];
        auto num = atof(argv[2]);
        cout << calc(func, num) << "\n";
    }
    else                //x + y, x - y, x x y, x . y, x / y, x : y
    {
        auto num1 = atof(argv[1]);
        auto num2 = atof(argv[3]);
        auto *op = argv[2];
        cout << calc(op[0], num1, num2) << "\n";
    }
}

///Calculate function for 2-argument commands
double calc(const char* func, const double& num)
{
    if (abs(num) > 1e6) invalidHandle(1);
    if (strcmp(func, "sin") == 0) return sin(num);
    else if (strcmp(func, "cos") == 0) return cos(num);
    else if (strcmp(func, "tan") == 0 || strcmp(func, "tg") == 0)
    {
        if (abs(cos(num)) < 1e-9) invalidHandle(0);
        else return tan(num);
    }
    else if (strcmp(func, "cot") == 0 || strcmp(func, "cotg") == 0)
    {
        if (abs(sin(num)) < 1e-9) invalidHandle(0);
        else return 1.0 / tan(num);
    }
    else if (strcmp(func, "sqrt") == 0)
    {
        if (num < 0) invalidHandle(0);
        else return sqrt(num);
    }
    else invalidHandle(0);
    return 0;
}

///Calculate function for 3-argument program
double calc(const char& op, const double& num1, const double& num2)
{
    double res = 0;
    switch(op)
    {
        case '+': 
        {
            res = num1 + num2;
            break;
        }
        case '-': 
        {
            res = num1 - num2;
            break;
        }
        case 'x':
        case '.':
        {
            res = num1 * num2;
            break;
        }
        case '/':
        case ':':
        {
            if (num2 == 0) invalidHandle(0);
            res = num1 / num2;
            break;
        }
        default: invalidHandle(0);
    }
    if (abs(res) > 1e6) invalidHandle(2);
    else return res;
    return 0;
}

///Handle invalid cases
void invalidHandle(const int& code)
{
    switch(code)
    {
        case 0: 
            cout << "Invalid input.";
            exit(1);
        case 1: 
            cout << "The input number(s) are too large.";
            exit(1);
        case 2: 
            cout << "The result exceeded number display limit.";
            exit(1);
        default: return;
    }
    
}

//written by kiennguyen246
