

class Summon
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	string display;
	bool evade;
	long int component;
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
	
	Summon()
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
		effect = 2;
	}
	~Summon() {}

	void summonMenu( Summon &summonObject, Player actor );
	void summonSuccess( Summon &summonObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem );
};

void Summon::summonMenu( Summon &summonObject, Player actor )
{
	int summonAction = 0;
	summonObject.playerInput = 0;

	while( ( cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " SUMMON Menu ---\n" 	
		<< "0.) Return to Menu\n" 
		<< "1.) MOOGLE      -- heal allies within 2 panels         --  8 MP --  2 CTR\n"
		<< "2.) SHIVA       -- Ice damage within 2 panels          -- 24 MP --  4 CTR\n" 
		<< "3.) RAMUH       -- Lit damage within 2 panels          -- 24 MP --  4 CTR\n"
		<< "4.) IFRIT       -- Fire damage within 2 panels         -- 24 MP --  4 CTR\n"
		<< "5.) TITAN       -- Earth damage within 2 panels        -- 30 MP --  5 CTR\n"
		<< "6.) GOLEM       -- Shield allies from ATTACK           -- 40 MP --  3 CTR\n" 
		<< "7.) CARBUNKLE   -- add reflect to allies               -- 30 MP --  4 CTR\n"
		<< "8.) BAHAMUT     -- damage within 3 panels              -- 60 MP -- 10 CTR\n" 
		<< "9.) ODIN        -- damage within 3 panels              -- 50 MP --  9 CTR\n" 
		<< "10.) LEVIATHAN  -- Water damage within 3 panels        -- 48 MP --  9 CTR\n" 
		<< "11.) SALAMANDER -- Fire damage within 2 panels         -- 48 MP --  9 CTR\n"
		<< "12.) SILF       -- add Silence within 2 panels         -- 26 MP --  5 CTR\n" 
		<< "13.) FAIRY      -- heal allies within 2 panels         -- 28 MP --  4 CTR\n"
		<< "14.) LICH       -- 50% of max life dmg within 2 panels -- 40 MP --  9 CTR\n" 
		<< "15.) CYCLOPS    -- damage within 2 panels              -- 62 MP --  9 CTR\n"
		//<< "16.) ZODIAC     -- damage within 3 panels              -- 99 MP -- 10 CTR\n"
	) && 
	( !(cin >> summonAction ) || summonAction < 0 || summonAction > 16  ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	summonObject.playerInput = summonAction;
	if( summonAction == 0 )
	{
		summonObject.confirm = 0;
	}
	else summonObject.confirm = 2;
}

void Summon::summonSuccess( Summon &summonObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem )
{
	summonObject.abilityName = "";
	summonObject.display = "";
	summonObject.evade = false;
	summonObject.abilityDamage = 0;
	summonObject.abilityChance = 0;
	summonObject.mod = 5;
	summonObject.rangeMax = 4;
	summonObject.rangeMin = 0;
	summonObject.component = 0;
	summonObject.casterImmune = false;
	summonObject.effect = 3;
	summonObject.abilityCTRCount = 0;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (60, 0);
	int tempHitChance = 0;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int summonRoll = 0;
	int summonConfirm = 2;


	if( summonObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( summonObject.confirm != 0 ) 
	{
		do
		{
			if( summonObject.playerInput == 1 )
			{
				summonObject.abilityName = "Moogle";
				summonObject.mp = 8;
				summonObject.abilityCTRCount = 2;
				summonObject.display = "-- restore HP to target and up to 2 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 12;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = mod5White( actor, target, actor.ma, summonObject.component );
				if( target.undead == true )
					summonObject.abilityDamage *= -1;
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );

			}//end Moogle loop


			else if( summonObject.playerInput == 2 )
			{
				summonObject.abilityName = "Shiva";
				summonObject.mp = 24;
				summonObject.abilityCTRCount = 4;
				summonObject.display = "-- Ice damage to target and up to 2 squares away -- ";
				summonObject.evade = false;
				summonObject.component = 24;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, false, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );

			}//end Shiva
			

			else if( summonObject.playerInput == 3 )
			{
				summonObject.abilityName = "Ramuh";
				summonObject.mp = 24;
				summonObject.abilityCTRCount = 4;
				summonObject.display = "-- Lightning dmg to target and up to 2 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 24;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true  )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, false, false, false, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );

			}//end Ramuh loop

			else if( summonObject.playerInput == 4 )
			{
				summonObject.abilityName = "Ifrit";
				summonObject.mp = 24;
				summonObject.abilityCTRCount = 4;
				summonObject.display = "-- Fire damage to target and up to 2 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 24;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Ifrit loop

			
			else if( summonObject.playerInput == 5 )
			{
				summonObject.abilityName = "Titan";
				summonObject.mp = 30;
				summonObject.abilityCTRCount = 5;
				summonObject.display = "-- Earth damage to target and up to 2 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 28;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true  )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, false,
					false, false, false, false, false, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end titan loop


			else if( summonObject.playerInput == 6 ) //not yet implemented ***
			{
				summonObject.abilityName = "Golem";
				summonObject.mp = 40;
				summonObject.abilityCTRCount = 3;
				summonObject.display = "-- physical damage shield on allies -- HP Shield of ";
				summonObject.evade = false;
				summonObject.abilityChance = 0;
				summonObject.component = 200;
				
				summonObject.abilityDamage = actor.maxLife;

				summonObject.abilityChance = mod6Golem( actor, actor.ma, summonObject.component );
				if( summonObject.abilityChance > 100 )
					summonObject.abilityChance = 100;

				summonConfirm = targetDisplay( actor, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );

				targetVector[0] = actor.currentRow - 1;
				targetVector[1] = actor.currentCol - 1;
				
			}//end golem

			else if( summonObject.playerInput == 7 )
			{
				summonObject.abilityName = "Carbunkle";
				summonObject.mp = 30;
				summonObject.abilityCTRCount = 4;
				summonObject.display = "-- add Reflect to allies";
				summonObject.evade = false;
				summonObject.component = 150;
				summonObject.abilityChance = 0;
				summonObject.mod = 6;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == true )
					|| ( actor.charm == false && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true  )
				summonObject.abilityChance = 0;

				else if( ( target.teamName != actor.teamName && actor.charm == true )
					|| ( actor.charm == false && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = mod6White( actor, target, actor.ma, summonObject.component );
				}

				if( summonObject.abilityChance > 100 )
					summonObject.abilityChance = 100;

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, false, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display, true );
			}//end carbunkle


			else if( summonObject.playerInput == 8 )
			{
				summonObject.abilityName = "Bahamut";
				summonObject.mp = 60;
				summonObject.abilityCTRCount = 10;
				summonObject.display = "-- damage to target and enemies up to 3 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 46;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 4;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Bahamut


			else if( summonObject.playerInput == 9 )
			{
				summonObject.abilityName = "Odin";
				summonObject.mp = 50;
				summonObject.abilityCTRCount = 9;
				summonObject.display = "-- damage to target and enemies up to 3 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 40;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 4;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Odin

			else if( summonObject.playerInput == 10 )
			{
				summonObject.abilityName = "Leviathan";
				summonObject.mp = 48;
				summonObject.abilityCTRCount = 9;
				summonObject.display = "-- damage to target and enemies up to 3 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 38;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 4;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, false,
					false, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end leviathan loop


			else if( summonObject.playerInput == 11 )
			{
				summonObject.abilityName = "Salamander";
				summonObject.mp = 48;
				summonObject.abilityCTRCount = 9;
				summonObject.display = "-- Fire dmg to target and enemies up to 2 squares -- HP ";
				summonObject.evade = false;
				summonObject.component = 46;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true  )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component, true );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Salamander loop


			else if( summonObject.playerInput == 12 )
			{
				summonObject.abilityName = "Silf";
				summonObject.mp = 26;
				summonObject.abilityCTRCount = 5;
				summonObject.display = "-- Silence to target and enemies up to 2 squares away";
				summonObject.evade = false;
				summonObject.component = 150;
				summonObject.abilityChance = 0;
				summonObject.mod = 6;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = mod6( actor, target, actor.ma, summonObject.component );	
				}

				if( summonObject.abilityChance > 100 )
					summonObject.abilityChance = 100;

				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display, true );
			}//end Silf loop


			else if( summonObject.playerInput == 13 )
			{
				summonObject.abilityName = "Fairy";
				summonObject.mp = 28;
				summonObject.abilityCTRCount = 4;
				summonObject.display = "-- restore HP to target and allies up to 2 squares -- HP ";
				summonObject.evade = false;
				summonObject.component = 24;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = mod5White( actor, target, actor.ma, summonObject.component );
				if( target.undead == true )
					summonObject.abilityDamage *= -1;
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Fairy loop


			
			else if( summonObject.playerInput == 14 ) //the damage on this is tricky ***
			{
				summonObject.abilityName = "Lich";
				summonObject.mp = 40;
				summonObject.abilityCTRCount = 9;
				summonObject.display = "-- 1/2 max HP damage to target and nearby enemies -- HP ";
				summonObject.evade = false;
				summonObject.component = 160;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = -1 * mod6( actor, target, actor.ma, summonObject.component, false, false, false,
						false, false, true );
				}

				if( summonObject.abilityChance > 100 )
					summonObject.abilityChance = 100;

				if( tempDamage % 2 == 0 )
					tempDamage = 0;
				else tempDamage = 1;

				summonObject.abilityDamage = target.maxLife / 2 + tempDamage;

				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );

			}//end Lich loop


			else if( summonObject.playerInput == 15 )
			{
				summonObject.abilityName = "Cyclops";
				summonObject.mp = 62;
				summonObject.abilityCTRCount = 9;
				summonObject.display = "-- damage to target and enemies up to 2 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 50;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;
				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Cyclops loop


			else if( summonObject.playerInput == 16 )
			{
				summonObject.abilityName = "Zodiac";
				summonObject.mp = 99;
				summonObject.abilityCTRCount = 10;
				summonObject.display = "-- damage to target and enemies up to 2 squares away -- HP ";
				summonObject.evade = false;
				summonObject.component = 96;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 4;

				targetVector = rangeTest( actor, summonObject.rangeMax,
					summonObject.abilityName, summonObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == true || ( target.teamName == actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName != target.teamName ) || target.dead == true 
					|| target.petrify == true )
				summonObject.abilityChance = 0;

				else if( ( target.teamName != actor.teamName && actor.charm == false )
					|| ( actor.charm == true && actor.teamName == target.teamName ) )
				{
					summonObject.abilityChance = 100;
				}

				summonObject.abilityDamage = -1 * mod5Magic( actor, target, actor.ma, summonObject.component );
				
				summonConfirm = targetDisplay( target, summonObject.abilityName, summonObject.abilityChance,
					summonObject.abilityDamage, summonObject.display );
			}//end Zodiac loop


			if( summonConfirm == 1 )
			{
				actor.ctrRow = targetVector[0];
				actor.ctrCol = targetVector[1];

				if( myArray[actor.ctrRow][actor.ctrCol] != 'O' )
				{
					summonObject.ctrFollow = targetFollowDisplay();
				}
				else summonObject.ctrFollow = 0;

				actor.charging = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 17;
				actor.ctrName = summonObject.abilityName;
				actor.ctrCountdown = summonObject.abilityCTRCount;
				if( actor.shortCharge == true )
					actor.ctrCountdown = actor.ctrCountdown / 2 + actor.ctrCountdown % 2;
				actor.ctrInput = summonObject.playerInput;
				actor.ctrFollow = summonObject.ctrFollow;

				if( actor.ctrFollow == 0 )
				{
					actor.ctrRow = targetVector[0];
					actor.ctrCol = targetVector[1];
				}
				else if( actor.ctrFollow == 1 )
				{
					actor.ctrFollowNumber = target.turnOrder;
				}
			}
		}while( summonConfirm == 2);
	}
		
	if( summonConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void summonResolve( Summon &summonObject, Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem, char myArray[][11], Player &nullPlayer, Golem &blueGolem, Golem &redGolem,
	MimeClass &mimeObject )
{

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (60, 0);

	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int summonRoll = 0;
	int summonConfirm = 2;
	int targetLoop;

	mimeObject.mimeSpellConfirm = 0;
	int actorMPBefore = actor.mp;

	if( actor.ctrInput == 1 )
	{
		summonObject.abilityName = "Moogle";
		summonObject.mp = 8;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 2;
		summonObject.display = " -- restore HP to target and up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 12;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName == target.teamName ) || ( actor.charm == true && actor.teamName != target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = mod5White( actor, target, actor.ma, summonObject.component );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10, true);

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end moogle loop


	else if( actor.ctrInput == 2 )
	{
		summonObject.abilityName = "Shiva";
		summonObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 4;
		summonObject.display = " -- Ice damage to target and up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 24;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, false, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end shiva loop


	else if( actor.ctrInput == 3 )
	{
		summonObject.abilityName = "Ramuh";
			summonObject.mp = 24;
			if( actor.halfOfMP == true )
			{
				summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
			}
			summonObject.abilityCTRCount = 4;
			summonObject.display = " -- Lightning damage to target and up to 2 squares away -- ";
			summonObject.evade = false;
			summonObject.component = 24;
			summonObject.abilityChance = 0;
			summonObject.mod = 5;
			summonObject.rangeMax = 4;
			summonObject.rangeMin = 0;
			summonObject.casterImmune = false;
			summonObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, false, false,
								false, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end ramuh loop


	else if( actor.ctrInput == 4 )
	{
		summonObject.abilityName = "Ifrit";
				summonObject.mp = 24;
				if( actor.halfOfMP == true )
				{
					summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
				}
				summonObject.abilityCTRCount = 4;
				summonObject.display = " -- Fire damage to target and up to 2 squares away -- ";
				summonObject.evade = false;
				summonObject.component = 24;
				summonObject.abilityChance = 0;
				summonObject.mod = 5;
				summonObject.rangeMax = 4;
				summonObject.rangeMin = 0;
				summonObject.casterImmune = false;
				summonObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end ramuh


	else if( actor.ctrInput == 5 )
	{
		summonObject.abilityName = "Titan";
		summonObject.mp = 30;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 5;
		summonObject.display = " -- Earth damage to target and up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 28;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, false,
								false, false, false, false, false, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end titan


	else if( actor.ctrInput == 6 ) //golem
	{
		summonObject.abilityName = "Golem";
		summonObject.mp = 40;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 3;
		summonObject.display = "";
		summonObject.evade = false;
		summonObject.component = 200;
		summonObject.abilityChance = 0;
		//summonObject.mod = 6Golem;
		// auto range and targeting
		//summonObject.rangeMax = 4;
		//summonObject.rangeMin = 0;
		//summonObject.casterImmune = false;
		//summonObject.effect = 3;

		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else//spell is cast
		{
			actor.mp -= summonObject.mp;
			summonObject.abilityChance = mod6Golem( actor, actor.ma, summonObject.component );

			summonRoll = rand() % 100 + 1;

			cout << summonObject.abilityName <<" targets " << actor.teamName << " " << actor.playerClassName
					<< " " << actor.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";
			cout << "\tRandom Number is... " << summonRoll << "\n";

			if( summonRoll <= summonObject.abilityChance )
			{
				golemSetter( actor, blueGolem, redGolem );
			}
			else cout << "\t" << summonObject.abilityName << " misses!\n";
		}

		

	}


	else if( actor.ctrInput == 7 )
	{
		summonObject.abilityName = "Carbunkle";
		summonObject.mp = 30;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 4;
		summonObject.display = " -- Add reflect to allies -- ";
		summonObject.evade = false;
		summonObject.component = 150;
		summonObject.abilityChance = 0;
		summonObject.mod = 6;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName == target.teamName ) || ( actor.charm == true && actor.teamName != target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = mod6( actor, target, actor.ma, summonObject.component );
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";
						cout << "\tRandom Number is... " << summonRoll << "\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							statusSetter( target, "Reflect" );
							

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end carbunkle loop


	else if( actor.ctrInput == 8 )
	{
		summonObject.abilityName = "Bahamut";
		summonObject.mp = 60;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 10;
		summonObject.display = " -- Damage to target and enemies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 46;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 4;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, false,
								false, false, false, false, false, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end bahamut


	else if( actor.ctrInput == 9 )
	{
		summonObject.abilityName = "Odin";
		summonObject.mp = 50;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 9;
		summonObject.display = " -- Damage to target and enemies up to 3 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 40;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 4;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end Odin


	else if( actor.ctrInput == 10 )
	{
		summonObject.abilityName = "Leviathan";
		summonObject.mp = 48;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 9;
		summonObject.display = " -- Damage to target and enemies up to 3 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 38;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 4;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false  )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, false,
								false, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end leviathan loop


	else if( actor.ctrInput == 11 )
	{
		summonObject.abilityName = "Salamander";
		summonObject.mp = 48;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 9;
		summonObject.display = " -- Fire damage to target and enemies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 46;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component, true );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end salamander loop


	else if( actor.ctrInput == 12 )
	{
		summonObject.abilityName = "Silf";
		summonObject.mp = 26;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 5;
		summonObject.display = " -- Silence to target and enemies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 150;
		summonObject.abilityChance = 0;
		summonObject.mod = 6;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = mod6( actor, target, actor.ma, summonObject.component );
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";
						cout << "\tRandom Number is... " << summonRoll << "\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							statusSetter( target, "Silence" );
							

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end silf loop


	else if( actor.ctrInput == 13 )
	{
		summonObject.abilityName = "Fairy";
		summonObject.mp = 28;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 4;
		summonObject.display = " -- restore HP to target and allies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 24;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;
		
		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName == target.teamName ) || ( actor.charm == true && actor.teamName != target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";
						

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = mod5White( actor, target, actor.ma, summonObject.component );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10,  true );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end fairy loop


	else if( actor.ctrInput == 14 )
	{
		summonObject.abilityName = "Lich";
		summonObject.mp = 40;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 9;
		summonObject.display = " -- 1/2 HP damage to target and enemies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 160;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = mod6( actor, target, actor.ma, summonObject.component, false,
								false, false, false, false, true );
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";
						cout << "\tRandom Number is... " << summonRoll << "\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							
							summonObject.abilityDamage = -target.maxLife / 2 + -target.maxLife % 2;
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end Lich loop


	else if( actor.ctrInput == 15 )
	{
		summonObject.abilityName = "Cyclops";
		summonObject.mp = 62;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 9;
		summonObject.display = " -- Damage to target and enemies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 50;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 3;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end cyclops loop


	else if( actor.ctrInput == 16 )
	{
		summonObject.abilityName = "Zodiac";
		summonObject.mp = 99;
		if( actor.halfOfMP == true )
		{
			summonObject.mp = summonObject.mp / 2 + summonObject.mp % 2;
		}
		summonObject.abilityCTRCount = 10;
		summonObject.display = " -- Damage to target and enemies up to 2 squares away -- ";
		summonObject.evade = false;
		summonObject.component = 96;
		summonObject.abilityChance = 0;
		summonObject.mod = 5;
		summonObject.rangeMax = 4;
		summonObject.rangeMin = 0;
		summonObject.casterImmune = false;
		summonObject.effect = 4;

		targetLoop = loopTarget( summonObject.effect, summonObject.casterImmune );
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < summonObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << summonObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= summonObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < targetLoop; i++ )
			{
				effectVector = multiRange( actor, summonObject.effect, summonObject.abilityName, summonObject.rangeMax,
					summonObject.rangeMin, false, summonObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( ( actor.charm == false && actor.teamName != target.teamName ) || ( actor.charm == true && actor.teamName == target.teamName ) )
					{
						if( target.nullPlayer == true || target.dead == true || target.petrify == true )
						{
							summonObject.abilityChance = 0;	
						}
						else
						{
							summonObject.abilityChance = 100;
						}

						summonRoll = rand() % 100 + 1;

						cout << summonObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << summonObject.abilityChance << "% chance to hit...\n";

						if( summonRoll <= summonObject.abilityChance )
						{
							summonObject.abilityDamage = -mod5Magic( actor, target, actor.ma, summonObject.component );
							hpDamage( target, actor, blueItem, redItem, summonObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						}
						else cout << "\t" << summonObject.abilityName << " misses!\n";
					}
					magicTypeReaction( summonObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end zodiac loop

	if( actorMPBefore != actor.mp )
	{
		vector<int> mimeVector (2, 0);
		mimeObject.mimeSpellConfirm = 1;
		mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor );
		mimeObject.spellSide = mimeVector[0];
		mimeObject.spellDistance = mimeVector[1];
		mimeObject.abilityName = summonObject.abilityName;
	}
}


class Steal
{

public:
	string abilityName;
	string abilityType;
	string info;
	bool reflect;
	bool calculate;
	bool elemental;
	bool counterBladeGrasp;
	bool counterMagic;
	bool counterFlood;
	bool evade;
	int magicPoints;
	int ctr; //clock ticks to resolution
	int jobPoints;
	int mod; //BMG type
	int abilityRange;
	int abilityEffect;
	int playerInput;
	int stealChance;
	int confirm;
	int side; //used for mime
	int distance; //used for mime
	int mimeConfirm;

	Steal() //can *** steal target empty squares or squares where no one is wearing a helmet?
	{
		abilityName = " ";
		abilityType = "physical";
		reflect = false;
		calculate = false;
		elemental = false;
		counterBladeGrasp = true;
		evade = true;
		magicPoints = 0;
		ctr = 0;
		jobPoints = 0;
		mod = 4;
		abilityRange = 1;
		abilityEffect = 1;
		confirm = 0;
	}

	void stealMenu( Steal &stealObject, Player actor );
	void stealSuccess( Steal &stealObject, char myArray[][11], Player &actor, Player &player1,
		Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
		Player &player7, Player &player8, Player &player9, Player& player10, Player &nullPlayer, Golem &blueGolem,
		Golem &redGolem, Item &blueItem, Item &redItem );
};

//displays steal menu and returns player input for the steal 
void Steal::stealMenu( Steal &stealObject, Player actor ) 
{
	int stealAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " STEAL Menu ---\n" 
		<< "0.) Return to Menu\n" 
		<< "1.) Steal Heart -- Add Charm\n"
		<< "2.) Steal Helmet\n" 
		<< "3.) Steal Armor\n" 
		<< "4.) Steal Shield\n" 
		<< "5.) Steal Weapon\n" 
		<< "6.) Steal Accessory\n" 
		) && ( !(cin >> stealAction) || stealAction < 0 || stealAction > 6 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	stealObject.playerInput = stealAction;
	if( stealAction == 0 )
	{
		stealObject.confirm = 0;
	}
	else stealObject.confirm = 2;

}

//calculates Steal success % and implements the action
//to fix: fix evasion %, implement charm, implement male/female thing, test
	//reaction abilities work on target, even if target % is 0... this is not set up correctly here
void Steal::stealSuccess( Steal &stealObject, char myArray[][11], Player &actor, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player& player10, Player &nullPlayer, Golem &blueGolem,
	Golem &redGolem, Item &blueItem, Item &redItem )
{
	vector<int> rangeVector (2, 0);
	int stealConfirm = 2;
	int baseHit = 0;
	int stealRandom = 0;
	Player target;
	stealObject.mimeConfirm = 0;

	vector<int> mimeVector (2, 0);
	int side = 0;
	int distance = 0;

	if ( stealObject.confirm == 0 )
	{
		actor.confirm = 3;
	}
	else if( stealObject.confirm != 0 )
	{ 
		do
		{
			if ( stealObject.playerInput == 1) 
			{
				stealObject.abilityName = "Steal Heart";
				stealObject.abilityRange = 3;
				stealObject.abilityType = "neutral";
				stealObject.evade = false;
				stealObject.info = "-- Add Charm to target";
		
				rangeVector = rangeTest( actor, stealObject.abilityRange, stealObject.abilityName );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true || target.sex == actor.sex )
				{
					stealObject.stealChance = 0;
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					
					if( stealConfirm  == 1 )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}
				
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					stealObject.stealChance = mod1( actor, target, actor.ma, 50 );
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					
					if( stealConfirm == 1 )
					{
						stealRandom = rand() % 100 + 1;
						cout << "\tRandom Number is ... " << stealRandom << "!\n";
						if( stealRandom <= stealObject.stealChance )
						{
							statusSetter( target, "Charm" );
							
							endTarget( target, player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, nullPlayer );
						}
						else
						{
							cout << stealObject.abilityName << " misses!\n";
						}
					}
				}

			}

			else if ( stealObject.playerInput == 2 ) // steal helmet 
			{
				stealObject.stealChance = mod4( actor, target, actor.speed, 40 );
				stealObject.abilityName = "Steal Helmet";
				stealObject.abilityRange = 1;
				stealObject.abilityType = "physical";
				stealObject.evade = true;
				stealObject.info = "-- Steal Helmet from target";
		
				rangeVector = rangeTest( actor, stealObject.abilityRange, stealObject.abilityName);
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					stealObject.stealChance = 0;
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					if( stealConfirm  == 1 )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}

				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )	
				{
					
					if( target.head == false || target.maintenance == true )
					{
						stealObject.stealChance = 0;
					}

					stealObject.stealChance = counterGraspEvade( stealObject.stealChance, actor, target, false,
						"physical", false ); 
					
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );

					if( stealConfirm == 1 )
					{
						stealRandom = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << stealRandom << '\n';
						if ( stealRandom <= stealObject.stealChance )
						{
							helmetDestroyer( target );
						}
						else
						{
							cout << stealObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			}// end steal helmet selection

			else if ( stealObject.playerInput == 3 ) // steal armor
			{
				stealObject.stealChance = mod4( actor, target, actor.speed, 35 );
				stealObject.abilityName = "Steal Armor";
				stealObject.abilityRange = 1;
				stealObject.abilityType = "physical";
				stealObject.evade = true;
				stealObject.info = "-- Steal Armor from target";
		
				rangeVector = rangeTest( actor, stealObject.abilityRange, stealObject.abilityName);
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					stealObject.stealChance = 0;
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					if( stealConfirm  == 1 )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}
				
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )	
				{
					
					if( target.body == false || target.maintenance == true )
					{
						stealObject.stealChance = 0;
					}

					stealObject.stealChance = counterGraspEvade( stealObject.stealChance, actor, target,
						false, "physical", false ); 
					
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					if( stealConfirm == 1 )
					{
						stealRandom = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << stealRandom << '\n';
						if ( stealRandom <= stealObject.stealChance )
						{
							armorDestroyer( target );
						}
						else
						{
							cout << stealObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			}// steal armor end here

			else if ( stealObject.playerInput == 4 ) // steal shield
			{
				stealObject.stealChance = mod4( actor, target, actor.speed, 35 );
				stealObject.abilityName = "Steal Shield";
				stealObject.abilityRange = 1;
				stealObject.abilityType = "physical";
				stealObject.evade = true;
				stealObject.info = "-- Steal Shield from target";
		
				rangeVector = rangeTest( actor, stealObject.abilityRange, stealObject.abilityName);
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					stealObject.stealChance = 0;
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					if( stealConfirm  == 1 )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )	
				{
					
					if( target.offHandType != "Shield" || target.maintenance == true )
					{
						stealObject.stealChance = 0;
					}

					stealObject.stealChance = counterGraspEvade( stealObject.stealChance, actor, target, false, "physical",
						false ); 
					
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );

					if( stealConfirm == 1 )
					{
						stealRandom = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << stealRandom << '\n';
						if ( stealRandom <= stealObject.stealChance )
						{
							shieldDestroyer( target );
						}
						else
						{
							cout << stealObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			}// steal shield selection

			else if ( stealObject.playerInput == 5 ) // steal weapon
			{
				stealObject.stealChance = mod4( actor, target, actor.speed, 30 );
				stealObject.abilityName = "Steal Weapon";
				stealObject.abilityRange = 1;
				stealObject.abilityType = "physical";
				stealObject.evade = true;
				stealObject.info = "-- Steal Weapon from target";
		
				rangeVector = rangeTest( actor, stealObject.abilityRange, stealObject.abilityName);
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					stealObject.stealChance = 0;
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					if( stealConfirm  == 1 )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}

				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )	
				{
					
					if( ( target.weapon == false && target.offHandWeapon == false ) || target.maintenance == true )
					{
						stealObject.stealChance = 0;
					}

					stealObject.stealChance = counterGraspEvade( stealObject.stealChance, actor, target, false,
						"physical", false ); 
					
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );

					if( stealConfirm == 1 )
					{
						stealRandom = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << stealRandom << '\n';
						if ( stealRandom <= stealObject.stealChance )
						{
							if( target.weapon == true )
							{
								weaponDestroyer( target );
							}
							else if( target.offHand == true && target.offHandType != "Shield" )
							{
								shieldDestroyer( target );
							}
						
						}
						else
						{
							cout << stealObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			}// steal weapon selection

			else if( stealObject.playerInput == 6 )
			{
				stealObject.stealChance = mod4( actor, target, actor.speed, 40 );
				stealObject.abilityName = "Steal Accessory";
				stealObject.abilityRange = 1;
				stealObject.abilityType = "physical";
				stealObject.evade = true;
				stealObject.info = "-- Steal Accessory from target";
		
				rangeVector = rangeTest( actor, stealObject.abilityRange, stealObject.abilityName);
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					stealObject.stealChance = 0;
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );
					if( stealConfirm  == 1 )
					{
						cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}

				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )	
				{
					if( target.accessory == false || target.maintenance == true )
					{
						stealObject.stealChance = 0;
					}

					stealObject.stealChance = counterGraspEvade( stealObject.stealChance, actor, target, false,
						"physical", false ); 
					
					stealConfirm = targetDisplay( target, stealObject.abilityName, stealObject.stealChance, 0, stealObject.info,
						true );

					if( stealConfirm == 1 )
					{
						stealRandom = ( rand() % 100 ) + 1;
						cout << "\tRandom Number is..." << stealRandom << '\n';
						if ( stealRandom <= stealObject.stealChance )
						{
							accessoryDestroyer( target );
						}
						else
						{
							cout << stealObject.abilityName << " misses!\n";
						}
						counterGraspReaction( actor, target, myArray, player1, player2, player3, player4, player5,
							player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem );
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			}// end steal accessory 
			mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor);
			stealObject.side = mimeVector[0];
			stealObject.distance = mimeVector[1];
			stealObject.mimeConfirm = stealConfirm;
		} while(stealConfirm == 2);
	}//end steal selection
	if( stealConfirm == 3 )
	{
		actor.confirm = 3;
	}
}


void mimeStealDamage( Player &theMime, Steal &stealObject, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int stealRoll;
	vector<int> targetVec (2, 0);

	targetVec = mimeTargetVector( theMime, stealObject.side, stealObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts "<< mimeObject.abilityName << " on (" << targetVec[0]-1 << ", " << targetVec[1]-1 << ")...\n";


	target = targetFunction( targetVec[0], targetVec[1], player1, player2, player3, player4,
		player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

	if( target.dead == false && target.petrify == false && target.nullPlayer == false )
	{
		stealRoll = rand() % 100 + 1;

		if( stealObject.playerInput == 1 )
		{
			mimeObject.chance = mod1( theMime, target, theMime.speed, mimeObject.component );
			if( theMime.teamName == target.teamName )
				mimeObject.chance = 0;
		}
		else
		{
			mimeObject.chance = mod4( theMime, target, theMime.speed, mimeObject.component );
			mimeObject.chance = counterGraspEvade( mimeObject.chance, theMime, target, false, "physical", false );
			if( target.maintenance == true )
				mimeObject.chance = 0;
			if( stealObject.playerInput == 2 && target.head == false )
				mimeObject.chance = 0;
			if( stealObject.playerInput == 3 && target.body == false )
				mimeObject.chance = 0;
			if( stealObject.playerInput == 4 && target.offHandType != "Shield" )
				mimeObject.chance = 0;
			if( stealObject.playerInput == 5 && target.weapon == false && target.offHand == false )
				mimeObject.chance = 0;
			if( stealObject.playerInput == 6 && target.accessory == false )
				mimeObject.chance = 0;
		}

		cout << "\t" << mimeObject.abilityName << " chance to hit is " << mimeObject.chance << "%. Random number is..." << stealRoll << "\n";
		if( stealRoll <= mimeObject.chance )
		{
			if( stealObject.playerInput == 1 )
				statusSetter( target, "Charm" );
			else if( stealObject.playerInput == 2 )
				helmetDestroyer( target );
			else if( stealObject.playerInput == 3 )
				armorDestroyer( target );
			else if( stealObject.playerInput == 4 )
			{
				if( target.offHandType == "Shield" )
				{
					shieldDestroyer( target );
				}
			}
			else if( stealObject.playerInput == 5 )
			{
				if( target.weapon == true )
				{
					weaponDestroyer( target );
				}
				else if( target.offHand == true && target.offHandType != "Shield" )
				{
					shieldDestroyer( target );
				}
			}
			else if( stealObject.playerInput == 6 )
				accessoryDestroyer( target );
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

void innerMimeStealFunction(MimeClass &mimeObject, Steal &stealObject )
{
	mimeObject.mod = 4;
	mimeObject.effect = 1;
	mimeObject.evade = true;

	if( stealObject.playerInput == 1 )
	{
		mimeObject.abilityName = "Steal Heart";
		mimeObject.mod = 1;
		mimeObject.evade = false;
		mimeObject.status = "Charm";
		mimeObject.component = 50;
	}
	else if( stealObject.playerInput == 2 )
	{
		mimeObject.abilityName = "Steal Helmet";
		mimeObject.component = 40;
	}
	else if( stealObject.playerInput == 3 )
	{
		mimeObject.abilityName = "Steal Armor";
		mimeObject.component = 35;
	}
	else if( stealObject.playerInput == 4 )
	{
		mimeObject.abilityName = "Steal Shield";
		mimeObject.component = 35;
	}
	else if( stealObject.playerInput == 5 )
	{
		mimeObject.abilityName = "Steal Weapon";
		mimeObject.component = 30;
	}
	else if( stealObject.playerInput == 6 )
	{
		mimeObject.abilityName = "Steal Accessory";
		mimeObject.component = 40;
	}
}

void mimeStealFunction( MimeClass &mimeObject, Steal &stealObject, Player &theMime, Player &mimedUnit, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, Item &blueItem, Item &redItem, Golem &blueGolem,
	Golem &redGolem, char myArray[][11], bool mimeSteal = true )
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
				if( mimeSteal == true && stealObject.playerInput > 0 && stealObject.mimeConfirm == 1 )
				{
					mimeObject.abilityName = stealObject.abilityName;

					cout << "\n"  
						<< "   --- MIME ACTION ---\n"
						<< theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
						<< " attempts to mimic... \n";
					innerMimeStealFunction( mimeObject, stealObject );
					mimeStealDamage( theMime, stealObject, mimeObject, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer,
						myArray, blueItem, redItem, blueGolem, redGolem );
					
				} //should always be true
			}// eligible status effect
		}//charmed or not charmed
	}//player is a mime
}



class Time
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	string display;
	bool evade;
	long int component;
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
	bool reflect;
	
	Time()
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
		effect = 2;
	}
	~Time() {}

	void timeMenu( Time &timeObject, Player actor );
	void timeSuccess( Time &timeObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem );
};

void Time::timeMenu( Time &timeObject, Player actor )
{
	int timeAction = 0;
	while( ( cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " TIME MAGIC Menu ---\n" 	
		<< "0.) Return to Menu\n"
		<< "1.) HASTE      -- add Haste to area      --  8 MP --  2 CTR\n"
		<< "2.) HASTE 2    -- add Haste to area      -- 30 MP --  7 CTR\n" 
		<< "3.) SLOW       -- add Slow to area       --  8 MP --  2 CTR\n"
		<< "4.) SLOW 2     -- add Slow to area       -- 30 MP --  7 CTR\n"
		<< "5.) STOP       -- add Stop to area       -- 14 MP --  7 CTR\n"
		<< "6.) DON'T MOVE -- add Don't Move to area -- 10 MP --  3 CTR\n" 
		<< "7.) FLOAT      -- add Float to area      --  8 MP --  2 CTR\n"
		<< "8.) REFLECT    -- add Reflect to target  -- 12 MP --  2 CTR\n"
		<< "9.) QUICK      -- add Quick to target    -- 24 MP --  4 CTR\n"
		<< "10.) DEMI      -- 1/4 HP damage to area  -- 24 MP --  6 CTR\n"
		<< "11.) DEMI 2    -- 1/2 HP damage to area  -- 50 MP --  9 CTR\n"
		<< "12.) METEOR    -- large area damage      -- 70 MP -- 13 CTR\n"
	) && 
	( !(cin >> timeAction ) || timeAction < 0 || timeAction > 12 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	timeObject.playerInput = timeAction;
	if( timeAction == 0 )
	{
		timeObject.confirm = 0;
	}
	else timeObject.confirm = 2;
}

void Time::timeSuccess( Time &timeObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem )
{
	timeObject.abilityName = "";
	timeObject.display = "";
	timeObject.evade = true;
	timeObject.abilityDamage = 0;
	timeObject.abilityChance = 0;
	timeObject.mod = 6;
	timeObject.rangeMax = 3;
	timeObject.rangeMin = 0;
	timeObject.component = 0;
	timeObject.casterImmune = false;
	timeObject.effect = 2;
	timeObject.abilityCTRCount = 0;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int tempHitChance = 0;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int timeRoll = 0;
	int timeConfirm = 2;

	if( timeObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( timeObject.confirm != 0 ) 
	{
		do
		{
			if( timeObject.playerInput == 1 )
			{
				timeObject.abilityName = "Haste";
				timeObject.mp = 8;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 2;
				timeObject.display = "-- add Haste to target and 4 surrounding squares";
				timeObject.evade = false;
				timeObject.component = 180;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
				
			}//end haste loop


			else if( timeObject.playerInput == 2 )
			{
				timeObject.abilityName = "Haste 2";
				timeObject.mp = 30;
				timeObject.abilityCTRCount = 7;
				timeObject.display = "-- add Haste to target and 4 surrounding squares";
				timeObject.evade = false;
				timeObject.component = 240;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end haste 2

			else if( timeObject.playerInput == 3 )
			{
				timeObject.abilityName = "Slow";
				timeObject.mp = 8;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 2;
				timeObject.display = "-- add Slow to target and 4 surrounding squares";
				timeObject.evade = true;
				timeObject.component = 180;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
				timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
				if( target.accAutoHaste == true || target.weaponAutoHaste == true || target.offHandAutoHaste == true )
				{
					timeObject.abilityChance = 0;
				}
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end slow loop

			else if( timeObject.playerInput == 4 )
			{
				timeObject.abilityName = "Slow 2";
				timeObject.mp = 30;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 7;
				timeObject.display = "-- add Slow to target and 4 surrounding squares";
				timeObject.evade = true;
				timeObject.component = 240;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
				timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
				if( target.accAutoHaste == true || target.weaponAutoHaste == true || target.offHandAutoHaste == true )
				{
					timeObject.abilityChance = 0;
				}

				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end slow 2 loop

			
			else if( timeObject.playerInput == 5 )
			{
				timeObject.abilityName = "Stop";
				timeObject.mp = 14;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 7;
				timeObject.display = "-- add Stop to target and 4 surrounding squares";
				timeObject.evade = true;
				timeObject.component = 180;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
				timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end top loop


			else if( timeObject.playerInput == 6 )
			{
				timeObject.abilityName = "Don't Move";
				timeObject.mp = 10;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 3;
				timeObject.display = "-- add Don't Move to target and 4 surrounding squares";
				timeObject.evade = true;
				timeObject.component = 190;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
				timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end don't move

			else if( timeObject.playerInput == 7 )
			{
				timeObject.abilityName = "Float";
				timeObject.mp = 8;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 2;
				timeObject.display = "-- add Float to target and 4 surrounding squares";
				timeObject.evade = true;
				timeObject.component = 140;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end float loop


			else if( timeObject.playerInput == 8 )
			{
				timeObject.abilityName = "Reflect";
				timeObject.mp = 12;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 2;
				timeObject.display = "-- add Reflect to target";
				timeObject.evade = false;
				timeObject.component = 180;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 4;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 1;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );
			}//end reflect loop


			else if( timeObject.playerInput == 9 )
			{
				timeObject.abilityName = "Quick";
				timeObject.mp = 24;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 4;
				timeObject.display = "-- add Quick to target";
				timeObject.evade = false;
				timeObject.component = 140;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 4;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
			
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display, true );

			}//end Quick loop


			else if( timeObject.playerInput == 10 )
			{
				timeObject.abilityName = "Demi";
				timeObject.mp = 24;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 6;
				timeObject.display = "-- 1/4 damage to target and 4 surrounding squares -- HP ";
				timeObject.evade = true;
				timeObject.component = 190;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 4;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
				timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
				
				if( target.maxLife % 4 == 0 )
					tempDamage = 0;
				else tempDamage = 1;

				timeObject.abilityDamage = -target.maxLife / 4 + -tempDamage;
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display );

			}//end demi

			else if( timeObject.playerInput == 11 )
			{
				timeObject.abilityName = "Demi 2";
				timeObject.mp = 50;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 9;
				timeObject.display = "-- 1/2 damage to target and 4 surrounding squares -- HP ";
				timeObject.evade = true;
				timeObject.component = 120;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 4;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
				timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
				
				if( target.maxLife % 2 == 0 )
					tempDamage = 0;
				else tempDamage = 1;

				timeObject.abilityDamage = -target.maxLife / 2 + -tempDamage;
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display );

			}//end demi 2 loop


			else if( timeObject.playerInput == 12 )
			{
				timeObject.abilityName = "Meteor";
				timeObject.mp = 70;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 13;
				timeObject.display = "-- damage to target and area up to 3 squares away -- HP ";
				timeObject.evade = true;
				timeObject.component = 60;
				timeObject.abilityChance = 0;
				timeObject.mod = 5;
				timeObject.rangeMax = 4;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 4;

				targetVector = rangeTest( actor, timeObject.rangeMax,
					timeObject.abilityName, timeObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				timeObject.abilityChance = 100;

				timeObject.abilityDamage = -mod5Magic( actor, target, actor.ma, timeObject.component );
				
				timeConfirm = targetDisplay( target, timeObject.abilityName, timeObject.abilityChance,
					timeObject.abilityDamage, timeObject.display );
			}//end Meteor loop


			if( timeConfirm == 1 )
			{
				actor.ctrRow = targetVector[0];
				actor.ctrCol = targetVector[1];

				if( myArray[actor.ctrRow][actor.ctrCol] != 'O' )
				{
					timeObject.ctrFollow = targetFollowDisplay();
				}
				else timeObject.ctrFollow = 0;

				actor.charging = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 19;
				actor.ctrName = timeObject.abilityName;
				actor.ctrCountdown = timeObject.abilityCTRCount;
				if( actor.shortCharge == true )
					actor.ctrCountdown = actor.ctrCountdown / 2 + actor.ctrCountdown % 2;
				actor.ctrInput = timeObject.playerInput;
				actor.ctrFollow = timeObject.ctrFollow;

				if( actor.ctrFollow == 0 )
				{
					actor.ctrRow = targetVector[0];
					actor.ctrCol = targetVector[1];
				}
				else if( actor.ctrFollow == 1 )
				{
					actor.ctrFollowNumber = target.turnOrder;
				}
			}
		}while( timeConfirm == 2);
	}
		
	if( timeConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void timeResolve( Time &timeObject, Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem, char myArray[][11], Player &nullPlayer, MimeClass &mimeObject )
{

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	vector<int> refVec (2, 0);

	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int timeRoll = 0;
	int timeConfirm = 2;
	timeObject.reflect = true;

	int actorMPBefore = actor.mp;
	mimeObject.mimeSpellConfirm = 0;

	if( actor.ctrInput == 1 )
	{
		timeObject.abilityName = "Haste";
		timeObject.mp = 8;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 2;
		timeObject.display = " -- add Haste to target and 4 surrounding squares -- ";
		timeObject.evade = false;
		timeObject.component = 180;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 3;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						statusSetter( target, "Haste" );	
					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";

				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end Haste loop


	else if( actor.ctrInput == 2 )
	{
		timeObject.abilityName = "Haste 2";
				timeObject.mp = 30;
				if( actor.halfOfMP == true )
				{
					timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
				}
				timeObject.abilityCTRCount = 7;
				timeObject.display = " -- add Haste to target and 4 surrounding squares -- ";
				timeObject.evade = false;
				timeObject.component = 240;
				timeObject.abilityChance = 0;
				timeObject.mod = 6;
				timeObject.rangeMax = 3;
				timeObject.rangeMin = 0;
				timeObject.casterImmune = false;
				timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Haste" );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end haste 2 loop


	else if( actor.ctrInput == 3 )
	{
		timeObject.abilityName = "Slow";
		timeObject.mp = 8;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 2;
		timeObject.display = " -- add Slow to target and 4 surrounding squares -- ";
		timeObject.evade = true;
		timeObject.component = 180;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 3;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
						timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
						if( target.accAutoHaste == true || target.weaponAutoHaste == true || target.offHandAutoHaste == true )
						{
							timeObject.abilityChance = 0;
						}
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Slow" );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
					timeObject.evade, true, "Slow", timeObject.reflect );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end slow loop


	else if( actor.ctrInput == 4 )
	{
		timeObject.abilityName = "Slow 2";
		timeObject.mp = 30;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 7;
		timeObject.display = " -- add Slow to target and 4 surrounding squares -- ";
		timeObject.evade = true;
		timeObject.component = 240;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 3;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false)
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
						timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
						if( target.accAutoHaste == true || target.weaponAutoHaste == true || target.offHandAutoHaste == true )
						{
							timeObject.abilityChance = 0;
						}
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Slow" );
						
					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
					timeObject.evade, true, "Slow", timeObject.reflect );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end slow 2 loop


	else if( actor.ctrInput == 5 )
	{
		timeObject.abilityName = "Stop";
		timeObject.mp = 14;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 7;
		timeObject.display = " -- add Stop to target and 4 surrounding squares -- ";
		timeObject.evade = true;
		timeObject.component = 180;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 3;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false)
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
						timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Stop" );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
						timeObject.evade, true, "Stop", timeObject.reflect );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end stop


	else if( actor.ctrInput == 6 )
	{
		timeObject.abilityName = "Don't Move";
		timeObject.mp = 10;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 3;
		timeObject.display = " -- add Don't Move to target and 4 surrounding squares -- ";
		timeObject.evade = true;
		timeObject.component = 190;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 3;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false)
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
						timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Don't Move" );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
						timeObject.evade, true, "Don't Move", timeObject.reflect );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end don't move loop


	else if( actor.ctrInput == 7 )
	{
		timeObject.abilityName = "Float";
		timeObject.mp = 8;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 2;
		timeObject.display = " -- add Float to target and 4 surrounding squares -- ";
		timeObject.evade = false;
		timeObject.component = 140;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 3;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false)
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						target.statusFloat = true;
						
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " gains Float!\n";

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end float loop


	else if( actor.ctrInput == 8 )
	{
		timeObject.abilityName = "Reflect";
		timeObject.mp = 12;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 2;
		timeObject.display = " -- add Reflect to target -- ";
		timeObject.evade = false;
		timeObject.component = 180;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 4;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 1; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Reflect" );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end reflect


	else if( actor.ctrInput == 9 )
	{
		timeObject.abilityName = "Quick";
		timeObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 4;
		timeObject.display = " -- add Quick to target -- ";
		timeObject.evade = false;
		timeObject.component = 140;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 4;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 1; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6White( actor, target, actor.ma, timeObject.component );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						
						statusSetter( target, "Quick" );
				
					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
					
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
						timeObject.evade, true, "Quick", timeObject.reflect );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end quick


	else if( actor.ctrInput == 10 )
	{
		timeObject.abilityName = "Demi";
		timeObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 6;
		timeObject.display = " -- 1/4 damage to target and 4 surrounding squares -- ";
		timeObject.evade = true;
		timeObject.component = 190;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 4;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
						timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						if( tempDamage % 4 == 0 )
							tempDamage = 0;
						else tempDamage = 1;
						timeObject.abilityDamage = -target.maxLife / 4 + -tempDamage;

						hpDamage( target, actor, blueItem, redItem, timeObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
						timeObject.evade, false, "", timeObject.reflect );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end demi loop


	else if( actor.ctrInput == 11 )// bolt 3
	{
		timeObject.abilityName = "Demi 2";
		timeObject.mp = 50;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 9;
		timeObject.display = " -- 1/2 damage to target and 4 surrounding squares -- ";
		timeObject.evade = true;
		timeObject.component = 120;
		timeObject.abilityChance = 0;
		timeObject.mod = 6;
		timeObject.rangeMax = 4;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = mod6( actor, target, actor.ma, timeObject.component );
						timeObject.abilityChance = magicEvade( timeObject.abilityChance, actor, target );
					}

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << timeRoll << "\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						if( tempDamage % 2 == 0 )
							tempDamage = 0;
						else tempDamage = 1;
						timeObject.abilityDamage = -target.maxLife / 2 + -tempDamage;

						hpDamage( target, actor, blueItem, redItem, timeObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
						timeObject.evade, false, "", timeObject.reflect );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end demi 2 loop


	else if( actor.ctrInput == 12 )
	{
		timeObject.abilityName = "Meteor";
		timeObject.mp = 70;
		if( actor.halfOfMP == true )
		{
			timeObject.mp = timeObject.mp / 2 + timeObject.mp % 2;
		}
		timeObject.abilityCTRCount = 13;
		timeObject.display = " -- damage to target and area up to 3 squares away -- ";
		timeObject.evade = false;
		timeObject.component = 60;
		timeObject.abilityChance = 100;
		timeObject.mod = 5;
		timeObject.rangeMax = 4;
		timeObject.rangeMin = 0;
		timeObject.casterImmune = false;
		timeObject.effect = 4;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < timeObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << timeObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= timeObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 25; i++ )
			{
				effectVector = multiRange( actor, timeObject.effect, timeObject.abilityName, timeObject.rangeMax,
					timeObject.rangeMin, false, timeObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						timeObject.abilityChance = 0;	
					}
					else
					{
						timeObject.abilityChance = 100;
					}

					timeObject.abilityDamage = -mod5Magic( actor, target, actor.ma, timeObject.component );

					timeRoll = rand() % 100 + 1;

					cout << timeObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << timeObject.abilityChance << "% chance to hit...\n";

					if( timeRoll <= timeObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, timeObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << timeObject.abilityName << " misses!\n";
				}
				magicTypeReaction( timeObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						timeObject.mod, timeObject.mp, timeObject.effect, timeObject.component, timeObject.abilityName,
						timeObject.evade, false, "", timeObject.reflect );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end meteor loop

	if( actorMPBefore != actor.mp )
	{
		vector<int> mimeVector (2, 0);
		mimeObject.mimeSpellConfirm = 1;
		mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor );
		mimeObject.spellSide = mimeVector[0];
		mimeObject.spellDistance = mimeVector[1];
		mimeObject.abilityName = timeObject.abilityName;
	}
}




class Black
{
public:

	//attributes
	int confirm;
	int playerInput;
	string abilityName;
	string abilityType;
	string display;
	bool evade;
	long int component;
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
	bool reflect;
	
	Black()
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
		effect = 2;
	}
	~Black() {}

	void blackMenu( Black &blackObject, Player actor );
	void blackSuccess( Black &blackObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem );
};

void Black::blackMenu( Black &blackObject, Player actor )
{
	int blackAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " BLACK MAGIC Menu ---\n" 	
		<< " 0.) Return to Menu\n" 
		<< " 1.) FIRE   -- Fire damage to area      --  6 MP --  4 CTR\n"
		<< " 2.) FIRE 2 -- Fire damage to area      -- 12 MP --  5 CTR\n"  
		<< " 3.) FIRE 3 -- Fire damage to area      -- 24 MP --  7 CTR\n"
		<< " 4.) FIRE 4 -- Fire damage to area      -- 48 MP -- 10 CTR\n" 
		<< " 5.) ICE    -- Lightning damage to area --  6 MP --  4 CTR\n"
		<< " 6.) ICE 2  -- Lightning damage to area -- 10 MP --  5 CTR\n"  
		<< " 7.) ICE 3  -- Lightning damage to area -- 24 MP --  7 CTR\n"
		<< " 8.) ICE 4  -- Lightning damage to area -- 48 MP -- 10 CTR\n" 
		<< " 9.) BOLT   -- Ice damage to area       --  6 MP --  4 CTR\n" 
		<< "10.) BOLT 2 -- Ice damage to area       -- 12 MP --  5 CTR\n"  
		<< "11.) BOLT 3 -- Ice damage to area       -- 24 MP --  7 CTR\n"
		<< "12.) BOLT 4 -- Ice damage to area       -- 48 MP -- 10 CTR\n" 
		<< "13.) POISON -- add Poison to area       --  6 MP --  3 CTR\n"
		<< "14.) FROG   -- add Frog to target       -- 12 MP --  5 CTR\n"  
		<< "15.) DEATH  -- kill target              -- 24 MP -- 10 CTR\n"
		<< "16.) FLARE  -- damage to target         -- 60 MP --  7 CTR\n"
	) && 
	( !(cin >> blackAction ) || blackAction < 0 || blackAction > 16 ||
	( actor.frog == true && blackAction != 14 )
	) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		if( actor.frog == true )
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is a Frog and can only cast FROG!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	blackObject.playerInput = blackAction;

	if( blackAction == 0 )
	{
		blackObject.confirm = 0;
	}
	else blackObject.confirm = 2;
}

void Black::blackSuccess( Black &blackObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem )
{
	blackObject.abilityName = "";
	blackObject.display = "";
	blackObject.evade = true;
	blackObject.abilityDamage = 0;
	blackObject.abilityChance = 0;
	blackObject.mod = 5;
	blackObject.rangeMax = 4;
	blackObject.rangeMin = 0;
	blackObject.component = 0;
	blackObject.casterImmune = false;
	blackObject.effect = 2;
	blackObject.abilityCTRCount = 0;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int tempHitChance = 0;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int blackRoll = 0;
	int blackConfirm = 2;

	if( blackObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( blackObject.confirm != 0 ) 
	{
		do
		{
			if( blackObject.playerInput == 1 )
			{
				blackObject.abilityName = "Fire";
				blackObject.mp = 6;
				blackObject.abilityCTRCount = 4;
				blackObject.display = "-- Fire damage to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.component = 14;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end fire loop


			else if( blackObject.playerInput == 2 )
			{
				blackObject.abilityName = "Fire 2";
				blackObject.mp = 12;
				blackObject.abilityCTRCount = 5;
				blackObject.display = "-- Fire damage to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.component = 18;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end fire 2

			else if( blackObject.playerInput == 3 )
			{
				blackObject.abilityName = "Fire 3";
				blackObject.mp = 24;
				blackObject.abilityCTRCount = 7;
				blackObject.component = 24;
				blackObject.display = "-- Fire damage to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end fire 3 loop

			else if( blackObject.playerInput == 4 )
			{
				blackObject.abilityName = "Fire 4";
				blackObject.mp = 48;
				blackObject.abilityCTRCount = 10;
				blackObject.component = 32;
				blackObject.display = "-- Fire damage to target and up to 2 squares away -- HP ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 3;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end fire 4 loop

			
			else if( blackObject.playerInput == 5 )
			{
				blackObject.abilityName = "Ice";
				blackObject.mp = 6;
				blackObject.abilityCTRCount = 4;
				blackObject.display = "-- Ice damage to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.component = 14;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end Ice loop


			else if( blackObject.playerInput == 6 )
			{
				blackObject.abilityName = "Ice 2";
				blackObject.mp = 12;
				blackObject.abilityCTRCount = 5;
				blackObject.display = "-- Ice damage to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.component = 18;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end ice 2

			else if( blackObject.playerInput == 7 )
			{
				blackObject.abilityName = "Ice 3";
				blackObject.mp = 24;
				blackObject.abilityCTRCount = 7;
				blackObject.component = 24;
				blackObject.display = "-- Ice damage to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end Ice 3 loop


			else if( blackObject.playerInput == 8 )
			{
				blackObject.abilityName = "Ice 4";
				blackObject.mp = 48;
				blackObject.abilityCTRCount = 10;
				blackObject.component = 32;
				blackObject.display = "-- Ice damage to target and up to 2 squares away -- HP ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 3;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end Ice 4 loop


			else if( blackObject.playerInput == 9 )
			{
				blackObject.abilityName = "Bolt";
				blackObject.mp = 6;
				blackObject.abilityCTRCount = 4;
				blackObject.display = "-- Lightning dmg to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.component = 14;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, false,
					false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );

			}//end Bolt loop


			else if( blackObject.playerInput == 10 )
			{
				blackObject.abilityName = "Bolt 2";
				blackObject.mp = 12;
				blackObject.abilityCTRCount = 5;
				blackObject.display = "-- Lightning dmg to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.component = 18;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, false,
					false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );

			}//end Bolt 2

			else if( blackObject.playerInput == 11 )
			{
				blackObject.abilityName = "Bolt 3";
				blackObject.mp = 24;
				blackObject.abilityCTRCount = 7;
				blackObject.component = 24;
				blackObject.display = "-- Lightning dmg to target and 4 surrounding squares -- HP ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, false,
					false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );

			}//end Bolt 3 loop


			else if( blackObject.playerInput == 12 )
			{
				blackObject.abilityName = "Bolt 4";
				blackObject.mp = 48;
				blackObject.abilityCTRCount = 10;
				blackObject.component = 32;
				blackObject.display = "-- Lightning dmg to target and up to 2 squares away -- HP ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 3;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = magicEvade( 100, actor, target );
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false, false,
					false, true );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );

			}//end Bolt 4 loop


			else if( blackObject.playerInput == 13 )
			{
				blackObject.abilityName = "Poison";
				blackObject.abilityCTRCount = 3;
				blackObject.mp = 6;
				blackObject.display = "-- add Poison to target and 4 surrounding squares";
				blackObject.evade = true;
				blackObject.component = 160;
				blackObject.abilityChance = 0;
				blackObject.mod = 6;
				blackObject.rangeMax = 3;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = mod6( actor, target, actor.ma, blackObject.component );
				
				if( blackObject.abilityChance >= 100 )
					blackObject.abilityChance = 100;
				if( blackObject.abilityChance < 0 )
					blackObject.abilityChance = 0;

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display, true );

			}//end poison loop


			else if( blackObject.playerInput == 14 )
			{
				blackObject.abilityName = "Frog";
				blackObject.abilityCTRCount = 5;
				blackObject.mp = 12;
				blackObject.display = "-- add Frog to target";
				blackObject.evade = true;
				blackObject.component = 120;
				blackObject.abilityChance = 0;
				blackObject.mod = 6;
				blackObject.rangeMax = 3;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 1;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = mod6( actor, target, actor.ma, blackObject.component );
				
				if( blackObject.abilityChance >= 100 )
					blackObject.abilityChance = 100;
				if( blackObject.abilityChance < 0 )
					blackObject.abilityChance = 0;

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display, true );

			}//end frog loop


			else if( blackObject.playerInput == 15 )
			{
				blackObject.abilityName = "Death";
				blackObject.abilityCTRCount = 10;
				blackObject.mp = 24;
				blackObject.display = "-- add Death to target";
				blackObject.evade = true;
				blackObject.component = 100;
				blackObject.abilityChance = 0;
				blackObject.mod = 6;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 1;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				blackObject.abilityChance = mod6( actor, target, actor.ma, blackObject.component );
				
				if( blackObject.abilityChance >= 100 )
					blackObject.abilityChance = 100;
				if( blackObject.abilityChance < 0 )
					blackObject.abilityChance = 0;

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display, true );

			}//end death loop


			else if( blackObject.playerInput == 16 )
			{
				blackObject.abilityName = "Flare";
				blackObject.abilityCTRCount = 7;
				blackObject.mp = 60;
				blackObject.display = "-- damage to target -- HP ";
				blackObject.evade = true;
				blackObject.component = 46;
				blackObject.abilityChance = 0;
				blackObject.mod = 6;
				blackObject.rangeMax = 5;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 1;

				targetVector = rangeTest( actor, blackObject.rangeMax,
					blackObject.abilityName, blackObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				//holy does not ignore shell or magic defend up
				blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component );
				blackObject.abilityChance = magicEvade( 100, actor, target );

				blackConfirm = targetDisplay( target, blackObject.abilityName, blackObject.abilityChance,
					blackObject.abilityDamage, blackObject.display );
			}//end flare loop


			if( blackConfirm == 1 )
			{
				actor.ctrRow = targetVector[0];
				actor.ctrCol = targetVector[1];

				if( myArray[actor.ctrRow][actor.ctrCol] != 'O' )
				{
					blackObject.ctrFollow = targetFollowDisplay();
				}
				else blackObject.ctrFollow = 0;

				actor.charging = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 20;
				actor.ctrName = blackObject.abilityName;
				actor.ctrCountdown = blackObject.abilityCTRCount;
				if( actor.shortCharge == true )
					actor.ctrCountdown = actor.ctrCountdown / 2 + actor.ctrCountdown % 2;
				actor.ctrInput = blackObject.playerInput;
				actor.ctrFollow = blackObject.ctrFollow;
				if( actor.ctrFollow == 0 )
				{
					actor.ctrRow = targetVector[0];
					actor.ctrCol = targetVector[1];
				}
				else if( actor.ctrFollow == 1 )
				{
					actor.ctrFollowNumber = target.turnOrder;
				}
			}
		}while( blackConfirm == 2);
	}
		
	if( blackConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void blackResolve( Black &blackObject, Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem, char myArray[][11], Player &nullPlayer, MimeClass &mimeObject )
{

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	vector<int> refVec (2, 0);

	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int blackRoll = 0;
	int blackConfirm = 2;
	blackObject.reflect = true;

	int actorMPBefore = actor.mp;
	mimeObject.mimeSpellConfirm = 0;

	if( actor.ctrInput == 1 )
	{
		blackObject.abilityName = "Fire";
		blackObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 4;
		blackObject.display = " -- Fire damage to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.component = 14;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, true );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end fire loop


	else if( actor.ctrInput == 2 )
	{
		blackObject.abilityName = "Fire 2";
		blackObject.mp = 12;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 5;
		blackObject.display = " -- Fire damage to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.component = 18;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end cure 2 loop


	else if( actor.ctrInput == 3 )// fire 3
	{
		blackObject.abilityName = "Fire 3";
		blackObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 7;
		blackObject.component = 24;
		blackObject.display = " -- Fire damage to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end fire 3 loop


	else if( actor.ctrInput == 4 )
	{
		blackObject.abilityName = "Fire 4";
		blackObject.mp = 48;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 10;
		blackObject.component = 32;
		blackObject.display = " -- Fire damage to target and up to 2 squares away -- ";
		blackObject.evade = true;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 3;
		blackObject.reflect = false;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end fire 4 loop


	else if( actor.ctrInput == 5 )// ice
	{
		blackObject.abilityName = "Ice";
		blackObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 4;
		blackObject.display = " -- Ice damage to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.component = 14;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false)
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, false, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end ice loop


	else if( actor.ctrInput == 6 )// raise 2
	{
		blackObject.abilityName = "Ice 2";
		blackObject.mp = 12;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 5;
		blackObject.display = " -- Ice damage to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.component = 18;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false)
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, false, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end ice 2 2 loop


	else if( actor.ctrInput == 7 )// reraise
	{
		blackObject.abilityName = "Ice 3";
		blackObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 7;
		blackObject.component = 24;
		blackObject.display = " -- Ice damage to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, false, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end ice 3 loop


	else if( actor.ctrInput == 8 )// ice 4
	{
		blackObject.abilityName = "Ice 4";
				blackObject.mp = 48;
				if( actor.halfOfMP == true )
				{
					blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
				}
				blackObject.abilityCTRCount = 10;
				blackObject.component = 32;
				blackObject.display = " -- Ice damage to target and up to 2 squares away -- ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false  )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end ice 4


	else if( actor.ctrInput == 9 ) //bolt
	{
		blackObject.abilityName = "Bolt";
				blackObject.mp = 6;
				if( actor.halfOfMP == true )
				{
					blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
				}
				blackObject.abilityCTRCount = 4;
				blackObject.display = " -- Bolt damage to target and 4 surrounding squares -- ";
				blackObject.evade = true;
				blackObject.component = 14;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, false, false, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end bolt loop


	else if( actor.ctrInput == 10 )// bolt 2
	{
		blackObject.abilityName = "Bolt 2";
				blackObject.mp = 12;
				if( actor.halfOfMP == true )
				{
					blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
				}
				blackObject.abilityCTRCount = 5;
				blackObject.display = " -- Bolt damage to target and 4 surrounding squares -- ";
				blackObject.evade = true;
				blackObject.component = 18;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, false, false, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end bolt 2 loop


	else if( actor.ctrInput == 11 )// bolt 3
	{
		blackObject.abilityName = "Bolt 3";
				blackObject.mp = 24;
				if( actor.halfOfMP == true )
				{
					blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
				}
				blackObject.abilityCTRCount = 7;
				blackObject.component = 24;
				blackObject.display = " -- Bolt damage to target and 4 surrounding squares -- ";
				blackObject.evade = true;
				blackObject.abilityChance = 0;
				blackObject.mod = 5;
				blackObject.rangeMax = 4;
				blackObject.rangeMin = 0;
				blackObject.casterImmune = false;
				blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
					blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
					blackObject.evade, false, "", blackObject.reflect, false, false, true );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end bolt 3 loop


	else if( actor.ctrInput == 12 )// bolt 4
	{
		blackObject.abilityName = "Bolt 4";
		blackObject.mp = 48;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.abilityCTRCount = 10;
		blackObject.component = 32;
		blackObject.display = " -- Bolt damage to target and up to 2 squares away -- ";
		blackObject.evade = true;
		blackObject.abilityChance = 0;
		blackObject.mod = 5;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 3;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 13; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false && target.dead == false && target.petrify == false  )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component, false,
						true );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is ... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
				}
				magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end bolt 4 loop


	else if( actor.ctrInput == 13 )// poison
	{
		blackObject.abilityName = "Poison";
		blackObject.abilityCTRCount = 3;
		blackObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.display = " -- add Poison to target and 4 surrounding squares -- ";
		blackObject.evade = true;
		blackObject.component = 160;
		blackObject.abilityChance = 0;
		blackObject.mod = 6;
		blackObject.rangeMax = 3;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 5; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = mod6( actor, target, actor.ma, blackObject.component );
						if( blackObject.abilityChance > 100 )
							blackObject.abilityChance = 100;
					}

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						statusSetter( target, "Poison" );
				
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
					magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
						blackObject.evade, true, "Poison", blackObject.reflect );

					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end Poison loop


	else if( actor.ctrInput == 14 )// frog
	{
		blackObject.abilityName = "Frog";
		blackObject.abilityCTRCount = 5;
		blackObject.mp = 12;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.display = " -- add Frog to target -- ";
		blackObject.evade = true;
		blackObject.component = 120;
		blackObject.abilityChance = 0;
		blackObject.mod = 6;
		blackObject.rangeMax = 3;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 1; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = mod6( actor, target, actor.ma, blackObject.component );
						if( blackObject.abilityChance > 100 )
							blackObject.abilityChance = 100;
					}

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						if( target.frog == false )
						{
							statusSetter( target, "Frog");
				
						}
						else if( target.frog == true )
						{
							target.frog = false;
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " is cured of Frog!\n";
						}
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
					magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
						blackObject.evade, true, "Frog", blackObject.reflect );

					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end frog


	else if( actor.ctrInput == 15 )// death
	{
		blackObject.abilityName = "Death";
		blackObject.abilityCTRCount = 10;
		blackObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.display = " -- add Death to target -- ";
		blackObject.evade = true;
		blackObject.component = 100;
		blackObject.abilityChance = 0;
		blackObject.mod = 6;
		blackObject.rangeMax = 4;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 1; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false && target.dead == false && target.petrify == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = mod6( actor, target, actor.ma, blackObject.component );
						if( blackObject.abilityChance > 100 )
							blackObject.abilityChance = 100;
					}

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						if( target.undead == false && target.bodyDeadBlock == false && target.headDeadBlock == false
							&& target.accDeadBlock == false )
						{
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " dies!\n";
							statusSetter( target, "Dead");
						}
						else if( target.undead == true && target.bodyDeadBlock == false && target.headDeadBlock == false
							&& target.accDeadBlock == false )
						{
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " is healed to full life!\n";
							target.life = target.maxLife;
						}
						else cout << "\t" << blackObject.abilityName << " is blocked!\n";
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
					magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
						blackObject.evade, true, "Death Type", blackObject.reflect );
				}
				j += 2;
			} //end for loop
		}
	}// end death

	else if( actor.ctrInput == 16 )// Flare
	{
		blackObject.abilityName = "Flare";
		blackObject.abilityCTRCount = 7;
		blackObject.mp = 60;
		if( actor.halfOfMP == true )
		{
			blackObject.mp = blackObject.mp / 2 + blackObject.mp % 2;
		}
		blackObject.display = " -- damage to target -- ";
		blackObject.evade = true;
		blackObject.component = 46;
		blackObject.abilityChance = 0;
		blackObject.mod = 6;
		blackObject.rangeMax = 5;
		blackObject.rangeMin = 0;
		blackObject.casterImmune = false;
		blackObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < blackObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << blackObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= blackObject.mp;

			if( actor.ctrFollow == 0 )
			{
				targetVector[0] = actor.ctrRow;
				targetVector[1] = actor.ctrCol;
			}
			else if( actor.ctrFollow == 1 )
			{
				target = targetFunctionFollow( actor.ctrFollowNumber, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				targetVector[0] = target.currentRow;
				targetVector[1] = target.currentCol;
			}
			int i = 0;
			int j = 0;
			for( i = 0; i < 1; i++ )
			{
				effectVector = multiRange( actor, blackObject.effect, blackObject.abilityName, blackObject.rangeMax,
					blackObject.rangeMin, false, blackObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false && target.dead == false && target.petrify == false  )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						blackObject.abilityChance = 0;	
					}
					else
					{
						blackObject.abilityChance = magicEvade( 100, actor, target );
					}

					blackObject.abilityDamage = -mod5Magic( actor, target, actor.ma, blackObject.component );

					blackRoll = rand() % 100 + 1;

					cout << blackObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << blackObject.abilityChance << "% chance to hit...\n";
					cout << "\t" << "Random Number is... " << blackRoll << "\n";

					if( blackRoll <= blackObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, blackObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10 );
					}
					else cout << "\t" << blackObject.abilityName << " misses!\n";
					magicTypeReaction( blackObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						blackObject.mod, blackObject.mp, blackObject.effect, blackObject.component, blackObject.abilityName,
						blackObject.evade, false, "", blackObject.reflect );

					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end Flare loop

	if( actorMPBefore != actor.mp )
	{
		vector<int> mimeVector (2, 0);
		mimeObject.mimeSpellConfirm = 1;
		mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor );
		mimeObject.spellSide = mimeVector[0];
		mimeObject.spellDistance = mimeVector[1];
		mimeObject.abilityName = blackObject.abilityName;
	}
}



