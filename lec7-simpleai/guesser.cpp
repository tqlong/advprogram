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

bool isSuitableWord(const string& word, const string& secretWord, const string& remainingChars)
{
    if (word.length() != secretWord.length()) return false;
    for (unsigned int i = 0; i < word.length(); i++) {
        if (secretWord[i] != '-') {
            if (tolower(word[i]) != tolower(secretWord[i])) return false;
        }
        else if (!isCharInWord(word[i], remainingChars))
             return false;
    }
    return true;
}

vector<string> getSuitableWords(const vector<string>& wordList,
                                const string& secretWord,
                                const string& remainingChars)
{
    vector<string> result;
    for (unsigned int i = 0; i < wordList.size(); i++)
        if (isSuitableWord(wordList[i], secretWord, remainingChars))
            result.push_back(wordList[i]);
    return result;
}

vector<int> getOccurenceCount(const vector<string>& wordList)
{
    vector<int> count(256, 0);
    for (unsigned int i = 0; i < wordList.size(); i++) {
        const string& word = wordList[i];
        for (unsigned int j = 0; j < word.length(); j++)
            count[word[j]]++;
    }
    return count;
}

char getMaxOccurenceChar(const string& remainingChars, const vector<int>& count)
{
    int best = 0;
    int n = 256;
    for (int c = 0; c < n; c++)
        if (isCharInWord(c, remainingChars) && count[c] > count[best]) best = c;
    return best;
}

char getNextGuess(const string& previousGuesses, const string& secretWord)
{
    static vector<string> wordList = readWordListFromFile("data/Ogden_Picturable_200.txt");
    string remainingChars = getRemainingChars(previousGuesses);
    if (remainingChars.length() == 0)
        return 0;

    if (isAllDash(secretWord))
        return getVowelGuess(remainingChars);

    vector<string> filteredWordList = getSuitableWords(wordList, secretWord, remainingChars);
    vector<int> occurenceCount = getOccurenceCount(filteredWordList);
    return getMaxOccurenceChar(remainingChars, occurenceCount);
}
