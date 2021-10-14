//Includes map, wait, player stats menu functions, sex select, welcome

void welcome()
{
	cout << " --- Welcome to the Final Fantasy Tactics mini-game! (Beta Version .75) ---\n" << "\n"
		<<"Currently the game features two teams of two units each. Over time this will\n"
		<<"expand to teams of five. Most classes, abilites, and status effects are in the\n"
		<<"game. See the game website for more details.\n"
		<< "\n"
		<< "If you discover any errors or have any questions or comments, please email me\n"
		<< "at martin.decoud@gmail.com or Skype at martin.decoud.\n" << "\n"
		<< "Check http://costaguanan.blogspot.com for news, updates, and the latest\n"
		<< "version of the game.\n"
		<< "\n";

	cout << "     --- INSTRUCTIONS ---\n"
		<< "\n"
		<< "There are two teams: Red and Blue. Both need to be controlled by player input\n"
		<< "(there is no AI). After each player selects their characters' attributes,\n"
		<< "skills, and equipment the game begins. Select from each menu by entering\n"
		<< "a number and hitting enter.\n"
		<< "\n"
		<< "To play online against a friend, use Skype (free to download) and the \n"
		<< "'Share Screen' feature.\n"
		<< "\n" << "Press Enter to Continue\n";

	string x = "";
	getline(cin, x);
}

//confirmFunction
int confirmFunction( int confirmInput )
{
	while( (cout << "\t" << "CONFIRM:  1.) Yes  2.) No\n" ) &&
		( !(cin>> confirmInput ) || confirmInput < 1 || confirmInput > 2 ))
		{
			cout << "Enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	return confirmInput;
}

int confirmFunctionMenu( int confirmInput )
{
	while( (cout << "\t" << "\t" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n" ) &&
		( !(cin>> confirmInput ) || confirmInput < 1 || confirmInput > 3 ))
		{
			cout << "Enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	return confirmInput;
}

//display status
void displayStatus(Player actor)
{
	int criticalInt;

	if( actor.maxLife % 5 == 0 )
		criticalInt = 0;
	else criticalInt = 1;
	if(actor.life < actor.maxLife / 5 + criticalInt)
	{
		actor.critical = true;
	}
	else actor.critical = false;

	if( actor.poison == false && actor.darkness == false && actor.silence == false &&
		actor.frog == false &&actor.petrify == false && actor.bloodSuck == false &&
		actor.confusion == false && actor.oil == false &&actor.deathSentence == false &&
		actor.berserk == false && actor.dontMove == false &&actor.dontAct== false &&
		actor.stop == false && actor.slow == false && actor.haste == false &&
		actor.charging == false &&actor.defending == false && actor.performing == false &&
		actor.charm == false && actor.statusFloat == false &&actor.protect == false &&
		actor.shell == false && actor.reraise == false && actor.regen == false &&
		actor.transparent == false && actor.chicken == false && actor.morbol == false &&
		actor.undead == false && actor.critical == false && actor.statusFaith == false &&
		actor.invite == false && actor.statusReflect == false && actor.dead == false &&
		actor.innocent == false && actor.sleep == false && actor.quick == false
		)
	{
	}
	else
	{
		
		cout << "   STATUS: ";
		if( actor.reraise == true || actor.accAutoReraise == true )
				cout << "RERAISE, ";
		if( actor.dead == true )
			cout << "DEAD -- " << actor.deadTimer << " --\n";
		else
		{ 
			if( actor.poison == true )
				cout << "POISON, ";
			if( actor.sleep == true )
				cout << "SLEEP, ";
			if( actor.darkness == true )
				cout << "DARKNESS, ";
			if( actor.silence == true )
				cout << "SILENCE, ";
			if( actor.frog == true )
				cout << "FROG, ";
			if( actor.petrify == true )
				cout << "PETRIFY, ";
			if( actor.bloodSuck == true )
				cout << "BLOODSUCK, ";
			if( actor.confusion == true )
				cout << "CONFUSION, ";
			if( actor.oil == true )
				cout << "OIL, ";
			if( actor.deathSentence == true )
				cout << "DEATH SENTENCE " << actor.deathSentenceTimer << ",";
			if( actor.berserk == true )
				cout << "BERSERK, ";
			if( actor.dontMove == true )
				cout << "DONT MOVE, ";
			if( actor.dontAct== true )
				cout << "DONT ACT, ";
			if( actor.stop == true )
				cout << "STOP, ";
			if( actor.slow == true )
				cout << "SLOW, ";
			if( actor.haste == true || actor.accAutoHaste == true || actor.weaponAutoHaste == true || actor.offHandAutoHaste == true )
				cout << "HASTE, ";
			if( actor.innocent == true )
				cout << "INNOCENT, ";
			if( actor.charging == true )
				cout << "CHARGING, ";
			if( actor.defending == true )
				cout << "DEFENDING, ";
			if( actor.performing == true )
				cout << "PERFORMING, ";
			if( actor.charm == true )
				cout << "CHARM, ";
			if( actor.statusFloat == true || actor.accAutoFloat == true )
				cout << "FLOAT, ";
			if( actor.protect == true || actor.weaponAutoProtect == true || actor.offHandAutoProtect == true || actor.accAutoProtect == true
				|| actor.bodyAutoProtect == true )
				cout << "PROTECT, ";
			if( actor.shell == true || actor.accAutoShell == true || actor.weaponAutoShell == true || actor.offHandAutoShell == true 
				|| actor.bodyAutoShell == true )
				cout << "SHELL, ";
			if( actor.regen == true || actor.accAutoRegen == true )
				cout << "REGEN, ";
			if( actor.transparent == true )
				cout << "TRANSPARENT, ";
			if( actor.chicken == true )
				cout << "CHICKEN, ";
			if( actor.morbol == true )
				cout << "MORBOL, ";
			if( actor.undead == true || actor.accAutoUndead == true )
				cout << "UNDEAD, ";
			if( actor.critical == true )
				cout << "CRITICAL, ";
			if( actor.statusFaith == true || actor.weaponAutoFaith == true || actor.offHandAutoFaith == true )
				cout << "FAITH, ";
			if( actor.invite == true )
				cout << "INVITED, ";
			if( actor.quick == true )
				cout << "QUICK, ";
			if( actor.statusReflect == true || actor.accAutoReflect == true || actor.bodyAutoReflect == true )
				cout << "REFLECT"; 
			cout << "\n";
		}
	}
}


// direction function
string direction( int blueDir )
{
	if(blueDir == 1)
	{
		return "NORTH";
	}
	else if(blueDir == 2)
	{
		return "EAST";
	}
	else if(blueDir == 3)
	{
		return "SOUTH";
	}					
	else
	{
		return "WEST";
	}
} 

//wait function
void waitFunction(Player &playerActor)
{
	int faceInt;
	string dirFace;
	while( (cout << "\n" << "   --- "<< playerActor.teamName << " " << playerActor.playerClassName << " " << playerActor.playerName << " --- \n"
		<< "Face which direction?" << " (1 = NORTH, 2 = EAST, 3 = SOUTH, 4 = WEST) \n")
		&&( !(cin>> faceInt) || faceInt < 1 || faceInt > 4 ))
		{
			cout << "Enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	dirFace = direction(faceInt);
	playerActor.facingDir = dirFace;
}

Player ctrTargetDisplay( Player actor, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer )
{
	if( actor.ctrFollowNumber == player1.turnOrder )
	{
		return player1;
	}
	else if( actor.ctrFollowNumber == player2.turnOrder )
	{
		return player2;
	}
	else if( actor.ctrFollowNumber == player3.turnOrder )
	{
		return player3;
	}
	else if( actor.ctrFollowNumber == player4.turnOrder )
	{
		return player4;
	}
	else if( actor.ctrFollowNumber == player5.turnOrder )
	{
		return player5;
	}
	else if( actor.ctrFollowNumber == player6.turnOrder )
	{
		return player6;
	}
	else if( actor.ctrFollowNumber == player7.turnOrder )
	{
		return player7;
	}
	else if( actor.ctrFollowNumber == player8.turnOrder )
	{
		return player8;
	}
	else if( actor.ctrFollowNumber == player9.turnOrder )
	{
		return player9;
	}
	else if( actor.ctrFollowNumber == player10.turnOrder )
	{
		return player10;
	}
	else return nullPlayer;
}

//displays pending resolutions
void ctrDisplay( Player actor, Player player1, Player player2, Player player3, Player player4,
	Player player5, Player player6, Player player7, Player player8, Player player9, Player player10, char myArray[][11],
	Player nullPlayer )
{
	Player target;
	target = ctrTargetDisplay( actor, player1, player2, player3, player4, player5,
		player6, player7, player8, player9, player10, myArray, nullPlayer );

	if( actor.ctrCountdownBool == true && actor.ctrType == 2 )
	{
		cout << "\t" << actor.teamName << " " << actor.playerClassName << " "
			<< actor.playerName << " will cast " << actor.ctrName << " in "
			<< actor.ctrCountdown << " CTR\n";
	}
	else if( actor.ctrCountdownBool == true && actor.ctrType == 5 )
	{
		cout << "\t" << actor.teamName << " " << actor.playerClassName << " "
			<< actor.playerName << " will cast " << actor.ctrName << " in "
			<< actor.ctrCountdown << " CTR\n";
	}
	else if( actor.ctrCountdownBool == true && actor.ctrFollow == 0)
	{
		cout << "\t" << actor.teamName << " " << actor.playerClassName << " "
			<< actor.playerName << " will cast " << actor.ctrName << " on ("
			<< actor.ctrRow - 1 << ", " << actor.ctrCol - 1 << ") in "
			<< actor.ctrCountdown << " CTR\n";
	}
	else if( actor.ctrCountdownBool == true && actor.ctrFollow == 1 )
	{
		cout << "\t" << actor.teamName << " " << actor.playerClassName << " "
			<< actor.playerName << " will cast " << actor.ctrName
			<< " on " << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " in " << actor.ctrCountdown << " CTR\n";
	}
}

//AT function *** setw so this is easier to read?
void activeTurn(Player player1, Player player2,  Player player3, Player player4, Player player5,
	 Player player6, Player player7, Player player8, Player player9, Player player10, char myArray[][11],
	 Player nullPlayer )
{
	cout << '\n';
	cout << "     --- Active Turn Menu ---     " << "\n";
	cout << "\n";
	cout <<"Turn Order -- Player -- Clock Ticks to Resolution (CTR)\n";
	ctrDisplay( player1, player1, player2, player3, player4, player5, player6, player7,
		player8, player9, player10, myArray, nullPlayer );
	ctrDisplay( player2, player1, player2, player3, player4, player5, player6, player7,
		player8, player9, player10, myArray, nullPlayer );
	ctrDisplay( player6, player1, player2, player3, player4, player5, player6, player7,
		player8, player9, player10, myArray, nullPlayer );
	ctrDisplay( player7, player1, player2, player3, player4, player5, player6, player7,
		player8, player9, player10, myArray, nullPlayer );
	int tempCTp1 = player1.ct;
	int tempCTp2 = player2.ct;
	int tempCTp6 = player6.ct;
	int tempCTp7 = player7.ct;
	int atCount = 0; //counts how many active turns have been outputted to user
	int tempATCTR = 0; //shows CTR until various actions resolve
	while(atCount < 10)
	{
		while( tempCTp1 >= 100 || tempCTp2 >= 100 || tempCTp6 >= 100 || tempCTp7 >= 100 )
		{ 
			if( tempCTp1 >= 100 )
			{
				atCount++;
				cout << atCount << ". " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp1 -= 100;
			}
			if( tempCTp1 < 100 && tempCTp6 >= 100 ) 
			{
				atCount++;
				cout << atCount << ". " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp6 -= 100;
			}
			if( tempCTp1 < 100 && tempCTp6 < 100 && tempCTp7 >= 100 ) 
			{
				atCount++;
				cout << atCount << ". " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp7 -= 100;
			}
			if( tempCTp1 < 100 && tempCTp6 < 100 && tempCTp7 < 100 && tempCTp2 >= 100 ) 
			{
				atCount++;
				cout << atCount << ". " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp2 -= 100;
			}
		}
		tempCTp1 += player1.speed;
		tempCTp2 += player2.speed;
		tempCTp6 += player6.speed;
		tempCTp7 += player7.speed;
		tempATCTR += 1;
	}
}

void outputActiveTurn( Player player1, Player player2,  Player player3, Player player4, Player player5,
	 Player player6, Player player7, Player player8, Player player9, Player player10  )
{
	ofstream destination("AT-Menu.txt");
	destination << '\n';
	destination << "     ----- Active Turn Menu -----     " << "\n";
	int tempCTp1 = player1.ct;
	int tempCTp2 = player2.ct;
	int tempCTp6 = player6.ct;
	int tempCTp7 = player7.ct;
	int atCount = 0; //counts how many active turns have been outputted to user
	int tempATCTR = 0; //shows CTR until various actions resolve
	while(atCount < 10)
	{
		while( tempCTp1 >= 100 || tempCTp2 >= 100 || tempCTp6 >= 100 || tempCTp7 >= 100 )
		{ 
			if( tempCTp1 >= 100 )
			{
				atCount++;
				destination << atCount << ". " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp1 -= 100;
			}
			if( tempCTp1 < 100 && tempCTp6 >= 100 ) 
			{
				atCount++;
				destination << atCount << ". " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp6 -= 100;
			}
			if( tempCTp1 < 100 && tempCTp6 < 100 && tempCTp7 >= 100 ) 
			{
				atCount++;
				destination << atCount << ". " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp7 -= 100;
			}
			if( tempCTp1 < 100 && tempCTp6 < 100 && tempCTp7 < 100 && tempCTp2 >= 100 ) 
			{
				atCount++;
				destination << atCount << ". " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName << " -- CTR: " << tempATCTR << "\n";
				tempCTp2 -= 100;
			}
		}
		tempCTp1 += player1.speed;
		tempCTp2 += player2.speed;
		tempCTp6 += player6.speed;
		tempCTp7 += player7.speed;
		tempATCTR += 1;
	}
}

void showCTFunction( Player &unit )
{
	unit.showCT = unit.ct;
	if( unit.showCT > 100 )
		unit.showCT = 100;
}
//better under map -- displays info under map for turn function
void turnUnderMap( Player player1, Player player2, Player player3, Player player4, Player player5, Player player6, Player player7,
	Player player8, Player player9, Player player10, Player nullPlayer, char myArray[][11] )
{
	showCTFunction( player1 );
	showCTFunction( player2 );
	showCTFunction( player3 );
	showCTFunction( player4 );

	cout << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
		<< " '" << player1.mapSymbol << "' at (" << player1.currentRow-1 <<", " << player1.currentCol-1 << ") facing " << player1.facingDir
		<< " -- HP: " << player1.life << "/" << player1.maxLife << " MP: " << player1.mp << " -- CT: " << player1.showCT << "\n";
		displayStatus(player1);
	cout << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
		<< " '" << player2.mapSymbol << "' at (" << player2.currentRow-1 <<", " << player2.currentCol-1 << ") facing " << player2.facingDir
		<< " -- HP: " << player2.life << "/" << player2.maxLife << " MP: " << player2.mp << " -- CT: " << player2.showCT << "\n";
		displayStatus(player2);
	cout << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
		<< " '" << player6.mapSymbol << "' at (" << player6.currentRow-1 <<", " << player6.currentCol-1 << ") facing " << player6.facingDir
		<< " -- HP: " << player6.life << "/" << player6.maxLife << " MP: " << player6.mp << " -- CT: " << player6.showCT << "\n";
		displayStatus(player6);
	cout << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
		<< " '" << player7.mapSymbol << "' at (" << player7.currentRow-1 <<", " << player7.currentCol-1 << ") facing " << player7.facingDir
		<< " -- HP: " << player7.life << "/" << player7.maxLife << " MP: " << player7.mp << " -- CT: " << player7.showCT << "\n";
		displayStatus(player7);
		ctrDisplay( player1, player1, player2, player3, player4, player5, player6, player7,
			player8, player9, player10, myArray, nullPlayer );
		ctrDisplay( player2, player1, player2, player3, player4, player5, player6, player7,
			player8, player9, player10, myArray, nullPlayer );
		ctrDisplay( player6, player1, player2, player3, player4, player5, player6, player7,
			player8, player9, player10, myArray, nullPlayer );
		ctrDisplay( player7, player1, player2, player3, player4, player5, player6, player7,
			player8, player9, player10, myArray, nullPlayer );
}


void displayMap( const char myArray[][11], const int turn, const int row, const int col,
	const int clockTick )
{
	cout << "\n   -----   Turn Number: " << turn << "   Clock Tick: " << clockTick <<"   -----\n"
		<< "\n";
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

void outputMap( const char myArray[][11], const int turn, const int row, const int col,
	const int clockTick, Player &player1, Player &player2, Player &player6, Player &player7 )
{
	ofstream destination("map.txt");
	destination << "\n   -----   Turn Number: " << turn << "   Clock Tick: " << clockTick <<"   -----\n";
	int i; int j;
	for( i = 0; i < row; i++ )
	{
		for( j = 0; j < col; j++ )
		{
			destination << myArray[i][j];
		}
	destination << '\n';
	}
	destination << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
		<< " '" << player1.mapSymbol << "' is at (" << player1.currentRow-1 <<", " << player1.currentCol-1 << ") facing " << player1.facingDir
		<< " -- Life: " << player1.life << "/" << player1.maxLife << " -- CT: " << player1.ct << "\n";
	destination << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
		<< " '" << player2.mapSymbol << "' is at (" << player2.currentRow-1 <<", " << player2.currentCol-1 << ") facing " << player2.facingDir
		<< " -- Life: " << player2.life << "/" << player2.maxLife << " -- CT: " << player2.ct << "\n";
	destination << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
		<< " '" << player6.mapSymbol << "' is at (" << player6.currentRow-1 <<", " << player6.currentCol-1 << ") facing " << player6.facingDir
		<< " -- Life: " << player6.life << "/" << player6.maxLife << " -- CT: " << player6.ct << "\n";
	destination << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
		<< " '" << player7.mapSymbol << "' is at (" << player7.currentRow-1 <<", " << player7.currentCol-1 << ") facing " << player7.facingDir
		<< " -- Life: " << player7.life << "/" << player7.maxLife << " -- CT: " << player7.ct << "\n";
}

void outputStats( Player player1, Player player2, Player player6, Player player7 )
{
	ofstream destination("player-stats.txt");
	destination << " --- " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName << " --- Sex: " << player1.sex << "  Map Symbol: " << player1.mapSymbol << "  Zodiac: " << player1.zodiac << "\n"
		<< "\tABILITIES" << setw(35) << "EQUIPMENT\n"
		<< setw(11) << "Primary: " << setw(14) << player1.playerClassName << setw(22) << "Weapon: " << player1.weaponName << "\n"
		<< setw(11) << "Secondary: " << setw(14) << player1.secondary << setw(22) << "Off-Hand: " << player1.offHandName << "\n"
		<< setw(11) << "Reaction: " << setw(14)  << player1.reaction << setw(22) << "Helmet: " << player1.headName << "\n"
		<< setw(11) << "Support: " << setw(14)  << player1.support << setw(22) << "Armor: " << player1.bodyName << "\n"
		<< setw(11) << "Movement: " << setw(14)  << player1.movement << setw(22) << "Accessory: " << player1.accName << "\n"
		<< "\tSTATS\n"
		<< "Life: " << player1.life << "/" << player1.maxLife << setw(10) << "MP: " << player1.mp << "/" << player1.maxMP  << setw(10) << "CT: " << player1.ct << '\n'
		<< "Move: " << player1.move << setw(16) << "Jump: " << player1.jump << setw(15) << "Speed: " << player1.speed << setw(15) << "Level: " << player1.level << '\n'
		<< "Phy Att: " << player1.pa << setw(18) << "Magic Att: " << player1.ma  << setw(15) << "Brave: " << player1.brave  << setw(15) << "Faith: " << player1.faith << '\n'
		<< "Weap Power: " << player1.weaponPower << setw(10) << "Type: "<< player1.weaponType  << setw(20) << "Off-Hand Type: " << player1.offHandType << '\n'
		<< "Class Ev: " << player1.cEvade << setw(13) << "Wp-Ev: " << player1.weaponEvade  << setw(25) << "Shield P-Ev: " << player1.offHandPhyEvade << '\n'
		<< "Shield M-Ev: " << player1.offHandMagEvade  << setw(13) << "Acc P-Ev: " << player1.accPhyEvade << setw(20) << "Acc M-Ev: " << player1.accMagEvade << "\n"
		<< "Quick Start Code: " << player1.quickCode
		<< '\n' << "\n";

	destination << " --- " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName << " --- Sex: " << player2.sex << "  Map Symbol: " << player2.mapSymbol << "  Zodiac: " << player2.zodiac << "\n"
		<< "\tABILITIES" << setw(35) << "EQUIPMENT\n"
		<< setw(11) << "Primary: " << setw(14) << player2.playerClassName << setw(22) << "Weapon: " << player2.weaponName << "\n"
		<< setw(11) << "Secondary: " << setw(14) << player2.secondary << setw(22) << "Off-Hand: " << player2.offHandName << "\n"
		<< setw(11) << "Reaction: " << setw(14)  << player2.reaction << setw(22) << "Helmet: " << player2.headName << "\n"
		<< setw(11) << "Support: " << setw(14)  << player2.support << setw(22) << "Armor: " << player2.bodyName << "\n"
		<< setw(11) << "Movement: " << setw(14)  << player2.movement << setw(22) << "Accessory: " << player2.accName << "\n"
		<< "\tSTATS\n"
		<< "Life: " << player2.life << "/" << player2.maxLife << setw(10) << "MP: " << player2.mp << "/" << player2.maxMP  << setw(10) << "CT: " << player2.ct << '\n'
		<< "Move: " << player2.move << setw(16) << "Jump: " << player2.jump << setw(15) << "Speed: " << player2.speed << setw(15) << "Level: " << player2.level << '\n'
		<< "Phy Att: " << player2.pa << setw(18) << "Magic Att: " << player2.ma  << setw(15) << "Brave: " << player2.brave  << setw(15) << "Faith: " << player2.faith << '\n'
		<< "Weap Power: " << player2.weaponPower << setw(10) << "Type: "<< player2.weaponType  << setw(20) << "Off-Hand Type: " << player2.offHandType << '\n'
		<< "Class Ev: " << player2.cEvade << setw(13) << "Wp-Ev: " << player2.weaponEvade  << setw(25) << "Shield P-Ev: " << player2.offHandPhyEvade << '\n'
		<< "Shield M-Ev: " << player2.offHandMagEvade  << setw(13) << "Acc P-Ev: " << player2.accPhyEvade << setw(20) << "Acc M-Ev: " << player2.accMagEvade << '\n' 
		<< "Quick Start Code: " << player2.quickCode
		<< '\n' << "\n";

	destination << " --- " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName << " --- Sex: " << player6.sex << "  Map Symbol: " << player6.mapSymbol << "  Zodiac: " << player6.zodiac << "\n"
		<< "\tABILITIES" << setw(35) << "EQUIPMENT\n"
		<< setw(11) << "Primary: " << setw(14) << player6.playerClassName << setw(22) << "Weapon: " << player6.weaponName << "\n"
		<< setw(11) << "Secondary: " << setw(14) << player6.secondary << setw(22) << "Off-Hand: " << player6.offHandName << "\n"
		<< setw(11) << "Reaction: " << setw(14)  << player6.reaction << setw(22) << "Helmet: " << player6.headName << "\n"
		<< setw(11) << "Support: " << setw(14)  << player6.support << setw(22) << "Armor: " << player6.bodyName << "\n"
		<< setw(11) << "Movement: " << setw(14)  << player6.movement << setw(22) << "Accessory: " << player6.accName << "\n"
		<< "\tSTATS\n"
		<< "Life: " << player6.life << "/" << player6.maxLife << setw(10) << "MP: " << player6.mp << "/" << player6.maxMP  << setw(10) << "CT: " << player6.ct << '\n'
		<< "Move: " << player6.move << setw(16) << "Jump: " << player6.jump << setw(15) << "Speed: " << player6.speed << setw(15) << "Level: " << player6.level << '\n'
		<< "Phy Att: " << player6.pa << setw(18) << "Magic Att: " << player6.ma  << setw(15) << "Brave: " << player6.brave  << setw(15) << "Faith: " << player6.faith << '\n'
		<< "Weap Power: " << player6.weaponPower << setw(10) << "Type: "<< player6.weaponType  << setw(20) << "Off-Hand Type: " << player6.offHandType << '\n'
		<< "Class Ev: " << player6.cEvade << setw(13) << "Wp-Ev: " << player6.weaponEvade  << setw(25) << "Shield P-Ev: " << player6.offHandPhyEvade << '\n'
		<< "Shield M-Ev: " << player6.offHandMagEvade  << setw(13) << "Acc P-Ev: " << player6.accPhyEvade << setw(20) << "Acc M-Ev: " << player6.accMagEvade << '\n'
		<< "Quick Start Code: " << player6.quickCode
		<< '\n' << "\n";

	destination << " --- " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName << " --- Sex: " << player7.sex << "  Map Symbol: " << player7.mapSymbol << "  Zodiac: " << player7.zodiac << "\n"
		<< "\tABILITIES" << setw(35) << "EQUIPMENT\n"
		<< setw(11) << "Primary: " << setw(14) << player7.playerClassName << setw(22) << "Weapon: " << player7.weaponName << "\n"
		<< setw(11) << "Secondary: " << setw(14) << player7.secondary << setw(22) << "Off-Hand: " << player7.offHandName << "\n"
		<< setw(11) << "Reaction: " << setw(14)  << player7.reaction << setw(22) << "Helmet: " << player7.headName << "\n"
		<< setw(11) << "Support: " << setw(14)  << player7.support << setw(22) << "Armor: " << player7.bodyName << "\n"
		<< setw(11) << "Movement: " << setw(14)  << player7.movement << setw(22) << "Accessory: " << player7.accName << "\n"
		<< "\tSTATS\n"
		<< "Life: " << player7.life << "/" << player7.maxLife << setw(10) << "MP: " << player7.mp << "/" << player7.maxMP  << setw(10) << "CT: " << player7.ct << '\n'
		<< "Move: " << player7.move << setw(16) << "Jump: " << player7.jump << setw(15) << "Speed: " << player7.speed << setw(15) << "Level: " << player7.level << '\n'
		<< "Phy Att: " << player7.pa << setw(18) << "Magic Att: " << player7.ma  << setw(15) << "Brave: " << player7.brave  << setw(15) << "Faith: " << player7.faith << '\n'
		<< "Weap Power: " << player7.weaponPower << setw(10) << "Type: "<< player7.weaponType  << setw(20) << "Off-Hand Type: " << player7.offHandType << '\n'
		<< "Class Ev: " << player7.cEvade << setw(13) << "Wp-Ev: " << player7.weaponEvade  << setw(25) << "Shield P-Ev: " << player7.offHandPhyEvade << '\n'
		<< "Shield M-Ev: " << player7.offHandMagEvade  << setw(13) << "Acc P-Ev: " << player7.accPhyEvade << setw(20) << "Acc M-Ev: " << player7.accMagEvade << '\n'
		<< "Quick Start Code: " << player7.quickCode
		<< '\n' << "\n";

}

//displays player stats
void statsMenu( Player actor ) 
{ //sex, map symbol
	cout << " --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " --- Sex: " << actor.sex << "  Map Symbol: " << actor.mapSymbol << "  Zodiac: " << actor.zodiac << "\n"
		<< "\tABILITIES" << setw(35) << "EQUIPMENT\n"
		<< setw(11) << "Primary: " << setw(14) << actor.playerClassName << setw(22) << "Weapon: " << actor.weaponName << "\n"
		<< setw(11) << "Secondary: " << setw(14) << actor.secondary << setw(22) << "Off-Hand: " << actor.offHandName << "\n"
		<< setw(11) << "Reaction: " << setw(14)  << actor.reaction << setw(22) << "Helmet: " << actor.headName << "\n"
		<< setw(11) << "Support: " << setw(14)  << actor.support << setw(22) << "Armor: " << actor.bodyName << "\n"
		<< setw(11) << "Movement: " << setw(14)  << actor.movement << setw(22) << "Accessory: " << actor.accName << "\n"
		<< "\tSTATS\n"
		<< "HP:          " << actor.life << "/" << actor.maxLife<< "     MP:        " << actor.mp << "/" << actor.maxMP  << "   CT: " << actor.showCT << '\n'
		<< "Move:        " << actor.move						<< "           Jump:     " << actor.jump  << "        Speed: " << actor.speed  << "     Level: " << actor.level << '\n'
		<< "Phy Att:     " << actor.pa							<< "          Magic Att: " << actor.ma    << "        Brave: " << actor.brave << "     Faith: " << actor.faith << '\n'
		<< "Class Ev:    " << actor.cEvade						<< "          Wp-Ev:     " << actor.weaponEvade   << "        Shield P-Ev: " << actor.offHandPhyEvade << '\n'
		<< "Shield M-Ev: " << actor.offHandMagEvade				<< "           Acc P-Ev: " << actor.accPhyEvade  << "        Acc M-Ev: " << actor.accMagEvade << '\n'
		<< "Weap Power:  " << actor.weaponPower					<< "          Wp Type: "<< actor.weaponType  << "     Off-Hand Type: " << actor.offHandType << '\n';
		
	displayStatus(actor);
	cout << "\n";	
}

//turn move function for turn function, need to fix for more characters and more collision types
int turnMoveFunction( Player &actor, char myArray[][11], Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10, int row = 11, int col = 11 )
{
	int moveRow = 40;
	int moveCol = 40;
	int confirmMove = 2;
	int tempHP = 0;
	int tempMP = 0;
	bool moveError = false;

	int absorbCrystal = 0;

	if( actor.teleport == true )
	{
		do
		{
			cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " is at (" << actor.currentRow - 1 << ", " << actor.currentCol - 1 << ")"
			<< " and can Teleport. Enter coordinates.\n";
			if(confirmMove != 3)
			{
				int teleportChance = 0;
				int teleportRoll = 0;
				do
				{
					while( (cout << "   Which Row?      ") && ( !(cin >> moveRow)
						|| moveRow < 0 || moveRow > 9 ))
					{
						cout << "Enter a valid row\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					moveRow += 1;
					while( (cout << "   Which Column?   ") && ( !(cin >> moveCol)
						|| moveCol < 0 || moveCol > 9 ))
					{
						cout << "Enter a valid column\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}
					moveCol += 1;

					if( myArray[moveRow][moveCol] != 'O' && myArray[moveRow][moveCol] != 'C' )
						cout << "That space is occupied.\n";
				}while(myArray[moveRow][moveCol] != 'O' && myArray[moveRow][moveCol] != 'C' );
	
				while( (cout << "\tCONFIRM Move to (" << moveRow-1 << ", " 
					<< moveCol-1 <<")?  1 = Yes  2 = No  3 = Menu  " ) && ( !(cin >> confirmMove)
					|| confirmMove < 1 || confirmMove > 3 ) )
				{
					cout << "Enter a valid number\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if( confirmMove == 1 )
				{
					teleportChance = 100 - 10 * ( abs(actor.currentRow - moveRow)
						+ abs(actor.currentCol - moveCol) - actor.move );
					teleportRoll = rand() % 100 / 1;
					cout << "Teleport chance to succeed is... " << teleportChance << "\n";
					cout << "\tRandom Number is... " << teleportRoll << "\n";
					if( teleportRoll > teleportChance ) //teleport fails
					{
						cout << "\tTeleport fails!\n";
						moveRow = actor.currentRow;
						moveCol = actor.currentCol;
					}
					else
					{
						cout << "\tTeleport Succeeds!\n"; 
					}
				}
				else if(confirmMove == 2)
				{
					moveRow = 40;
					moveCol = 40;
				}
				else if(confirmMove == 3 )
				{ 
					moveRow = 40;
					moveCol = 40;
				}
			}
		}while(confirmMove == 2 );
	}
	else if( actor.teleport == false )
	{
		cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
			<< " is at (" << actor.currentRow - 1 << ", " << actor.currentCol - 1 << ")"	
			<< " and can move up to " << actor.move << " spaces.\n";
		do
		{
			moveError = false;

			if(confirmMove == 3)
			{
				break;
			}
			while( (cout << "   Which Row?      ") && ( !(cin >> moveRow)
				|| moveRow < 0 || moveRow > 9 ))
			{
				cout << "Enter a valid row\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			moveRow += 1;
			while( (cout << "   Which Column?   ") && ( !(cin >> moveCol)
				|| moveCol < 0 || moveCol > 9 ))
			{
				cout << "Enter a valid column\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			moveCol += 1;

			if ( moveRow == actor.currentRow && moveCol == actor.currentCol )
			{
				confirmMove = 3;
				break;
			}
			else if ((abs(moveRow-actor.currentRow)+abs(moveCol-actor.currentCol)) > actor.move)
			{ //player tried to move too far
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName 
					<< " cannot move that far.\n"
					<< actor.teamName << " " << actor.playerClassName << " " << actor.playerName 
					<< " is at (" << actor.currentRow - 1 << ", " << actor.currentCol - 1<< ")"
					<< " and can move up to " << actor.move << " spaces.\n";
				moveRow = 40;
				moveCol = 40;
				moveError = true;
			}
			else if ( myArray[moveRow][moveCol] != 'O' && myArray[moveRow][moveCol] != 'C' )
			{ //player tried to move to occupied space
				moveRow = 40;
				moveCol = 40;
				cout << "Invalid move, space is occupied.\n"
				<< "Where do you want to move to?\n";
				moveError = true;
			}
			//fly ignores collision
			if( actor.fly == false && moveError == false )
			{
				moveError = moveEligible( moveRow, moveCol, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10 );
			}
			if( moveError == false )
			{
				while( (cout << "\tCONFIRM Move to (" << moveRow-1 << ", " 
				<< moveCol-1 <<")?  1 = Yes  2 = No  3 = Menu  " ) && ( !(cin >> confirmMove)
				|| confirmMove < 1 || confirmMove > 3 ) )
				{
					cout << "Enter a valid number\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
				if(confirmMove == 2)
				{
					moveRow = 40;
					moveCol = 40;
				}
				if(confirmMove == 3 )
				{ 
					moveRow = 40;
					moveCol = 40;
					break;
				}
			}
		}while( confirmMove == 2 );
	}
	
	if(confirmMove == 1)
	{
		//ask if player wants to absorb Crystal
		if( myArray[moveRow][moveCol] == 'C' )
		{
			cout << "\tAbsorb Crystal and restore HP & MP to full?\n";
			absorbCrystal = confirmFunction( absorbCrystal );
			if( absorbCrystal == 1 )
			{
				actor.life = actor.maxLife;
				actor.mp = actor.maxMP;
			}
		}
		//updated player position
		myArray[actor.currentRow][actor.currentCol] = 'O';
		actor.currentRow = moveRow;
		actor.currentCol = moveCol;
		myArray[actor.currentRow][actor.currentCol] = actor.mapSymbol;

		
		if( actor.moveHP == true )
		{
			if( actor.berserk == false && actor.confusion == false && actor.bloodSuck == false)
			{
				actor.life += actor.maxLife / 10 + 1;
				tempHP = actor.maxLife / 10 + 1;
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " gains " << tempHP << " HP from Move-HP Up.\n";
				if( actor.life > actor.maxLife )
				{
					actor.life = actor.maxLife;
				}
			}
		}
		else if( actor.moveMP == true )
		{
			if( actor.berserk == false && actor.confusion == false && actor.bloodSuck == false)
			{
				actor.mp += actor.maxMP / 10 + 1;
				tempMP = actor.maxMP / 10 + 1;
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " gains " << tempMP << " MP from Move-MP Up.\n";
				if( actor.mp > actor.maxMP )
				{
					actor.mp = actor.maxMP;
				}
			}
		}
	}
	else if( confirmMove == 3 )
	{
		confirmMove = 2;
		return confirmMove;
	}
	return 0; //this should never trigger
}


void statusSetter( Player &target, string statusString )
{
	// ideal way this works: all status inflictions run through here and output message
		//originates from here
		// one exception is dead from HP damage funciton, in which case the message comes
		// out of the HP damage function
	// Dead for HP damage, Death Type for the status effect Dead
	bool statusBlock = false;
	bool statusCancel = false;
	int demiCheck = 0;


	//HP damage for dead
	if( statusString == "Dead" )
	{
		target.dead = true;

		target.life = 0;
		target.deadTimer = 3;
		target.berserk = false;
		target.bloodSuck = false;
		target.charm = false;
		target.confusion = false;
		target.charging = false;
		target.archerCharging = false;
		target.critical = false;
		target.deathSentence = false;
		target.deathSentenceTimer = 0;
		target.ctrCountdownBool = false;
		target.defending = false;
		target.dontAct = false;
		target.dontMove = false;
		target.statusFaith = false;
		target.statusFloat = false;
		target.haste = false;
		target.innocent = false;
		target.performing = false;
		target.poison = false;
		target.protect = false;
		target.statusReflect = false;
		target.regen = false;
		target.shell = false;
		target.slow = false;
		target.stop = false;
		target.transparent = false;
	}


	//beneficial status types

	if( statusString == "Esuna" )
	{
		target.petrify = false;
		target.darkness = false;
		target.confusion = false;
		target.silence = false;
		target.berserk = false;
		target.frog = false;
		target.poison = false;
		target.sleep = false;
		target.dontAct = false;
		target.dontMove = false;
	}
	if( statusString == "Float" )
	{
		target.statusFloat = true;
		statusBlock = false;
	}
	if( statusString == "Haste" )
	{
		target.haste = true;
		target.hasteTimer = 32;
		target.slow = false;
		target.slowTimer = 0;
		statusBlock = false;
	}
	if( statusString == "Protect")
	{
		target.protect = true;
		target.protectTimer = 32;
		statusBlock = false;
	}
	if( statusString == "Raise 2")
	{
		if( target.undead == false )
		{
			target.dead = false;
			target.life = target.maxLife;
		}
		else if( target.undead == true )
		{
			statusSetter( target, "Dead" );			
		}
		statusBlock = false;
	}
	if( statusString == "Raise")
	{
		if( target.undead == false )
		{
			target.dead = false;
			target.life = target.maxLife / 2 + target.maxLife % 2;
		}
		else if( target.undead == true )
		{
			target.life -= target.maxLife /2 - target.maxLife % 2;
			if( target.life <= 0 )
				statusSetter( target, "Dead");
		}
		statusBlock = false;
	}
	if( statusString == "Regen")
	{
		target.regen = true;
		target.regenTimer = 36;
		target.poison = false;
		target.poisonTimer = 0;
		statusBlock = false;
	}
	if( statusString == "Reraise" )
	{
		if( target.undead == false )
		{
			target.reraise = true;
			statusBlock = false;
		}
		else if( target.undead == true )
		{
			target.reraise = false;
			statusBlock = true;
		}
	}
	if( statusString == "Shell")
	{
		target.shell = true;
		target.shellTimer = 32;
		statusBlock = false;
	}
	if( statusString == "Wall")
	{
		target.protect = true;
		target.protectTimer = 32;
		target.shell = true;
		target.shellTimer = 32;
		statusBlock = false;
	}
	if( statusString == "Transparent")
	{
		target.transparent = true;
		statusBlock = false;
	}


	//harmful status effect types
	if( statusString == "Berserk" )
	{
		if( target.headBerserkBlock == true || target.accBerserkBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.berserk = true;

			target.performing = false;
			target.archerCharging = false;
			target.defending = false;
			target.ctrCountdownBool = false;
			target.ctrCountdown = 0;
			target.ctrEffect = 0;
			target.ctrFollowNumber = 0;
			target.ctrInput = 0;
			target.ctrType = 0;
			target.ctrK = 0;
			target.ctrName = "";
			statusBlock = false;
		}
	}
	if( statusString == "Blood Suck" )
	{
		if( target.headBloodSuckBlock == true || target.accBloodSuckBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.bloodSuck = true;

			target.performing = false;
			target.archerCharging = false;
			target.defending = false;
			target.ctrCountdownBool = false;
			target.ctrCountdown = 0;
			target.ctrEffect = 0;
			target.ctrFollowNumber = 0;
			target.ctrInput = 0;
			target.ctrType = 0;
			target.ctrK = 0;
			target.ctrName = "";
			statusBlock = false;
		}
	}
	if( statusString == "Charm")
	{
		if( target.headCharmBlock == true || target.accCharmBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.charm = true;
			target.charmTimer = 32;
		}
	}
	if( statusString == "Chicken" )
	{
		if( target.brave < 10 )
		{
			target.chicken = true;

			target.performing = false;
			target.archerCharging = false;
			target.defending = false;
			target.ctrCountdownBool = false;
			target.ctrCountdown = 0;
			target.ctrEffect = 0;
			target.ctrFollowNumber = 0;
			target.ctrInput = 0;
			target.ctrType = 0;
			target.ctrK = 0;
			target.ctrName = "";
		}
		else statusBlock = false;
	}
	if( statusString == "Confusion" )
	{
		if( target.headConfusionBlock == true || target.accConfusionBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.confusion = true;

			target.performing = false;
			target.archerCharging = false;
			target.defending = false;
			target.ctrCountdownBool = false;
			target.ctrCountdown = 0;
			target.ctrEffect = 0;
			target.ctrFollowNumber = 0;
			target.ctrInput = 0;
			target.ctrType = 0;
			target.ctrK = 0;
			target.ctrName = "";
		}
	}
	if( statusString == "Darkness" )
	{
		if( target.headDarknessBlock == true || target.accDarknessBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.darkness = true;
			statusBlock = false;
		}
	}
	if( statusString == "Death Sentence" )
	{
		if( target.headDeathSentenceBlock == true || target.accDeathSentenceBlock == true
			|| target.deathSentence == true )
		{
			statusBlock = true;
		}
		else
		{
			target.deathSentence = true;
			target.deathSentenceTimer = 3;
		}
	}
	if( statusString == "Death Type" )
	{
		statusString = "Death";
		if( target.headDeadBlock == true || target.accDarknessBlock == true ||
			target.bodyDeadBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.dead = true;
			target.life = 0;
			target.deadTimer = 3;
			target.berserk = false;
			target.bloodSuck = false;
			target.charm = false;
			target.confusion = false;
			target.charging = false;
			target.archerCharging = false;
			target.critical = false;
			target.deathSentence = false;
			target.deathSentenceTimer = 0;
			target.ctrCountdownBool = false;
			target.defending = false;
			target.dontAct = false;
			target.dontMove = false;
			target.statusFaith = false;
			target.statusFloat = false;
			target.haste = false;
			target.innocent = false;
			target.performing = false;
			target.poison = false;
			target.protect = false;
			target.statusReflect = false;
			target.regen = false;
			target.shell = false;
			target.slow = false;
			target.stop = false;
			target.transparent = false;
			statusBlock = false;
		}
	}
	if( statusString == "Demi")
	{
		if( demiCheck % 4 != 0 )
			demiCheck = 1;
		target.life -= target.maxLife / 4 + demiCheck;
		if( target.life <= 0 )
			statusSetter( target, "Dead" );
	}
	if( statusString == "Demi 2")
	{
		target.life -= target.maxLife / 2 + target.maxLife % 2;
		if( target.life <= 0 )
			statusSetter( target, "Dead" );
	}
	if( statusString == "Don't Act")
	{
		if( target.headDontActBlock == true || target.accDontActBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.dontAct = true;
			target.dontActTimer = 24;
		}
	}
	if( statusString == "Dispel Magic")
	{
		target.protect = false;
		target.shell = false;
		target.haste = false;
		target.statusFloat = false;
		target.regen = false;
		target.reraise = false;
		target.transparent = false;
		target.statusFaith = false;
		target.statusReflect = false;
	}
	if( statusString == "Don't Move")
	{
		if( target.headDontMoveBlock == true || target.accDontActBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.dontMove = true;
			target.dontMoveTimer = 24;
		}
	}
	if( statusString == "Faith")
	{
		target.statusFaith = true;
		target.statusFaithTimer = 32;
		target.innocent = false;
		target.innocentTimer = 0;
	}
	if( statusString == "Frog" )
	{
		if( target.headFrogBlock == true || target.accFrogBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			if( target.frog == true )
				target.frog = false;
			else if( target.frog == false )
				target.frog = true;
		
			target.performing = false;
			target.defending = false;
			target.archerCharging = false;
			target.ctrCountdownBool = false;
			target.ctrCountdown = 0;
			target.ctrEffect = 0;
			target.ctrFollowNumber = 0;
			target.ctrInput = 0;
			target.ctrType = 0;
			target.ctrK = 0;
			target.ctrName = "";
		}
	}
	if( statusString == "Foxbird")
	{
		target.brave -= 30;
		if( target.brave < 1)
			target.brave = 1;
		if( target.brave < 10 )
			statusSetter( target, "Chicken" );
	}

	if( statusString == "Innocent")
	{
		target.innocent = true;
		target.innocentTimer = 32;
		target.statusFaith = false;
		target.statusFaithTimer = 0;
	}
	if( statusString == "Invite Blue" )
	{
		if( target.invite == true || target.headInviteBlock == true || target.accInviteBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.invite = true;
			target.teamName = "Blue";
		}
	}
	if( statusString == "Invite Red" )
	{
		if( target.invite == true || target.headInviteBlock == true || target.accInviteBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.invite = true;
			target.teamName = "Red";
		}
	}
	if( statusString == "Petrify" )
	{
		if(target.headPetrifyBlock == true || target.accPetrifyBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.petrify = true;
		}
	}
	if( statusString == "Poison")
	{
		if( target.accAutoRegen == true || target.weaponAutoRegen == true ||
			target.offHandAutoRegen == true || target.headPoisonBlock == true
			|| target.accPoisonBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.poison = true;
			target.poisonTimer = 36;
			target.regen = false;
			target.regenTimer = 0;
		}
	}
	if( statusString == "Quick")
	{
		target.quick = true;
		target.ct = 100;
	}
	if( statusString == "Reflect" )
	{
		target.statusReflect = true;
		target.statusReflectTimer = 32;
	}
	if( statusString == "Silence" )
	{
		if( target.headSilenceBlock == true || target.accSilenceBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.silence = true;
		}
	}
	if( statusString == "Sleep")
	{
		if( target.headSleepBlock == true || target.accSleepBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.sleep = true;
			target.sleepTimer = 60;

			target.performing = false;
			target.archerCharging = false;
			target.defending = false;
			target.ctrCountdownBool = false;
			target.ctrCountdown = 0;
			target.ctrEffect = 0;
			target.ctrFollowNumber = 0;
			target.ctrInput = 0;
			target.ctrType = 0;
			target.ctrK = 0;
			target.ctrName = "";
		}
	}
	if( statusString == "Slow")
	{
		if( target.accAutoHaste == true || target.offHandAutoHaste == true || target.weaponAutoHaste == true
			|| target.headSlowBlock == true || target.accSlowBlock == true
			)
		{
			statusBlock = true;
		}
		else
		{
			target.slow = true;
			target.slowTimer = 24;
			target.haste = false;
			target.hasteTimer = 0;
		}
	}
	if( statusString == "Stop")
	{
		if( target.headStopBlock == true || target.bodyStopBlock == true ||
			target.accStopBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.stop = true;
			target.stopTimer = 20;
		}
	}
	if( statusString == "Undead")
	{
		if( target.headUndeadBlock == true || target.accUndeadBlock == true )
		{
			statusBlock = true;
		}
		else
		{
			target.undead = true;
		}
	}
	
	//Talk Skill statuses not shown above
	if( statusString == "Persuade")
	{
		target.ct = 0;
	}
	if( statusString == "Praise")
	{
		target.brave += 4;
		if( target.brave >= 100 )
			target.brave = 100;
	}
	if( statusString == "Threaten")
	{
		target.brave -= 20;
		if( target.brave < 0 )
			target.brave = 1;
		if( target.brave < 10 )
			target.chicken = true;
	}
	if( statusString == "Preach")
	{
		target.faith += 4;
		if( target.faith >= 100 )
			target.faith = 100;
	}
	if( statusString == "Solution")
	{
		target.faith -= 20;
		if( target.faith < 0 )
			target.faith = 1;
	}

	
	//cancel status effects from weapon hits
	if( statusString == "Cancel Death Sentence" )
	{
		statusCancel = true;
		if( target.deathSentence == true )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " is cured of Death Sentence!\n";
		}
	}
	if( statusString == "Cancel Darkness" )
	{
		statusCancel = true;
		if( target.darkness == true || target.silence == true || target.silence == true || target.oil == true
			|| target.frog == true || target.poison == true || target.stop == true || target.slow == true
			|| target.dontAct == true || target.dontMove == true )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " is cured!\n";
		}
	}
	
	if( statusCancel == false )
	{
		if( statusString != "Dead" )
		{
			if( statusBlock == true )
			{
				cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " blocks " << statusString <<"!\n";
			}
			else if( statusBlock == false )
			{
				cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " is hit with " << statusString <<"!\n";
			}
		}
	}

}

//used for mod6 attacks with special effects


string statusAttackChecker( Player actor, bool mainHand = true )
{
	string statusName = "";

	if( mainHand == true )
	{
		if( actor.weaponCharm == true )
		{
			statusName = "Charm";
			return statusName;
		}
		if( actor.weaponConfusion == true )
		{
			statusName = "Confusion";
			return statusName;
		}
		if( actor.weaponDarkness == true )
		{
			statusName = "Darkness";
			return statusName;
		}
		if( actor.weaponDeathSentence == true )
		{
			statusName = "Death Sentence";
			return statusName;
		}
		if( actor.weaponDontAct == true )
		{
			statusName = "Don't Act";
			return statusName;
		}
		if( actor.weaponDontMove == true )
		{
			statusName = "Don't Move";
			return statusName;
		}
		if( actor.weaponFaith == true )
		{
			statusName = "Faith";
			return statusName;
		}
		if( actor.weaponFrog == true )
		{
			statusName = "Frog";
			return statusName;
		}
		if( actor.weaponInnocent == true )
		{
			statusName = "Innocent";
			return statusName;
		}
		if( actor.weaponPetrify == true )
		{
			statusName = "Petrify";
			return statusName;
		}
		if( actor.weaponPoison == true )
		{
			statusName = "Poison";
			return statusName;
		}
		if( actor.weaponSilence == true )
		{
			statusName = "Silence";
			return statusName;
		}
		if( actor.weaponSleep == true )
		{
			statusName = "Sleep";
			return statusName;
		}
		if( actor.weaponSlow == true )
		{
			statusName = "Slow";
			return statusName;
		}
		if( actor.weaponCancelDeathSentence == true )
		{
			statusName = "Cancel Death Sentence";
			return statusName;
		}
		if( actor.weaponCancelDarkness == true )
		{
			statusName = "Cancel Darkness";
			return statusName;
		}
	}
	else if( mainHand == false )
	{
		if( actor.offHandCharm == true )
		{
			statusName = "Charm";
			return statusName;
		}
		if( actor.offHandConfusion == true )
		{
			statusName = "Confusion";
			return statusName;
		}
		if( actor.offHandDarkness == true )
		{
			statusName = "Darkness";
			return statusName;
		}
		if( actor.offHandDeathSentence == true )
		{
			statusName = "Death Sentence";
			return statusName;
		}
		if( actor.offHandDontAct == true )
		{
			statusName = "Don't Act";
			return statusName;
		}
		if( actor.offHandDontMove == true )
		{
			statusName = "Don't Move";
			return statusName;
		}
		if( actor.offHandFaith == true )
		{
			statusName = "Faith";
			return statusName;
		}
		if( actor.offHandFrog == true )
		{
			statusName = "Frog";
			return statusName;
		}
		if( actor.offHandInnocent == true )
		{
			statusName = "Innocent";
			return statusName;
		}
		if( actor.offHandPetrify == true )
		{
			statusName = "Petrify";
			return statusName;
		}
		if( actor.offHandPoison == true )
		{
			statusName = "Poison";
			return statusName;
		}
		if( actor.offHandSilence == true )
		{
			statusName = "Silence";
			return statusName;
		}
		if( actor.offHandSleep == true )
		{
			statusName = "Sleep";
			return statusName;
		}
		if( actor.offHandSlow == true )
		{
			statusName = "Slow";
			return statusName;
		}
		if( actor.offHandCancelDeathSentence == true )
		{
			statusName = "Cancel Death Sentence";
			return statusName;
		}
		if( actor.offHandCancelDarkness == true )
		{
			statusName = "Cancel Darkness";
			return statusName;
		}
	}
	cout << "\nBETA MESSAGE: error no status identified.\n";
	return statusName;
}

int loopTarget( int effect, bool casterImmune = false )
{
	if( effect == 1)
		return 1;
	else if( effect == 2 && casterImmune == false )
		return 5;
	else if( effect == 2 && casterImmune == true )
		return 4;
	else if( effect == 3 && casterImmune == false )
		return 13;
	else if( effect == 3 && casterImmune == true )
		return 12;
	else if( effect == 4 )
		return 25;
	else if( effect == 8 )
		return 8;
	else return 1;
}

void ctTickInner( Player &unit ) 
{
	int tempSpeed = 0;
	unit.showCT = unit.ct;

	if( unit.petrify == false && unit.sleep == false && unit.stop == false && unit.activePlayer == true )
	{
		if( unit.slow == true )
		{
			tempSpeed = unit.speed / 2;
			unit.ct += tempSpeed;
			unit.showCT = unit.ct;
		}
		else if( ( unit.haste == true || unit.accAutoHaste == true || unit.weaponAutoHaste == true
			|| unit.offHandAutoHaste == true ) )
		{
			tempSpeed = unit.speed * 3 / 2;
			unit.ct += tempSpeed;
			unit.showCT = unit.ct;
		}
		else
		{
			unit.ct += unit.speed;
			unit.showCT = unit.ct;
		}

		unit.showCT = unit.ct;
		if( unit.showCT > 100 )
		{
			unit.showCT = 100;
		}
	} //end unit
}

//if i get errors with this, set some sort of toggle in the main loop that tiggers this every time we go past CT function and nothing happens
void ctTickOuter( int &clockTick, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10 )
{
	int tempSpeed = 0;
	if( 
		( player1.ct < 100 || ( player1.ct >= 100 && ( player1.petrify == true || player1.stop == true || player1.sleep == true ) ) )
		&& ( player2.ct < 100 || ( player2.ct >= 100 && ( player2.petrify == true || player2.stop == true || player2.sleep == true ) ) )
		&& ( player3.ct < 100 || ( player3.ct >= 100 && ( player3.petrify == true || player3.stop == true || player3.sleep == true ) ) )
		&& ( player4.ct < 100 || ( player4.ct >= 100 && ( player4.petrify == true || player4.stop == true || player4.sleep == true ) ) )
		&& ( player5.ct < 100 || ( player5.ct >= 100 && ( player5.petrify == true || player5.stop == true || player5.sleep == true ) ) )
		&& ( player6.ct < 100 || ( player6.ct >= 100 && ( player6.petrify == true || player6.stop == true || player6.sleep == true ) ) )
		&& ( player7.ct < 100 || ( player7.ct >= 100 && ( player7.petrify == true || player7.stop == true || player7.sleep == true ) ) )
		&& ( player8.ct < 100 || ( player8.ct >= 100 && ( player8.petrify == true || player8.stop == true || player8.sleep == true ) ) )
		&& ( player9.ct < 100 || ( player9.ct >= 100 && ( player9.petrify == true || player9.stop == true || player9.sleep == true ) ) )
		&& ( player10.ct < 100 || ( player10.ct >= 100 && ( player10.petrify == true || player10.stop == true || player10.sleep == true ) ) )
	)
	{
		++clockTick; 
		ctTickInner( player1 );
		ctTickInner( player6 );
		ctTickInner( player7 );
		ctTickInner( player2 );
		ctTickInner( player3 );
		ctTickInner( player8 );
		ctTickInner( player9 );
		ctTickInner( player4 );
		ctTickInner( player5 );
		ctTickInner( player10 );
	}//end ct incrementor
}

void confusionOff( Player &unit )
{
	if(unit.confusion == true )
	{
		unit.confusion = false;
		cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
			<< " is cured from Confusion!\n";
	}
	if(unit.sleep == true )
	{
		unit.sleep = false;
		cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
			<< " is cured from Sleep!\n";
	}
	if(unit.charm == true )
	{
		unit.charm = false;
		cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
			<< " is cured from Charm!\n";
	}
	if(unit.transparent == true )
	{
		unit.transparent = false;
		cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
			<< " loses Transparent!\n";
	}
}

void regenFunction( Player &unit)
{
	int tempRegen = 0;

	if( unit.dead == false && unit.petrify == false )
	{
		if( unit.regen == true || unit.accAutoRegen == true || unit.weaponAutoRegen == true || unit.offHandAutoRegen == true )
		{
			tempRegen = unit.maxLife / 8;
			unit.life += tempRegen;
			if( unit.life > unit.maxLife )
				unit.life = unit.maxLife;
			cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
				<< " gains " << tempRegen << " HP from Regen!\n";
		}
	}
}

void poisonFunction( Player &unit)
{
	int tempPoison = 0;
	if( unit.dead == false && unit.petrify == false )
	{
		if( unit.poison == true )
		{
			tempPoison = unit.maxLife / 8;
			unit.life -= tempPoison;
			confusionOff( unit );

			if( unit.life < 0 )
			{
				unit.life = 0;
				cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
					<< " lose " << tempPoison << " HP from Poison and dies!\n";
				statusSetter( unit, "Dead" );
			}
			else
			{
				cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
					<< " loses " << tempPoison << " HP from Poison!\n";
			}
		}
	}
}


void deathSentenceFunction( Player &unit )
{
	string ctrPause = "";
	if( unit.deathSentence == true )
		{
			unit.deathSentenceTimer -= 1;
			if ( unit.deathSentenceTimer == 0 )
			{
				if( unit.accDeadBlock == true || unit.bodyDeadBlock == true || unit.headDeadBlock == true ||
					unit.undead == true )
				{
					cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
						<< " blocks Death Sentence!\n";
				}
				else
				{
					cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
						<< " dies from Death Sentence!\n";
					statusSetter( unit, "Death Type" );
				}
				cout << "\n";
				cout << "Enter 1 to continue.\n";
				cin >> ctrPause;
			}
		}
}


void deadFunction( Player &unit, char myArray[][11] )
{
	int tempInt = 0;
	int deadRoll = 0;

	if( unit.dead == true && ( unit.reraise == true || unit.accAutoReraise == true ) )
	{
		unit.dead = false;
		unit.reraise = false;
		unit.accAutoReraise = false;
		if( tempInt % 10 == 0 )
			tempInt = 0;
		else tempInt = 1;
		unit.life = unit.maxLife/10 + tempInt;
		cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
			<< " is brought to life from Reraise!\n";		
	}
	else if( unit.dead == true )
		{
			unit.ct -= 100;
			unit.deadTimer -= 1;
			if ( unit.deadTimer <= -1 )
			{
				deadRoll = rand() % 2;
				if( deadRoll == 0 )
				{
					if( unit.undead == false )
					{
						cout << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
							<<"'s body turns to dust!\n";
						myArray[unit.currentRow][unit.currentCol] = 'O';
						unit.activePlayer = false;
						unit.ct = 0;
						unit.speed = 0;
						unit.deadTimer = 0;
					}
					if( unit.undead == true )
					{
						cout << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
							<<"'s is restored to life! Zombie Power!\n";
						unit.dead = false;
						unit.life += rand() % unit.maxLife + 1;
					}
				}
				else if( deadRoll == 1 )
				{
					cout << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
						<<"'s body turns into a Crystal!\n";
					unit.crystal = true;
					unit.activePlayer = false;
					unit.ct = 0;
					unit.speed = 0;
					myArray[unit.currentRow][unit.currentCol] = 'C';
					unit.deadTimer = 0;
				}
			}
		}
}




//turn move function for turn function, need to fix for more characters and more collision types
int chickenMove( Player &actor, char myArray[][11], Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10, int row = 11, int col = 11 )
{
	int moveRow = 40;
	int moveCol = 40;
	int confirmMove = 0;
	int tempHP = 0;
	int tempMP = 0;
	int i = 0;
	string ctrPause = "";

	cout << '\n' << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " is a Chicken and flees!\n";

	if( actor.currentCol > 6 ) //flees east then south
	{
		for( i = 0; i < actor.move + 1 ; i++ )
		{
			moveRow = actor.currentRow + i;
			moveCol = actor.currentCol + actor.move - i;
			if( moveCol > 11 )
				moveCol = 11;
			if( moveRow > 11 )
				moveRow = 11;
			if( myArray[moveRow][moveCol] == 'O' )
			{
				confirmMove = 1;
				break;
			}
		}
	}
	else if( actor.currentRow < 5 ) //flees west then north
	{
		for( i = 0; i < actor.move + 1 ; i++ )
		{
			moveRow = actor.currentRow - i;
			moveCol = actor.currentCol - actor.move + i;
			if( moveCol < 2 )
				moveCol = 2;
			if( moveRow < 2 )
				moveRow = 2;
			if( myArray[moveRow][moveCol] == 'O' )
			{
				confirmMove = 1;
				break;
			}
		}
	}
	
	if( myArray[moveRow][moveCol] == 'O' )
	{
		//updated player position
		myArray[actor.currentRow][actor.currentCol] = 'O';
		actor.currentRow = moveRow;
		actor.currentCol = moveCol;
		myArray[actor.currentRow][actor.currentCol] = actor.mapSymbol;
		if( actor.moveHP == true )
		{
			if( actor.berserk == false && actor.confusion == false && actor.bloodSuck == false)
			{
				actor.life += actor.maxLife / 10 + 1;
				tempHP = actor.maxLife / 10 + 1;
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " gains " << tempHP << " life.\n";
				if( actor.life > actor.maxLife )
				{
					actor.life = actor.maxLife;
				}
			}
		}
		else if( actor.moveMP == true )
		{
			if( actor.berserk == false && actor.confusion == false && actor.bloodSuck == false)
			{
				actor.mp += actor.maxMP / 10 + 1;
				tempMP = actor.maxMP / 10 + 1;
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " gains " << tempMP << " MP.\n";
				if( actor.mp > actor.maxMP )
				{
					actor.mp = actor.maxMP;
				}
			}
		}
	}
	cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " moves to (" << actor.currentRow - 1 << ", " << actor.currentCol - 1 << ")\n";
	cout << "\n";
	cout << "Enter 1 to continue.\n";
	cin >> ctrPause;

	return confirmMove;
	return 0; //this should never trigger
}




int quickFunction( Player &unit )
{
	//internal turn order: p1, p6, p7, p2, p3, p8, p9, p4, p5, p10
	if( unit.quick == true )
	{
		if( unit.petrify == false && unit.sleep == false && unit.stop == false && unit.jumping == false )
		{
			unit.quick = false;
			return unit.turnOrder;
		}
	}
	
	return 0;
}


int innerTurnDecider( Player &unit )
{
	if( unit.ct >= 100 )
	{
		if( unit.petrify == false && unit.sleep == false && unit.stop == false && unit.jumping == false )
			return unit.turnOrder;
	}
	
	return 0;
}

int turnDecider( Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10 )
{
	//internal turn order: p1, p6, p7, p2, p3, p8, p9, p4, p5, p10
	int whoTurn = 0;

	//quick loop
	whoTurn = quickFunction( player1 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player6 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player7 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player2 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player3 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player8 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player9 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player4 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player5 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = quickFunction( player10 );
	if( whoTurn != 0)
		return whoTurn;

	//normal turn loop
	whoTurn = innerTurnDecider( player1 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player6 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player7 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player2 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player3 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player8 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player9 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player4 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player5 );
	if( whoTurn != 0)
		return whoTurn;
	whoTurn = innerTurnDecider( player10 );
	if( whoTurn != 0)
		return whoTurn;

	return 0;
}


int targetDisplay( Player target, string abilityName, int hitChance,
	int damage, string abilityEffect = "", bool statusType = false )
{
	int confirm = 0;

	if( statusType == false )
	{
		if( target.nullPlayer == false )
		{
			while ( (cout << "\t" << "TARGET: "<< target.teamName << " " << target.playerClassName << " " << target.playerName << " -- REACTION: " << target.reaction << "\n"
					<< "\t" << abilityEffect << damage << " -- " << hitChance <<"%\n"
					<< "\tCONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
					( !(cin >> confirm) || confirm < 1 || confirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			return confirm;
		}
		else
		{
			while ( (cout << "\t" << "NO TARGET\n"
					<< "\t" << abilityEffect << damage << " -- " << hitChance <<"%\n"
					<< "\tCONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
					( !(cin >> confirm) || confirm < 1 || confirm > 3 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			return confirm;
		}
	}

	else
	{
		if( target.nullPlayer == false )
		{
			while ( (cout << "\t" << "TARGET: "<< target.teamName << " " << target.playerClassName << " " << target.playerName << " -- REACTION: " << target.reaction << "\n"
					<< "\t" << abilityEffect << " -- " << hitChance <<"%\n"
					<< "\tCONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
					( !(cin >> confirm) || confirm < 1 || confirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			return confirm;
		}
		else
		{
			while ( (cout << "\t" << "NO TARGET\n"
					<< "\t" << abilityEffect << " -- " << hitChance <<"%\n"
					<< "\tCONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
					( !(cin >> confirm) || confirm < 1 || confirm > 3 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			return confirm;
		}
	}

	return confirm;

}


int targetFollowDisplay( )
{
	int confirm = 0 ;

	while ( (cout << "Target character or map square?  0.) Map Square  1.) Character\n") &&
			( !(cin >> confirm ) || confirm < 0 || confirm > 1 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return confirm;
}



class Golem
{

public:
	bool alive;
	int maxLife;
	int life;
	
	Golem()
	{
		alive = false;
		maxLife = 0;
		life = 0;
	}
	~Golem(){}

};

void golemSetter( Player actor, Golem &blueGolem, Golem &redGolem )
{
	if( (actor.teamName == "Blue" && actor.charm == false )
		|| ( actor.teamName == "Red" && actor.charm == true )
		)
	{
		blueGolem.alive = true;
		blueGolem.maxLife = actor.maxLife;
		blueGolem.life = actor.maxLife;
		cout << "\t" << actor.teamName << " gains a protective Golem!\n";
	}
	else if( (actor.teamName == "Red" && actor.charm == false )
		|| ( actor.teamName == "Blue" && actor.charm == true )
		)
	{
		redGolem.alive = true;
		redGolem.maxLife = actor.maxLife;
		redGolem.life = actor.maxLife;
		cout << "\t" << actor.teamName << " gains a protective Golem!\n";
	}
}

bool golemTester( Player target, Golem &blueGolem, Golem &redGolem )
{
	if( target.teamName == "Blue" && blueGolem.alive == true )
		return true;
	if( target.teamName == "Red" && redGolem.alive == true )
		return true;

	return false;
}

void golemDestroyer( Player target, Golem &blueGolem, Golem &redGolem, int damage )
{
	
	if( target.teamName == "Blue" )
	{
		if( blueGolem.alive == true )
		{
			damage = abs(damage);
			blueGolem.life -= damage;

			if( blueGolem.life <= 0 )
			{
				blueGolem.alive = false;
				blueGolem.life = 0;
				blueGolem.maxLife = 0;
				cout << "\t" << "Blue team's Golem takes " << damage << "! Blue team's Golem has been destroyed!\n";
			}
			else cout << "\t" << "Blue team's Golem takes " << damage << " damage!\n";
			
		}
	}

	else if( target.teamName == "Red")
	{
		if( redGolem.alive == true )
		{
			damage = abs(damage);
			redGolem.life -= damage;

			if( redGolem.life <= 0 )
			{
				redGolem.alive = false;
				redGolem.life = 0;
				redGolem.maxLife = 0;
				cout << "\t" << "Red team's Golem takes " << damage << "! Red team's Golem has been destroyed!\n";
			}
			else cout << "\t" << "Red team's Golem takes " << damage << " damage!\n";
		}
	}

}


void elementUpTest( Player &actor )
{
	actor.fireUp = false;
	actor.iceUp = false;
	actor.lightningUp = false;
	actor.waterUp = false;
	actor.earthUp = false;
	actor.windUp = false;
	actor.holyUp = false;
	actor.darkUp = false;
	
	if( actor.weaponFireUp == true || actor.bodyFireUp == true || actor.offHandFireUp == true
		|| actor.accFireUp == true )
	{
		actor.fireUp = true;
	}
	if( actor.weaponIceUp == true || actor.offHandIceUp == true || actor.bodyIceUp == true
		|| actor.accIceUp == true )
	{
		actor.iceUp = true;
	}
	if( actor.weaponLightningUp == true || actor.offHandLightningUp == true || actor.bodyLightningUp == true
		|| actor.accLightningUp == true )
	{
		actor.lightningUp = true;
	}
	if( actor.accWaterUp == true )
	{
		actor.waterUp = true;
	}
	if( actor.bodyEarthUp == true || actor.accEarthUp == true )
	{
		actor.earthUp = true;
	}
	if( actor.accWindUp == true )
	{
		actor.windUp = true;
	}
	if( actor.weaponHolyUp == true || actor.offHandHolyUp == true || actor.accHolyUp == true )
	{
		actor.holyUp = true;
	}
	if( actor.accDarkUp == true )
	{
		actor.darkUp = true;
	}
}


void elementDefenseTest( Player &target )
{
	target.fireAbsorb = false;
	target.iceAbsorb = false;
	target.lightningAbsorb = false;
	target.waterAbsorb = false;
	target.earthAbsorb = false;
	target.windAbsorb = false;
	target.holyAbsorb = false;
	target.darkAbsorb = false;

	target.fireHalf = false;
	target.iceHalf = false;
	target.lightningHalf = false;
	target.waterHalf = false;
	target.earthHalf = false;
	target.windHalf = false;
	target.holyHalf = false;
	target.darkHalf = false;

	target.fireWeak = false;
	target.iceWeak = false;
	target.lightningWeak = false;
	target.waterWeak = false;
	target.earthWeak = false;
	target.windWeak = false;
	target.holyWeak = false;
	target.darkWeak = false;

	target.fireBlock = false;
	target.iceBlock = false;
	target.lightningBlock = false;
	target.waterBlock = false;
	target.earthBlock = false;
	target.windBlock = false;
	target.holyBlock = false;
	target.darkBlock = false;

	if( target.weaponHolyAbsorb == true || target.offHandHolyAbsorb == true || target.bodyHolyAbsorb == true )
	{
		target.holyAbsorb = true;
	}
	if( target.bodyEarthAbsorb == true )
	{
		target.earthAbsorb = true;
	}
	if( target.offHandAbsorbFire == true )
	{
		target.fireAbsorb = true;
	}
	if( target.offHandAbsorbIce == true )
	{
		target.iceAbsorb = true;
	}

	if( target.offHandHalfFire == true || target.bodyFireHalf == true )
	{
		target.fireHalf = true;
	}
	if( target.offHandHalfIce == true || target.bodyIceHalf == true )
	{
		target.iceHalf = true;
	}
	if( target.offHandHalfLightning == true || target.bodyLightningHalf == true )
	{
		target.lightningHalf = true;
	}
	if( target.accDarkHalf == true )
	{
		target.darkHalf = true;
	}
	
	if( target.offHandWeakLightning == true )
	{
		target.lightningWeak = true;
	}
	if( target.offHandWeakWater == true )
	{
		target.waterWeak = true;
	}
	
	if( target.bodyLightningBlock == true || target.accLightningBlock == true )
	{
		target.lightningBlock = true;
	}
	
}

void tLine( Player target )
{
	cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName;
}

void mpDamage( Player &target, int damage )
{
	if( damage > 0 )
	{
		target.mp += damage;
		if( target.mp > target.maxMP )
			target.mp = target.maxMP;
		tLine(target);
		cout << " gains " << damage << " MP!\n";
	}
	else if( damage < 0 )
	{
		target.mp += damage;
		if( target.mp < 0 )
			target.mp = 0;
		tLine(target);
		cout << " takes " << damage << " MP damage!\n";
	}
	
	
}


void statusRemover( Player &target, string abilityName )
{
	string status = "";
	bool removed = false;
	int roundUp = 0;

	if( abilityName == "Antidote" )
	{
		if( target.poison == true )
		{
			removed = true;
			status = "Poison";
			target.poison = false;
		}
	}
	if( abilityName == "Eye Drop" )
	{
		if( target.darkness == true )
		{
			removed = true;
			status = "Darkness";
			target.darkness = false;
		}
	}
	if( abilityName == "Echo Grass" )
	{
		if( target.silence == true )
		{
			removed = true;
			status = "Silence";
			target.silence = false;
		}
	}
	if( abilityName == "Maiden's Kiss" )
	{
		if( target.frog == true )
		{
			removed = true;
			status = "Frog";
			target.frog = false;
		}
	}
	if( abilityName == "Soft" )
	{
		if( target.petrify == true )
		{
			removed = true;
			status = "Petrify";
			target.petrify = false;
		}
	}
	if( abilityName == "Holy Water" )
	{
		if( target.undead == true || target.bloodSuck == true )
		{
			removed = true;
			status = "Undead & Blood Suck";
			target.undead = false;
			target.bloodSuck = false;
		}
	}
	if( abilityName == "Remedy" )
	{
		if( target.darkness == true || target.petrify == true || target.confusion == true
			|| target.silence == true || target.oil == true || target.frog == true
			|| target.poison == true || target.sleep == true )
		{
			removed = true;
			status = " various ailments ";
			target.darkness = false;
			target.petrify = false;
			target.confusion = false;
			target.silence = false;
			target.oil = false;
			target.frog = false;
			target.poison = false;
			target.sleep = false;
		}
	}
	if( abilityName == "Revive" )
	{
		if( target.dead == true && target.undead == false )
		{
			if( target.maxLife % 5 != 0 )
				roundUp = 1;

			removed = true;
			status = "Dead";
			target.dead = false;
			target.life = target.maxLife / 5 + roundUp;
		}
	}
	if( abilityName == "Stigma Magic" )
	{
		if( target.darkness == true || target.petrify == true || target.confusion == true
			|| target.silence == true || target.berserk == true || target.frog == true
			|| target.poison == true || target.sleep == true || target.dontAct == true
			|| target.dontMove == true
			)
		{
			removed = true;
			status = " various ailments ";
			target.darkness = false;
			target.petrify = false;
			target.confusion = false;
			target.silence = false;
			target.berserk = false;
			target.frog = false;
			target.poison = false;
			target.sleep = false;
			target.dontAct = false;
			target.dontMove = false;
		}
	}

	if( removed == true )
	{
		tLine( target );
		cout << " is cured of " << status << "!\n";
	}
	else
	{
		cout << "\t" << abilityName << " has no effect on "
			<< target.teamName << " " << target.playerClassName << " " << target.playerName
			<< ".\n";
	}
	
}

void lifeSetter( Player &target, int damage )
{
	target.life += damage;

	if( target.life > target.maxLife )
	{
		target.life = target.maxLife;
		tLine( target );
		cout << " gains " << damage << " HP!\n";
	}
	else if( target.life < 1 )
	{
		statusSetter( target, "Dead" );
		tLine( target );
		cout << " takes " << damage << " HP damage and dies!\n";
	}
	else
	{
		tLine( target );
		cout << " takes " << damage << " HP damage!\n";
	}
}

int spellSetter( Player &target, string abilityName, Player &actor )
{
	//just damage and display happens here, reaction abilities back in main function

	elementDefenseTest( target );
	int damage = 0;
	int tempInt = 0;

	if( abilityName == "Lich" )
	{
		damage = -target.maxLife / 2 + -target.maxLife % 2;
		if( target.darkBlock == true )
			damage = 0;
		if( target.darkHalf == true )
			damage = damage / 2;
		if( target.darkAbsorb == true )
			damage *= -1;
		if( target.darkWeak == true )
			damage *= 2;

		lifeSetter( target, damage );
	}
	else if( abilityName == "Demi 2" )
	{
		damage = -target.maxLife / 2 + -target.maxLife % 2;
		

		target.maxLife += damage;

		lifeSetter( target, damage );
	}
	else if( abilityName == "Demi" )
	{
		if( tempInt % 4 != 0 )
			tempInt = 1;

		damage = -target.maxLife / 4 + -tempInt;
	
		target.maxLife += damage;

		lifeSetter( target, damage );
	}
	else if( abilityName == "Life Drain" )
	{
		if( tempInt % 4 != 0 )
			tempInt = 1;

		damage = -target.maxLife / 4 + -tempInt;
		
		if( target.undead == true )
			damage *= -1;
	
		lifeSetter( target, damage );
		damage *= -1;
		lifeSetter( actor, damage );
	
	}
	else if( abilityName == "Spell Absorb" )
	{
		if( tempInt % 4 != 0 )
			tempInt = 1;

		damage = -target.maxMP / 4 + -tempInt;
		
		if( target.mp < damage )
			damage = target.mp;
	
		target.mp += damage;
		
		actor.mp -= damage;
		if( actor.mp > actor.maxMP )
			actor.mp = actor.maxMP;

		tLine( target );
		cout << " loses " << damage << " MP!\n";
		tLine( actor );
		cout << " gains " << -damage << " MP!\n";

		return 0;
	}

	return damage;
}

void lifeDrainWeapon( Player &actor, int damage, bool mainHand = true )
{
	damage *= -1; //damage is absorbed. undead reversal happens in attack function
	if( actor.weaponLifeDrain == true && mainHand == true )
	{
		lifeSetter( actor, damage );
	}
	else if( actor.offHandLifeDrain == true && mainHand == false )
	{
		lifeSetter( actor, damage );
	}
}

void reflectSetter( Player &unit )
{
	if( ( unit.statusReflect == true || unit.accAutoReflect == true ||
		unit.bodyAutoReflect == true ) && unit.dead == false && unit.petrify == false )
	{
		unit.statusReflect = true;
	}
	else unit.statusReflect = false;

}