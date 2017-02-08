// genmask.cpp
// Tool for generating mask for Hangman game

#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3) {
        cout << "Usage: genmask <word> <char>" << endl;
        return 1;
    }

    string word = argv[1];
    char guess = tolower(argv[2][0]);

    for (unsigned int i = 0; i < word.length(); i++)
        if (tolower(word[i]) != guess) word[i] = '-';
        else word[i] = guess;

    cout << word << endl;
    return 0;
}
