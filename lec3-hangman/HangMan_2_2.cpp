#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <vector>
#include <fstream>
#include <algorithm>
#include "draw.h"

using namespace std;

const int MAX_BAD_GUESSES = 7;
const char DATA_FILE[] = "data/Ogden_Picturable_200.txt";

string chooseWord(const char* fileName);
char readAGuess();
bool contains(const string& word, char guess);
void updateGuessedWord(string& guessedWord, const string& word, char guess);

int main()
{
	srand(time(0));
	string word = chooseWord(DATA_FILE);
	if (word.length() < 1) {
		cout << "Error reading vocabulary file " << DATA_FILE;
		return -1;
	}
	string guessedWord = string(word.length(), '-');
	string badGuesses = "";

	do {
		renderGame(guessedWord, badGuesses);
		char guess = readAGuess();
		if (contains(word, guess))
			updateGuessedWord(guessedWord, word, guess);
		else {
			badGuesses += guess;
		}
	} while (badGuesses.length() < MAX_BAD_GUESSES && word != guessedWord);
    displayFinalResult(badGuesses.length() < MAX_BAD_GUESSES, word);

	return 0;
}

string getLowerCaseString(const string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}

string chooseWord(const char* fileName)
{
	vector<string> wordList;
	ifstream file(fileName);
  	if (file.is_open()) {
	    string word;
		while (file >> word) {
            wordList.push_back(word);
        }
    	file.close();
  	}
  	if (wordList.size() > 0) {
  		int randomIndex = rand() % wordList.size();
    	return getLowerCaseString(wordList[randomIndex]);
	} else return "";
}

char readAGuess()
{
	char input;
	cout << "Your guess: ";
	cin >> input;
	return tolower(input);
}

bool contains(const string& word, char c)
{
	return (word.find_first_of(c) != string::npos);
}

void updateGuessedWord(string& guessedWord, const string& word, char guess)
{
	for (int i = word.length() - 1; i >= 0; i--) {
        if (word[i] == guess) {
            guessedWord[i] = guess;
        }
    }
}
