//target functions, throw moved to classes

Player targetFunction( int attackRow, int attackCol, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer )
{
	//some weird thing to do w/ earth slash and kiku targetting into negative rows...
	if( attackRow < 0 || attackCol < 0 )
	{
		return nullPlayer;
	}
	else if( myArray[attackRow][attackCol] == myArray[player1.currentRow][player1.currentCol] )
	{
		return player1;
	}
	else if( myArray[attackRow][attackCol] == myArray[player2.currentRow][player2.currentCol] )
	{
		return player2;
	}
	else if( myArray[attackRow][attackCol] == myArray[player3.currentRow][player3.currentCol] )
	{
		return player3;
	}
	else if( myArray[attackRow][attackCol] == myArray[player4.currentRow][player4.currentCol] )
	{
		return player4;
	}
	else if( myArray[attackRow][attackCol] == myArray[player5.currentRow][player5.currentCol] )
	{
		return player5;
	}
	else if( myArray[attackRow][attackCol] == myArray[player6.currentRow][player6.currentCol] )
	{
		return player6;
	}
	else if( myArray[attackRow][attackCol] == myArray[player7.currentRow][player7.currentCol] )
	{
		return player7;
	}
	else if( myArray[attackRow][attackCol] == myArray[player8.currentRow][player8.currentCol] )
	{
		return player8;
	}
	else if( myArray[attackRow][attackCol] == myArray[player9.currentRow][player9.currentCol] )
	{
		return player9;
	}
	else if( myArray[attackRow][attackCol] == myArray[player10.currentRow][player10.currentCol] )
	{
		return player10;
	}
	else return nullPlayer;
}

Player targetFunctionFollow( int turnOrder, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer )
{
	if( turnOrder == player1.turnOrder )
	{
		return player1;
	}
	else if( turnOrder == player2.turnOrder )
	{
		return player2;
	}
	else if( turnOrder == player3.turnOrder )
	{
		return player3;
	}
	else if( turnOrder == player4.turnOrder )
	{
		return player4;
	}
	else if( turnOrder == player5.turnOrder )
	{
		return player5;
	}
	else if( turnOrder == player6.turnOrder )
	{
		return player6;
	}
	else if( turnOrder == player7.turnOrder )
	{
		return player7;
	}
	else if( turnOrder == player8.turnOrder )
	{
		return player8;
	}
	else if( turnOrder == player9.turnOrder )
	{
		return player9;
	}
	else if( turnOrder == player10.turnOrder )
	{
		return player10;
	}
	else return nullPlayer;
}

void endTarget( Player &target, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, Player &nullPlayer )
{

	if( target.turnOrder == 1 )
	{
		player1 = target;	
	}
	else if( target.turnOrder == 4 )
	{
		player2 = target;	
	}
	else if( target.turnOrder == 5 )
	{
		player3 = target;	
	}
	else if( target.turnOrder == 8 )
	{
		player4 = target;	
	}
	else if( target.turnOrder == 9 )
	{
		player5 = target;	
	}
	else if( target.turnOrder == 2 )
	{
		player6 = target;	
	}
	else if( target.turnOrder == 3 )
	{
		player7 = target;	
	}
	else if( target.turnOrder == 6 )
	{
		player8 = target;	
	}
	else if( target.turnOrder == 7 )
	{
		player9 = target;	
	}
	else if( target.turnOrder == 10 )
	{
		player10 = target;	
	}
}


void collisionDisplay( int hitRow, int hitCol, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], string abilityName = "" )
{
	Player target;

	target = targetFunction( hitRow, hitCol, player1, player2, player3, player4, player5,
		player6, player7, player8, player9, player10, myArray, nullPlayer );

	cout << abilityName << " hits " << target.teamName << " " << target.playerClassName << " " << target.playerName
		<< " at (" << hitRow << ", " << hitCol << ") before reaching its target!\n";
}

//checks to see if the player is dead
bool outerCollisionDisplay( int hitRow, int hitCol, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], string abilityName = "" )
{
	Player target;

	target = targetFunction( hitRow, hitCol, player1, player2, player3, player4, player5,
			player6, player7, player8, player9, player10, myArray, nullPlayer );
	if( target.nullPlayer == false && target.dead == false )
	{
		collisionDisplay( hitRow, hitCol, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer,
			myArray, abilityName );
		return false;
	}
	return true;
}

//detects collision in a straight line and diagnols for ranged actions
//unsure of long bow and other particulars
vector<int> rangeCollision( int startRow, int startCol, int endRow, int endCol,
	char myArray[][11], Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, Player &nullPlayer, string abilityName = "" )
{
	//add a collision message... square or maybe which target
	vector<int> retVec (2, 0);
	int distance = 0;
	int i = 0;
	int j = 1;
	bool deadCheck = true;

	//default vector to return is no collisio
	retVec[0] = endRow;
	retVec[1] = endCol;
	
	// attack traced along a row
	if( startRow == endRow && abs( startCol - endCol ) > 1 )
	{
		retVec[0] = endRow;
		distance = abs( startCol - endCol ) - 1; //-1 since last square is the target
		if( endCol > startCol ) //heading east
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[startCol + j][endRow] != 'O' && myArray[startCol + j][endRow] != 'C' )
				{
					retVec[1] = startCol + j;
					
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
		else //heading west
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[startCol - j][endRow] != 'O' && myArray[startCol - j][endRow] != 'C' )
				{
					retVec[1] = startCol - j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
	}
	else if( abs( startRow - endRow ) > 1 && startCol == endCol )
	{	//traced along a column
		retVec[1] = endCol;
		distance = abs( startRow - endRow ) - 1;
		if( endRow > startRow ) //heading south
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[endCol][startRow + j] != 'O' && myArray[endCol][startRow + j] != 'C' )
				{
					retVec[0] = startRow + j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
		else //heading North
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[endCol][startRow - j] != 'O' && myArray[endCol][startRow - j] != 'C' )
				{
					retVec[0] = startRow - j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
	}
	else if( abs( startRow - endRow ) == abs( startCol - endCol ) && abs( startCol - endCol ) > 1 )
	{	//traced along a diagnol
		distance = abs( startCol - endCol ) - 1;
		if( endRow > startRow && endCol > startCol ) //southeast
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[startRow + j][startCol + j] != 'O' && myArray[startRow + j][startCol + j] != 'C' )
				{
					retVec[0] = startRow + j;
					retVec[1] = startCol + j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
		else if( endRow < startRow && endCol < startCol ) //northwest
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[startRow - j][startCol - j] != 'O' && myArray[startRow - j][startCol - j] != 'C' )
				{
					retVec[0] = startRow - j;
					retVec[1] = startCol - j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
		else if( endRow < startRow && endCol > startCol ) //north east
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[startRow - j][startCol + j] != 'O' && myArray[startRow - j][startCol + j] != 'C' )
				{
					retVec[0] = startRow - j;
					retVec[1] = startCol + j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
		else
		{
			for( i = 0; i < distance; i++)
			{
				if( myArray[startRow + j][startCol - j] != 'O' && myArray[startRow + j][startCol - j] != 'C' )
				{
					retVec[0] = startRow + j;
					retVec[1] = startCol - j;
					deadCheck = outerCollisionDisplay( retVec[0], retVec[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, myArray, abilityName );
					if( deadCheck == false )
					{
						return retVec;
					}
				}
				j++;
			}
		}
	}

	return retVec;
}



vector<int> reflectVector( int targetRow, int targetCol, Player &actor, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10, Player &nullPlayer, 
	char myArray[][11], bool reflect = false )
{
	Player target;
	vector<int> retVec ( 2, 0 );
	int tempRow = 0;
	int tempCol = 0;

	retVec[0] = targetRow;
	retVec[1] = targetCol;

	target = targetFunction( targetRow, targetCol, player1, player2, player3,
		player4, player5, player6, player7, player8, player9, player10, myArray,
		nullPlayer );

	reflectSetter( target );

	if( target.statusReflect == true && target.nullPlayer == false )
	{
		tempRow = targetRow + ( targetRow - actor.currentRow );
		tempCol = targetCol + ( targetCol - actor.currentCol );

		//reflects off the map
		if( tempRow > 10 || tempRow < 1 || tempCol > 10 || tempCol < 1 )
		{
			retVec[0] = 0;
			retVec[1] = 0;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< "'s spell reflects off of " << target.teamName << " " << target.playerClass
				<< " " << target.playerName << " and bounces off the map!\n";
			return retVec;
		}
		else 
		{
			retVec[0] = tempRow;
			retVec[1] = tempCol;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< "'s spell reflects off of " << target.teamName << " " << target.playerClass
				<< " " << target.playerName << " and reflects to (" << retVec[0]-1 << ", " << retVec[1]-1
				<< ")!\n";
			return retVec;
		}

	}

	return retVec;

}

