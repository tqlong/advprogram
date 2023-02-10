#include<bits/stdc++.h>
using namespace std;

float arithmetic1(float num1, char op, float num2){
	switch(op){
		case '+':
			return num1 + num2;
		case '-':
			return num1 - num2;
		case 'x':
			return num1 * num2;
		case '/':
			if (num2 == 0){
				cout<<"Invalid divisor"<<endl;
				exit(1);
			}
			else{
				return num1 / num2;
			}
		default:
			cout<<"Invalid operator"<<endl;
			exit(1);
	}
}

float arithmetic2(float num1, char op){
	switch(op){
		case 'c':
			return cos(num1);
		case 's':
			return sqrt(num1);
		default:
			cout<<"Invalid operator"<<endl;
			exit(1);
	}
}

int main(int argc, char* argv[]){
	int n1, n2;
	char op;
	if (argc == 4){
		n1 = atoi(argv[1]);
		op = argv[2][0];
		n2 = atoi(argv[3]);
		cout<<arithmetic1(n1, op, n2);
	}
	if (argc == 3){
		n1 = atoi(argv[1]);
		op = argv[2][0];
		cout<<arithmetic2(n1, op);
	}
}

