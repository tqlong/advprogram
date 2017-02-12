#include <iostream>

#include "guesser.h"
#include "assessment.h"

using namespace std;

int main(int argc, char* argv[])
{
    string testFile = argc > 1 ? argv[1] : "data/Ogden_Picturable_200.txt";
    string dictFile = argc > 2 ? argv[2] : "data/dictionary.txt";

    Guesser guesser(dictFile);
    Assessment assessment(testFile, guesser);

    assessment.playSimulation();

    cout << "Using dictFile " << dictFile << endl
         << "on testFile " << testFile << endl
         << "average #guesses = " << assessment.getAverageIncorrectGuess()
         << endl;
    return 0;
}
