#include <bits/stdc++.h>
using namespace std;
int generateRandomNumber();
int getPlayerGuess();
int solandoan = 0; int tongdiem = 0;
void playGuessIt();
void printAnswer(int number, int randomNumber);
int main()
{
  bool play_again = true;
  while (play_again)
  {
    playGuessIt();
	cout << "One more time (y / n)?";
    char answer;
    cin >> answer;
    if (tolower(answer) != 'y')
    {
        play_again = false;
    }
  }
  return 0;
}

void playGuessIt()
{
	int randomNumber = generateRandomNumber();
	    int number;
	    do {
	        number = getPlayerGuess();
	        printAnswer(number, randomNumber);
	    } while (number != randomNumber);
}
int generateRandomNumber()
{
    int a;
    srand (time(0));
    a = rand() % 100 + 1;
    return a;
}

int getPlayerGuess()
{
    int number;
    cout << endl << "Enter your number between 1 and 100: ";
    cin >> number;
    while(cin.fail())
    {
        cin.clear();
        cin.ignore();
        cin >> number;
    }
    if (number > 100 || number <= 0)
    {
    	return number;
    }
    else {solandoan++;
    return number;}
}

void printAnswer(int number, int randomNumber)
{
	if (number > 100 || number <= 0) {
        cout <<"Invalid number, guess again." << endl;}
	else if (number > randomNumber) {
        cout <<"Your number is higher." << endl;
    } else if (number < randomNumber) {
        cout <<"Your number is lower." << endl;
    } else {
        cout << "Congratulation! You win." << endl;
        cout << "So lan doan cua ban la: " << solandoan << endl;
        cout << "Diem cua ban la: " << 100 - solandoan << endl;
    }
}

