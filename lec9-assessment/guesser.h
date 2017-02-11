#pragma once

#include <string>
#include <set>
#include <vector>
#include <map>

class Guesser
{
private:
    std::string secretWord;
    int incorrectGuess;
    std::set<char> previousGuesses;
    bool stop;
    std::vector<std::string> wordList;
    std::vector<int> filteredWordIndex;
private:
    bool isGoodMask(char guess, const std::string& mask);
    void updateSecretWord(const std::string& mask);
    std::set<char> getRemainingChars(const std::set<char>& previousGuesses);
    char getVowelGuess(const std::set<char>& remainingChars);
    char selectRandomChar(const std::set<char>& s);
    std::map<char, int> getOccurenceCount(const std::set<char>& remainingChars, const std::vector<std::string>& wordList);
    char getMaxOccurenceChar(const std::set<char>& remainingChars, const std::map<char, int>& count);
    bool isSuitableWord(const std::string& word, const std::string& secretWord, const std::set<char>& remainingChars);
    std::vector<std::string> getSuitableWords(const std::vector<std::string>& wordList, const std::string& secretWord, const std::set<char>& remainingChars);
    std::vector<int> getSuitableWordsIndex(const std::vector<int>& index, const std::string& secretWord, const std::set<char>& remainingChars);
    std::map<char, int> getOccurenceCount(const std::set<char>& remainingChars, const std::vector<std::string>& wordList, const std::vector<int>& index);
public:
    const int MAX_GUESSES = 7;
public:
    Guesser();
    Guesser(const std::string& wordFile);
    void newGame(int wordLength);
    void receiveHostAnswer(char guess, const std::string& mask);
    char getNextGuess();

    int getIncorrectGuess() const { return incorrectGuess; }
    std::set<char> getPreviousGuesses() const { return previousGuesses; }
    bool isStop() const { return stop; }
    std::string getSecretWord() const { return secretWord; }
};
