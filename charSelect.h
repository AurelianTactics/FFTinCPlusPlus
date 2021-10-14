//function to select sex, and zodiac, faith brave
void selectBraveFaith( Player & unit )
{
	int braveSelect = 0;
	int faithSelect = 0;
	while( ( cout << "   --- " << unit.teamName  << " " << unit.playerName
				<< " Select Brave ( 40 to 70 ) ---\n"
				<< "\n"
		) &&
		( !(cin >> braveSelect ) || braveSelect < 40 || braveSelect > 70 ) )
	{
		cout << "Invalid answer. Brave must be between 40 & 70.\n" <<"\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	unit.brave = braveSelect;

	while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerName
				<< " Select Faith ( 40 to 70 ) ---\n"
				<< "\n"
		) &&
		( !(cin >> faithSelect ) || faithSelect < 40 || faithSelect > 70 ) )
	{
		cout << "Invalid answer. Faith must be between 40 & 70.\n" <<"\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	unit.faith = faithSelect;

}

void selectSex(Player &actor )
{
	int sexConfirm = 2;
	int selectSex = 0;
	string tempSex = "";
	string tempZodiac = "";
	int tempZodiacInt = 0;
	string tempName = "";
	do
	{
		while(true)
		{
			cout << actor.teamName << " choose player name (2 - 5 letters): ";
			cin >> tempName;
			if (tempName.size() <= 5 && tempName.size() >= 2 ) break;
			cerr << "Name must be 2 - 5 letters.\n" << "\n";
		}
		cout << "\n";
		actor.playerName = tempName;
		while( ( cout << "   --- " << actor.teamName << " Player"
		<< " select Sex ---\n" << "\n" << "1.) Male\n2.) Female\n" ) && ( !(cin >> selectSex) ||
		selectSex < 1 || selectSex > 2 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( selectSex == 1 )
		{
			tempSex = "Male";
		}
		else if( selectSex == 2 )
		{
			tempSex = "Female";
		}
		int selectZodiac = 0;
		cout << "\n";
		while ( (cout << "   --- " << actor.teamName << " Player" << " select Zodiac ---\n"
		<< "\n"
		<< "1.) Capricorn\t2.) Aquarius\n"
		<< "3.) Pisces\t4.) Aries\n"
		<< "5.) Taurus\t6.) Gemini\n"
		<< "7.) Cancer\t8.) Leo\n"
		<< "9.) Virgo\t10.) Libra\n"
		<< "11.) Scorpio\t12.) Sagittarius\n")
		&& ( !(cin >> selectZodiac) || selectZodiac < 1 || selectZodiac > 12 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n" << '\n';
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( selectZodiac == 1 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Capricorn";
		}
		else if( selectZodiac == 2 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Aquarius";
		}
		else if( selectZodiac == 3 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Pisces";
		}
		else if( selectZodiac == 4 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Aries";
		}
		else if( selectZodiac == 5 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Taurus";
		}
		else if( selectZodiac == 6 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Gemini";
		}
		else if( selectZodiac == 7 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Cancer";
		}
		else if( selectZodiac == 8 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Leo";
		}
		else if( selectZodiac == 9 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Virgo";
		}
		else if( selectZodiac == 10 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Libra";
		}
		else if( selectZodiac == 11 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Scorpio";
		}
		else if( selectZodiac == 12 )
		{
			tempZodiacInt = selectZodiac;
			tempZodiac = "Sagittarius";
		}
		cout << "\n";

		selectBraveFaith( actor );
		while ( (cout
		<< "Name:  " << tempName	<< "   Sex: " << tempSex << "   Zodiac: " << tempZodiac << "\n"
		<< "Brave: " << actor.brave << "      Faith: " << actor.faith << "\n"
		<< "Confirm: 1.) Yes  2.) No\n" )
		&& ( !(cin >> sexConfirm ) || sexConfirm < 1 || sexConfirm > 2 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while(sexConfirm == 2);
	
	actor.sex = tempSex;
	actor.zodiac = tempZodiac; 
	actor.zodiacInt = tempZodiacInt;
	actor.playerName = tempName;

	
	

}

void selectLevel( Player &actor )
{
	long int myLevel = 0;
	long int denom = 1638400;
	long int rawSpeed = 98304;
	long int rawPA;
	long int rawMA;
	long int rawLife;
	long int rawMP;
	long int tempLife;
	long int tempMP;
	long int tempPA;
	long int tempMA;
	long int tempSpeed;
	int levelConfirm = 2;

	cout << "\n";
	while ( (cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
		<< " select Level (2 to 99):  " ) && ( !( cin >> myLevel ) ||
		myLevel < 2 || myLevel > 99 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if(actor.sex == "Male")
	{
		rawPA = 81920;
		rawMA = 65536;
		rawLife = 524287;
		rawMP = 245759;
	}
	else if(actor.sex == "Female")
	{
		rawPA = 65536; 
		rawMA = 81920;
		rawLife = 491519;
		rawMP = 262143;
	}
	rawSpeed += ( rawSpeed/(actor.speedC + 1) ) * (myLevel - 1);
	tempSpeed = rawSpeed * actor.speedM / denom;

	rawLife += ( rawLife/(actor.lifeC + 1) ) * (myLevel - 1);
	tempLife = rawLife * actor.lifeM / denom;

	rawMP += ( rawMP/(actor.mpC + 1) ) * (myLevel - 1);
	tempMP = rawMP * actor.mpM / denom;

	rawPA += ( rawPA/(actor.paC + 1) ) * (myLevel - 1);
	tempPA = rawPA * actor.paM / denom;

	rawMA += ( rawMA/(actor.maC + 1) ) * (myLevel - 1);
	tempMA = rawMA * actor.maM / denom;

	actor.maxLife = tempLife;
	actor.life = tempLife;
	actor.maxMP = tempMP;
	actor.mp = tempMP;
	actor.pa = tempPA;
	actor.ma = tempMA;
	actor.speed = tempSpeed;
	actor.level = myLevel;
}

//function to select class
void selectClass(Player &playerObject)
{
	int selectClass;
	int confirmClass;
	do
	{
		while ( (cout << "   --- " << playerObject.teamName << " " << playerObject.playerName
			<< " select Class ---\n"
			<< "\n"
			<< " 1.) Archer              "  << " 2.) Bard                "  << " 3.) Calculator \n"
			<< " 4.) Chemist             "  << " 5.) Dancer              "  << " 6.) Geomancer\n"
			<< " 7.) Knight              "  << " 8.) Lancer              "  << " 9.) Mediator\n"
			<< "10.) Mime                "  << "11.) Monk                "  << "12.) Ninja\n"
			<< "13.) Oracle              "  << "14.) Priest              "  << "15.) Samurai\n"
			<< "16.) Squire              "  << "17.) Summoner            "  << "18.) Thief\n"
			<< "19.) Time Mage           "  << "20.) Wizard\n"
			) 
			&& ( !(cin >> selectClass) || selectClass < 1 || selectClass > 20 || ( selectClass == 2 && playerObject.sex == "Female" )
			||  ( selectClass == 5 && playerObject.sex == "Male" ) ) )
		{
			cout << "Invalid answer. Enter a valid number. Dancers must be Female and Bards Male.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		playerObject.playerNumber = selectClass;

		if(selectClass == 1)
		{
			Archer archerCreator;
			archerCreator.archerStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 2)
		{
			Bard bard;
			bard.bardStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 3)
		{
			Calculator calculator;
			calculator.calculatorStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 4)
		{
			Chemist chemistCreator;
			chemistCreator.chemistStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 5)
		{
			Dancer dancer;
			dancer.dancerStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 6)
		{
			Geomancer geomancer;
			geomancer.geomancerStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 7)
		{
			Knight knightCreator;
			knightCreator.knightStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 8)
		{
			Lancer lancer;
			lancer.lancerStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 9)
		{
			Mediator mediator;
			mediator.mediatorStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 10)
		{
			Mime mime;
			mime.mimeStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 11)
		{
			Monk monk;
			monk.monkStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 12)
		{
			Ninja ninja;
			ninja.ninjaStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 13)
		{
			Oracle oracle;
			oracle.oracleStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 14)
		{
			Priest priest;
			priest.priestStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 15)
		{
			Samurai samurai;
			samurai.samuraiStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 16)
		{
			Squire squireCreator;
			squireCreator.squireStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if( selectClass == 17 )
		{
			Summoner summoner;
			summoner.summonerStats(playerObject);
			selectLevel(playerObject);
			
		}
		else if(selectClass == 18 )
		{
			Thief thiefCreator;
			thiefCreator.thiefStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 19 )
		{
			TimeMage timeMage;
			timeMage.TimeMageStats(playerObject);
			selectLevel(playerObject);
		}
		else if(selectClass == 20 )
		{
			Wizard wizard;
			wizard.wizardStats(playerObject);
			selectLevel(playerObject);
		}

		while ( (cout << "\n" << playerObject.teamName << " " << playerObject.playerName << " "
			<< playerObject.playerClassName << " Level: " << playerObject.level << "\n" << "\n"
			<< "Confirm: 1.) Yes 2.) No\n") && ( !( cin >> confirmClass ) ||
			confirmClass < 1 || confirmClass > 2 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while(confirmClass == 2);
	cout << "\n";
}

//player chooses abilities and stats are altered accordingly
void abilitySelect( Player &unit )
{
	int abilityConfirm = 40;
	int tempSecondary = 40;
	string tempSecondaryName = "";
	Reaction robj;
	Support sObj;
	Movement moveObject;

	if( unit.playerClass != 10 )
	{
		do
		{
			while( ( cout << "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
				<< " Select Secondary ---\n"
				<< "\n"
				<< " 0.) None                " << " 1.) CHARGE              " << " 2.) SING\n"
				<< " 3.) MATH SKILL          " << " 4.) ITEM                " << " 5.) DANCE\n"
				<< " 6.) ELEMENTAL           " << " 7.) BATTLE SKILL        " << " 8.) JUMP\n"
				<< " 9.) TALK SKILL          " << "10.) NONE                " << "11.) PUNCH ART\n"
				<< "12.) THROW               " << "13.) YIN YANG MAGIC      " << "14.) WHITE MAGIC\n"
				<< "15.) DRAW OUT            " << "16.) BASIC SKILL         " << "17.) SUMMON\n"
				<< "18.) STEAL               " << "19.) TIME MAGIC          " << "20.) BLACK MAGIC\n"
				) &&
				( !(cin >> tempSecondary) || tempSecondary < 0 || tempSecondary > 20  
				|| unit.playerClass == tempSecondary || ( tempSecondary == 2 && unit.sex == "Female" )
				|| ( tempSecondary == 5 && unit.sex == "Male" )
				) )
			{
				if( tempSecondary == unit.playerClass )
				{
					cout << "Invalid answer. Cannot select your class's ability set as a secondary.\n" <<"\n";
				}
				else if( tempSecondary == 5 && unit.sex == "Male" )
				{
					cout << "Invalid answer. Male units cannot use DANCE.\n" <<"\n";
				}
				else if( tempSecondary == 2 && unit.sex == "Female" )
				{
					cout << "Invalid answer. Female units cannot use SING.\n" <<"\n";
				}
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if( tempSecondary == 0 || tempSecondary == 0)
			{
				tempSecondaryName = "NONE";
			}
			else if( tempSecondary == 1)
			{
				tempSecondaryName = "CHARGE";
			}
			else if( tempSecondary == 2)
			{
				tempSecondaryName = "SING";
			}
			else if( tempSecondary == 3)
			{
				tempSecondaryName = "MATH SKILL";
			}
			else if( tempSecondary == 4)
			{
				tempSecondaryName = "ITEM";
			}
			else if( tempSecondary == 5)
			{
				tempSecondaryName = "DANCE";
			}
			else if( tempSecondary == 6)
			{
				tempSecondaryName = "ELEMENTAL";
			}
			else if( tempSecondary == 7)
			{
				tempSecondaryName = "BATTLE SKILL";
			}
			else if( tempSecondary == 8)
			{
				tempSecondaryName = "JUMP";
			}
			else if( tempSecondary == 9)
			{
				tempSecondaryName = "TALK SKILL";
			}
			else if( tempSecondary == 11) //skips 10 on purpose
			{
				tempSecondaryName = "PUNCH ART";
			}
			else if( tempSecondary == 12)
			{
				tempSecondaryName = "THROW";
			}
			else if( tempSecondary == 13)
			{
				tempSecondaryName = "YIN YANG MAGIC";
			}
			else if( tempSecondary == 14)
			{
				tempSecondaryName = "WHITE MAGIC";
			}
			else if( tempSecondary == 15)
			{
				tempSecondaryName = "DRAW OUT";
			}
			else if( tempSecondary == 16)
			{
				tempSecondaryName = "BASIC SKILL";
			}
			else if( tempSecondary == 17)
			{
				tempSecondaryName = "SUMMON";
			}
			else if( tempSecondary == 18)
			{
				tempSecondaryName = "STEAL";
			}
			else if( tempSecondary == 19)
			{
				tempSecondaryName = "TIME MAGIC";
			}
			else if( tempSecondary == 20)
			{
				tempSecondaryName = "BLACK MAGIC";
			}
			cout << "\n";
			robj.reactionSelect( robj, unit ); cout << "\n";
			sObj.supportSelect( sObj, unit ); cout << "\n";
			moveObject.movementSelect( moveObject, unit ); cout << "\n";

			while ( (cout << "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " ---\n"
				<< "\n"
				<< "Secondary Ability: " << tempSecondaryName.c_str() << '\n'
				<< "Reaction Ability:  " << robj.reactionName  << '\n'
				<< "Support Ability:   " << sObj.supportName << '\n'
				<< "Movement Ability:  " << moveObject.moveAbilityName << '\n'
				<< "\nConfirm: 1.) Yes 2.) No\n") &&
				( !(cin >> abilityConfirm) || abilityConfirm < 1 || abilityConfirm > 2 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(abilityConfirm == 1) //transfers ability stats to the player
			{
				//secondary transfer
				unit.secondary = tempSecondaryName;
				unit.secondaryNumber = tempSecondary;

				//reaction transfer
				unit.reaction = robj.reactionName;
				unit.abandon = robj.abandon;
				unit.absorbUsedMP = robj.absorbUsedMP;
				unit.arrowGuard = robj.arrowGuard;
				unit.aSave = robj.aSave;
				unit.autoPotion = robj.autoPotion;
				unit.bladeGrasp = robj.bladeGrasp;
				unit.braveUp = robj.braveUp;
				unit.caution = robj.caution;
				unit.counter = robj.counter;
				unit.counterFlood = robj.counterFlood;
				unit.counterMagic = robj.counterMagic;
				unit.counterTackle = robj.counterTackle;
				unit.criticalQuick = robj.criticalQuick;
				unit.damageSplit = robj.damageSplit;
				unit.distribute = robj.distribute;
				unit.dragonSpirit = robj.dragonSpirit;
				unit.faceUp = robj.faceUp;
				unit.fingerGuard = robj.fingerGuard;
				unit.gilgameHeart = robj.gilgameHeart;
				unit.hamedo = robj.hamedo;
				unit.hpRestore = robj.hpRestore;
				unit.maSave = robj.maSave;
				unit.meatboneSlash = robj.meatboneSlash;
				unit.mpRestore = robj.mpRestore;
				unit.mpSwitch = robj.mpSwitch;
				unit.reactionCatch = robj.reactionCatch;
				unit.reactionReflect = robj.reactionReflect;
				unit.regenerator = robj.regenerator;
				unit.speedSave = robj.speedSave;
				unit.sunkenState = robj.sunkenState;
				unit.weaponGuard = robj.weaponGuard;

				//support transfer
				unit.support = sObj.supportName;
				unit.attackUp = sObj.attackUp;
				unit.concentrate = sObj.concentrate;
					if(unit.playerClass == 10) //Mime exception
						unit.concentrate = true;
				unit.defend = sObj.defend;
				unit.defenseUp = sObj.defenseUp;
				unit.equipArmor = sObj.equipArmor;
				unit.equipAxe = sObj.equipAxe;
				unit.equipChange = sObj.equipChange;
				unit.equipCrossbow = sObj.equipCrossbow;
				unit.equipGun = sObj.equipGun;
				unit.equipKnife = sObj.equipKnife;
				unit.equipShield = sObj.equipShield;
				unit.equipSpear = sObj.equipSpear;
				unit.equipSword = sObj.equipSword;
				unit.halfOfMP = sObj.halfOfMP;
				unit.magicAttackUp = sObj.magicAttackUp;
				unit.magicDefendUp = sObj.magicDefendUp;
				unit.maintenance = sObj.maintenance;
				unit.martialArts = sObj.martialArts;
				if( unit.playerClass == 11 ) //monk exception
					unit.martialArts = true;
				unit.monsterSkill = sObj.monsterSkill;
				unit.monsterTalk = sObj.monsterTalk;
				if(unit.playerClass == 9 ) //mediator exception
					unit.monsterTalk = true; 
				unit.nonCharge = sObj.nonCharge;
				unit.secretHunt = sObj.secretHunt;
				unit.shortCharge = sObj.shortCharge;
				unit.throwItem = sObj.throwItem;
				unit.train = sObj.train;
				unit.twoHands = sObj.twoHands;
				unit.twoSwords = sObj.twoSwords;
				if( unit.playerClass == 12 ) // ninja exception
					unit.twoSwords = true;
				if( unit.twoSwords == true ) //two swords exception
					unit.offHandType = "Bare Hands";
		
				//movement transfer
				unit.movement = moveObject.moveAbilityName;
				unit.move += moveObject.move;
				unit.jump += moveObject.jump;
				unit.moveFloat = moveObject.floatStatus;
				unit.statusFloat = moveObject.floatStatus;
				unit.fly = moveObject.fly;
				unit.ignoreHeight = moveObject.ignoreHeight;
				unit.teleport = moveObject.teleport;
				unit.teleport2 = moveObject.teleport2;
				unit.moveHP = moveObject.moveHP;
				unit.moveMP	= moveObject.moveMP;
				unit.moveLava = moveObject.moveLava;
				unit.anyGround = moveObject.anyGround;
				unit.moveInWater = moveObject.moveInWater;
				unit.anyWeather = moveObject.anyWeather;
				unit.walkOnWater = moveObject.walkOnWater;
			}
		}while(abilityConfirm == 2);
	}
}


