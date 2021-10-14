

vector<int> confusionAttack( Player &actor, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer )
{
	Player target;
	vector<int> retVec( 2, 0);
	
	if( actor.weaponRange == 1 )
	{
		target = targetFunction( actor.currentRow - 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		target = targetFunction( actor.currentRow, actor.currentCol + 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		target = targetFunction( actor.currentRow + 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		
		target = targetFunction( actor.currentRow, actor.currentCol - 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

	}
	else if( actor.weaponRange == 2 )
	{
		target = targetFunction( actor.currentRow - 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol + 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow + 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol - 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		//tries range 2 
		target = targetFunction( actor.currentRow - 2, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol + 2, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow + 2, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol - 2, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.nullPlayer == false )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

	}

	else if( actor.weaponRange > 2 )
	{
		int k = actor.weaponRange + 1 - actor.weaponRangeMin;

		int j = actor.weaponRangeMin;

		int i = 0;

		for( i = 0; i < k; i++ )
		{
			target = targetFunction( actor.currentRow - j, actor.currentCol, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == false )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			target = targetFunction( actor.currentRow, actor.currentCol + j, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == false )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			target = targetFunction( actor.currentRow + j, actor.currentCol, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == false )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			target = targetFunction( actor.currentRow, actor.currentCol - j, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == false )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			//tries the diagnols
			if( j % 2 == 0 )
			{
				target = targetFunction( actor.currentRow - j/2, actor.currentCol - j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == false )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}

				target = targetFunction( actor.currentRow - j/2, actor.currentCol + j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == false )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}

				target = targetFunction( actor.currentRow + j/2, actor.currentCol - j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == false )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}

				target = targetFunction( actor.currentRow + j/2, actor.currentCol + j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == false )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}
			}

			j++;
		}
	}

	//default, means no one is within range of attack
	return retVec;
}

bool confusionMove( Player &actor, char myArray[][11], Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10 )
{
	int confirmMove = 0;
	int i = 0;
	string ctrPause = "";
	int numberLoop = 0;
	int rowRand = 0;
	int colRand = 0;
	bool moveError = false;

	numberLoop = actor.move * 9;

	cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is Confused and moves randomly!\n";

	for( i = 0; i < numberLoop ; i++ )
	{
		rowRand = rand() % ( actor.move + 1 );
		colRand = rand() % ( actor.move + 1 - rowRand );

		if( rand() % 2 == 0 )
		{
			rowRand *= -1;
		}
		if( rand() % 2 == 0 )
		{
			colRand *= -1;
		}
		if( myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'O' ||
			myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'C' )
		{
			if( actor.fly == false )
			{
				moveError = moveEligible( actor.currentRow + rowRand, actor.currentCol + colRand, actor, player1, player2,
					player3, player4, player5, player6, player7, player8, player9, player10 );
			}
			if( moveError == false )
			{
				confirmMove = 1;
				if( myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'O' ||
						myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'C' )
				{
					//updated player position
					myArray[actor.currentRow][actor.currentCol] = 'O';
					actor.currentRow = actor.currentRow + rowRand;
					actor.currentCol = actor.currentCol + colRand;
					myArray[actor.currentRow][actor.currentCol] = actor.mapSymbol;
		
				}
				break;
			}
		}
	}

	//default is person stays in place
	if( confirmMove == 1 )
	{
		cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is Confused and moves to (" << actor.currentRow - 1 << ", " << actor.currentCol - 1 << ")\n";
		cout << "\n";
		cout << "Enter 1 to continue.\n";
		cin >> ctrPause;
		return true;
	}
	else
	{
		cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is confused and does not move.\n";
		cout << "Enter 1 to continue.\n";
		cin >> ctrPause;
		return false;
	}

}


int confusionAction( Player &actor, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer, Golem &blueGolem,
	Golem &redGolem, Item &blueItem, Item &redItem )
{
	bool hamedoTest = false;
	Player target;
	int targetDamage = 0;
	vector<int> targetVector(2 , 0);
	bool moveBool = false;

	int confusionReturn = 0;
	//1 if act then confusion broken //0 if nothing //2 if move and act //3 if dead or petrified or stopped etc
	//4 if move and no act //5 only acts //6 waits
	if( actor.confusion == true )
	{
		targetVector = confusionAttack( actor, player1, player2, player3, player4, player5,
			player6, player7, player8, player9, player10, myArray, nullPlayer );
		if( targetVector[0] + targetVector[1] > 0 )
		{
			target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " is Confused and ATTACKS " << target.teamName << " " << target.playerClassName << " " << target.playerName << "!\n";

			hamedoTest = hamedoReaction( actor, target, myArray, blueItem, redItem, blueGolem, redGolem,
								player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

			if( hamedoTest == false )
			{
				targetDamage= turnInnerAttack( actor, target, myArray, blueGolem, redGolem );

				hpReaction( target, blueItem, redItem, actor, targetDamage );
				if( targetDamage > 0 )
				{
					distributeReaction( target, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, targetDamage );
				}
				if( actor.weaponType != "Magic Gun" )
				{
					counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
				}
				else
				{
					magicGunReaction( 0, target, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
				}
			}
			counterGraspReaction( actor, target, myArray, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
				redGolem );
			endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
			if( actor.confusion == true && actor.petrify == false && actor.dead == false && actor.stop == false
				&& actor.sleep == false )
			{
				moveBool = confusionMove( actor, myArray, player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10);
				if( moveBool == true )
				{
					confusionReturn = 2; //move and acted subtract 100 CT
				}
				else confusionReturn = 5; //only acted, no move then should wait
				return confusionReturn; 
			}
			else if( actor.petrify == true || actor.dead == true || actor.stop == true || actor.sleep == true )
			{
				confusionReturn = 3;
				return confusionReturn; //acted only subtract 80 CT
			}
			else if( actor.confusion == false )
			{
				confusionReturn = 1; //acted only, now gets to move
				return confusionReturn; 
			}
		}
		else
		{
			moveBool = confusionMove( actor, myArray, player1, player2, player3, player4, player5, player6, player7,
				player8, player9, player10 );

			targetVector = confusionAttack( actor, player1, player2, player3, player4, player5,
				player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( targetVector[0] + targetVector[1] > 0 )
			{
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< " is Confused and ATTACKS " << target.teamName << " " << target.playerClassName << " " << target.playerName << "!\n";

				hamedoTest = hamedoReaction( actor, target, myArray, blueItem, redItem, blueGolem, redGolem,
									player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

				if( hamedoTest == false )
				{
					targetDamage= turnInnerAttack( actor, target, myArray, blueGolem, redGolem );

					hpReaction( target, blueItem, redItem, actor, targetDamage );
					if( targetDamage > 0 )
					{
						distributeReaction( target, actor, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, targetDamage );
					}
					if( actor.weaponType != "Magic Gun" )
					{
						counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
					}
					else
					{
						magicGunReaction( 0, target, actor, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
					}
				}
				counterGraspReaction( actor, target, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
					redGolem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				
				if( moveBool == true )
				{
					confusionReturn = 2; //move and acted subtract 100 CT
				}
				else confusionReturn = 5; //only acted
				return confusionReturn;  
			}
			
			if( moveBool == true )
			{
				confusionReturn = 4; //just moved subtract 80 CT
			}
			else confusionReturn = 6; //just waits
			return confusionReturn; 
		}
	}
	return 0;
}


void berserkX( int openArray[][13], Player actor, Player unit )
{
	//eligible targets are 0
	if( unit.activePlayer == true && actor.teamName != unit.teamName && actor.charm == false )
	{
		openArray[unit.currentRow][unit.currentCol] = 0;
	}
	else if( unit.activePlayer == true && actor.teamName == unit.teamName && actor.charm == true )
	{
		openArray[unit.currentRow][unit.currentCol] = 0;
	}
	//squares occupied by teammates are 2
	if( unit.activePlayer == true && actor.teamName == unit.teamName )
	{
		openArray[unit.currentRow][unit.currentCol] = 2;
	}
}

// displays 9's on squares where berserker can move to and attack an enemy
	//only gets straight lines and diagnols for ranged weapons
bool berserkEligible( int moveRow, int moveCol, Player &actor, Player &player1, Player &player2,
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

	int bigInt = 0;
	int tempInt = 1;
	int nineLoop = 0;
	int loopCounter = 0;

	int tempRange = actor.weaponRangeMin;

	//how many times it should loop through adding 9's
	nineLoop = actor.weaponRange - actor.weaponRangeMin + 1;
	
	vector<int> retVec( 2, 0 );

	

	berserkX( openArray, actor, player1 );
	berserkX( openArray, actor, player2 );
	berserkX( openArray, actor, player3 );
	berserkX( openArray, actor, player4 );
	berserkX( openArray, actor, player5 );
	berserkX( openArray, actor, player6 );
	berserkX( openArray, actor, player7 );
	berserkX( openArray, actor, player8 );
	berserkX( openArray, actor, player9 );
	berserkX( openArray, actor, player10 );

	int i = 0;
	int j = 0;
	
	while( loopCounter < nineLoop )
	{
		loopCounter++;

		for( i = 0; i < 13; i++)
		{
			for( j = 0; j < 13; j++)
			{
				if( i > 0 && j > 0 && i < 12 && j < 12 )
				{
			
					tempInt = 1;
					if( openArray[i][j] == 1)
					{
						if( i - tempRange > -1 )
						{
							tempInt = openArray[i-tempRange][j];
							if( tempInt == 0 )
							{
								openArray[i][j] = 9;
							}
						}

						if( j + tempRange < 13 )
						{
							tempInt = openArray[i][j+tempRange];
							if( tempInt == 0 )
							{
								openArray[i][j] = 9;
							}
						}

						if( i + tempRange < 13 )
						{
							tempInt = openArray[i+tempRange][j];
							if( tempInt == 0 )
							{
								openArray[i][j] = 9;
							}
						}

						if( j - tempRange > -1 )
						{
							tempInt = openArray[i][j-tempRange];
							if( tempInt == 0 )
							{
								openArray[i][j] = 9;
							}
						}

						//gets the diagnols for items that aren't spears
						if(actor.weaponRange > 2 && tempRange % 2 == 0 )
						{
							if( i - tempRange > -1 && j - tempRange > -1 )
							{
								tempInt = openArray[i-tempRange/2][j-tempRange/2];
								if( tempInt == 0 )
								{
									openArray[i][j] = 9;
								}
							}
							if( i - tempRange > -1 && j + tempRange < 13 )
							{
								tempInt = openArray[i-tempRange/2][j+tempRange/2];
								if( tempInt == 0 )
								{
									openArray[i][j] = 9;
								}
							}
							if( i + tempRange < 13 && j - tempRange > -1 )
							{
								tempInt = openArray[i+tempRange/2][j-tempRange/2];
								if( tempInt == 0 )
								{
									openArray[i][j] = 9;
								}
							}
							if( i + tempRange < 13 && j + tempRange < 13 )
							{
								tempInt = openArray[i+tempRange/2][j+tempRange/2];
								if( tempInt == 0 )
								{
									openArray[i][j] = 9;
								}
							}
						}
					}
				}

			}//end inner for loop
		}//end outer for loop
		tempRange++;
	}//end while loop
				
	if( openArray[moveRow][moveCol] == 9 )
	{
		return true;
	}

	return false;

	//displayOpenMap( openArray, 13, 13 );
}


bool berserkMove( Player &actor, char myArray[][11], Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10 )
{
	int confirmMove = 0;
	int i = 0;
	string ctrPause = "";
	int numberLoop = 0;
	int rowRand = 0;
	int colRand = 0;
	bool moveError = false;
	bool berserkTest = false;

	numberLoop = actor.move * 18;

	cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is Berserked and moves!\n";

	for( i = 0; i < numberLoop ; i++ )
	{
		rowRand = rand() % ( actor.move + 1 );
		colRand = rand() % ( actor.move + 1 - rowRand );

		if( rand() % 2 == 0 )
		{
			rowRand *= -1;
		}
		if( rand() % 2 == 0 )
		{
			colRand *= -1;
		}
		if( myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'O' ||
			myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'C' )
		{
			if( actor.fly == false )
			{
				moveError = moveEligible( actor.currentRow + rowRand, actor.currentCol + colRand, actor, player1, player2,
					player3, player4, player5, player6, player7, player8, player9, player10 );
			}
			if( moveError == false )
			{
				berserkTest = berserkEligible( actor.currentRow + rowRand, actor.currentCol + colRand,
					actor, player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10 );
				if( berserkTest == true )
				{
					confirmMove = 1;
					if( myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'O' ||
							myArray[actor.currentRow + rowRand][actor.currentCol + colRand] == 'C' )
					{
						//updated player position
						myArray[actor.currentRow][actor.currentCol] = 'O';
						actor.currentRow = actor.currentRow + rowRand;
						actor.currentCol = actor.currentCol + colRand;
						myArray[actor.currentRow][actor.currentCol] = actor.mapSymbol;
		
					}
					break;
				}
			}
		}
	}

	//default is person stays in place
	if( confirmMove == 1 )
	{
		cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is Berserked and moves to (" << actor.currentRow - 1 << ", " << actor.currentCol - 1 << ")\n";
		cout << "\n";
		cout << "Enter 1 to continue.\n";
		cin >> ctrPause;
		return true;
	}
	else
	{
		cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is Berserked and does not move.\n";
		cout << "Enter 1 to continue.\n";
		cin >> ctrPause;
		return false;
	}

}

vector<int> berserkAttack( Player &actor, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer )
{
	Player target;
	vector<int> retVec( 2, 0);
	
	if( actor.weaponRange == 1 )
	{
		target = targetFunction( actor.currentRow - 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) 
			|| ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		target = targetFunction( actor.currentRow, actor.currentCol + 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		target = targetFunction( actor.currentRow + 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		
		target = targetFunction( actor.currentRow, actor.currentCol - 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

	}
	else if( actor.weaponRange == 2 )
	{
		target = targetFunction( actor.currentRow - 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol + 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow + 1, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol - 1, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}
		//tries range 2 
		target = targetFunction( actor.currentRow - 2, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol + 2, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow + 2, actor.currentCol, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

		target = targetFunction( actor.currentRow, actor.currentCol - 2, player1, player2, player3,
			player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
		{
			retVec[0] = target.currentRow;
			retVec[1] = target.currentCol;
			return retVec;
		}

	}

	else if( actor.weaponRange > 2 )
	{
		int k = actor.weaponRange + 1 - actor.weaponRangeMin;

		int j = actor.weaponRangeMin;

		int i = 0;

		for( i = 0; i < k; i++ )
		{
			target = targetFunction( actor.currentRow - j, actor.currentCol, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			target = targetFunction( actor.currentRow, actor.currentCol + j, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			target = targetFunction( actor.currentRow + j, actor.currentCol, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			target = targetFunction( actor.currentRow, actor.currentCol - j, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
			{
				retVec[0] = target.currentRow;
				retVec[1] = target.currentCol;
				return retVec;
			}

			//tries the diagnols
			if( j % 2 == 0 )
			{
				target = targetFunction( actor.currentRow - j/2, actor.currentCol - j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}

				target = targetFunction( actor.currentRow - j/2, actor.currentCol + j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}

				target = targetFunction( actor.currentRow + j/2, actor.currentCol - j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}

				target = targetFunction( actor.currentRow + j/2, actor.currentCol + j/2, player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( ( target.nullPlayer == false && target.teamName != actor.teamName && actor.charm == false ) || ( target.nullPlayer == false && target.teamName == actor.teamName && actor.charm == true ) )
				{
					retVec[0] = target.currentRow;
					retVec[1] = target.currentCol;
					return retVec;
				}
			}
			j++;
		}
	}

	//default, means no one is within range of attack
	return retVec;
}


int berserkAction( Player &actor, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer, Golem &blueGolem,
	Golem &redGolem, Item &blueItem, Item &redItem )
{
	bool hamedoTest = false;
	Player target;
	int targetDamage = 0;
	vector<int> targetVector(2 , 0);
	bool moveBool = false;

	int berserkReturn = 0;
	//1 if act then confusion broken //0 if nothing //2 if move and act //3 if dead or petrified or stopped etc
	//4 if move and no act //5 only acts //6 waits
	if( actor.berserk == true )
	{
		targetVector = berserkAttack( actor, player1, player2, player3, player4, player5,
			player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( targetVector[0] + targetVector[1] > 0 )
		{
			target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " is Berserk and ATTACKS " << target.teamName << " " << target.playerClassName << " " << target.playerName << "!\n";

			hamedoTest = hamedoReaction( actor, target, myArray, blueItem, redItem, blueGolem, redGolem,
					player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

			if( hamedoTest == false )
			{
				targetDamage= turnInnerAttack( actor, target, myArray, blueGolem, redGolem );

				hpReaction( target, blueItem, redItem, actor, targetDamage );
				if( targetDamage > 0 )
				{
					distributeReaction( target, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, targetDamage );
				}
				if( actor.weaponType != "Magic Gun" )
				{
					counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
				}
				else
				{
					magicGunReaction( 0, target, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
				}
			}
			counterGraspReaction( actor, target, myArray, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
				redGolem );
			endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );

			if( actor.petrify == false && actor.dead == false && actor.stop == false && actor.sleep == false )
			{
				moveBool = berserkMove( actor, myArray, player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10);
				if( moveBool == true )
				{
					berserkReturn = 2; //move and acted subtract 100 CT
				}
				else berserkReturn = 5; //only acted, no move then should wait
				return berserkReturn; 
			}
			else if( actor.petrify == true || actor.dead == true || actor.stop == true || actor.sleep == true )
			{
				berserkReturn = 3;
				return berserkReturn; //acted only subtract 80 CT
			}
		}
		else
		{
			
			moveBool = berserkMove( actor, myArray, player1, player2, player3, player4, player5, player6, player7,
				player8, player9, player10 );

			targetVector = berserkAttack( actor, player1, player2, player3, player4, player5,
				player6, player7, player8, player9, player10, myArray, nullPlayer );
			
			if( targetVector[0] + targetVector[1] > 0 )
			{
				
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< " is Berserk and ATTACKS " << target.teamName << " " << target.playerClassName << " " << target.playerName << "!\n";

				hamedoTest = hamedoReaction( actor, target, myArray, blueItem, redItem, blueGolem, redGolem,
									player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

				if( hamedoTest == false )
				{
					targetDamage= turnInnerAttack( actor, target, myArray, blueGolem, redGolem );

					hpReaction( target, blueItem, redItem, actor, targetDamage );
					if( targetDamage > 0 )
					{
						distributeReaction( target, actor, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, targetDamage );
					}
					if( actor.weaponType != "Magic Gun" )
					{
						counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
					}
					else
					{
						magicGunReaction( 0, target, actor, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
					}
				}
				counterGraspReaction( actor, target, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
					redGolem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				
				if( moveBool == true )
				{
					berserkReturn = 2; //move and acted subtract 100 CT
				}
				else berserkReturn = 5; //only acted
				return berserkReturn;  
			}
			
			if( moveBool == true )
			{
				berserkReturn = 4; //just moved subtract 80 CT
			}
			else berserkReturn = 6; //just waits
			return berserkReturn; 
		}
	}
	return 0;
}