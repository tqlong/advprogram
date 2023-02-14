#include <iostream>
#include <cstdlib>

using namespace std;

int arithmetic(int num1, int num2, char op);

int main(int argc, char* argv[])
{
    int num1, num2, result;
    if (argc == 3) {
      cout << unary_arithmetic(...)
    }
    else {
      char op;

      num1 = atoi(argv[1]);
      op = argv[2][0];
      num2 = atoi(argv[3]);

      cout << arithmetic(num1, num2, op) << endl;

    }
   
    return 0;
}

double unary_arithmetic(int num1, const string& op) {
  switch (op)
  {
    case "cos":
      break
    case "tan":
      break
    default:
      cout << "unsupport operator";
  }
}

int binary_arithmetic(int num1, int num2, char op)
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
        if (num2 == 0)
        {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return num1 % num2;
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
}
