#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

 using namespace std;

 float arithmetic(float num1, float num2, char op) {
     switch(op)
     {
     case '+':
         {
    return num1+num2;
    break;
         }
    case '-':
         {
    return num1-num2;
    break;
         }
         case '*':
         {
    return num1*num2;
    break;
         }
         case '/':
         {
    if (num2==0)
    cout <<"Invalid divisor";
    return num1/num2;
    break;
         }
    case '%':
         {
    if (num2==0)
    break;
    cout <<"Invalid divisor";
    return num1%num2;
    break;
         }
    default:
 cout << "Invalid operator" << endl;
 exit(1);
     }
 }
 float arithmetic2(string func, float num) {
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

 int main(float argc, char* argv[])
{

  if (argc == 4) {
        float num1, num2, result;
        char op;

        num1 = atof(argv[1]);
        op = argv[2][0];
        num2 = atof(argv[3]);

        cout << arithmetic(num1, num2, op) << endl;
    } else if (argc == 3) {
        float num, result;
        string func;
        num = atof(argv[2]);
        func = argv[1];

        cout << arithmetic2(func, num) << endl;
    }


    return 0;
}

float arithmetic2(string func, float num) {
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
