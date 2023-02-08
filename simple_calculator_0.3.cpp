#include <bits/stdc++.h>

using namespace std;

int arithmetic(int num1, int num2, char op);
int arithmetic1(int num, char op);

int main(int argc, char *argv[])
{
	if (argc == 4)
	{
		int num1, num2;
		char op;

		num1 = atoi(argv[1]);
		op = argv[2][0];
		num2 = atoi(argv[3]);

		cout << arithmetic(num1, num2, op) << endl;
	}
	else if (argc == 3)
	{
		int num;
		char op;

		num = atoi(argv[2]);
		op = argv[1][0];

		cout << arithmetic1(num, op) << endl;
	}
	else
	{
		cout << "Invalid parameter" << endl;
		exit(1);
	}
	return 0;
}

int arithmetic(int num1, int num2, char op)
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
            if (num2 == 0) {
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

int arithmetic1(int num, char op)
{
	switch (op)
	{
        case 'c':
            return cos(num);
        case 's':
            return sqrt(num);
        default:
            cout << "Invalid operator" << endl;
        exit(1);
	}
}


