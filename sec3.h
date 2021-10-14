
class YinYang
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
	int abilityDamage2; //mp restore
	int abilityChance;
	int mod;
	int rangeMax;
	int rangeMin;
	int xa;
	int effect;
	bool casterImmune;
	int abilityCTRCount;
	int ctrFollow;
	int mp;
	bool reflect;
	
	YinYang()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "magical";
		display = "";
		mod = 6;
		evade = true;
		abilityDamage = 0;
		abilityChance = 0;
		rangeMin = 0;
		rangeMax = 4;
		component = 0;
	}
	~YinYang() {}

	void yinYangMenu( YinYang &yinYangObject, Player actor );
	void yinYangSuccess( YinYang &yinYangObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem );
};

void YinYang::yinYangMenu( YinYang &yinYangObject, Player actor )
{
	int yinYangAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " YIN YANG MAGIC Menu ---\n" 	
	<< "0.) Return to Menu\n" 
	<< "1.) BLIND           -- add Darkness to area --  4 MP -- 2 CTR\n"
	<< "2.) SPELL ABSORB    -- absorb MP            --  2 MP -- 2 CTR\n" 
	<< "3.) LIFE DRAIN      -- absorb HP            -- 16 MP -- 2 CTR\n"
	<< "4.) PRAY FAITH      -- add Faith            --  6 MP -- 4 CTR\n" 
	<< "5.) DOUBT FAITH     -- add Innocent         --  6 MP -- 4 CTR\n"
	<< "6.) ZOMBIE          -- add Undead           -- 20 MP -- 5 CTR\n" 
	<< "7.) SILENCE SONG    -- add Silence to area  -- 16 MP -- 3 CTR\n" 
	<< "8.) BLIND RAGE      -- add Berserk          -- 16 MP -- 5 CTR\n" 
	<< "9.) FOXBIRD         -- Brave -30            -- 20 MP -- 4 CTR\n"
	<< "10.) CONFUSION SONG -- add Confusion        -- 20 MP -- 5 CTR\n" 
	<< "11.) DISPEL MAGIC   -- dispel good status   -- 34 MP -- 3 CTR\n"
	<< "12.) PARALYZE       -- add Don't Act area   -- 10 MP -- 5 CTR\n"
	<< "13.) SLEEP          -- add Sleep to area    -- 24 MP -- 6 CTR\n"
	<< "14.) PETRIFY        -- add Petrify          -- 16 MP -- 9 CTR\n"
	) && 
	( !(cin >> yinYangAction ) || yinYangAction < 0 || yinYangAction > 14 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	yinYangObject.playerInput = yinYangAction;
	if( yinYangAction == 0 )
	{
		yinYangObject.confirm = 0;
	}
	else yinYangObject.confirm = 2;
}

void YinYang::yinYangSuccess( YinYang &yinYangObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem )
{
	yinYangObject.abilityName = "";
	yinYangObject.display = "";
	yinYangObject.evade = true;
	yinYangObject.abilityDamage = 0;
	yinYangObject.abilityChance = 0;
	yinYangObject.mod = 6;
	yinYangObject.rangeMax = 4;
	yinYangObject.rangeMin = 0;
	yinYangObject.component = 0;
	yinYangObject.casterImmune = false;
	yinYangObject.effect = 2;
	yinYangObject.abilityCTRCount = 0;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	long int tempHitChance;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int yinYangRoll = 0;
	int yinYangConfirm = 2;

	if( yinYangObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( yinYangObject.confirm != 0 ) 
	{
		do
		{
			if( yinYangObject.playerInput == 1 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Blind";
				yinYangObject.abilityCTRCount = 2;
				yinYangObject.display = "-- add Darkness to target and 4 surrounding squares";
				yinYangObject.evade = true;
				yinYangObject.component = 200;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 2;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Blind loop

			else if( yinYangObject.playerInput == 2 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Spell Absorb";
				yinYangObject.abilityCTRCount = 2;

				yinYangObject.display = "-- Drain MP from the target & restore to actor -- MP ";
				yinYangObject.evade = true;
				yinYangObject.component = 160;
				yinYangObject.abilityChance = 0;
				yinYangObject.abilityDamage = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 1;
				yinYangObject.casterImmune = true;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.maxMP % 3 == 0 )
					tempDamage = 0;
				else tempDamage = 1;
				yinYangObject.abilityDamage = -target.maxMP * 33 / 100 + tempDamage;

				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, false );
		
			}//end spell absorb loop

			else if( yinYangObject.playerInput == 3 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Life Drain";
				yinYangObject.abilityCTRCount = 2;

				yinYangObject.display = "-- drain HP from target & restore to caster -- HP ";
				yinYangObject.evade = true;
				yinYangObject.component = 160;
				yinYangObject.abilityChance = 0;
				yinYangObject.abilityDamage = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 1;
				yinYangObject.casterImmune = true;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.maxLife % 4 == 0 )
					tempDamage = 0;
				else tempDamage = 1;
				if( target.undead == false )
					yinYangObject.abilityDamage = -target.maxLife * 25 / 100 + tempDamage;
				else if( target.undead == true )
					yinYangObject.abilityDamage = target.maxLife * 25 / 100 + tempDamage;

				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, false );
				
			}//end life drain loop

			else if( yinYangObject.playerInput == 4 )
			{
				//can be counter magic'd, reflected
				yinYangObject.abilityName = "Pray Faith";
				yinYangObject.abilityCTRCount = 4;

				yinYangObject.display = "-- add Faith to target";
				yinYangObject.evade = false;
				yinYangObject.component = 150;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Pray Faith loop

			else if( yinYangObject.playerInput == 5 )
			{
				//can be  reflected
				yinYangObject.abilityName = "Doubt Faith";
				yinYangObject.abilityCTRCount = 4;

				yinYangObject.display = "-- add Innocent to target";
				yinYangObject.evade = false;
				yinYangObject.component = 150;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		

				
			}//end Doubt Faith loop

			else if( yinYangObject.playerInput == 6 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Zombie";
				yinYangObject.abilityCTRCount = 5;

				yinYangObject.display = " -- add Undead to target";
				yinYangObject.evade = true;
				yinYangObject.component = 100;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Zombie loop

			else if( yinYangObject.playerInput == 7 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Silence Song";
				yinYangObject.abilityCTRCount = 3;

				yinYangObject.display = " -- add Silence to target and 4 surrounding squares";
				yinYangObject.evade = true;
				yinYangObject.component = 180;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 2;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end silence song loop

			else if( yinYangObject.playerInput == 8 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Blind Rage";
				yinYangObject.abilityCTRCount = 5;

				yinYangObject.display = " -- add Berserk to target";
				yinYangObject.evade = true;
				yinYangObject.component = 120;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end blind rage loop

			else if( yinYangObject.playerInput == 9 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Foxbird";
				yinYangObject.abilityCTRCount = 4;

				yinYangObject.display = " -- target Brave -30";
				yinYangObject.evade = true;
				yinYangObject.component = 140;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Foxbird loop

			else if( yinYangObject.playerInput == 10 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Confusion Song";
				yinYangObject.abilityCTRCount = 5;

				yinYangObject.display = " -- add Confusion to target";
				yinYangObject.evade = true;
				yinYangObject.component = 130;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Confusion Song loop loop

			else if( yinYangObject.playerInput == 11 )
			{
	
				yinYangObject.abilityName = "Dispel Magic";
				yinYangObject.abilityCTRCount = 3;

				yinYangObject.display = " -- remove Prot/Shell/Haste/Float/Regen/Reraise/Faith/Reflect";
				yinYangObject.evade = false;
				yinYangObject.component = 200;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Dispel Magic loop

			else if( yinYangObject.playerInput == 12 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Paralyze";
				yinYangObject.abilityCTRCount = 5;

				yinYangObject.display = "-- add Don't Act to target and 4 surrounding squares";
				yinYangObject.evade = true;
				yinYangObject.component = 185;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 2;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );

				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end paralyze loop

			else if( yinYangObject.playerInput == 13 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Sleep";
				yinYangObject.abilityCTRCount = 6;

				yinYangObject.display = " -- add Sleep to target and 4 surrounding squares";
				yinYangObject.evade = true;
				yinYangObject.component = 170;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 2;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );

				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end sleep loop

			else if( yinYangObject.playerInput == 14 )
			{
				//can be evaded, counter magic'd, reflected
				yinYangObject.abilityName = "Petrify";
				yinYangObject.abilityCTRCount = 9;

				yinYangObject.display = " -- add Petrify to target";
				yinYangObject.evade = true;
				yinYangObject.component = 120;
				yinYangObject.abilityChance = 0;
				yinYangObject.mod = 6;
				yinYangObject.rangeMax = 4;
				yinYangObject.rangeMin = 0;
				yinYangObject.casterImmune = false;
				yinYangObject.effect = 1;

				targetVector = rangeTest( actor, yinYangObject.rangeMax,
					yinYangObject.abilityName, yinYangObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
				yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );

				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					yinYangObject.abilityChance = 0;

				if( yinYangObject.abilityChance >= 100 )
					yinYangObject.abilityChance = 100;
				if( yinYangObject.abilityChance < 0 )
					yinYangObject.abilityChance = 0;

				yinYangConfirm = targetDisplay( target, yinYangObject.abilityName,
					yinYangObject.abilityChance, yinYangObject.abilityDamage, yinYangObject.display, true );
		
			}//end Petrify loop loop

			if( yinYangConfirm == 1 )
			{
				actor.ctrRow = targetVector[0];
				actor.ctrCol = targetVector[1];

				if( myArray[actor.ctrRow][actor.ctrCol] != 'O' )
				{
					yinYangObject.ctrFollow = targetFollowDisplay();
				}
				else yinYangObject.ctrFollow = 0;

				actor.charging = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 13;
				actor.ctrName = yinYangObject.abilityName;
				actor.ctrCountdown = yinYangObject.abilityCTRCount;
				if( actor.shortCharge == true )
					actor.ctrCountdown = actor.ctrCountdown / 2 + actor.ctrCountdown % 2;
				actor.ctrInput = yinYangObject.playerInput;
				actor.ctrFollow = yinYangObject.ctrFollow;

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

		}while( yinYangConfirm == 2);
	}
		
	if( yinYangConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void yinYangResolve( YinYang &yinYangObject, Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem, char myArray[][11], Player &nullPlayer, MimeClass &mimeObject )
{

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	vector<int> refVec(2, 0 );
	long int tempHitChance;
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int yinYangRoll = 0;
	int yinYangConfirm = 2;
	yinYangObject.reflect = true;

	mimeObject.mimeSpellConfirm = 0;
	bool mimeSilenceCheck = actor.silence;
	bool mimeMPCheck = true;

	if( actor.ctrInput == 1 )
	{
		yinYangObject.abilityName = "Blind";
		yinYangObject.mp = 4;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityCTRCount = 2;
		yinYangObject.display = " -- add Darkness to target and 4 surrounding squares -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 200;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4; 
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
			mimeMPCheck = false;
		}

		else //spell is cast!
		{
			

			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
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
						yinYangObject.abilityChance = 0;	
					}
					else
					{
						tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
						yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
						if( yinYangObject.abilityChance >= 100 )
							yinYangObject.abilityChance = 100;
						if( yinYangObject.abilityChance < 0 )
							yinYangObject.abilityChance = 0;
					}

					yinYangRoll = rand() % 100 + 1;

					cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << yinYangRoll << "\n";

					if( yinYangRoll <= yinYangObject.abilityChance )
					{
						statusSetter( target, "Darkness" );
	
					}
					else cout << "\t" << yinYangObject.abilityName << " misses!\n";
					magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Darkness", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end blind loop


	else if( actor.ctrInput == 2 )
	{
		yinYangObject.mp = 2;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Spell Absorb";
		yinYangObject.abilityCTRCount = 2;
		yinYangObject.display = " -- Drain MP from the target & restore to actor -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 160;
		yinYangObject.abilityChance = 0;
		yinYangObject.abilityDamage = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 1;
		yinYangObject.casterImmune = true;
		yinYangObject.effect = 1;
		

		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
					yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
					if( yinYangObject.abilityChance >= 100 )
							yinYangObject.abilityChance = 100;
						if( yinYangObject.abilityChance < 0 )
							yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{ 
					if( target.maxMP % 3 == 0 )
						tempDamage = 0;
					else tempDamage = 1;
					yinYangObject.abilityDamage = target.maxMP * 33 / 100 + tempDamage;
					target.mp -= yinYangObject.abilityDamage;
					actor.mp += yinYangObject.abilityDamage;
					if( target.mp < 0)
						target.mp = 0;
					if( actor.mp > actor.maxMP )
						actor.mp = actor.maxMP;
					cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< " loses " << yinYangObject.abilityDamage << " MP!\n";
					cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " gains " << yinYangObject.abilityDamage << " MP!\n";

					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, false, "", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end spell absorb loop


	else if( actor.ctrInput == 3 )// life drain
	{
		yinYangObject.mp = 16;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Life Drain";
		yinYangObject.abilityCTRCount = 2;

		yinYangObject.display = " -- Drain HP from target & restore to caster -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 160;
		yinYangObject.abilityChance = 0;
		yinYangObject.abilityDamage = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 1;
		yinYangObject.casterImmune = true;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
					yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{ 
					if( target.maxMP % 4 == 0 )
						tempDamage = 0;
					else tempDamage = 1;
					yinYangObject.abilityDamage = target.maxLife * 25 / 100 + tempDamage;
					
					if( target.undead == false)
					{
						target.life -= yinYangObject.abilityDamage;
						actor.life += yinYangObject.abilityDamage;
						if( target.life < 0)
						{
							target.life = 0;
							target.dead = true;
							target.deadTimer = 3;
						}
						if( actor.life > actor.maxLife )
							actor.life = actor.maxLife;
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " loses " << yinYangObject.abilityDamage << " HP!\n";
						cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " gains " << yinYangObject.abilityDamage << " HP!\n";
						hpReaction( target, blueItem, redItem, actor, yinYangObject.abilityDamage );
				
					}
					else if( target.undead == true )
					{
						target.life += yinYangObject.abilityDamage;
						actor.life -= yinYangObject.abilityDamage;
						if( actor.life < 0)
						{
							actor.life = 0;
							actor.dead = true;
							actor.deadTimer = 3;
						}
						if( target.life > target.maxLife )
							target.life = target.maxLife;
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " gains " << yinYangObject.abilityDamage << " HP!\n";
						cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " loses " << yinYangObject.abilityDamage << " HP!\n";
					}
					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, false, "", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
			
		}
	}// end life drain loop


	else if( actor.ctrInput == 4 )// pray faith
	{
		yinYangObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Pray Faith";
		yinYangObject.abilityCTRCount = 4;

		yinYangObject.display = " -- add Faith to target -- ";
		yinYangObject.evade = false;
		yinYangObject.component = 150;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					yinYangObject.abilityChance = mod6( actor, target, actor.ma, yinYangObject.component );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;				
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{
					statusSetter( target, "Faith" );
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );

				endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
			
		}
	}// end pray faith loop


	else if( actor.ctrInput == 5 )// doubt faith
	{
		yinYangObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Doubt Faith";
		yinYangObject.abilityCTRCount = 4;

		yinYangObject.display = " -- add Innocent to target -- ";
		yinYangObject.evade = false;
		yinYangObject.component = 150;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					yinYangObject.abilityChance = mod6( actor, target, actor.ma, yinYangObject.component );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;				
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{
					statusSetter( target, "Innocent" );
					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem ); //no counter magic
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end doubt faith loop


	else if( actor.ctrInput == 6 )// zombie
	{
		yinYangObject.mp = 20;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Zombie";
		yinYangObject.abilityCTRCount = 5;

		yinYangObject.display = " -- add Undead to target -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 100;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
					yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{
					statusSetter( target, "Undead" );
					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Undead", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end zombie loop


	else if( actor.ctrInput == 7 )// silence song
	{
		yinYangObject.mp = 16;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Silence";
		yinYangObject.abilityCTRCount = 3;

		yinYangObject.display = " -- add Silence to target and 4 surrounding squares -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 180;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{

					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						yinYangObject.abilityChance = 0;	
					}
					else
					{
						tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
						yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
						if( yinYangObject.abilityChance >= 100 )
							yinYangObject.abilityChance = 100;
						if( yinYangObject.abilityChance < 0 )
							yinYangObject.abilityChance = 0;
					}

					yinYangRoll = rand() % 100 + 1;

					cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << yinYangRoll << "\n";

					if( yinYangRoll <= yinYangObject.abilityChance )
					{
						statusSetter( target, "Silence");
						
					}
					else cout << "\t" << yinYangObject.abilityName << " misses!\n";
					magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Silence", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
					j += 2;
			} //end for loop
		}
	}// end silence song loop


	else if( actor.ctrInput == 8 )// blind rage
	{
		yinYangObject.mp = 16;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Blind Rage";
		yinYangObject.abilityCTRCount = 5;

		yinYangObject.display = " -- add Berserk to target -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 120;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true
						)
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
					yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{
					statusSetter( target, "Berserk" );
					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Berserk", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end blind rage loop


	else if( actor.ctrInput == 9 )//foxbird
	{
		yinYangObject.mp = 20;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Foxbird";
		yinYangObject.abilityCTRCount = 4;

		yinYangObject.display = " -- target Brave -30 -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 140;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
					yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{
					target.brave -= 30;
					cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< " loses 30 Brave!\n";
					if( target.brave <= 0 )
						target.brave = 0;
					if( target.brave <= 9)
					{
						statusSetter( target, "Chicken" );
					}
					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
						yinYangObject.evade, true, "Chicken", yinYangObject.reflect, false, false, false, false, false,
						false, false, false );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end foxbird loop


	else if( actor.ctrInput == 10 )// confusion song
	{
		yinYangObject.mp = 20;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Confusion Song";
		yinYangObject.abilityCTRCount = 5;

		yinYangObject.display = " -- add Confusion to target -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 130;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true
						)
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
					yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
				{
					statusSetter( target, "Confusion" );
					
				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Confusion", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end confusion song loop


	else if( actor.ctrInput == 11 )// dispel magic
	{
		yinYangObject.mp = 34;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Dispel Magic";
		yinYangObject.abilityCTRCount = 3;

		yinYangObject.display = " -- remove Protect/Shell/Haste/Float/Regen/Reraise/Transparent/Faith/Reflect from target -- ";
		yinYangObject.evade = false;
		yinYangObject.component = 200;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		yinYangObject.reflect = false;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.dead == true || target.petrify == true )
				{
					yinYangObject.abilityChance = 0;	
				}
				else
				{
					yinYangObject.abilityChance = mod6( actor, target, actor.ma, yinYangObject.component );
					if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
					if( yinYangObject.abilityChance < 0 )
						yinYangObject.abilityChance = 0;
				}

				yinYangRoll = rand() % 100 + 1;

				cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << yinYangRoll << "\n";

				if( yinYangRoll <= yinYangObject.abilityChance )
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
					cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< " loses beneficial status!\n";

				}
				else cout << "\t" << yinYangObject.abilityName << " misses!\n";
				
				magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
						yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
						yinYangObject.evade, false, "", yinYangObject.reflect, false, false, false, false, false,
						false, false, false );

				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end dispel magic loop


	else if( actor.ctrInput == 12 )
	{
		yinYangObject.mp = 10;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Paralyze";
		yinYangObject.abilityCTRCount = 5;

		yinYangObject.display = " -- add Don't Act to target and 4 surrounding squares -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 185;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
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
						yinYangObject.abilityChance = 0;	
					}
					else
					{
						tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
						yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
						if( yinYangObject.abilityChance >= 100 )
						yinYangObject.abilityChance = 100;
						if( yinYangObject.abilityChance < 0 )
							yinYangObject.abilityChance = 0;
					}

					yinYangRoll = rand() % 100 + 1;

					cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << yinYangRoll << "\n";

					if( yinYangRoll <= yinYangObject.abilityChance )
					{
						statusSetter( target, "Don't Act" );
						
					}
					else cout << "\t" << yinYangObject.abilityName << " misses!\n";
					magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Don't Act", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end paralyze loop


	else if( actor.ctrInput == 13 )// sleep
	{
		yinYangObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Sleep";
		yinYangObject.abilityCTRCount = 6;

		yinYangObject.display = "-- add Sleep to target and 4 surrounding squares -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 170;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
				effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
					yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false && target.petrify == false && target.dead == false )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						yinYangObject.abilityChance = 0;	
					}
					else
					{
						tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
						yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
						if( yinYangObject.abilityChance >= 100 )
							yinYangObject.abilityChance = 100;
						if( yinYangObject.abilityChance < 0 )
							yinYangObject.abilityChance = 0;
					}

					yinYangRoll = rand() % 100 + 1;

					cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << yinYangRoll << "\n";

					if( yinYangRoll <= yinYangObject.abilityChance )
					{
						statusSetter( target, "Sleep" );
					}
					else cout << "\t" << yinYangObject.abilityName << " misses!\n";
					magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Sleep", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end sleep loop


	else if( actor.ctrInput == 14 )// petrify
	{
		yinYangObject.mp = 16;
		if( actor.halfOfMP == true )
		{
			yinYangObject.mp = yinYangObject.mp / 2 + yinYangObject.mp % 2;
		}
		yinYangObject.abilityName = "Petrify";
		yinYangObject.abilityCTRCount = 9;

		yinYangObject.display = " -- add Petrify to target -- ";
		yinYangObject.evade = true;
		yinYangObject.component = 120;
		yinYangObject.abilityChance = 0;
		yinYangObject.mod = 6;
		yinYangObject.rangeMax = 4;
		yinYangObject.rangeMin = 0;
		yinYangObject.casterImmune = false;
		yinYangObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < yinYangObject.mp )
		{
			mimeMPCheck = false;
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << yinYangObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= yinYangObject.mp;

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
						effectVector = multiRange( actor, yinYangObject.effect, yinYangObject.abilityName, yinYangObject.rangeMax,
							yinYangObject.rangeMin, false, yinYangObject.casterImmune, targetVector[0], targetVector[1] );
						refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
							player1, player2, player3, player4, player5, player6, player7,
							player8, player9, player10, nullPlayer, myArray, true );
						effectVector[j] = refVec[0];
						effectVector[j+1] = refVec[1];
						target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
						if( target.nullPlayer == true || target.dead == true || target.petrify == true
							 )
						{
							yinYangObject.abilityChance = 0;	
						}
						else
						{
							tempHitChance = mod6( actor, target, actor.ma, yinYangObject.component );
							yinYangObject.abilityChance = magicEvade( tempHitChance, actor, target );
							if( yinYangObject.abilityChance >= 100 )
								yinYangObject.abilityChance = 100;
							if( yinYangObject.abilityChance < 0 )
								yinYangObject.abilityChance = 0;
						}

						yinYangRoll = rand() % 100 + 1;

						cout << yinYangObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
									<< " " << target.playerName << ". " << yinYangObject.abilityChance << "% chance to hit...\n";
						cout << "\tRandom Number is... " << yinYangRoll << "\n";

						if( yinYangRoll <= yinYangObject.abilityChance )
						{
							statusSetter( target, "Petrify" );
						}
						else cout << "\t" << yinYangObject.abilityName << " misses!\n";
						magicTypeReaction( yinYangObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							yinYangObject.mod, yinYangObject.mp, yinYangObject.effect, yinYangObject.component, yinYangObject.abilityName,
							yinYangObject.evade, true, "Petrify", yinYangObject.reflect, false, false, false, false, false,
							false, false, false );
						endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
						j += 2;
					} //end for loop
		}
	}// end petrify loop

	if( mimeSilenceCheck == false && mimeMPCheck == true )
	{
		vector<int> mimeVector (2, 0);
		mimeObject.mimeSpellConfirm = 1;
		mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor );
		mimeObject.spellSide = mimeVector[0];
		mimeObject.spellDistance = mimeVector[1];
		mimeObject.abilityName = yinYangObject.abilityName;
	}
}



class White
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
	
	White()
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
	~White() {}

	void whiteMenu( White &whiteObject, Player actor );
	void whiteSuccess( White &whiteObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem );
};

void White::whiteMenu( White &whiteObject, Player actor )
{
	int whiteAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " WHITE MAGIC Menu ---\n" 	
		<< "0.) Return to Menu\n"
		<< "1.) CURE       -- restore HP to area  --  6 MP --  4 CTR\n"
		<< "2.) CURE 2     -- restore HP to area  -- 10 MP --  5 CTR\n"  
		<< "3.) CURE 3     -- restore HP to area  -- 16 MP --  7 CTR\n"
		<< "4.) CURE 4     -- restore HP to area  -- 20 MP -- 10 CTR\n" 
		<< "5.) RAISE      -- cure Dead           -- 10 MP --  4 CTR\n"
		<< "6.) RAISE 2    -- cure Dead           -- 20 MP -- 10 CTR\n" 
		<< "7.) RERAISE    -- add Reraise         -- 16 MP --  7 CTR\n"
		<< "8.) REGEN      -- add Regen to area   --  8 MP --  4 CTR\n"
		<< "9.) PROTECT    -- add Protect to area --  6 MP --  4 CTR\n" 
		<< "10.) PROTECT 2 -- add Protect to area -- 24 MP --  7 CTR\n" 
		<< "11.) SHELL     -- add Shell to area   --  6 MP --  4 CTR\n"
		<< "12.) SHELL 2   -- add Shell to area   -- 20 MP --  7 CTR\n" 
		<< "13.) WALL      -- add Protect & Shell -- 24 MP --  4 CTR\n"
		<< "14.) ESUNA     -- cure bad Status     -- 18 MP --  3 CTR\n"
		<< "15.) HOLY      -- Holy damage         -- 56 MP --  6 CTR\n"
	) && 
	( !(cin >> whiteAction ) || whiteAction < 0 || whiteAction > 15 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	whiteObject.playerInput = whiteAction;
	if( whiteAction == 0 )
	{
		whiteObject.confirm = 0;
	}
	else whiteObject.confirm = 2;
}

void White::whiteSuccess( White &whiteObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem )
{
	whiteObject.abilityName = "";
	whiteObject.display = "";
	whiteObject.evade = false;
	whiteObject.abilityDamage = 0;
	whiteObject.abilityChance = 0;
	whiteObject.mod = 5;
	whiteObject.rangeMax = 4;
	whiteObject.rangeMin = 0;
	whiteObject.component = 0;
	whiteObject.casterImmune = false;
	whiteObject.effect = 2;
	whiteObject.abilityCTRCount = 0;

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int whiteRoll = 0;
	int whiteConfirm = 2;

	if( whiteObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( whiteObject.confirm != 0 ) 
	{
		do
		{
			if( whiteObject.playerInput == 1 )
			{
				//can be counter magic'd, reflected
				whiteObject.abilityName = "Cure";
				whiteObject.abilityCTRCount = 4;
				whiteObject.display = "-- restore HP to target and 4 surrounding squares -- HP ";
				whiteObject.evade = false;
				whiteObject.component = 14;
				whiteObject.abilityChance = 100;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display );

			}//end cure loop

			else if( whiteObject.playerInput == 2 )
			{
				whiteObject.abilityName = "Cure 2";
				whiteObject.abilityCTRCount = 5;
				whiteObject.display = "-- restore HP to target and 4 surrounding squares -- HP ";
				whiteObject.evade = false;
				whiteObject.component = 20;
				whiteObject.abilityChance = 100;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display );
				
			}//end cure 2

			else if( whiteObject.playerInput == 3 )
			{
				whiteObject.abilityName = "Cure 3";
				whiteObject.abilityCTRCount = 7;
				whiteObject.display = "-- restore HP to target and 4 surrounding squares -- HP ";
				whiteObject.evade = false;
				whiteObject.component = 30;
				whiteObject.abilityChance = 100;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display );
				
			}//end cure 3 loop

			else if( whiteObject.playerInput == 4 )
			{
				whiteObject.abilityName = "Cure 4";
				whiteObject.abilityCTRCount = 10;
				whiteObject.display = "-- restore HP to target and 4 surrounding squares -- HP ";
				whiteObject.evade = false;
				whiteObject.component = 40;
				whiteObject.abilityChance = 100;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display );
				
			}//end Cure 4 loop

			else if( whiteObject.playerInput == 5 )
			{
				//can be  reflected
				whiteObject.abilityName = "Raise";
				whiteObject.abilityCTRCount = 4;

				whiteObject.display = "-- restore target with half HP";
				whiteObject.evade = false;
				whiteObject.component = 180;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 1;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == false )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end raise

			else if( whiteObject.playerInput == 6 )
			{
				whiteObject.abilityName = "Raise 2";
				whiteObject.abilityCTRCount = 10;

				whiteObject.display = "-- restore target with full HP";
				whiteObject.evade = false;
				whiteObject.component = 160;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 1;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == false )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end raise 2 loop

			else if( whiteObject.playerInput == 7 )
			{
				whiteObject.abilityName = "Reraise";
				whiteObject.abilityCTRCount = 7;

				whiteObject.display = "-- add Reraise to target";
				whiteObject.evade = false;
				whiteObject.component = 140;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 4;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 1;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				if( target.undead == true)
					whiteObject.abilityChance = 0;
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end reraise loop

			else if( whiteObject.playerInput == 8 )
			{
				whiteObject.abilityName = "Regen";
				whiteObject.abilityCTRCount = 4;

				whiteObject.display = "-- add Regen to target and 4 surrounding squares";
				whiteObject.evade = false;
				whiteObject.component = 170;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end regen loop

			else if( whiteObject.playerInput == 9 )
			{
				whiteObject.abilityName = "Protect";
				whiteObject.abilityCTRCount = 4;

				whiteObject.display = "-- add Protect to target and 4 surrounding squares";
				whiteObject.evade = false;
				whiteObject.component = 200;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );
			}//end protect loop

			else if( whiteObject.playerInput == 10 )
			{
				whiteObject.abilityName = "Protect 2";
				whiteObject.abilityCTRCount = 7;

				whiteObject.display = "-- add Protect to target and 4 surrounding squares";
				whiteObject.evade = false;
				whiteObject.component = 120;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end protect 2 loop

			else if( whiteObject.playerInput == 11 )
			{
	
				whiteObject.abilityName = "Shell";
				whiteObject.abilityCTRCount = 4;

				whiteObject.display = "-- add Shell to target and 4 surrounding squares";
				whiteObject.evade = false;
				whiteObject.component = 200;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );
			}//end shell loop

			else if( whiteObject.playerInput == 12 )
			{
				whiteObject.abilityName = "Shell 2";
				whiteObject.abilityCTRCount = 7;

				whiteObject.display = "-- add Shell to target and 4 surrounding squares";
				whiteObject.evade = false;
				whiteObject.component = 120;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end shell 2 loop

			else if( whiteObject.playerInput == 13 )
			{
				whiteObject.abilityName = "Wall";
				whiteObject.abilityCTRCount = 7;

				whiteObject.display = "-- add Protect & Shell to target";
				whiteObject.evade = false;
				whiteObject.component = 140;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 1;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );

			}//end wall loop

			else if( whiteObject.playerInput == 14 )
			{
				whiteObject.abilityName = "Esuna";
				whiteObject.abilityCTRCount = 3;

				whiteObject.display = "-- cure Petr/Dark/Conf/Sile/Bers/Frog/Pois/Sleep/Don't Move/Act";
				whiteObject.evade = false;
				whiteObject.component = 190;
				whiteObject.abilityChance = 0;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 3;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 2;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				
				if( whiteObject.abilityChance >= 100 )
					whiteObject.abilityChance = 100;
				if( whiteObject.abilityChance < 0 )
					whiteObject.abilityChance = 0;

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, true );
			}//end esuna loop loop


			else if( whiteObject.playerInput == 15 )
			{
				whiteObject.abilityName = "Holy";
				whiteObject.abilityCTRCount = 6;
				whiteObject.display = "-- Holy damage to target -- HP ";
				whiteObject.evade = false;
				whiteObject.component = 50;
				whiteObject.abilityChance = 100;
				whiteObject.mod = 6;
				whiteObject.rangeMax = 5;
				whiteObject.rangeMin = 0;
				whiteObject.casterImmune = false;
				whiteObject.effect = 1;

				targetVector = rangeTest( actor, whiteObject.rangeMax,
					whiteObject.abilityName, whiteObject.rangeMin );
				target = targetFunction( targetVector[0], targetVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				//holy does not ignore shell or magic defend up
				whiteObject.abilityDamage = -mod5Magic( actor, target, actor.ma, whiteObject.component, false, false, false,
					false, true );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
					whiteObject.abilityChance = 0;
				whiteConfirm = targetDisplay( target, whiteObject.abilityName, whiteObject.abilityChance,
					whiteObject.abilityDamage, whiteObject.display, false );
				
			}//end Holy loop


			if( whiteConfirm == 1 )
			{
				actor.ctrRow = targetVector[0];
				actor.ctrCol = targetVector[1];

				if( myArray[actor.ctrRow][actor.ctrCol] != 'O' )
				{
					whiteObject.ctrFollow = targetFollowDisplay();
				}
				else whiteObject.ctrFollow = 0;

				actor.charging = true;
				actor.ctrCountdownBool = true;
				actor.ctrType = 14;
				actor.ctrName = whiteObject.abilityName;
				actor.ctrCountdown = whiteObject.abilityCTRCount;
				if( actor.shortCharge == true )
					actor.ctrCountdown = actor.ctrCountdown / 2 + actor.ctrCountdown % 2;
				actor.ctrInput = whiteObject.playerInput;
				actor.ctrFollow = whiteObject.ctrFollow;

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

		}while( whiteConfirm == 2);
	}
		
	if( whiteConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}

void whiteResolve( White &whiteObject, Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Item &blueItem, Item &redItem, char myArray[][11], Player &nullPlayer, MimeClass &mimeObject )
{

	Player target;
	vector<int> targetVector (2, 0);
	vector<int> effectVector (50, 0);
	vector<int> refVec( 2, 0 );

	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int whiteRoll = 0;
	int whiteConfirm = 2;
	whiteObject.reflect = false;

	bool mimeSilenceCheck = actor.silence;
	mimeObject.mimeSpellConfirm = 0;
	int actorMPBefore = actor.mp;

	if( actor.ctrInput == 1 )
	{
		whiteObject.abilityName = "Cure";
		whiteObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityCTRCount = 4;
		whiteObject.display = " -- restore HP to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 14;
		whiteObject.abilityChance = 100;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = 100;
					}

					whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, whiteObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10 , true );
					}
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end cure loop


	else if( actor.ctrInput == 2 )
	{
		whiteObject.abilityName = "Cure 2";
		whiteObject.mp = 10;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityCTRCount = 5;
		whiteObject.display = " -- restore HP to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 20;
		whiteObject.abilityChance = 100;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = 100;
					}

					whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, whiteObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10 , true );
					}
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end cure 2 loop


	else if( actor.ctrInput == 3 )// cure 3
	{
		whiteObject.abilityName = "Cure 3";
		whiteObject.mp = 16;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityCTRCount = 7;
		whiteObject.display = " -- restore HP to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 30;
		whiteObject.abilityChance = 100;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = 100;
					}

					whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, whiteObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10 , true );
					}
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end cure 3 loop


	else if( actor.ctrInput == 4 )// cure 4
	{
		whiteObject.abilityName = "Cure 4";
		whiteObject.mp = 20;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityCTRCount = 10;
		whiteObject.display = " -- restore HP to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 40;
		whiteObject.abilityChance = 100;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
				
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = 100;
					}

					whiteObject.abilityDamage = mod5White( actor, target, actor.ma, whiteObject.component );

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, whiteObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10 , true );
					}
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end cure 4 loop


	else if( actor.ctrInput == 5 )// Raise
	{
		whiteObject.mp = 10;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Raise";
		whiteObject.abilityCTRCount = 4;
		whiteObject.display = " -- restore target with half HP -- ";
		whiteObject.evade = false;
		whiteObject.component = 180;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.petrify == true || ( target.dead == true && target.undead == true ) )
				{
					whiteObject.abilityChance = 0;	
				}
				else if( target.dead == true || target.undead == true )
				{
					whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				}

				whiteRoll = rand() % 100 + 1;

				cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << whiteRoll << "\n";

				if( whiteRoll <= whiteObject.abilityChance )
				{
					if ( target.dead == true )
					{
						target.dead = false;
						target.life = target.maxLife * 50 / 100 + target.maxLife % 2;
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is restored to Life!\n";
					}
					else if( target.undead == true )
					{
						whiteObject.abilityDamage = target.maxLife * 50 / 100 + target.maxLife % 2;
						target.life -= whiteObject.abilityDamage;
						if( target.life < 0 )
						{
							statusSetter( target, "Dead" );
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " loses "<< whiteObject.abilityDamage << " HP and dies!\n";
						}
						else
						{
							cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
								<< " loses "<< whiteObject.abilityDamage << " HP!\n";
						}
					}
				}
				else cout << "\t" << whiteObject.abilityName << " misses!\n";
				magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end raise loop


	else if( actor.ctrInput == 6 )// raise 2
	{
		whiteObject.mp = 20;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Raise 2";
		whiteObject.abilityCTRCount = 10;
		whiteObject.display = " -- restore target with full HP -- ";
		whiteObject.evade = false;
		whiteObject.component = 160;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.petrify == true || ( target.dead == true && target.undead == true ) )
				{
					whiteObject.abilityChance = 0;	
				}
				else if( target.dead == true || target.undead == true )
				{
					whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				}

				whiteRoll = rand() % 100 + 1;

				cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << whiteRoll << "\n";

				if( whiteRoll <= whiteObject.abilityChance )
				{
					if ( target.dead == true )
					{
						target.dead = false;
						target.life = target.maxLife;
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is restored to Life!\n";
					}
					else if( target.undead == true )
					{
						statusSetter( target, "Dead" );
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " dies!\n";
					}
				}
				else cout << "\t" << whiteObject.abilityName << " misses!\n";
				magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end raise 2 loop


	else if( actor.ctrInput == 7 )// reraise
	{
		whiteObject.mp = 16;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Reraise";
		whiteObject.abilityCTRCount = 7;

		whiteObject.display = " -- add Reraise to target -- ";
		whiteObject.evade = false;
		whiteObject.component = 140;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 4;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.petrify == true || target.dead == true || target.undead == true )
				{
					whiteObject.abilityChance = 0;	
				}
				else
				{
					whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				}

				whiteRoll = rand() % 100 + 1;

				cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << whiteRoll << "\n";

				if( whiteRoll <= whiteObject.abilityChance )
				{
					statusSetter( target, "Reraise" );

				}
				else cout << "\t" << whiteObject.abilityName << " misses!\n";
				magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end reraise loop


	else if( actor.ctrInput == 8 )// regen
	{
		whiteObject.mp = 8;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Regen";
		whiteObject.abilityCTRCount = 4;

		whiteObject.display = " -- add Regen to target -- ";
		whiteObject.evade = false;
		whiteObject.component = 170;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					whiteObject.abilityChance = 0;	
				}
				else
				{
					whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
				}

				whiteRoll = rand() % 100 + 1;

				cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
							<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
				cout << "\tRandom Number is... " << whiteRoll << "\n";

				if( whiteRoll <= whiteObject.abilityChance )
				{
					statusSetter( target, "Regen" );
				

				}
				else cout << "\t" << whiteObject.abilityName << " misses!\n";
				magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
				endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
				j += 2;
			} //end for loop
		}
	}// end regen


	else if( actor.ctrInput == 9 )//protect
	{
		whiteObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Protect";
		whiteObject.abilityCTRCount = 4;

		whiteObject.display = " -- add Protect to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 200;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
						if( whiteObject.abilityChance > 100 )
							whiteObject.abilityChance = 100;
					}

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << whiteRoll << "\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						statusSetter( target, "Protect" );
						
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end protect loop


	else if( actor.ctrInput == 10 )// protect 2
	{
		whiteObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Protect 2";
		whiteObject.abilityCTRCount = 7;

		whiteObject.display = " -- add Protect to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 120;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
						if( whiteObject.abilityChance > 100 )
							whiteObject.abilityChance = 100;
					}

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << whiteRoll << "\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						statusSetter( target, "Protect" );
						
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end protect 2 loop


	else if( actor.ctrInput == 11 )// shell
	{
		whiteObject.mp = 6;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Shell";
		whiteObject.abilityCTRCount = 4;

		whiteObject.display = " -- add Shell to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 200;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
						if( whiteObject.abilityChance > 100 )
							whiteObject.abilityChance = 100;
					}

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << whiteRoll << "\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						statusSetter( target, "Shell" );
						
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end shell loop


	else if( actor.ctrInput == 12 )// shell 2
	{
		whiteObject.mp = 20;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Shell 2";
		whiteObject.abilityCTRCount = 7;

		whiteObject.display = " -- add Shell to target and 4 surrounding squares -- ";
		whiteObject.evade = false;
		whiteObject.component = 120;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false || target.petrify == true || target.dead == true )
				{
					if( target.nullPlayer == true || target.dead == true || target.petrify == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
						if( whiteObject.abilityChance > 100 )
							whiteObject.abilityChance = 100;
					}

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << whiteRoll << "\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						statusSetter( target, "Shell" );
						
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end shell 2 loop


	else if( actor.ctrInput == 13 )// wall
	{
		whiteObject.mp = 24;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Wall";
		whiteObject.abilityCTRCount = 7;

		whiteObject.display = " -- add Protect & Shell to target -- ";
		whiteObject.evade = false;
		whiteObject.component = 140;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
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
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
						if( whiteObject.abilityChance > 100 )
							whiteObject.abilityChance = 100;
					}

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << whiteRoll << "\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						statusSetter( target, "Shell" );
						statusSetter( target, "Protect" );
						
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end wall loop


	else if( actor.ctrInput == 14 )// esuna
	{
		whiteObject.mp = 18;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Esuna";
		whiteObject.abilityCTRCount = 3;

		whiteObject.display = " -- cure Petrify/Darkness/Confusion/Silence/Berserk/Frog/Poison/Sleep/Don't Move/Don't Act -- ";
		whiteObject.evade = false;
		whiteObject.component = 190;
		whiteObject.abilityChance = 0;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 3;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 2;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
				refVec = reflectVector( effectVector[j], effectVector[j+1], actor,
					player1, player2, player3, player4, player5, player6, player7,
					player8, player9, player10, nullPlayer, myArray, true );
				effectVector[j] = refVec[0];
				effectVector[j+1] = refVec[1];
				target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
				if( target.nullPlayer == false )
				{
					if( target.nullPlayer == true || target.dead == true )
					{
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = mod6White( actor, target, actor.ma, whiteObject.component );
						if( whiteObject.abilityChance > 100 )
							whiteObject.abilityChance = 100;
					}

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";
					cout << "\tRandom Number is... " << whiteRoll << "\n";

					if( whiteRoll <= whiteObject.abilityChance )
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
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is cured!\n";
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end esuna


	else if( actor.ctrInput == 15 )// Holy
	{
		whiteObject.mp = 56;
		if( actor.halfOfMP == true )
		{
			whiteObject.mp = whiteObject.mp / 2 + whiteObject.mp % 2;
		}
		whiteObject.abilityName = "Holy";
		whiteObject.abilityCTRCount = 6;
		whiteObject.display = " -- Holy damage to target -- ";
		whiteObject.evade = false;
		whiteObject.component = 50;
		whiteObject.abilityChance = 100;
		whiteObject.mod = 6;
		whiteObject.rangeMax = 5;
		whiteObject.rangeMin = 0;
		whiteObject.casterImmune = false;
		whiteObject.effect = 1;
		
		if( actor.silence == true )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but is Silenced!\n";
		}
		else if( actor.mp < whiteObject.mp )
		{
			cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " tries to cast " << whiteObject.abilityName << " but does not have enough MP!\n";
		}

		else //spell is cast!
		{
			actor.mp -= whiteObject.mp;

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
				effectVector = multiRange( actor, whiteObject.effect, whiteObject.abilityName, whiteObject.rangeMax,
					whiteObject.rangeMin, false, whiteObject.casterImmune, targetVector[0], targetVector[1] );
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
						whiteObject.abilityChance = 0;	
					}
					else
					{
						whiteObject.abilityChance = 100;
					}

					whiteObject.abilityDamage = -mod5Magic( actor, target, actor.ma, whiteObject.component, false, false,
						false, false, true, false, false, false );

					whiteRoll = rand() % 100 + 1;

					cout << whiteObject.abilityName <<" targets " << target.teamName << " " << target.playerClassName
								<< " " << target.playerName << ". " << whiteObject.abilityChance << "% chance to hit...\n";

					if( whiteRoll <= whiteObject.abilityChance )
					{
						hpDamage( target, actor, blueItem, redItem, whiteObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
					}
					else cout << "\t" << whiteObject.abilityName << " misses!\n";
					magicTypeReaction( whiteObject.mp, target, actor, player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem, true,
							whiteObject.mod, whiteObject.mp, whiteObject.effect, whiteObject.component, whiteObject.abilityName,
							whiteObject.evade, false, "", whiteObject.reflect, false, false, false, false, false,
							false, true, false );
					endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
				}
				j += 2;
			} //end for loop
		}
	}// end Holy loop

	if( mimeSilenceCheck == false && actorMPBefore != actor.mp )
	{
		vector<int> mimeVector (2, 0);
		mimeObject.mimeSpellConfirm = 1;
		mimeVector = mimeTargetFunction( targetVector[0], targetVector[1], actor );
		mimeObject.spellSide = mimeVector[0];
		mimeObject.spellDistance = mimeVector[1];
		mimeObject.abilityName = whiteObject.abilityName;
	}
}



class DrawOut
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

	//inventory
	int chirijiraden;
	int masamune;
	int kikuichimoji;
	int muramasa;
	int kiyomori;
	int heavensCloud;
	int murasame;
	int bizenBoat;
	int koutetsu;
	int asura;
	
	DrawOut()
	{
		//coding
		confirm = 2;
		abilityName = "";
		abilityType = "magical";
		display = "";
		mod = 5;
		evade = true;
		abilityDamage = 0;
		abilityChance = 100;
		rangeMin = 0;

		//inventory
		chirijiraden = 1;
		masamune = 1;
		kikuichimoji = 1;
		muramasa = 1;
		kiyomori = 1;
		heavensCloud = 1;
		murasame = 1;
		bizenBoat = 1;
		koutetsu = 1;
		asura = 1;

	}
	~DrawOut() {}

	void drawOutMenu( DrawOut &drawOutObject, Player actor );
	void drawOutSuccess( DrawOut &drawOutObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject
	);
};

void DrawOut::drawOutMenu( DrawOut &drawOutObject, Player actor )
{
	int drawOutAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " DRAW OUT Menu ---\n" 	
		<< "0.) Return to Menu\n"  
		<< "1.) Asura          -- damage to nearby enemies               -- " << drawOutObject.asura << " left\n"
		<< "2.) Koutetsu       -- damage to nearby enemies               -- " << drawOutObject.koutetsu << " left\n"
		<< "3.) Bizen Boat     -- MP damage to nearby enemies            -- " << drawOutObject.bizenBoat << " left\n"
		<< "4.) Murasame       -- restore HP to nearby allies            -- " << drawOutObject.murasame << " left\n" 
		<< "5.) Heaven's Cloud -- damage to nearby enemies, add Slow     -- " << drawOutObject.heavensCloud<< " left\n"
		<< "6.) Kiyomori       -- add Protect & Shell to nearby allies   -- " << drawOutObject.kiyomori << " left\n"
		<< "7.) Muramasa       -- damage to nearby enemies, add DS/Conf  -- " << drawOutObject.muramasa << " left\n" 
		<< "8.) Kikuichimoji   -- damage to enemies up to 8 squares away -- " << drawOutObject.kikuichimoji << " left\n"
		<< "9.) Masamune       -- add Regen & Haste to nearby allies     -- " << drawOutObject.masamune << " left\n" 
		//<< "10.) Chirijiraden  -- damage to nearby enemies               -- " << drawOutObject.chirijiraden << " left\n"
	) && 
	( !(cin >> drawOutAction ) || drawOutAction < 0 || drawOutAction > 10
	|| ( drawOutAction == 1 && drawOutObject.asura <= 0 )
	|| ( drawOutAction == 2 && drawOutObject.koutetsu <= 0 )
	|| ( drawOutAction == 3 && drawOutObject.bizenBoat <= 0 )
	|| ( drawOutAction == 4 && drawOutObject.murasame <= 0 )
	|| ( drawOutAction == 5 && drawOutObject.heavensCloud <= 0 )
	|| ( drawOutAction == 6 && drawOutObject.kiyomori <= 0 )
	|| ( drawOutAction == 7 && drawOutObject.muramasa <= 0 )
	|| ( drawOutAction == 8 && drawOutObject.kikuichimoji <= 0 )
	|| ( drawOutAction == 9 && drawOutObject.masamune <= 0 )
	|| ( drawOutAction == 10 && drawOutObject.chirijiraden <= 0 )
	) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	drawOutObject.playerInput = drawOutAction;
	if( drawOutAction == 0 )
	{
		drawOutObject.confirm = 0;
	}
	else drawOutObject.confirm = 2;
}

void drawOutInventory( DrawOut &drawOutObject )
{
	int drawOutRoll = 0;
	drawOutRoll = rand() % 100 + 1;

	if( drawOutRoll <= 15 )
	{
		if( drawOutObject.playerInput == 1 )
		{
			cout << "\tAsura breaks!\n";
			drawOutObject.asura--;
		}
		else if( drawOutObject.playerInput == 3 )
		{
			cout << "\tBizen Boat breaks!\n";
			drawOutObject.bizenBoat--;
		}
		else if( drawOutObject.playerInput == 4 )
		{
			cout << "\tMurasame breaks!\n";
			drawOutObject.murasame--;
		}
		else if( drawOutObject.playerInput == 5 )
		{
			cout << "\tHeaven's Cloud!\n";
			drawOutObject.heavensCloud--;
		}
		else if( drawOutObject.playerInput == 6 )
		{
			cout << "\tKiyomori breaks!\n";
			drawOutObject.kiyomori--;
		}
		else if( drawOutObject.playerInput == 8 )
		{
			cout << "\tKikuichimoji breaks!\n";
			drawOutObject.kikuichimoji--;
		}
		else if( drawOutObject.playerInput == 9 )
		{
			cout << "\tMasamune breaks!\n";
			drawOutObject.masamune--;
		}
		else if( drawOutObject.playerInput == 2 )
		{
			cout << "\tKoutetsu breaks!\n";
			drawOutObject.koutetsu--;
		}
		else if( drawOutObject.playerInput == 7 )
		{
			cout << "\tMuramasa breaks!\n";
			drawOutObject.muramasa--;
		}
		else if( drawOutObject.playerInput == 10 )
		{
			cout << "\tChirijiraden breaks!\n";
			drawOutObject.chirijiraden--;
		}

	}
}

void DrawOut::drawOutSuccess( DrawOut &drawOutObject, Player &actor, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11],
	Item &blueItem, Item &redItem, MimeClass &mimeObject )
{
	drawOutObject.abilityName = "";
	drawOutObject.display = "";
	drawOutObject.evade = false;
	drawOutObject.abilityDamage = 0;
	drawOutObject.abilityChance = 100;
	drawOutObject.mod = 5;
	drawOutObject.rangeMax = 1;
	drawOutObject.rangeMin = 1;

	Player target;
	vector<int> rangeVector (50, 0);
	int xaTemp = 0;
	int tempDamage = 0;
	int xaTemp2 = 0;
	int tempDamage2 = 0;
	int tempRoll = 0;
	int drawOutRoll = 0;
	int drawOutConfirm = 2;

	if( drawOutObject.confirm == 0) //loops back to menu
	{
		actor.confirm = 3;
	}

	else if( drawOutObject.confirm != 0 ) 
	{
		do
		{

			if( drawOutObject.playerInput == 1 ) //asura
			{
				drawOutObject.abilityName = "Asura";
				drawOutObject.display = "-- damage to enemies up to 2 squares away -- HP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 8 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );


				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 8 );
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
								player2, player3, player4, player5, player6, player7, player8, player9,
								player10  );

								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end asura loop

			else if( drawOutObject.playerInput == 2 )
			{
				drawOutObject.abilityName = "Koutetsu";
				drawOutObject.display = "-- damage to enemies up to 2 squares away -- HP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 12 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 12 );
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end koutetsu loop

			else if( drawOutObject.playerInput == 3 )
			{
				drawOutObject.abilityName = "Bizen Boat";
				drawOutObject.display = "-- MP damage to enemies up to 2 squares away -- MP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 4 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 4 );
								target.mp += drawOutObject.abilityDamage;
								cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
										<< " takes " << drawOutObject.abilityDamage << " MP damage!\n";	
								if( target.mp <= 0 )
								{
									target.mp = 0;
								}
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end bizen boat loop

			else if( drawOutObject.playerInput == 4 )
			{
				drawOutObject.abilityName = "Murasame";
				drawOutObject.display = "-- restore allies HP up to 2 squares away -- HP ";
				drawOutObject.mod = 0;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = 12 * actor.ma;
				if( target.undead == true )
					drawOutObject.abilityDamage *= -1;

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName == target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName != target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = 12 * actor.ma;
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10, true );

								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets allies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end murasame loop

			else if( drawOutObject.playerInput == 5 )
			{
				drawOutObject.abilityName = "Heaven's Cloud";
				drawOutObject.display = "-- damage to enemies up to 2 squares away, add Slow -- HP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 14 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 14 );
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

								if( target.dead == false )
								{
									cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
										<< " takes " << drawOutObject.abilityDamage << " damage!\n";
									drawOutRoll = rand() % 100 + 1;
									cout << "\t25% chance to add Slow... Random Number is..." << drawOutRoll << "\n"; 
									if( drawOutRoll <= 25 )
									{
										statusSetter( target, "Slow" );
									}
									else cout << "\tSlow misses!\n";
								}
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end Heaven's Cloud

			else if( drawOutObject.playerInput == 6 )
			{
				drawOutObject.abilityName = "Kiyomori";
				drawOutObject.display = "-- add Protect & Shell to allies within 2 squares";
				drawOutObject.mod = 0;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display, true );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName == target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName != target.teamName && actor.charm == true ) )
							{
								statusSetter( target, "Shell");
								statusSetter( target, "Protect");
								
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets allies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end Kiyomiri loop

			else if( drawOutObject.playerInput == 7 )
			{
				drawOutObject.abilityName = "Muramasa";
				drawOutObject.display = "-- dmg to enemies within 2 square, add Conf/DS -- HP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 18 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 18 );
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

								if( target.dead == false )
								{
									cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
										<< " takes " << drawOutObject.abilityDamage << " damage!\n";
									drawOutRoll = rand() % 100 + 1;
									cout << "\t25% chance to add Confusion or Death Sentence... Random Number is..." << drawOutRoll << "\n"; 
									if( drawOutRoll <= 25 )
									{
										drawOutRoll = rand() % 2;
										if( drawOutRoll == 1 )
										{
											statusSetter( target, "Confusion" );
										}
										else
										{
											statusSetter( target, "Death Sentence" );
										}
									}
									else cout << "\tmisses!\n";
								}
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end Muramasa

			else if( drawOutObject.playerInput == 8 )
			{
				drawOutObject.abilityName = "Kikuichimoji";
				drawOutObject.display = "-- damage to enemies up to 8 squares away -- HP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 8, drawOutObject.abilityName, 8, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 16 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 8; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 16 );
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end kikuichimoji loop

			else if( drawOutObject.playerInput == 9 )
			{
				drawOutObject.abilityName = "Masamune";
				drawOutObject.display = "-- add Regen & Haste to allies within 2 squares";
				drawOutObject.mod = 0;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display, true );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName == target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName != target.teamName && actor.charm == true ) )
							{
								statusSetter( target, "Haste");
								statusSetter( target, "Regen");
								
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets allies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end Masamune loop

			else if( drawOutObject.playerInput == 10 )
			{
				drawOutObject.abilityName = "Chirijiraden";
				drawOutObject.display = "-- damage to enemies up to 2 squares away -- HP ";
				drawOutObject.mod = 5;

				rangeVector = multiRange( actor, 3, drawOutObject.abilityName, 1, 1, true, true );
				drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 30 );

				drawOutConfirm = targetDisplay( target, drawOutObject.abilityName, drawOutObject.abilityChance,
					drawOutObject.abilityDamage, drawOutObject.display );

				if( drawOutConfirm == 1 )
				{
					int i = 0;
					int j = 0;
					for( i = 0; i < 12; i++)
					{
						target = targetFunction( rangeVector[j], rangeVector[j+1], player1, player2, player3,
							player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
						
						if( target.nullPlayer == false && target.dead == false && target.petrify == false )
						{
							if( ( actor.teamName != target.teamName && actor.charm == false ) //only target enemy players
							|| ( actor.teamName == target.teamName && actor.charm == true ) )
							{
								drawOutObject.abilityDamage = -mod5DrawOut( actor, target, actor.ma, 30 );
								hpDamage( target, actor, blueItem, redItem, drawOutObject.abilityDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );
								
								endTarget( target, player1, player2, player3, player4, player5, player6,
									player7, player8, player9, player10, nullPlayer );
							} //only targets enemies
						}//only targets alive players not null players
						j += 2;
					}//end for loop
					drawOutInventory( drawOutObject );
				} //end confirm loop
			}//end chirijiraden loop
			if( drawOutConfirm == 1)
			{
				mimeObject.mimeDrawConfirm = 1;
				mimeObject.abilityName = drawOutObject.abilityName;
				vector<int> mimeVector (2 , 0);
				mimeVector = mimeTargetFunction( actor.currentRow, actor.currentCol, actor);
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
			}
		}while( drawOutConfirm == 2);
	}
		
	if( drawOutConfirm == 3 )
	{
		actor.confirm = 3;
	}	
	
}



void mimeDrawDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	vector<int> targetVector (2, 0);
	int targetLoop = 1;
	int spellSetterDamage = 0;

	mimeObject.summonTypeAlly = false;
	mimeObject.summonTypeEnemy = false;

	vector<int> effectVector (50, 0);
	
	targetVector = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic "<< mimeObject.abilityName << " on (" << targetVector[0]-1 << ", " << targetVector[1]-1 << ") ...\n";

		if( mimeObject.abilityName == "Kikuichimoji" )
			mimeObject.effect = 8;
		else mimeObject.effect = 3;


		effectVector = multiRange( theMime, mimeObject.effect, mimeObject.abilityName, 8,
			1, true, true, targetVector[0], targetVector[1], true );
		targetLoop = loopTarget( mimeObject.effect, true );

		int i = 0;
		int j = 0;

		if( mimeObject.abilityName == "Kiyomori" || mimeObject.abilityName == "Masamune" 
			|| mimeObject.abilityName == "Murasame" )
		{
			mimeObject.summonTypeAlly = true;
		}
		else 
		{
			mimeObject.summonTypeEnemy = true;
		}

		for( i = 0; i < targetLoop; i++)
		{
			target = targetFunction( effectVector[j], effectVector[j+1], player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
			if( target.nullPlayer == false && target.dead == false && target.petrify == false )	
			{

				//beneficial draw outs
				if(  //keeps summons from targetting units they shouldn't
					( theMime.charm == false && mimeObject.summonTypeAlly == true && theMime.teamName == target.teamName )
					|| ( theMime.charm == true && mimeObject.summonTypeAlly == true && theMime.teamName != target.teamName )
					)
				{
					mimeObject.chance = 100;
					hitRoll = rand() % 100 + 1; //hit roll for add status

					cout << "   " << mimeObject.abilityName << " targets " << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< ". Chance to hit is " << mimeObject.chance << "%...\n";
					//cout << "\tRandom number is... " << hitRoll << "\n";

					if( mimeObject.abilityName == "Murasame" )
					{
						mimeObject.damage = mod5DrawOut( theMime, target, theMime.ma, 12 );
						hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1,
							player2, player3, player4, player5, player6, player7, player8,
							player9, player10, true );
					}
					else if( mimeObject.abilityName == "Kiyomori" )
					{
						statusSetter( target, "Protect" );
						statusSetter( target, "Shell" );
					}
					else if( mimeObject.abilityName == "Masamune" )
					{
						statusSetter( target, "Regen" );
						statusSetter( target, "Haste" );
					}
				}
				
				//harmful draw outs
				else if(  //keeps summons from targetting units they shouldn't
					( theMime.charm == false && mimeObject.summonTypeEnemy == true && theMime.teamName != target.teamName )
					|| ( theMime.charm == true && mimeObject.summonTypeEnemy == true && theMime.teamName == target.teamName )
					)
				{
					mimeObject.chance = 100;
					hitRoll = rand() % 100 + 1; //hit roll for add status

					cout << "   " << mimeObject.abilityName << " targets " << target.teamName << " " << target.playerClassName << " " << target.playerName
						<< ". Chance to hit is " << mimeObject.chance << "%...\n";
					//cout << "\tRandom number is... " << hitRoll << "\n";
			
					if( hitRoll <= mimeObject.chance )
					{
						//cout << "\t" << mimeObject.abilityName << " hits!\n";
						
						if( mimeObject.abilityName == "Asura" )
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 8 );
						}
						else if( mimeObject.abilityName == "Koutetsu" )
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 12 );
						}
						else if( mimeObject.abilityName == "Bizen Boat")
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 4 );
							mpDamage( target, mimeObject.damage );
						}
						else if( mimeObject.abilityName == "Heaven's Cloud" )
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 14 );
							if( hitRoll <= 25 )
								statusSetter( target, "Slow" );
						}
						else if( mimeObject.abilityName == "Muramasa" )
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 18 );
							if( hitRoll <= 25 )
							{
								hitRoll = rand () % 2;
								if( hitRoll == 1 )
								{
									statusSetter( target, "Confusion" );
								}
								else
								{
									statusSetter( target, "Death Sentence" );
								}
							}
						}
						else if( mimeObject.abilityName == "Kikuichimoji" )
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 16 );
						}
						else if( mimeObject.abilityName == "Chirijiraden" )
						{
							mimeObject.damage = -mod5DrawOut( theMime, target, theMime.ma, 30 );
						}

						if( mimeObject.abilityName != "Bizen Boat" )
						{
							hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1,
								player2, player3, player4, player5, player6, player7, player8, player9,
								player10 );
						}
					}//hit roll loop
				} //ends targetting player loop for harmful summons
				endTarget( target, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10, nullPlayer );
			}//ends target player loop
			j += 2;
		} //ends for loop
}


//Squire skillset, need to add knockback
//can throw stone or dash work on empty squares?
//how much damage does throw stone and dash display
//can heal work on enemies?
class BasicSkill
{
public:
	string abilityName;
	string abilityType;
	string display;
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
	int basicSkillChance;
	int basicSkillDamage;
	int confirm;

	int side;
	int distance;
	int mimeConfirm;

	BasicSkill() 
	{
		abilityName = "";
		abilityType = "physical";
		reflect = false;
		calculate = false;
		elemental = "NULL";
		counterBladeGrasp = false;
		evade = false;
		magicPoints = 0;
		ctr = 0;
		jobPoints = 0;
		mod = 2;
		abilityRange = 4; 
		abilityRangeMin = 1; 
		abilityEffect = 1;
		basicSkillChance = 0;
		basicSkillDamage = 0;
		confirm = 0;
	}

	~BasicSkill() {}

	void basicSkillMenu( BasicSkill &basicSkillObject, Player actor );
	void basicSkillSuccess(  BasicSkill &basicSkillObject, Player &playerActor, char myArray[][11], 
	Item &blueItem, Item &redItem, Player &player1, Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10, Player &nullPlayer, MimeClass &mimeObject );

};

void BasicSkill::basicSkillMenu( BasicSkill &basicSkillObject, Player actor )
{
	int basicSkillAction = 0;
	while( (cout << "\n"
		<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " BASIC SKILL Menu ---\n" 	
		<< "0.) Return to Menu\n" 
		<< "1.) Accumulate  -- PA +1\n" 
		<< "2.) Throw Stone -- Ranged attack\n"
		<< "3.) Dash        -- Chance to knockback unit\n"
		<< "4.) Heal        -- Cure Poison/Silence/Darkness\n" 
		) && ( !(cin >> basicSkillAction) || basicSkillAction < 0 || basicSkillAction > 4 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	
	basicSkillObject.playerInput = basicSkillAction;
	
	if( basicSkillAction == 0 )
	{
		basicSkillObject.confirm = 0;
	}
	else basicSkillObject.confirm = 2;
}

void BasicSkill::basicSkillSuccess( BasicSkill &basicSkillObject, Player &actor, char myArray[][11], 
	Item &blueItem, Item &redItem, Player &player1, Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10, Player &nullPlayer, MimeClass &mimeObject )
{
	vector<int> rangeVector (2, 0);
	vector<int> mimeVector (2, 0);
	int basicSkillConfirm = 2;
	int hitRoll = 0;
	Player target;
	
	basicSkillObject.abilityName = "";
	basicSkillObject.basicSkillChance = 0;
	basicSkillObject.basicSkillDamage = 0;
	basicSkillObject.abilityRangeMin = 1;
	int mod2Temp = 0;

	mimeObject.mimeBasicConfirm = 0;


	if( basicSkillObject.confirm == 0 )
	{
		actor.confirm = 3;
	}
	else if( basicSkillObject.confirm != 0 )
	{
		do
		{
			if( basicSkillObject.playerInput == 1) //acumulate selection
			{
				basicSkillObject.abilityName = "Accumulate";
				basicSkillObject.display = "-- PA +1";
				basicSkillObject.basicSkillChance = 100;

				basicSkillConfirm = targetDisplay( actor, basicSkillObject.abilityName,
					basicSkillObject.basicSkillChance, basicSkillObject.basicSkillDamage,
					basicSkillObject.display, true );
				
					if( basicSkillConfirm  == 1 )
					{
						actor.pa += 1;
						cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " Phy Attack +1! Phy Attack is now " << actor.pa << "!\n";
						rangeVector[0] = actor.currentRow;
						rangeVector[1] = actor.currentCol;
					}
			}//end accumulate selection

			else if( basicSkillObject.playerInput == 2) //throw stone selection
			{
				//mod 2
				basicSkillObject.abilityName = "Throw Stone";
				basicSkillObject.display = "-- HP ";
				basicSkillObject.abilityRange = 4;
				basicSkillObject.evade = true;
				basicSkillObject.basicSkillDamage = 0;
				basicSkillObject.abilityRangeMin = 1;

				rangeVector = rangeTest( actor, basicSkillObject.abilityRange, basicSkillObject.abilityName );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				basicSkillObject.basicSkillChance = evadeFunction( 100, actor, target );
				double tempDisplay = 0;
				mod2Temp = mod2xaDisplay( actor, target, actor.pa );
				tempDisplay = 1.5 * mod2Temp;
				basicSkillObject.basicSkillDamage = -tempDisplay;
				basicSkillConfirm = targetDisplay( target, basicSkillObject.abilityName,
					basicSkillObject.basicSkillChance, basicSkillObject.basicSkillDamage,
					basicSkillObject.display, false );

				

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					
					if( basicSkillConfirm  == 1 )
					{
						rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
							myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
							player10, nullPlayer, basicSkillObject.abilityName );
						target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

						cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}	
				}
				
				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					
					if( basicSkillConfirm == 1 )
					{
						rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
							myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
							player10, nullPlayer, basicSkillObject.abilityName );
						target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
							player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

						basicSkillObject.basicSkillChance = evadeFunction( 100, actor, target );
						hitRoll = rand () % 100 + 1;
						if( hitRoll <= basicSkillObject.basicSkillChance )
						{
							int throwStoneRandom = 0;
							throwStoneRandom = ( rand() % 2 ) + 1;
							mod2Temp = mod2xa( actor, target, actor.pa );
							basicSkillObject.basicSkillDamage = -throwStoneRandom * mod2Temp;
							knockback( actor, target, myArray );

							hpDamage( target, actor, blueItem, redItem, basicSkillObject.basicSkillDamage, player1,
								player2, player3, player4, player5, player6, player7, player8, player9,
								player10  );
						}
						else cout << "\t" << basicSkillObject.abilityName << " misses!\n";
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end throw stone selection

			else if( basicSkillObject.playerInput == 3) //dash selection
			{
				//mod 2
				basicSkillObject.abilityName = "Dash";
				basicSkillObject.display = "-- HP ";
				basicSkillObject.abilityRange = 1;
				basicSkillObject.evade = false;
				basicSkillObject.basicSkillDamage = 0;
				basicSkillObject.abilityRangeMin = 1;

				rangeVector = rangeTest( actor, basicSkillObject.abilityRange, basicSkillObject.abilityName );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					basicSkillObject.basicSkillChance = 0;
					double tempDisplay = 0;
					mod2Temp = mod2xaDisplay( actor, target, actor.pa );
					tempDisplay = 2.5 * mod2Temp;
					basicSkillObject.basicSkillDamage = -tempDisplay;

					basicSkillConfirm = targetDisplay( target, basicSkillObject.abilityName,
						basicSkillObject.basicSkillChance, basicSkillObject.basicSkillDamage,
						basicSkillObject.display, false );

					if( basicSkillConfirm  == 1 )
					{
						cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}

				else if( myArray[rangeVector[0]][rangeVector[1]] == myArray[target.currentRow][target.currentCol] )
				{
					basicSkillObject.basicSkillChance = 100;
					double tempDisplay = 0;
					mod2Temp = mod2xaDisplay( actor, target, actor.pa );
					tempDisplay = 2.5 * mod2Temp;
					basicSkillObject.basicSkillDamage = -tempDisplay;

					basicSkillConfirm = targetDisplay( target, basicSkillObject.abilityName,
						basicSkillObject.basicSkillChance, basicSkillObject.basicSkillDamage,
						basicSkillObject.display, false );

					if( basicSkillConfirm == 1 )
					{
						int dashRandom = 0;
						dashRandom = ( rand() % 4 ) + 1;
						mod2Temp = mod2xa( actor, target, actor.pa );
						basicSkillObject.basicSkillDamage = -dashRandom * mod2Temp;
						knockback( actor, target, myArray );
						
						hpDamage( target, actor, blueItem, redItem, basicSkillObject.basicSkillDamage, player1,
							player2, player3, player4, player5, player6, player7, player8, player9,
							player10  );

						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			} //end dash selection

			else if( basicSkillObject.playerInput == 4) //Heal selection
			{
				basicSkillObject.abilityName = "Heal";
				basicSkillObject.display = "-- cure Darkness/Silence/Poison";
				basicSkillObject.abilityRange = 1;
				basicSkillObject.abilityRangeMin = 1;
				basicSkillObject.basicSkillChance = 100;

				rangeVector = rangeTest( actor, basicSkillObject.abilityRange, basicSkillObject.abilityName,
					basicSkillObject.abilityRangeMin );
				target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3,
					player4, player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
			
				if( target.nullPlayer == true || target.petrify == true || target.dead == true )
				{
					basicSkillConfirm = targetDisplay( target, basicSkillObject.abilityName,
						basicSkillObject.basicSkillChance, basicSkillObject.basicSkillDamage,
						basicSkillObject.display, true );

					if( basicSkillConfirm  == 1 )
					{
						cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
							<< ") and no one is hit.\n";
					}
				}

				else if( myArray[rangeVector[0]][rangeVector[1]] == target.mapSymbol )
				{
					basicSkillObject.basicSkillChance = 100;

					basicSkillConfirm = targetDisplay( target, basicSkillObject.abilityName,
						basicSkillObject.basicSkillChance, basicSkillObject.basicSkillDamage,
						basicSkillObject.display, true );

					if( basicSkillConfirm == 1 )
					{
						target.darkness = false;
						target.poison = false;
						target.poisonTimer = 0;
						target.silence = false;
						cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
							<< " is no longer suffering from Darkness/Silence/Poison!\n";
						endTarget( target, player1, player2, player3, player4, player5, player6,
							player7, player8, player9, player10, nullPlayer );
					}
				}
			}//end Heal
			
			if( basicSkillConfirm == 1 )
			{
				mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor);
				basicSkillObject.mimeConfirm = 1;
				basicSkillObject.side = mimeVector[0];
				basicSkillObject.distance = mimeVector[1];

			}
			if( basicSkillConfirm == 1)
			{
				mimeObject.mimeBasicConfirm = 1;
				mimeObject.abilityName = basicSkillObject.abilityName;
				mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor);
				mimeObject.side = mimeVector[0];
				mimeObject.distance = mimeVector[1];
				mimeObject.playerInput = basicSkillObject.playerInput;
			}
		} while( basicSkillConfirm == 2);
	}//end if confirmation loop
	if( basicSkillConfirm == 3 )
	{
		actor.confirm = 3;
	}
}


void mimeBasicDamage( Player &theMime, Player &mimedUnit, MimeClass &mimeObject, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, char myArray[][11], Item &blueItem,
	Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	Player target;
	int hitRoll;
	int bsRoll;
	vector<int> targetVec (2, 0);
	
	targetVec = mimeTargetVector( theMime, mimeObject.side, mimeObject.distance );

	cout << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
		<< " attempts to Mimic " << mimeObject.abilityName << " on (" << targetVec[0]-1 << ", " << targetVec[1]-1 << ") ...\n";

	target = targetFunction( targetVec[0], targetVec[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

	if(mimeObject.playerInput == 1 )
	{
		theMime.pa += 1;
		cout << "\t" << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
			<< " Physical Attack +1! PA is now " << theMime.pa << "1\n";			
	}
	else if( mimeObject.playerInput == 4 )
	{
		if( target.nullPlayer == true || target.petrify == true || target.dead == true )
		{
			cout << "   " << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
				<< " targets (" << targetVec[0]-1 << ", " << targetVec[1]-1
				<< ") and no one is hit.\n";
		}
		else
		{
			target.darkness = false;
			target.poison = false;
			target.poisonTimer = 0;
			target.silence = false;
			cout << "   " << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " is no longer suffering from Darkness/Silence/Poison!\n";
			endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
		}
	}
	else
	{
		targetVec = rangeCollision( theMime.currentRow, theMime.currentCol, targetVec[0], targetVec[1],
			myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
			player10, nullPlayer, mimeObject.abilityName );
		target = targetFunction( targetVec[0], targetVec[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );

		if( target.dead == false && target.petrify == false && target.nullPlayer == false )
		{
			hitRoll = rand() % 100 + 1;

			if( mimeObject.playerInput == 2 )
			{
				mimeObject.chance = evadeFunction( 100, theMime, target );
				bsRoll = rand() % 2 + 1;
			}
			else 
			{
				mimeObject.chance = 100;
				bsRoll = rand() % 4 + 1;
			}

			cout << "   "<< mimeObject.abilityName << " chance to hit is " << mimeObject.chance << "%. Random number is..." << hitRoll << "\n";
			if( hitRoll <= mimeObject.chance )
			{
				mimeObject.damage = -mod2xa( theMime, target, theMime.pa );
				mimeObject.damage *= bsRoll;
				knockback( theMime, target, myArray );
				hpDamage( target, theMime, blueItem, redItem, mimeObject.damage, player1, player2,
					player3, player4, player5, player6, player7, player8, player9, player10 );
			}
			else cout << "   misses!\n";
			endTarget( target, player1, player2, player3, player4, player5, player6,
				player7, player8, player9, player10, nullPlayer );
		}
		else cout << "   and it has no effect.\n";
	}

}


