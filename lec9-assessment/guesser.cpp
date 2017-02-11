#include <string>
#include <cstdlib>
#include <algorithm>
#include "guesser.h"
#include "util.h"

using namespace std;

set<char> Guesser::getRemainingChars(const set<char>& previousGuesses)
{
    set<char> remainingChars;
    for (char c = 'a'; c <= 'z'; c++)
        remainingChars.insert(c);
    for (char c: previousGuesses)
        remainingChars.erase(c);
    return remainingChars;
}

char Guesser::selectRandomChar(const set<char>& s) {
  int r = rand() % s.size();
  set<char>::iterator it = s.begin();
  for (; r != 0; r--) it++;
  return *it;
}

char Guesser::getVowelGuess(const set<char>& remainingChars)
{
    char vowel[] = {'e', 'a', 'o', 'i', 'u'};
    for (char c : vowel) {
        if (remainingChars.find(c) != remainingChars.end())
            return c;
    }
    return 0;
}

bool Guesser::isSuitableWord(const string& word, const string& secretWord, const set<char>& remainingChars)
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

vector<string> Guesser::getSuitableWords(const vector<string>& wordList,
                                const string& secretWord,
                                const set<char>& remainingChars)
{
    vector<string> result;
    for (const string& word : wordList)
        if (isSuitableWord(word, secretWord, remainingChars))
            result.push_back(word);
    return result;
}

vector<int> Guesser::getSuitableWordsIndex(const vector<int>& index,
                                const string& secretWord,
                                const set<char>& remainingChars)
{
    vector<int> result;
    int n = index.size();
    for (int i = 0; i < n; i++) {
        int idx = index[i];
        if (isSuitableWord(wordList[idx], secretWord, remainingChars))
            result.push_back(idx);
    }
    return result;
}

map<char, int> Guesser::getOccurenceCount(const set<char>& remainingChars, const vector<string>& wordList)
{
    map<char, int> count;
    for (char c: remainingChars) count[c] = 0;

    for (const string& word : wordList) {
        for (char c : word)
            if (count.find(c) != count.end())
                count[c]++;
    }
    return count;
}

map<char, int> Guesser::getOccurenceCount(const set<char>& remainingChars, const vector<string>& wordList, const vector<int>& index)
{
    map<char, int> count;
    for (char c: remainingChars) count[c] = 0;

    int n = index.size();
    for (int i = 0; i < n; i++) {
        const string& word = wordList[index[i]];
        for (char c : word)
            if (count.find(c) != count.end())
                count[c]++;
    }
    return count;
}

char Guesser::getMaxOccurenceChar(const set<char>& remainingChars, const map<char, int>& count)
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

Guesser::Guesser()
{
    wordList = readWordListFromFile("data/Ogden_Picturable_200.txt");
}

Guesser::Guesser(const string& wordFile)
{
    wordList = readWordListFromFile(wordFile);
}

void Guesser::newGame(int wordLength)
{
    secretWord = string(wordLength, '-');
    incorrectGuess = 0;
    previousGuesses = set<char>();
    stop = false;
    filteredWordIndex = vector<int>(wordList.size());
    iota(filteredWordIndex.begin(), filteredWordIndex.end(), 0);
}

void Guesser::receiveHostAnswer(char guess, const std::string& mask)
{
    if (!isGoodMask(guess, mask))
        throw invalid_argument("mistake entering answer");

    previousGuesses.insert(guess);
    if (isAllDash(mask)) {
        incorrectGuess ++;
        if (incorrectGuess == MAX_GUESSES) stop = true;
    } else {
        updateSecretWord(mask);
        if (isAllNotDash(secretWord)) stop = true;
    }
}

bool Guesser::isGoodMask(char guess, const string& mask)
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

void Guesser::updateSecretWord(const string& mask)
{
    for (unsigned int i = 0; i < secretWord.length(); i++)
        if (mask[i] != '-')
            secretWord[i] = mask[i];
}

char Guesser::getNextGuess()
{
    set<char> remainingChars = getRemainingChars(previousGuesses);
    if (remainingChars.size() == 0)
        return 0;

    if (isAllDash(secretWord))
        return getVowelGuess(remainingChars);

//    vector<string> filteredWordList = getSuitableWords(wordList, secretWord, remainingChars);
//    map<char, int> occurenceCount = getOccurenceCount(remainingChars, filteredWordList);
    filteredWordIndex = getSuitableWordsIndex(filteredWordIndex, secretWord, remainingChars);
    map<char, int> occurenceCount = getOccurenceCount(remainingChars, wordList, filteredWordIndex);
    return getMaxOccurenceChar(remainingChars, occurenceCount);
}
