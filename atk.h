//functions for attach: test range, evasion, calculate damage, calculate crit, give damage

//range test
vector<int> rangeTest( Player actor, int rangeMax = 1, string actionName = "ATTACK", int rangeMin = 1,
	bool spearAct = false )
{
	//frog exception
	if( actor.frog == true && actionName == "ATTACK" )
	{
		rangeMin = 1;
		rangeMax = 1;
	}

	vector<int> retVec (2, 0);
	if( rangeMin > 1 && rangeMax != 1 )
	{
		cout << actionName << " can target between " << rangeMin << " and " << rangeMax 
			<< " squares away from current location.\n"
			<< "   Current location is (" << actor.currentRow - 1 << ", " << actor.currentCol -1 << "). Enter coordinates.\n";
	}
	else if( ( rangeMin == 1 || rangeMin == 0 ) && rangeMax > 1 )
	{
		cout << actionName << " can target up to " << rangeMax 
			<< " squares away from current location.\n"
			<< "   Current location is (" << actor.currentRow - 1 << ", " << actor.currentCol -1 << "). Enter coordinates.\n";
	}
	else if( ( actor.weaponType == "Stick" || actor.weaponType == "Spear" || actor.weaponType == "Fabric" ) && rangeMax == 2 && spearAct == true )
	{
		cout << actionName << " can target up to 2 squares away but not diagnolly.\n" 
			<< "   Current location is (" << actor.currentRow - 1 << ", " << actor.currentCol -1 << "). Enter coordinates.\n";
	}
	else
	{
		cout << actionName << " can target " << rangeMax 
			<< " square away from current location.\n"
			<< "   Current location is (" << actor.currentRow - 1 << ", " << actor.currentCol -1 << "). Enter coordinates.\n";
	}
	int attackRow = 40;
	int attackCol = 40;
	do
	{
		while( (cout << "   Which Row?     ") && ( !(cin>> attackRow) || attackRow < 0 || attackRow > 9 ))
		{
			cout << "Enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		attackRow += 1;
		while( (cout << "   Which Column?  ") && ( !(cin>> attackCol) || attackCol < 0 || attackCol > 9 ))
		{
			cout << "Enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		attackCol += 1;
		if( ( (abs(attackRow-actor.currentRow)+abs(attackCol-actor.currentCol)) > rangeMax ) ||
			(abs(attackRow-actor.currentRow)+abs(attackCol-actor.currentCol)) < rangeMin )
		{
		cout << "Invalid input. You can only target between " << rangeMin
			<< " and " << rangeMax  << " square(s) away.\n" << "\n"
			<< "   Current location is (" << actor.currentRow - 1 << ", " << actor.currentCol -1 << "). Enter coordinates.\n";
		}
		//spear / stick exception
		if( ( actor.weaponType == "Stick" || actor.weaponType == "Spear" || actor.weaponType == "Fabric" )
			&& rangeMax == 2 && spearAct == true && ( actor.currentCol != attackCol && actor.currentRow != attackRow ) )
		{
			cout << "Invalid input. You cannot target diagnolly.\n"
			<< "   Current location is (" << actor.currentRow - 1 << ", " << actor.currentCol -1 << "). Enter coordinates.\n";
		
		}
	} while( ( (abs(attackRow-actor.currentRow)+abs(attackCol-actor.currentCol)) > rangeMax ) ||
		( abs(attackRow-actor.currentRow)+abs(attackCol-actor.currentCol) < rangeMin ) );
	retVec[0] = attackRow;
	retVec[1] = attackCol;
	return retVec;
}

vector<int> multiRange( Player &actor, int effectSize, string actionName,
	int rangeMax = 1, int rangeMin = 1, bool targetActor = false , bool casterImmune = false,
	int targetRow = 0, int targetCol = 0, bool mimeBool = false )
{
	int rangeConfirm = 0;
	vector<int> retVec (60, 0);

	if( effectSize == 1 )
	{
		retVec[0] = targetRow;
		retVec[1] = targetCol;
		return retVec;
	}

	if( targetActor == true ) //effect area starts caster
	{
		if( effectSize == 2 && targetActor == true && casterImmune == true )
		{
			cout << actionName << " targets the 4 squares surrounding caster.\n";
			//starting at 12 oclock, return 4 square surrounding caster
			retVec[0] = actor.currentRow + 1;
			retVec[1] = actor.currentCol;
			retVec[2] = actor.currentRow;
			retVec[3] = actor.currentCol + 1;
			retVec[4] = actor.currentRow - 1;
			retVec[5] = actor.currentCol;
			retVec[6] = actor.currentRow;
			retVec[7] = actor.currentCol - 1;
			return retVec;
		}
		else if( effectSize == 2 && targetActor == true && casterImmune == false )
		{
			cout << actionName << " targets " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " and the 4 surrounding squares.\n";
			//4 squares surrounding the caster then the caster
			retVec[0] = actor.currentRow + 1;
			retVec[1] = actor.currentCol;
			retVec[2] = actor.currentRow;
			retVec[3] = actor.currentCol + 1;
			retVec[4] = actor.currentRow - 1;
			retVec[5] = actor.currentCol;
			retVec[6] = actor.currentRow;
			retVec[7] = actor.currentCol - 1;
			retVec[8] = actor.currentRow;
			retVec[9] = actor.currentCol;
			return retVec;
		}
		else if( effectSize == 3 && casterImmune == true )
		{ //4 squares surrounding the caster then the ring around that, NO caster
			retVec[0] = actor.currentRow + 1;
			retVec[1] = actor.currentCol;
			retVec[2] = actor.currentRow;
			retVec[3] = actor.currentCol + 1;
			retVec[4] = actor.currentRow - 1;
			retVec[5] = actor.currentCol;
			retVec[6] = actor.currentRow;
			retVec[7] = actor.currentCol - 1;
			//outer ring
			retVec[8] = actor.currentRow + 2;
			retVec[9] = actor.currentCol;
			retVec[10] = actor.currentRow + 1;
			retVec[11] = actor.currentCol + 1;
			retVec[12] = actor.currentRow;
			retVec[13] = actor.currentCol + 2;
			retVec[14] = actor.currentRow - 1;
			retVec[15] = actor.currentCol + 1;
			retVec[16] = actor.currentRow - 2;
			retVec[17] = actor.currentCol;
			retVec[18] = actor.currentRow - 1;
			retVec[19] = actor.currentCol - 1;
			retVec[20] = actor.currentRow;
			retVec[21] = actor.currentCol - 2;
			retVec[22] = actor.currentRow + 1;
			retVec[23] = actor.currentCol - 1;
			return retVec;
		}
		else if( effectSize == 3 && casterImmune == false )
		{ //4 squares surrounding the caster then the ring around that, then caster
			retVec[0] = actor.currentRow + 1;
			retVec[1] = actor.currentCol;
			retVec[2] = actor.currentRow;
			retVec[3] = actor.currentCol + 1;
			retVec[4] = actor.currentRow - 1;
			retVec[5] = actor.currentCol;
			retVec[6] = actor.currentRow;
			retVec[7] = actor.currentCol - 1;
			//outer ring
			retVec[8] = actor.currentRow + 2;
			retVec[9] = actor.currentCol;
			retVec[10] = actor.currentRow + 1;
			retVec[11] = actor.currentCol + 1;
			retVec[12] = actor.currentRow;
			retVec[13] = actor.currentCol + 2;
			retVec[14] = actor.currentRow - 1;
			retVec[15] = actor.currentCol + 1;
			retVec[16] = actor.currentRow - 2;
			retVec[17] = actor.currentCol;
			retVec[18] = actor.currentRow - 1;
			retVec[19] = actor.currentCol - 1;
			retVec[20] = actor.currentRow;
			retVec[21] = actor.currentCol - 2;
			retVec[22] = actor.currentRow + 1;
			retVec[23] = actor.currentCol - 1;
			//actor
			retVec[24] = actor.currentRow;
			retVec[25] = actor.currentCol;
			return retVec;
		}
		else if( effectSize == 8 && targetActor == true && casterImmune == true && mimeBool == false ) //earth slash and draw out techniques that go a straight line
		{
		
			while ( (cout << actionName << " targets " << rangeMax 
				<< " squares in any direction. Choose direction.\n"
				<< "\t1.) NORTH   2.) EAST   3.) SOUTH   4.) WEST\n" )  &&
				( !(cin >> rangeConfirm) || rangeConfirm < 1 || rangeConfirm > 4 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if( rangeConfirm == 1 ) //north
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow -  1 - i;
					retVec[j + 1] = actor.currentCol;
					j += 2;
				}
				return retVec;
			}
			else if( rangeConfirm == 2 ) //east
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow;
					retVec[j + 1] = actor.currentCol + 1 + i;
					j += 2;
				}
				return retVec;
			}
			else if( rangeConfirm == 3 ) //south
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow +  1 + i;
					retVec[j + 1] = actor.currentCol;
					j += 2;
				}
				return retVec;
			}
			else if( rangeConfirm == 4 ) //west
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow;
					retVec[j + 1] = actor.currentCol - 1 - i;
					j += 2;
				}
				return retVec;
			}
		}
		else if( effectSize == 8 && mimeBool == true )
		{
			if( actor.facingDir == "NORTH" ) //north
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow -  1 - i;
					retVec[j + 1] = actor.currentCol;
					j += 2;
				}
				return retVec;
			}
			else if( actor.facingDir == "EAST" ) //east
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow;
					retVec[j + 1] = actor.currentCol + 1 + i;
					j += 2;
				}
				return retVec;
			}
			else if( actor.facingDir == "SOUTH" ) //south
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow +  1 + i;
					retVec[j + 1] = actor.currentCol;
					j += 2;
				}
				return retVec;
			}
			else if( actor.facingDir == "WEST" ) //west
			{
				int i = 0;
				int j = 0;
				for( i = 0; i < rangeMax; i++ )
				{
					retVec[j] = actor.currentRow;
					retVec[j + 1] = actor.currentCol - 1 - i;
					j += 2;
				}
				return retVec;
			}
		}
	}
	
	else if( targetActor == false )
	{
		if( effectSize == 2 )
		{
			//4 squares surrounding the target then the target
			retVec[0] = targetRow + 1;
			retVec[1] = targetCol;
			retVec[2] = targetRow;
			retVec[3] = targetCol + 1;
			retVec[4] = targetRow - 1;
			retVec[5] = targetCol;
			retVec[6] = targetRow;
			retVec[7] = targetCol - 1;
			retVec[8] = targetRow;
			retVec[9] = targetCol;
			return retVec;
		}
		else if( effectSize == 3 )
		{
			retVec[0] = targetRow + 1;
			retVec[1] = targetCol;
			retVec[2] = targetRow;
			retVec[3] = targetCol + 1;
			retVec[4] = targetRow - 1;
			retVec[5] = targetCol;
			retVec[6] = targetRow;
			retVec[7] = targetCol - 1;
			//outer ring
			retVec[8] = targetRow + 2;
			retVec[9] = targetCol;
			retVec[10] = targetRow + 1;
			retVec[11] = targetCol + 1;
			retVec[12] = targetRow;
			retVec[13] = targetCol + 2;
			retVec[14] = targetRow - 1;
			retVec[15] = targetCol + 1;
			retVec[16] = targetRow - 2;
			retVec[17] = targetCol;
			retVec[18] = targetRow - 1;
			retVec[19] = targetCol - 1;
			retVec[20] = targetRow;
			retVec[21] = targetCol - 2;
			retVec[22] = targetRow + 1;
			retVec[23] = targetCol - 1;
			//target
			retVec[24] = targetRow;
			retVec[25] = targetCol;
			return retVec;
		}
		else if( effectSize == 4 )
		{
			retVec[0] = targetRow + 1;
			retVec[1] = targetCol;
			retVec[2] = targetRow;
			retVec[3] = targetCol + 1;
			retVec[4] = targetRow - 1;
			retVec[5] = targetCol;
			retVec[6] = targetRow;
			retVec[7] = targetCol - 1;
			//outer ring
			retVec[8] = targetRow + 2;
			retVec[9] = targetCol;
			retVec[10] = targetRow + 1;
			retVec[11] = targetCol + 1;
			retVec[12] = targetRow;
			retVec[13] = targetCol + 2;
			retVec[14] = targetRow - 1;
			retVec[15] = targetCol + 1;
			retVec[16] = targetRow - 2;
			retVec[17] = targetCol;
			retVec[18] = targetRow - 1;
			retVec[19] = targetCol - 1;
			retVec[20] = targetRow;
			retVec[21] = targetCol - 2;
			retVec[22] = targetRow + 1;
			retVec[23] = targetCol - 1;
			//target
			retVec[24] = targetRow;
			retVec[25] = targetCol;
			//outer outer ring
			retVec[26] = targetRow + 3;
			retVec[27] = targetCol;
			retVec[28] = targetRow + 2;
			retVec[29] = targetCol + 1;
			retVec[30] = targetRow + 1;
			retVec[31] = targetCol + 2;
			retVec[32] = targetRow;
			retVec[33] = targetCol + 3;
			retVec[34] = targetRow - 1;
			retVec[35] = targetCol + 2;
			retVec[36] = targetRow - 2;
			retVec[37] = targetCol + 1;
			retVec[38] = targetRow - 3;
			retVec[39] = targetCol;
			retVec[40] = targetRow - 2;
			retVec[41] = targetCol - 1;
			retVec[42] = targetRow - 1;
			retVec[43] = targetCol - 2;
			retVec[44] = targetRow;
			retVec[45] = targetCol - 3;
			retVec[46] = targetRow + 1;
			retVec[47] = targetCol - 2;
			retVec[48] = targetRow + 2;
			retVec[49] = targetCol - 1;
			return retVec;
		}

	}
	return retVec;
}

vector<int> mimeTargetFunction( int attackRow, int attackCol, Player mimedUnit )
{
	//mimes can only attack in a cone in front of them
		//first # is how far to the left (negative) or right (positive) of the mime
		//second number is distance in front of mime in # of panels
	vector<int> retVec (2, 0);
	
	if( mimedUnit.currentRow == attackRow && mimedUnit.currentCol == attackCol )
	{
		//target self
		retVec[0] = 0;
		retVec[1] = 0;
		return retVec;
	}
	else if( abs( attackRow - mimedUnit.currentRow ) != abs( attackCol - mimedUnit.currentCol ) )
	{
		if( abs( attackRow - mimedUnit.currentRow ) > abs( attackCol - mimedUnit.currentCol ) )
		{
			if( attackRow > mimedUnit.currentRow ) //looking south
			{
				if( attackCol > mimedUnit.currentCol ) //looking southeast
				{
					retVec[0] = -abs( attackCol - mimedUnit.currentCol );
					retVec[1] = abs( attackRow - mimedUnit.currentRow );
				}
				else //looking southwest
				{
					retVec[0] = abs( attackCol - mimedUnit.currentCol );
					retVec[1] = abs( attackRow - mimedUnit.currentRow );
				}
				return retVec;
			}
			else //looking north
			{
				if( attackCol > mimedUnit.currentCol ) //looking northeast
				{
					retVec[0] = abs( attackCol - mimedUnit.currentCol );
					retVec[1] = abs( attackRow - mimedUnit.currentRow );
				}
				else //looking north west
				{
					retVec[0] = -abs( attackCol - mimedUnit.currentCol );
					retVec[1] = abs( attackRow - mimedUnit.currentRow );
				}
				return retVec;
			}
		}
		else //looking to the east or west
		{
			if( attackCol > mimedUnit.currentCol ) //looking east
			{
				if( attackRow > mimedUnit.currentRow ) //looking southeast
				{
					retVec[0] = abs( attackRow - mimedUnit.currentRow );
					retVec[1] = abs( attackCol - mimedUnit.currentCol );
				}
				else //looking northeast
				{
					retVec[0] = -abs( attackRow - mimedUnit.currentRow );
					retVec[1] = abs( attackCol - mimedUnit.currentCol );
				}
				return retVec;
			}
			else //looking west
			{
				if( attackRow < mimedUnit.currentRow ) //looking west by northwest
				{
					retVec[0] = abs( attackRow - mimedUnit.currentRow );
					retVec[1] = abs( attackCol - mimedUnit.currentCol );
				}
				else //looking west by southwest
				{
					retVec[0] = -abs( attackRow - mimedUnit.currentRow );
					retVec[1] = abs( attackCol - mimedUnit.currentCol );
				}
				return retVec;
			}
		}
	}
	else if ( abs( attackRow - mimedUnit.currentRow ) == abs( attackCol - mimedUnit.currentCol ) )
	{
		//diagnols
		if( mimedUnit.facingDir == "NORTH" )
		{
			if( attackCol > mimedUnit.currentCol ) //diagnol is NE or turn to the right then it is NE
			{
				retVec[0] = abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
			else //NW or turn to the left NW
			{
				retVec[0] = -abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
		}
		else if( mimedUnit.facingDir == "EAST" )
		{
			if( attackRow > mimedUnit.currentRow ) //diagnol is NE or turn to the right then it is NE
			{
				retVec[0] = abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
			else //NW or turn to the left NW
			{
				retVec[0] = -abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
		}
		else if( mimedUnit.facingDir == "WEST" )
		{
			if( attackRow < mimedUnit.currentRow ) //diagnol is NE or turn to the right then it is NE
			{
				retVec[0] = abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
			else //NW or turn to the left NW
			{
				retVec[0] = -abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
		}
		else //facing south
		{
			if( attackCol < mimedUnit.currentCol ) //diagnol is NE or turn to the right then it is NE
			{
				retVec[0] = abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
			else //NW or turn to the left NW
			{
				retVec[0] = -abs( attackRow - mimedUnit.currentRow );
				retVec[1] = abs( attackCol - mimedUnit.currentCol );
				return retVec;
			}
		}
	}

	//default... should never reach here
	retVec[0] = 0;
	retVec[1] = 1;
	return retVec;
	
}

vector<int> mimeTargetVector( Player theMime, int side, int distance )
{
	vector<int> retVec (2, 0);

	distance = abs( distance );

	if( theMime.facingDir == "NORTH" )
	{
		retVec[0] = theMime.currentRow - distance;
		retVec[1] = theMime.currentCol + side;
	}
	else if( theMime.facingDir == "SOUTH" )
	{
		retVec[0] = theMime.currentRow + distance;
		retVec[1] = theMime.currentCol - side;
	}
	else if( theMime.facingDir == "EAST" )
	{
		retVec[0] = theMime.currentRow + side;
		retVec[1] = theMime.currentCol + distance;
	}
	else if( theMime.facingDir == "WEST" )
	{
		retVec[0] = theMime.currentRow - side;
		retVec[1] = theMime.currentCol - distance;
	}
	
	return retVec;
}



//magic evade
long int magicEvade( int baseHit, Player actor, Player target )
{
	long int hitChance = 0;
	double shieldEvade = target.offHandMagEvade;
	double accEvade = target.accMagEvade;

	if( target.charging == true || target.performing == true || target.dontAct == true || target.chicken == true
		|| target.frog == true || target.sleep == true || target.stop == true || target.bloodSuck == true
		|| target.confusion == true || target.berserk == true )
		return baseHit;

	if( target.defending == true )
	{
		shieldEvade *= 2;
		accEvade *= 2;
	}
	if( target.abandon == true && target.bloodSuck == false && target.chicken == false && target.confusion == false
		&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
		&& target.berserk == false && target.dontAct == false && target.sleep == false )
	{
		shieldEvade *= 2;
		accEvade *= 2;
	}
	if( actor.confusion == true )
	{
		shieldEvade *= 2;
		accEvade *= 2;
	}
	hitChance = ( baseHit * ( 100 - shieldEvade ) * ( 100 - accEvade ) / 10000 );
	if( hitChance > 100 )
		hitChance = 100;
	else if( hitChance < 0 )
		hitChance = 0;
	return hitChance;
}

int bladeGraspFunction( Player target, Player actor, int baseHit, bool ninjaThrow )
{
	int hitChance = 0;

	//concentrate & bow versus target with arrow guard
	if( target.arrowGuard == true &&
		( actor.weaponType == "Bow" || actor.weaponType == "Crossbow" ) )
	{
		hitChance = ( baseHit * (100 - target.brave ) ) / 100;
		return hitChance;
	}
	//concentrate & ninja throw against someone with catch
	else if( ninjaThrow == true && target.reactionCatch == true )
	{
		hitChance = ( baseHit * (100 - target.brave ) ) / 100;
		return hitChance;
	}
	//concentrate versus blade grasp
	else if( target.bladeGrasp == true )
	{
		hitChance = ( baseHit * (100 - target.brave ) ) / 100;
		return hitChance;
	}
	else
	{
		hitChance = baseHit;
		return hitChance;
	}
}


//better evade function, used for all physical non counter grasp evade
int evadeFunction( int baseHit, Player actor, Player target,
	string type = "physical", bool gunShot = false )
{
	double cEvade = target.cEvade;
	double offHandPhyEvade = target.offHandPhyEvade;
	double accPhyEvade = target.accPhyEvade;
	double weaponEvade = 0;
	double doubleBaseHit = baseHit; //hope this works
	int hitChance = 0;

	if( target.nullPlayer == true || target.petrify == true || target.dead == true )
	{
		hitChance = 0;
		return hitChance;
	}

	 //evasion and reaction abilities do not trigger w/ any of these status's
	if( target.charging == true || target.performing == true || target.dontAct == true || target.chicken == true
		|| target.sleep == true || target.stop == true || target.bloodSuck == true
		|| target.confusion == true || target.berserk == true )
		return baseHit;

	if( actor.concentrate == true ) //blade grasp and arrow guard handled in other function
	{
		return baseHit;
	}

	if( ( actor.weaponType == "Gun" || actor.weaponType == "Magic Gun" ) && gunShot == true )
	{
		if( actor.weaponType == "Magic Gun" )
			return baseHit;
		if( target.bladeGrasp == true )
		{
			doubleBaseHit = baseHit * ( 100 - target.brave ) / 100;
			return doubleBaseHit;
		}
		else return baseHit;
	}

	if( target.weaponGuard == true )
	{
		weaponEvade = target.weaponEvade;
	}

	if( target.defending == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	if( target.abandon == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	if ( actor.darkness == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	if( actor.confusion == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}


	if( type == "physical" ) //mag evade handled in different function
	{
		
		if( target.facingDir == "NORTH" )
		{
			if( ( abs(actor.currentRow - target.currentRow ) >= abs(actor.currentCol - target.currentCol) )
				&& (actor.currentRow < target.currentRow) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//cout << "North, front " << hitChance << '\n';
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) > abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentRow > target.currentRow ) ) //back
			{
				hitChance = ( ( doubleBaseHit  * ( 100 - accPhyEvade) ) / 100 );
				//cout << "North, back " << hitChance << '\n';
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//cout << "North, side " << hitChance << '\n';
				return hitChance;
			}
		}
		else if( target.facingDir == "SOUTH" )
		{
			if( ( abs( actor.currentRow - target.currentRow ) > abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentRow < target.currentRow ) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade ) ) / 100 );
				//cout << "south, back " << hitChance << '\n';
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) >= abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentRow > target.currentRow ) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//cout << "south, front " << hitChance << '\n';
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//cout << "South, side " << hitChance << '\n';
				return hitChance;
			}
		}
		else if( target.facingDir == "EAST" )
		{
			if( ( abs( actor.currentRow - target.currentRow ) <= abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentCol > target.currentCol ) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//cout << "east, front " << hitChance << '\n';
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) < abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentCol < target.currentCol ) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade) ) / 100 );
				//cout << "east, back " << hitChance << '\n';
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//cout << "east, side " << hitChance << '\n';
				return hitChance;
			}
		}
		else if( target.facingDir == "WEST" )
		{
			if( ( abs( actor.currentRow - target.currentRow ) < abs( actor.currentCol - target.currentCol) )
				&& (actor.currentCol > target.currentCol) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade ) ) / 100 );
				//cout << "west, back " << hitChance << '\n';
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) <= abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentCol < target.currentCol ) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//cout << "west, front " << hitChance << '\n';
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//cout << "west, side " << hitChance << '\n';
				return hitChance;
			}
		}
	}

	cout << "ERROR MESSAGE no direction, no side" << hitChance << '\n';
	return 0;
}


//counterGrasp Evade function
	//used for attack (not magic gun), jump, throw, charge, battle skill, steal equipment
int counterGraspEvade( int baseHit, Player actor, Player target, bool ninjaThrow = false,
	string type = "physical", bool gunShot = true )
{
	double cEvade = target.cEvade;
	double offHandPhyEvade = target.offHandPhyEvade;
	double accPhyEvade = target.accPhyEvade;
	double weaponEvade = 0;
	double doubleBaseHit = baseHit; //hope this works
	int hitChance = 0;
	
	if( target.nullPlayer == true || target.petrify == true || target.dead == true )
	{
		hitChance = 0;
		return hitChance;
	}

	if( target.charging == true || target.performing == true || target.dontAct == true || target.chicken == true
		|| target.sleep == true || target.stop == true || target.bloodSuck == true
		|| target.confusion == true || target.berserk == true )
		return baseHit;

	if( ( type == "Jump" && target.bladeGrasp == true ) ||
		( type == "Jump" && target.arrowGuard == true && ( actor.weaponType == "Bow" || actor.weaponType == "Crossbow" ) )
		)
	{
		hitChance = 100 - target.brave;
		return hitChance;
	}
	else if( type == "Jump" )
	{
		hitChance = 100;
		return hitChance;
	}
	
	if( ( actor.weaponType == "Gun" || actor.weaponType == "Magic Gun" ) && gunShot == true )
	{
		if( actor.weaponType == "Magic Gun" )
			return baseHit;
		if( target.bladeGrasp == true )
		{
			doubleBaseHit = baseHit * ( 100 - target.brave ) / 100;
			return doubleBaseHit;
		}
		else return baseHit;
	}

	if ( target.weaponGuard == true )
	{
		weaponEvade = target.weaponEvade;
	}

	if( target.defending == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	if( target.abandon == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	if ( actor.darkness == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	if( actor.confusion == true )
	{
		cEvade *= 2;
		offHandPhyEvade *= 2;
		accPhyEvade *= 2;
		weaponEvade *= 2;
	}
	
	if( type == "physical" )
	{
		if( actor.concentrate == true ) //if player has concentrate equipped as support
		{
			hitChance = bladeGraspFunction( target, actor, baseHit, ninjaThrow );
			return hitChance;
		}

		else if( target.facingDir == "NORTH" )
		{
			if( ( abs(actor.currentRow - target.currentRow) >= abs(actor.currentCol - target.currentCol) )
				&& (actor.currentRow < target.currentRow) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;

			}
			else if( ( abs( actor.currentRow - target.currentRow ) > abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentRow > target.currentRow ) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade ) ) / 100 );
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
		}
		if( target.facingDir == "SOUTH" )
		{
			if( ( abs( actor.currentRow - target.currentRow ) > abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentRow < target.currentRow ) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade ) ) / 100 );
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) >= abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentRow > target.currentRow ) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
		}
		if( target.facingDir == "EAST" )
		{
			if( ( abs( actor.currentRow - target.currentRow ) <= abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentCol > target.currentCol ) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) < abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentCol < target.currentCol ) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade ) ) / 100 );
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
		}
		if( target.facingDir == "WEST" )
		{
			if( ( abs( actor.currentRow - target.currentRow ) < abs( actor.currentCol - target.currentCol) )
				&& (actor.currentCol > target.currentCol) ) //back
			{
				hitChance = ( ( baseHit  * ( 100 - accPhyEvade ) ) / 100 );
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else if( ( abs( actor.currentRow - target.currentRow ) <= abs( actor.currentCol - target.currentCol ) )
				&& ( actor.currentCol < target.currentCol ) ) //front
			{
				hitChance = doubleBaseHit * ( 100 - cEvade ) * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 100000000;
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
			else //side
			{
				hitChance = doubleBaseHit * ( 100 - offHandPhyEvade ) * ( 100 - accPhyEvade ) * ( 100 - weaponEvade ) / 1000000;
				//reduced chance due to bladegrasp, catch arrow guard
				hitChance = bladeGraspFunction( target, actor, hitChance, ninjaThrow );
				return hitChance;
			}
		}
	}
	
	cout << "\tbeta error message: no direction, no side" << hitChance << "\n";
	return 0;
}


//crit function
int critCalculator(int xa, Player &actor)
{
	actor.critKnockback = false;
	int critTest = 0;
	critTest = rand() % 20;
	int knockbackTest = 0;
	if(critTest < 1 ) // return to < 1 when finished
	{
		actor.critKnockback = true;
		cout << "\t"<< "CRITICAL HIT!" << '\n';
		int xaModifier = 0;
		xaModifier = rand() % xa;
		xa += xaModifier;
		return xa;
	}
	else return xa;
}


//knockback
//need to add more if statements in case player cannot be knocked back
bool knockback(Player &actor, Player &target, char myArray[][11] )
{
	int kRand;
	kRand = rand() % 2;
	if( kRand == 0 )
	{
		cout << "\tChance for knockback... FAILS!" << "\n";
		return false;
	}
	else if( kRand == 1 )
	{
		cout << "\tChance for knockback... HITS!" << "\n";
		if( ( abs(actor.currentRow - target.currentRow) >= abs(actor.currentCol - target.currentCol) )
			&& (actor.currentRow < target.currentRow) ) //front
		{
			//cout << "\t beta test message knockback down the map"  << '\n';
			if( target.currentRow < 10 && myArray[target.currentRow + 1][target.currentCol] == 'O' )
			{
				myArray[target.currentRow][target.currentCol] = 'O';
				target.currentRow += 1;
				cout << "\t" << target.teamName << " now at (" << target.currentRow-1 <<", " <<target.currentCol-1 <<")\n";
				myArray[target.currentRow][target.currentCol] = target.mapSymbol;
				return true;
			}
			else
			{
				cout << "\tbut player cannot be knocked back!\n";
				return false;
			}
		}
		else if( ( abs( actor.currentRow - target.currentRow ) > abs( actor.currentCol - target.currentCol ) )
			&& ( actor.currentRow > target.currentRow ) ) //back
		{
			//cout << "\t beta test message knockback up the map"  << '\n';
			if( target.currentRow > 1 && myArray[target.currentRow - 1][target.currentCol] == 'O')
			{
				myArray[target.currentRow][target.currentCol] = 'O';
				target.currentRow -= 1;
				cout << "\t" << target.teamName << " now at (" << target.currentRow-1 <<", " <<target.currentCol-1 <<")\n";
				myArray[target.currentRow][target.currentCol] = target.mapSymbol;
				return true;
			}
			else
			{
				cout << "\tbut player cannot be knocked back!\n";
				return false;
			}
		}
		else if( ( abs( actor.currentRow - target.currentRow ) <= abs( actor.currentCol - target.currentCol ) )
			&& ( actor.currentCol > target.currentCol ) ) //front
		{
			//cout << "\t beta test message knockback west the map"  << '\n';
			if( target.currentCol > 1 && myArray[target.currentRow][target.currentCol-1] == 'O' )
			{
				myArray[target.currentRow][target.currentCol] = 'O';
				target.currentCol -= 1;
				cout << "\t" << target.teamName << " now at (" << target.currentRow-1 <<", " <<target.currentCol-1 <<")\n";
				myArray[target.currentRow][target.currentCol] = target.mapSymbol;
				return true;
			}
			else
			{
				cout << "\tbut player cannot be knocked back!\n";
				return false;
			}
		}
		else if( ( abs( actor.currentRow - target.currentRow ) < abs( actor.currentCol - target.currentCol ) )
			&& ( actor.currentCol < target.currentCol ) ) //back
		{
			//cout << "\t beta test message knockback east the map"  << '\n';
			if( target.currentCol < 10 && myArray[target.currentRow][target.currentCol+1] == 'O' )
			{
				myArray[target.currentRow][target.currentCol] = 'O';
				target.currentCol += 1;
				cout << "\t" << target.teamName << " now at (" << target.currentRow-1 <<", " <<target.currentCol-1 <<")\n";
				myArray[target.currentRow][target.currentCol] = target.mapSymbol;
				return true;
			}
			else
			{
				cout << "\tbut player cannot be knocked back!\n";
				return false;
			}
		}
	}
	return false;
}



int mod1( Player &actor, Player &target, int xa0, int baseHit )
{
	int xa = 0;
	xa = xa0;
	xa = mod3Zodiac( xa, baseHit, actor, target );
	xa += baseHit;
	return xa;
}

int mod2( Player &actor, Player &target, int xa0, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false )
{
	int xa = 0;
	int damage = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	xa = critCalculator( xa, actor );
	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.attackUp == true )
		xa = xa * 4 / 3;
	if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
		xa = xa * 3 / 2;
	if( actor.berserk == true )
		xa = xa * 3 / 2;
	if( target.defenseUp == true )
		xa = xa * 2 / 3;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.chicken == true || target.frog == true )
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );

	damage = xa;
	//no elemental factors
	if( fireType == false && waterType == false &&
		iceType == false && lightningType == false &&
		holyType == false && darkType == false &&
		windType == false && earthType == false )
		return damage;
	//target weak against elementals
	else if( (fireType == true && target.fireWeak == true ) ||
		(waterType == true && target.waterWeak == true ) ||
		(iceType == true && target.iceWeak == true ) ||
		(lightningType == true && target.lightningWeak == true ) ||
		(windType == true && target.windWeak == true ) ||
		(earthType == true && target.earthWeak == true ) ||
		(darkType == true && target.darkWeak == true ) ||
		(holyType == true && target.holyWeak == true ) )
		return damage * 2;
	//target half against elementals
	else if( ( fireType == true && target.fireHalf == true ) ||
		( waterType == true && target.waterHalf == true ) ||
		( iceType == true && target.iceHalf == true ) ||
		( lightningType == true && target.lightningHalf == true ) ||
		( windType == true && target.windHalf == true ) ||
		( earthType == true && target.earthHalf == true ) ||
		( darkType == true && target.darkHalf == true ) ||
		( holyType == true && target.holyHalf == true ) )
		return damage / 2;
	//target absorb against elementals
	else if( ( fireType == true && target.fireAbsorb == true ) ||
		( waterType == true && target.waterAbsorb == true ) ||
		( iceType == true && target.iceAbsorb == true ) ||
		( lightningType == true && target.lightningAbsorb == true ) ||
		( windType == true && target.windAbsorb == true ) ||
		( earthType == true && target.earthAbsorb == true ) ||
		( darkType == true && target.darkAbsorb == true ) ||
		( holyType == true && target.holyAbsorb == true ) )
	{
		damage *= -1;
		return damage;
	}
	else return damage;
}

int mod2xa( Player &actor, Player &target, int xa0, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false, bool chakra = false )
{
	int xa = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	xa = critCalculator( xa, actor );
	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.attackUp == true )
		xa = xa * 4 / 3;
	if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
		xa = xa * 3 / 2;
	if( actor.berserk == true )
		xa = xa * 3 / 2;
	if( chakra == false )
	{
		if( target.defenseUp == true )
			xa = xa * 2 / 3;
		if( target.protect == true )
			xa = xa * 2 / 3;
	}
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.chicken == true || target.frog == true )
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );

	return xa;
}

int mod2xaDisplay( Player &actor, Player &target, int xa0, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false, bool chakra = false )
{
	int xa = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.attackUp == true )
		xa = xa * 4 / 3;
	if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
		xa = xa * 3 / 2;
	if( actor.berserk == true )
		xa = xa * 3 / 2;
	if( chakra == false )
	{
		if( target.defenseUp == true )
			xa = xa * 2 / 3;
		if( target.protect == true )
			xa = xa * 2 / 3;
	}
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.chicken == true || target.frog == true )
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );

	return xa;
}

int mod2Damage( Player &actor, Player &target, int damage, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false )
{

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	//no elemental factors
	if( fireType == false && waterType == false &&
		iceType == false && lightningType == false &&
		holyType == false && darkType == false &&
		windType == false && earthType == false )
		return damage;
	//target weak against elementals
	else if( (fireType == true && target.fireWeak == true ) ||
		(waterType == true && target.waterWeak == true ) ||
		(iceType == true && target.iceWeak == true ) ||
		(lightningType == true && target.lightningWeak == true ) ||
		(windType == true && target.windWeak == true ) ||
		(earthType == true && target.earthWeak == true ) ||
		(darkType == true && target.darkWeak == true ) ||
		(holyType == true && target.holyWeak == true ) )
		return damage * 2;
	//target half against elementals
	else if( ( fireType == true && target.fireHalf == true ) ||
		( waterType == true && target.waterHalf == true ) ||
		( iceType == true && target.iceHalf == true ) ||
		( lightningType == true && target.lightningHalf == true ) ||
		( windType == true && target.windHalf == true ) ||
		( earthType == true && target.earthHalf == true ) ||
		( darkType == true && target.darkHalf == true ) ||
		( holyType == true && target.holyHalf == true ) )
		return damage / 2;
	//target absorb against elementals
	else if( ( fireType == true && target.fireAbsorb == true ) ||
		( waterType == true && target.waterAbsorb == true ) ||
		( iceType == true && target.iceAbsorb == true ) ||
		( lightningType == true && target.lightningAbsorb == true ) ||
		( windType == true && target.windAbsorb == true ) ||
		( earthType == true && target.earthAbsorb == true ) ||
		( darkType == true && target.darkAbsorb == true ) ||
		( holyType == true && target.holyAbsorb == true ) )
	{
		damage *= -1;
		return damage;
	}
	else return damage;
}

int mod2Display( Player &actor, Player &target, int xa0, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false )
{
	int xa = 0;
	int damage = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	//xa = critCalculator( xa, actor );
	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.attackUp == true )
		xa = xa * 4 / 3;
	if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
		xa = xa * 3 / 2;
	if( actor.berserk == true )
		xa = xa * 3 / 2;
	if( target.defenseUp == true )
		xa = xa * 2 / 3;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.chicken == true || target.frog == true )
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );

	damage = xa;
	//no elemental factors
	if( fireType == false && waterType == false &&
		iceType == false && lightningType == false &&
		holyType == false && darkType == false &&
		windType == false && earthType == false )
		return damage;
	//target weak against elementals
	else if( (fireType == true && target.fireWeak == true ) ||
		(waterType == true && target.waterWeak == true ) ||
		(iceType == true && target.iceWeak == true ) ||
		(lightningType == true && target.lightningWeak == true ) ||
		(windType == true && target.windWeak == true ) ||
		(earthType == true && target.earthWeak == true ) ||
		(darkType == true && target.darkWeak == true ) ||
		(holyType == true && target.holyWeak == true ) )
		return damage * 2;
	//target half against elementals
	else if( ( fireType == true && target.fireHalf == true ) ||
		( waterType == true && target.waterHalf == true ) ||
		( iceType == true && target.iceHalf == true ) ||
		( lightningType == true && target.lightningHalf == true ) ||
		( windType == true && target.windHalf == true ) ||
		( earthType == true && target.earthHalf == true ) ||
		( darkType == true && target.darkHalf == true ) ||
		( holyType == true && target.holyHalf == true ) )
		return damage / 2;
	//target absorb against elementals
	else if( ( fireType == true && target.fireAbsorb == true ) ||
		( waterType == true && target.waterAbsorb == true ) ||
		( iceType == true && target.iceAbsorb == true ) ||
		( lightningType == true && target.lightningAbsorb == true ) ||
		( windType == true && target.windAbsorb == true ) ||
		( earthType == true && target.earthAbsorb == true ) ||
		( darkType == true && target.darkAbsorb == true ) ||
		( holyType == true && target.holyAbsorb == true ) )
	{
		damage *= -1;
		return damage;
	}
	else return damage;
}

//mode 3 returns the xa success amount which then must be applied to the formula in
	//the ability menu
int mod3( Player &actor, Player &target, int xa0, int baseHit, int weaponPower = 0 )
{
	int xa = 0;
	xa = xa0;

	if( target.nullPlayer == true || target.petrify == true || target.dead == true )
	{
		return 0;
	}

	if( actor.attackUp == true )
		xa = xa * 4 / 3;
	if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
		xa = xa * 3 / 2;
	if( target.defenseUp == true )
		xa = xa * 2 / 3;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.chicken == true || target.frog == true )
		xa = xa * 3 / 2;
	xa = mod3Zodiac( xa, baseHit, actor, target, weaponPower );
	return xa;
}

//mod 4 returns the overall success value
int mod4( Player &actor, Player &target, int xa0, int baseHit )
{
	int xa = 0;
	xa = xa0;

	if( actor.attackUp == true )
		xa = xa * 4 / 3;
	if( actor.martialArts == true )
		xa = xa * 3 / 2;
	if( target.defenseUp == true )
		xa = xa * 2 / 3;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.chicken == true || target.frog == true )
		xa = xa * 3 / 2;
	xa = mod3Zodiac( xa, baseHit, actor, target );
	xa = xa + baseHit;
	return xa;
}

//mod 5 magic attacks, add more in case weather is ever done
int mod5Magic( Player &actor, Player &target, long int xa0, long int component, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false  )
{
	long int xa = 0;
	long int damage = 0;
	long int targetFaith = target.faith;
	long int actorFaith = actor.faith;
	long int fNum = 0;
	long int fDen = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;
	if( target.magicDefendUp == true )
		xa = xa * 2 / 3;
	if( target.shell== true )
		xa = xa * 2 / 3;
	xa = zodiac( xa, actor, target );

	if( target.statusFaith == true )
		targetFaith = 100;
	if( actor.statusFaith == true )
		actorFaith = 100;
	if( target.innocent == true )
		targetFaith = 0;
	if( actor.innocent == true )
		actorFaith = 0;

	fNum = 1;
	fDen = 1;
	//add elementals here

	//target weak against elementals
	if( (fireType == true && target.fireWeak == true ) ||
		(waterType == true && target.waterWeak == true ) ||
		(iceType == true && target.iceWeak == true ) ||
		(lightningType == true && target.lightningWeak == true ) ||
		(windType == true && target.windWeak == true ) ||
		(earthType == true && target.earthWeak == true ) ||
		(darkType == true && target.darkWeak == true ) ||
		(holyType == true && target.holyWeak == true ) )
		fNum *= 2;
	//target half against elementals
	else if( ( fireType == true && target.fireHalf == true ) ||
		( waterType == true && target.waterHalf == true ) ||
		( iceType == true && target.iceHalf == true ) ||
		( lightningType == true && target.lightningHalf == true ) ||
		( windType == true && target.windHalf == true ) ||
		( earthType == true && target.earthHalf == true ) ||
		( darkType == true && target.darkHalf == true ) ||
		( holyType == true && target.holyHalf == true ) )
		fDen *= 2;
	//target absorb against elementals
	else if( ( fireType == true && target.fireAbsorb == true ) ||
		( waterType == true && target.waterAbsorb == true ) ||
		( iceType == true && target.iceAbsorb == true ) ||
		( lightningType == true && target.lightningAbsorb == true ) ||
		( windType == true && target.windAbsorb == true ) ||
		( earthType == true && target.earthAbsorb == true ) ||
		( darkType == true && target.darkAbsorb == true ) ||
		( holyType == true && target.holyAbsorb == true ) )
	{
		fNum *=-1;
	}

	damage = ( xa * actorFaith * targetFaith * component * fNum ) / ( 10000 * fDen );
	return damage;
}

//cure ignores magic defend up and shell
int mod5White( Player &actor, Player &target, long int xa0, long int component, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false  )
{
	long int xa = 0;
	long int damage = 0;
	long int targetFaith = target.faith;
	long int actorFaith = actor.faith;
	long int fNum = 0;
	long int fDen = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;
	xa = zodiac( xa, actor, target );

	if( target.statusFaith == true )
		targetFaith = 100;
	if( actor.statusFaith == true )
		actorFaith = 100;
	if( target.innocent == true )
		targetFaith = 0;
	if( actor.innocent == true )
		actorFaith = 0;

	fNum = 1;
	fDen = 1;
	//add elementals here

	//target weak against elementals
	if( (fireType == true && target.fireWeak == true ) ||
		(waterType == true && target.waterWeak == true ) ||
		(iceType == true && target.iceWeak == true ) ||
		(lightningType == true && target.lightningWeak == true ) ||
		(windType == true && target.windWeak == true ) ||
		(earthType == true && target.earthWeak == true ) ||
		(darkType == true && target.darkWeak == true ) ||
		(holyType == true && target.holyWeak == true ) )
		fNum *= 2;
	//target half against elementals
	else if( ( fireType == true && target.fireHalf == true ) ||
		( waterType == true && target.waterHalf == true ) ||
		( iceType == true && target.iceHalf == true ) ||
		( lightningType == true && target.lightningHalf == true ) ||
		( windType == true && target.windHalf == true ) ||
		( earthType == true && target.earthHalf == true ) ||
		( darkType == true && target.darkHalf == true ) ||
		( holyType == true && target.holyHalf == true ) )
		fDen *= 2;
	//target absorb against elementals
	else if( ( fireType == true && target.fireAbsorb == true ) ||
		( waterType == true && target.waterAbsorb == true ) ||
		( iceType == true && target.iceAbsorb == true ) ||
		( lightningType == true && target.lightningAbsorb == true ) ||
		( windType == true && target.windAbsorb == true ) ||
		( earthType == true && target.earthAbsorb == true ) ||
		( darkType == true && target.darkAbsorb == true ) ||
		( holyType == true && target.holyAbsorb == true ) )
	{
		fNum *=-1;
	}

	damage = ( xa * actorFaith * targetFaith * component * fNum ) / ( 10000 * fDen );
	return damage;
}


int mod5Elemental( Player &actor, Player &target, int xa0, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false  )
{
	int xa = 0;
	int damage = 0;
	xa = xa0;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;
	if( target.magicDefendUp == true )
		xa = xa * 2 / 3;
	if( target.shell== true )
		xa = xa * 2 / 3;
	xa = zodiac( xa, actor, target );

	damage = ( actor.pa + 2 / 2 ) * xa;

	//no elemental factors
	if( fireType == false && waterType == false &&
		iceType == false && lightningType == false &&
		holyType == false && darkType == false &&
		windType == false && earthType == false )
		return damage;
	//target weak against elementals
	else if( (fireType == true && target.fireWeak == true ) ||
		(waterType == true && target.waterWeak == true ) ||
		(iceType == true && target.iceWeak == true ) ||
		(lightningType == true && target.lightningWeak == true ) ||
		(windType == true && target.windWeak == true ) ||
		(earthType == true && target.earthWeak == true ) ||
		(darkType == true && target.darkWeak == true ) ||
		(holyType == true && target.holyWeak == true ) )
		return damage * 2;
	//target half against elementals
	else if( ( fireType == true && target.fireHalf == true ) ||
		( waterType == true && target.waterHalf == true ) ||
		( iceType == true && target.iceHalf == true ) ||
		( lightningType == true && target.lightningHalf == true ) ||
		( windType == true && target.windHalf == true ) ||
		( earthType == true && target.earthHalf == true ) ||
		( darkType == true && target.darkHalf == true ) ||
		( holyType == true && target.holyHalf == true ) )
		return damage / 2;
	//target absorb against elementals
	else if( ( fireType == true && target.fireAbsorb == true ) ||
		( waterType == true && target.waterAbsorb == true ) ||
		( iceType == true && target.iceAbsorb == true ) ||
		( lightningType == true && target.lightningAbsorb == true ) ||
		( windType == true && target.windAbsorb == true ) ||
		( earthType == true && target.earthAbsorb == true ) ||
		( darkType == true && target.darkAbsorb == true ) ||
		( holyType == true && target.holyAbsorb == true ) )
	{
		damage *= -1;
		return damage;
	}
	else return damage;
}

int mod5DrawOut( Player &actor, Player &target, int xa0, int drawOutConstant )
{
	int xa = 0;
	int damage = 0;
	xa = xa0;

	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;
	if( target.magicDefendUp == true )
		xa = xa * 2 / 3;
	if( target.shell == true )
		xa = xa * 2 / 3;
	xa = zodiac( xa, actor, target );

	damage = drawOutConstant * xa;

	return damage;
}

//returns the hit chance prior to evasion function
int mod6( Player &actor, Player &target, long int ma0, long int component, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false )
{
	long int xa;
	xa = ma0;
	long int hitChance;
	long int actorFaith = actor.faith;
	long int targetFaith = target.faith;

	elementUpTest( actor );
	elementDefenseTest( target );

	//floating targets are immune to earth elemental attacks
	if( earthType == true && ( target.statusFloat == true || 
		target.accAutoFloat == true ) )
		return 0;

	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;
	if( target.magicDefendUp == true )
		xa = xa * 2 / 3;
	if( target.shell == true )
		xa = xa * 2 / 3;
	xa = mod3Zodiac( xa, component, actor, target );

	if( actor.statusFaith == true )
		actorFaith = 100;
	if( actor.innocent == true )
		actorFaith = 0;
	if( target.statusFaith == true )
		targetFaith = 100;
	if( target.innocent == true )
		targetFaith = 0;

	hitChance = ( actorFaith * targetFaith * ( xa + component ) ) / 10000;
	if(hitChance > 100)
		hitChance = 100;
	return hitChance;
}

//white magic ignores shell and magic defendUP
int mod6White( Player &actor, Player &target, long int ma0, long int component, bool fireType = false,
	bool iceType = false, bool waterType = false, bool lightningType = false,
	bool holyType = false, bool darkType = false, bool earthType = false,
	bool windType = false )
{
	long int xa;
	xa = ma0;
	long int hitChance;
	long int actorFaith = actor.faith;
	long int targetFaith = target.faith;

	elementUpTest( actor );
	elementDefenseTest( target );

	if( ( fireType == true && actor.fireUp == true ) ||
		( iceType == true && actor.iceUp == true ) ||
		( waterType == true && actor.waterUp == true ) ||
		( lightningType == true && actor.lightningUp == true ) ||
		( holyType == true && actor.holyUp == true ) ||
		( darkType == true && actor.darkUp == true ) ||
		( earthType == true && actor.earthUp == true ) ||
		( windType == true && actor.windUp == true ) )
		xa = xa * 5 / 4;
	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;
	xa = mod3Zodiac( xa, component, actor, target );

	if( actor.statusFaith == true )
		actorFaith = 100;
	if( actor.innocent == true )
		actorFaith = 0;
	if( target.statusFaith == true )
		targetFaith = 100;
	if( target.innocent == true )
		targetFaith = 0;

	hitChance = ( actorFaith * targetFaith * ( xa + component ) ) / 10000;
	if(hitChance > 100)
		hitChance = 100;
	return hitChance;
}


//golem
int mod6Golem( Player &actor, long int ma0, long int component )
{
	long int xa;
	xa = ma0;
	long int hitChance;
	long int actorFaith = actor.faith;


	if( actor.magicAttackUp == true )
		xa = xa * 4 / 3;

	if( actor.statusFaith == true )
		actorFaith = 100;
	if( actor.innocent == true )
		actorFaith = 0;

	hitChance = ( actorFaith * ( xa + component ) ) / 100;
	if(hitChance > 100)
		hitChance = 100;
	return hitChance;
}


int magicGun( Player &actor, Player &target )
{
	bool fireType = false;
	bool iceType = false;
	bool lightningType = false;
	actor.magicGunStrength = 1;

	int componentRoll;
	int component = 14;
	int damage;

	if( actor.weaponPower == 20 )
		iceType = true;
	if( actor.weaponPower == 21 )
		fireType = true;
	if( actor.weaponPower == 22 )
		lightningType = true;

	componentRoll = rand() % 100 + 1;

	if( componentRoll <= 10 )
	{
		component = 24;
		actor.magicGunStrength = 3;
	}
	else if( componentRoll <= 70 )
	{
		component = 18;
		actor.magicGunStrength = 2;
	}
	else component = 14;

	//keep it positive, goes minus in the main attack function
	damage = mod5Magic( actor, target, actor.weaponPower, component, fireType, iceType,
		false, lightningType );
	return damage;
}

//attack damage function 
int attackDamage( Player &actor, Player &target )
	{
		int xa0 = 0;
		int xa = 0;
		int damage = 0;

		elementUpTest( actor );
		elementDefenseTest( target );

		if( target.dead == true || target.petrify == true )
			return damage;
		if( actor.frog == true )
		{
			damage = actor.pa * actor.brave / 100;
			return damage;
		}

		if( actor.weaponType == "Magic Gun" )
		{
			damage = magicGun( actor, target );
			return damage;
		}
	
		if( actor.weaponType == "Bare Hands" || actor.weaponType == "Katana" || actor.weaponType == "Knight Sword" )
			xa0 = ( actor.pa + actor.ctrK ) * actor.brave / 100; 
		else if( actor.weaponType == "Knife" || actor.weaponType == "Ninja Sword" || actor.weaponType == "Bow" )
			xa0 = ( actor.pa + actor.speed + 2 * actor.ctrK ) / 2;
		else if( actor.weaponType == "Sword" || actor.weaponType == "Rod" || actor.weaponType == "Spear"
			|| actor.weaponType == "Crossbow" )
			xa0 = ( actor.pa + actor.ctrK );
		else if( actor.weaponType == "Staff" || actor.weaponType == "Stick" )
			xa0 = ( actor.ma + actor.ctrK );
		else if( actor.weaponType == "Flail" || actor.weaponType == "Axe" || actor.weaponType == "Bag" )
		{
			xa0 = rand() % ( actor.pa + actor.ctrK ) + 1;
		}
		else if( actor.weaponType == "Fabric" || actor.weaponType == "Harp" || actor.weaponType == "Dictionary" )
			xa0 = (actor.ma + actor.pa + 2 * actor.ctrK ) / 2;
		else if( actor.weaponType == "Gun" )
			xa0 = actor.weaponPower + actor.ctrK;

		//begins damage modifiers
		xa = xa0;
		xa = critCalculator( xa, actor );
		if( ( actor.fireWeapon == true && actor.fireUp == true ) ||
			( actor.iceWeapon == true && actor.iceUp == true ) ||
			( actor.waterWeapon == true && actor.waterUp == true ) ||
			( actor.lightningWeapon == true && actor.lightningUp == true ) ||
			( actor.holyWeapon == true && actor.holyUp == true ) ||
			( actor.darkWeapon == true && actor.darkUp == true ) ||
			( actor.earthWeapon == true && actor.earthUp == true ) ||
			( actor.windWeapon == true && actor.windUp == true ) )
			xa = xa * 5 / 4;
		if( actor.attackUp == true )
			xa = xa * 4 / 3;
		if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
			xa = xa * 3 / 2;
		if( actor.berserk == true )
			xa = xa * 3 / 2;
		if( target.defenseUp == true )
			xa = xa * 2 / 3;
		if( target.protect == true )
			xa = xa * 2 / 3;
		if( target.charging == true )
			xa = xa * 3 / 2;
		if( target.sleep == true )
			xa = xa * 3 / 2;
		if( target.chicken == true || target.frog == true )
			xa = xa * 3 / 2;
		xa = zodiac( xa, actor, target );

		if( actor.weaponType == "Bare Hands" )
			damage = xa * actor.pa;
		else if( actor.weaponType == "Katana" || actor.weaponType == "Knight Sword" )
		{
			if( actor.weaponType == "Katana" && actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Knife" || actor.weaponType == "Ninja Sword" || actor.weaponType == "Bow" )
		{
			if( ( actor.weaponType == "Knife" || actor.weaponType == "Ninja Sword" ) && actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Sword" || actor.weaponType == "Rod" || actor.weaponType == "Spear"
			|| actor.weaponType == "Crossbow" )
		{
			if( actor.weaponType == "Sword" && actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Staff" || actor.weaponType == "Stick" )
			damage = actor.ma * actor.weaponPower;
		else if( actor.weaponType == "Flail" || actor.weaponType == "Axe" || actor.weaponType == "Bag" )
		{
			if( actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Fabric" || actor.weaponType == "Harp" || actor.weaponType == "Dictionary" )
			damage = xa * actor.weaponPower;
		else if( actor.weaponType == "Gun" )
			damage = xa * actor.weaponPower;

		if( actor.weaponLifeDrain == true && target.undead == true )
		{
			damage *= -1;
		}
		if( actor.weaponHeal == true )
		{
			damage *= -1;
		}

		//no elemental factors
		if( actor.fireWeapon == false && actor.waterWeapon == false &&
			actor.iceWeapon == false && actor.lightningWeapon == false &&
			actor.holyWeapon == false && actor.darkWeapon == false &&
			actor.windWeapon == false && actor.earthWeapon == false )
			return damage;
		//target weak against elementals
		else if( (actor.fireWeapon == true && target.fireWeak == true ) ||
			(actor.waterWeapon == true && target.waterWeak == true ) ||
			(actor.iceWeapon == true && target.iceWeak == true ) ||
			(actor.lightningWeapon == true && target.lightningWeak == true ) ||
			(actor.windWeapon == true && target.windWeak == true ) ||
			(actor.earthWeapon == true && target.earthWeak == true ) ||
			(actor.darkWeapon == true && target.darkWeak == true ) ||
			(actor.holyWeapon == true && target.holyWeak == true ) )
			return damage * 2;
		//target half against elementals
		else if( (actor.fireWeapon == true && target.fireHalf == true ) ||
			(actor.waterWeapon == true && target.waterHalf == true ) ||
			(actor.iceWeapon == true && target.iceHalf == true ) ||
			(actor.lightningWeapon == true && target.lightningHalf == true ) ||
			(actor.windWeapon == true && target.windHalf == true ) ||
			(actor.earthWeapon == true && target.earthHalf == true ) ||
			(actor.darkWeapon == true && target.darkHalf == true ) ||
			(actor.holyWeapon == true && target.holyHalf == true ) )
			return damage / 2;
		//target absorb against elementals
		else if( (actor.fireWeapon == true && target.fireAbsorb == true ) ||
			(actor.waterWeapon == true && target.waterAbsorb == true ) ||
			(actor.iceWeapon == true && target.iceAbsorb == true ) ||
			(actor.lightningWeapon == true && target.lightningAbsorb == true ) ||
			(actor.windWeapon == true && target.windAbsorb == true ) ||
			(actor.earthWeapon == true && target.earthAbsorb == true ) ||
			(actor.darkWeapon == true && target.darkAbsorb == true ) ||
			(actor.holyWeapon == true && target.holyAbsorb == true ) )
		{
			damage *= -1;
			return damage;
		}
		else return damage;
	}

//displays damage, doesn't include criticals
int displayDamage( Player &actor, Player &target )
	{
		int xa0 = 0;
		int xa = 0;
		int damage = 0;

		elementUpTest( actor );
		elementDefenseTest( target );

		if( target.dead == true || target.petrify == true )
			return damage;
		if( actor.frog == true )
		{
			damage = actor.pa * actor.brave / 100;
			return damage;
		}

		if( actor.weaponType == "Magic Gun" )
		{
			damage = magicGun( actor, target );
			return damage;
		}
	
		if( actor.weaponType == "Bare Hands" || actor.weaponType == "Katana" || actor.weaponType == "Knight Sword" )
			xa0 = ( actor.pa + actor.ctrK ) * actor.brave / 100; 
		else if( actor.weaponType == "Knife" || actor.weaponType == "Ninja Sword" || actor.weaponType == "Bow" )
			xa0 = ( actor.pa + actor.speed + 2 * actor.ctrK ) / 2;
		else if( actor.weaponType == "Sword" || actor.weaponType == "Rod" || actor.weaponType == "Spear"
			|| actor.weaponType == "Crossbow" )
			xa0 = ( actor.pa + actor.ctrK );
		else if( actor.weaponType == "Staff" || actor.weaponType == "Stick" )
			xa0 = ( actor.ma + actor.ctrK );
		else if( actor.weaponType == "Flail" || actor.weaponType == "Axe" || actor.weaponType == "Bag" )
		{
			xa0 = rand() % ( actor.pa + actor.ctrK ) + 1;
		}
		else if( actor.weaponType == "Fabric" || actor.weaponType == "Harp" || actor.weaponType == "Dictionary" )
			xa0 = (actor.ma + actor.pa + 2 * actor.ctrK ) / 2;
		else if( actor.weaponType == "Gun" )
			xa0 = actor.weaponPower + actor.ctrK;

		//begins damage modifiers
		xa = xa0;

		if( ( actor.fireWeapon == true && actor.fireUp == true ) ||
			( actor.iceWeapon == true && actor.iceUp == true ) ||
			( actor.waterWeapon == true && actor.waterUp == true ) ||
			( actor.lightningWeapon == true && actor.lightningUp == true ) ||
			( actor.holyWeapon == true && actor.holyUp == true ) ||
			( actor.darkWeapon == true && actor.darkUp == true ) ||
			( actor.earthWeapon == true && actor.earthUp == true ) ||
			( actor.windWeapon == true && actor.windUp == true ) )
			xa = xa * 5 / 4;
		if( actor.attackUp == true )
			xa = xa * 4 / 3;
		if( actor.martialArts == true && actor.weaponType == "Bare Hands" )
			xa = xa * 3 / 2;
		if( actor.berserk == true )
			xa = xa * 3 / 2;
		if( target.defenseUp == true )
			xa = xa * 2 / 3;
		if( target.protect == true )
			xa = xa * 2 / 3;
		if( target.charging == true )
			xa = xa * 3 / 2;
		if( target.sleep == true )
			xa = xa * 3 / 2;
		if( target.chicken == true || target.frog == true )
			xa = xa * 3 / 2;
		xa = zodiac( xa, actor, target );

		if( actor.weaponType == "Bare Hands" )
			damage = xa * actor.pa;
		else if( actor.weaponType == "Katana" || actor.weaponType == "Knight Sword" )
		{
			if( actor.weaponType == "Katana" && actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Knife" || actor.weaponType == "Ninja Sword" || actor.weaponType == "Bow" )
		{
			if( ( actor.weaponType == "Knife" || actor.weaponType == "Ninja Sword" ) && actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Sword" || actor.weaponType == "Rod" || actor.weaponType == "Spear"
			|| actor.weaponType == "Crossbow" )
		{
			if( actor.weaponType == "Sword" && actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Staff" || actor.weaponType == "Stick" )
			damage = actor.ma * actor.weaponPower;
		else if( actor.weaponType == "Flail" || actor.weaponType == "Axe" || actor.weaponType == "Bag" )
		{
			if( actor.twoHands == true )
				damage = xa * ( 2 * actor.weaponPower );
			else damage = xa * actor.weaponPower;
		}
		else if( actor.weaponType == "Fabric" || actor.weaponType == "Harp" || actor.weaponType == "Dictionary" )
			damage = xa * actor.weaponPower;
		else if( actor.weaponType == "Gun" )
			damage = xa * actor.weaponPower;

		if( actor.weaponLifeDrain == true && target.undead == true )
		{
			damage *= -1;
		}
		if( actor.weaponHeal == true )
		{
			damage *= -1;
		}

		//no elemental factors
		if( actor.fireWeapon == false && actor.waterWeapon == false &&
			actor.iceWeapon == false && actor.lightningWeapon == false &&
			actor.holyWeapon == false && actor.darkWeapon == false &&
			actor.windWeapon == false && actor.earthWeapon == false )
			return damage;
		//target weak against elementals
		else if( (actor.fireWeapon == true && target.fireWeak == true ) ||
			(actor.waterWeapon == true && target.waterWeak == true ) ||
			(actor.iceWeapon == true && target.iceWeak == true ) ||
			(actor.lightningWeapon == true && target.lightningWeak == true ) ||
			(actor.windWeapon == true && target.windWeak == true ) ||
			(actor.earthWeapon == true && target.earthWeak == true ) ||
			(actor.darkWeapon == true && target.darkWeak == true ) ||
			(actor.holyWeapon == true && target.holyWeak == true ) )
			return damage * 2;
		//target half against elementals
		else if( (actor.fireWeapon == true && target.fireHalf == true ) ||
			(actor.waterWeapon == true && target.waterHalf == true ) ||
			(actor.iceWeapon == true && target.iceHalf == true ) ||
			(actor.lightningWeapon == true && target.lightningHalf == true ) ||
			(actor.windWeapon == true && target.windHalf == true ) ||
			(actor.earthWeapon == true && target.earthHalf == true ) ||
			(actor.darkWeapon == true && target.darkHalf == true ) ||
			(actor.holyWeapon == true && target.holyHalf == true ) )
			return damage / 2;
		//target absorb against elementals
		else if( (actor.fireWeapon == true && target.fireAbsorb == true ) ||
			(actor.waterWeapon == true && target.waterAbsorb == true ) ||
			(actor.iceWeapon == true && target.iceAbsorb == true ) ||
			(actor.lightningWeapon == true && target.lightningAbsorb == true ) ||
			(actor.windWeapon == true && target.windAbsorb == true ) ||
			(actor.earthWeapon == true && target.earthAbsorb == true ) ||
			(actor.darkWeapon == true && target.darkAbsorb == true ) ||
			(actor.holyWeapon == true && target.holyAbsorb == true ) )
		{
			damage *= -1;
			return damage;
		}
		else return damage;
	}

//offhand damage function
int offHandDamage( Player &actor, Player &target )
	{
		int xa0 = 0;
		int xa = 0;
		int damage = 0;

		elementUpTest( actor );
		elementDefenseTest( target );
	
		if( actor.offHandType == "Bare Hands" || actor.offHandType == "Katana" || actor.offHandType == "Knight Sword" )
			xa0 = ( actor.pa + actor.ctrK ) * actor.brave / 100; 
		else if( actor.offHandType == "Knife" || actor.offHandType == "Ninja Sword" || actor.offHandType == "Bow" )
			xa0 = ( actor.pa + actor.speed + 2 * actor.ctrK ) / 2;
		else if( actor.offHandType == "Sword" || actor.offHandType == "Rod" || actor.offHandType == "Spear"
			|| actor.offHandType == "Crossbow" )
			xa0 = ( actor.pa + actor.ctrK ) * actor.offHandPower;
		else if( actor.offHandType == "Staff" || actor.offHandType == "Stick" )
			xa0 = ( actor.ma + actor.ctrK ) * actor.offHandPower;
		else if( actor.offHandType == "Flail" || actor.offHandType == "Axe" || actor.offHandType == "Bag" )
		{
			xa0 = rand() % ( actor.pa + actor.ctrK ) + 1;
		}
		else if( actor.offHandType == "Fabric" || actor.offHandType == "Harp" || actor.offHandType == "Dictionary" )
			xa0 = (actor.ma + actor.pa + 2 * actor.ctrK ) / 2;
		else if( actor.offHandType == "Gun" )
			xa0 = actor.offHandPower + actor.ctrK;

		//begins damage modifiers
		xa = xa0;
		xa = critCalculator( xa, actor );
		if( ( actor.fireWeapon == true && actor.fireUp == true ) ||
			( actor.iceWeapon == true && actor.iceUp == true ) ||
			( actor.waterWeapon == true && actor.waterUp == true ) ||
			( actor.lightningWeapon == true && actor.lightningUp == true ) ||
			( actor.holyWeapon == true && actor.holyUp == true ) ||
			( actor.darkWeapon == true && actor.darkUp == true ) ||
			( actor.earthWeapon == true && actor.earthUp == true ) ||
			( actor.windWeapon == true && actor.windUp == true ) )
			xa = xa * 5 / 4;
		if( actor.attackUp == true )
			xa = xa * 4 / 3;
		if( actor.martialArts == true && actor.offHandType == "Bare Hands" )
			xa = xa * 3 / 2;
		if( actor.berserk == true )
			xa = xa * 3 / 2;
		if( target.defenseUp == true )
			xa = xa * 2 / 3;
		if( target.protect == true )
			xa = xa * 2 / 3;
		if( target.charging == true )
			xa = xa * 3 / 2;
		if( target.sleep == true )
			xa = xa * 3 / 2;
		if( target.chicken == true || target.frog == true )
			xa = xa * 3 / 2;
		xa = zodiac( xa, actor, target );

		if( actor.offHandType == "Bare Hands" )
			damage = xa * actor.pa;
		else if( actor.offHandType == "Katana" || actor.offHandType == "Knight Sword" )
			damage = xa * actor.offHandPower;
		else if( actor.offHandType == "Knife" || actor.offHandType == "Ninja Sword" || actor.offHandType == "Bow" )
			damage = xa * actor.offHandPower;
		else if( actor.offHandType == "Sword" || actor.offHandType == "Rod" || actor.offHandType == "Spear"
			|| actor.offHandType == "Crossbow" )
			damage = xa * actor.offHandPower;
		else if( actor.offHandType == "Staff" || actor.offHandType == "Stick" )
			xa0 = actor.ma * actor.offHandPower;
		else if( actor.offHandType == "Flail" || actor.offHandType == "Axe" || actor.offHandType == "Bag" )
		{
			damage = xa * actor.offHandPower;
		}
		else if( actor.offHandType == "Fabric" || actor.offHandType == "Harp" || actor.offHandType == "Dictionary" )
			damage = xa * actor.offHandPower;
		else if( actor.offHandType == "Gun" )
			damage = xa * actor.offHandPower;

		if( actor.weaponLifeDrain == true && target.undead == true )
		{
			damage *= -1;
		}
		if( actor.weaponHeal == true )
		{
			damage *= -1;
		}

		//no elemental factors
		if( actor.offHandFireWeapon == false && actor.offHandWaterWeapon == false &&
			actor.offHandIceWeapon == false && actor.offHandLightningWeapon == false &&
			actor.offHandHolyWeapon == false && actor.offHandDarkWeapon == false &&
			actor.offHandWindWeapon == false && actor.offHandEarthWeapon == false )
			return damage;
		//target weak against elementals
		else if( (actor.offHandFireWeapon == true && target.fireWeak == true ) ||
			(actor.offHandWaterWeapon == true && target.waterWeak == true ) ||
			(actor.offHandIceWeapon == true && target.iceWeak == true ) ||
			(actor.offHandLightningWeapon == true && target.lightningWeak == true ) ||
			(actor.offHandWindWeapon == true && target.windWeak == true ) ||
			(actor.offHandEarthWeapon == true && target.earthWeak == true ) ||
			(actor.offHandDarkWeapon == true && target.darkWeak == true ) ||
			(actor.offHandHolyWeapon == true && target.holyWeak == true ) )
			return damage * 2;
		//target half against elementals
		else if( (actor.offHandFireWeapon == true && target.fireHalf == true ) ||
			(actor.offHandWaterWeapon == true && target.waterHalf == true ) ||
			(actor.offHandIceWeapon == true && target.iceHalf == true ) ||
			(actor.offHandLightningWeapon == true && target.lightningHalf == true ) ||
			(actor.offHandWindWeapon == true && target.windHalf == true ) ||
			(actor.offHandEarthWeapon == true && target.earthHalf == true ) ||
			(actor.offHandDarkWeapon == true && target.darkHalf == true ) ||
			(actor.offHandHolyWeapon == true && target.holyHalf == true ) )
			return damage / 2;
		//target absorb against elementals
		else if( (actor.offHandFireWeapon == true && target.fireAbsorb == true ) ||
			(actor.offHandWaterWeapon == true && target.waterAbsorb == true ) ||
			(actor.offHandIceWeapon == true && target.iceAbsorb == true ) ||
			(actor.offHandLightningWeapon == true && target.lightningAbsorb == true ) ||
			(actor.offHandWindWeapon == true && target.windAbsorb == true ) ||
			(actor.offHandEarthWeapon == true && target.earthAbsorb == true ) ||
			(actor.offHandDarkWeapon == true && target.darkAbsorb == true ) ||
			(actor.offHandHolyWeapon == true && target.holyAbsorb == true ) )
		{
			damage *= -1;
			return damage;
		}
		else return damage;
	}