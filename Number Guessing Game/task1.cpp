#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    cout << "*****************************************" << endl;
    cout << "*** WELCOME TO NUMBER GUESSING GAME! ***" << endl;
    cout << "*****************************************" << endl;
    cout << endl;
    cout << "      Let's test your luck and skill!" << endl;
    cout << endl;

    srand(time(0));
    int score = 0;
    int attempts = 0;

    do {
        int difficulty;
        cout << "Please select a difficulty level:" << endl;
        cout << "1. Easy" << endl;
        cout << "2. Moderate" << endl;
        cout << "3. Hard" << endl;
        cout << "4. Exit Game" << endl;
        cout << "Enter your choice: ";
        cin >> difficulty;

        if (difficulty < 1 || difficulty > 4) {
            cout << "Exiting the game." << endl;
            break;
        }

        int range = (difficulty == 1) ? 10 : (difficulty == 2) ? 100 : 1000;
        int randomNumber = rand() % range + 1;
        int guess;
        attempts = 0;

        cout << endl;
        cout << "Guess the number between 1 and " << range << "." << endl;
        cout << "You have 5 attempts to guess the number." << endl;

        while (attempts < 5) {
            cout << "Attempt #" << attempts + 1 << ": Enter your guess: ";
            cin >> guess;

            if (guess < 1 || guess > range) {
                cout << "Please enter a number within the valid range." << endl;
                continue;
            }

            attempts++;
            if (guess == randomNumber) {
                cout << endl;
                cout << "Congratulations! You guessed the correct number!" << endl;
                score += (6 - attempts) * 10; // Score based on number of attempts
                cout << "Your score for this round: " << score << endl;
                break;
            } else {
                cout << "Incorrect guess. ";
                if (guess < randomNumber) cout << "Your guess is too low." << endl;
                else cout << "Your guess is too high." << endl;
            }
        }

        if (attempts == 5) {
            cout << endl;
            cout << "Sorry, you've used all your attempts. The correct number was: " << randomNumber << "." << endl;
        }

    } while (true);

    cout << "Thank you for playing! Goodbye." << endl;
    return 0;
}
