#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int generateRandomNumber(int min, int max)
{
    return rand() % (max-min) + min;
}

string chooseWord()
{
    const int NUMBER_OF_WORDS = 3;
    string wordList[] = { "dog", "cat", "human" };
    return wordList[generateRandomNumber(0, NUMBER_OF_WORDS)];
}

int main()
{
    cout << "chooseWord() returns: " << chooseWord() << endl;

    return 0;
}
