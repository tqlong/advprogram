#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int randomNumber = rand() % 100 + 1;;
    int number;

    do {
        cout << endl << "Enter your number between 1 and 100: ";
        cin >> number;
        if (number > randomNumber) {
            cout <<"Your number is higher." << endl;
        } else if (number < randomNumber) {
            cout <<"Your number is lower." << endl;
        } else {
            cout << "Congratulation! You win." << endl;
        }
    } while (number != randomNumber);

    return 0;
}
