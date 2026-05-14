
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h> // For Sleep function (Windows only)

using namespace std;

// --------- Stone Paper Scissors ------------
void playStonePaperScissors() {
    char playAgain;
    do {
        cout << "::::::::::::::::::::::::::::::WELCOME::::::::::::::::::::::::::::::" << endl;
        int n;
        cout << "stone=1, paper=2, scissor=3" << endl;
        cout << "Enter Your choice: ";
        cin >> n;

        if (n > 3 || n == 0) {
            cout << "Invalid Choice" << endl;
            return;
        }

        cout << "--------------------------------" << endl;

        if (n == 1) cout << "Your Choice is : Stone" << endl;
        if (n == 2) cout << "Your Choice is : Paper" << endl;
        if (n == 3) cout << "Your Choice is : Scissor" << endl;

        srand(time(0));
        int b = 1 + rand() % 3;

        if (b == 1) cout << "Computer choice is : Stone" << endl;
        if (b == 2) cout << "Computer choice is : Paper" << endl;
        if (b == 3) cout << "Computer choice is : Scissor" << endl;

        if (b == n) cout << "It's a draw" << endl;
        else if ((n == 1 && b == 3) || (n == 2 && b == 1) || (n == 3 && b == 2)) cout << "You won" << endl;
        else cout << "You lost" << endl;

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

// --------- Number Guessing Game ------------
void playGuessingGame() {
    char playAgain;
    do {
        srand(time(0));
        int numberToGuess = rand() % 100 + 1;
        int playerGuess = 0;
        int numberOfTries = 0;

        cout << "Welcome to Guess the Number Game!\n";
        cout << "I have selected a number between 1 and 100. Can you guess what it is?\n";

        do {
            cout << "Enter your guess: ";
            cin >> playerGuess;
            numberOfTries++;

            if (playerGuess > numberToGuess) {
                cout << "Too high! Try again." << endl;
            } else if (playerGuess < numberToGuess) {
                cout << "Too low! Try again." << endl;
            } else {
                cout << "Congratulations! You've guessed the number in " << numberOfTries << " tries." << endl;
            }
        } while (playerGuess != numberToGuess);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

// --------- Dice Rolling Game ------------
void dice1() { cout << "*\n"; }
void dice2() { cout << "*\n\t*\n"; }
void dice3() { cout << "*\n\t*\n\t\t*\n"; }
void dice4() { cout << "*\t*\n*\t*\n"; }
void dice5() { cout << "*\t\t*\n\t*\n*\t\t*\n"; }
void dice6() { cout << "*\t*\n*\t*\n*\t*\n"; }

void showDice(int num) {
    switch (num) {
        case 1: dice1(); break;
        case 2: dice2(); break;
        case 3: dice3(); break;
        case 4: dice4(); break;
        case 5: dice5(); break;
        case 6: dice6(); break;
    }
}

void playDiceRolling() {
    char playAgain;
    do {
        int x;
        cout << "Let's start the Dice Rolling game\n";
        cout << "Enter 1 to roll your dice: ";
        cin >> x;

        if (x == 1) {
            srand(time(NULL));
            int userDice = rand() % 6 + 1;
            int compDice = rand() % 6 + 1;

            cout << "Wait for your dice roll..." << endl;
            Sleep(2000); // 2 seconds delay~
            cout << "Your dice is:\n";
            showDice(userDice);

            cout << "------------------------\n";

            cout << "Wait for computer's dice roll..." << endl;
            Sleep(2000); // 2 seconds delay
            cout << "Computer's dice is:\n";
            showDice(compDice);

            cout << "------------------------\n";

            if (userDice == compDice) cout << "The match is a tie\n\n";
            else if (userDice > compDice) cout << "Match result: User has won\n\n";
            else cout << "Match result: Computer has won\n\n";
        } else {
            cout << "Invalid input. Returning to menu.\n";
            return;
        }

        cout << "Do you want to roll the dice again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');
}

// --------- GameBox Menu ------------
int main() {
    int selected_option;
    while (true) {
        cout << "\n:::::::::::::::::::::: WELCOME TO GAMEBOX ::::::::::::::::::::::::::\n";
        cout << "Select the game you want to play:\n";
        cout << "Enter 1 for -- Stone Paper & Scissor\n";
        cout << "Enter 2 for -- Number Guessing\n";
        cout << "Enter 3 for -- Dice Rolling\n";
        cout << "Enter 0 to -- Exit\n";
        cout << "Your choice: ";
        cin >> selected_option;

        switch (selected_option) {
            case 1:
                playStonePaperScissors();
                break;
            case 2:
                playGuessingGame();
                break;
            case 3:
                playDiceRolling();
                break;
            case 0:
                cout << "Thank you for playing! Goodbye.\n";
                return 0;
            default:
                cout << "Invalid option. Please try again.\n";
        }

        cout << "\n--------------------------------------------------\n";
    }

    return 0;
}


