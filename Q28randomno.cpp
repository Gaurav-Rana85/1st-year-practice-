#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int number_to_guess = rand() % 100 + 1;
    int guess;
    int turns = 0;
    const int max_turns = 5;

    cout << "Guess the number (between 1 and 100): ";

    while (turns < max_turns) {
        cin >> guess;
        turns++;
        if (guess < number_to_guess) {
            cout << "Too low! Try again: ";
        } else if (guess > number_to_guess) {
            cout << "Too high! Try again: ";
        } else {
            cout << "Congratulations! You guessed the correct number in " << turns << " turns!" << endl;
            break;
        }
    }

    if (turns == max_turns && guess != number_to_guess) {
        cout << "Sorry, you've used all your turns. The correct number was " << number_to_guess << "." << endl;
    }

    return 0;
}