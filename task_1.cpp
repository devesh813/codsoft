#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){

    // Providing a seed value
    srand((unsigned) time(NULL));

    // Generate a random number between 1 and 100
    int targetNum = 1 + rand() % 100;

    // Print the random number
    //cout<<targetNum<<endl;
	
    int userGuess;
    int attempts = 0;
    
    while (true) {
        cout << "Guess the number between 1 and 100: ";
        cin >> userGuess;
        
        attempts++;
        
        if (userGuess < targetNum) {
            cout << "Too low! Try again." <<endl<<endl;
        } else if (userGuess > targetNum) {
            cout << "Too high! Try again." <<endl<<endl;
        } else {
            cout<<endl;
            cout << "Congratulations! You guessed the correct number: " << targetNum << endl;
            cout << "It took you " << attempts << " attempts." << endl<< endl;
            break;
        }
    }

	return 1;
}