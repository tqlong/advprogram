#pragma once

#include <string>
#include <vector>
#include "guesser.h"

struct WordCount
{
    std::string word;
    int count;
    WordCount(const std::string& word_, int count_)
        : word(word_), count(count_) {}
};

class Assessment
{
private:
    std::vector<std::string> testWordList;
    Guesser& guesser;
    std::vector< WordCount > wordIncorrectGuess;
private:
    std::string getMask(char guess, const std::string& word);
public:
    Assessment(const std::string& testFile, Guesser& guesser_);
    void playSimulation();
    double getAverageIncorrectGuess();
};
