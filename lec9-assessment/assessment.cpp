#include <algorithm>

#include "assessment.h"
#include "util.h"

using namespace std;

Assessment::Assessment(const string& testFile, Guesser& guesser_)
    : guesser(guesser_)
{
    testWordList = readWordListFromFile(testFile);
}

bool greaterWordCount(const WordCount& a, const WordCount& b)
{
    return a.count > b.count;
}

void Assessment::playSimulation()
{
    wordIncorrectGuess.clear();
    for (const string& word : testWordList) {
        guesser.newGame(word.length());
        do {
            char guess = guesser.getNextGuess();
            if (guess == 0) {
                wordIncorrectGuess.push_back(WordCount(word, guesser.MAX_GUESSES));
                break;
            }
            guesser.receiveHostAnswer(guess, getMask(guess, word));
            if (guesser.isStop())
                wordIncorrectGuess.push_back(WordCount(word, guesser.getIncorrectGuess()));
        } while (!guesser.isStop());
    }
    sort(wordIncorrectGuess.begin(),
         wordIncorrectGuess.end(),
         greaterWordCount);
}

string Assessment::getMask(char guess, const string& word)
{
    string mask(word.length(), '-');
    for (unsigned int i = 0; i < word.length(); i++)
        if (tolower(word[i]) == guess) mask[i] = guess;
    return mask;
}

double Assessment::getAverageIncorrectGuess()
{
    double totalGuess = 0;
    for (const WordCount& p : wordIncorrectGuess)
        totalGuess += p.count;
    return totalGuess / wordIncorrectGuess.size();
}
