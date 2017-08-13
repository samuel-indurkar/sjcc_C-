/*
 * rockPaperScissors.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: Samuel
 */

#include <iostream>

using namespace std;

int main (int argc, char* argv[ ] )
{
	char player1; //input for player1
	char player2; //input for player2
	char playAgain = 'y'; //play again

	cout << "Enter R P or S for rock, paper, or scissors" <<endl;
	while (playAgain == 'Y' || playAgain == 'y')
	{
		cout << "Player 1 (R P S): ";
		cin >> player1;
		cout << "Player 2 (R P S): ";
		cin >> player2;
		player1 = toupper(player1);
		player2 = toupper(player2);
		// now to compute who won
		if (player1 == 'R')
		{
			if (player1 == player2)
				cout <<"nobody wins, tie" << endl;
			else if (player2 == 'P')
				cout << "Paper covers rock - Player 2 wins" <<endl;
			else if (player2 == 'S')
				cout << "Rock breaks Scissors - Player 1 wins" <<endl;
			else
				cout << "Illegal entry for player 2" << endl;
		}
		else if (player1 == 'S')
		{
			if (player1 == player2)
				cout <<"nobody wins, tie" << endl;
			else if (player2 == 'P')
				cout << "Scissor cut paper - Player 1 wins" <<endl;
			else if (player2 == 'R')
				cout << "Rock breaks Scissors - Player 2 wins" <<endl;
			else
				cout << "Illegal entry for player 2" << endl;
		}
		else if (player1 == 'P')
		{
			if (player1 == player2)
				cout <<"nobody wins, tie" << endl;
			else if (player2 == 'R')
				cout << "Paper covers rock - Player 1 wins" <<endl;
			else if (player2 == 'S')
				cout << "Scissor cuts paper - Player 2 wins" <<endl;
			else
				cout << "Illegal entry for player 2" << endl;
		}
		else {
			cout << "Illegal entry for player 1 \n";
		}
		cout << "do you want ot play again? \n";
		cout << " please enter Y to play again: ";
		cin >> playAgain;
	}
	return 0;
}


