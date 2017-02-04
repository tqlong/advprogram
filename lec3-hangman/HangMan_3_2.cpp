#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include <cctype>
#include <algorithm>
#include <stdexcept>

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
    static const string figure[] = {
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

void updateSecretWord(string& secretWord, char ch, string word)
{
    int len = word.length();
    for (int i = 0; i < len; ++i) {
        if (word[i] == ch) {
            secretWord[i] = ch;
        }
    }
}

bool isCharInWord(char ch, string word)
{
    return (word.find_first_of(ch) != string::npos);
}

void render(const string& word, const string& secretWord,
            int incorrectGuess,
            const string& incorrectChars, const string& correctChars,
            int MAX_GUESSES)
{
    cout << endl << endl << endl << endl << endl << endl << endl
         << endl << endl << endl << endl << endl << endl << endl
         << endl << endl << endl << endl << endl << endl << endl
         << endl << endl << endl << endl << endl << endl << endl
         << endl << endl << endl << endl << endl;

    cout << getDrawing(incorrectGuess)
         << endl << "Current word: " << secretWord
         << endl << "Correct guesses: " << correctChars
         << endl << "Incorrect guesses: " << incorrectChars
         << endl << "Choose a character: ";

    if (word == secretWord)
        cout << endl << "Well done :D. The word is: " << word << endl;

    if (incorrectGuess == MAX_GUESSES)
        cout << endl << "You lose :(. The word is: " << word << endl;
}

void update(char ch, const string& word,
            string& secretWord,
            int& incorrectGuess,
            string& incorrectChars, string& correctChars)
{
    if (isCharInWord(ch, word)) {
        if (!isCharInWord(ch, correctChars)) {
            updateSecretWord(secretWord, ch, word);
            correctChars += ch;
        }
    } else {
        incorrectChars += ch;
        incorrectGuess ++;
    }
}

vector<string> readWordListFromFile(const string& filePath)
{
    vector<string> wordList;
    string word;
    ifstream wordFile(filePath);
    if (wordFile.is_open()) {
        while (wordFile >> word) {
            wordList.push_back(word);
        }
        wordFile.close();
        return wordList;
    } else {
        throw domain_error("Error: Unable to open vocabulary file " + filePath);
    }
}

string getLowerString(const string& s)
{
    string res = s;
    transform(s.begin(), s.end(), res.begin(), ::tolower);
    return res;
}

string chooseWordFromList(const vector<string>& wordList)
{
    if (wordList.empty()) return "";
    const int NUMBER_OF_WORDS = wordList.size();
    string word = wordList[generateRandomNumber(0, NUMBER_OF_WORDS)];
    return getLowerString(word);
}

void initialize(vector<string>& wordList, string& word, string& secretWord,
                int& incorrectGuess,
                string& incorrectChars, string& correctChars)
{
    try {
        wordList = readWordListFromFile("data/Ogden_Picturable_200.txt");
    } catch (domain_error e) {
        cout << "Exception occurs: " << e.what() << endl;
        exit(1);
    }
    word = chooseWordFromList(wordList);
    secretWord = string(word.length(), '-');
    incorrectGuess = 0;
    incorrectChars = "";
    correctChars = "";
}

char getUserInput()
{
    char ch;
    cin >> ch;
    return tolower(ch);
}

int main()
{
    srand(time(0));

    char ch;
    string word, secretWord;
    int incorrectGuess;
    string incorrectChars, correctChars;
    const int MAX_GUESSES = 7;
    vector<string> wordList;

    initialize(wordList, word, secretWord, incorrectGuess, incorrectChars, correctChars);

    do {
        render(word, secretWord, incorrectGuess, incorrectChars, correctChars, MAX_GUESSES);
        ch = getUserInput();
        update(ch, word, secretWord, incorrectGuess, incorrectChars, correctChars);
    } while (word != secretWord && incorrectGuess < MAX_GUESSES);
    render(word, secretWord, incorrectGuess, incorrectChars, correctChars, MAX_GUESSES);
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
