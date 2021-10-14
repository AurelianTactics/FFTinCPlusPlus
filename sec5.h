class MathSkill
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	string display;
	string status;
	bool evade;
	long int component;
	int mathInteger;
	int displayDamage;
	int abilityDamage;
	int abilityDamage2; 
	int abilityChance;
	int abilityCTRCount;
	int mod;
	int rangeMax;
	int rangeMin;
	int xa;
	int effect;
	bool casterImmune;
	int mp;
	int ctrFollow;
	int mod6Damage;
	bool reflect;
	bool fireType;
	bool iceType;
	bool lightningType;
	bool waterType;
	bool earthType;
	bool windType;
	bool holyType;
	bool darkType;
	bool cure;
	
	MathSkill()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "magical";
		display = "";
		mod = 5;
		evade = false;
		abilityDamage = 0;
		abilityChance = 0;
		rangeMin = 0;
		rangeMax = 4;
		component = 0;
		effect = 1;
		mathInteger = 0;
	}
	~MathSkill() {}

	void mathSkillMenu( MathSkill &mathSkillObject, Player actor );
	void mathSkillSuccess( MathSkill &mathSkillObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject );
};

void MathSkill::mathSkillMenu( MathSkill &mathSkillObject, Player actor )
{
	int mathSkillAction = 0;
	int mathSkillInteger = 0;
	mathSkillObject.mathInteger = 0;

	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " MATH SKILL Math Menu ---\n" 	
		<< "0.) Return to Menu\n" 
		<< "1.) CT Prime Number\n"
		<< "2.) CT 5\n"
		<< "3.) CT 4\n"
		<< "4.) CT 3\n"
	) && 
	( !(cin >> mathSkillInteger ) || mathSkillInteger < 0 || mathSkillInteger > 4 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	//white magic
	if( mathSkillInteger > 0 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
	{
		while( (cout << "\n"
			<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " MATH SKILL Spell Menu ---\n" 	
			<< "0.) Return to Menu\n" 
			<< "1.) CURE   \n"
			<< "2.) CURE 2  \n"  
			<< "3.) CURE 3  \n"
			<< "4.) RAISE    \n"
			<< "5.) RAISE 2  \n"  
			<< "6.) RERAISE   \n" 
			<< "7.) REGEN   \n" 
			<< "8.) PROTECT  \n"  
			<< "9.) SHELL \n"
			<< "10.) WALL \n"
			<< "11.) ESUNA   \n"  
			<< "12.) HOLY  \n"
		) && 
		( !(cin >> mathSkillAction ) || mathSkillAction < 0 || mathSkillAction > 12 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//black magic
	else if( mathSkillInteger > 0 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
	{
		while( (cout << "\n"
			<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " MATH SKILL Spell Menu ---\n" 	
			<< "0.) Return to Menu\n" 
			<< "1.) FIRE    \n"
			<< "2.) FIRE 2  \n"  
			<< "3.) FIRE 3  \n"
			<< "4.) BOLT    \n"
			<< "5.) BOLT 2  \n"  
			<< "6.) BOLT 3  \n" 
			<< "7.) ICE     \n" 
			<< "8.) ICE 2  \n"  
			<< "9.) ICE 3  \n"
			<< "10.) POISON \n"
			<< "11.) FROG   \n"  
			<< "12.) DEATH  \n"
			<< "13.) FLARE  \n"
		) && 
		( !(cin >> mathSkillAction ) || mathSkillAction < 0 || mathSkillAction > 13 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//yin yang magic
	else if( mathSkillInteger > 0 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
	{
		while( (cout << "\n"
			<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " MATH SKILL Spell Menu ---\n" 	
			<< "0.) Return to Menu\n" 
			<< "1.) BLIND   \n"
			<< "2.) PRAY FAITH  \n"  
			<< "3.) DOUBT FAITH \n"
			<< "4.) ZOMBIE   \n"
			<< "5.) SILENCE SONG  \n"  
			<< "6.) BLIND RAGE\n" 
			<< "7.) FOXBIRD\n" 
			<< "8.) CONFUSION SONG\n"  
			<< "9.) DISPEL MAGIC \n"
			<< "10.) PARALYZE \n"
			<< "11.) SLEEP   \n"  
			<< "12.) PETRIFY  \n"
		) && 
		( !(cin >> mathSkillAction ) || mathSkillAction < 0 || mathSkillAction > 12 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	//time magic
	else if( mathSkillInteger > 0 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
	{
		while( (cout << "\n"
			<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " MATH SKILL Spell Menu ---\n" 	
			<< "0.) Return to Menu\n" 
			<< "1.) HASTE  \n"
			<< "2.) SLOW  \n"  
			<< "3.) STOP  \n"
			<< "4.) DON'T MOVE   \n"
			<< "5.) FLOAT \n"  
			<< "6.) REFLECT  \n" 
			<< "7.) DEMI     \n" 
			<< "8.) DEMI 2  \n"  
		) && 
		( !(cin >> mathSkillAction ) || mathSkillAction < 0 || mathSkillAction > 8 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else if( mathSkillInteger > 0 )
	{
		cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " knows no spells...\n";
		mathSkillAction = 0;
	}

	if( mathSkillInteger == 1 )
	{
		mathSkillObject.mathInteger = 7;
		mathSkillObject.display = "CT Prime Number";
	}
	if( mathSkillInteger == 2 )
	{
		mathSkillObject.mathInteger = 5;
		mathSkillObject.display = "CT 5";
	}
	if( mathSkillInteger == 3 )
	{
		mathSkillObject.mathInteger = 4;
		mathSkillObject.display = "CT 4";
	}
	if( mathSkillInteger == 4 )
	{
		mathSkillObject.mathInteger = 3;
		mathSkillObject.display = "CT 3";
	}
	
	mathSkillObject.playerInput = mathSkillAction;

	if( mathSkillAction == 0 || mathSkillInteger == 0 )
	{
		mathSkillObject.confirm = 0;
	}
	else mathSkillObject.confirm = 2;
}

void mathSkillDamageDisplay( MathSkill &mathSkillObject, Player &actor, Player &target )
{
	if( mathSkillObject.mod == 5 )
	{
		mathSkillObject.abilityChance = magicEvade( 100, actor, target );
		if( mathSkillObject.abilityName == "Holy" )
			mathSkillObject.abilityChance = 100;
		mathSkillObject.abilityDamage = -mod5Magic( actor, target, actor.ma, mathSkillObject.component,
			mathSkillObject.fireType, mathSkillObject.iceType, mathSkillObject.waterType, mathSkillObject.lightningType,
			mathSkillObject.holyType );
	}
	else if( mathSkillObject.mod == 6 )
	{
		mathSkillObject.abilityChance = mod6( actor, target, actor.ma, mathSkillObject.component,
												mathSkillObject.fireType, mathSkillObject.iceType, mathSkillObject.waterType, mathSkillObject.lightningType,
												mathSkillObject.holyType );
		if( mathSkillObject.evade == true )
			mathSkillObject.abilityChance = magicEvade( mathSkillObject.abilityChance, actor, target );
		mathSkillObject.abilityDamage = 0;
	}
	else if( mathSkillObject.mod == 15 )
	{
		mathSkillObject.abilityDamage = mod5White( actor, target, actor.ma, mathSkillObject.component,
												mathSkillObject.fireType, mathSkillObject.iceType, mathSkillObject.waterType, mathSkillObject.lightningType,
												mathSkillObject.holyType );
		mathSkillObject.abilityChance = 100;
	}
	else if( mathSkillObject.mod == 16 )
	{
		mathSkillObject.abilityChance = mod6White( actor, target, actor.ma, mathSkillObject.component,
												mathSkillObject.fireType, mathSkillObject.iceType, mathSkillObject.waterType, mathSkillObject.lightningType,
												mathSkillObject.holyType );
		if( ( mathSkillObject.abilityName == "Raise" || mathSkillObject.abilityName == "Raise 2" ) && target.dead == false && target.undead == false )
			mathSkillObject.abilityChance = 0;
		mathSkillObject.abilityDamage = 0;
	}

}

void mathSkillEligibleDisplay( MathSkill &mathSkillObject, Player &actor, Player &target )
{
	bool primeTest = true;
	target.showCT = target.ct;
	if( target.showCT > 100 )
		target.showCT = 100;

	if( target.dead == false && target.petrify == false && target.jumping == false && target.activePlayer == true )
	{

		if( ( mathSkillObject.mathInteger == 3 || mathSkillObject.mathInteger == 4 || mathSkillObject.mathInteger == 5 ) && target.ct > 0 )
		{
			if( target.showCT % mathSkillObject.mathInteger == 0 )
			{
				mathSkillDamageDisplay( mathSkillObject, actor, target );
				cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName;
				if( mathSkillObject.mod == 5 || mathSkillObject.mod == 15 )
				{
					cout << " -- HP " << mathSkillObject.abilityDamage << " -- " << mathSkillObject.abilityChance << "% -- REACTION: " << target.reaction << "\n";
				}
				else
				{
					cout << " -- " << mathSkillObject.abilityName << " -- " << mathSkillObject.abilityChance << "% -- REACTION: " << target.reaction << "\n";
				}
			}
		}
		else if(  mathSkillObject.mathInteger == 7  && target.ct > 0 )
		{
			int i = 2;
			for( i = 2; i < target.ct/2 + 1 ; i++ )
			{
				if( target.showCT % i == 0 )
					primeTest = false;
			}
			if( primeTest == true )
			{
				mathSkillDamageDisplay( mathSkillObject, actor, target );
				cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName;
				if( mathSkillObject.mod == 5 || mathSkillObject.mod == 15 )
				{
					cout << " -- HP " << mathSkillObject.abilityDamage << " -- " << mathSkillObject.abilityChance << "% -- REACTION: " << target.reaction << "\n";
				}
				else
				{
					cout << " -- " << mathSkillObject.abilityName << " -- " << mathSkillObject.abilityChance << "% -- REACTION: " << target.reaction << "\n";
				}
			}
		}
	} //check to see if target is dead, petrified, jumping and an active player
}

int mathSkillDisplay( MathSkill &mathSkillObject, Player &actor, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10)
{
	int confirmReturn = 0;
	
	cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " can use " << mathSkillObject.display << " " << mathSkillObject.abilityName
		<< " on:\n";
	mathSkillEligibleDisplay( mathSkillObject, actor, player1 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player2 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player3 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player4 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player5 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player6 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player7 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player8 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player9 );
	mathSkillEligibleDisplay( mathSkillObject, actor, player10 );

	confirmReturn = confirmFunctionMenu( confirmReturn );

	return confirmReturn;

}



void mathSkillEligibleDamage( MathSkill &mathSkillObject, Player &actor, Player &target, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7, Player &player8, Player &player9,
	Player &player10, Item &blueItem, Item &redItem )
{
	bool primeTest = true;
	int mathSkillRoll = 0;
	target.showCT = target.ct;
	if( target.showCT > 100 )
		target.showCT = 100;

	if( target.dead == false && target.petrify == false && target.jumping == false && target.activePlayer == true )
	{
		if( ( mathSkillObject.mathInteger == 3 || mathSkillObject.mathInteger == 4 || mathSkillObject.mathInteger == 5 ) && target.ct > 0 )
		{
			if( target.showCT % mathSkillObject.mathInteger == 0 )
			{
				mathSkillRoll = rand() % 100 + 1;
				mathSkillDamageDisplay( mathSkillObject, actor, target );
			
				cout << mathSkillObject.abilityChance << "% chance to hit " << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " random number is... " << mathSkillRoll << "\n";
				if( mathSkillRoll <= mathSkillObject.abilityChance )
				{
					if( mathSkillObject.mod == 5 || mathSkillObject.mod == 15 )
					{
						
						hpDamage( target, actor, blueItem, redItem, mathSkillObject.abilityDamage, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, mathSkillObject.cure );
						
					}
					else
					{
						statusSetter( target, mathSkillObject.status );
						if( mathSkillObject.abilityName == "Raise" || mathSkillObject.abilityName == "Raise 2"
							|| mathSkillObject.abilityName == "Demi" || mathSkillObject.abilityName == "Demi 2" )
						{
							if( mathSkillObject.abilityName == "Raise" )
							{
								mathSkillObject.mod6Damage = target.maxLife / 2 + target.maxLife % 2;
							}
							else if( mathSkillObject.abilityName == "Raise 2" )
							{
								mathSkillObject.mod6Damage = target.maxLife;
							}
							else if( mathSkillObject.abilityName == "Demi 2" )
							{
								mathSkillObject.mod6Damage = -target.maxLife/2 + -target.maxLife % 2;
							}
							else if( mathSkillObject.abilityName == "Demi" )
							{
								mathSkillObject.mod6Damage = -target.maxLife/4 + -target.maxLife % 2;
							}
							if( mathSkillObject.mod6Damage < 0 || ( mathSkillObject.mod6Damage > 0 && target.undead == true ) )
								hpReaction( target, blueItem, redItem, actor, mathSkillObject.mod6Damage );
						}
					}
				}
				else cout << "\t" << mathSkillObject.abilityName << " misses!\n";
			}
		}
		else if( mathSkillObject.mathInteger == 7 && target.ct > 0 )
		{
			int i = 2;
			for( i = 2; i < target.ct/2 + 1 ; i++ )
			{
				if( target.showCT % i == 0 )
					primeTest = false;
			}
			if( primeTest == true )
			{
				mathSkillRoll = rand() % 100 + 1;
				mathSkillDamageDisplay( mathSkillObject, actor, target );
			
				cout << mathSkillObject.abilityChance << "% chance to hit " << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " random number is... " << mathSkillRoll << "\n";
				if( mathSkillRoll <= mathSkillObject.abilityChance )
				{
					if( mathSkillObject.mod == 5 || mathSkillObject.mod == 15 )
					{
						hpDamage( target, actor, blueItem, redItem, mathSkillObject.abilityDamage, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, mathSkillObject.cure );
					}
					else
					{
						statusSetter( target, mathSkillObject.status );
						if( mathSkillObject.abilityName == "Raise" || mathSkillObject.abilityName == "Raise 2"
							|| mathSkillObject.abilityName == "Demi" || mathSkillObject.abilityName == "Demi 2" )
						{
							if( mathSkillObject.abilityName == "Raise" )
							{
								mathSkillObject.mod6Damage = target.maxLife / 2 + target.maxLife % 2;
							}
							else if( mathSkillObject.abilityName == "Raise 2" )
							{
								mathSkillObject.mod6Damage = target.maxLife;
							}
							else if( mathSkillObject.abilityName == "Demi 2" )
							{
								mathSkillObject.mod6Damage = -target.maxLife/2 + -target.maxLife % 2;
							}
							else if( mathSkillObject.abilityName == "Demi" )
							{
								mathSkillObject.mod6Damage = -target.maxLife/4 + -target.maxLife % 2;
							}
							hpReaction( target, blueItem, redItem, actor, mathSkillObject.mod6Damage );
						}
					}
				}
				else cout << "\t" << mathSkillObject.abilityName << " misses!\n";
			}
		}
	}//player is not petrified, dead, jumping and is an eligible player
}


void mimeMathFunction( MimeClass &mimeObject, MathSkill &mathSkillObject, Player &theMime, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Item &blueItem, Item &redItem, bool mimeMath = true )
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
				if( mimeMath == true )
				{
					cout << "\n" << "   --- MIME ACTION ---\n"
						<< theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
						<< " attempts to Mimic... \n";
					mathSkillEligibleDamage( mathSkillObject, theMime, player1, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player6, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player7, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player2, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player3, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player8, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player9, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player4, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player5, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
					mathSkillEligibleDamage( mathSkillObject, theMime, player10, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem);
				} //should always be true
			}// eligible status effect
		}//charmed or not charmed
	}//player is a mime
}


void MathSkill::mathSkillSuccess( MathSkill &mathSkillObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject )
{
	mathSkillObject.abilityName = "";
	mathSkillObject.evade = true;
	mathSkillObject.component = 0;
	mathSkillObject.abilityChance = 0;
	mathSkillObject.abilityDamage = 0;
	mathSkillObject.reflect = false; //math skill can't be reflected
	mathSkillObject.mod = 5; //mod 16 for white 6, mod 15 for white 5
	mathSkillObject.effect = 1;
	mathSkillObject.status = "";
	mathSkillObject.mod6Damage = 0;
	
	mathSkillObject.fireType = false;
	mathSkillObject.iceType = false;
	mathSkillObject.lightningType = false;
	mathSkillObject.waterType = false;
	mathSkillObject.earthType = false;
	mathSkillObject.windType = false;
	mathSkillObject.holyType = false;
	mathSkillObject.darkType = false;
	mathSkillObject.cure = false;
	

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int tempHitChance = 0;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int mathSkillRoll = 0;
	int mathSkillConfirm = 2;

	if( mathSkillObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( mathSkillObject.confirm != 0 ) 
	{
		do
		{
			if( mathSkillObject.playerInput  == 1 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Cure";
				mathSkillObject.evade = false;
				mathSkillObject.component = 14;
				mathSkillObject.mod = 15;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.cure = true;
			}
			else if( mathSkillObject.playerInput  == 2 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Cure 2";

				mathSkillObject.evade = false;
				mathSkillObject.component = 20;
				mathSkillObject.mod = 15;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.cure = true;
			}
			else if( mathSkillObject.playerInput  == 3 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Cure 3";

				mathSkillObject.evade = false;
				mathSkillObject.component = 30;
				mathSkillObject.mod = 15;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.cure = true;
			}
			else if( mathSkillObject.playerInput  == 4 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Raise";

				mathSkillObject.evade = false;
				mathSkillObject.component = 140;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Raise";
				mathSkillObject.cure = true;
			}
			else if( mathSkillObject.playerInput  == 5 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Raise 2";

				mathSkillObject.evade = false;
				mathSkillObject.component = 160;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Raise 2";
				mathSkillObject.cure = true;
			}
			else if( mathSkillObject.playerInput  == 6 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Reraise";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 140;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Reraise";
			}
			else if( mathSkillObject.playerInput  == 7 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Regen";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 170;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Regen";
			}
			else if( mathSkillObject.playerInput  == 8 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Protect";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 200;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Protect";
			}
			else if( mathSkillObject.playerInput  == 9 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Shell";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 200;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Shell";
			}
			else if( mathSkillObject.playerInput  == 10 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Wall";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 140;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Wall";
			}
			else if( mathSkillObject.playerInput  == 11 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Esuna";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 190;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Esuna";
			}
			else if( mathSkillObject.playerInput  == 12 && ( actor.playerNumber == 14 || actor.secondaryNumber == 14 ) )
			{
				mathSkillObject.abilityName = "Holy";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 50;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Protect";
				mathSkillObject.holyType = true;
			}
			else if( mathSkillObject.playerInput  == 1 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Fire";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 14;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.fireType = true;
			}
			else if( mathSkillObject.playerInput  == 2 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Fire 2";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 18;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.fireType = true;
			}
			else if( mathSkillObject.playerInput  == 3 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Fire 3";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 24;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.fireType = true;
			}
			else if( mathSkillObject.playerInput  == 4 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Bolt";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 14;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.lightningType = true;
			}
			else if( mathSkillObject.playerInput  == 5 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Bolt 2";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 18;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.lightningType = true;
			}
			else if( mathSkillObject.playerInput  == 6 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Bolt 3";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 24;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.lightningType = true;
			}
			else if( mathSkillObject.playerInput  == 7 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Ice";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 14;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.iceType = true;
			}
			else if( mathSkillObject.playerInput  == 8 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Ice 2";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 18;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.iceType = true;
			}
			else if( mathSkillObject.playerInput  == 9 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Ice 3";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 24;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
				mathSkillObject.iceType = true;
			}
			else if( mathSkillObject.playerInput  == 10 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Poison";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 160;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Poison";
			}
			else if( mathSkillObject.playerInput  == 11 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Frog";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 120;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Frog";
			}
			else if( mathSkillObject.playerInput  == 12 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Death";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 100;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Death Type";
			}
			else if( mathSkillObject.playerInput  == 13 && ( actor.playerNumber == 20 || actor.secondaryNumber == 20 ) )
			{
				mathSkillObject.abilityName = "Flare";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 46;
				mathSkillObject.mod = 5;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "";
			}
			else if( mathSkillObject.playerInput  == 1 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Haste";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 180;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Haste";
			}
			else if( mathSkillObject.playerInput  == 2 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Slow";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 180;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Slow";
			}
			else if( mathSkillObject.playerInput  == 3 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Stop";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 110;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Stop";
			}
			else if( mathSkillObject.playerInput  == 4 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Don't Move";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 190;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Don't Move";
			}
			else if( mathSkillObject.playerInput  == 5 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Float";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 140;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Float";
			}
			else if( mathSkillObject.playerInput  == 6 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Reflect";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 180;
				mathSkillObject.mod = 16;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Reflect";
			}
			else if( mathSkillObject.playerInput  == 7 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Demi";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 190;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Demi";
			}
			else if( mathSkillObject.playerInput  == 8 && ( actor.playerNumber == 19 || actor.secondaryNumber == 19 ) )
			{
				mathSkillObject.abilityName = "Demi 2";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 120;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Demi 2";
			}
			else if( mathSkillObject.playerInput  == 1 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Blind";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 200;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Darkness";
			}
			else if( mathSkillObject.playerInput  == 2 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Pray Faith";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 150;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Faith";
			}
			else if( mathSkillObject.playerInput  == 3 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Doubt Faith";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 150;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Innocent";
			}
			else if( mathSkillObject.playerInput  == 4 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Zombie";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 100;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Undead";
			}
			else if( mathSkillObject.playerInput  == 5 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Silence Song";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 180;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Silence";
			}
			else if( mathSkillObject.playerInput  == 6 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Blind Rage";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 120;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Berserk";
			}
			else if( mathSkillObject.playerInput  == 7 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Foxbird";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 140;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Foxbird";
			}
			else if( mathSkillObject.playerInput  == 8 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Confusion Song";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 130;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Confusion";
			}
			else if( mathSkillObject.playerInput  == 9 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Dispel Magic";
				
				mathSkillObject.evade = false;
				mathSkillObject.component = 200;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Dispel Magic";
			}
			else if( mathSkillObject.playerInput  == 10 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Paralyze";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 185;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Don't Act";
			}
			else if( mathSkillObject.playerInput  == 11 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Sleep";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 170;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Sleep";
			}
			else if( mathSkillObject.playerInput  == 12 && ( actor.playerNumber == 13 || actor.secondaryNumber == 13 ) )
			{
				mathSkillObject.abilityName = "Petrify";
				
				mathSkillObject.evade = true;
				mathSkillObject.component = 120;
				mathSkillObject.mod = 6;
				mathSkillObject.effect = 1;
				mathSkillObject.status = "Petrify";
			}

			mathSkillConfirm = mathSkillDisplay( mathSkillObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10 );

			if( mathSkillConfirm == 1 )
			{
				mathSkillEligibleDamage( mathSkillObject, actor, player1, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player2, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player3, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player4, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player5, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player6, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player7, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player8, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player9, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );
				mathSkillEligibleDamage( mathSkillObject, actor, player10, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem );

				mimeMathFunction( mimeObject, mathSkillObject, player1, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player6, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player7, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player2, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player3, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player8, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player9, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player4, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player5, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
				mimeMathFunction( mimeObject, mathSkillObject, player10, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, true );

			}
		}while( mathSkillConfirm == 2);
	}
		
	if( mathSkillConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void innerMimeSpell( MimeClass &mimeObject )
{
	//not set here: ability name, spellConfirm, side, distance
		//set later, chance damage
	mimeObject.effect = 2;
	mimeObject.mod = 5;
	mimeObject.evade = true;
	mimeObject.summonTypeAlly = false;
	mimeObject.summonTypeEnemy = false;
	mimeObject.cure = false;
	mimeObject.component = 0;
	mimeObject.status = "";
	//for spells, effect, mod, ability, name, evade, cure, damage, chance, component, and status are above

	mimeObject.reflect = false;
	mimeObject.fireType = false;
	mimeObject.iceType = false;
	mimeObject.lightningType = false;
	mimeObject.waterType = false;
	mimeObject.earthType = false;
	mimeObject.windType = false;
	mimeObject.holyType = false;
	mimeObject.darkType = false;
	mimeObject.casterImmune = false;
	mimeObject.ignoreDead = false;
	mimeObject.lightningType = false;
	mimeObject.counterMagic = false;

	if( mimeObject.abilityName == "Cure" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 15;
		mimeObject.effect = 2;
		mimeObject.component = 14;
		
		mimeObject.cure = true;
	}
	else if( mimeObject.abilityName == "Cure 2" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 15;
		mimeObject.effect = 2;
		mimeObject.component = 20;
		
		mimeObject.cure = true;
	}
	else if( mimeObject.abilityName == "Cure 3" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 15;
		mimeObject.effect = 2;
		mimeObject.component = 30;
		
		mimeObject.cure = true;
	}
	else if( mimeObject.abilityName == "Cure 4" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 15;
		mimeObject.effect = 2;
		mimeObject.component = 40;
		
		mimeObject.cure = true;
	}
	else if( mimeObject.abilityName == "Raise" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 180;
		
		mimeObject.status = "Raise";
		mimeObject.cure = true;
		mimeObject.ignoreDead = true;
	}
	else if( mimeObject.abilityName == "Raise 2" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 160;
		
		mimeObject.status = "Raise 2";
		mimeObject.cure = true;
		mimeObject.ignoreDead = true;
	}
	else if( mimeObject.abilityName == "Reraise" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 140;
		mimeObject.status = "Reraise";
	}
	else if( mimeObject.abilityName == "Regen" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 170;
		mimeObject.status = "Regen";
	}
	else if( mimeObject.abilityName == "Protect" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 200;
		mimeObject.status = "Protect";
	}
	else if( mimeObject.abilityName == "Protect 2" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 120;
		mimeObject.status = "Protect";
	}
	else if( mimeObject.abilityName == "Shell" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 200;
		mimeObject.status = "Shell";
	}
	else if( mimeObject.abilityName == "Shell 2" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 120;
		mimeObject.status = "Shell";
	}
	else if( mimeObject.abilityName == "Wall" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 140;
		mimeObject.status = "Wall";
	}
	else if( mimeObject.abilityName == "Esuna" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 190;
		mimeObject.status = "Esuna";

		mimeObject.ignorePetrify = true;
	}
	else if( mimeObject.abilityName == "Holy" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 1;
		mimeObject.component = 50;
		
		mimeObject.holyType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Fire" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 14;
		
		mimeObject.fireType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Fire 2" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 18;
		
		mimeObject.fireType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Fire 3" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 24;
		
		mimeObject.fireType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Fire 4" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 32;
		
		mimeObject.fireType = true;
		mimeObject.casterImmune = true;
	}
	else if( mimeObject.abilityName == "Ice" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 14;
		
		mimeObject.iceType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Ice 2" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 18;
		
		mimeObject.iceType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Ice 3" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 24;
		
		mimeObject.iceType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Ice 4" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 32;
		
		mimeObject.iceType = true;
		mimeObject.casterImmune = true;
	}
	else if( mimeObject.abilityName == "Bolt" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 14;
		
		mimeObject.lightningType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Bolt 2" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 18;
		
		mimeObject.lightningType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Bolt 3" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 2;
		mimeObject.component = 24;
		
		mimeObject.lightningType = true;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Bolt 4" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 32;
		
		mimeObject.lightningType = true;
		mimeObject.casterImmune = true;
	}
	else if( mimeObject.abilityName == "Poison" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 160;
		
		mimeObject.status = "Poison";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Frog" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 120;
		
		mimeObject.status = "Frog";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Death" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 100;
		
		mimeObject.status = "Death Type";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Flare" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 5;
		mimeObject.effect = 1;
		mimeObject.component = 46;
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Haste" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 180;
		
		mimeObject.status = "Haste";
	}
	else if( mimeObject.abilityName == "Haste 2" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 240;
		
		mimeObject.status = "Haste";
	}
	else if( mimeObject.abilityName == "Slow" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 180;
		
		mimeObject.status = "Slow";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Slow 2" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 240;
		
		mimeObject.status = "Slow";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Stop" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 110;
		
		mimeObject.status = "Stop";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Don't Move" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 190;
		
		mimeObject.status = "Don't Move";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Float" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 2;
		mimeObject.component = 140;
		
		mimeObject.status = "Float";
	}
	else if( mimeObject.abilityName == "Reflect" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 180;
		
		mimeObject.status = "Reflect";
	}
	else if( mimeObject.abilityName == "Quick" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 16;
		mimeObject.effect = 1;
		mimeObject.component = 140;
		
		mimeObject.status = "Quick";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Demi" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 190;
		
		mimeObject.status = "Demi";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Demi 2" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 120;
		
		mimeObject.status = "Demi 2";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Meteor" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 4;
		mimeObject.component = 60;

		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Blind" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 200;
		
		mimeObject.status = "Darkness";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Spell Absorb" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 160;
		
		mimeObject.status = "Spell Absorb";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Life Drain" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 160;
		
		mimeObject.status = "Life Drain";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Pray Faith" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 150;
		
		mimeObject.status = "Faith";
	}
	else if( mimeObject.abilityName == "Doubt Faith" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 150;
		
		mimeObject.status = "Innocent";
	}
	else if( mimeObject.abilityName == "Zombie" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 100;
		
		mimeObject.status = "Undead";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Silence Song" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 180;
		
		mimeObject.status = "Silence";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Blind Rage" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 120;
		
		mimeObject.status = "Berserk";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Foxbird" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 140;
		
		mimeObject.status = "Foxbird";
	}
	else if( mimeObject.abilityName == "Confusion Song" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 130;
		
		mimeObject.status = "Confusion";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Dispel Magic" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 200;
		
		mimeObject.status = "Dispel Magic";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Paralyze" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 185;
		
		mimeObject.status = "Don't Act";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Sleep" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 2;
		mimeObject.component = 170;
		
		mimeObject.status = "Sleep";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Petrify" )
	{
		mimeObject.evade = true;
		mimeObject.reflect = true;
		mimeObject.mod = 6;
		mimeObject.effect = 1;
		mimeObject.component = 120;
		
		mimeObject.status = "Petrify";
		mimeObject.counterMagic = true;
	}
	else if( mimeObject.abilityName == "Moogle" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 15;
		mimeObject.effect = 3;
		mimeObject.component = 12;
		
		mimeObject.summonTypeAlly = true;
		mimeObject.cure = true;
	}
	else if( mimeObject.abilityName == "Shiva" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 24;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.iceType = true;
	}
	else if( mimeObject.abilityName == "Ramuh" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 24;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.lightningType = true;
	}
	else if( mimeObject.abilityName == "Ifrit" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 24;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.fireType = true;
	}
	else if( mimeObject.abilityName == "Titan" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 28;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.earthType = true;
	}
	else if( mimeObject.abilityName == "Golem" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 26;
		mimeObject.effect = 0;
		mimeObject.component = 200;
		
		mimeObject.summonTypeAlly;
	}
	else if( mimeObject.abilityName == "Carbunkle" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 16;
		mimeObject.effect = 3;
		mimeObject.component = 150;
		
		mimeObject.summonTypeAlly = true;
		mimeObject.status = "Reflect";
		
	}
	else if( mimeObject.abilityName == "Bahamut" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 4;
		mimeObject.component = 46;
		
		mimeObject.summonTypeEnemy = true;
	}
	else if( mimeObject.abilityName == "Odin" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 4;
		mimeObject.component = 40;
		
		mimeObject.summonTypeEnemy = true;
	}
	else if( mimeObject.abilityName == "Leviathan" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 4;
		mimeObject.component = 38;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.waterType = true;
	}
	else if( mimeObject.abilityName == "Salamander" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 38;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.fireType = true;
	}
	else if( mimeObject.abilityName == "Silf" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 6;
		mimeObject.effect = 3;
		mimeObject.component = 150;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.status = "Silence";
	}
	else if( mimeObject.abilityName == "Fairy" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 15;
		mimeObject.effect = 3;
		mimeObject.component = 24;
		
		mimeObject.summonTypeAlly = true;
		mimeObject.cure = true;
	}
	else if( mimeObject.abilityName == "Lich" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 16;
		mimeObject.effect = 3;
		mimeObject.component = 160;
		
		mimeObject.summonTypeEnemy = true;
		mimeObject.status = "Lich";
		mimeObject.darkType = true;
	}
	else if( mimeObject.abilityName == "Cyclops" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 3;
		mimeObject.component = 50;
		
		mimeObject.summonTypeEnemy = true;
	}
	else if( mimeObject.abilityName == "Zodiac" )
	{
		mimeObject.evade = false;
		mimeObject.reflect = false;
		mimeObject.mod = 5;
		mimeObject.effect = 4;
		mimeObject.component = 96;
		
		mimeObject.summonTypeEnemy = true;
	}
}

void mimeSpellDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	vector<int> targetVector (2, 0);
	vector<int> refVec( 2, 0 );
	int targetLoop = 1;
	int spellSetterDamage = 0;

	vector<int> effectVector (50, 0);
	
	targetVector = mimeTargetVector( theMime, mimeObject.spellSide, mimeObject.spellDistance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic "<< mimeObject.abilityName << " on (" << targetVector[0]-1 << ", " << targetVector[1]-1 << ") ...\n";

	if( theMime.silence == false )
	{
		target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		innerMimeSpell( mimeObject );

		effectVector = multiRange( theMime, mimeObject.effect, mimeObject.abilityName, 5,
			0, false, false, targetVector[0], targetVector[1] );
		targetLoop = loopTarget( mimeObject.effect, mimeObject.casterImmune );

		int i = 0;
		int j = 0;

		for( i = 0; i < targetLoop; i++)
		{
			refVec = reflectVector( effectVector[j], effectVector[j+1], theMime,
				player1, player2, player3, player4, player5, player6, player7,
				player8, player9, player10, nullPlayer, myArray, mimeObject.reflect );
			effectVector[j] = refVec[0];
			effectVector[j+1] = refVec[1];
			target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

			if( 
				target.nullPlayer == false && ( target.dead == false || mimeObject.ignoreDead == true )
				&& ( target.petrify == false || mimeObject.ignorePetrify == true )
				)	
			{
				if(  //keeps summons from targetting units they shouldn't
					( mimeObject.summonTypeAlly == false && mimeObject.summonTypeEnemy == false )
					|| ( theMime.charm == false && mimeObject.summonTypeAlly == true && theMime.teamName == target.teamName )
					|| ( theMime.charm == true && mimeObject.summonTypeAlly == true && theMime.teamName != target.teamName )
					|| ( theMime.charm == false && mimeObject.summonTypeEnemy == true && theMime.teamName != target.teamName )
					|| ( theMime.charm == true && mimeObject.summonTypeEnemy == true && theMime.teamName == target.teamName )
					)
				{
			
					if( mimeObject.mod == 5 )
					{
						mimeObject.damage = -mod5Magic( theMime, target, theMime.ma, mimeObject.component,
							mimeObject.fireType, mimeObject.iceType, mimeObject.waterType, mimeObject.lightningType,
							mimeObject.holyType, mimeObject.darkType, mimeObject.earthType, mimeObject.windType );
						mimeObject.chance = 100;
						if( mimeObject.evade == true )
						{
							mimeObject.chance = magicEvade( mimeObject.chance, theMime, target );
						}
						if( mimeObject.casterImmune == true && theMime.turnOrder == target.turnOrder )
						{
							mimeObject.chance = 0;
						}
					}
					else if( mimeObject.mod == 15 )
					{
						mimeObject.damage = mod5White( theMime, target, theMime.ma, mimeObject.component,
							mimeObject.fireType, mimeObject.iceType, mimeObject.waterType, mimeObject.lightningType,
							mimeObject.holyType, mimeObject.darkType, mimeObject.earthType, mimeObject.windType );
						mimeObject.chance = 100;
						if( mimeObject.evade == true )
						{
							mimeObject.chance = magicEvade( mimeObject.chance, theMime, target );
						}
					}
					else if( mimeObject.mod	== 6 )
					{
						mimeObject.chance = mod6( theMime, target, theMime.ma, mimeObject.component,
							mimeObject.fireType, mimeObject.iceType, mimeObject.waterType, mimeObject.lightningType,
							mimeObject.holyType, mimeObject.darkType, mimeObject.earthType, mimeObject.windType );
						if( mimeObject.evade == true )
						{
							mimeObject.chance = magicEvade( mimeObject.chance, theMime, target );
						}
					}
					else if( mimeObject.mod == 16 )
					{
						mimeObject.chance = mod6White( theMime, target, theMime.ma, mimeObject.component,
							mimeObject.fireType, mimeObject.iceType, mimeObject.waterType, mimeObject.lightningType,
							mimeObject.holyType, mimeObject.darkType, mimeObject.earthType, mimeObject.windType );
						if( mimeObject.evade == true )
						{
							mimeObject.chance = magicEvade( mimeObject.chance, theMime, target );
						}
					}
					else if( mimeObject.mod == 26 )
					{
						mimeObject.chance = mod6Golem( theMime, theMime.ma, mimeObject.component );
					}

					hitRoll = rand() % 100 + 1;

					cout << "   " << mimeObject.abilityName << " targets " << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< ". Chance to hit is " << mimeObject.chance << "%...\n";
					cout << "   random number is... " << hitRoll << "\n";
			
					if( hitRoll <= mimeObject.chance )
					{
						cout << "   " << mimeObject.abilityName << " hits!\n";
						if( mimeObject.mod == 5 || mimeObject.mod == 15 )
						{
							hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1,
								player2, player3, player4, player5, player6, player7, player8, player9,
								player10, mimeObject.cure);
						}
						else if( mimeObject.mod == 6 || mimeObject.mod == 16 )
						{
							if( mimeObject.abilityName == "Lich" ||
								mimeObject.abilityName == "Demi" ||
								mimeObject.abilityName == "Demi 2" ||
								mimeObject.abilityName == "Spell Absorb" ||
								mimeObject.abilityName == "Life Drain"
								)
							{
								spellSetterDamage = spellSetter( target, mimeObject.abilityName, theMime );
								if( mimeObject.abilityName != "Spell Absorb" )
								{
									hpReaction( target, blueItem, redItem, theMime, spellSetterDamage );
									distributeReaction( target, theMime, player1, player2, player3, player4, player5,
										player6, player7, player8, player9, player10, spellSetterDamage);
								}
							}
							else
							{
								statusSetter( target, mimeObject.status );
							}
						}
						else if( mimeObject.mod == 26 )
						{
							golemSetter( theMime, blueGolem, redGolem );
						}
					}
					else cout << "   " << mimeObject.abilityName << " misses!\n";
					magicTypeReaction( 0, target, theMime, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem,
						mimeObject.counterMagic, mimeObject.mod, 0, mimeObject.effect, mimeObject.component,
						mimeObject.abilityName, mimeObject.evade, false, mimeObject.status, mimeObject.reflect, mimeObject.fireType,
						mimeObject.iceType, mimeObject.lightningType, mimeObject.waterType, mimeObject.windType,
						mimeObject.earthType, mimeObject.holyType, mimeObject.darkType );
							
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				}//ends summon targetting loop
			} //ends targetting player loop
			j += 2;
		} //ends for loop
	}//silence check
	else cout << "\tbut is prevented by Silence!\n";
}
	



void mimeOuterMessage( Player theMime )
{
	cout << "\n" 
	<< "   --- MIME ACTION ---\n";
	//<< "\n";
	//cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
	//<< " attempts to mimic... \n";
}

void mimeOuterFunction( MimeClass &mimeObject, Player &theMime, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem, Golem &blueGolem,
	Golem &redGolem, char myArray[][11], bool mimeThrow = false, bool mimeItem = false, bool mimeBasic = false,
	bool mimeBattle = false, bool mimeAttack = false, bool mimeCharge = false, bool mimeElemental = false,
	bool mimeSpell = false, bool mimeDraw = false, bool mimeTalk = false, bool mimePunch = false )
{
	if( theMime.playerClass == 10 && theMime.turnOrder != mimedUnit.turnOrder )
	{
		
		if( ( theMime.teamName == mimedUnit.teamName && theMime.charm == false ) ||
			( theMime.teamName != mimedUnit.teamName && theMime.charm == true ) )
		{
			if( theMime.dead == false && theMime.petrify == false && theMime.sleep == false
				&& theMime.stop == false && theMime.bloodSuck == false && theMime.dontAct == false
				&& theMime.frog == false && theMime.chicken == false && theMime.confusion == false
				&& theMime.berserk == false )
			{
				if( mimeThrow == true && mimeObject.mimeThrowConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeThrowDamage( theMime, mimedUnit, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, myArray,
						blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeItem == true && mimeObject.mimeItemConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					innerMimeItemFunction( mimeObject );
					mimeItemDamage( theMime, mimedUnit, mimeObject, player1, player2,
						player3, player4, player5, player6, player7, player8, player9, player10,
						nullPlayer, myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeBasic == true && mimeObject.mimeBasicConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeBasicDamage( theMime, mimedUnit, mimeObject, player1, player2,
						player3, player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeBattle == true && mimeObject.mimeBattleConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					innerMimeBattleFunction( mimeObject );
					mimeBattleDamage( theMime, mimeObject, mimedUnit, player1, player2,
						player3, player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeAttack == true && mimeObject.mimeAttackConfirm == 1)
				{
					mimeOuterMessage( theMime );
					mimeAttackFunction( theMime, mimedUnit, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, myArray, blueItem,
						redItem, blueGolem, redGolem, mimeObject );
				}
				else if( mimeCharge == true && mimeObject.mimeChargeConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeChargeFunction( theMime, mimedUnit, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, myArray, blueItem,
						redItem, blueGolem, redGolem, mimeObject );
				}
				else if( mimeElemental == true && mimeObject.mimeElementalConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeElementalDamage( theMime, mimedUnit, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeSpell == true && mimeObject.mimeSpellConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeSpellDamage( theMime, mimedUnit, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeDraw == true && mimeObject.mimeDrawConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeDrawDamage( theMime, mimedUnit, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimeTalk == true && mimeObject.mimeTalkConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimeTalkDamage( theMime, mimedUnit, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
				else if( mimePunch == true && mimeObject.mimePunchConfirm == 1 )
				{
					mimeOuterMessage( theMime );
					mimePunchDamage( theMime, mimedUnit, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
				}
			}// eligible status effect
		}//charmed or not charmed
	}//player is a mime
}


void mimeOuterCondenser( MimeClass &mimeObject, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem, Golem &blueGolem,
	Golem &redGolem, char myArray[][11], bool mimeThrow = false, bool mimeItem = false, bool mimeBasic = false, bool mimeBattle = false, bool mimeAttack = false,
	bool mimeCharge = false, bool mimeElemental = false, bool mimeSpell = false, bool mimeDraw = false, bool mimeTalk = false,
	bool mimePunch = false )
	{
		mimeOuterFunction( mimeObject, player1, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player6, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player7, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player2, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player3, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player8, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player9, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player4, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player5, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

		mimeOuterFunction( mimeObject, player10, mimedUnit, player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, 
			redItem, blueGolem, redGolem, myArray, mimeThrow, mimeItem, mimeBasic, mimeBattle, mimeAttack,
			mimeCharge, mimeElemental, mimeSpell, mimeDraw, mimeTalk, mimePunch );

	}

