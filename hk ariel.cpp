// HK Ariel War Games 04.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;


int main()
{
	char playAgain; // holds inputs at the end of the program 

	cout << "VTOL Warship coming Online!";
	//This do loop is to store the input from the Ai when it comes to guessing between the grid of 1-64
	do
	{
		srand(static_cast<unsigned int>(time(0))); // Seed random number generator
		//Store the number to search between, so in this case, 1-64
		int highNum = 64;
		int lowNum = 1;
		//  AI is trying to find a number between the numbers above 
		const int targetPos = rand() % highNum + lowNum;
		//AI's guess is being stored here 
		int randomAIPos = rand() % 64;
		//AIs guess 
		int guess;
		//Human Guess 
		int humanGuess;
		//Number of attempts for AI to find the object 
		int ai1Tries = 0;
		int ai2Tries = 0;
		int ai3Tries = 0;
		// number of attempts it took the player to find the target
		int humanTries = 0;
		//  number of attempts it took the winner to find the target
		int winner;


		//This do loop is for the human guess
		do
		{
			//This will Prompt the user 
			cout << "Piolet, your mission is to find the targer on an 8x8 grid (1-64)\n" << endl;
			cin >> humanGuess; //  called every time the loop restarts. makes player guess again 
			cout << "\nSearching: " << humanGuess << "." << endl;

			if (humanGuess > targetPos) // if target is smaller than our guess
			{
				cout << "Target not found. \nYou must search a lower position." << endl << endl;
				//adds a try to human, if does not get correct
				humanTries++;
			}
			// if target is larger than our guess
			else if (humanGuess < targetPos)
			{
				cout << "Target not found. \nYou must search a higher position." << endl << endl;
				humanTries++;
			}
			else
			{
				humanTries++; // add 1 to tries, so we know how many attempts it took the player
				cout << "Target Spotted at " << targetPos << endl; // print the block that we found our target at.
				cout << "Located " << humanTries << " Attempts to find Target." << endl << endl; // Print the number of tries it took us to get the correct number
			}
		} while (humanGuess != targetPos); // This restarts the human guess loop

		do // Do loop! This runs at least once! Binary Search
		{
			guess = ((highNum - lowNum) / 2) + lowNum; // This will get called every time the loop restarts. It will make the computer choose a new guess.
			cout << "Initiating VTOL Warship AI  search at position " << guess << "." << endl;

			if (guess > targetPos)
			{
				cout << "Target not found. \nInitiating search at lower position." << endl << endl;
				highNum = guess; // If number is too high, then we make highNum the guess, so when we restart the loop, the computer cannot guess any higher than our previous number
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
			}
			else if (guess < targetPos)
			{
				cout << "Target not found. \nInitiating search at higher position." << endl << endl;
				lowNum = guess; // If number is too low, then we make lowNum the guess, so when we restart the loop, the computer cannot guess any lower than our previous guess
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
			}
			else
			{
				ai1Tries++; // add 1 to tries, so we know how many attempts it took the computer
				cout << "Target spotted at " << targetPos << endl; // print the block that we found our target at.
				cout << "Located  " << ai1Tries << " it took the VTOL Warship AI to find the target. " << endl << endl; // Print the number of tries it took us to get the correct number

			}

		} while (guess != targetPos); // This is the loop part of the Do. As long as the AI hasn't found the target it will keep searching.

		for (int i = 0; i <= targetPos; i++) // Linear Search
		{
			if (i != targetPos) // if the iteration of our search is not equal to the targets position
			{
				cout << "Target not in cell " << i << "." << endl;
			}
			else // if the iteration of our search is equal to the targets position
			{
				cout << "Target Spotted at " << i << "." << endl;
				cout << "It took " << ai2Tries << " VTOL Warship AI took # of tries to find the Target." << endl;
			}
			ai2Tries++; // add 1 to ai2's tries
		}

		while (true) // Random Search
		{
			ai3Tries++; // add 1 to ai3's tries
			if (randomAIPos != targetPos) // if the random AI's guess is not equal to the targets position
			{
				cout << "Target not found at " << randomAIPos << endl;
				randomAIPos = rand() % 64 + 1; // pick a new random number
			}
			else // if the random AI's guess is equl to the targets position
			{
				cout << "Target found at " << targetPos << endl;
				cout << "It took AI 3 " << ai3Tries << " tries to find the cell." << endl;
				break; // break the loop when we have found the targets position
			}

		}
		cout << "The binary AI took " << ai1Tries << " to find the Target." << endl; // Results 
		cout << "The linear AI took " << ai2Tries << " to find the Target." << endl; // Results
		cout << "The Random AI took " << ai3Tries << " to find the Target." << endl; // Results
		cout << "You took " << humanTries << " trys to find the Target." << endl; // Results 

		winner = min(ai1Tries, min(ai2Tries, min(ai3Tries, humanTries))); // Sets the winner equal to the lowest number of tries so we can compare them next.

																		  // Below print out the name of the AI that won!
		if (winner == ai1Tries)
		{
			cout << "Binary Search AI Wins!" << endl;
		}
		else if (winner == ai2Tries)
		{
			cout << "Linear Search AI Wins!" << endl;
		}
		else if (winner == ai3Tries)
		{
			cout << "Random Search AI Wins!" << endl;
		}
		else if (winner == humanTries)
		{
			cout << "Human Player 1 Wins!" << endl;
		}

		cout << "\n\nWould you like to search again?\nY/N" << endl; // Ask player if they want to play again or not
		cin >> playAgain; // Player input for wrether they want to play again or not
		while (playAgain != 'Y' && playAgain != 'N' && playAgain != 'y' && playAgain != 'n') // This loop catches invalid inputs
		{
			cout << "Error: Invalid Input.\nPlease Select a valid operator\n";
			cin >> playAgain;
		}
	} while (playAgain == 'y' || playAgain == 'Y');

	system("pause"); // Pause the console


	return 0;
}