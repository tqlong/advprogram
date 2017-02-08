#include <string>
#include "util.h"

using namespace std;

char getNextGuess(const string& previousGuesses, const string& secretWord)
{
    string remainingChars = "";
    for (char c = 'a'; c <= 'z'; c++) {
        if (!isCharInWord(c, previousGuesses))
            remainingChars += c;
    }

    if (remainingChars.length() == 0)
        return 0;
    else
        return remainingChars[generateRandomNumber(0, remainingChars.length())];
}
