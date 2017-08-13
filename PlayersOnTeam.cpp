/*
 * PlayersOnTeam.cpp
 *
 *  Created on: Jun 22, 2017
 *      Author: Samuel
 */

#include <iostream>

using namespace std;

int main( int argc, char * argv[] )
{
	int teamSize;
	int playersOnTeam;
	int morePlayersNeeded;
	int extraPlayers;

	// Input data
	cout << "How many players should be on the team? ";
	cin >> teamSize;
	cout << "How many players are on the team? ";
	cin >> playersOnTeam;

	// Process and output
	if (playersOnTeam < teamSize)
	{
		cout << "There are not enough players" << endl;
		morePlayersNeeded = teamSize - playersOnTeam;
		cout << morePlayersNeeded << " more players are needed" <<endl << endl;
	}
	else if (playersOnTeam > teamSize)
	{
		cout << "There are too many players" << endl;
		extraPlayers = playersOnTeam - teamSize;
		cout << extraPlayers << " players need to be eliminated" << endl << endl;
	}
	else
	{
		cout << "You have the correct number of players" << endl << endl;
	}
	return 0;
}


