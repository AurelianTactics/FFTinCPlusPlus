//More secondary abilities


class Jump
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
	int side;
	int distance;
	int mimeConfirm;
	
	Jump()
	{
		//coding
		confirm = 2;
		abilityName = "Jump";
		abilityType = "physical";
		evade = false;
		abilityCTR = true;
		abilityCTRCount = 0;
		abilityDamage = 0;
		abilityChance = 100;
		
	}
	~Jump() {}

	void jumpMenu( Jump &jumpObject );
	void jumpSuccess( Jump &jumpObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11]
	);
};

void Jump::jumpMenu( Jump &jumpObject )
{
	int jumpMenu = 0; 
	int jumpAction = 0;
	jumpObject.confirm = 2;

	jumpObject.abilityName = "Jump";
	jumpObject.abilityType = "physical";
	jumpObject.evade = false;
	jumpObject.abilityCTR = true;
	jumpObject.abilityCTRCount = 0;
	jumpObject.abilityDamage = 0;
	jumpObject.abilityChance = 100;
}

int jumpDamage( Player actor, Player target )
{
	int xa = actor.pa;
	int jumpDamage = 0;
	if( target.defenseUp == true )
		xa = xa * 2 / 3;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2 ;
	if( target.frog == true || target.chicken == true )
		xa = xa * 3 / 2;
	if( actor.weaponType == "Spear")
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );
	if( actor.weaponType == "Bare Hands" )
		xa = xa * ( actor.pa * actor.brave / 100 );
	else xa = xa * actor.weaponPower;
	return xa;
}

void Jump::jumpSuccess( Jump &jumpObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11]
	 )
{
	vector<int> rangeVector (2, 0);
	Player target;
	int jumpConfirm = 2;
	int baseHit = 0;
	int chargeK = 0;
	int jumpDisplayDamage = 0;
	int jumpActualDamage = 0;
	jumpObject.side = 0;
	jumpObject.distance = 0;
	jumpObject.mimeConfirm = 0;

	if( jumpObject.confirm == 0 )
	{
		actor.confirm = 3;
	}
	else if( jumpObject.confirm != 0)
	{

		do 
		{
			rangeVector = rangeTest( actor, 8,
				jumpObject.abilityName, 1 );
			target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
			jumpDisplayDamage = -jumpDamage( actor, target );

			if( target.nullPlayer == true || target.petrify == true || target.dead == true || target.jumping == true ) //targets no one
			{
				jumpConfirm = targetDisplay( target, "Jump", 0, jumpDisplayDamage, "-- HP ");
				
				if( jumpConfirm == 1 )
				{
					actor.ctrCountdownBool = true;
					actor.ctrCountdown = 50/actor.speed;
					actor.ctrName = jumpObject.abilityName;
					actor.ctrType = 8; //charge type 
					actor.ctrRow = rangeVector[0];
					actor.ctrCol = rangeVector[1];
					actor.jumping = true;
					myArray[actor.currentRow][actor.currentCol] = 'J'; //can't target someone while jumping
				}
			}
			else
			{
				baseHit = counterGraspEvade( 100, actor, target, false, "Jump" );
				jumpDisplayDamage = -jumpDamage( actor, target );

				jumpConfirm = targetDisplay( target, "Jump", baseHit, jumpDisplayDamage, "-- HP ");
				
				if( jumpConfirm == 1 )
				{
					actor.ctrCountdownBool = true;
					actor.ctrCountdown = 50/actor.speed;
					actor.ctrName = jumpObject.abilityName;
					actor.ctrType = 8; //charge type 
					actor.ctrRow = rangeVector[0];
					actor.ctrCol = rangeVector[1];
					actor.jumping = true;
					myArray[actor.currentRow][actor.currentCol] = 'J'; //can't target someone while jumping
				}
			}
		} while(jumpConfirm == 2);
	}
	if( jumpConfirm == 3 )
	{
		actor.confirm = 3;
	}
}

void jumpResolve( Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem, char myArray[][11], Player &nullPlayer, Golem &blueGolem, Golem &redGolem,
	Jump &jumpObject )
{
	Player target;
	bool golemTest = false;

	target = targetFunction( actor.ctrRow, actor.ctrCol, player1, player2, player3, player4, player5,
		player6, player7, player8, player9, player10, myArray, nullPlayer );
	if( target.mapSymbol == myArray[actor.ctrRow][actor.ctrCol] )
	{
		int actualDamage = 0;
		int hitChance = 0;
		hitChance = counterGraspEvade( 100, actor, target, false, "Jump" );

		int roll = rand() % 100 + 1;
		if( roll <= hitChance )
		{
			actualDamage = -jumpDamage( actor, target );
			
			golemTest = golemTester( target, blueGolem, redGolem );
			if( golemTest == true )
			{
				golemDestroyer( target, blueGolem, redGolem, actualDamage );
			}
			else
			{
				hpDamage( target, actor, blueItem, redItem, actualDamage, player1,
					player2, player3, player4, player5, player6, player7, player8, player9,
					player10  );
			}

		}
		else
		{
			if( target.bladeGrasp == true )
			{
				cout << "\tJump is blocked by Blade Grasp!\n";
			}
			if( target.arrowGuard == true )
			{
				cout << "\tJump is blocked by Arrow Guard!\n";
			}
		}
		counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
			player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
		counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
			player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
		endTarget( target, player1, player2, player3, player4, player5, player6, player7,
			player8, player9, player10, nullPlayer );
	}
	else
	{
		cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
			<< " lands on square ( " << actor.ctrRow-1 << ", " << actor.ctrCol-1 << " ) but no one is hit...\n";
	}
	vector<int> mimeVector (2, 0);
	mimeVector = mimeTargetFunction( actor.ctrRow, actor.ctrCol, actor);
	jumpObject.side = mimeVector[0];
	jumpObject.distance = mimeVector[1];
	jumpObject.mimeConfirm = 1;
}

void mimeJumpDamage( Player &theMime, Player &mimedUnit, Jump &jumpObject, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	vector<int> targetVec (2, 0);
	bool golemTest = false;
	
	targetVec = mimeTargetVector( theMime, jumpObject.side, jumpObject.distance );


	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic Jump on (" << targetVec[0]-1 << ", " << targetVec[1]-1 << ") ...\n";

	target = targetFunction( targetVec[0], targetVec[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

	if( target.dead == false && target.petrify == false && target.nullPlayer == false )
	{
		hitRoll = rand() % 100 + 1;

		mimeObject.chance = counterGraspEvade( 100, theMime, target, false,
			"physical", false );

		theMime.weaponType = mimedUnit.weaponType; //mime's "borrow" jumpers weapon
		theMime.weaponPower = mimedUnit.weaponPower;

		mimeObject.damage = -jumpDamage( theMime, target );

		theMime.weaponType = "Bare Hands";
		theMime.weaponPower = 0;

		cout << "\tJump chance to hit is " << mimeObject.chance << "%. Random number is..." << hitRoll << "\n";
		if( hitRoll <= mimeObject.chance )
		{
			golemTest = golemTester( target, blueGolem, redGolem );
			if( golemTest == true )
			{
				golemDestroyer( target, blueGolem, redGolem, mimeObject.damage );
			}
			else
			{
				hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1, player2,
					player3, player4, player5, player6, player7, player8, player9, player10 );
			}
		}
		else cout << "\tmisses!\n";
		counterGraspReaction( theMime, target, myArray, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
			redGolem );
		endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );
	}
	else cout << "\tand it has no effect.";

}


void mimeJumpFunction( MimeClass &mimeObject, Jump &jumpObject, Player &theMime, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem, Golem &blueGolem,
	Golem &redGolem, char myArray[][11], bool mimeJump = true )
{

	if( theMime.playerClass == 10 )
	{
		if( ( theMime.teamName == mimedUnit.teamName && theMime.charm == false ) ||
			( theMime.teamName != mimedUnit.teamName && theMime.charm == true ) )
		{
			if( theMime.dead == false && theMime.petrify == false && theMime.sleep == false
				&& theMime.stop == false && theMime.bloodSuck == false && theMime.dontAct == false
				&& theMime.frog == false && theMime.chicken == false && theMime.confusion == false
				&& theMime.berserk == false )
			{
				if( mimeJump == true && jumpObject.mimeConfirm == 1 )
				{

					cout << "\n" 
						<< "   --- MIME ACTION ---\n"
						<< theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
						<< " attempts to mimic... \n";

					mimeJumpDamage( theMime, mimedUnit, jumpObject, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
					
				} //should always be true
			}// eligible status effect
		}//charmed or not charmed
	}//player is a mime
}


class TalkSkill
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
	int abilityDamage2; //mp restore
	int abilityChance;
	int mod;
	int rangeMax;
	int rangeMin;
	int xa;
	
	TalkSkill()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "neutral";
		display = "";
		mod = 1;
		evade = false;
		abilityDamage = 0;
		abilityChance = 0;
		rangeMin = 1;
		rangeMax = 3;
	}
	~TalkSkill() {}

	void talkSkillMenu( TalkSkill &talkSkillObject, Player actor );
	void talkSkillSuccess( TalkSkill &talkSkillObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject );
};

void TalkSkill::talkSkillMenu( TalkSkill &talkSkillObject, Player actor )
{
	int talkSkillAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " TALK SKILL Menu ---\n" 
		<< "0.) Return to Menu\n"
		<< "1.) Invitation -- Recruit Enemy\n"  
		<< "2.) Persuade -- Set CT to 0\n"
		<< "3.) Praise -- Brave +4\n" 
		<< "4.) Threaten -- Brave -20\n" 
		<< "5.) Preach -- Faith +4\n"
		<< "6.) Solution -- Faith -20\n" 
		<< "7.) Death Sentence\n" 
		<< "8.) Insult -- Add Berserk\n" 
		<< "9.) Mimic Daravon -- Add Sleep to area\n"
	) && 
	( !(cin >> talkSkillAction ) || talkSkillAction < 0 || talkSkillAction > 9 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	talkSkillObject.playerInput = talkSkillAction;
	if( talkSkillAction == 0 )
	{
		talkSkillObject.confirm = 0;
	}
	else talkSkillObject.confirm = 2;
}

void TalkSkill::talkSkillSuccess( TalkSkill &talkSkillObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject )
{
	talkSkillObject.abilityName = "";
	talkSkillObject.display = "";
	talkSkillObject.evade = false;
	talkSkillObject.abilityDamage = 0;
	talkSkillObject.abilityChance = 0;
	talkSkillObject.mod = 1;
	talkSkillObject.rangeMax = 3;
	talkSkillObject.rangeMin = 1;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int talkSkillRoll = 0;
	int talkSkillConfirm = 2;

	mimeObject.mimeTalkConfirm = 0;

	if( talkSkillObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( talkSkillObject.confirm != 0 ) 
	{
		do
		{

			if( talkSkillObject.playerInput == 1 )
			{
				talkSkillObject.abilityName = "Invitation";
				talkSkillObject.display = "-- Invite Enemy";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 1;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true
					|| target.teamName == actor.teamName || target.invite == true || target.petrify == true
					|| actor.silence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 20 );

					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
					
				}
				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						if( (actor.teamName == "Blue" && actor.charm == false )
							|| (actor.teamName == "Red" && actor.charm == true ) )
						{
							statusSetter( target, "Invite Blue" );
						}
						else if( (actor.teamName == "Red" && actor.charm == false )
							|| (actor.teamName == "Blue" && actor.charm == true ) )
						{
							statusSetter( target, "Invite Red" );
						}
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end Invitation loop

			if( talkSkillObject.playerInput == 2 )
			{
				talkSkillObject.abilityName = "Persuade";
				talkSkillObject.display = "-- CT to 0";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true || target.petrify == true || actor.silence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 30 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						target.ct = 0;
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " has CT set to 0!\n";
									
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end Persuade loop

			if( talkSkillObject.playerInput == 3 )
			{
				talkSkillObject.abilityName = "Praise";
				talkSkillObject.display = "-- Brave +4";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true || target.petrify == true || actor.silence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 50 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						target.brave += 4;
						if( target.brave >= 100 )
							target.brave = 100;

						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " has Brave increased by 4!\n";			
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end Praise loop

			else if( talkSkillObject.playerInput == 4 )
			{
				talkSkillObject.abilityName = "Threaten";
				talkSkillObject.display = "-- Brave -20";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true || target.petrify == true || actor.silence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 90 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						target.brave -= 20;
						if( target.brave <= 0 )
							target.brave = 0;

						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " has Brave decreased by 20!\n";
						if( target.brave <= 9 )
						{
							statusSetter( target, "Chicken");
						}
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end threaten loop

			else if( talkSkillObject.playerInput == 5 )
			{
				talkSkillObject.abilityName = "Preach";
				talkSkillObject.display = "-- Faith +4";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true || target.petrify == true || actor.silence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 50 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						target.faith += 4;
						if( target.faith >= 100 )
							target.faith = 100;

						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " has Faith increased by 4!\n";			
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end Preach loop

			else if( talkSkillObject.playerInput == 6 )
			{
				talkSkillObject.abilityName = "Solution";
				talkSkillObject.display = "-- Faith -20";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true
					|| target.petrify == true || actor.silence == true || target.faith == 0 )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 90 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						target.faith -= 20;
						if( target.faith <= 0 )
							target.faith = 0;

						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " has Faith decreased by 20!\n";
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end solution loop

			if( talkSkillObject.playerInput == 7 )
			{
				talkSkillObject.abilityName = "Death Sentence";
				talkSkillObject.display = "-- Add Death Sentence";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true ||
					target.dead == true || target.petrify == true || actor.silence == true
					|| target.deathSentence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 30 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						statusSetter( target, "Death Sentence" );

					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end Death Sentence loop

			if( talkSkillObject.playerInput == 8 )
			{
				talkSkillObject.abilityName = "Insult";
				talkSkillObject.display = "-- Add Berserk";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || target.sleep == true || target.dead == true
					|| target.petrify == true || actor.silence == true || target.berserk == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 40 );
					if( target.fingerGuard == true )
					{
						cout << "beta message inside finger guard loop " << talkSkillObject.abilityChance << "\n";
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								cout << "beta message inside inside if finger guard loop before " << talkSkillObject.abilityChance << "\n";
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
								cout << "beta message inside finger guard loop after " << talkSkillObject.abilityChance << "\n";
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					talkSkillRoll = rand() % 100 + 1;

					cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << talkSkillRoll << "\n";

					if( talkSkillRoll <= talkSkillObject.abilityChance )
					{
						statusSetter( target, "Berserk");

				
					}
					else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				} //ends player confirm loop
			}//end Insult loop

			if( talkSkillObject.playerInput == 9 )
			{
				talkSkillObject.abilityName = "Mimic Daravon";
				talkSkillObject.display = "-- Add Sleep to target and 4 surrounding squares";
				talkSkillObject.evade = false;
				talkSkillObject.abilityDamage = 0;
				talkSkillObject.abilityChance = 0;
				talkSkillObject.mod = 1;
				talkSkillObject.rangeMax = 3;
				talkSkillObject.rangeMin = 0;

				targetVector = rangeTest( actor, talkSkillObject.rangeMax,
					talkSkillObject.abilityName, talkSkillObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 40 );

				if( target.nullPlayer == true || target.sleep == true || target.dead == true
							|| target.petrify == true || actor.silence == true )
				{
					talkSkillObject.abilityChance = 0;	
				}
				else
				{
					talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 40 );
					if( target.fingerGuard == true )
					{
							if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
							&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
							&& target.confusion == false && target.berserk == false )
							{
								talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
							}
					}
				}

				talkSkillConfirm = targetDisplay( target, talkSkillObject.abilityName, talkSkillObject.abilityChance,
					0, talkSkillObject.display, true );

				if( talkSkillConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 5; i++ )
					{
						effectVector = multiRange( actor, 2, "Mimic Daravon", 3, 0, false, false,
							targetVector[0], targetVector[1] );
						target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
						if( target.nullPlayer == true || target.sleep == true || target.dead == true
							|| target.petrify == true || actor.silence == true )
						{
							talkSkillObject.abilityChance = 0;	
						}
						else
						{
							talkSkillObject.abilityChance = mod1( actor, target, actor.ma, 40 );
							if( target.fingerGuard == true )
							{
									if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
									&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
									&& target.confusion == false && target.berserk == false )
									{
										talkSkillObject.abilityChance = talkSkillObject.abilityChance * ( 100 - target.brave ) / 100;
									}
							}
						}
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							talkSkillRoll = rand() % 100 + 1;

							cout << talkSkillObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
										<< " " << target.playerName << ". " << talkSkillObject.abilityChance << "% chance to hit...\n";
							cout << "\tRandom Number is... " << talkSkillRoll << "\n";

							if( talkSkillRoll <= talkSkillObject.abilityChance )
							{
								statusSetter( target, "Sleep" );
								
							}
							else cout << "\t" << talkSkillObject.abilityName << " misses!\n";
							endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
						}// end targetting loop
						j += 2;
					} //end for loop
				} //ends player confirm loop
			}//end Mimic Daravon loop
			if( talkSkillConfirm == 1 && actor.silence == false )
			{
				mimeObject.mimeTalkConfirm = 1;
				mimeObject.abilityName = talkSkillObject.abilityName;
				vector<int> mimeVector (2 , 0);
				mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor);
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
				mimeObject.playerInput = talkSkillObject.playerInput;
			}
		}while( talkSkillConfirm == 2);
	}
		
	if( talkSkillConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void mimeTalkDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	vector<int> targetVector (2, 0);
	int targetLoop = 1;

	vector<int> effectVector (50, 0);
	
	targetVector = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic "<< mimeObject.abilityName << " on (" << targetVector[0]-1 << ", " << targetVector[1]-1 << ") ...\n";

	if( mimeObject.playerInput == 1 )
	{
		mimeObject.component = 20;
		if( (theMime.teamName == "Blue" && theMime.charm == false )
			|| (theMime.teamName == "Red" && theMime.charm == true ) )
		{
			mimeObject.status = "Invite Blue";
		}
		else if( (theMime.teamName == "Red" && theMime.charm == false )
			|| (theMime.teamName == "Blue" && theMime.charm == true ) )
		{
			mimeObject.status = "Invite Red";
		}
	}
	else if( mimeObject.playerInput == 2 )
	{
		mimeObject.component = 30;
		mimeObject.status = "Persuade";
	}
	else if( mimeObject.playerInput == 3 )
	{
		mimeObject.component = 50;
		mimeObject.status = "Praise";
	}
	else if( mimeObject.playerInput == 4 )
	{
		mimeObject.component = 90;
		mimeObject.status = "Threaten";
	}
	else if( mimeObject.playerInput == 5 )
	{
		mimeObject.component = 50;
		mimeObject.status = "Preach";
	}
	else if( mimeObject.playerInput == 6 )
	{
		mimeObject.component = 90;
		mimeObject.status = "Solution";
	}
	else if( mimeObject.playerInput == 7 )
	{
		mimeObject.component = 30;
		mimeObject.status = "Death Sentence";
	}
	else if( mimeObject.playerInput == 8 )
	{
		mimeObject.component = 40;
		mimeObject.status = "Berserk";
	}
	else if( mimeObject.playerInput == 9 )
	{
		mimeObject.component = 40;
		mimeObject.status = "Sleep";
	}

	if( theMime.silence == false )
	{
		target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( mimeObject.abilityName == "Mimic Daravon")
			mimeObject.effect = 2;
		else mimeObject.effect = 1;

		effectVector = multiRange( theMime, mimeObject.effect, mimeObject.abilityName, 5,
			0, false, false, targetVector[0], targetVector[1] );
		targetLoop = loopTarget( mimeObject.effect, false );

		int i = 0;
		int j = 0;

		for( i = 0; i < targetLoop; i++)
		{
			target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == false && target.dead == false && target.petrify == false )	
			{

				mimeObject.chance = mod1( theMime, target, theMime.ma, mimeObject.component );

				if( target.fingerGuard == true )
				{
					if( target.charging == false && target.performing == false && target.dontAct == false && target.chicken == false
					&& target.frog == false && target.sleep == false && target.stop == false && target.bloodSuck == false
					&& target.confusion == false && target.berserk == false )
					{
						mimeObject.chance = mimeObject.chance * ( 100 - target.brave ) / 100;
					}
				}

				hitRoll = rand() % 100 + 1;

				cout << "   " << mimeObject.abilityName << " targets " << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< ". Chance to hit is " << mimeObject.chance << "%...\n";
				cout << "   random number is... " << hitRoll << "\n";
			
				if( hitRoll <= mimeObject.chance )
				{
					cout << "   " << mimeObject.abilityName << " hits!\n";
					statusSetter( target, mimeObject.status );
				}
				else cout << "   " << mimeObject.abilityName << " misses!\n";
				endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
			} //ends targetting player loop
			j += 2;
		} //ends for loop
	}//silence check
	else cout << "   but is prevented by Silence!\n";
}


class PunchArt
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
	int abilityDamage2; //mp restore
	int abilityChance;
	int mod;
	int rangeMax;
	int rangeMin;
	int xa;
	
	PunchArt()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "physical";
		display = "";
		mod = 2;
		evade = true;
		abilityDamage = 0;
		abilityChance = 100;
		rangeMin = 1;
	}
	~PunchArt() {}

	void punchArtMenu( PunchArt &punchArtObject, Player actor );
	void punchArtSuccess( PunchArt &punchArtObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject
	);
};

void PunchArt::punchArtMenu( PunchArt &punchArtObject, Player actor )
{
	int punchArtAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " PUNCH ART Menu ---\n" 
	<< "0.) Return to Menu\n"  
	<< "1.) SPIN FIST       --  damage all adjacent units\n"
	<< "2.) REPEATING FIST  --  variable damage to target\n"
	<< "3.) WAVE FIST       --  damage target up to 3 squares away\n" 
	<< "4.) EARTH SLASH     --  damage all units in a line up to 8 squares away\n"  
	<< "5.) SECRET FIST     --  add Death Sentence\n"
	<< "6.) STIGMA MAGIC    --  cure many harmful status effects\n" 
	<< "7.) CHAKRA          --  restore HP and MP\n"
	<< "8.) REVIVE          --  revive Dead target\n" 
	) && 
	( !(cin >> punchArtAction ) || punchArtAction < 0 || punchArtAction > 8 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	punchArtObject.playerInput = punchArtAction;
	if( punchArtAction == 0 )
	{
		punchArtObject.confirm = 0;
	}
	else punchArtObject.confirm = 2;
}

void PunchArt::punchArtSuccess( PunchArt &punchArtObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject )
{
	punchArtObject.abilityName = "";
	punchArtObject.display = "";
	punchArtObject.evade = true;
	punchArtObject.abilityDamage = 0;
	punchArtObject.abilityChance = 0;
	punchArtObject.mod = 2;
	punchArtObject.rangeMax = 1;
	punchArtObject.rangeMin = 1;

	Player target;
	vector<int> rangeVector (50, 0);
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int punchArtRoll = 0;
	int punchArtConfirm = 2;

	mimeObject.mimePunchConfirm = 0;

	if( punchArtObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( punchArtObject.confirm != 0 ) 
	{
		do
		{

			if( punchArtObject.playerInput == 1 )
			{
				punchArtObject.abilityName = "Spin Fist";
				punchArtObject.display = "-- Damage to 4 surrounding squares -- HP ";
				punchArtObject.evade = true;
				punchArtObject.abilityDamage = 0;
				punchArtObject.abilityChance = 0;
				punchArtObject.mod = 2;
				punchArtObject.rangeMax = 1;
				punchArtObject.rangeMin = 1;

				rangeVector = multiRange( actor, 2, punchArtObject.abilityName, 1, 1, true, true );
				xaTemp = mod2xaDisplay( actor, actor, actor.pa );
				tempDamage = xaTemp * ( actor.pa / 2 );
				punchArtObject.abilityDamage = -mod2Damage( actor, actor, tempDamage );

				punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
					punchArtObject.abilityDamage, punchArtObject.display );

				if( punchArtConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 4; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							punchArtRoll = ( rand() % 100 ) + 1;
							xaTemp = mod2xa( actor, target, actor.pa );
							tempDamage = xaTemp * ( actor.pa / 2 );
							punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );
							punchArtObject.abilityChance = evadeFunction( 100, actor, target );

							cout << "Spin Fist targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << punchArtObject.abilityChance << "% chance to hit...\n";

							cout << "\tRandom Number is... " << punchArtRoll << "\n";
							if( punchArtRoll <= punchArtObject.abilityChance )
							{
								cout << "\t" << punchArtObject.abilityName << " hits!\n";
								if( actor.critKnockback == true )
								{
									knockback( actor, target, myArray );
									actor.critKnockback = false;
								}
								hpDamage( target, actor, blueItem, redItem, punchArtObject.abilityDamage, player1,
									player2, player3, player4, player5, player6, player7, player8, player9,
									player10  );

								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							}
							else cout << "\t" << punchArtObject.abilityName << " misses!\n";
						}//only targets players, skips if no one is surrounding
						j += 2;
					}//end for loop
				}
			}//end spin fist loop

			else if( punchArtObject.playerInput == 2) 
			{
				punchArtObject.abilityName = "Repeating Fist";
				punchArtObject.display = "-- Variable damage -- HP ";
				punchArtObject.evade = true;
				punchArtObject.mod = 2;
				punchArtObject.rangeMax = 1;
				punchArtObject.rangeMin = 1;

				rangeVector = rangeTest( actor, punchArtObject.rangeMax,
					punchArtObject.abilityName, punchArtObject.rangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					punchArtObject.abilityChance = 0;
					xaTemp = mod2xaDisplay( actor, target, actor.pa );
					tempDamage = 5 * ( xaTemp + ( actor.pa / 2 ) );
					punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );

					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display );
				}
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					punchArtObject.abilityChance = evadeFunction( 100, actor, target );
					xaTemp = mod2xaDisplay( actor, target, actor.pa );
					tempDamage = 5 * ( xaTemp + ( actor.pa / 2 ) );
					punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );

					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display );

					if( punchArtConfirm == 1 )
					{
						punchArtRoll = ( rand() % 100 ) + 1;
						tempRoll = rand() % 9 + 1;
						xaTemp = mod2xa( actor, target, actor.pa );
						tempDamage = tempRoll * ( xaTemp + ( actor.pa / 2 ) );
						punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );
						
						cout << "\tRandom Number is... " << punchArtRoll << "\n";
						if( punchArtRoll <= punchArtObject.abilityChance )
						{
							cout << "\t" << punchArtObject.abilityName << " hits!\n"; 
							if( actor.critKnockback == true )
							{
								knockback( actor, target, myArray );
								actor.critKnockback = false;
							}
							hpDamage( target, actor, blueItem, redItem, punchArtObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

							endTarget( target, player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, nullPlayer );
							}
						else cout << punchArtObject.abilityName << " misses!\n";
					}
				}
			}//ends repeating fist loop

			else if( punchArtObject.playerInput == 3 ) //wave fist
			{
				punchArtObject.abilityName = "Wave Fist";
				punchArtObject.display = "-- HP ";
				punchArtObject.evade = true;
			
				punchArtObject.mod = 2;
				punchArtObject.rangeMax = 3;
				punchArtObject.rangeMin = 1;

				rangeVector = rangeTest( actor, punchArtObject.rangeMax,
					punchArtObject.abilityName, punchArtObject.rangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					punchArtObject.abilityChance = 0;
					xaTemp = mod2xaDisplay( actor, target, actor.pa );
					tempDamage = xaTemp * ( (actor.pa + 2) / 2 );
					punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );

					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display );

				}
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					punchArtObject.abilityChance = evadeFunction( 100, actor, target );
					xaTemp = mod2xaDisplay( actor, target, actor.pa );
					tempDamage = xaTemp * ( (actor.pa + 2) / 2 );
					punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );

					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display );

					if( punchArtConfirm == 1 )
					{
						rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
							myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
							player10, nullPlayer, punchArtObject.abilityName );
						target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
								player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

						punchArtRoll = ( rand() % 100 ) + 1;
						xaTemp = mod2xa( actor, target, actor.pa );
						tempDamage = xaTemp * ( (actor.pa + 2) / 2 );
						punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage );
						
						cout << "\tRandom Number is... " << punchArtRoll << "\n";
						if( punchArtRoll <= punchArtObject.abilityChance )
						{
							cout << "\t" << punchArtObject.abilityName << " hits!\n"; 
							if( actor.critKnockback == true )
							{
								knockback( actor, target, myArray );
								actor.critKnockback = false;
							}
							hpDamage( target, actor, blueItem, redItem, punchArtObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

							endTarget( target, player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, nullPlayer );
							}
						else cout << punchArtObject.abilityName << " misses!\n";
					}
				}
			} //ends wave fist loop

			else if( punchArtObject.playerInput == 4 ) //earth slash
			{
				punchArtObject.abilityName = "Earth Slash";
				punchArtObject.display = "-- Damage in a straight line up to 8 squares -- HP ";
				punchArtObject.evade = false;
				punchArtObject.mod = 2;
				punchArtObject.rangeMax = 8;
				punchArtObject.rangeMin = 1;

				rangeVector = multiRange( actor, 8, punchArtObject.abilityName, punchArtObject.rangeMax,
					punchArtObject.rangeMin, true, true );
				xaTemp = mod2xaDisplay( actor, target, actor.pa, false, false, false, false, false, false, true );
				tempDamage = xaTemp * ( actor.pa / 2 );
				punchArtObject.abilityDamage = -mod2Damage( actor, actor, tempDamage, false, false, false, false, false, false, true );
							
				punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display );

				if( punchArtConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 8; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false )
						{
							punchArtRoll = ( rand() % 100 ) + 1;
							xaTemp = mod2xa( actor, target, actor.pa, false, false, false, false, false, false,
								true );
							tempDamage = xaTemp * ( actor.pa / 2 );
							punchArtObject.abilityDamage = -mod2Damage( actor, target, tempDamage, false, false, 
								false, false, false, false, true );
							punchArtObject.abilityChance = 100;

							cout << "Earth Slash targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << "... " << punchArtObject.abilityChance << "% chance to hit...\n";

							if( punchArtRoll <= punchArtObject.abilityChance )
							{
								cout << "\t" << punchArtObject.abilityName << " hits!\n"; 
								if( actor.critKnockback == true )
								{
									knockback( actor, target, myArray );
									actor.critKnockback = false;
								}
								hpDamage( target, actor, blueItem, redItem, punchArtObject.abilityDamage, player1,
									player2, player3, player4, player5, player6, player7, player8, player9,
									player10  );

								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
								}
							else cout << "\t" << punchArtObject.abilityName << " misses!\n";
						}//only targets players, skips if no one is surrounding
						j += 2;
					}//end for loop
				}
			} //ends earth slash loop

			else if( punchArtObject.playerInput == 5 ) //secret fist
			{
				punchArtObject.abilityName = "Secret Fist";
				punchArtObject.display = "-- Add Death Sentence";
				punchArtObject.evade = false;
				punchArtObject.mod = 3;
				punchArtObject.rangeMax = 1;
				punchArtObject.rangeMin = 1;

				rangeVector = rangeTest( actor, punchArtObject.rangeMax,
					punchArtObject.abilityName, punchArtObject.rangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.dead == true || target.petrify == true  )
				{
					punchArtObject.abilityChance = 0;

					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display, true );

				}
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					punchArtObject.abilityChance = mod3( actor, target, actor.ma, 50 ) + 50;
					if( target.deathSentence == true )
						punchArtObject.abilityChance = 0;
				
					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display, true );

					if( punchArtConfirm == 1 )
					{
						punchArtRoll = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is... " << punchArtRoll << "\n";
						
						if( punchArtRoll <= punchArtObject.abilityChance )
						{
							cout << "\t" << punchArtObject.abilityName << " hits!\n"; 
							statusSetter( target, "Death Sentence" );
		
							endTarget( target, player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, nullPlayer );
						}
						else cout << punchArtObject.abilityName << " misses!\n";
					}
				}
			} //ends secret fist

			else if( punchArtObject.playerInput == 6 ) //stigma magic
			{
				punchArtObject.abilityName = "Stigma Magic";
				punchArtObject.display = "-- Cure Petr/Dark/Conf/Frog/Sil/Ber/Pois/Sleep/Don't Move/Act";
				punchArtObject.evade = false;
				punchArtObject.mod = 3;
				punchArtObject.rangeMax = 1;
				punchArtObject.rangeMin = 0;

				rangeVector = multiRange( actor, 2, punchArtObject.abilityName, 1, 0, true, false );
				punchArtObject.abilityChance = mod3( actor, actor, actor.pa, 120 ) + 120;
				if( punchArtObject.abilityChance > 100 )
				{
					punchArtObject.abilityChance = 100;
				}

				punchArtConfirm = targetDisplay( actor, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display, true );

				if( punchArtConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 5; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false )
						{
							punchArtRoll = ( rand() % 100 ) + 1;
							punchArtObject.abilityChance = mod3( actor, target, actor.pa, 120 ) + 120;
							if( punchArtObject.abilityChance > 100 )
								punchArtObject.abilityChance = 100;

							cout << punchArtObject.abilityName << " targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << punchArtObject.abilityChance << "% chance to hit...\n";

							cout << "\tRandom Number is... " << punchArtRoll << "\n";
							if( punchArtRoll <= punchArtObject.abilityChance )
							{
								cout << "\t" << punchArtObject.abilityName << " hits!\n"; 
								target.petrify = false;
								target.darkness = false;
								target.confusion = false;
								target.frog = false;
								target.silence = false;
								target.berserk = false;
								target.poison = false;
								target.sleep = false;
								target.dontMove = false;
								target.dontAct = false;

								cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
									<< " is cured!\n";	
								
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							}
							else cout << "\t" << punchArtObject.abilityName << " misses!\n";
						}//only targets players, skips if no one is surrounding
						j += 2;
					}//end for loop
				}
			} //ends stigma magic
		
			else if( punchArtObject.playerInput == 7 ) //Chakra
			{
				punchArtObject.abilityName = "Chakra";
				punchArtObject.display = "";
				punchArtObject.evade = false;
				punchArtObject.mod = 2;
				punchArtObject.rangeMax = 1;
				punchArtObject.rangeMin = 0;

				rangeVector = multiRange( actor, 2, punchArtObject.abilityName, 1, 0, true, false );
				punchArtObject.abilityChance = 100;
				xaTemp = mod2xaDisplay( actor, actor, actor.pa, false, false, false, false, false,
								false, false, false, true  );
				tempDamage = 5 * xaTemp; //HP restore
				punchArtObject.abilityDamage = mod2Damage( actor, actor, tempDamage);
				//mp restore
				xaTemp2 = mod2xaDisplay( actor, actor, actor.pa, false, false, false, false, false,
								false, false, false, true  );
				tempDamage2 = 5 * xaTemp2 / 2;
				punchArtObject.abilityDamage2 = mod2Damage( actor, actor, tempDamage2 );
				
				while ( (cout << "\t" << punchArtObject.abilityName << " -- Restore " << punchArtObject.abilityDamage << " Life & "
					<< punchArtObject.abilityDamage2 << " MP -- " << punchArtObject.abilityChance << "%\n"
					<< "\t" << "CONFIRM:  1.) Yes  2.) No  3.) Menu\n") &&
						( !(cin >> punchArtConfirm) || punchArtConfirm < 1 || punchArtConfirm > 3 ) )
				{
					cout << "Invalid answer. Enter a valid number.\n";
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}

				if( punchArtConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 5; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							punchArtRoll = ( rand() % 100 ) + 1;
							punchArtObject.abilityChance = 100;
							xaTemp = mod2xaDisplay( actor, target, actor.pa, false, false, false, false, false,
								false, false, false, true  );
							tempDamage = 5 * xaTemp; //HP restore
							punchArtObject.abilityDamage = mod2Damage( actor, target, tempDamage);
							//mp restore
							xaTemp2 = mod2xaDisplay( actor, target, actor.pa, false, false, false, false, false,
								false, false, false, true );
							tempDamage2 = 5 * xaTemp2 / 2;
							punchArtObject.abilityDamage2 = mod2Damage( actor, target, tempDamage2 );

							cout << punchArtObject.abilityName << " targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << "\n";

							if( punchArtRoll <= punchArtObject.abilityChance )
							{
								target.life += punchArtObject.abilityDamage;
								target.mp += punchArtObject.abilityDamage2;
								if( target.life > target.maxLife )
									target.life = target.maxLife;
								if( target.mp > target.maxMP )
									target.mp = target.maxMP;

								cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
									<< " gains " << punchArtObject.abilityDamage << " Life & " << punchArtObject.abilityDamage2
									<< " MP!\n";
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							}
							else cout << "\t" << punchArtObject.abilityName << " misses!\n";
						}//only targets players, skips if no one is surrounding
						j += 2;
					}//end for loop
				}
			}

			else if( punchArtObject.playerInput == 8 ) //revive
			{
				punchArtObject.abilityName = "Revive";
				punchArtObject.display = "-- Revive Target with 20% Life -- HP ";
				punchArtObject.evade = false;
				punchArtObject.mod = 3;
				punchArtObject.rangeMax = 1;
				punchArtObject.rangeMin = 1;

				rangeVector = rangeTest( actor, punchArtObject.rangeMax,
					punchArtObject.abilityName, punchArtObject.rangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.dead == false || target.petrify == true )
				{
					punchArtObject.abilityChance = 0;

					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display, false );
				}
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					if( target.dead == true )
						punchArtObject.abilityChance = mod3( actor, target, actor.pa, 70 ) + 70;
					else punchArtObject.abilityChance = 0;
					if( punchArtObject.abilityChance > 100 )
					{
						punchArtObject.abilityChance = 100;
					}

					if( target.maxLife % 20 == 0 )
						tempDamage = 0;
					else tempDamage = 1;
					punchArtObject.abilityDamage = target.maxLife / 20 + tempDamage;
				
					punchArtConfirm = targetDisplay( target, punchArtObject.abilityName, punchArtObject.abilityChance,
						punchArtObject.abilityDamage, punchArtObject.display, false );

					if( punchArtConfirm == 1 )
					{
						punchArtRoll = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is... " << punchArtRoll << "\n";
						
						if( target.dead == true )
						{
							if( punchArtRoll <= punchArtObject.abilityChance )
							{
								cout << "\t" << punchArtObject.abilityName << " hits!\n"; 
								target.dead = false;
								target.life = punchArtObject.abilityDamage;
								cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
									<< " is restored to Life!\n";		
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							}
						}
						else cout << punchArtObject.abilityName << " misses!\n";
					}
				}
			} //end revive

			if( punchArtConfirm == 1)
			{
				mimeObject.mimePunchConfirm = 1;
				mimeObject.abilityName = punchArtObject.abilityName;
				vector<int> mimeVector (2 , 0);
				mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor);
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
				mimeObject.playerInput = punchArtObject.playerInput;
			}

		}while( punchArtConfirm == 2);
	}
		
	if( punchArtConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}


void mimePunchDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	vector<int> targetVector (2, 0);
	int targetLoop = 1;
	vector<int> effectVector (50, 0);

	//used for calculating damage
	int xaTemp = 0;
	int tempDamage = 0;
	
	mimeObject.casterImmune = false;
	mimeObject.ignoreDead = false;
	mimeObject.ignorePetrify = false;
	mimeObject.punchCrit = false;
	mimeObject.punchStatus = false;
	mimeObject.targetActor = false;
	
	targetVector = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic "<< mimeObject.abilityName << " on (" << targetVector[0]-1 << ", " << targetVector[1]-1 << ") ...\n";

	if( mimeObject.playerInput == 1 )
	{
		mimeObject.effect = 2;
		mimeObject.casterImmune = true;	
		mimeObject.punchCrit = true;
		mimeObject.targetActor = true;
	}
	else if( mimeObject.playerInput == 2 )
	{
		mimeObject.effect = 1;
		mimeObject.punchCrit = true;
	}
	else if( mimeObject.playerInput == 3 )
	{
		mimeObject.effect = 1;
		mimeObject.punchCrit = true;
	}
	else if( mimeObject.playerInput == 4 )
	{
		mimeObject.effect = 8;
		mimeObject.punchCrit = true;
		mimeObject.targetActor = true;
		mimeObject.casterImmune = true;
	}
	else if( mimeObject.playerInput == 5 )
	{
		mimeObject.component = 50;
		mimeObject.effect = 1;
		mimeObject.punchStatus = true;
		mimeObject.status = "Death Sentence";
	}
	else if( mimeObject.playerInput == 6 )
	{
		mimeObject.effect = 2;
		mimeObject.component = 120;
		mimeObject.status = "Stigma Magic";
		mimeObject.punchStatus = true;
		mimeObject.ignoreDead = true;
		mimeObject.targetActor = true;
	}
	else if( mimeObject.playerInput == 7 ) //chakra
	{
		mimeObject.effect = 2;
		mimeObject.targetActor = true;
	}
	else if( mimeObject.playerInput == 8 )
	{
		mimeObject.effect = 1;
		mimeObject.status = "Revive";
		mimeObject.punchStatus = true;
		mimeObject.ignoreDead = true;
	}

	
		target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );


		//caster immune in two places due to target actor part of it
		effectVector = multiRange( theMime, mimeObject.effect, mimeObject.abilityName, 8,
			0, mimeObject.targetActor, mimeObject.casterImmune, targetVector[0], targetVector[1], true );
		targetLoop = loopTarget( mimeObject.effect, false );

		int i = 0;
		int j = 0;

		for( i = 0; i < targetLoop; i++)
		{
			if( mimeObject.playerInput == 3 )
			{
				effectVector = rangeCollision( theMime.currentRow, theMime.currentCol, effectVector[0], effectVector[1],
					myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
					player10, nullPlayer, mimeObject.abilityName );
			}
	
			target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( target.nullPlayer == false && ( target.dead == false || mimeObject.ignoreDead == true )
				&& ( target.petrify == false || mimeObject.ignorePetrify == true ) )	
			{

				if( mimeObject.playerInput == 1 )
				{
					mimeObject.chance = evadeFunction( 100, theMime, target );
					xaTemp = mod2xa( theMime, target, theMime.pa );
					tempDamage = xaTemp * ( theMime.pa / 2 );
					mimeObject.damage = -mod2Damage( theMime, target, tempDamage );
				}
				else if( mimeObject.playerInput == 2 )
				{
					mimeObject.chance = evadeFunction( 100, theMime, target );
					xaTemp = mod2xa( theMime, target, theMime.pa );
					hitRoll = rand() % 9 + 1;
					tempDamage = hitRoll * ( xaTemp + ( theMime.pa / 2 ) );
					mimeObject.damage = -mod2Damage( theMime, target, tempDamage );
				}
				else if( mimeObject.playerInput == 3 )
				{
					mimeObject.chance = evadeFunction( 100, theMime, target );
					xaTemp = mod2xa( theMime, target, theMime.pa );
					tempDamage = xaTemp * ( ( theMime.pa + 2 ) / 2 );
					mimeObject.damage = -mod2Damage( theMime, target, tempDamage );
				}
				else if( mimeObject.playerInput == 4 )
				{
					if( target.statusFloat == false )
						mimeObject.chance = 100;
					else mimeObject.chance = 0;

					xaTemp = mod2xa( theMime, target, theMime.pa );
					tempDamage = xaTemp * ( theMime.pa / 2 );
					mimeObject.damage = -mod2Damage( theMime, target, tempDamage, false, false,
						false, false, false, false, true );
				}
				else if( mimeObject.playerInput == 5 )
				{
					mimeObject.chance = mod3( theMime, target, theMime.ma, 50 ) + 50;
				}
				else if( mimeObject.playerInput == 6 )
				{
					mimeObject.chance = mod3( theMime, target, theMime.ma, 120 ) + 120;
					if( mimeObject.chance > 100 )
						mimeObject.chance = 100;
				}
				else if( mimeObject.playerInput == 7 )
				{
					mimeObject.chance = 100;
					xaTemp = mod2xaDisplay( theMime, target, theMime.pa, false, false, false, false, false,
						false, false, false, true );
					tempDamage = xaTemp * 5;
					mimeObject.damage = mod2Damage( theMime, target, tempDamage );
					tempDamage = xaTemp * 5 / 2;
					mimeObject.punchMP = mod2Damage( theMime, target, tempDamage );
				}
				else if( mimeObject.playerInput == 8 )
				{
					mimeObject.chance = mod3( theMime, target, theMime.pa, 70 ) + 70;
				}

				hitRoll = rand() % 100 + 1;

				cout << "   " << mimeObject.abilityName << " targets " << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< ". Chance to hit is " << mimeObject.chance << "%...\n";
				cout << "   Random number is... " << hitRoll << "\n";
			
				if( hitRoll <= mimeObject.chance )
				{
					cout << "   " << mimeObject.abilityName << " hits!\n";
					if( mimeObject.punchStatus == true )
					{
						if( mimeObject.playerInput == 5 )
						{
							statusSetter( target, mimeObject.status );
						}
						else
						{
							statusRemover( target, mimeObject.status );
						}
					}
					else if( mimeObject.abilityName == "Chakra" )
					{
						target.life += mimeObject.damage;
						target.mp += mimeObject.punchMP;
						if( target.life > target.maxLife )
							target.life = target.maxLife;
						if( target.mp > target.maxMP )
							target.mp = target.maxMP;

						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " gains " << mimeObject.damage << " HP & " << mimeObject.punchMP
							<< " MP!\n";
					}
					else
					{
						hpDamage( target, theMime, blueItem, redItem, mimeObject.damage,
							player1, player2, player3, player4, player5, player6, player7,
							player8, player9, player10 );
						if( theMime.critKnockback == true )
						{
							knockback( theMime, target, myArray );
							theMime.critKnockback = false;
						}
					}
				}
				else cout << "\t" << mimeObject.abilityName << " misses!\n";
				endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
			} //ends targetting player loop
			j += 2;
		} //ends for loop
}


class Throw
{
public:

	//attributes
	int confirm;
	int weaponPower;
	int weaponType;
	int playerInput;
	int throwChance;
	string abilityName;
	string abilityType;
	string display;
	bool evade;
	bool fireBool;
	bool iceBool;
	bool lightningBool;
	bool waterBool;
	bool earthBool;
	bool windBool;
	bool darkBool;
	bool holyBool;

	int side;
	int distance;
	int mimeConfirm;

	//inventory
	int shuriken;
	int magicShuriken;
	int yagyuDarkness;
	int fireBall;
	int waterBall;
	int lightningBall;
	int slasher;
	int giantAxe;
	int scorpionTail;
	int javelin;
	int chaosBlade;
	
	Throw()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "physical";
		evade = true;
		fireBool = false;
		iceBool = false;
		lightningBool = false;
		waterBool = false;
		earthBool = false;
		windBool = false;
		darkBool = false;
		holyBool = false;

		//inventory
		weaponPower = 0;
		weaponType = 0;
		shuriken = 10;
		magicShuriken = 5;
		yagyuDarkness = 3;
		fireBall = 5;
		waterBall = 5;
		lightningBall = 5;
		slasher = 1;
		giantAxe = 1;
		scorpionTail = 1;
		javelin = 1;
		chaosBlade = 1;
	}
	~Throw() {}

	void throwMenu( Throw &throwObject, Player actor );
	void throwSuccess( Throw &throwObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem, MimeClass &mimeObject );
};

void Throw::throwMenu( Throw &throwObject, Player actor )
{
	int throwMenu = 0; 
	int throwAction = 0;
	throwObject.weaponPower = 0;
	throwObject.confirm = 2;
	throwObject.abilityName = "";
	throwObject.abilityType = "physical";
	throwObject.evade = true;
	throwObject.fireBool = false;
	throwObject.iceBool = false;
	throwObject.lightningBool = false;
	throwObject.waterBool = false;
	throwObject.earthBool = false;
	throwObject.windBool = false;
	throwObject.darkBool = false;
	throwObject.holyBool = false;

	while( ( cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " THROW Menu ---\n" 
		<< "0.) Return to Menu\n"
		<< "1.) Throw Shuriken\n"
		<< "2.) Throw Ball\n"
		<< "3.) Throw Other\n"
		)
		&& ( !(cin >> throwMenu) || throwMenu < 0 || throwMenu > 3  ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if( throwMenu == 1)
	{
		while( ( cout << "   --- Throw Shuriken -- Weapon Power (WP) ---\n"
		<< "0.) Return to Menu\n"
		<< "1.) Shuriken -- 4 WP" << setw(15) << "Remaining: " << throwObject.shuriken << "\n"
		<< "2.) Magic Shuriken -- 7 WP" << setw(15) << "Remaining: " << throwObject.magicShuriken << "\n"
		<< "3.) Yagyu Darkness -- 10 WP" << setw(15) << "Remaining: " << throwObject.yagyuDarkness << "\n"
		)
		&& ( !(cin >> throwAction) || throwAction < 0 || throwAction > 3
		|| ( throwObject.shuriken <= 0 && throwAction == 1 )
		|| ( throwObject.magicShuriken <= 0 && throwAction == 2 )
		|| ( throwObject.yagyuDarkness <= 0 && throwAction == 3 )
		) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( throwAction == 1)
		{
			throwObject.abilityName = "Throw Shuriken";
			throwObject.weaponPower = 4;
		}
		else if( throwAction == 2)
		{
			throwObject.abilityName = "Throw Magic Shuriken";
			throwObject.weaponPower = 7;
		}
		else if( throwAction == 3)
		{
			throwObject.abilityName = "Throw Yagyu Darkness";
			throwObject.weaponPower = 10;
		}
	}
	else if( throwMenu == 2)
	{
		while( ( cout << "   --- Throw Ball -- Weapon Power (WP) ---\n"
			<< "0.) Return to Menu\n"
		<< "1.) Fire Ball -- 8 WP" << setw(15) << "Remaining: " << throwObject.fireBall << "\n"
		<< "2.) Water Ball -- 8 WP" << setw(15) << "Remaining: " << throwObject.waterBall << "\n"
		<< "3.) Lightning Ball -- 8 WP" << setw(15) << "Remaining: " << throwObject.lightningBall << "\n"
		)
		&& ( !(cin >> throwAction) || throwAction < 0 || throwAction > 3
		|| ( throwObject.fireBall <= 0 && throwAction == 1 )
		|| ( throwObject.waterBall <= 0 && throwAction == 2 )
		|| ( throwObject.lightningBall <= 0 && throwAction == 3 )
		) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( throwAction == 1)
		{
			throwObject.abilityName = "Throw Fire Ball";
			throwObject.weaponPower = 8;
			throwObject.fireBool = true;
		}
		if( throwAction == 2)
		{
			throwObject.abilityName = "Throw Water Ball";
			throwObject.weaponPower = 8;
			throwObject.waterBool = true;
		}
		if( throwAction == 3)
		{
			throwObject.abilityName = "Throw Lightning Ball";
			throwObject.weaponPower = 8;
			throwObject.lightningBool = true;
		}
	}

	else if( throwMenu == 3 )
	{
		while( ( cout << "   --- Throw Weapon -- Weapon Power (WP) ---\n"
			<< "0.) Return to Menu\n"
		<< "1.) Slasher -- 12 WP" << setw(15) << "Remaining: " << throwObject.slasher << "\n"
		<< "2.) Giant Axe -- 16 WP" << setw(15) << "Remaining: " << throwObject.giantAxe << "\n"
		<< "3.) Scorpion Tail -- 23 WP" << setw(15) << "Remaining: " << throwObject.scorpionTail << "\n"
		)
		&& ( !(cin >> throwAction) || throwAction < 0 || throwAction > 5
		|| ( throwObject.slasher <= 0 && throwAction == 1 )
		|| ( throwObject.giantAxe <= 0 && throwAction == 2 )
		|| ( throwObject.scorpionTail <= 0 && throwAction == 3 )
		|| ( throwObject.javelin <= 0 && throwAction == 4 )
		|| ( throwObject.chaosBlade <= 0 && throwAction == 5 )
		) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( throwAction == 1)
		{
			throwObject.abilityName = "Throw Slasher";
			throwObject.weaponPower = 12;
		}
		else if( throwAction == 2)
		{
			throwObject.abilityName = "Throw Giant Axe";
			throwObject.weaponPower = 16;
		}
		else if( throwAction == 3)
		{
			throwObject.abilityName = "Throw Scorpion Tail";
			throwObject.weaponPower = 23;
		}
		else if( throwAction == 4)
		{
			throwObject.abilityName = "Throw Javelin";
			throwObject.weaponPower = 30;
		}
		else if( throwAction == 5 )
		{
			throwObject.abilityName = "Throw Chaos Blade";
			throwObject.weaponPower = 40;
		}
	}

		throwObject.playerInput = throwAction;
		if( throwAction == 0 || throwMenu == 0 )
		{
			throwObject.confirm = 0;
		}
		else throwObject.confirm = 2;
}

void ninjaThrowInventory( Throw &throwObject )
{
	if( throwObject.abilityName == "Throw Shuriken" )
		--throwObject.shuriken;
	if( throwObject.abilityName == "Throw Magic Shuriken" )
		--throwObject.magicShuriken;
	if( throwObject.abilityName == "Throw Yagyu Darkness" )
		--throwObject.yagyuDarkness;
	if( throwObject.abilityName == "Throw Fire Ball" )
		--throwObject.fireBall;
	if( throwObject.abilityName == "Throw Water Ball" )
		--throwObject.waterBall;
	if( throwObject.abilityName == "Throw Lightning Ball" )
		--throwObject.lightningBall;
	if( throwObject.abilityName == "Throw Slasher" )
		--throwObject.slasher;
	if( throwObject.abilityName == "Throw Giant Axe" )
		--throwObject.giantAxe;
	if( throwObject.abilityName == "Throw Scorpion Tail" )
		--throwObject.scorpionTail;
	if( throwObject.abilityName == "Throw Javelin" )
		--throwObject.javelin;
	if( throwObject.abilityName == "Throw Chaos Blade" )
		--throwObject.chaosBlade;
}

int ninjaThrowDamage(Player actor, Player &target, Throw throwObject )
{
	int xa = actor.speed;
	int ninjaDamage = 0;

	elementDefenseTest( target );

	if( target.defenseUp == true )
		xa = xa * 2 / 3 ;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.frog == true || target.chicken == true )
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );
	ninjaDamage = xa * throwObject.weaponPower;

	//no elemental factors
	if( throwObject.fireBool == false && throwObject.waterBool == false &&
		throwObject.iceBool == false && throwObject.lightningBool == false &&
		throwObject.holyBool == false && throwObject.darkBool == false &&
		throwObject.windBool == false && throwObject.earthBool == false )
		return ninjaDamage;
	//target weak against elementals
	else if( (throwObject.fireBool == true && target.fireWeak == true ) ||
		(throwObject.waterBool == true && target.waterWeak == true ) ||
		(throwObject.iceBool == true && target.iceWeak == true ) ||
		(throwObject.lightningBool == true && target.lightningWeak == true ) ||
		(throwObject.windBool == true && target.windWeak == true ) ||
		(throwObject.earthBool == true && target.earthWeak == true ) ||
		(throwObject.darkBool == true && target.darkWeak == true ) ||
		(throwObject.holyBool == true && target.holyWeak == true ) )
		return ninjaDamage * 2;
	//target half against elementals
	else if( (throwObject.fireBool == true && target.fireHalf == true ) ||
		(throwObject.waterBool == true && target.waterHalf == true ) ||
		(throwObject.iceBool == true && target.iceHalf == true ) ||
		(throwObject.lightningBool == true && target.lightningHalf == true ) ||
		(throwObject.windBool == true && target.windHalf == true ) ||
		(throwObject.earthBool == true && target.earthHalf == true ) ||
		(throwObject.darkBool == true && target.darkHalf == true ) ||
		(throwObject.holyBool == true && target.holyHalf == true ) )
		return ninjaDamage / 2;
	//target absorb against elementals
	else if( (throwObject.fireBool == true && target.fireAbsorb == true ) ||
		(throwObject.waterBool == true && target.waterAbsorb == true ) ||
		(throwObject.iceBool == true && target.iceAbsorb == true ) ||
		(throwObject.lightningBool == true && target.lightningAbsorb == true ) ||
		(throwObject.windBool == true && target.windAbsorb == true ) ||
		(throwObject.earthBool == true && target.earthAbsorb == true ) ||
		(throwObject.darkBool == true && target.darkAbsorb == true ) ||
		(throwObject.holyBool == true && target.holyAbsorb == true ) )
	{
		ninjaDamage *= -1;
		return ninjaDamage;
	}
	else if( (throwObject.fireBool == true && target.fireBlock == true ) ||
		(throwObject.waterBool == true && target.waterBlock == true ) ||
		(throwObject.iceBool == true && target.iceBlock == true ) ||
		(throwObject.lightningBool == true && target.lightningBlock == true ) ||
		(throwObject.windBool == true && target.windBlock == true ) ||
		(throwObject.earthBool == true && target.earthBlock == true ) ||
		(throwObject.darkBool == true && target.darkBlock == true ) ||
		(throwObject.holyBool == true && target.holyBlock == true ) )
	{
		ninjaDamage = 0;
		return ninjaDamage;
	}
	else return ninjaDamage;
}

void Throw::throwSuccess( Throw &throwObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem, MimeClass &mimeObject )
{
	Player target;
	bool golemTest = false;
	int throwConfirm = 2;
	int throwDamage = 0;
	bool ninjaThrow = true;
	vector<int> rangeVector (2, 0);
	vector<int> mimeVector (2, 0);
	throwObject.display = "-- HP ";

	mimeObject.mimeThrowConfirm = 0;

	if( throwObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( throwObject.confirm != 0 ) //begins throw calculations
	{
		do
		{
			rangeVector = rangeTest( actor, actor.move, throwObject.abilityName );
			target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			
				
			
		
			throwObject.throwChance = counterGraspEvade( 100, actor, target, ninjaThrow );
			throwDamage = -ninjaThrowDamage( actor, target, throwObject );
				
			throwConfirm = targetDisplay( target, throwObject.abilityName, throwObject.throwChance,
				throwDamage, throwObject.display );

			

			if( throwConfirm == 1 )
			{
				rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
					myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
					player10, nullPlayer, throwObject.abilityName );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				throwObject.throwChance = counterGraspEvade( 100, actor, target, ninjaThrow );
				throwDamage = -ninjaThrowDamage( actor, target, throwObject );

				ninjaThrowInventory( throwObject );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					cout << "\t" << actor.teamName << " " << actor.playerClassName << " " <<actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
					
				}
				else
				{
					int rollAttack;
					rollAttack = ( rand() % 100 ) + 1;
					cout << "\tChance to hit is " << throwObject.throwChance << " random number is... " << rollAttack << '\n';
					if ( rollAttack <= throwObject.throwChance )
					{
						golemTest = golemTester( target, blueGolem, redGolem );
						if( golemTest == true )
						{
							golemDestroyer( target, blueGolem, redGolem, throwDamage );
						}
						else
						{
							hpDamage( target, actor, blueItem, redItem, throwDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10 );
						}
					}
					else
					{
						cout << "\t" << "Throw misses!\n";
					}
				}
				counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
				counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
				endTarget( target, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer );
				
			}
			
			if( throwConfirm == 1)
			{
				mimeObject.mimeThrowConfirm = 1;
				mimeObject.abilityName = throwObject.abilityName;
				mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor);
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
				mimeObject.playerInput = throwObject.playerInput;
				mimeObject.fireBool = throwObject.fireBool;
				mimeObject.iceBool = throwObject.iceBool;
				mimeObject.lightningBool = throwObject.lightningBool;
				mimeObject.waterBool = throwObject.waterBool;
				mimeObject.earthBool = throwObject.earthBool;
				mimeObject.windBool = throwObject.windBool;
				mimeObject.holyBool = throwObject.holyBool;
				mimeObject.darkBool = throwObject.darkBool;
				mimeObject.throwWeaponPower = throwObject.weaponPower;
			}
		}while(throwConfirm == 2);
	}
	if( throwConfirm == 3 )
	{
		actor.confirm = 3;
	}
}

int mimeNinjaThrowDamage(Player actor, Player &target, MimeClass mimeObject )
{
	int xa = actor.speed;
	int ninjaDamage = 0;

	elementDefenseTest( target );

	if( target.defenseUp == true )
		xa = xa * 2 / 3 ;
	if( target.protect == true )
		xa = xa * 2 / 3;
	if( target.charging == true )
		xa = xa * 3 / 2;
	if( target.sleep == true )
		xa = xa * 3 / 2;
	if( target.frog == true || target.chicken == true )
		xa = xa * 3 / 2;
	xa = zodiac( xa, actor, target );
	ninjaDamage = xa * mimeObject.throwWeaponPower;

	//no elemental factors
	if( mimeObject.fireBool == false && mimeObject.waterBool == false &&
		mimeObject.iceBool == false && mimeObject.lightningBool == false &&
		mimeObject.holyBool == false && mimeObject.darkBool == false &&
		mimeObject.windBool == false && mimeObject.earthBool == false )
		return ninjaDamage;
	//target weak against elementals
	else if( (mimeObject.fireBool == true && target.fireWeak == true ) ||
		(mimeObject.waterBool == true && target.waterWeak == true ) ||
		(mimeObject.iceBool == true && target.iceWeak == true ) ||
		(mimeObject.lightningBool == true && target.lightningWeak == true ) ||
		(mimeObject.windBool == true && target.windWeak == true ) ||
		(mimeObject.earthBool == true && target.earthWeak == true ) ||
		(mimeObject.darkBool == true && target.darkWeak == true ) ||
		(mimeObject.holyBool == true && target.holyWeak == true ) )
		return ninjaDamage * 2;
	//target half against elementals
	else if( (mimeObject.fireBool == true && target.fireHalf == true ) ||
		(mimeObject.waterBool == true && target.waterHalf == true ) ||
		(mimeObject.iceBool == true && target.iceHalf == true ) ||
		(mimeObject.lightningBool == true && target.lightningHalf == true ) ||
		(mimeObject.windBool == true && target.windHalf == true ) ||
		(mimeObject.earthBool == true && target.earthHalf == true ) ||
		(mimeObject.darkBool == true && target.darkHalf == true ) ||
		(mimeObject.holyBool == true && target.holyHalf == true ) )
		return ninjaDamage / 2;
	//target absorb against elementals
	else if( (mimeObject.fireBool == true && target.fireAbsorb == true ) ||
		(mimeObject.waterBool == true && target.waterAbsorb == true ) ||
		(mimeObject.iceBool == true && target.iceAbsorb == true ) ||
		(mimeObject.lightningBool == true && target.lightningAbsorb == true ) ||
		(mimeObject.windBool == true && target.windAbsorb == true ) ||
		(mimeObject.earthBool == true && target.earthAbsorb == true ) ||
		(mimeObject.darkBool == true && target.darkAbsorb == true ) ||
		(mimeObject.holyBool == true && target.holyAbsorb == true ) )
	{
		ninjaDamage *= -1;
		return ninjaDamage;
	}
	else if( (mimeObject.fireBool == true && target.fireBlock == true ) ||
		(mimeObject.waterBool == true && target.waterBlock == true ) ||
		(mimeObject.iceBool == true && target.iceBlock == true ) ||
		(mimeObject.lightningBool == true && target.lightningBlock == true ) ||
		(mimeObject.windBool == true && target.windBlock == true ) ||
		(mimeObject.earthBool == true && target.earthBlock == true ) ||
		(mimeObject.darkBool == true && target.darkBlock == true ) ||
		(mimeObject.holyBool == true && target.holyBlock == true ) )
	{
		ninjaDamage = 0;
		return ninjaDamage;
	}
	else return ninjaDamage;
}

void mimeThrowDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	bool golemTest = false;
	vector<int> targetVec (2, 0);
	vector<int> rangeVector (2, 0);
	
	targetVec = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic " << mimeObject.abilityName << " on (" << targetVec[0]-1 << ", " << targetVec[1]-1 << ") ...\n";

	rangeVector = rangeCollision( theMime.currentRow, theMime.currentCol, targetVec[0], targetVec[1],
		myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
		player10, nullPlayer, mimeObject.abilityName );
	target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

	if( target.dead == false && target.petrify == false && target.nullPlayer == false )
	{
		hitRoll = rand() % 100 + 1;

		//ninja throw false on purpose since mime throws can't be caught
		mimeObject.chance = counterGraspEvade( 100, theMime, target, false,
			"physical", false );

		mimeObject.damage = -mimeNinjaThrowDamage( theMime, target, mimeObject );

		cout << "\t"<< mimeObject.abilityName << " chance to hit is " << mimeObject.chance << "%. Random number is..." << hitRoll << "\n";
		if( hitRoll <= mimeObject.chance )
		{
			golemTest = golemTester( target, blueGolem, redGolem );
			if( golemTest == true )
			{
				golemDestroyer( target, blueGolem, redGolem, mimeObject.damage );
			}
			else
			{
				hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1, player2,
					player3, player4, player5, player6, player7, player8, player9, player10 );
			}
		}
		else cout << "\tmisses!\n";
		counterGraspReaction( theMime, target, myArray, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem,
			redGolem );
		endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );
	}
	else cout << "\tand it has no effect.\n";

}