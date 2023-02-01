#include <bits/stdc++.h>
using namespace std;

int arithmetic(int num1, int num2, char op);
double sothuc(char op, double num);
int main(int argc, char* argv[])
{
    if (argc == 4)
    {
	int num1, num2;	char op;

    num1 = atoi(argv[1]);	
    op = argv[2][0];
    num2 = atoi(argv[3]);
	cout << arithmetic(num1, num2, op) << endl;
	return 0;
	}
	else if (argc == 3)
	{
		double num;
		string ape;
		char op;
		num = atoi(argv[2]);
		ape = argv[1][0];
		op = ape[0];
		cout << sothuc(op, num) << endl;
		return 0;
	}
}

int arithmetic(int num1, int num2, char op)
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
double sothuc(char op, double num)
{
	switch (op)
	{
		case 'c':
			return cos(num);
		case 's':
			if (num < 0)
			{
				cout << "Invalid number" << endl;
				exit(1);
			}
			else
				return sqrt(num);
		default:
			cout << "Invalid operator" << endl;
        	exit(1);
	}
}
