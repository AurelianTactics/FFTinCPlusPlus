//secondaries, Item & elemental are with the reactions abilities


//Archer Primary, charge secondary
	//need to add charging status
class Charge
{

public:
	string abilityName;
	string abilityType;
	bool reflect;
	bool calculate;
	bool elemental;
	bool counterBladeGrasp;
	bool counterMagic;
	bool counterFlood;
	bool evade;
	int magicPoints;
	int ctr; //clock ticks to resolution
	int ctrType;
	int jobPoints;
	int mod; //BMG type
	int abilityRange;
	int abilityEffect;
	int playerInput;
	int confirm;

	Charge() 
	{
		abilityName = " ";
		abilityType = "physical";
		reflect = false;
		calculate = false;
		elemental = true;
		counterBladeGrasp = true;
		evade = true;
		magicPoints = 0;
		ctr = 0; //set individually
		ctrType = 1; //used for resolving the action in slow menu
		jobPoints = 0;
		mod = 0; //not sure about this
		abilityRange = 1; //actually weapon range
		abilityEffect = 1;
		playerInput = 0; //set by input
		confirm = 0;
	}
	~Charge() {}

	void chargeMenu( Charge &chargeObject, Player actor );
	void chargeFunction( Charge &chargeObject, char myArray[][11], Player &actor, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, MimeClass &mimeObject );
};

void Charge::chargeMenu( Charge &chargeObject, Player actor )
{
	int chargeAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " CHARGE Menu ---\n"	
		<< "0.) Return to Menu\n"
		<< "1.) Charge +1 -- 4 CTR\n"
		<< "2.) Charge +2 -- 5 CTR\n"
		<< "3.) Charge +3 -- 6 CTR\n"
		<< "4.) Charge +4 -- 8 CTR\n"
		<< "5.) Charge +5 -- 10 CTR\n"
		<< "6.) Charge +7 -- 14 CTR\n"
		<< "7.) Charge +10 -- 20 CTR\n"
		<< "8.) Charge +20 -- 35 CTR\n" 
		) && ( !( cin >> chargeAction ) || chargeAction < 0 || chargeAction > 8 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	chargeObject.playerInput = chargeAction;
	if( chargeObject.playerInput == 0 )
	{
		chargeObject.confirm = 0;
	}
	else chargeObject.confirm = 2;
}

void Charge::chargeFunction( Charge &chargeObject, char myArray[][11], Player &actor, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, MimeClass &mimeObject )
{
	vector<int> rangeVector (2, 0);
	Player target;
	int chargeConfirm = 2;
	int baseHit = 0;
	int chargeK = 0;
	int chargeDisplayDamage = 0;
	int chargeActualDamage = 0;

	mimeObject.mimeChargeConfirm = 0;

	if( chargeObject.confirm == 0 )
	{
		actor.confirm = 3;
	}
	else if( chargeObject.confirm != 0)
	{
		if ( chargeObject.playerInput == 1)
		{
			chargeK = chargeObject.playerInput;
			chargeObject.abilityName = "Charge +1";
			chargeObject.ctr = 4;
		}
		if ( chargeObject.playerInput == 2)
		{
			chargeK = chargeObject.playerInput;
			chargeObject.abilityName = "Charge +2";
			chargeObject.ctr = 5;
		}
		if ( chargeObject.playerInput == 3)
		{
			chargeK = chargeObject.playerInput;
			chargeObject.abilityName = "Charge +3";
			chargeObject.ctr = 6;
			
		}
		if ( chargeObject.playerInput == 4)
		{
			chargeK = chargeObject.playerInput;
			chargeObject.abilityName = "Charge +4";
			chargeObject.ctr = 8;
		}
		if ( chargeObject.playerInput == 5 )
		{
			chargeK = chargeObject.playerInput;
			chargeObject.abilityName = "Charge +5";
			chargeObject.ctr = 10;
		}
		else if (chargeObject.playerInput == 6 )
		{
			chargeK = 7;
			chargeObject.abilityName = "Charge +7";
			chargeObject.ctr = 14;
		}
		else if (chargeObject.playerInput == 7 )
		{
			chargeK = 10;
			chargeObject.abilityName = "Charge +10";
			chargeObject.ctr = 20;
		}
		else if( chargeObject.playerInput == 8 )
		{
			chargeK = 20;
			chargeObject.abilityName = "Charge +20";
			chargeObject.ctr = 35;
		}
		do 
		{
			rangeVector = rangeTest( actor, actor.weaponRange,
				chargeObject.abilityName, actor.weaponRangeMin, true );
			target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == true ) //targets no one
			{
				chargeConfirm = targetDisplay( target, chargeObject.abilityName, 0, 
					chargeDisplayDamage, "-- HP " );
				
				if( chargeConfirm == 1 )
				{
					actor.charging = true;
					actor.archerCharging = true;
					actor.ctrCountdownBool = true;
					actor.ctrCountdown = chargeObject.ctr;
					actor.ctrName = chargeObject.abilityName;
					actor.ctrType = chargeObject.ctrType; //charge type 
					actor.ctrRow = rangeVector[0];
					actor.ctrCol = rangeVector[1];
					actor.ctrK = chargeK;
				}
			}
			else
			{
				actor.ctrK = chargeK;
				baseHit = counterGraspEvade( 100, actor, target );
				chargeDisplayDamage = -displayDamage( actor, target );
				actor.ctrK = 0;

				chargeConfirm = targetDisplay( target, chargeObject.abilityName, baseHit, 
					chargeDisplayDamage, "-- HP " );

				if( chargeConfirm == 1 )
				{
					actor.charging = true;
					actor.ctrCountdownBool = true;
					actor.ctrCountdown = chargeObject.ctr;
					actor.ctrName = chargeObject.abilityName;
					actor.ctrType = chargeObject.ctrType; //charge type 
					actor.ctrRow = rangeVector[0];
					actor.ctrCol = rangeVector[1];
					actor.ctrK = chargeK;
				}
			}
		} while(chargeConfirm == 2);
	}
	if( chargeConfirm == 3 )
	{
		actor.confirm = 3;
	}
}


void chargeResolve(Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Player &nullPlayer, char myArray[][11], Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem,
	MimeClass &mimeObject )
{
	Player target;
	int targetDamage = 0;
	bool hamedoTest = false;

	target = targetFunction( actor.ctrRow, actor.ctrCol, player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

	if( target.nullPlayer == true || target.petrify == true || target.dead == true )
	{
		cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
			<< " targets (" << actor.ctrRow - 1 << ", " << actor.ctrCol - 1
			<< ") and no one is hit.\n";
	}
	else
	{
		hamedoTest = hamedoReaction( actor, target, myArray, blueItem, redItem, blueGolem, redGolem,
			player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

		if( hamedoTest == false )
		{
			targetDamage = turnInnerAttack( actor, target, myArray, blueGolem, redGolem );

			hpReaction( target, blueItem, redItem, actor, targetDamage );
			if( targetDamage > 0 )
			{
				distributeReaction( target, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, targetDamage );
			}
			if( actor.weaponType != "Magic Gun" )
			{
				counterGraspReaction( actor, target, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
				counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
			}
			else
			{
				magicGunReaction( 0, target, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			}
		}
	}
	endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );

	//mime stuff
	mimeObject.mimeChargeConfirm = 1;
	vector<int> mimeVector (2, 0);
	mimeVector = mimeTargetFunction( actor.ctrRow, actor.ctrCol, actor);
	mimeObject.chargeSide = mimeVector[0];
	mimeObject.chargeDistance = mimeVector[1];
	mimeObject.ctrK = actor.ctrK;
}

void mimeChargeFunction( Player &theMime, Player &mimedUnit, Player &player1, Player &player2, Player &player3, Player &player4,
	 Player &player5, Player &player6,  Player &player7, Player &player8, Player &player9, Player &player10,
	 Player &nullPlayer, char myArray[][11], Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem,
	 MimeClass &mimeObject )
{
	string attackString = "ATTACK";

	vector<int> targetVector (2, 0);
	Player target;

	bool hamedoTest = false;
	int targetDamage = 0;

	cout << "\t" << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
			<< " attempts to Mimic CHARGE ";

	targetVector = mimeTargetVector( theMime, mimeObject.chargeSide, mimeObject.chargeDistance );
	target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
	
	if( target.nullPlayer == true || target.petrify == true || target.dead == true )
	{
		
		cout << "\t" << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
			<< " targets (" << targetVector[0]-1 << ", " << targetVector[1]-1
			<< ") and no one is hit.\n";
	}
	else
	{
		cout << "\t" << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
			<< " targets " << target.teamName << " " << target.playerClassName << " " << target.playerName << "...\n";

		hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
			player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

		if( hamedoTest == false )
		{
			weaponCopier( theMime, mimedUnit );
			theMime.ctrK = mimeObject.ctrK;
			targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );
			theMime.ctrK = 0;
			weaponUnCopy( theMime );

			hpReaction( target, blueItem, redItem, theMime, targetDamage );
			if( targetDamage > 0 )
			{
				distributeReaction( target, theMime, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, targetDamage );
			}
			if( theMime.weaponType != "Magic Gun" )
			{
				counterGraspReaction( theMime, target, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
				counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
			}
			else
			{
				magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			}
		}
		endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );
		
	} //ends player target loop
}


class Song
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	bool evade;
	bool abilityCTR;
	int abilityCTRCount;
	int abilityDamage;
	int abilityChance;
	
	Song()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "neutral";
		evade = false;
		abilityCTR = true;
		abilityCTRCount = 0;
		abilityDamage = 0;
		abilityChance = 0;
		
	}
	~Song() {}

	void songMenu( Song &songObject, Player actor );
	void songSuccess( Song &songObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11]
	);
};

void Song::songMenu( Song &songObject, Player actor )
{
	int songMenu = 0; 
	int songAction = 0;

	songObject.confirm = 2;
	songObject.abilityName = "";
	songObject.abilityType = "neutral";
	songObject.evade = false;
	songObject.abilityCTR = true;
	songObject.abilityCTRCount = 0;
	songObject.abilityDamage = 0;
	songObject.abilityChance = 0;

	while( ( cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " SING Menu ---\n"
		<< "0.) Return to Menu\n" 
		<< "1.) ANGEL SONG    -- Restore MP      --  6 CTR\n"  
		<< "2.) LIFE SONG     -- Restore HP      --  6 CTR\n" 
		<< "3.) CHEER SONG    -- Speed +1        --  8 CTR\n"
		<< "4.) BATTLE SONG   -- PA +1           --  8 CTR\n"  
		<< "5.) MAGIC SONG    -- MA +1           -- 10 CTR\n"
		<< "6.) NAMELESS SONG -- Add Good Status -- 10 CTR\n"
		<< "7.) LAST SONG     -- Add Quick       -- 20 CTR\n" 
		)
		&& ( !(cin >> songMenu)
		|| songMenu < 0 || songMenu > 7  ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

		songObject.playerInput = songMenu;
		if( songMenu == 0 )
		{
			songObject.confirm = 0;
		}
		else songObject.confirm = 2;
}

void Song::songSuccess( Song &songObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11]
	)
{
	Player target;
	int songConfirm = 2;
	int throwDamage = 0;

	if( songObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}
	else if( songObject.confirm != 0 ) //begins throw calculations
	{
		do
		{
			if( songObject.playerInput == 1 )
			{
				songObject.abilityName = "Angel Song";
				songObject.abilityCTRCount = 6;
				songObject.abilityDamage = 20 + actor.ma;
				songObject.abilityChance = 100;

				while ( (cout << songObject.abilityName << " -- MP +" << songObject.abilityDamage <<" -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( songObject.playerInput == 2 )
			{
				songObject.abilityName = "Life Song";
				songObject.abilityCTRCount = 6;
				songObject.abilityDamage = 10 + actor.ma;
				songObject.abilityChance = 100;

				while ( (cout << songObject.abilityName << " -- Life +" << songObject.abilityDamage <<" -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( songObject.playerInput == 3 )
			{
				songObject.abilityName = "Cheer Song";
				songObject.abilityCTRCount = 8;
				songObject.abilityDamage = 1;
				songObject.abilityChance = 50;

				while ( (cout << songObject.abilityName << " -- Speed +" << songObject.abilityDamage <<" -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( songObject.playerInput == 4 )
			{
				songObject.abilityName = "Battle Song";
				songObject.abilityCTRCount = 8;
				songObject.abilityDamage = 1;
				songObject.abilityChance = 50;

				while ( (cout << songObject.abilityName << " -- Phy Attack +" << songObject.abilityDamage <<" -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( songObject.playerInput == 5 )
			{
				songObject.abilityName = "Magic Song";
				songObject.abilityCTRCount = 10;
				songObject.abilityDamage = 1;
				songObject.abilityChance = 50;

				while ( (cout << songObject.abilityName << " -- MA +" << songObject.abilityDamage <<" -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( songObject.playerInput == 6 )
			{
				songObject.abilityName = "Nameless Song";
				songObject.abilityCTRCount = 8;
				songObject.abilityChance = 50;

				while ( (cout << songObject.abilityName << " -- Reraise/Regen/Protect/Shell/Reflect -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( songObject.playerInput == 7 )
			{
				songObject.abilityName = "Last Song";
				songObject.abilityCTRCount = 20;
				songObject.abilityChance = 50;

				while ( (cout << songObject.abilityName << " -- Quick " << " -- " << songObject.abilityChance 
				<< "%\n" << "Confirm: 1.) Yes 2.) No 3.) Menu\n") &&
				( !(cin >> songConfirm) || songConfirm < 1 || songConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			if( songConfirm == 1 )
			{
				actor.performing = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 2;
				actor.ctrName = songObject.abilityName;
				actor.ctrCountdown = songObject.abilityCTRCount;
				actor.ctrInput = songObject.playerInput;
			}
		}while(songConfirm == 2);
	}
	if( songConfirm == 3 )
	{
		actor.confirm = 3;
	}
}




void songResolve( Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10
	)
{
	int songDamage;
	int songChance;
	int songRoll = 0;
	int namelessRoll = 0;
	string namelessString = "";

	if( actor.teamName == player1.teamName )
	{
		if( actor.ctrInput == 1 ) //angel song
		{
			actor.ctrCountdown = 6;
			songChance = 100;
			songDamage = 20 + actor.ma;
			
			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player1.mp += songDamage;
				if( player1.mp > player1.maxMP )
					player1.mp = player1.maxMP;
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player2.mp += songDamage;
				if( player2.mp > player2.maxMP )
					player2.mp = player2.maxMP;
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player3.mp += songDamage;
				if( player3.mp > player3.maxMP )
					player3.mp = player3.maxMP;
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player4.mp += songDamage;
				if( player4.mp > player4.maxMP )
					player4.mp = player4.maxMP;
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player5.mp += songDamage;
				if( player5.mp > player5.maxMP )
					player5.mp = player5.maxMP;
			}
		}
		else if( actor.ctrInput == 2 ) //Life song
		{
			actor.ctrCountdown = 6;
			songChance = 100;
			songDamage = 10 + actor.ma;
			
			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player1.life += songDamage;
				if( player1.life > player1.maxLife )
					player1.life = player1.maxLife;
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player2.life += songDamage;
				if( player2.life > player2.maxLife )
					player2.life = player2.maxLife;
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player3.life += songDamage;
				if( player3.life > player3.maxLife )
					player3.life = player3.maxLife;
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player4.life += songDamage;
				if( player4.life > player4.maxLife )
					player4.life = player4.maxLife;
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player5.life += songDamage;
				if( player5.life > player5.maxLife )
					player5.life = player5.maxLife;
			}
		}
		else if( actor.ctrInput == 3 ) //Cheer song
		{
			actor.ctrCountdown = 8;
			songChance = 50;
			songDamage = 1;
			
			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player1.speed += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player2.speed += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player3.speed += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player4.speed += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player5.speed += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 4 ) //battle song
		{
			actor.ctrCountdown = 8;
			songChance = 50;
			songDamage = 1;

			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player1.pa += songDamage;
				}
				else cout  << "\t"  << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player2.pa += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player3.pa += songDamage;
				}
				else cout << "\t"  << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player4.pa += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player5.pa += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 5 ) //Magic song
		{
			actor.ctrCountdown = 10;
			songChance = 50;
			songDamage = 1;
			
			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player1.ma += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player2.ma += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player3.ma += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player4.ma += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player5.ma += songDamage;
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 6 ) //Nameless song
		{
			actor.ctrCountdown = 10;
			songChance = 50;
			
			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player1.undead == false )
						{
							player1.reraise = true;
							statusSetter( player1, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player1.regen = true;
						statusSetter( player1, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player1.protect = true;
						statusSetter( player1, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player1.shell = true;
						statusSetter( player1, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player1.statusReflect = true;
						statusSetter( player1, "Reflect" );
					}	
				}
				else cout  << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player2.undead == false )
						{
							player2.reraise = true;
							statusSetter( player2, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player2.regen = true;
						statusSetter( player2, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player2.protect = true;
						statusSetter( player2, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player2.shell = true;
						statusSetter( player2, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player2.statusReflect = true;
						statusSetter( player2, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player3.undead == false )
						{
							player3.reraise = true;
							statusSetter( player3, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player3.regen = true;
						statusSetter( player3, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player3.protect = true;
						statusSetter( player3, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player3.shell = true;
						statusSetter( player3, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player3.statusReflect = true;
						statusSetter( player3, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player4.undead == false )
						{
							player4.reraise = true;
							statusSetter( player4, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player4.regen = true;
						statusSetter( player4, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player4.protect = true;
						statusSetter( player4, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player4.shell = true;
						statusSetter( player4, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player4.statusReflect = true;
						statusSetter( player4, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player5.undead == false )
						{
							player5.reraise = true;
							statusSetter( player5, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player5.regen = true;
						statusSetter( player5, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player5.protect = true;
						statusSetter( player5, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player5.shell = true;
						statusSetter( player5, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player5.statusReflect = true;
						statusSetter( player5, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 7 ) //Last song
		{
			actor.ctrCountdown = 20;
			songChance = 50;
			
			if( player1.sleep == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					statusSetter( player1, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					statusSetter( player2, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					statusSetter( player3, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				if( songRoll <= songChance )
				{
				
					statusSetter( player4, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.invite == false && player5.dead == false  && player5.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				if( songRoll <= songChance )
				{
					
					statusSetter( player5, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
	}// end first team loop

	else if( actor.teamName == player6.teamName )
	{
		if( actor.ctrInput == 1 ) //angel song
		{
			actor.ctrCountdown = 6;
			songChance = 100;
			songDamage = 20 + actor.ma;
			
			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player6.mp += songDamage;
				if( player6.mp > player6.maxMP )
					player6.mp = player6.maxMP;
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player7.mp += songDamage;
				if( player7.mp > player7.maxMP )
					player7.mp = player7.maxMP;
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player8.mp += songDamage;
				if( player8.mp > player8.maxMP )
					player8.mp = player8.maxMP;
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player9.mp += songDamage;
				if( player9.mp > player9.maxMP )
					player9.mp = player9.maxMP;
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< " " << songDamage << " MP restored!\n"; 
				player10.mp += songDamage;
				if( player10.mp > player10.maxMP )
					player10.mp = player10.maxMP;
			}
		}
		else if( actor.ctrInput == 2 ) //Life song
		{
			actor.ctrCountdown = 6;
			songChance = 100;
			songDamage = 10 + actor.ma;
			
			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player6.life += songDamage;
				if( player6.life > player6.maxLife )
					player6.life = player6.maxLife;
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player7.life += songDamage;
				if( player7.life > player7.maxLife )
					player7.life = player7.maxLife;
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player8.life += songDamage;
				if( player8.life > player8.maxLife )
					player8.life = player8.maxLife;
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player9.life += songDamage;
				if( player9.life > player9.maxLife )
					player9.life = player9.maxLife;
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< " " << songDamage << " Life restored!\n"; 
				player10.life += songDamage;
				if( player10.life > player10.maxLife )
					player10.life = player10.maxLife;
			}
		}
		else if( actor.ctrInput == 3 ) //Cheer song
		{
			actor.ctrCountdown = 8;
			songChance = 50;
			songDamage = 1;
			
			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player6.speed += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player7.speed += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player8.speed += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player9.speed += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Speed!\n"; 
					player10.speed += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 4 ) //battle song
		{
			actor.ctrCountdown = 8;
			songChance = 50;
			songDamage = 1;

			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player6.pa += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player7.pa += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player8.pa += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player9.pa += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Physical Attack!\n"; 
					player10.pa += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 5 ) //Magic song
		{
			actor.ctrCountdown = 10;
			songChance = 50;
			songDamage = 1;
			
			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player6.ma += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player7.ma += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player8.ma += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player9.ma += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					cout << "\tSong hits! +" << songDamage << " Magic Attack!\n"; 
					player10.ma += songDamage;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 6 ) //Nameless song
		{
			actor.ctrCountdown = 10;
			songChance = 50;
			
			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					
					if( namelessRoll == 1 )
					{
						if( player6.undead == false )
						{
							player6.reraise = true;
							statusSetter( player6, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player6.regen = true;
						statusSetter( player6, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player6.protect = true;
						statusSetter( player6, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player6.shell = true;
						statusSetter( player6, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player6.statusReflect = true;
						statusSetter( player6, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player7.undead == false )
						{
							player7.reraise = true;
							statusSetter( player7, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player7.regen = true;
						statusSetter( player7, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player7.protect = true;
						statusSetter( player7, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player7.shell = true;
						statusSetter( player7, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player7.statusReflect = true;
						statusSetter( player7, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player8.undead == false )
						{
							player8.reraise = true;
							statusSetter( player8, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player8.regen = true;
						statusSetter( player8, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player8.protect = true;
						statusSetter( player8, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player8.shell = true;
						statusSetter( player8, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player8.statusReflect = true;
						statusSetter( player8, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player9.undead == false )
						{
							player9.reraise = true;
							statusSetter( player9, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player9.regen = true;
						statusSetter( player9, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player9.protect = true;
						statusSetter( player9, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player9.shell = true;
						statusSetter( player9, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player9.statusReflect = true;
						statusSetter( player9, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				namelessRoll = rand() % 5;
				if( namelessRoll == 1 )
					namelessString = "Reraise";
				else if( namelessRoll == 2)
					namelessString = "Regen";
				else if( namelessRoll == 3)
					namelessString = "Protect";
				else if( namelessRoll == 4)
					namelessString = "Shell";
				else if( namelessRoll == 0)
					namelessString = "Reflect";

				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				if( songRoll <= songChance )
				{
					
					if( namelessRoll == 1 )
					{
						if( player10.undead == false )
						{
							player10.reraise = true;
							statusSetter( player10, "Reraise" );
						}
					}
					else if( namelessRoll == 2)
					{
						player10.regen = true;
						statusSetter( player10, "Regen" );
					}
					else if( namelessRoll == 3)
					{
						player10.protect = true;
						statusSetter( player10, "Protect" );
					}
					else if( namelessRoll == 4)
					{
						player10.shell = true;
						statusSetter( player10, "Shell" );
					}
					else if( namelessRoll == 0)
					{
						player10.statusReflect = true;
						statusSetter( player10, "Reflect" );
					}	
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 7 ) //Last song
		{
			actor.ctrCountdown = 20;
			songChance = 50;
			
			if( player6.sleep == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				cout << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				songRoll = rand() % 100 + 1;
				if( songRoll <= songChance )
				{
					statusSetter( player6, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				if( songRoll <= songChance )
				{
					statusSetter( player7, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				if( songRoll <= songChance )
				{
					statusSetter( player8, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				if( songRoll <= songChance )
				{
					statusSetter( player9, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.invite == false && player10.dead == false  && player10.activePlayer == true )
			{
				songRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << songRoll << "\n";
				
				if( songRoll <= songChance )
				{
					statusSetter( player10, "Quick" );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
	}// end second team loop
}


void mimeSongFunction( MimeClass &mimeObject, Player &theMime, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, bool mimeSong = true )
{

	if( theMime.playerClass == 10  )
	{
		if( ( theMime.teamName == mimedUnit.teamName && theMime.charm == false ) ||
			( theMime.teamName != mimedUnit.teamName && theMime.charm == true ) )
		{
			if( theMime.dead == false && theMime.petrify == false && theMime.sleep == false
				&& theMime.stop == false && theMime.bloodSuck == false && theMime.dontAct == false
				&& theMime.frog == false && theMime.chicken == false && theMime.confusion == false
				&& theMime.berserk == false )
			{
				theMime.ctrInput = mimedUnit.ctrInput;
				theMime.ctrType = mimedUnit.ctrType;
				theMime.ctrName = mimedUnit.ctrName;

				if( mimeSong == true && theMime.ctrType == 2 )
				{
					cout << "\n"
						<< "   --- MIME ACTION ---\n"
						<< theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
						<< " attempts to mimic... \n";
					songResolve( theMime, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10 );
					
				} //should always be true

				theMime.ctrInput = 0;
				theMime.ctrType = 0;
			}// eligible status effect
		}//charmed or not charmed
	}//player is a mime

	
}

class Dance
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	bool evade;
	bool abilityCTR;
	int abilityCTRCount;
	int abilityDamage;
	int abilityChance;
	
	Dance()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "neutral";
		evade = false;
		abilityCTR = true;
		abilityCTRCount = 0;
		abilityDamage = 0;
		abilityChance = 0;
		
	}
	~Dance() {}

	void danceMenu( Dance &danceObject, Player actor );
	void danceSuccess( Dance &danceObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11]
	);
};

void Dance::danceMenu( Dance &danceObject, Player actor )
{
	int danceMenu = 0; 
	int danceAction = 0;

	danceObject.confirm = 2;
	danceObject.abilityName = "";
	danceObject.abilityType = "neutral";
	danceObject.evade = false;
	danceObject.abilityCTR = true;
	danceObject.abilityCTRCount = 0;
	danceObject.abilityDamage = 0;
	danceObject.abilityChance = 0;

	while( ( cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " DANCE Menu ---\n"
		<< "0.) Return to Menu\n" 
		<< "1.) WITCH HUNT     -- MP Damage      --  6 CTR\n"  
		<< "2.) WIZNAIBUS      -- HP Damage      --  6 CTR\n" 
		<< "3.) SLOW DANCE     -- Speed -1       --  8 CTR\n"  
		<< "4.) POLKA POLKA    -- PA -1          --  8 CTR\n"  
		<< "5.) DISILLUSION    -- MA -1          --  8 CTR\n"
		<< "6.) NAMELESS DANCE -- Add Bad Status -- 10 CTR\n" 
		<< "7.) LAST DANCE     -- Set CT to 0    -- 20 CTR\n" 
		)
		&& ( !(cin >> danceMenu)
		|| danceMenu < 0 || danceMenu > 7  ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

		danceObject.playerInput = danceMenu;
		if( danceMenu == 0 )
		{
			danceObject.confirm = 0;
		}
		else danceObject.confirm = 2;
}

void Dance::danceSuccess( Dance &danceObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11]
	)
{
	Player target;
	int danceConfirm = 2;
	int throwDamage = 0;

	if( danceObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}
	else if( danceObject.confirm != 0 ) 
	{
		do
		{
			if( danceObject.playerInput == 1 )
			{
				danceObject.abilityName = "Witch Hunt";
				danceObject.abilityCTRCount = 6;
				danceObject.abilityDamage = actor.pa + actor.pa * actor.brave / 100;
				danceObject.abilityChance = 100;

				while ( (cout << danceObject.abilityName << " -- MP -" << danceObject.abilityDamage <<" -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( danceObject.playerInput == 2 )
			{
				danceObject.abilityName = "Wiznaibus";
				danceObject.abilityCTRCount = 6;
				danceObject.abilityDamage = actor.pa + actor.pa * actor.brave / 100;
				danceObject.abilityChance = 100;

				while ( (cout << danceObject.abilityName << " -- Life -" << danceObject.abilityDamage <<" -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( danceObject.playerInput == 3 )
			{
				danceObject.abilityName = "Slow Dance";
				danceObject.abilityCTRCount = 8;
				danceObject.abilityDamage = 1;
				danceObject.abilityChance = 50;

				while ( (cout << danceObject.abilityName << " -- Speed -" << danceObject.abilityDamage <<" -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( danceObject.playerInput == 4 )
			{
				danceObject.abilityName = "Polka Polka";
				danceObject.abilityCTRCount = 8;
				danceObject.abilityDamage = 1;
				danceObject.abilityChance = 50;

				while ( (cout << danceObject.abilityName << " -- Phy Attack -" << danceObject.abilityDamage <<" -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( danceObject.playerInput == 5 )
			{
				danceObject.abilityName = "Disillusion";
				danceObject.abilityCTRCount = 8;
				danceObject.abilityDamage = 1;
				danceObject.abilityChance = 50;

				while ( (cout << danceObject.abilityName << " -- MA -" << danceObject.abilityDamage <<" -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( danceObject.playerInput == 6 )
			{
				danceObject.abilityName = "Nameless Dance";
				danceObject.abilityCTRCount = 10;
				danceObject.abilityChance = 50;

				while ( (cout << danceObject.abilityName << " -- Darkness/Confusion/Silence/Frog/Poison/Slow/Stop/Sleep -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			else if( danceObject.playerInput == 7 )
			{
				danceObject.abilityName = "Last Dance";
				danceObject.abilityCTRCount = 20;
				danceObject.abilityChance = 34;

				while ( (cout << danceObject.abilityName << " -- CT = 0" << " -- " << danceObject.abilityChance 
				<< "%\n" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
				( !(cin >> danceConfirm) || danceConfirm < 1 || danceConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			if( danceConfirm == 1 )
			{
				actor.performing = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 5;
				actor.ctrName = danceObject.abilityName;
				actor.ctrCountdown = danceObject.abilityCTRCount;
				actor.ctrInput = danceObject.playerInput;
			}
		}while(danceConfirm == 2);
	}
	if( danceConfirm == 3 )
	{
		actor.confirm = 3;
	}
}

void danceResolve( Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem )
{
	int danceDamage;
	int danceChance;
	int danceRoll = 0;
	int namelessRoll = 0;
	string namelessString = "";

	if( 
		( actor.teamName != player1.teamName && actor.charm == false ) ||
		( actor.teamName == player1.teamName && actor.charm == true )
		)
	{
		if( actor.ctrInput == 1 ) //Witch Hunt
		{
			actor.ctrCountdown = 6;
			danceChance = 100;
			danceDamage = actor.pa + actor.pa * actor.brave / 100;
			
			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false
				&& player1.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player1.mp -= danceDamage;
				if( player1.mp <= 0)
					player1.mp = 0;
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player2.mp -= danceDamage;
				if( player2.mp <= 0)
					player2.mp = 0;
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player3.mp -= danceDamage;
				if( player3.mp <= 0)
					player3.mp = 0;
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player4.mp -= danceDamage;
				if( player4.mp <= 0)
					player4.mp = 0;
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player5.mp -= danceDamage;
				if( player5.mp <= 0)
					player5.mp = 0;
			}
		}
		else if( actor.ctrInput == 2 ) //Wiznaibus
		{
			actor.ctrCountdown = 6;
			danceChance = 100;
			danceDamage = -1 * actor.pa + -actor.pa * actor.brave / 100;
			
			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player1, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player2, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				cout << "\t"  << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player3, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player4, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player5, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
		}
		else if( actor.ctrInput == 3 ) //slow dance
		{
			actor.ctrCountdown = 8;
			danceChance = 50;
			danceDamage = 1;
			
			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player1.speed -= danceDamage;
					if( player1.speed < 1 )
						player1.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player2.speed -= danceDamage;
					if( player2.speed < 1 )
						player2.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player3.speed -= danceDamage;
					if( player3.speed < 1 )
						player3.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player4.speed -= danceDamage;
					if( player4.speed < 1 )
						player4.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player5.speed -= danceDamage;
					if( player5.speed < 1 )
						player5.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 4 ) //polka polka
		{
			actor.ctrCountdown = 8;
			danceChance = 50;
			danceDamage = 1;

			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player1.pa -= danceDamage;
					if( player1.pa < 1 )
						player1.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player2.pa -= danceDamage;
					if( player2.pa < 1 )
						player2.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player3.pa -= danceDamage;
					if( player3.pa < 1 )
						player3.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player4.pa -= danceDamage;
					if( player4.pa < 1 )
						player4.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player5.pa -= danceDamage;
					if( player5.pa < 1 )
						player5.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 5 ) //Magic dance
		{
			actor.ctrCountdown = 8;
			danceChance = 50;
			danceDamage = 1;
			
			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player1.ma -= danceDamage;
					if( player1.ma < 1 )
						player1.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player2.ma -= danceDamage;
					if( player2.ma < 1 )
						player2.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player3.ma -= danceDamage;
					if( player3.ma < 1 )
						player3.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player4.ma -= danceDamage;
					if( player4.ma < 1 )
						player4.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player5.ma -= danceDamage;
					if( player5.ma < 1 )
						player5.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 6 ) //Nameless dance
		{
			actor.ctrCountdown = 10;
			danceChance = 50;
			
			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player1, namelessString );
					
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					
					statusSetter( player2, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player3, namelessString );
					
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player4, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false && player5.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player5, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 7 ) //Last dance
		{
			actor.ctrCountdown = 20;
			danceChance = 34;
			
			if( player1.sleep == false && player1.petrify == false && player1.invite == false && player1.dead == false && player1.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player1.teamName << " " << player1.playerClassName << " " << player1.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player1.playerName << " CT set to 0!\n"; 
					player1.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player2.sleep == false && player2.petrify == false && player2.invite == false && player2.dead == false && player2.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player2.teamName << " " << player2.playerClassName << " " << player2.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player2.playerName << " CT set to 0!\n"; 
					player2.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player3.sleep == false && player3.petrify == false && player3.invite == false && player3.dead == false && player3.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player3.teamName << " " << player3.playerClassName << " " << player3.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player3.playerName << " CT set to 0!\n";  
					player3.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player4.sleep == false && player4.petrify == false && player4.invite == false && player4.dead == false && player4.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player4.teamName << " " << player4.playerClassName << " " << player4.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player4.playerName << " CT set to 0!\n";  
					player4.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player5.sleep == false && player5.petrify == false && player5.invite == false && player5.dead == false  && player5.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player5.teamName << " " << player5.playerClassName << " " << player5.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player5.playerName << " CT set to 0!\n";  
					player5.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
	}// end first team loop

	else if( 
		( actor.teamName != player6.teamName && actor.charm == false ) ||
		( actor.teamName == player6.teamName && actor.charm == true ) 
		)
	{
		if( actor.ctrInput == 1 ) //Witch Hunt
		{
			actor.ctrCountdown = 6;
			danceChance = 100;
			danceDamage = actor.pa + actor.pa * actor.brave / 100;
			
			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false
				&& player6.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player6.mp -= danceDamage;
				if( player6.mp <= 0)
					player6.mp = 0;
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player7.mp -= danceDamage;
				if( player7.mp <= 0)
					player7.mp = 0;
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player8.mp -= danceDamage;
				if( player8.mp <= 0)
					player8.mp = 0;
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player9.mp -= danceDamage;
				if( player9.mp <= 0)
					player9.mp = 0;
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< " " << danceDamage << " MP lost!\n"; 
				player10.mp -= danceDamage;
				if( player10.mp <= 0)
					player10.mp = 0;
			}
		}
		else if( actor.ctrInput == 2 ) //Wiznaibus
		{
			actor.ctrCountdown = 6;
			danceChance = 100;
			danceDamage = -1 * actor.pa + -actor.pa * actor.brave / 100;
			
			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player1, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player2, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				cout << "\t"  << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player3, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player4, actor, blueItem, redItem, danceDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< " " << danceDamage << " Life lost!\n"; 
				hpDamage( player5, actor, blueItem, redItem, danceDamage, player1,
					player2, player3, player4, player5, player6, player7, player8, player9,
					player10  );
			}
		}
		else if( actor.ctrInput == 3 ) //slow dance
		{
			actor.ctrCountdown = 8;
			danceChance = 50;
			danceDamage = 1;
			
			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player6.speed -= danceDamage;
					if( player6.speed < 1 )
						player6.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player7.speed -= danceDamage;
					if( player7.speed < 1 )
						player7.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player8.speed -= danceDamage;
					if( player8.speed < 1 )
						player8.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player9.speed -= danceDamage;
					if( player9.speed < 1 )
						player9.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Speed!\n"; 
					player10.speed -= danceDamage;
					if( player10.speed < 1 )
						player10.speed = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 4 ) //polka polka
		{
			actor.ctrCountdown = 8;
			danceChance = 50;
			danceDamage = 1;

			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player6.pa -= danceDamage;
					if( player6.pa < 1 )
						player6.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player7.pa -= danceDamage;
					if( player7.pa < 1 )
						player7.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player8.pa -= danceDamage;
					if( player8.pa < 1 )
						player8.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player9.pa -= danceDamage;
					if( player9.pa < 1 )
						player9.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Physical Attack!\n"; 
					player10.pa -= danceDamage;
					if( player10.pa < 1 )
						player10.pa = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 5 ) //Magic dance
		{
			actor.ctrCountdown = 8;
			danceChance = 50;
			danceDamage = 1;
			
			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player6.ma -= danceDamage;
					if( player6.ma < 1 )
						player6.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player7.ma -= danceDamage;
					if( player7.ma < 1 )
						player7.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player8.ma -= danceDamage;
					if( player8.ma < 1 )
						player8.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player9.ma -= danceDamage;
					if( player9.ma < 1 )
						player9.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					cout << "\tdance hits! -" << danceDamage << " Magic Attack!\n"; 
					player10.ma -= danceDamage;
					if( player10.ma < 1 )
						player10.ma = 1;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 6 ) //Nameless dance
		{
			actor.ctrCountdown = 10;
			danceChance = 50;
			
			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player6, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player7, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player8, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player9, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false && player10.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				namelessRoll = rand() % 8;
				if( namelessRoll == 1 )
					namelessString = "Darkness";
				else if( namelessRoll == 2)
					namelessString = "Confusion";
				else if( namelessRoll == 3)
					namelessString = "Silence";
				else if( namelessRoll == 4)
					namelessString = "Frog";
				else if( namelessRoll == 5)
					namelessString = "Poison";
				else if( namelessRoll == 6)
					namelessString = "Slow";
				else if( namelessRoll == 7)
					namelessString = "Stop";
				else if( namelessRoll == 0)
					namelessString = "Sleep";

				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";
				if( danceRoll <= danceChance )
				{
					statusSetter( player10, namelessString );
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}
		else if( actor.ctrInput == 7 ) //Last dance
		{
			actor.ctrCountdown = 20;
			danceChance = 34;
			
			if( player6.sleep == false && player6.petrify == false && player6.invite == false && player6.dead == false && player6.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player6.teamName << " " << player6.playerClassName << " " << player6.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player6.playerName << " CT set to 0!\n"; 
					player6.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player7.sleep == false && player7.petrify == false && player7.invite == false && player7.dead == false && player7.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player7.teamName << " " << player7.playerClassName << " " << player7.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player7.playerName << " CT set to 0!\n"; 
					player7.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player8.sleep == false && player8.petrify == false && player8.invite == false && player8.dead == false && player8.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << actor.ctrName << " is cast on " << player8.teamName << " " << player8.playerClassName << " " << player8.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player8.playerName << " CT set to 0!\n";  
					player8.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player9.sleep == false && player9.petrify == false && player9.invite == false && player9.dead == false && player9.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player9.teamName << " " << player9.playerClassName << " " << player9.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player9.playerName << " CT set to 0!\n";  
					player9.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
			if( player10.sleep == false && player10.petrify == false && player10.invite == false && player10.dead == false  && player10.activePlayer == true )
			{
				danceRoll = rand() % 100 + 1;
				cout << "\t" << actor.ctrName << " is cast on " << player10.teamName << " " << player10.playerClassName << " " << player10.playerName
					<< "\n" << "\tRandom Number is ... " << danceRoll << "\n";	
				if( danceRoll <= danceChance )
				{
					cout << "\t" << "Dance hits! " << player10.playerName << " CT set to 0!\n";  
					player10.ct = 0;
				}
				else cout << "\t" << actor.ctrName << " misses!\n";
			}
		}

	}// end second team loop
}

void mimeDanceFunction( MimeClass &mimeObject, Player &theMime, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Item &blueItem, Item &redItem, bool mimeDance = true )
{

	if( theMime.playerClass == 10  )
	{
		if( ( theMime.teamName == mimedUnit.teamName && theMime.charm == false ) ||
			( theMime.teamName != mimedUnit.teamName && theMime.charm == true ) )
		{
			if( theMime.dead == false && theMime.petrify == false && theMime.sleep == false
				&& theMime.stop == false && theMime.bloodSuck == false && theMime.dontAct == false
				&& theMime.frog == false && theMime.chicken == false && theMime.confusion == false
				&& theMime.berserk == false )
			{
				theMime.ctrInput = mimedUnit.ctrInput;
				theMime.ctrType = mimedUnit.ctrType;
				theMime.ctrName = mimedUnit.ctrName;

				if( mimeDance == true && theMime.ctrType == 5 )
				{
					cout << "\n"
						<< "   --- MIME ACTION ---\n"
						<< theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
						<< " attempts to mimic... \n";
					danceResolve( theMime, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, blueItem, redItem );
					
				} //should always be true

				theMime.ctrInput = 0;
				theMime.ctrType = 0;
				theMime.ctrName = "";
			}// eligible status effect
		}//charmed or not charmed
	}//player is a mime

	
}



//Knight Primary -- Battle Skill Secondary
//when reducing MA, PA, Speed, MP and dealign with threshhold amount 
	//does not display proper effect or confirm, though this may be how the game does it
class BattleSkill
{

public:
	string abilityName;
	string abilityType;
	string info;
	bool reflect;
	bool calculate;
	string elemental;
	bool counterBladeGrasp;
	bool counterMagic;
	bool counterFlood;
	bool evade;
	int magicPoints;
	int ctr; //clock ticks to resolution
	int jobPoints;
	int mod; //BMG type
	int abilityRange;
	int abilityRangeMin;
	int abilityEffect;
	int playerInput;
	int battleSkillChance;
	int battleSkillDamage;
	int confirm;

	int mimeConfirm;
	int side;
	int distance;

	BattleSkill() //can steal target empty squares or squares where no one is wearing a helmet?
	{
		abilityName = " ";
		abilityType = "physical";
		reflect = false;
		calculate = false;
		elemental = "weapon"; //not sure if this matters at all...
		counterBladeGrasp = true;
		evade = true;
		magicPoints = 0;
		ctr = 0;
		jobPoints = 0;
		mod = 4;
		abilityRange = 1;
		abilityRangeMin = 1;
		abilityEffect = 1;
		battleSkillChance = 0;
		battleSkillDamage = 0;
		confirm = 0;
	}

	void battleSkillMenu( BattleSkill &battleSkillObject, Player actor );
	void battleSkillSuccess( BattleSkill &battleSkillObject, Player &playerActor, char myArray[][11], Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem,
	Golem &blueGolem, Golem &redGolem, MimeClass &mimeObject );

};

//displays Battle Skill menu and returns player input for Battle Skill
void BattleSkill::battleSkillMenu( BattleSkill &battleSkillObject, Player actor ) 
{
	int battleSkillAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " BATTLE SKILL Menu ---\n"
		<< "0.) Return to Menu\n"
		<< "1.) Head Break -- Break Target Helmet\n"
		<< "2.) Armor Break -- Break Target Armor\n" 
		<< "3.) Shield Break -- Break Target Shield\n" 
		<< "4.) Weapon Break -- Break Target Weapon\n" 
		<< "5.) Magic Break -- Lower Target MP\n" 
		<< "6.) Speed Break -- Lower Target Speed\n"
		<< "7.) Power Break -- Lower Target PA\n"
		<< "8.) Mind Break -- Lower Target MA\n"
		)
		&& ( !(cin >> battleSkillAction ) || battleSkillAction < 0 || battleSkillAction > 8 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	battleSkillObject.playerInput = battleSkillAction;
	if( battleSkillAction == 0 )
	{
		battleSkillObject.confirm = 0;
	}
	else battleSkillObject.confirm = 2;
}

void BattleSkill::battleSkillSuccess( BattleSkill &battleSkillObject, Player &actor, char myArray[][11], Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem,
	Golem &blueGolem, Golem &redGolem, MimeClass &mimeObject )
{
	vector<int> rangeVector (2, 0);
	int battleSkillConfirm = 2;
	int baseHit = 0;
	int battleSkillRoll = 0;
	Player target;

	vector<int> mimeVector (2, 0);
	mimeObject.mimeBattleConfirm = 0;

	if( battleSkillObject.confirm == 0 )
	{
		actor.confirm = 3;
	}

	else if( battleSkillObject.confirm != 0)
	{
		do
		{
			battleSkillObject.abilityRange = actor.weaponRange;
			battleSkillObject.abilityRangeMin = actor.weaponRangeMin;
			battleSkillObject.evade = true;

			rangeVector = rangeTest( actor, battleSkillObject.abilityRange, "BATTLE SKILL", 
					battleSkillObject.abilityRangeMin, true );
			target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if ( battleSkillObject.playerInput == 1 ) //head break, chance to break opponent helmet
			{

				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 45, actor.weaponPower) + 45 + actor.weaponPower;
				if( target.head == false || target.maintenance == true )
				{
					battleSkillObject.battleSkillChance = 0;
				}
				battleSkillObject.abilityName = "Head Break";
				
				battleSkillObject.info = "-- Break Target Helmet";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				
					
				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						if( target.head == false || target.maintenance == true )
						{
							battleSkillObject.battleSkillChance = 0;
						}
					
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						if( target.head == true )
						{
							battleSkillRoll = ( rand() % 100 ) + 1;
							cout << "\tRandom Number is..." << battleSkillRoll << '\n';
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								helmetDestroyer( target );
							}
							else
							{
								cout << "\t" << battleSkillObject.abilityName << " misses!\n" << "\n";
							}
						}
						else if( target.head == false )
						{
							turnInnerAttack( actor, target, myArray, blueGolem, redGolem );
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}
			}// end Head Break section

			else if ( battleSkillObject.playerInput == 2 ) //armor break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 40, actor.weaponPower) + 40 + actor.weaponPower;
				if( target.body == false || target.maintenance == true )
				{
					battleSkillObject.battleSkillChance = 0;
				}
				battleSkillObject.abilityName = "Armor Break";
				battleSkillObject.info = "-- Break Target Armor";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						if( target.body == false || target.maintenance == true )
						{
							battleSkillObject.battleSkillChance = 0;
						}
					
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						if( target.body == true )
						{
							battleSkillRoll = ( rand() % 100 ) + 1;
							cout << "\tRandom Number is..." << battleSkillRoll << '\n';
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								armorDestroyer( target );
							}
							else
							{
								cout << "\t" << battleSkillObject.abilityName << " misses!\n" << "\n";
							}
						}
						else if( target.body == false )
						{
							turnInnerAttack( actor, target, myArray, blueGolem, redGolem );
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}

			}// end Armor Break section

			else if ( battleSkillObject.playerInput == 3 ) //shield break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 55, actor.weaponPower) + 55 + actor.weaponPower;
				if( target.offHandType != "Shield" || target.maintenance == true )
				{
					battleSkillObject.battleSkillChance = 0;
				}
				battleSkillObject.abilityName = "Shield Break";

				battleSkillObject.info = "-- Break Target Shield";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						if( target.offHandType != "Shield" || target.maintenance == true )
						{
							battleSkillObject.battleSkillChance = 0;
						}
					
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						if( target.shield == true )
						{
							battleSkillRoll = ( rand() % 100 ) + 1;
							cout << "\tRandom Number is..." << battleSkillRoll << '\n';
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								shieldDestroyer( target );
							}
							else
							{
								cout << "\t" << battleSkillObject.abilityName << " misses!\n" << "\n";
							}
						}
						else if( target.shield == false )
						{
							turnInnerAttack( actor, target, myArray, blueGolem, redGolem );	
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}
			}// end Shield Break section

			else if ( battleSkillObject.playerInput == 4 ) //weapon break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 30, actor.weaponPower) + 30 + actor.weaponPower;
				if( target.weapon == false || target.maintenance == true )
				{
					battleSkillObject.battleSkillChance = 0;
				}
				battleSkillObject.abilityName = "Weapon Break";
				battleSkillObject.info = "-- Break Target Weapon";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						if( target.weapon == false || target.maintenance == true )
						{
							battleSkillObject.battleSkillChance = 0;
						}
					
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						if( target.weapon == true )
						{
							battleSkillRoll = ( rand() % 100 ) + 1;
							cout << "\tRandom Number is..." << battleSkillRoll << '\n';
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								weaponDestroyer( target );
							}
							else
							{
								cout << "\t" << battleSkillObject.abilityName << " misses!\n" << "\n";
							}
						}
						else if( target.offHandWeapon == true && target.offHandType != "Shield" )
						{
							battleSkillRoll = ( rand() % 100 ) + 1;
							cout << "\tRandom Number is..." << battleSkillRoll << '\n';
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								shieldDestroyer( target );
							}
							else
							{
								cout << "\t" << battleSkillObject.abilityName << " misses!\n" << "\n";
							}
						}
						else
						{
							turnInnerAttack( actor, target, myArray, blueGolem, redGolem );	
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}
			}// end Weapon Break section

			else if ( battleSkillObject.playerInput == 5) //magic break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 50 ) + 50;
				battleSkillObject.battleSkillDamage = ( target.maxMP/2 + ( target.maxMP % 2 ) );
				battleSkillObject.abilityName = "Magic Break";
				battleSkillObject.info = "-- Lower Target MP by half of Max MP";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						battleSkillRoll = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << battleSkillRoll << '\n';
						if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
						{
							if( target.mp <= battleSkillObject.battleSkillDamage )
							{
								target.mp = 0;
							}
							else
							{
								target.mp -= battleSkillObject.battleSkillDamage;
							}
						
							cout << target.teamName << " " << target.playerClassName << " "
								<< target.playerName <<"'s MP is reduced!\n" << '\n';
						}
						else
						{
							cout << battleSkillObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}
			
			}// end Magic Break section

			else if ( battleSkillObject.playerInput == 6 ) //speed break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 50 ) + 50;
				battleSkillObject.battleSkillDamage = 2;
				battleSkillObject.abilityName = "Speed Break";
				battleSkillObject.info = "-- Lower target Speed by 2";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						battleSkillRoll = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << battleSkillRoll << '\n';
						if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
						{
							if( target.speed > 2 )
							{
								target.speed -= battleSkillObject.battleSkillDamage;
							}
							else if ( target.speed == 2 )
							{
								target.speed = 1;
							}
							cout << "\t" << target.teamName << " " << target.playerClassName << " "
								<< target.playerName <<"'s Speed is reduced by 2!\n";
						}
						else
						{
							cout << battleSkillObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}

			}// end Speed Break section

			else if ( battleSkillObject.playerInput == 7 ) //power break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 50 ) + 50;
				battleSkillObject.battleSkillDamage = 3;
				battleSkillObject.abilityName = "Power Break";
				battleSkillObject.info = "-- Lower target PA by 3";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						battleSkillRoll = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << battleSkillRoll << '\n';
						if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
						{
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								if( target.pa > 3 )
								{
									target.pa -= battleSkillObject.battleSkillDamage;
								}
								else if ( ( target.pa <=3 ) || ( target.pa >= 1 ) )
								{
									target.pa = 1;
								}
						
								cout << "\t" << target.teamName << " " << target.playerClassName << " "
									<< target.playerName <<"'s PA is reduced by 3!\n";
							}
						}
						else
						{
							cout << battleSkillObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}
			
			}// end Power Break section

			else if ( battleSkillObject.playerInput == 8 ) //mind break
			{
				battleSkillObject.battleSkillChance = mod3( actor, target, actor.pa, 50 ) + 50;
				battleSkillObject.battleSkillDamage = 3;
				battleSkillObject.abilityName = "Mind Break";
				battleSkillObject.info = "-- Lower target MA by 3";
				battleSkillConfirm = targetDisplay( target, battleSkillObject.abilityName, battleSkillObject.battleSkillChance,
					0, battleSkillObject.info, true );

				if( battleSkillConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, battleSkillObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					}
					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol ) 
					{
						battleSkillObject.battleSkillChance = counterGraspEvade( battleSkillObject.battleSkillChance,
							actor, target );

						battleSkillRoll = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << battleSkillRoll << '\n';
						if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
						{
							if ( battleSkillRoll <= battleSkillObject.battleSkillChance )
							{
								if( target.ma > 3 )
								{
									target.ma -= battleSkillObject.battleSkillDamage;
								}
								else if ( ( target.ma <=3 ) || ( target.ma >= 1 ) )
								{
									target.ma = 1;
								}
								cout << "\t" << target.teamName << " " << target.playerClassName << " "
									<< target.playerName <<"'s MA is reduced by 3!\n";
							}
						}
						else
						{
							cout << battleSkillObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer);
					}
				}

			}// end Mind Break section

			if( battleSkillConfirm == 1)
			{
				mimeObject.mimeBattleConfirm = 1;
				mimeObject.abilityName = battleSkillObject.abilityName;
				vector<int> mimeVector (2 , 0);
				mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor);
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
				mimeObject.playerInput = battleSkillObject.playerInput;
			}
		} while( battleSkillConfirm == 2);
	} //ends if loop
	if( battleSkillConfirm == 3)
	{
		actor.confirm = 3;
	}
}



void innerMimeBattleFunction(MimeClass &mimeObject )
{
	mimeObject.mod = 3;
	mimeObject.effect = 1;
	mimeObject.evade = true;

	if( mimeObject.playerInput == 1 )
	{
		mimeObject.abilityName = "Head Break";
		mimeObject.component = 45;
	}
	else if( mimeObject.playerInput == 2 )
	{
		mimeObject.abilityName = "Armor Break";
		mimeObject.component = 40;
	}
	else if( mimeObject.playerInput == 3 )
	{
		mimeObject.abilityName = "Shield Break";
		mimeObject.component = 55;
	}
	else if( mimeObject.playerInput == 4 )
	{
		mimeObject.abilityName = "Weapon Break";
		mimeObject.component = 30;
	}
	else if( mimeObject.playerInput == 5 )
	{
		mimeObject.abilityName = "Magic Break";
		mimeObject.component = 50;
	}
	else if( mimeObject.playerInput == 6 )
	{
		mimeObject.abilityName = "Speed Break";
		mimeObject.component = 50;
		mimeObject.damage = 2;
	}
	else if( mimeObject.playerInput == 7 )
	{
		mimeObject.abilityName = "Power Break";
		mimeObject.component = 50;
		mimeObject.damage = 3;
	}
	else if( mimeObject.playerInput == 8 )
	{
		mimeObject.abilityName = "Mind Break";
		mimeObject.component = 50;
		mimeObject.damage = 3;
	}
}

void mimeBattleDamage( Player &theMime, MimeClass &mimeObject, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	vector<int> targetVec (2, 0);
	bool hamedoTest = false;
	int targetDamage = 0;

	targetVec = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts "<< mimeObject.abilityName << " on (" << targetVec[0]-1 << ", " << targetVec[1]-1 << ")...\n";

	targetVec = rangeCollision( theMime.currentRow, theMime.currentCol, targetVec[0], targetVec[1],
		myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
		player10, nullPlayer, mimeObject.abilityName );
	target = targetFunction( targetVec[0], targetVec[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
	

	if( target.dead == false && target.petrify == false && target.nullPlayer == false )
	{
		hitRoll = rand() % 100 + 1;

		weaponCopier( theMime, mimedUnit );
	
		if( mimeObject.playerInput >=1 && mimeObject.playerInput <= 4)
		{
			mimeObject.chance = mod3( theMime, target, theMime.pa, mimeObject.component, theMime.weaponPower ) + mimeObject.component + theMime.weaponPower;
		}
		else
		{
			mimeObject.chance = mod3( theMime, target, theMime.pa, mimeObject.component, theMime.weaponPower ) + mimeObject.component;
		}
		mimeObject.chance = counterGraspEvade( mimeObject.chance, theMime, target );
		if( target.maintenance == true )
			mimeObject.chance = 0;
		if( mimeObject.playerInput == 1 && target.head == false )
			mimeObject.chance = 0;
		if( mimeObject.playerInput == 2 && target.body == false )
			mimeObject.chance = 0;
		if( mimeObject.playerInput == 3 && target.offHandType != "Shield" )
			mimeObject.chance = 0;
		if( mimeObject.playerInput == 4 && target.weapon == false && target.offHand == false )
			mimeObject.chance = 0;

		cout << "   " << mimeObject.abilityName << " targets " <<target.teamName << " " << target.playerClassName << " " << target.playerName << "\n";
		cout << "   " << mimeObject.abilityName << " chance to hit is " << mimeObject.chance << "%. Random number is..." << hitRoll << "\n";
		
		if( target.maintenance == false && mimeObject.playerInput >= 1 && mimeObject.playerInput <= 4 && mimeObject.chance == 0 )
		{
			hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
						player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

			if( hamedoTest == false )
			{
				targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );

				hpReaction( target, blueItem, redItem, theMime, targetDamage );
				if( targetDamage > 0 )
				{
					distributeReaction( target, theMime, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, targetDamage );
				}
				if( theMime.weaponType != "Magic Gun" )
				{
					counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
				}
				else
				{
					magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				}
			}
		}
		else if( hitRoll <= mimeObject.chance )
		{
			if( mimeObject.playerInput == 1 )
			{	
				if( target.head == true )
				{
					helmetDestroyer( target );
				}
				else
				{
					hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
						player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

					if( hamedoTest == false )
					{
						targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );

						hpReaction( target, blueItem, redItem, theMime, targetDamage );
						if( targetDamage > 0 )
						{
							distributeReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, targetDamage );
						}
						if( theMime.weaponType != "Magic Gun" )
						{
							counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
						}
						else
						{
							magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
						}
					}
				}
			}
			else if( mimeObject.playerInput == 2 )
			{
				if( target.body == true )
				{
					armorDestroyer( target );
				}
				else
				{
					hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
						player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

					if( hamedoTest == false )
					{
						targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );

						hpReaction( target, blueItem, redItem, theMime, targetDamage );
						if( targetDamage > 0 )
						{
							distributeReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, targetDamage );
						}
						if( theMime.weaponType != "Magic Gun" )
						{
							counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
						}
						else
						{
							magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
						}
					}
				}

			}
			else if( mimeObject.playerInput == 3 )
			{
				if( target.offHandType == "Shield" )
				{
					shieldDestroyer( target );
				}
				else
				{
					hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
						player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

					if( hamedoTest == false )
					{
						targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );

						hpReaction( target, blueItem, redItem, theMime, targetDamage );
						if( targetDamage > 0 )
						{
							distributeReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, targetDamage );
						}
						if( theMime.weaponType != "Magic Gun" )
						{
							counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
						}
						else
						{
							magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
						}
					}
				}
			}
			else if( mimeObject.playerInput == 4 )
			{
				if( target.weapon == true )
				{
					weaponDestroyer( target );
				}
				else if( target.offHand == true && target.offHandType != "Shield" )
				{
					shieldDestroyer( target );
				}
				else
				{
					hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
						player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

					if( hamedoTest == false )
					{
						targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );

						hpReaction( target, blueItem, redItem, theMime, targetDamage );
						if( targetDamage > 0 )
						{
							distributeReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, targetDamage );
						}
						if( theMime.weaponType != "Magic Gun" )
						{
							counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
						}
						else
						{
							magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			
						}
					}
				}
			}
			else if( mimeObject.playerInput == 5 )
			{
				mimeObject.damage = -target.mp / 2 + - target.mp % 2;
				mpDamage( target, mimeObject.damage );
			}
			else if( mimeObject.playerInput == 6 )
			{
				if( target.speed > 2 )
				{
					target.speed -= mimeObject.damage;
				}
				else if ( target.speed == 2 )
				{
					target.speed = 1;
				}
				cout << "\t" << target.teamName << " " << target.playerClassName << " "
					<< target.playerName <<"'s Speed is reduced by 2!\n";
			}
			else if( mimeObject.playerInput == 7 )
			{
				if( target.pa > 3 )
				{
					target.pa -= mimeObject.damage;
				}
				else if ( ( target.pa <=3 ) || ( target.pa >= 1 ) )
				{
					target.pa = 1;
				}
						
				cout << "\t" << target.teamName << " " << target.playerClassName << " "
					<< target.playerName <<"'s PA is reduced by 3!\n";
			}
			else if( mimeObject.playerInput == 8 )
			{
				if( target.ma > 3 )
				{
					target.ma -= mimeObject.damage;
				}
				else if ( ( target.ma <=3 ) || ( target.ma >= 1 ) )
				{
					target.ma = 1;
				}
				cout << "\t" << target.teamName << " " << target.playerClassName << " "
					<< target.playerName <<"'s MA is reduced by 3!\n";
			}
		}
		else cout << "\tmisses!\n";
		weaponUnCopy( theMime );
		counterGraspReaction( theMime, target, myArray, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
			redGolem );
		endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );
	}
	else cout << "\tand it has no effect.";

}

