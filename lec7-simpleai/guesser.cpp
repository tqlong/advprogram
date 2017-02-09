#include <string>
#include "util.h"

using namespace std;

string getRemainingChars(const string& previousGuesses)
{
    string remainingChars = "";
    for (char c = 'a'; c <= 'z'; c++) {
        if (!isCharInWord(c, previousGuesses))
            remainingChars += c;
    }
    return remainingChars;
}

char getVowelGuess(const string& remainingChars)
{
    char vowel[] = {'e', 'a', 'o', 'i', 'u'};
    for (int i = 0; i < 5; i++) {
        if (isCharInWord(vowel[i], remainingChars))
            return vowel[i];
    }
    return 0;
}

char getNextGuess(const string& previousGuesses, const string& secretWord)
{
    static vector<string> wordList = readWordListFromFile("data/Ogden_Picturable_200.txt");
    string remainingChars = getRemainingChars(previousGuesses);

    if (isAllDash(secretWord))
        return getVowelGuess(remainingChars);

    if (remainingChars.length() == 0)
        return 0;
    else
        return remainingChars[generateRandomNumber(0, remainingChars.length())];
}
