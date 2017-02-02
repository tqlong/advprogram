#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void test_chooseWord();
void test_getDrawing();

int generateRandomNumber(int min, int max)
{
    return rand() % (max-min) + min;
}

string chooseWord()
{
    string wordList[] = {
        "angle", "ant", "apple", "arch", "arm", "army",
        "baby", "bag", "ball", "band", "basin", "basket", "bath", "bed", "bee", "bell", "berry",
        "bird", "blade", "board", "boat", "bone", "book", "boot", "bottle", "box", "boy",
        "brain", "brake", "branch", "brick", "bridge", "brush", "bucket", "bulb", "button",
        "cake", "camera", "card",  "cart", "carriage", "cat", "chain", "cheese", "chest",
        "chin", "church", "circle", "clock", "cloud", "coat", "collar", "comb", "cord",
        "cow", "cup", "curtain", "cushion",
        "dog", "door", "drain", "drawer", "dress", "drop", "ear", "egg", "engine", "eye",
        "face", "farm", "feather", "finger", "fish", "flag", "floor", "fly",
        "foot", "fork", "fowl", "frame",
        "garden", "girl", "glove", "goat", "gun",
        "hair", "hammer", "hand", "hat", "head", "heart", "hook", "horn", "horse",
        "hospital", "house",
        "island", "jewel",
        "kettle", "key", "knee", "knife", "knot",
        "leaf", "leg", "library", "line", "lip", "lock",
        "map", "match", "monkey", "moon", "mouth", "muscle",
        "nail", "neck", "needle", "nerve", "net", "nose", "nut",
        "office", "orange", "oven", "parcel", "pen", "pencil", "picture", "pig", "pin",
        "pipe", "plane", "plate", "plow", "pocket", "pot", "potato", "prison", "pump",
        "rail", "rat", "receipt", "ring", "rod", "roof", "root",
        "sail", "school", "scissors", "screw", "seed", "sheep", "shelf", "ship", "shirt",
        "shoe", "skin", "skirt", "snake", "sock", "spade", "sponge", "spoon", "spring",
        "square", "stamp", "star", "station", "stem", "stick", "stocking", "stomach",
        "store", "street", "sun",
        "table", "tail", "thread", "throat", "thumb", "ticket", "toe", "tongue", "tooth",
        "town", "train", "tray", "tree", "trousers",
        "umbrella",
        "wall", "watch", "wheel", "whip", "whistle", "window", "wire", "wing", "worm",
    };
    const int NUMBER_OF_WORDS = sizeof(wordList) / sizeof(string);
    return wordList[generateRandomNumber(0, NUMBER_OF_WORDS)];
}

string getDrawing(int incorrectGuess)
{
        string figure[] = {
                "   -------------    \n"
                "   |                \n"
                "   |                \n"
                "   |                \n"
                "   |                \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |                \n"
                "   |                \n"
                "   |                \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |           O    \n"
                "   |                \n"
                "   |                \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |           O    \n"
                "   |           |    \n"
                "   |                \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |           O    \n"
                "   |          /|    \n"
                "   |                \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |           O    \n"
                "   |          /|\\  \n"
                "   |                \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |           O    \n"
                "   |          /|\\  \n"
                "   |          /     \n"
                "   |     \n"
                " -----   \n",
                "   -------------    \n"
                "   |           |    \n"
                "   |           O    \n"
                "   |          /|\\  \n"
                "   |          / \\  \n"
                "   |     \n"
                " -----   \n",
    };

    const int NUMBER_OF_FIGURES = sizeof(figure) / sizeof(string);
    return figure[incorrectGuess % NUMBER_OF_FIGURES];
}

string updateSecretWord(char ch, string secretWord, string word)
{
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (word[i] == ch) {
            secretWord[i] = ch;
        }
    }
    return secretWord;
}

bool isCharInWord(char ch, string word)
{
    return (word.find_first_of(ch) != string::npos);
}

int main()
{
    srand(time(0));

    char ch;
    string word = chooseWord();
    string secretWord = string(word.length(), '-');
    int incorrectGuess = 0, correctGuess = 0;
    string incorrectChars = "", correctChars = "";
    const int MAX_GUESSES = 8;

    while (true) {
        cout << getDrawing(incorrectGuess)
             << endl << "Current word: " << secretWord
             << endl << "Correct guesses: " << correctChars
             << endl << "Incorrect guesses: " << incorrectChars
             << endl << "Choose a character: ";
        cin >> ch;

        if (isCharInWord(ch, word)) {
            if (!isCharInWord(ch, correctChars)) {
                correctChars += ch;
                correctGuess ++;
            }
        } else {
            incorrectChars += ch;
            incorrectGuess ++;
        }

        secretWord = updateSecretWord(ch, secretWord, word);

        if (correctGuess == (int)word.length()) {
            cout << endl << "Well done :D. The word is: " << word << endl;
            break;
        }

        if (incorrectGuess == MAX_GUESSES) {
            cout << endl << "You lose :(. The word is: " << word << endl;
            break;
        }
    } // while
    return 0;
}

void test_chooseWord()
{
    cout << "chooseWord() returns: " << chooseWord() << endl;
}

void test_getDrawing()
{
    for (int incorrectGuess = 0; incorrectGuess < 8; incorrectGuess++)
        cout << getDrawing(incorrectGuess) << endl;
}
