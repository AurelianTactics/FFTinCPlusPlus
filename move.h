




void openX( int openArray[][13], Player actor, Player unit )
{
	if( unit.activePlayer == true && actor.teamName != unit.teamName && unit.charm == false )
	{
		openArray[unit.currentRow][unit.currentCol] = 0;
	}
	else if( unit.activePlayer == true && actor.teamName == unit.teamName && unit.charm == true )
	{
		openArray[unit.currentRow][unit.currentCol] = 0;
	}
}

void displayOpenMap( const int myArray[][13], const int row, const int col )
{
	cout << "\n";
	int i; int j;
	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
		{
			cout << myArray[i][j];
		}
	cout << '\n';
	}
	cout << "\n";
}

bool moveEligible( int moveRow, int moveCol, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10 )
{
	int openArray[13][13] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,},
	};

	int tempMove = actor.move + 1;
	int bigInt = 0;
	int tempInt = 0;
	int moveLoop = 0;

	openArray[actor.currentRow][actor.currentCol] = actor.move + 2;

	openX( openArray, actor, player1 );
	openX( openArray, actor, player2 );
	openX( openArray, actor, player3 );
	openX( openArray, actor, player4 );
	openX( openArray, actor, player5 );
	openX( openArray, actor, player6 );
	openX( openArray, actor, player7 );
	openX( openArray, actor, player8 );
	openX( openArray, actor, player9 );
	openX( openArray, actor, player10 );

	int i = 0;
	int j = 0;
	while ( moveLoop < actor.move + 1)
	{
		for( i = 0; i < 13; i++)
		{
			for( j = 0; j < 13; j++)
			{
				if( i > 0 && j > 0 && i < 12 && j < 12 )
				{
					bigInt = 0;
					tempInt = 0;
					
					bigInt = openArray[i][j];

					tempInt = openArray[i-1][j];
					if( tempInt > bigInt )
					{
						bigInt = tempInt;
						bigInt -=1;
					}

					tempInt = openArray[i][j+1];
					if( tempInt > bigInt )
					{
						bigInt = tempInt;
						bigInt -=1;
					}
					tempInt = openArray[i+1][j];
					if( tempInt > bigInt )
					{
						bigInt = tempInt;
						bigInt -=1;
					}
					tempInt = openArray[i][j-1];
					if( tempInt > bigInt )
					{
						bigInt = tempInt;
						bigInt -=1;
					}
				}

				if( bigInt > 1 && openArray[i][j] != 0 )
				{
					openArray[i][j] = bigInt;
				}
				
				
				
			}
		}
		moveLoop++;
	}

	//displayOpenMap( openArray, 13, 13 );

	if( openArray[moveRow][moveCol] > 1 )
	{
		return false;
	}
	cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is blocked from moving to that location by the other team!\n";
	
	return true;
}


