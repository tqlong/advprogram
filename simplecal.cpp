#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

 using namespace std;

 int arithmetic(int num1, int num2, char op) {
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
 int main(int argc, char* argv[])
{

 int num1, num2;
 char op;
 num1 = atoi(argv[1]);
 op = argv[2][0];
 num2 = atoi(argv[3]);
 cout << arithmetic(num1, num2, op) << endl;
 return 0;
}
