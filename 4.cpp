#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
	int a = atoi(argv[1]);
	char b = argv[2][0];
	switch (b)
	{
		case 's':
			{
				cout << sqrt(a);
				break;
			}
		case 'c':
			{
				cout << cos(a);
				break;
			}
	}
	return 0;
}
