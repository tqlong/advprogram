//simple_calculator.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>

using namespace std;

double arithmetic(double &num1,double &num2, char &op);
double arithmetic(string &func,double &num);

int main(int argc, char* argv[])
{
    double num1, num2, result;
    char op;
    if(argc == 3){ // Xu ly ham luong giac va can bac 2
        string func = argv[1];
        double num = atof(argv[2]);
        cout << arithmetic(func,num) << endl;
    }else{  // Xu ly tinh toan thong thuong
    num1 = atof(argv[1]);
    op = argv[2][0];
    num2 = atof(argv[3]);
    cout << arithmetic(num1, num2, op) << endl;
    }
    return 0;
}

double arithmetic(double &num1,double &num2, char &op)
{   double result;
    switch (op)
    {
    case '+':
        result =  num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case 'x':
        result =  num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            result = num1 / num2;
            break;
    case '%':
        if (num2 == 0)
        {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else if (num1-(int)num1 == 0 && num2 - (int)num2 == 0){
            result = (int)num1 % (int)num2;
            break;
        }
        else{
            cout << "Invalid number (float numbers aren't allowed with this operator)" << endl;
            exit(1);
        }
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
    if(abs(result) > 1e6){
        cout << "Result exceeded limit" << endl;
    }else{
        return result;
    }
    return 0;
}

double arithmetic(string &func,double &num){
    if(abs(num) > 1e6){
        cout << "Input exceed limit" << endl;
        return 0;
    }

    if(func.compare("cos") == 0){
        return cos(num);
    }else if(func.compare("sin") == 0){
        return sin(num);
    }else if(func.compare("tan") == 0 || func.compare("tg") == 0){
        if(abs(cos(num)) < 1e-9){
            cout << "Invalid input" << endl;
        }else
        return tan(num);
    }else if(func.compare("cot") == 0 || func.compare("cotg") == 0){
        if(abs(sin(num)) < 1e-9){
            cout << "Invalid input" << endl;
        }else
        return 1/tan(num);
    }else if(func.compare("sqrt") == 0 ){
        if(num < 0){
            cout << "Invalid input square root function" << endl;
            return 0;
        }else{
            return sqrt(num);
        }
    }
    else{
    cout << "Invalid Function" << endl;
    }
    return 0;
}



//Modified by 22021212_LeVuVietAnh
