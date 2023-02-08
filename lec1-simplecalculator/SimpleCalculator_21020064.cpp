#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string.h>
using namespace std;

double arithmetic(int num, char *op) { // No switch case for string
  if (strcmp(op, "sin") == 0) return sin(num);
  if (strcmp(op, "cos") == 0) return cos(num);
  if (strcmp(op, "tan") == 0) return tan(num);
  if (strcmp(op, "sqrt") == 0) return sqrt(num);
  return 0;
}

int arithmetic(int num1, int num2, char op) {
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
    } else
      return num1 / num2;
  case '%':
    if (num2 == 0) {
      cout << "Invalid divisor" << endl;
      exit(1);
    } else
      return num1 % num2;
  default:
    cout << "Invalid operator" << endl;
    exit(1);
  }
}

int main(int argc, char *argv[]) {
  if (argc == 4) {
    int num1 = atoi(argv[1]), num2 = atoi(argv[3]);
    char op = argv[2][0];
    cout << arithmetic(num1, num2, op);
  } else if (argc == 3) {
    char *op = argv[1];
    stringstream ss(argv[2]);
    int num;
    ss >> num;
    cout << arithmetic(num, op);
  } else {
    cout << "-h\nThis is a simple calculator with no manual";
  }
}