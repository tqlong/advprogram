#include <iostream>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <chrono>

#include "util.h"
#include "guesser.h"
#include "draw.h"

using namespace std;

#define MAX_GUESSES 7

int getUserWordLength()
{
    int wordLength;
    cout << endl << "Enter your word length: ";
    cin >> wordLength;
    return wordLength;
}

void initialize(int& wordLength, string& secretWord,
                int& incorrectGuess, string& previousGuesses,
                bool& stop)
{
    wordLength = getUserWordLength();
    secretWord = string(wordLength, '-');
    incorrectGuess = 0;
    previousGuesses = "";
    stop = false;
}

string getUserAnswer(char guess)
{
    string answer;
    cout << endl << "I guess " << guess << ", please enter your mask: ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return answer;
}

bool isGoodMask(char guess, const string& mask, const string& secretWord)
{
    if (mask.length() != secretWord.length()) return false;
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-') {
            if (mask[i] != guess)
                return false;
            if (secretWord[i] != '-' && secretWord[i] != mask[i])
                return false;
        }
    return true;
}

void updateSecretWord(const string& mask, string& secretWord)
{
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-')
            secretWord[i] = mask[i];
}

void update(char guess, const string& mask,
            int& incorrectGuess, string& previousGuesses,
            string& secretWord, bool& stop)
{
    if (!isGoodMask(guess, mask, secretWord))
        throw invalid_argument("mistake entering answer");

    previousGuesses += guess;
    if (isAllDash(mask)) {
        incorrectGuess ++;
        if (incorrectGuess == MAX_GUESSES) stop = true;
    } else {
        updateSecretWord(mask, secretWord);
        if (isAllNotDash(secretWord)) stop = true;
    }
}

void render(int incorrectGuess, const string& previousGuesses,
            const string& secretWord)
{
    clearScreen();
    cout << endl << "Incorrect guess = " << incorrectGuess
         << "   previous guesses = " << previousGuesses
         << "   secretWord = " << secretWord << endl;
    cout << getDrawing(incorrectGuess) << endl;
}

void playAnimation(bool isLosing, const string& word)
{
    clearScreen();
    while (true) {
        if (isLosing)
            cout << endl << "I lost :(. My best word is: " << word << endl;
        else
            cout << endl << "Haha, I win :D. The word is: " << word << endl;
        cout << (isLosing ? getNextHangman() : getNextStandingman());
        this_thread::sleep_for(chrono::milliseconds(500));
        clearScreen();
    }
}

int main()
{
    int wordLength;
    string secretWord;
    int incorrectGuess;
    string previousGuesses;
    bool stop;

    initialize(wordLength, secretWord, incorrectGuess, previousGuesses, stop);

    render(incorrectGuess, previousGuesses, secretWord);
    do {
        char guess = getNextGuess(previousGuesses, secretWord);
        if (guess == 0) {
            cout << "I give up, hang me" << endl;
            return 0;
        }

        do {
            try {
                string mask = getUserAnswer(guess);
                update(guess, mask, incorrectGuess, previousGuesses, secretWord, stop);
                break;
            } catch (invalid_argument e) {
                cout << "Invalid mask, try again" << endl;
            }
        } while (true);
        render(incorrectGuess, previousGuesses, secretWord);
    } while (!stop);
    playAnimation(incorrectGuess == MAX_GUESSES, secretWord);

    return 0;
}
