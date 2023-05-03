#include <bits/stdc++.h>
using namespace std;

int arithmetic(double num1, double num2, char op);
double sothuc(string op, double num);
int main(int argc, char* argv[])
{
    if (argc == 4)
    {
	string n = argv[2];
    int k = n.length();
    if (k != 1)
    {
    	cout << "Invalid operator" << endl; return 0;
	}
	int num1, num2;	char op;
	string tmp = argv[1];
	string tmpp = argv[3];
	for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] < '0' || tmp[i] > '9')
		{
			cout << "Invalid number"; exit(1);
		}
	}
	for (int i = 0; i < tmpp.length(); i++)
	{
		if (tmpp[i] < '0' || tmpp[i] > '9')
		{
			cout << "Invalid number"; exit(1);
		}
	}
	num1 = atof(argv[1]);	
    op = argv[2][0];
    num2 = atof(argv[3]);
	cout << arithmetic(num1, num2, op) << endl;
	return 0;
	}
	else if (argc == 3)
	{
		string n = argv[1];
		int k = n.length();
		if (k == 3){
            if ((n != "cos") && (n != "sin") && (n != "tan" && n != "cot")){
                cout<< "Invalid operator";
                exit(1);
            }
        }
        if (k == 4){
            if (n != "sqrt"){
                cout<< "Invalid operator";
                exit(1);
            }
        }
        string tmp = argv[2];
        for (int i = 0; i < tmp.length(); i++)
	{
		if (tmp[i] < '0' || tmp[i] > '9')
		{
			cout << "Invalid number"; exit(1);
		}
	}
        double num;
        num = atof(argv[2]);
        cout<< sothuc(n, num);
    }
    else {
        cout<< "Invalid operator";
        exit(1);
    }
}

int arithmetic(double num1, double num2, char op)
{
    switch (op)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
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
        if (num2 == 0 || num2 != (int)num2 || num1 != (int)num1) 
        {
            cout << "Invalid divisor" << endl;
            exit(1);
        }
        else
            return int(num1) % int(num2);
    default:
        cout << "Invalid operator" << endl;
        exit(1);
    }
}
double sothuc(string op, double num)
{
	if (op == "sin")
	{
		return sin(num);	
	}
	else if (op == "cos")
	{
		return cos(num);
	}
	else if (op == "tan")
	{
		if (cos(num) == 0)
		{
			cout << "Invalid Number"; exit(1);
		}
		else return tan(num);	
	}
	else if (op == "cot")
	{
		if (sin(num) == 0)
		{
			cout << "Invalid Number"; exit(1);
		}
		else return (1/tan(num));
	}
	else if (op == "sqrt")
	{
		if (num < 0)
		{
			cout << "Invalid Number"; exit(1);
		}
		else return sqrt(num);
	}
	else {cout << "Invalid operator" << endl;
        	exit(1);}
}
