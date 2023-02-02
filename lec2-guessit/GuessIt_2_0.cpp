#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int minNumber = 1;
const int maxNumber = 100;

int totalScore, timesGuessed;

int generateRandomNumber();
int getPlayerGuess();
void printAnswer(int number, int randomNumber);
void playGuessIt();

int main()
{
	srand(time(0));
	char isContinued;
	do
	{
		timesGuessed = 0;
		playGuessIt();
		cout << "You guessed " << timesGuessed << " time(s)" << endl;
		totalScore += maxNumber - timesGuessed;
		cout << "Do you want to play again (y/n) ?  " << endl;
		cin >> isContinued;
		if (isContinued == 'n' || isContinued == 'N')
			cout << "Your score: " << totalScore << endl;
	} while (isContinued == 'y' || isContinued == 'Y');
	return 0;
}

int generateRandomNumber()
{
	return rand() % maxNumber + minNumber;
}

int getPlayerGuess()
{
	int number;
	cout << endl
		 << "Enter your number between " << minNumber << " and " << maxNumber << ": ";
	cin >> number;
	timesGuessed++;
	return number;
}

void printAnswer(int number, int randomNumber)
{
	if (number > randomNumber)
	{
		cout << "Your number is higher." << endl;
	}
	else if (number < randomNumber)
	{
		cout << "Your number is lower." << endl;
	}
	else
	{
		cout << "Congratulation! You win." << endl;
	}
}

void playGuessIt()
{
	int randomNumber = generateRandomNumber();
	int number;

	do
	{
		number = getPlayerGuess();
		printAnswer(number, randomNumber);
	} while (number != randomNumber);
}
