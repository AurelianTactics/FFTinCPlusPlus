class MimeClass
{
public:

	//attributes
	int playerInput;
	int damage;
	int effect;
	int chance;
	int mod;
	int ctrType;
	int component;
	string abilityName;
	string display;
	string status;
	bool evade;
	bool cure;
	bool targetActor;

	int mimeAttackConfirm;
	int attackSide;
	int attackDistance;
	
	int mimeChargeConfirm;
	int chargeSide;
	int chargeDistance;
	int ctrK;

	int mimeElementalConfirm;
	int elementalSide;
	int elementalDistance;

	//for spells, effect, mod, ability, name, evade, cure, damage, chance, component, and status are above
	int mimeSpellConfirm;
	int spellSide;
	int spellDistance;
	bool reflect;
	bool summonTypeAlly; //ie can only hit enemies/allies
	bool summonTypeEnemy;
	bool ignoreDead; //lets spell target dead
	bool ignorePetrify; //lets spell target petrified units
	bool fireType;
	bool iceType;
	bool lightningType;
	bool waterType;
	bool earthType;
	bool windType;
	bool holyType;
	bool darkType;
	bool casterImmune;
	bool counterMagic;

	int mimePunchConfirm;
	int side; //used for punch, talk, draw
	int distance; //used for punch, talk, draw
	bool punchCrit;
	bool punchStatus;
	int punchMP;

	int mimeTalkConfirm;
	int mimeBattleConfirm;
	int mimeBasicConfirm;
	int mimeDrawConfirm;
	int mimeItemConfirm;

	int mimeThrowConfirm;
	//for throw elementals
	bool fireBool;
	bool iceBool;
	bool lightningBool;
	bool waterBool;
	bool earthBool;
	bool windBool;
	bool holyBool;
	bool darkBool;
	int throwWeaponPower;
	
	MimeClass()
	{
		//coding
		
	}
	~MimeClass() {}

};


void innerDistribute( Player &target, int cureAmount )
{
	target.life += cureAmount;
	if( target.life > target.maxLife )
		target.life = target.maxLife;
	cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " gains " << cureAmount << " HP!\n";
}


void distributeReaction( Player &target, Player&actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, int cureAmount = 0)
{
	int excess = 0;
	int eligibleUnits = 0;
	int roundUp = 0;
	int braveRoll = 0;
	int targetTempLife = 0;
	bool player1Eligible = false;
	bool player2Eligible = false;
	bool player3Eligible = false;
	bool player4Eligible = false;
	bool player5Eligible = false;
	bool player6Eligible = false;
	bool player7Eligible = false;
	bool player8Eligible = false;
	bool player9Eligible = false;
	bool player10Eligible = false;

	targetTempLife = target.life;

	//innerDistribute( target, cureAmount );

	if(  target.bloodSuck == false && target.chicken == false && target.confusion == false
		&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
		&& target.berserk == false && target.dontAct == false && target.sleep == false  ) //can't counter if blood sucked
	{
		if( target.distribute == true && actor.turnOrder != target.turnOrder )
		{
			if( cureAmount + targetTempLife > target.maxLife )
			{
				braveRoll = rand() % 100 + 1;
				if( braveRoll <= target.brave )
				{
					cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< "'s " << target.reaction << " triggers!\n";
					excess = cureAmount + targetTempLife - target.maxLife;
					if( target.teamName == "Blue" )
					{
						if( target.turnOrder != player1.turnOrder && player1.dead == false &&
							player1.petrify == false && player1.life < player1.maxLife )
						{
							eligibleUnits += 1;
							player1Eligible = true;
						}
						if( target.turnOrder != player2.turnOrder && player2.dead == false &&
							player2.petrify == false && player2.life < player2.maxLife )
						{
							eligibleUnits += 1;
							player2Eligible = true;
						}
						if( target.turnOrder != player3.turnOrder && player3.dead == false &&
							player3.petrify == false && player3.life < player3.maxLife )
						{
							eligibleUnits += 1;
							player3Eligible = true;
						}

						if( target.turnOrder != player4.turnOrder && player4.dead == false &&
							player4.petrify == false && player4.life < player4.maxLife )
						{
							eligibleUnits += 1;
							player4Eligible = true;
						}
						if( target.turnOrder != player5.turnOrder && player5.dead == false &&
							player5.petrify == false && player5.life < player5.maxLife )
						{
							eligibleUnits += 1;
							player5Eligible = true;
						}
					}//check blue team
					else if( target.teamName == "Red" )
					{
						if( target.turnOrder != player6.turnOrder && player6.dead == false &&
							player6.petrify == false && player6.life < player6.maxLife )
						{
							eligibleUnits += 1;
							player6Eligible = true;
						}
						if( target.turnOrder != player7.turnOrder && player7.dead == false &&
							player7.petrify == false && player7.life < player7.maxLife )
						{
							eligibleUnits += 1;
							player7Eligible = true;
						}
						if( target.turnOrder != player8.turnOrder && player8.dead == false &&
							player8.petrify == false && player8.life < player8.maxLife )
						{
							eligibleUnits += 1;
							player8Eligible = true;
						}
						if( target.turnOrder != player9.turnOrder && player9.dead == false &&
							player9.petrify == false && player9.life < player9.maxLife )
						{
							eligibleUnits += 1;
							player9Eligible = true;
						}
						if( target.turnOrder != player10.turnOrder && player10.dead == false &&
							player10.petrify == false && player10.life < player10.maxLife )
						{
							eligibleUnits += 1;
							player10Eligible = true;
						}
					}//check red team
					if( excess % eligibleUnits != 0 )
						roundUp = 1;
					excess = excess / eligibleUnits + roundUp;
					if( player1Eligible == true )
						innerDistribute( player1, excess );
					if( player2Eligible == true )
						innerDistribute( player2, excess );
					if( player3Eligible == true )
						innerDistribute( player3, excess );
					if( player4Eligible == true )
						innerDistribute( player4, excess );
					if( player5Eligible == true )
						innerDistribute( player5, excess );
					if( player6Eligible == true )
						innerDistribute( player6, excess );
					if( player7Eligible == true )
						innerDistribute( player7, excess );
					if( player8Eligible == true )
						innerDistribute( player8, excess );
					if( player9Eligible == true )
						innerDistribute( player9, excess );
					if( player10Eligible == true )
						innerDistribute( player10, excess );
				}//distribute roll
				else cout << "\t" << "\t" << "Reaction ability fails to trigger\n!";
			}//heals in excess of max life
		}// not healing self
	}//not inflicted with a reaction ability that will prevent being reaction ability triggered
}

//special hpdamage for using items, undead will not use reaction abilities
void hpDamageItem( Player &target, Player &actor, int damage, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, bool cure = false, bool twoSwordsAttack = false )
{
	if( damage < 0 )
	{
		target.life += damage;

		if( target.life <= 0 )
		{
			statusSetter( target, "Dead");
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " takes " << -damage << " and dies!\n";
		}
		else if( target.life > 0 )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " loses " << -damage << " HP!\n";
			if( twoSwordsAttack == false )
			{
				
			}
			confusionOff( target );
		}
	}
	else if( damage > 0 )
	{
		distributeReaction( target, actor, player1, player2, player3, player4, player5, player6, player7,
			player8, player9, player10, damage );
		target.life += damage;
		if( target.life > target.maxLife )
			target.life = target.maxLife;
		cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " gains " << damage << " HP!\n";
		
	}

	if( target.undead == true && cure == true )
	{
		target.life -= damage;

		if( target.life <= 0 )
		{
			statusSetter( target, "Dead");
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " has died!\n";
		}
		else if( target.life > 0 )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " loses " << damage << " HP!\n";
			confusionOff( target );
		}
	}
}

//can items be used on empty squares?
//can items be used on people with no effect (ie eye drops on someone with no darkness)
	//potion on someone with max life etc
//this has to be placed before HP Reaction Function
class Item
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
	int abilityChance;
	int abilityEffect;
	int playerInput;
	int itemChance;
	int itemLife;
	int confirm;

	int side;
	int distance;
	int mimeConfirm;

	//usable items
	int potion;
	int hiPotion;
	int xPotion;
	int ether;
	int hiEther;
	int elixir;
	int antidote;
	int eyeDrop;
	int echoGrass;
	int maidensKiss;
	int soft;
	int holyWater;
	int remedy;
	int phoenixDown;

	//can item target an empty square?
	Item() 
	{
		abilityName = "";
		abilityType = "NULL";
		reflect = false;
		calculate = false;
		elemental = "NULL";
		counterBladeGrasp = false;
		evade = false;
		magicPoints = 0;
		ctr = 0;
		jobPoints = 0;
		mod = 0;
		abilityRange = 1; //set to 4 if chemist or if throw item
		abilityRangeMin = 0; //see if this works
		abilityEffect = 1;
		itemChance = 100;
		itemLife = 0;
		confirm = 2;

		//item stock
		potion = 30;
		hiPotion = 20;
		xPotion = 10;
		ether = 10;
		hiEther = 10;
		elixir = 1;
		antidote = 10;
		eyeDrop = 10;
		echoGrass = 10;
		maidensKiss = 10;
		soft = 10;
		holyWater = 10;
		remedy = 10;
		phoenixDown = 10;
	}

	void itemMenu( Item &itemObject, Player actor );
	void itemSuccess( Item &itemObject, Player &playerActor, char myArray[][11],
	Player &player1, Player &player2, Player &player3, Player &player4, Player &player5,
	 Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	 Player &nullPlayer, MimeClass &mimeObject );
};

void Item::itemMenu( Item &itemObject, Player actor )
{
	int itemAction = 0; 
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " ITEM Menu ---\n" 
		<< "0.) Return to Menu\n"
		<< "1.) Potion:\t" << "\t" << itemObject.potion << " remaining\n"
		<< "2.) Hi-Potion:\t" << '\t' << itemObject.hiPotion << " remaining\n" 
		<< "3.) X-Potion:\t" << '\t' << itemObject.xPotion << " remaining\n"
		<< "4.) Ether:\t" << '\t' << itemObject.ether << " remaining\n" 
		<< "5.) Hi-Ether:\t" << '\t' << itemObject.hiEther << " remaining\n"
		<< "6.) Elixir:\t" << '\t' << itemObject.elixir << " remaining\n" 
		<< "7.) Antidote:\t" << '\t' << itemObject.antidote << " remaining\n"
		<< "8.) Eye Drop:\t" << '\t' << itemObject.eyeDrop << " remaining\n" 
		<< "9.) Echo Grass:\t" << '\t' << itemObject.echoGrass << " remaining\n"
		<< "10.) Maiden's Kiss:\t" << itemObject.maidensKiss << " remaining\n"
		<< "11.) Soft:\t" << '\t' << itemObject.soft << " remaining\n" 
		<< "12.) Holy Water:\t" << itemObject.holyWater << " remaining\n"
		<< "13.) Remedy:\t" << '\t' << itemObject.remedy << " remaining\n" 
		<< "14.) Phoenix Down:\t" << itemObject.phoenixDown << " remaining\n" )
		&& ( !(cin >> itemAction)
		|| ( ( itemAction == 1 ) && ( itemObject.potion <= 0 ) )
		|| ( ( itemAction == 2 ) && ( itemObject.hiPotion <= 0 ) )
		|| ( ( itemAction == 3 ) && ( itemObject.xPotion <= 0 ) )
		|| ( ( itemAction == 4 ) && ( itemObject.ether <= 0 ) )
		|| ( ( itemAction == 5 ) && ( itemObject.hiEther <= 0 ) )
		|| ( ( itemAction == 6 ) && ( itemObject.elixir <= 0 ) )
		|| ( ( itemAction == 7 ) && ( itemObject.antidote <= 0 ) )
		|| ( ( itemAction == 8 ) && ( itemObject.eyeDrop <= 0 ) )
		|| ( ( itemAction == 9 ) && ( itemObject.echoGrass <= 0 ) )
		|| ( ( itemAction == 10 ) && ( itemObject.maidensKiss <= 0 ) )
		|| ( ( itemAction == 11 ) && ( itemObject.soft <= 0 ) )
		|| ( ( itemAction == 12 ) && ( itemObject.holyWater <= 0 ) )
		|| ( ( itemAction == 13 ) && ( itemObject.remedy <= 0 ) )
		|| ( ( itemAction == 14 ) && ( itemObject.phoenixDown <= 0 ) )
		|| itemAction > 14 || itemAction < 0 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
		itemObject.playerInput = itemAction;
		if( itemAction == 0)
		{
			itemObject.confirm = 0;
		}
		else itemObject.confirm = 2;
}

void Item::itemSuccess( Item &itemObject, Player &actor, char myArray[][11],
	Player &player1, Player &player2, Player &player3, Player &player4, Player &player5,
	 Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	 Player &nullPlayer, MimeClass &mimeObject )
{
	vector<int> rangeVector (2, 0);
	int itemConfirm = 2;
	itemObject.abilityChance = 100;

	itemObject.side = 0;
	itemObject.distance = 0;
	itemObject.mimeConfirm = 0;
	vector<int> mimeVector (2, 0);
	
	mimeObject.mimeItemConfirm = 0;
	Player target;

	if( actor.playerClass == 4 || actor.throwItem == true )
	{
		itemObject.abilityRange = 4; //default is 1
	}
	else itemObject.abilityRange = 1;

	if( itemObject.confirm == 0 )
	{
		actor.confirm = 3;
	}

	if(itemObject.confirm != 0 )
	{
		do
		{
			if ( ( itemObject.playerInput == 1 ) && ( itemObject.potion > 0 ) ) //use a potion
			{
				itemObject.abilityName = "Potion";
				itemObject.itemLife = 30;
				itemObject.info = "-- HP +";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true )
					itemObject.abilityChance = 0;
				if(target.undead == true )
					itemObject.itemLife *= -1;
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance, itemObject.itemLife,
					itemObject.info ); 
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;
					if(target.undead == true )
						itemObject.itemLife = -30;
					else itemObject.itemLife = 30;

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
				
					
						if( target.dead == false && target.petrify == false )
						{
							hpDamageItem( target, actor, itemObject.itemLife, player1, player2, player3,
								player4, player5, player6, player7, player8, player9, player10, true );
						}
						itemObject.potion--;
						endTarget( target, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, nullPlayer );
					
					}
				}
			} //end potion choice

			else if( ( itemObject.playerInput == 2 ) && ( itemObject.hiPotion > 0 ) ) //choose hi potion
			{
				itemObject.abilityName = "Hi-Potion";
				itemObject.itemLife = 70;
				itemObject.info = "-- HP +";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true )
					itemObject.abilityChance = 0;
				if(target.undead == true )
					itemObject.itemLife *= -1;
				itemObject.info = " -- HP +";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;
					if(target.undead == true )
						itemObject.itemLife = -70;
					else itemObject.itemLife = 70;

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							hpDamageItem( target, actor, itemObject.itemLife, player1, player2, player3,
								player4, player5, player6, player7, player8, player9, player10, true );
						}
						itemObject.hiPotion--;
						endTarget( target, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end hi potion choice

			else if( ( itemObject.playerInput == 3 ) && ( itemObject.xPotion > 0 ) ) //choose x potion
			{
				itemObject.abilityName = "X-Potion";
				itemObject.itemLife = 150;

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true )
					itemObject.abilityChance = 0;
				if(target.undead == true )
					itemObject.itemLife *= -1;
				itemObject.info = "-- HP +";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;
					if(target.undead == true )
						itemObject.itemLife = -150;
					else itemObject.itemLife = 150;

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							hpDamageItem( target, actor, itemObject.itemLife, player1, player2, player3,
								player4, player5, player6, player7, player8, player9, player10, true );
						}
						itemObject.xPotion--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end x potion choice

			else if( ( itemObject.playerInput == 4 ) && ( itemObject.ether > 0 ) ) //choose ether
			{
				itemObject.abilityName = "Ether";
				itemObject.itemLife = 20;
				
				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
				itemObject.info = "-- MP +";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;
					
					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							target.mp += itemObject.itemLife;
							if ( target.mp > target.maxMP )
							{
								target.mp = target.maxMP;
							}
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " MP +20!\n";
						}
						itemObject.ether--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}

			} //end ether choice

			else if( ( itemObject.playerInput == 5 ) && ( itemObject.hiEther > 0 ) ) //choose  hi ether
			{
				itemObject.abilityName = "Hi-Ether";
				itemObject.itemLife = 50;

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true )
					itemObject.abilityChance = 0;
				itemObject.info = "-- MP +";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							target.mp += itemObject.itemLife;
							if ( target.mp > target.maxMP )
							{
								target.mp = target.maxMP;
							}
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " MP +50!\n";
						}
						itemObject.hiEther--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}

			} //end hi ether choice

			else if( ( itemObject.playerInput == 6 ) && ( itemObject.elixir > 0 ) ) //choose elixir
			{
				itemObject.abilityName = "Elixir";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true )
					itemObject.abilityChance = 0;
				itemObject.info = "-- HP & MP to full";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;


					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							target.mp = target.maxMP;
							target.life = target.maxLife;
							cout << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " Life & MP restored to full!\n";
						}
						itemObject.elixir--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}

			} //end elixir

			else if( ( itemObject.playerInput == 7 ) && ( itemObject.antidote > 0 ) ) //choose antidote
			{
				itemObject.abilityName = "Antidote";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.petrify == true || target.dead == true || target.poison == false )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Poison";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
					if( target.petrify == true || target.dead == true )
						itemObject.abilityChance = 0;
					else itemObject.abilityChance = 100;

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							target.poison = false;
							cout << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " is no longer suffering from Poison!\n";
						
						}
						itemObject.antidote--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end antidote

			else if( ( itemObject.playerInput == 8 ) && ( itemObject.eyeDrop > 0 ) ) //use eyedrop
			{
				itemObject.abilityName = "Eye Drop";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true || target.darkness == false )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Darkness";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
							target.darkness = false;
							cout << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " is no longer suffering from Darkness!\n";
						}
						itemObject.eyeDrop--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
				
			} //end eye drop

			else if( ( itemObject.playerInput == 9 ) && ( itemObject.echoGrass > 0 ) ) //use echo grass
			{
				itemObject.abilityName = "Echo Grass";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.petrify == true || target.dead == true || target.silence == false )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Silence";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
						target.silence = false;
						cout << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is no longer suffering from Silence!\n";
						}
						itemObject.echoGrass--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}

			} //end echo drop

			else if( ( itemObject.playerInput == 10 ) && ( itemObject.maidensKiss > 0 ) ) //use maiden kiss
			{
				itemObject.abilityName = "Maiden's Kiss";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true || target.frog == false )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Frog";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
						target.frog = false;
						cout << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is no longer suffering from Frog!\n";
						}
						itemObject.maidensKiss--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
				
			} //end maiden's kiss

			else if( ( itemObject.playerInput == 11 ) && ( itemObject.soft > 0 ) ) //use soft
			{
				itemObject.abilityName = "Soft";
				
				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == false || target.dead == true )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Petrify";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false )
						{
						target.petrify = false;
						cout << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is no longer suffering from Petrify!\n";
						}
						itemObject.soft--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end soft

			else if( ( itemObject.playerInput == 12 ) && ( itemObject.holyWater > 0 ) ) //use holy water
			{
				itemObject.abilityName = "Holy Water";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == true || ( target.undead == false && target.bloodSuck == false ) )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Undead & Blood Suck";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false && target.petrify == false )
						{
						target.undead = false;
						target.bloodSuck = false;
						cout << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is no longer suffering from Undead and Blood Suck!\n";
						}
						itemObject.holyWater--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}

			} //end holy water

			else if( ( itemObject.playerInput == 13 ) && ( itemObject.remedy > 0 ) ) //use remedy
			{
				itemObject.abilityName = "Remedy";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.dead == true )
					itemObject.abilityChance = 0;
				itemObject.info = "-- Cure Petrify/Darkness/Conf/Silence/Oil/Frog/Poison/Sleep";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						if( target.dead == false )
						{
						target.petrify = false;
						target.darkness = false;
						target.confusion = false;
						target.silence = false;
						target.oil = false;
						target.frog = false;
						target.poison = false;
						target.sleep = false;
						cout << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is cured!\n";
						}
						itemObject.remedy--;
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end remedy

			else if( ( itemObject.playerInput == 14 ) && ( itemObject.phoenixDown > 0 ) ) //use phoenix down
			{
				itemObject.abilityName = "Phoenix Down";

				rangeVector = rangeTest( actor, itemObject.abilityRange, itemObject.abilityName, 
					itemObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.petrify == true || target.dead == false )
					itemObject.abilityChance = 0;
				if( target.dead == true )
					itemObject.abilityChance = 100;
				itemObject.info = "-- Cure Dead";
				itemConfirm = targetDisplay( target, itemObject.abilityName, itemObject.abilityChance,
					itemObject.itemLife, itemObject.info, true );
				
				if( itemConfirm == 1 )
				{
					rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
						myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
						player10, nullPlayer, itemObject.abilityName );
					target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == true )
					{
						tLine( actor );
						cout << " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1 << ") but no one is hit...\n";
					}

					else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
					{
						itemObject.phoenixDown--;
						if( target.dead == true )
						{
							target.dead = false;
							target.life = ( rand() % 20 ) + 1;
							cout << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " is no brought back to life with " << target.life << " Life!\n";
						}
						else cout << "Phoenix Down has no effect!   \"...I'm, I'm not quite dead, sir\"\n";
						endTarget( target, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end phoenix down
			if( itemConfirm == 1)
			{
				mimeObject.mimeItemConfirm = 1;
				mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor );
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
				mimeObject.abilityName = itemObject.abilityName;
				mimeObject.playerInput = itemObject.playerInput;
			}
		}while(itemConfirm == 2);
	} //end select item part
	if(itemConfirm == 3)
	{
		actor.confirm = 3;
	}
}


void autoPotionReaction( Player &target, Item &colorItem )
{
	int potionLife = 0;

	if( target.level >= 45 )
	{
		if( colorItem.xPotion > 0 )
		{
			potionLife = 150;
			--colorItem.xPotion;
		}
		else if( colorItem.hiPotion > 0 )
		{
			potionLife = 70;
			--colorItem.hiPotion;
		}
		else if( colorItem.potion > 0 )
		{
			potionLife = 30;
			--colorItem.potion;
		}
		else
		{
			potionLife = 0;
		}
	}
	else if( target.level > 19 )
	{
		if( colorItem.hiPotion > 0 )
		{
			potionLife = 70;
			--colorItem.hiPotion;
		}
		else if( colorItem.potion > 0 )
		{
			potionLife = 30;
			--colorItem.potion;
		}
		else if( colorItem.xPotion > 0 )
		{
			potionLife = 150;
			--colorItem.xPotion;
		}
		else
		{
			potionLife = 0;
		}
	}
	else
	{
		if( colorItem.potion > 0 )
		{
			potionLife = 30;
			--colorItem.potion;
		}
		else if( colorItem.hiPotion > 0 )
		{
			potionLife = 70;
			--colorItem.hiPotion;
		}
		else if( colorItem.xPotion > 0 )
		{
			potionLife = 150;
			--colorItem.xPotion;
		}
		else
		{
			potionLife = 0;
		}
	}
	
	if( target.undead == true )
		potionLife *= -1;

	target.life += potionLife;

	if( target.life > target.maxLife )
	{
		target.life = target.maxLife;
	}
		
	cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n"
		<< "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
		<< " gains " << potionLife << " HP!\n";
}

void hpReaction( Player &target, Item &blueItem, Item &redItem, Player &actor, int damage )
{
	int criticalCheck = 0;
	int roundUpFlag = 0;
	int braveRoll = 0;
	int distance = 0;

	//checks for critical status
	if( target.maxLife % 5 != 0 )
		roundUpFlag = 1;
	
	criticalCheck = target.maxLife/5 + roundUpFlag;

	if( target.life <= criticalCheck )
	{
		target.critical = true;
	}
	else target.critical = false;
	
	if( target.bloodSuck == false && target.chicken == false && target.confusion == false
		&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
		&& target.berserk == false && target.dontAct == false && target.sleep == false && damage < 0 ) //targets with blood suck can't react
	{
		if( target.autoPotion == true )
		{
			if( target.teamName == "Blue" )
			{
				braveRoll = ( rand() % 100 ) + 1;
				if( braveRoll <= target.brave )
				{
					autoPotionReaction( target, blueItem );
				}
				else
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
				}
			}
			else
			{
				braveRoll = ( rand() % 100 ) + 1;
				if( braveRoll <= target.brave )
				{
					autoPotionReaction( target, redItem );
				}
				else
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
				}
			}
		}
		else if( target.caution == true )
		{
			braveRoll = ( rand() % 100 ) + 1;
			if(braveRoll <= target.brave)
			{
				target.defending = true;
				cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n"
					<< "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " is now defending!\n";
			}
			else
			{
				cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
		else if( target.speedSave == true ) //player gains 1 speed
		{
			braveRoll = ( rand() % 100 ) + 1;
			if(braveRoll <= target.brave)
			{
				target.speed += 1;
				cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n"
					<< "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains 1 Speed!\n";
			}
			else
			{
				cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
		else if( target.aSave == true ) //player gains 1 pa
		{
			braveRoll = ( rand() % 100 ) + 1;
			if(braveRoll <= target.brave)
			{
				target.pa += 1;
				cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n"
					<< "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains 1 PA!\n";
			}
			else
			{
				cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
		else if( target.maSave == true ) //player gains 1 MA
		{
			braveRoll = ( rand() % 100 ) + 1;
			if(braveRoll <= target.brave)
			{
				target.ma += 1;
				cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n"
					<< "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains 1 MA!\n";
			}
			else
			{
				cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
		else if( target.regenerator == true ) //player gains regen
		{
			braveRoll = ( rand() % 100 ) + 1;
			if(braveRoll <= target.brave)
			{
				cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n";
				cout << "\t"; statusSetter( target, "Regen" );
			
			}
			else
			{
				cout << "\t" << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
		else if( target.damageSplit == true && damage < 0 ) 
		{
			braveRoll = ( rand() % 100 ) + 1;
			if(braveRoll <= target.brave)
			{
				int displayDamage = 0;
				displayDamage = abs(damage)/2 + abs(damage) % 2;
				target.life += abs(damage)/2 + abs(damage) % 2;
				actor.life -= abs(damage)/2 + abs(damage) % 2;
				if( actor.life <= 0 )
				{
					statusSetter( actor, "Dead" );
				}
				cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n"
					<< "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains " << displayDamage << " Life!\n"
					<< "\t" << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< " takes " << displayDamage << " damage!\n";
					if( actor.life <= 0 )
						cout << "\t" << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " has died!\n";
			}
			else
			{
				cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
		else if( target.critical == true )
		{
			if( target.hpRestore == true )
			{
				braveRoll = ( rand() % 100 ) + 1;

				if(braveRoll <= target.brave)
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n";
					
					target.life = target.maxLife;
					cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains full Life!\n";
				}
				else
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
				}
			}
			else if( target.mpRestore == true )
			{
				braveRoll = ( rand() % 100 ) + 1;

				if(braveRoll <= target.brave)
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n";
					
					target.mp = target.maxMP;
					cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains full MP!\n";
				}
				else
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
				}
			}
			else if( target.criticalQuick == true )
			{
				braveRoll = ( rand() % 100 ) + 1;
				if(braveRoll <= target.brave)
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " is triggered!\n";
					
					target.quick = true;
					target.ct = 100;
					cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< " gains Quick!\n";
				}
				else
				{
					cout << "\t" << "\tReaction Ability " << target.reaction << " fails.\n";
				}
			}
			else if( target.meatboneSlash == true )
			{
				distance = abs( actor.currentRow - target.currentRow ) + abs( actor.currentCol - target.currentCol );
				if(  distance <= target.weaponRange && distance >= target.weaponRangeMin )
				{
					if( target.weaponType == "Spear" || target.weaponType == "Stick" )
					{
						if( abs( actor.currentRow - target.currentRow ) == 0 || abs( actor.currentCol - target.currentCol ) == 0 )
						{
							braveRoll = ( rand() % 100 ) + 1;
							if(braveRoll <= target.brave)
							{
								cout << "\t" << "\tReaction Ability " << target.reaction << " triggers!\n";
								actor.life -= target.maxLife;
								cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
									<< " takes " << target.maxLife << " damage!\n";
								if( actor.life <= 0)
								{
									statusSetter( actor, "Dead" );
								}
							}
							else
							{
								cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
							}
						}
					}
					else
					{
						braveRoll = ( rand() % 100 ) + 1;

						if(braveRoll <= target.brave)
						{
							cout << "\t" << "\tReaction Ability " << target.reaction << " triggers!\n";
							actor.life -= target.maxLife;
							cout << "\t" << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
								<< " takes " << target.maxLife << " damage!\n";
							if( actor.life <= 0)
							{
								statusSetter( actor, "Dead" );
							}
						}
						else
						{
							cout << "\t" << "\tReaction Ability " << target.reaction << " fails to trigger\n";
						}
					}
				}
			}//end meatbone slash
		} //end critical reactions
		else if( target.mpSwitch == true && target.mp > 0 )
		{
			braveRoll = ( rand() % 100 ) + 1;

			if(braveRoll <= target.brave)
			{
				cout << " BUT is converted to MP damage by MP Switch!\n";
				mpDamage( target, damage );
				target.life -= damage;
				if( target.life > target.maxLife )
					target.life = target.maxLife;
			}
			else
			{
				cout << "\tReaction Ability " << target.reaction << " fails to trigger.\n";
			}
		}
	}//end status effect loop
}




void hpDamage( Player &target, Player &actor, Item &blueItem, Item &redItem, int damage, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10,
	bool cure = false, bool twoSwordsAttack = false, bool counterType = false )
{
	if( damage < 0 )
	{
		target.life += damage;

		if( target.life <= 0 )
		{
			statusSetter( target, "Dead");
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " takes " << -damage << " damage and dies!\n";
		}
		else if( target.life > 0 )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " loses " << -damage << " HP!\n";
			if( twoSwordsAttack == false )
			{
				if( counterType == false )
				{
					hpReaction( target, blueItem, redItem, actor, damage );
				}
			}
			confusionOff( target );
		}
	}
	else if( damage > 0 )
	{
		if( target.distribute == true )
		{
			innerDistribute( target, damage );
			distributeReaction( target, actor, player1, player2, player3, player4, player5, 
				player6, player7, player9, player9, player10, damage );
		}
		else
		{
			target.life += damage;
			if( target.life > target.maxLife )
				target.life = target.maxLife;
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains " << damage << " HP!\n";
		}
	}

	if( target.undead == true && cure == true )
	{
		target.life -= damage;

		if( target.life <= 0 )
		{
			statusSetter( target, "Dead");
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " has died!\n";
		}
		else if( target.life > 0 )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " loses " << damage << " HP!\n";
			if( counterType == false )
			{
				hpReaction( target, blueItem, redItem, actor, damage );
			}
			confusionOff( target );
		}
	}
}


void innerMimeItemFunction(MimeClass &mimeObject )
{
	mimeObject.mod = 0;
	mimeObject.effect = 1;
	mimeObject.evade = false;
	mimeObject.cure = false;
	mimeObject.status = "";
	mimeObject.damage = 0;
	mimeObject.abilityName = "";

	if( mimeObject.playerInput == 1 )
	{
		mimeObject.abilityName = "Potion";
		mimeObject.damage = 30;
		mimeObject.cure = true;
	}
	else if( mimeObject.playerInput == 2 )
	{
		mimeObject.abilityName = "Hi-Potion";
		mimeObject.damage = 70;
		mimeObject.cure = true;
	}
	else if( mimeObject.playerInput == 3 )
	{
		mimeObject.abilityName = "X-Potion";
		mimeObject.damage = 150;
		mimeObject.cure = true;
	}
	else if( mimeObject.playerInput == 4 )
	{
		mimeObject.abilityName = "Ether";
		mimeObject.damage = 20;
	}
	else if( mimeObject.playerInput == 5 )
	{
		mimeObject.abilityName = "Hi-Ether";
		mimeObject.damage = 50;
	}
	else if( mimeObject.playerInput == 6 )
	{
		mimeObject.abilityName = "Elixir";
		mimeObject.cure = true;
	}
	else if( mimeObject.playerInput == 7 )
	{
		mimeObject.abilityName = "Antidote";
		mimeObject.status = "Poison";
	}
	else if( mimeObject.playerInput == 8 )
	{
		mimeObject.abilityName = "Eye Drop";
		mimeObject.status = "Darkness";
	}
	else if( mimeObject.playerInput == 9 )
	{
		mimeObject.abilityName = "Echo Grass";
		mimeObject.status = "Silence";
	}
	else if( mimeObject.playerInput == 10 )
	{
		mimeObject.abilityName = "Maiden's Kiss";
		mimeObject.status = "Poison";
	}
	else if( mimeObject.playerInput == 11 )
	{
		mimeObject.abilityName = "Soft";
		mimeObject.status = "Petrify";
	}
	else if( mimeObject.playerInput == 12 )
	{
		mimeObject.abilityName = "Holy Water";
		mimeObject.status = "Undead & Blood Suck";
	}
	else if( mimeObject.playerInput == 13 )
	{
		mimeObject.abilityName = "Remedy";
		mimeObject.status = "various Status ailments";
	}
	else if( mimeObject.playerInput == 14 )
	{
		mimeObject.abilityName = "Phoenix Down";
		mimeObject.cure = true;
		mimeObject.damage = 10;
	}
}

void mimeItemDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	int phoenixRoll = 0;
	vector<int> targetVec (2, 0);
	
	targetVec = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic " << mimeObject.abilityName << " on (" << targetVec[0]-1 << ", " << targetVec[1]-1 << ") ...\n";

	targetVec = rangeCollision( theMime.currentRow, theMime.currentCol, targetVec[0], targetVec[1],
		myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
		player10, nullPlayer, mimeObject.abilityName );
	target = targetFunction( targetVec[0], targetVec[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

	if( target.nullPlayer == false )
	{
		hitRoll = rand() % 100 + 1;

		mimeObject.chance = 100;

		cout << "   "<< mimeObject.abilityName << " chance to hit is " << mimeObject.chance << "%\n";
		
		if( hitRoll <= mimeObject.chance )
		{
			if( target.dead == false && target.petrify == false )
			{
				if( mimeObject.playerInput  >= 1 && mimeObject.playerInput <= 3)
				{
					hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1, player2,
						player3, player4, player5, player6, player7, player8, player9, player10, mimeObject.cure );
				}
				else if( mimeObject.playerInput == 4 || mimeObject.playerInput == 5 )
				{
					mpDamage( target, mimeObject.damage );
				}
				else if( mimeObject.playerInput == 6 )
				{
					if( target.undead == true )
					{
						statusSetter( target, "Dead" );
						target.mp = target.maxMP;
					}
					else
					{
						target.life = target.maxLife;
						target.mp = target.maxMP;
						tLine( target );
						cout << " gains full HP & MP!";
					}
				}
				
				
			}
			if( target.dead == false )
			{
				if( mimeObject.playerInput >= 7 && mimeObject.playerInput <= 13 )
				{
					statusRemover( target, mimeObject.abilityName );
				}
			}
			if( target.dead == true || target.undead == true )
			{
				if( mimeObject.playerInput == 14 )
				{
					if( target.dead == true && target.undead == false )
					{
						tLine( target );
						cout << " is restored to life!\n";
						target.dead = false;
						phoenixRoll = rand() % 20 + 1;
						target.life += phoenixRoll;
					}
					if( target.undead == true )
					{
						statusSetter( target, "Dead" );
					}
					else cout << "\tand it has no effect.\n";
				}
			}
		}
		else cout << "   misses!\n";
		endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );
	}
	else cout << "\tand it has no effect.\n";

}

void counterFloodReaction( Player &target, Player &actor, Player &player1, Player &player2, Player &player3,
	Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem, char myArray[][11] )
{

	string abilityName = "";
	int mod = 5;
	int abilityDamage = 0;
	bool evade = false;
	int rangeMin = 0;
	int rangeMax = 5;

	Player counterTarget;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int elementalConfirm = 2;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int elementalGroundRoll = 0;
	int elementalStatusRoll = 0;
	string elementalGround = "";
	string elementalStatus = "";

	bool fireType = false;
	bool iceType = false;
	bool waterType = false;
	bool lightningType = false;
	bool holyType = false;
	bool darkType = false;
	bool earthType = false;
	bool windType = false;

	int braveRoll;

	if( target.counterFlood == true )
	{

	//target is the person doing the counter Flood
		if( target.bloodSuck == false && target.chicken == false && target.confusion == false
			&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
			&& target.berserk == false && target.dontAct == false && target.sleep == false ) 
		{
			braveRoll = rand() % 100 + 1;
			if( braveRoll <= target.brave )
			{
				elementalGroundRoll = rand() % 12;
				if( elementalGroundRoll == 0 )
				{
					elementalGround = "Wasteland";
					elementalStatus = "Don't Move";
					abilityName = "Pitfall";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 1 )
				{
					elementalGround = "Water";
					elementalStatus = "Frog";
					abilityName = "Water Ball";
					fireType = false;
					iceType = false;
					waterType = true;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 2 )
				{
					elementalGround = "Grassland";
					elementalStatus = "Stop";
					abilityName = "Hell Ivy";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 3 )
				{
					elementalGround = "Stone";
					elementalStatus = "Petrify";
					abilityName = "Carve Model";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 4 )
				{
					elementalGround = "Rocky Cliff";
					elementalStatus = "Confusion";
					abilityName = "Local Quick";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = true;
					windType = false;
				}
				else if( elementalGroundRoll == 5 )
				{
					elementalGround = "Moss";
					elementalStatus = "Don't Act";
					abilityName = "Kamaitachi";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = true;
				}
				else if( elementalGroundRoll == 6 )
				{
					elementalGround = "Wooden Floor";
					elementalStatus = "Sleep";
					abilityName = "Demon Fire";
					fireType = true;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 7 )
				{
					elementalGround = "Swamp";
					elementalStatus = "Death Sentence";
					abilityName = "Quicksand";
					fireType = false;
					iceType = false;
					waterType = true;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 8 )
				{
					elementalGround = "Sand";
					elementalStatus = "Darkness";
					abilityName = "Sand Storm";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = true;
				}
				else if( elementalGroundRoll == 9 )
				{
					elementalGround = "Snow";
					elementalStatus = "Silence";
					abilityName = "Blizzard";
					fireType = false;
					iceType = true;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 10 )
				{
					elementalGround = "Sky";
					elementalStatus = "Slow";
					abilityName = "Gusty Wind";
					fireType = false;
					iceType = true;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 11 )
				{
					elementalGround = "Lava";
					elementalStatus = "Dead";
					abilityName = "Lava Ball";
					fireType = true;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				cout << "\t" << "\tCOUNTER FLOOD activates! The ground shifts under " << target.playerName << "'s feet...\n"
					<< "\t" << "\t"<< "and turns to " << elementalGround << " while " << abilityName << " is cast!\n";

				effectVector = multiRange( target, 2, abilityName, 5,
					0, false, false, actor.currentRow, actor.currentCol );
				
				int i = 0;
				int j = 0;

				for( i = 0; i < 5; i++)
				{
					counterTarget = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( counterTarget.nullPlayer == false && counterTarget.dead == false && counterTarget.petrify == false )
					{
						//can't target yourself
						if( target.turnOrder != counterTarget.turnOrder )
						{
							abilityDamage = -mod5Elemental( target, counterTarget, target.ma, fireType,
								iceType, waterType, lightningType, holyType, darkType, earthType, windType );
						
							if( counterTarget.dead == false )
							{
								elementalStatusRoll = rand() % 100 + 1;
								cout << "\t" << "\t" << "Counter Flood targets " << target.teamName << " " << target.playerClassName << " " << target.playerName << "\n"
									<< "\t" << "\t" << "25% Chance to add " << elementalStatus << "\n"
									<< "\t"  << "\t" << "Random number is... " << elementalStatusRoll << "\n";
								if( elementalStatusRoll <= 25 )
								{
									
									if( elementalGroundRoll == 0 )
										statusSetter( counterTarget, "Don't Move" );
									else if( elementalGroundRoll == 1 )
										statusSetter( counterTarget, "Frog" );
									else if( elementalGroundRoll == 2 )
										statusSetter( counterTarget, "Stop" );
									else if( elementalGroundRoll == 3 )
										statusSetter( counterTarget, "Petrify" );
									else if( elementalGroundRoll == 4 )
										statusSetter( counterTarget, "Confusion" );
									else if( elementalGroundRoll == 5 )
										statusSetter( counterTarget, "Don't Act" );
									else if( elementalGroundRoll == 6 )
										statusSetter( counterTarget, "Sleep" );
									else if( elementalGroundRoll == 7 )
										statusSetter( counterTarget, "Death Sentence" );
									else if( elementalGroundRoll == 8 )
										statusSetter( counterTarget, "Darkness" );
									else if( elementalGroundRoll == 9 )
										statusSetter( counterTarget, "Silence" );
									else if( elementalGroundRoll == 10 )
										statusSetter( counterTarget, "Slow" );
									else if( elementalGroundRoll == 11 )
									{
										statusSetter( counterTarget, "Death Type" );
									}
								}
								else cout << "\t" << "\tMisses! No status is added!\n";
								hpDamage( counterTarget, target, blueItem, redItem, abilityDamage, player1,
									player2, player3, player4, player5, player6, player7, player8, player9,
									player10, false, false, true  );
								if( target.dead == true && target.petrify == true )
									target.petrify = false;
							}
						}
						endTarget( counterTarget, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					} //ends targetting player loop
					j += 2;
				} //ends for loop
				}//brave roll
			else cout << "\t" << "\t" << "Counter Flood fails to trigger!\n";
		}//statuses that prevent reaction abilities
	}//ends check to see if target has counter flood
}


//long term: add elemental to map spaces
class Elemental
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	string display;
	bool evade;
	int displayDamage;
	int abilityDamage;
	int abilityDamage2;
	int abilityChance;
	int mod;
	int rangeMax;
	int rangeMin;
	int xa;
	
	Elemental()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "magical";
		display = "";
		mod = 5;
		evade = false;
		abilityDamage = 0;
		abilityChance = 100;
		rangeMin = 0;
		rangeMax = 5;
	}
	~Elemental() {}

	void elementalMenu( Elemental &elementalObject );
	void elementalSuccess( Elemental &elementalObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject );
};

void Elemental::elementalMenu( Elemental &elementalObject )
{
	int elementalMenu = 0; 
	int elementalAction = 0;
	elementalObject.confirm = 2;
}

void Elemental::elementalSuccess( Elemental &elementalObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject )
{

	elementalObject.abilityName = "";
	elementalObject.abilityType = "magical";
	elementalObject.display = "-- 25% Chance at Random Status -- HP ";
	elementalObject.mod = 5;
	elementalObject.evade = false;
	elementalObject.abilityDamage = 0;
	elementalObject.abilityChance = 100;
	elementalObject.rangeMin = 0;
	elementalObject.rangeMax = 5;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int elementalConfirm = 2;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int elementalGroundRoll = 0;
	int elementalStatusRoll = 0;
	string elementalGround = "";
	string elementalStatus = "";

	bool fireType = false;
	bool iceType = false;
	bool waterType = false;
	bool lightningType = false;
	bool holyType = false;
	bool darkType = false;
	bool earthType = false;
	bool windType = false;

	if( elementalObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( elementalObject.confirm != 0 ) 
	{
		do
		{
			cout << "\n"
				<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " ELEMENTAL ---\n"
				<< "ELEMENTAL will hit the target square and 4 surrounding squares.\n";
			targetVector = rangeTest( actor, elementalObject.rangeMax,
				"Elemental", elementalObject.rangeMin );
			target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			tempDamage = -mod5Elemental( actor, target, actor.ma );

			if( target.nullPlayer == true || target.dead == true || target.petrify == true
				|| target.turnOrder == actor.turnOrder )
			{
				elementalObject.abilityChance = 0;
			}
			else elementalObject.abilityChance = 100;

			elementalConfirm = targetDisplay( target, "Elemental", elementalObject.abilityChance, tempDamage,
				elementalObject.display );

			if( elementalConfirm == 1 )
			{
				elementalGroundRoll = rand() % 12;
				if( elementalGroundRoll == 0 )
				{
					elementalGround = "Wasteland";
					elementalStatus = "Don't Move";
					elementalObject.abilityName = "Pitfall";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 1 )
				{
					elementalGround = "Water";
					elementalStatus = "Frog";
					elementalObject.abilityName = "Water Ball";
					fireType = false;
					iceType = false;
					waterType = true;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 2 )
				{
					elementalGround = "Grassland";
					elementalStatus = "Stop";
					elementalObject.abilityName = "Hell Ivy";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 3 )
				{
					elementalGround = "Stone";
					elementalStatus = "Petrify";
					elementalObject.abilityName = "Carve Model";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 4 )
				{
					elementalGround = "Rocky Cliff";
					elementalStatus = "Confusion";
					elementalObject.abilityName = "Local Quick";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = true;
					windType = false;
				}
				else if( elementalGroundRoll == 5 )
				{
					elementalGround = "Moss";
					elementalStatus = "Don't Act";
					elementalObject.abilityName = "Kamaitachi";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = true;
				}
				else if( elementalGroundRoll == 6 )
				{
					elementalGround = "Wooden Floor";
					elementalStatus = "Sleep";
					elementalObject.abilityName = "Demon Fire";
					fireType = true;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 7 )
				{
					elementalGround = "Swamp";
					elementalStatus = "Death Sentence";
					elementalObject.abilityName = "Quicksand";
					fireType = false;
					iceType = false;
					waterType = true;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 8 )
				{
					elementalGround = "Sand";
					elementalStatus = "Darkness";
					elementalObject.abilityName = "Sand Storm";
					fireType = false;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = true;
				}
				else if( elementalGroundRoll == 9 )
				{
					elementalGround = "Snow";
					elementalStatus = "Silence";
					elementalObject.abilityName = "Blizzard";
					fireType = false;
					iceType = true;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 10 )
				{
					elementalGround = "Sky";
					elementalStatus = "Slow";
					elementalObject.abilityName = "Gusty Wind";
					fireType = false;
					iceType = true;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				else if( elementalGroundRoll == 11 )
				{
					elementalGround = "Lava";
					elementalStatus = "Dead";
					elementalObject.abilityName = "Lava Ball";
					fireType = true;
					iceType = false;
					waterType = false;
					lightningType = false;
					holyType = false;
					darkType = false;
					earthType = false;
					windType = false;
				}
				cout << "The ground shifts under " << actor.playerName << "'s feet "
					<< "and turns to " << elementalGround << " while " << elementalObject.abilityName << " is cast!\n";

				effectVector = multiRange( actor, 2, elementalObject.abilityName, elementalObject.rangeMax,
					elementalObject.rangeMin, false, false, targetVector[0], targetVector[1] );
				
				int i = 0;
				int j = 0;

				for( i = 0; i < 5; i++)
				{
					target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

					if( target.nullPlayer == false && target.dead == false && target.petrify == false )
					{
						//can't target yourself
						if( actor.turnOrder != target.turnOrder )
						{
							elementalObject.abilityDamage = -mod5Elemental( actor, target, actor.ma, fireType,
								iceType, waterType, lightningType, holyType, darkType, earthType, windType );
							
							if( target.dead == false ) 
							{
								elementalStatusRoll = rand() % 100 + 1;
								cout << "\tChance to add " << elementalStatus << "..."
								<< " random number is... " << elementalStatusRoll << "\n";
								if( elementalStatusRoll <= 25 )
								{
									
									if( elementalGroundRoll == 0 )
										statusSetter( target, "Don't Move" );
									else if( elementalGroundRoll == 1 )
										statusSetter( target, "Frog" );
									else if( elementalGroundRoll == 2 )
										statusSetter( target, "Stop" );
									else if( elementalGroundRoll == 3 )
										statusSetter( target, "Petrify" );
									else if( elementalGroundRoll == 4 )
										statusSetter( target, "Confusion" );
									else if( elementalGroundRoll == 5 )
										statusSetter( target, "Don't Act" );
									else if( elementalGroundRoll == 6 )
										statusSetter( target, "Sleep" );
									else if( elementalGroundRoll == 7 )
										statusSetter( target, "Death Sentence" );
									else if( elementalGroundRoll == 8 )
										statusSetter( target, "Darkness" );
									else if( elementalGroundRoll == 9 )
										statusSetter( target, "Silence" );
									else if( elementalGroundRoll == 10 )
										statusSetter( target, "Slow" );
									else if( elementalGroundRoll == 11 )
									{
										statusSetter( target, "Death Type" );
									}
								}
								else cout << "\t" << "\tMisses! No status is added!\n";
								hpDamage( target, actor, blueItem, redItem, abilityDamage, player1,
									player2, player3, player4, player5, player6, player7, player8, player9,
									player10, false, false, true  );
								counterFloodReaction( target, actor, player1, player2, player3, player4,
									player5, player6, player7, player8, player9, player10,
									nullPlayer, blueItem, redItem, myArray );
							}
						}
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					} //ends targetting player loop
					j += 2;
				} //ends for loop
				} //ends confirm turn loop
			if( elementalConfirm == 1 )
			{
				vector<int> mimeVector (2, 0);
				mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor );
				mimeObject.elementalSide = mimeVector[0];
				mimeObject.elementalDistance = mimeVector[1];
				mimeObject.mimeElementalConfirm = 1;
			}
		}while( elementalConfirm == 2);
	}
		
	if( elementalConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
} //ends elemental


void mimeElementalDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	vector<int> targetVector (2, 0);

	vector<int> effectVector (50, 0);
	int elementalConfirm = 2;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int elementalGroundRoll = 0;
	int elementalStatusRoll = 0;
	string elementalGround = "";
	string elementalStatus = "";

	bool fireType = false;
	bool iceType = false;
	bool waterType = false;
	bool lightningType = false;
	bool holyType = false;
	bool darkType = false;
	bool earthType = false;
	bool windType = false;
	
	targetVector = mimeTargetVector( theMime, mimeObject.elementalSide, mimeObject.elementalDistance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic Elemental" << " on (" << targetVector[0]-1 << ", " << targetVector[1]-1 << ") ...\n";

	target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );


		elementalGroundRoll = rand() % 12;

			if( elementalGroundRoll == 0 )
			{
				elementalGround = "Wasteland";
				elementalStatus = "Don't Move";
				mimeObject.abilityName = "Pitfall";
				fireType = false;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 1 )
			{
				elementalGround = "Water";
				elementalStatus = "Frog";
				mimeObject.abilityName = "Water Ball";
				fireType = false;
				iceType = false;
				waterType = true;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 2 )
			{
				elementalGround = "Grassland";
				elementalStatus = "Stop";
				mimeObject.abilityName = "Hell Ivy";
				fireType = false;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 3 )
			{
				elementalGround = "Stone";
				elementalStatus = "Petrify";
				mimeObject.abilityName = "Carve Model";
				fireType = false;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 4 )
			{
				elementalGround = "Rocky Cliff";
				elementalStatus = "Confusion";
				mimeObject.abilityName = "Local Quick";
				fireType = false;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = true;
				windType = false;
			}
			else if( elementalGroundRoll == 5 )
			{
				elementalGround = "Moss";
				elementalStatus = "Don't Act";
				mimeObject.abilityName = "Kamaitachi";
				fireType = false;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = true;
			}
			else if( elementalGroundRoll == 6 )
			{
				elementalGround = "Wooden Floor";
				elementalStatus = "Sleep";
				mimeObject.abilityName = "Demon Fire";
				fireType = true;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 7 )
			{
				elementalGround = "Swamp";
				elementalStatus = "Death Sentence";
				mimeObject.abilityName = "Quicksand";
				fireType = false;
				iceType = false;
				waterType = true;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 8 )
			{
				elementalGround = "Sand";
				elementalStatus = "Darkness";
				mimeObject.abilityName = "Sand Storm";
				fireType = false;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = true;
			}
			else if( elementalGroundRoll == 9 )
			{
				elementalGround = "Snow";
				elementalStatus = "Silence";
				mimeObject.abilityName = "Blizzard";
				fireType = false;
				iceType = true;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 10 )
			{
				elementalGround = "Sky";
				elementalStatus = "Slow";
				mimeObject.abilityName = "Gusty Wind";
				fireType = false;
				iceType = true;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			else if( elementalGroundRoll == 11 )
			{
				elementalGround = "Lava";
				elementalStatus = "Dead";
				mimeObject.abilityName = "Lava Ball";
				fireType = true;
				iceType = false;
				waterType = false;
				lightningType = false;
				holyType = false;
				darkType = false;
				earthType = false;
				windType = false;
			}
			cout << "The ground shifts under " << theMime.playerName << "'s feet "
				<< "and turns to " << elementalGround << " while " << mimeObject.abilityName << " is cast!\n";

			effectVector = multiRange( theMime, 2, mimeObject.abilityName, 5,
				0, false, false, targetVector[0], targetVector[1] );
				
			int i = 0;
			int j = 0;

			for( i = 0; i < 5; i++)
			{
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					//can't target yourself
					if( theMime.turnOrder != target.turnOrder )
					{
						mimeObject.damage = -mod5Elemental( theMime, target, theMime.ma, fireType,
							iceType, waterType, lightningType, holyType, darkType, earthType, windType );
						//counters come later after the chance to add status effect
						
						if( target.dead == false ) 
						{
							elementalStatusRoll = rand() % 100 + 1;
							cout << "\t" << "\tChance to add " << elementalStatus << "..."
								<< " random number is... " << elementalStatusRoll << "\n";
							if( elementalStatusRoll <= 25 )
							{
									
								if( elementalGroundRoll == 0 )
									statusSetter( target, "Don't Move" );
								else if( elementalGroundRoll == 1 )
									statusSetter( target, "Frog" );
								else if( elementalGroundRoll == 2 )
									statusSetter( target, "Stop" );
								else if( elementalGroundRoll == 3 )
									statusSetter( target, "Petrify" );
								else if( elementalGroundRoll == 4 )
									statusSetter( target, "Confusion" );
								else if( elementalGroundRoll == 5 )
									statusSetter( target, "Don't Act" );
								else if( elementalGroundRoll == 6 )
									statusSetter( target, "Sleep" );
								else if( elementalGroundRoll == 7 )
									statusSetter( target, "Death Sentence" );
								else if( elementalGroundRoll == 8 )
									statusSetter( target, "Darkness" );
								else if( elementalGroundRoll == 9 )
									statusSetter( target, "Silence" );
								else if( elementalGroundRoll == 10 )
									statusSetter( target, "Slow" );
								else if( elementalGroundRoll == 11 )
								{
									statusSetter( target, "Death Type" );
								}
							}
							else cout << "\t" << "\tMisses! No status is added!\n";
							hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1,
								player2, player3, player4, player5, player6, player7, player8, player9,
								player10, false, false, true  );
							counterFloodReaction( target, theMime, player1, player2, player3, player4,
								player5, player6, player7, player8, player9, player10,
								nullPlayer, blueItem, redItem, myArray );
						}
					}
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends targetting player loop
				j += 2;
			} //ends for loop

	


}





void magicTypeReaction( int mpUsed, Player &target, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer, Item &blueItem, Item &redItem,
	bool counterMagic = false, int mod = 5, int mpCost = 0, int effect = 0, int component = 0, string abilityName = "",
	bool evade = true, bool statusType = false, string statusName = "", bool reflectable = false, 
	bool fireType = false, bool iceType = false, bool lightningType = false, bool waterType = false,
	bool windType = false, bool earthType = false, bool holyType = false, bool darkType = false )
{
	int braveRoll;
	int targetLoop = 1;
	int magicDamage;
	int magicChance;
	Player counterTarget;
	vector<int> targetVector(2, 0);
	vector<int> effectVector (50, 0);

	if(  target.nullPlayer == false && target.bloodSuck == false && target.chicken == false && target.confusion == false
		&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
		&& target.berserk == false && target.dontAct == false && target.sleep == false
		&& target.turnOrder != actor.turnOrder  // not sure about this line for Face Up and Counter Magic
		) //can't counter if blood sucked
	{

		if( target.absorbUsedMP == true )
		{
			braveRoll = rand() % 100 + 1;
			cout << "\tChance for " << target.reaction << " to trigger...\n";
			if( braveRoll <= target.brave )
			{
				cout << "\t" << target.reaction << " triggers! "
					<< target.teamName << " " << target.playerClassName << " " << target.teamName
					<< " gains " << mpUsed << " MP!\n";
				target.mp += mpUsed;
				if( target.mp > target.maxMP )
					target.mp = target.maxMP;
			}
			else cout << "\t" << target.reaction << " fails to trigger.\n";
		}
		else if( target.faceUp == true )
		{
			braveRoll = rand() % 100 + 1;
			cout << "\tChance for " << target.reaction << " to trigger...\n";
			if( braveRoll <= target.brave )
			{
				cout << "\t" << target.reaction << " triggers! "
					<< target.teamName << " " << target.playerClassName << " " << target.teamName
					<< " gains 3 Faith!\n";
				target.faith += 3;
				if( target.faith > 100 )
					target.faith = 100;
			}
			else cout << "\t" << target.reaction << " fails to trigger.\n";
		}

		else if( target.counterMagic == true && counterMagic == true )
		{
			braveRoll = rand() % 100 + 1;
			cout << "\t" << "\tChance for " << target.reaction << " to trigger...\n";

			if( braveRoll <= target.brave )
			{
				cout << "\t" << "\t" << target.reaction << " triggers! "
					<< target.teamName << " " << target.playerClassName << " " << target.teamName
					<< " casts " << abilityName << "!\n";

				if( target.halfOfMP == true )
					mpCost = mpCost/2 + mpCost % 2;
				if( target.silence == true )
				{
					cout << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< " tries to cast " << abilityName << " but is Silenced!\n";
				}
				else if( target.mp < mpCost )
				{
					cout << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< " tries to cast " << abilityName << " but does not have enough MP!\n";
				}

				else //spell is cast!
				{
					target.mp -= mpCost;
					targetLoop = loopTarget( effect );
					targetVector[0] = actor.currentRow;
					targetVector[1] = actor.currentCol;

					int i = 0;
					int j = 0;
					for( i = 0 ; i < targetLoop; i++ )
					{
					
						effectVector = multiRange( target, effect, abilityName, 1, 1, false, false,
							targetVector[0], targetVector[1] );
						counterTarget = targetFunction( effectVector[j], effectVector[j+1], player1, player2,
							player3, player4, player5, player6, player7, player8, player9, player10, myArray,
							nullPlayer );
						if( counterTarget.nullPlayer == false && counterTarget.petrify == false && counterTarget.dead == false )
						{
							if( mod == 6 )
							{
								magicChance = mod6( target, counterTarget, target.ma, component, fireType, iceType, waterType,
									lightningType, holyType, darkType, earthType, windType ); //reversed on purpose
								if( evade == true )
								{
									magicChance = magicEvade( magicChance, target, counterTarget );
								}
							}
							else if( mod == 5 )
							{
								if( evade == true )
								{
									magicChance = magicEvade( 100, target, counterTarget ); //reversed on purpose
								}
							}

							braveRoll = rand() % 100 + 1;

							if( braveRoll <= magicChance )
							{
								if( mod == 5 )
								{
									magicDamage = -mod5Magic( target, counterTarget, target.ma, component, fireType, iceType, waterType,
										lightningType, holyType, darkType, earthType, windType );
									hpDamage( counterTarget, target, blueItem, redItem, magicDamage, player1,
										player2, player3, player4, player5, player6, player7, player8, player9,
										player10, false, false, true );
								}
								if( mod == 6 )
								{	
									statusSetter( counterTarget, statusName );
								}
							}
							else cout << "\t"  << "\t" << abilityName << " misses!\n";
							endTarget( counterTarget, player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, nullPlayer );
						}
						j += 2;
					}
				}
			}
			else cout << "\t" << "\t" << target.reaction << " fails to trigger.\n";
		}
	}//loop for statuses that prevent reactions
}


void magicGunReaction( int mpUsed, Player &target, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7, Player &player8,
	Player &player9, Player &player10, char myArray[][11], Player &nullPlayer, Item &blueItem, Item &redItem )
{
	bool fireType = false;
	bool iceType = false;
	bool lightningType = false;
	int component = 14;
	int mpAmount = 6;
	string statusName = "";
	string abilityName = "";
	
	

	if( actor.weaponName == "Blaze Gun" )
	{
		iceType = true;
		if( actor.magicGunStrength == 3 )
		{
			component = 24;
			abilityName = "Ice 3";
			mpAmount = 24;
		}
		else if( actor.magicGunStrength == 2 )
		{
			component = 18;
			abilityName = "Ice 2";
			mpAmount = 12;
		}
		else
		{
			component = 14;
			abilityName = "Ice";
		}
	}
	else if( actor.weaponName == "Glacier Gun" )
	{
		fireType = true;
		if( actor.magicGunStrength == 3 )
		{
			component = 24;
			abilityName = "Fire 3";
			mpAmount = 24;
		}
		else if( actor.magicGunStrength == 2 )
		{
			component = 18;
			abilityName = "Fire 2";
			mpAmount = 12;
		}
		else
		{
			component = 14;
			abilityName = "Fire";
		}
	}
	else
	{
		lightningType = true;
		if( actor.magicGunStrength == 3 )
		{
			component = 24;
			abilityName = "Bolt 3";
			mpAmount = 24;
		}
		else if( actor.magicGunStrength == 2 )
		{
			component = 18;
			abilityName = "Bolt 2";
			mpAmount = 12;
		}
		else
		{
			component = 14;
			abilityName = "Bolt";
		}
	}
	
	magicTypeReaction( 0, target, actor, player1, player2, player3, player4, player5,
		player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem,
		redItem, true, 5, mpAmount, 2, component, abilityName, true, false, statusName,
		true, fireType, iceType, lightningType, false, false, false, false, false );
}