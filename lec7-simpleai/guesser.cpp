#include <string>
#include <cstdlib>
#include <map>
#include "guesser.h"
#include "util.h"

using namespace std;

set<char> getRemainingChars(const set<char>& previousGuesses)
{
    set<char> remainingChars;
    for (char c = 'a'; c <= 'z'; c++)
        remainingChars.insert(c);
    for (char c: previousGuesses)
        remainingChars.erase(c);
    return remainingChars;
}

char selectRandomChar(const set<char>& s) {
  int r = rand() % s.size();
  set<char>::iterator it = s.begin();
  for (; r != 0; r--) it++;
  return *it;
}

char getVowelGuess(const set<char>& remainingChars)
{
    char vowel[] = {'e', 'a', 'o', 'i', 'u'};
    for (int i = 0; i < 5; i++) {
        if (remainingChars.find(vowel[i]) != remainingChars.end())
            return vowel[i];
    }
    return 0;
}

bool isSuitableWord(const string& word, const string& secretWord, const set<char>& remainingChars)
{
    if (word.length() != secretWord.length()) return false;
    for (unsigned int i = 0; i < word.length(); i++) {
        if (secretWord[i] != '-') {
            if (tolower(word[i]) != tolower(secretWord[i])) return false;
        }
        else if (remainingChars.find(word[i]) == remainingChars.end())
             return false;
    }
    return true;
}

vector<string> getSuitableWords(const vector<string>& wordList,
                                const string& secretWord,
                                const set<char>& remainingChars)
{
    vector<string> result;
    for (unsigned int i = 0; i < wordList.size(); i++)
        if (isSuitableWord(wordList[i], secretWord, remainingChars))
            result.push_back(wordList[i]);
    return result;
}

map<char, int> getOccurenceCount(const set<char>& remainingChars, const vector<string>& wordList)
{
    map<char, int> count;
    for (char c: remainingChars) count[c] = 0;

    for (unsigned int i = 0; i < wordList.size(); i++) {
        const string& word = wordList[i];
        for (unsigned int j = 0; j < word.length(); j++)
            if (count.find(word[j]) != count.end())
                count[word[j]]++;
    }
    return count;
}

char getMaxOccurenceChar(const set<char>& remainingChars, const map<char, int>& count)
{
    char best = 0;
    int best_count = 0;
    for (auto p : count)
        if (p.second > best_count) {
            best = p.first;
            best_count = p.second;
        }
    return best;
}

char getNextGuess(const set<char>& previousGuesses, const string& secretWord)
{
    static vector<string> wordList = readWordListFromFile("data/Ogden_Picturable_200.txt");
    set<char> remainingChars = getRemainingChars(previousGuesses);
    if (remainingChars.size() == 0)
        return 0;

    if (isAllDash(secretWord))
        return getVowelGuess(remainingChars);

    vector<string> filteredWordList = getSuitableWords(wordList, secretWord, remainingChars);
    map<char, int> occurenceCount = getOccurenceCount(remainingChars, filteredWordList);
    return getMaxOccurenceChar(remainingChars, occurenceCount);
}
