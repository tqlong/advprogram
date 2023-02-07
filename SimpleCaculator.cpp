#include <iostream>
#include <cstdlib>
#include <sstream>

int arithmetic(int num1, int num2, char op);
double arithmetic(double num, std::string& op);
double arithmetic(double num1, double num2, char op);

int main(int argc, char* argv[])
{
	if (argc == 3)
	{
		double num;
		std::string op;

		std::stringstream ss;
		op = argv[1];
		ss << argv[2];
		ss >> num;	
		std::cout << arithmetic(num, op);
	}
	else 
		if (argc == 4)
		{
			int num1 = atoi(argv[1]);
			int num2 = atoi(argv[3]);
			char op = argv[2][0];
			std::cout << arithmetic(num1, num2, op);
		}	
	return 0;
}

double arithmetic(double number, std::string &op)
{
	if (op == "cos")
	{
		return std::cos(number);
	}
	else 
		if (op == "sqrt")
		{
			if (number >= 0)
			{
				return sqrt(number);
			}
			else
			{
				std::cout << "Invalid Divisor";
				exit(1);
			}
			
		}
}

double arithmetic(double number1, double number2, char op)
{
	switch (op)
	{
	case '+':
		return number1 + number2;
	case '-':
		return number1 - number2;
	case '*':
		return number1 * number2;
	case '/':
		if (number2 == 0)
		{
			std::cout << "Invalid Divisor";
			exit(1);
		}
		else return number1 / number2;
	case '%':
	{
		int num1 = number1;
		int num2 = number2;
		if (num2 == 0)
		{
			std::cout << "Invalid Divisor";
			exit(1);
		}
		else return num1 % num2;
	}
	default:
		std::cout << "Invalid Divisor";
		exit(1);
	}
	exit(1);
}

int arithmetic(int number1, int number2, char op)
{
	switch (op)
	{
	case '+':
		return number1 + number2;
	case '-':
		return number1 - number2;
	case '*':
		return number1 * number2;
	case '/':
		if (number2 == 0)
		{
			std::cout << "Invalid Divisor";
			exit(1);
		}
		else return number1 / number2;
	case '%':
	{
		int num1 = number1;
		int num2 = number2;
		if (num2 == 0)
		{
			std::cout << "Invalid Divisor";
			exit(1);
		}
		else return num1 % num2;
	}
	default:
		std::cout << "Invalid Divisor";
		exit(1);
	}
	exit(1);
}
