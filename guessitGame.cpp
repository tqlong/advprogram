#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>

int getRandNum();
int getGuess();
void printRes(int guess, int randNum);
void guessIt();

int main( int argc, char * argv[] ){
    char isContinued;
    std::cout << "Welcome to Guess It Game!\n";
    std::cout << "You have to guess a number between 1 and 100.\n";
    std::cout << "If your guess is higher than the number, you will be told to guess lower.\n";
    std::cout << "If your guess is lower than the number, you will be told to guess higher.\n";
    std::cout << "You can enter 'quit' to exit the game.\n";
    do {
        guessIt();
        std::cout << '\n' << "Do you want to play again (y/n) ?  ";
        std::cin >> isContinued;
    } while (isContinued == 'y' || isContinued == 'Y');
    return 0;
}

int getRandNum(){
    srand(time(0));
    return rand() % 100 + 1;
}

int getGuess(){
    std::cout << "Enter your guess: ";
    std::string s;
    std::cin >> s;
    if (s == "quit" || s == "Quit" || s == "QUIT"){
        exit(0);
    }
    for (int i = 0; i < s.length(); i++){
        if (!(s[i] >= '0' && s[i] <= '9')){
            std::cout << "Invalid input. Please enter a number." << std::endl;
            return getGuess();
        }
    }
    std::stringstream ss(s);
    int guess;
    ss << s;
    ss >> guess;
    if (guess < 1 || guess > 100){
        std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
        return getGuess();
    }
    return guess;
}

void printRes(int guess, int randNum){
    if (guess > randNum){
        std::cout << "Your guess is higher." << std::endl;
    } else if (guess < randNum){
        std::cout << "Your guess is lower." << std::endl;
    } else {
        std::cout << "Congratulation! You win." << std::endl;
    }
}

void guessIt(){
    int randNum = getRandNum();
    int guess;
    do {
        guess = getGuess();
        printRes(guess, randNum);
    } while (guess != randNum);
}