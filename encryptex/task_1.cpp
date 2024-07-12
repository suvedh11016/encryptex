#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

using namespace std;

// Function to handle the guessing game.
void numberGuess(int ourGuess, int random)
{
    // Prompt user to enter their guess.
    cout << "Enter your guess: "; 
    cin >> ourGuess;

    // Check if the guess is correct.
    if (ourGuess == random)
    {
        // If the guess is correct, congratulate the user.
        cout << "*********************************" << endl;
        cout << "** Hurray! Your guess is right **" << endl;
        cout << "*********************************" << endl;
    }
    else if (ourGuess > random)
    {
        // If the guess is too high, prompt the user to guess lower.
        cout << "Guess low" << endl;
        // Recursively call the function for another guess.
        numberGuess(ourGuess, random);
    }
    else if (ourGuess < random)
    {
        // If the guess is too low, prompt the user to guess higher.
        cout << "Guess high" << endl;
        // Recursively call the function for another guess.
        numberGuess(ourGuess, random);
    }
}

int main()
{
    // Seed the random number generator with the current time.
    srand((unsigned)time(NULL));
    
    int startingNumber; // Variable for the starting value in the range.
    int range;          // Variable for the number of values in the range.
    
    // Prompt the user to enter the starting number and range.
    cout << "Enter the starting number and range of numbers up to which you want to play the game: ";
    cin >> startingNumber >> range;
    
    // Generate a random number within the specified range.
    int random = startingNumber + (rand() % range);
    
    int ourGuess = 1; // Initial value for ourGuess variable, just to initialize it for use.
    
    // Start the guessing game.
    numberGuess(ourGuess, random);

    return 0;
}
