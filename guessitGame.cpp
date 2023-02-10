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
    do {
        guessIt();
        std::cout << std::endl << "Do you want to play again (y/n) ?  ";
        std::cin >> isContinued;
    } while (isContinued == 'y' || isContinued == 'Y');
    return 0;
}

int getRandNum(){
    srand(time(0));
    return rand() % 100 + 1;
}

int getGuess(){
    std::cout << "Enter your guess between 1 and 100: ";
    std::string s;
    std::cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (!(s[i] > 47 && s[i] < 58)){
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