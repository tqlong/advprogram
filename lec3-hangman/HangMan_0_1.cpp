#include <iostream>

using namespace std;

const int MAX_BAD_GUESSES = 7;

string chooseWord();
void renderGame(string guessedWord, int badGuessCount);
char readAGuess();
bool contains(string word, char guess);
string update(string guessedWord, string word, char guess);

int main()
{
	string word = chooseWord();
	string guessedWord = string(word.length(), '-');
	int badGuessCount = 0;
	
	do {
		renderGame(guessedWord, badGuessCount);
		char guess = readAGuess();
		if (contains(word, guess)) 
			guessedWord = update(guessedWord, word, guess);
		else badGuessCount++;
	} while (badGuessCount < MAX_BAD_GUESSES && word != guessedWord);
	
	renderGame(guessedWord, badGuessCount);
	if (badGuessCount < MAX_BAD_GUESSES) 
		cout << "Congratulations! You win!";
	else 
		cout << "You lost. The correct word is " << word; 
		
	return 0;
}

string chooseWord() 
{
	return "book";
}

void renderGame(string guessedWord, int badGuessCount)
{
	cout << guessedWord << endl;
	cout << "Number of wrong guesses: " << badGuessCount << endl;
}

char readAGuess() 
{
	char input;
	cout << "Your guess: ";
	cin >> input;
	return input;
}

bool contains(string word, char c)
{
	return (word.find_first_of(c) != string::npos);
}

string update(string guessedWord, string word, char guess)
{
	for (int i = word.length() - 1; i >= 0; i--) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
    return guessedWord;
}
