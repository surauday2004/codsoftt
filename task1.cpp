#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); 

    int targetNumber = rand() % 100 + 1; 
    int userGuess;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I've picked a number between 1 and 100. Try to guess it!" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess < targetNumber) {
            cout << "Too low! Try again." << endl;
        } else if (userGuess > targetNumber) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You've guessed the correct number: " << targetNumber << endl;
            break; 
        }
    }

    return 0;
}