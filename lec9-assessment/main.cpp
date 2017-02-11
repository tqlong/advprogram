#include <iostream>
#include <set>
#include <cctype>
#include <algorithm>
#include <stdexcept>
#include <thread>
#include <chrono>

#include "util.h"
#include "guesser.h"
#include "draw.h"

using namespace std;

int getUserWordLength()
{
    int wordLength;
    cout << endl << "Enter your word length: ";
    cin >> wordLength;
    return wordLength;
}

string getUserAnswer(char guess)
{
    string answer;
    cout << endl << "I guess " << guess << ", please enter your mask: ";
    cin >> answer;
    transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
    return answer;
}

void render(const Guesser& guesser)
{
    clearScreen();
    cout << endl << "Incorrect guess = " << guesser.getIncorrectGuess()
         << "   previous guesses = ";
    for (char c : guesser.getPreviousGuesses())
        cout << c;
    cout << "   secretWord = " << guesser.getSecretWord() << endl;
    cout << getDrawing(guesser.getIncorrectGuess()) << endl;
}

void playAnimation(const Guesser& guesser)
{
    clearScreen();
    bool isLosing = guesser.getIncorrectGuess() == guesser.MAX_GUESSES;
    const string& word = guesser.getSecretWord();
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

int playHangman()
{
    Guesser guesser;
    guesser.newGame(getUserWordLength());

    render(guesser);
    do {
        char guess = guesser.getNextGuess();
        if (guess == 0) {
            cout << "I give up, hang me" << endl;
            return 0;
        }

        do {
            try {
                string mask = getUserAnswer(guess);
                guesser.receiveHostAnswer(guess, mask);
                break;
            } catch (invalid_argument e) {
                cout << "Invalid mask, try again" << endl;
            }
        } while (true);
        render(guesser);
    } while (!guesser.isStop());
    playAnimation(guesser);

    return 0;
}

string getMask(char guess, const string& word)
{
    string mask(word.length(), '-');
    for (unsigned int i = 0; i < word.length(); i++)
        if (tolower(word[i]) == guess) mask[i] = guess;
    return mask;
}

int main(int argc, char* argv[])
{
    string testFile = argc > 1 ? argv[1] : "data/Ogden_Picturable_200.txt";
    vector<string> testWordList = readWordListFromFile(testFile);

    double totalGuess = 0;
    for (const string& word : testWordList) {
        Guesser guesser;
        guesser.newGame(word.length());
        do {
            char guess = guesser.getNextGuess();
            if (guess == 0) {
                totalGuess += guesser.MAX_GUESSES;
                break;
            }
            guesser.receiveHostAnswer(guess, getMask(guess, word));
            if (guesser.isStop()) {
                totalGuess += guesser.getIncorrectGuess();
            }
        } while (!guesser.isStop());
    }
    cout << "For testFile " << testFile
         << ", average number of guesses = " << totalGuess / testWordList.size()
         << endl;
    return 0;
}
