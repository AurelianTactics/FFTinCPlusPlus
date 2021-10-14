int innerQuickStart(Player unit, int menuSelect )
{
	if( menuSelect == 2 && unit.turnOrder == 1 )
	{
		cout << "\n"
			<< "The Quick Start option reads character information from file and enters all    \n"
			<< "abilities and equipment into the character. The Quick Start code is read from \n"
			<< "the text file found in the directory of this game. Each team player has its own\n"
			<< "Quick Start file. For example the first Blue Player has a Quick Start file \n"
			<< "called \"blue1.txt\", the third Red Player \"red3.txt\", etc. Quick Start codes\n"
			<< "are automatically generated to the file everytime a character is created.\n"
			<< "Quick Start codes are also outputted to the player-stat.txt file along with the\n"
			<< "character description.\n"
			<< "\n"
			<< "In order for Quick Start to work, there must be valid Quick Start code in the \n"
			<< "Quick Start file.\n";
		
		while( ( cout << "\nCONFIRM Quick Start:\n"
		<< "1.) Return to Character Select\n2.) Confirm Quick Start\n" ) && ( !(cin >> menuSelect) ||
		menuSelect < 1 || menuSelect > 2 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	return menuSelect;
}

//for now QS player by player. Long term, make it team
	//also add player display before confirming it
int quickStartMenu( Player unit, string playerNumber )
{
	int menuSelect = 1;

	while( ( cout << "   --- " << unit.teamName << " Player select " << playerNumber
		<< " character or enter Quick Start code?\n"
		<< "\n"
		<< "1.) Select Character\n2.) Quick Start code\n" ) && ( !(cin >> menuSelect) ||
	menuSelect < 1 || menuSelect > 2 ) )
	{
		cout << "Invalid answer. Enter a valid number.\n" << "\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	menuSelect = innerQuickStart( unit, menuSelect );

	return menuSelect;
}

void quickStartSex( Player &unit, vector<string> unitVec )
{
	//sex
	if( unitVec[0] == "1" )
	{
		unit.sex = "Male";
	}
	else if( unitVec[0] == "2" )
	{
		unit.sex = "Female";
	}
}

void quickStartZodiac( Player &unit, vector<string> unitVec )
{
	if( unitVec[1] == "0" )
	{
		if( unitVec[2] == "1")
		{
			unit.zodiacInt = 1;
			unit.zodiac = "Capricorn";
		}
		else if( unitVec[2] == "2")
		{
			unit.zodiacInt = 2;
			unit.zodiac = "Aquarius";
		}
		else if( unitVec[2] == "3")
		{
			unit.zodiacInt = 3;
			unit.zodiac = "Pisces";
		}
		else if( unitVec[2] == "4")
		{
			unit.zodiacInt = 4;
			unit.zodiac = "Aries";
		}
		else if( unitVec[2] == "5")
		{
			unit.zodiacInt = 5;
			unit.zodiac = "Taurus";
		}
		else if( unitVec[2] == "6")
		{
			unit.zodiacInt = 6;
			unit.zodiac = "Gemini";
		}
		else if( unitVec[2] == "7")
		{
			unit.zodiacInt = 7;
			unit.zodiac = "Cancer";
		}
		else if( unitVec[2] == "8")
		{
			unit.zodiacInt = 8;
			unit.zodiac = "Leo";
		}
		else if( unitVec[2] == "9")
		{
			unit.zodiacInt = 9;
			unit.zodiac = "Vergo";
		}

	}
	else if( unitVec[1] == "1" )
	{
		if( unitVec[2] == "0")
		{
			unit.zodiacInt = 10;
			unit.zodiac = "Libra";
		}
		else if( unitVec[2] == "1")
		{
			unit.zodiacInt = 11;
			unit.zodiac = "Scorpio";
		}
		else if( unitVec[2] == "2")
		{
			unit.zodiacInt = 12;
			unit.zodiac = "Sagittarius";
		}
	}
}

void quickStartBrave( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[3];
	tempString += unitVec[4];

	tempInt = atoi(tempString.c_str());
	unit.brave = tempInt;
}

void quickStartFaith( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[5];
	tempString += unitVec[6];

	tempInt = atoi(tempString.c_str());
	unit.faith = tempInt;
}

void quickStartLevel( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[7];
	tempString += unitVec[8];

	tempInt = atoi(tempString.c_str());
	unit.level = tempInt;
}


void quickStartClass( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[9];
	tempString += unitVec[10];

	tempInt = atoi(tempString.c_str());
	unit.playerClass = tempInt;

	if( unit.playerClass == 1 )
		unit.playerClassName = "Archer";
	else if( unit.playerClass == 2 )
		unit.playerClassName = "Bard";
	else if( unit.playerClass == 3 )
		unit.playerClassName = "Calculator";
	else if( unit.playerClass == 4 )
		unit.playerClassName = "Chemist";
	else if( unit.playerClass == 5 )
		unit.playerClassName = "Dancer";
	else if( unit.playerClass == 6 )
		unit.playerClassName = "Geomancer";
	else if( unit.playerClass == 7 )
		unit.playerClassName = "Knight";
	else if( unit.playerClass == 8 )
		unit.playerClassName = "Lancer";
	else if( unit.playerClass == 9 )
		unit.playerClassName = "Mediator";
	else if( unit.playerClass == 10 )
		unit.playerClassName = "Mime";
	else if( unit.playerClass == 11 )
		unit.playerClassName = "Monk";
	else if( unit.playerClass == 12 )
		unit.playerClassName = "Ninja";
	else if( unit.playerClass == 13 )
		unit.playerClassName = "Oracle";
	else if( unit.playerClass == 14 )
		unit.playerClassName = "Priest";
	else if( unit.playerClass == 15 )
		unit.playerClassName = "Samurai";
	else if( unit.playerClass == 16 )
		unit.playerClassName = "Squire";
	else if( unit.playerClass == 17 )
		unit.playerClassName = "Summoner";
	else if( unit.playerClass == 18 )
		unit.playerClassName = "Thief";
	else if( unit.playerClass == 19 )
		unit.playerClassName = "Time Mage";
	else if( unit.playerClass == 20 )
		unit.playerClassName = "Wizard";
}

void quickStartSelectLevel( Player &actor )
{
	long int myLevel = actor.level;
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

void quickStartClassBuilder(Player &unit )
{
	int selectClass = unit.playerClass;

		if(selectClass == 1)
		{
			Archer archerCreator;
			archerCreator.archerStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 2)
		{
			Bard bard;
			bard.bardStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 3)
		{
			Calculator calculator;
			calculator.calculatorStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 4)
		{
			Chemist chemistCreator;
			chemistCreator.chemistStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 5)
		{
			Dancer dancer;
			dancer.dancerStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 6)
		{
			Geomancer geomancer;
			geomancer.geomancerStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 7)
		{
			Knight knightCreator;
			knightCreator.knightStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 8)
		{
			Lancer lancer;
			lancer.lancerStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 9)
		{
			Mediator mediator;
			mediator.mediatorStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 10)
		{
			Mime mime;
			mime.mimeStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 11)
		{
			Monk monk;
			monk.monkStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 12)
		{
			Ninja ninja;
			ninja.ninjaStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 13)
		{
			Oracle oracle;
			oracle.oracleStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 14)
		{
			Priest priest;
			priest.priestStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 15)
		{
			Samurai samurai;
			samurai.samuraiStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 16)
		{
			Squire squireCreator;
			squireCreator.squireStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if( selectClass == 17 )
		{
			Summoner summoner;
			summoner.summonerStats(unit);
			quickStartSelectLevel(unit);
			
		}
		else if(selectClass == 18 )
		{
			Thief thiefCreator;
			thiefCreator.thiefStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 19 )
		{
			TimeMage timeMage;
			timeMage.TimeMageStats(unit);
			quickStartSelectLevel(unit);
		}
		else if(selectClass == 20 )
		{
			Wizard wizard;
			wizard.wizardStats(unit);
			quickStartSelectLevel(unit);
		}

}

void quickStartSecondary( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[11];
	tempString += unitVec[12];

	tempInt = atoi(tempString.c_str());
	unit.secondaryNumber = tempInt;

	if( unit.secondaryNumber == 1 )
		unit.secondary = "CHARGE";
	else if( unit.secondaryNumber == 2 )
		unit.secondary = "SING";
	else if( unit.secondaryNumber == 3 )
		unit.secondary = "MATH SKILL";
	else if( unit.secondaryNumber == 4 )
		unit.secondary = "ITEM";
	else if( unit.secondaryNumber == 5 )
		unit.secondary = "DANCE";
	else if( unit.secondaryNumber == 6 )
		unit.secondary = "ELEMENTAL";
	else if( unit.secondaryNumber == 7 )
		unit.secondary = "BATTLE SKILL";
	else if( unit.secondaryNumber == 8 )
		unit.secondary = "JUMP";
	else if( unit.secondaryNumber == 9 )
		unit.secondary = "TALK SKILL";
	else if( unit.secondaryNumber == 10 )
		unit.secondary = "MIME";
	else if( unit.secondaryNumber == 11 )
		unit.secondary = "PUNCH ART";
	else if( unit.secondaryNumber == 12 )
		unit.secondary = "THROW";
	else if( unit.secondaryNumber == 13 )
		unit.secondary = "YIN YANG MAGIC";
	else if( unit.secondaryNumber == 14 )
		unit.secondary = "WHITE MAGIC";
	else if( unit.secondaryNumber == 15 )
		unit.secondary = "DRAW OUT";
	else if( unit.secondaryNumber == 16 )
		unit.secondary = "BASIC SKILL";
	else if( unit.secondaryNumber == 17 )
		unit.secondary = "SUMMON MAGIC";
	else if( unit.secondaryNumber == 18 )
		unit.secondary = "STEAL";
	else if( unit.secondaryNumber == 19 )
		unit.secondary = "TIME MAGIC";
	else if( unit.secondaryNumber == 20 )
		unit.secondary = "BLACK MAGIC";
}

void quickStartReactionSelect( Player &unit, int tempInt )
{
	unit.reaction = "NONE";
	unit.abandon = false;
	unit.weaponGuard = false;
	unit.aSave = false;
	unit.autoPotion = false;
	unit.caution = false;
	unit.damageSplit = false;
	unit.gilgameHeart = false;
	unit.maSave = false;
	unit.regenerator = false;
	unit.speedSave = false;
	unit.bladeGrasp = false;
	unit.braveUp = false;
	unit.counter = false;
	unit.counterTackle = false;
	unit.dragonSpirit = false;
	unit.sunkenState = false;
	unit.criticalQuick = false;
	unit.hpRestore = false;
	unit.meatboneSlash = false;
	unit.mpRestore = false;
	unit.absorbUsedMP = false;
	unit.arrowGuard = false;
	unit.reactionCatch = false;
	unit.counterFlood = false;
	unit.counterMagic = false;
	unit.distribute = false;
	unit.faceUp = false;
	unit.fingerGuard = false;
	unit.hamedo = false;
	unit.mpSwitch = false;
	unit.reactionReflect = false;

	int reactionSelect = tempInt;
	
	if( reactionSelect == 0)
	{
		unit.reaction = "NONE";
		unit.abandon = false;
		unit.weaponGuard = false;
		unit.aSave = false;
		unit.autoPotion = false;
		unit.caution = false;
		unit.damageSplit = false;
		unit.gilgameHeart = false;
		unit.maSave = false;
		unit.regenerator = false;
		unit.speedSave = false;
		unit.bladeGrasp = false;
		unit.braveUp = false;
		unit.counter = false;
		unit.counterTackle = false;
		unit.dragonSpirit = false;
		unit.sunkenState = false;
		unit.criticalQuick = false;
		unit.hpRestore = false;
		unit.meatboneSlash = false;
		unit.mpRestore = false;
		unit.absorbUsedMP = false;
		unit.arrowGuard = false;
		unit.reactionCatch = false;
		unit.counterFlood = false;
		unit.counterMagic = false;
		unit.distribute = false;
		unit.faceUp = false;
		unit.fingerGuard = false;
		unit.hamedo = false;
		unit.mpSwitch = false;
		unit.reactionReflect = false;
	}
	else if( reactionSelect == 1 )
	{
		unit.reaction = "A Save";
		unit.aSave = true;
	}
	else if( reactionSelect == 2 )
	{
		unit.reaction = "Abandon";
		unit.abandon = true;
	}
	else if( reactionSelect == 3 )
	{
		unit.reaction = "Absorb Used MP";
		unit.absorbUsedMP = true;
	}
	else if( reactionSelect == 4)
	{
		unit.reaction = "Arrow Guard";
		unit.arrowGuard = true;
	}
	else if( reactionSelect == 5 )
	{
		unit.reaction = "Auto Potion";
		unit.autoPotion = true;
	}
	else if( reactionSelect == 6 )
	{
		unit.reaction = "Blade Grasp";
		unit.bladeGrasp = true;
	}
	else if( reactionSelect == 7 )
	{
		unit.reaction = "Brave Up";
		unit.braveUp = true;
	}
	else if( reactionSelect == 8 )
	{
		unit.reaction = "Catch";
		unit.reactionCatch = true;
	}
	else if( reactionSelect == 9 )
	{
		unit.reaction = "Caution";
		unit.caution = true;
	}
	else if( reactionSelect == 10 )
	{
		unit.reaction = "Counter";
		unit.counter = true;
	}
	else if( reactionSelect == 11 )
	{
		unit.reaction = "Counter Flood";
		unit.counterFlood = true;
	}
	else if( reactionSelect == 12 )
	{
		unit.reaction = "Counter Magic";
		unit.counterMagic = true;
	}
	else if( reactionSelect == 13 )
	{
		unit.reaction = "Counter Tackle";
		unit.counterTackle = true;
	}
	else if( reactionSelect == 14 )
	{
		unit.reaction = "Critical Quick";
		unit.criticalQuick = true;
	}
	else if( reactionSelect == 15 )
	{
		unit.reaction = "Damage Split";
		unit.damageSplit = true;
	}
	else if( reactionSelect == 16 )
	{
		unit.reaction = "Distribute";
		unit.distribute = true;
	}
	else if( reactionSelect == 17 )
	{
		unit.reaction = "Dragon Spirit";
		unit.dragonSpirit = true;
	}
	else if( reactionSelect == 18 )
	{
		unit.reaction = "Face Up";
		unit.faceUp = true;
	}
	else if( reactionSelect == 19 )
	{
		unit.reaction = "Finger Guard";
		unit.fingerGuard = true;
	}
	else if( reactionSelect == 20 )
	{
		unit.reaction = "Hamedo";
		unit.hamedo = true;
	}
	else if( reactionSelect == 21 )
	{
		unit.reaction = "HP Restore";
		unit.hpRestore = true;
	}
	else if( reactionSelect == 22 )
	{
		unit.reaction = "MA Save";
		unit.maSave = true;
	}
	else if( reactionSelect == 23 )
	{
		unit.reaction = "Meatbone Slash";
		unit.meatboneSlash = true;
	}
	else if( reactionSelect == 24 )
	{
		unit.reaction = "MP Restore";
		unit.mpRestore = true;
	}
	else if( reactionSelect == 25 )
	{
		unit.reaction = "MP Switch";
		unit.mpSwitch = true;
	}
	else if( reactionSelect == 26 )
	{
		unit.reaction = "Regenerator";
		unit.regenerator = true;
	}
	else if( reactionSelect == 27 )
	{
		unit.reaction = "Speed Save";
		unit.speedSave = true;
	}
	else if( reactionSelect == 28 )
	{
		unit.reaction = "Sunken State";
		unit.sunkenState = true;
	}
	else if( reactionSelect == 29)
	{
		unit.reaction = "Weapon Guard";
		unit.weaponGuard = true;
	}
}

void quickStartReaction( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[13];
	tempString += unitVec[14];

	tempInt = atoi(tempString.c_str());

	quickStartReactionSelect( unit, tempInt );
}

void quickStartSupportSelect( Player &unit, int tempInt )
{
	unit.support = "NONE";
	unit.attackUp = false;
	unit.concentrate = false;
	unit.defend = false;
	unit.defenseUp = false;
	unit.equipArmor = false;
	unit.equipAxe = false;
	unit.equipChange = false;
	unit.equipCrossbow = false;
	unit.equipGun = false;
	unit.equipKnife = false;
	unit.equipShield = false;
	unit.equipSpear = false;
	unit.equipSword = false;
	unit.halfOfMP = false;
	unit.magicAttackUp = false;
	unit.magicDefendUp = false;
	unit.maintenance = false;
	unit.martialArts = false;
	unit.monsterSkill = false;
	unit.monsterTalk = false;
	unit.nonCharge = false;
	unit.secretHunt = false;
	unit.shortCharge = false;
	unit.throwItem = false;
	unit.train = false;
	unit.twoHands = false;
	unit.twoSwords = false;

	int supportSelect = tempInt;
	
	if( supportSelect == 0)
	{
		unit.support = "NONE";
		unit.attackUp = false;
		unit.concentrate = false;
		unit.defend = false;
		unit.defenseUp = false;
		unit.equipArmor = false;
		unit.equipAxe = false;
		unit.equipChange = false;
		unit.equipCrossbow = false;
		unit.equipGun = false;
		unit.equipKnife = false;
		unit.equipShield = false;
		unit.equipSpear = false;
		unit.equipSword = false;
		unit.halfOfMP = false;
		unit.magicAttackUp = false;
		unit.magicDefendUp = false;
		unit.maintenance = false;
		unit.martialArts = false;
		unit.monsterSkill = false;
		unit.monsterTalk = false;
		unit.nonCharge = false;
		unit.secretHunt = false;
		unit.shortCharge = false;
		unit.throwItem = false;
		unit.train = false;
		unit.twoHands = false;
		unit.twoSwords = false;
	}
	else if( supportSelect == 1)
	{
		unit.support = "Attack UP";
		unit.attackUp = true;
	}
	else if( supportSelect == 2)
	{
		unit.support = "Concentrate";
		unit.concentrate = true;
	}
	else if( supportSelect == 3)
	{
		unit.support = "Defend";
		unit.defend = true;
	}
	else if( supportSelect == 4)
	{
		unit.support = "Defense UP";
		unit.defenseUp = true;
	}
	else if( supportSelect == 5)
	{
		unit.support = "Equip Armor";
		unit.equipArmor = true;
		unit.armor = true;
	}
	else if( supportSelect == 6)
	{
		unit.support = "Equip Axe";
		unit.equipAxe = true;
		unit.axe = true;
	}
	else if( supportSelect == 7)
	{
		unit.support = "Equip Crossbow";
		unit.equipCrossbow = true;
		unit.crossbow = true;
	}
	else if( supportSelect == 8)
	{
		unit.support = "Equip Gun";
		unit.equipGun = true;
		unit.gun = true;
	}
	else if( supportSelect == 9)
	{
		unit.support = "Equip Knife";
		unit.equipKnife = true;
		unit.katana = true;
	}
	else if( supportSelect == 10)
	{
		unit.support = "Equip Shield";
		unit.equipShield = true;
		unit.shield = true;
	}
	else if( supportSelect == 11)
	{
		unit.support = "Equip Spear";
		unit.equipSpear = true;
		unit.spear = true;
	}
	else if( supportSelect == 12)
	{
		unit.support = "Equip Sword";
		unit.equipSword = true;
		unit.sword = true;
	}
	else if( supportSelect == 13)
	{
		unit.support = "Half of MP";
		unit.halfOfMP = true;
	}
	else if( supportSelect == 14)
	{
		unit.support = "Magic AttackUP";
		unit.magicAttackUp = true;
	}
	else if( supportSelect == 15)
	{
		unit.support = "Maintenance";
		unit.maintenance = true;
	}
	else if( supportSelect == 16)
	{
		unit.support = "Martial Arts";
		unit.martialArts = true;
	}
	else if( supportSelect == 17)
	{
		unit.support = "Monster Skill";
		unit.monsterSkill = true;
	}
	else if( supportSelect == 18)
	{
		unit.support = "Monster Talk";
		unit.monsterTalk = true;
	}
	else if( supportSelect == 19)
	{
		unit.support = "Short Charge";
		unit.shortCharge = true;
	}
	else if( supportSelect == 20)
	{
		unit.support = "Throw Item";
		unit.throwItem = true;
	}
	else if( supportSelect == 21 )
	{
		unit.support = "Train";
		unit.train = true;
	}
	else if( supportSelect == 22)
	{
		unit.support = "Two Hands";
		unit.twoHands = true;
	}
	else if( supportSelect == 23 )
	{
		unit.support = "Two Swords";
		unit.twoSwords = true;
		unit.offHandType = "Bare Hands";
	}
	else if( supportSelect == 24 )
	{
		unit.support = "Magic DefendUP";
		unit.magicDefendUp = true;
	}
	else if( supportSelect == 25 )
	{
		unit.support = "Equip Change";
		unit.equipChange = true;
	}
	if( unit.playerClass == 11 )
		unit.martialArts = true;
	if( unit.playerClass == 1 )
		unit.twoSwords = true;
	if( unit.offHand = true )
		unit.offHandType = "Bare Hands";
	if( unit.playerClass == 9 )
		unit.monsterTalk = true;
	if( unit.playerClass == 10 )
		unit.concentrate = true;
	
}

void quickStartSupport( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[15];
	tempString += unitVec[16];

	tempInt = atoi(tempString.c_str());

	quickStartSupportSelect( unit, tempInt );
}

void quickStartMovementSelect( Player &unit, int tempInt )
{
	int moveSelect = tempInt;
	int tempMove = 0;
	int tempJump = 0;

	unit.movement = "NONE";
	unit.statusFloat = false;
	unit.fly = false;
	unit.ignoreHeight = false;
	unit.teleport = false;
	unit.teleport2 = false;
	unit.moveHP = false;
	unit.moveMP = false;
	unit.moveLava = false;
	unit.anyGround = false;
	unit.moveInWater = false;
	unit.anyWeather = false;
	unit.walkOnWater = false;

	
		if( moveSelect == 0 ) //none
		{
			unit.movement = "NONE";
			tempMove = 0;
			tempJump = 0;
			unit.statusFloat = false;
			unit.fly = false;
			unit.ignoreHeight = false;
			unit.teleport = false;
			unit.teleport2 = false;
			unit.moveHP = false;
			unit.moveMP = false;
			unit.moveLava = false;
			unit.anyGround = false;
			unit.moveInWater = false;
			unit.anyWeather = false;
			unit.walkOnWater = false;
		}
		else if( moveSelect == 1 ) //Move +1
		{
			unit.movement = "Any Ground";
			unit.anyGround = true;
		}
		else if( moveSelect == 2 ) 
		{
			unit.movement = "Any Weather";
			unit.anyWeather = true;
		}
		else if( moveSelect == 3 ) //none
		{
			unit.movement = "Float";
			unit.statusFloat = true;
		}
		else if( moveSelect == 4 ) //none
		{
			unit.movement = "Fly";
			unit.fly = true;
		}
		else if( moveSelect == 5 ) //none
		{
			unit.movement = "Ignore Height";
			unit.ignoreHeight = true;
		}
		else if( moveSelect == 6 ) //none
		{
			unit.movement = "Jump +1";
			tempJump = 1;
		}
		else if( moveSelect == 7 ) //none
		{
			unit.movement = "Jump +2";
			tempJump = 2;
		}
		else if( moveSelect == 8 ) //none
		{
			unit.movement = "Jump +3";
			tempJump = 3;
		}
		else if( moveSelect == 9 ) //none
		{
			unit.movement = "Move +1";
			tempMove = 1;
		}
		else if( moveSelect == 10 ) //none
		{
			unit.movement = "Move +2";
			tempMove = 2;
		}
		else if( moveSelect == 11 ) //none
		{
			unit.movement = "Move +3";
			tempMove = 3;
		}
		else if( moveSelect == 12 ) //none
		{
			unit.movement = "Move-HP Up";
			unit.moveHP = true;
		}
		else if( moveSelect == 13 ) //none
		{
			unit.movement = "Move-MP Up";
			unit.moveMP = true;
		}
		else if( moveSelect == 14 ) //none
		{
			unit.movement = "Move on Lava";
			unit.moveLava = true;
		}
		else if( moveSelect == 15 ) //none
		{
			unit.movement = "Move in Water";
			unit.moveInWater = true;
		}
		else if( moveSelect == 16 ) //none
		{
			unit.movement = "Teleport";
			unit.teleport = true;
		}
		else if( moveSelect == 17 ) //none
		{
			unit.movement = "Walk on Water";
			unit.walkOnWater = true;
		}
		else if( moveSelect == 18 ) //none
		{
			unit.movement = "Teleport 2";
			tempMove = 50;
			unit.fly = true;
		}
		unit.move += tempMove;
		unit.jump += tempJump;
}

void quickStartMovement( Player &unit, vector<string> unitVec )
{
	string tempString = "";
	int tempInt = 0;

	tempString = unitVec[17];
	tempString += unitVec[18];

	tempInt = atoi(tempString.c_str());

	quickStartMovementSelect( unit, tempInt );
}

void quickStartWeaponSelect( Player &unit, int tempInt, int secInt )
{
	

	int equipAction = tempInt;
	int equipWeapon = secInt;
	//weapon slot
		unit.weapon = false;
		unit.weaponEffectBool= false;
		unit.weaponName= "";
		unit.weaponType= "";
		unit.weaponEffect= "";
		unit.weaponRange= 1;
		unit.weaponRangeMin= 1;
		unit.weaponPower= 0;
		unit.weaponEvade= 0;
		unit.weaponMA= 0;
		unit.weaponPA= 0;
		unit.weaponSpeed= 0;
		//unit.weapon add status 25%
		unit.weaponStatusEffect= false; //indicator for attack function
		unit.weaponDarkness= false;
		unit.weaponSilence= false;
		unit.weaponDeathSentence= false;
		unit.weaponSleep= false;
		unit.weaponDontAct= false;
		unit.weaponDontMove= false;
		unit.weaponFrog= false;
		unit.weaponPetrify= false;
		unit.weaponSlow= false;
		unit.weaponFaith= false;
		unit.weaponPoison= false;
		unit.weaponConfusion= false;
		unit.weaponCharm= false;
		unit.weaponInnocent= false;
		unit.weaponCancelDarkness= false;
		unit.weaponCancelSilence= false;
		unit.weaponCancelOil= false;
		unit.weaponCancelFrog= false;
		unit.weaponCancelPoison= false;
		unit.weaponCancelStop= false;
		unit.weaponCancelSlow= false;
		unit.weaponCancelDontMove= false;
		unit.weaponCancelDontAct= false;
		unit.weaponCancelDeathSentence= false;
		//unit.weapon elemental
		unit.weaponWind= false;
		unit.weaponIce= false;
		unit.weaponLightning= false;
		unit.weaponHolyUp= false;
		unit.weaponFire= false;
		unit.weaponHoly= false;
		unit.weaponIceUp = false;
		unit.weaponFireUp = false;
		unit.weaponLightningUp = false;
		//special unit.weapon effects
		unit.weaponCastSpell = false;
		unit.weaponLifeDrain= false; //damage converted to HP
		unit.weaponHeal= false; //heals target on damage
		unit.weaponIce2= false; //casts ice 2
		unit.weaponBolt1= false;
		unit.weaponFire1= false;
		unit.weaponIce1= false;
		unit.weaponFire2= false;
		unit.weaponHolyCast= false;
		unit.weaponMateriaBlade = false; //cloud subset
		unit.weaponHolyAbsorb = false;
		//unit.weapon add status to user
		unit.weaponAutoProtect= false;
		unit.weaponAutoHaste= false;
		unit.weaponAutoShell= false;
		unit.weaponAutoRegen= false;
		unit.weaponAutoFaith= false;
		unit.weaponStartPetrify= false; //start Petrified

	if( equipAction == 0 )
	{
		unit.weaponName = "NONE";
		unit.weaponEffect = "NULL";
		unit.weaponType = "Bare Hands";
		unit.weaponRange = 1;
		unit.weaponPower = 0;
		unit.weaponEvade = 0;
		unit.weapon = false;
		unit.weaponEffectBool = false;
	}
	else if( equipAction == 1 )
	{
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		if( equipWeapon == 1 )
		{
			unit.weaponName = "Battle Axe";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Axe";
			unit.weaponRange = 1;
			unit.weaponPower = 9;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		if( equipWeapon == 2 )
		{
			unit.weaponName = "Giant Axe";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Axe";
			unit.weaponRange = 1;
			unit.weaponPower = 12;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		if( equipWeapon == 3 )
		{
			unit.weaponName = "Slasher";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Axe";
			unit.weaponRange = 1;
			unit.weaponPower = 16;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = true;
			unit.weaponSlow = true;
		}
	}
	else if( equipAction == 2 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "C Bag";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bag";
			unit.weaponRange = 1;
			unit.weaponPower = 10;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponMA = 1;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "FS Bag";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bag";
			unit.weaponRange = 1;
			unit.weaponPower = 20;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "P Bag";
			unit.weaponEffect = "Auto Regen";
			unit.weaponType = "Bag";
			unit.weaponRange = 1;
			unit.weaponPower = 12;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponAutoRegen = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "H Bag";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bag";
			unit.weaponRange = 1;
			unit.weaponPower = 14;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponSpeed = 1;
		}
	}
	else if( equipAction == 3 )
	{
		
		if( equipWeapon == 0)
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1)
		{	
			unit.weaponName = "Long Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 4;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			unit.weaponName = "Silver Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 5;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.weaponName = "Ice Bow";
			unit.weaponEffect = "Ice";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 5;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponIce;
		}
		else if( equipWeapon == 4)
		{	
			unit.weaponName = "Lightning Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 6;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponLightning = true;
			unit.weaponBolt1 = true;
		}
		else if( equipWeapon == 5 )
		{	
			unit.weaponName = "Windslash Bow";
			unit.weaponEffect = "Wind";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 8;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponWind = true;
		}
		else if( equipWeapon == 6)
		{	
			unit.weaponName = "Mythril Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 7;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 7)
		{	
			unit.weaponName = "Ultimus Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 10;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{	
			unit.weaponName = "Yoichi Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 12;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 9 )
		{	
			unit.weaponName = "Perseus Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bow";
			unit.weaponRange = 5;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 16;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 4 )
	{
		
		if( equipWeapon == 0)
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			unit.weaponName = "Bow Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Crossbow";
			unit.weaponRange = 4;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 3;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		
		}
		else if( equipWeapon == 2)
		{	
			unit.weaponName = "Night Killer";
			unit.weaponEffect = "Darkness";
			unit.weaponType = "Crossbow";
			unit.weaponRange = 4;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 3;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponDarkness = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 3)
		{	
			unit.weaponName = "Cross Bow";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Crossbow";
			unit.weaponRange = 4;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 4;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			unit.weaponName = "Poison Bow";
			unit.weaponEffect = "Poison";
			unit.weaponType = "Crossbow";
			unit.weaponRange = 4;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 4;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponPoison = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 5)
		{	
			unit.weaponName = "Hunting Bow";
			unit.weaponEffect = "";
			unit.weaponType = "Crossbow";
			unit.weaponRange = 4;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 6;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			unit.weaponName = "Gastrafitis";
			unit.weaponEffect = "";
			unit.weaponType = "Crossbow";
			unit.weaponRange = 4;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 10;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 5 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Battle Dict";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Dictionary";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 7;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Monster Dict";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Dictionary";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 8;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Papyrus Plate";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Dictionary";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 9;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Madlemgen";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Dictionary";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 11;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 6 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		if( equipWeapon == 1 )
		{
			unit.weaponName = "Persia";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Fabric";
			unit.weaponRange = 2;
			unit.weaponPower = 8;
			unit.weaponEvade = 50;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		if( equipWeapon == 2 )
		{
			unit.weaponName = "Cashmere";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Fabric";
			unit.weaponRange = 2;
			unit.weaponPower = 10;
			unit.weaponEvade = 50;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		if( equipWeapon == 3 )
		{
			unit.weaponName = "Ryozan Silk";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Fabric";
			unit.weaponRange = 2;
			unit.weaponPower = 15;
			unit.weaponEvade = 50;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 7 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Flail";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Flail";
			unit.weaponRange = 1;
			unit.weaponPower = 9;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Flame Whip";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Flail";
			unit.weaponRange = 1;
			unit.weaponPower = 11;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponFire = true;
			unit.weaponFire2 = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Morning Star";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Flail";
			unit.weaponRange = 1;
			unit.weaponPower = 16;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Scorpion Tail";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Flail";
			unit.weaponRange = 1;
			unit.weaponPower = 23;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 8 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Romanda Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Gun";
			unit.weaponRange = 8;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 6;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Mythril Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Gun";
			unit.weaponRange = 8;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 8;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Stone Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Gun";
			unit.weaponRange = 8;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 16;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponStartPetrify = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Blaze Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Magic Gun";
			unit.weaponRange = 8;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 20;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponIce = true;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Glacier Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Magic Gun";
			unit.weaponRange = 8;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 21;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponFire = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Blast Gun";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Magic Gun";
			unit.weaponRange = 8;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 22;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponLightning = true;
		}
	}
	else if( equipAction == 9 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Ramia Harp";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Harp";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 10;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponStatusEffect = true;
			unit.weaponConfusion = true;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Bloody Strings";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Harp";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 13;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponLifeDrain = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Fairy Harp";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Harp";
			unit.weaponRange = 3;
			unit.weaponRangeMin = 3;
			unit.weaponPower = 15;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponStatusEffect = true;
			unit.weaponCharm = true;
		}
	}
	else if( equipAction == 10 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Asura Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 7;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Koutetsu Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 8;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Bizen Boat";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 9;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Murasame";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 10;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Heaven's Cloud";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 11;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Kiyomori";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 12;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.weaponName = "Muramasa";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 14;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{
			unit.weaponName = "Kikuichimoji";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 15;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 9 )
		{
			unit.weaponName = "Masamune";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 18;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 10 )
		{
			unit.weaponName = "Chirijiraden";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Katana";
			unit.weaponRange = 1;
			unit.weaponPower = 25;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 11 )
	{
		
		if( equipWeapon == 0)
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			unit.weaponName = "Dagger";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 0;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon== 2)
		{	
			unit.weaponName = "Mythril Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 4;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.weaponName = "Blind Knife";
			unit.weaponEffect = "Darkness";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 4;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponDarkness = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 4)
		{	
			unit.weaponName = "Mage Masher";
			unit.weaponEffect = "Silence";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 4;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponSilence = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 5)
		{	
			unit.weaponName = "Platina Dagger";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 5;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			unit.weaponName = "Main Gauche";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 6;
			unit.weaponEvade = 40;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 7)
		{	
			unit.weaponName = "Orichalcum";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 7;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 8)
		{	
			unit.weaponName = "Assassin Dagger";
			unit.weaponEffect = "Add: Death Sentence";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 7;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponDeathSentence = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 9 )
		{	
			unit.weaponName = "Air Knife";
			unit.weaponEffect = "Wind Elemental";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 10;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponWind = true;
		}
		else if( equipWeapon == 10)
		{	
			unit.weaponName = "Zorlin Shape";
			unit.weaponEffect = "Add: Sleep";
			unit.weaponType = "Knife";
			unit.weaponRange = 1;
			unit.weaponPower = 12;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponSleep = true;
			unit.weaponStatusEffect = true;
		}
	}
	else if( equipAction == 12 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Defender";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Knight Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 16;
			unit.weaponEvade = 60;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Save the Queen";
			unit.weaponEffect = "Auto Protect";
			unit.weaponType = "Knight Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 18;
			unit.weaponEvade = 30;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponAutoProtect = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Excalibur";
			unit.weaponEffect = "Auto Haste, Absorb Holy, Strengthen Holy";
			unit.weaponType = "Knight Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 21;
			unit.weaponEvade = 35;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponAutoHaste = true;
			unit.weaponHolyUp = true;
			unit.weaponHolyAbsorb = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Ragnarok";
			unit.weaponEffect = "Auto Shell";
			unit.weaponType = "Knight Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 24;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponAutoShell = true;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Chaos Blade";
			unit.weaponEffect = "Auto Regen, Add Petrify";
			unit.weaponType = "Knight Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 40;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponAutoRegen = true;
			unit.weaponPetrify = true;
			unit.weaponStatusEffect = true;
		}
	}
	else if( equipAction == 13 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Hidden Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 8;
			unit.weaponEvade = 5;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Ninja Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 9;
			unit.weaponEvade = 5;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Short Edge";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 10;
			unit.weaponEvade = 5;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Ninja Edge";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 12;
			unit.weaponEvade = 5;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Spell Edge";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 13;
			unit.weaponEvade = 5;
			unit.weapon = false;
			unit.weaponEffectBool = true;
			unit.weaponStatusEffect = true;
			unit.weaponDontAct = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Sasuke Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 14;
			unit.weaponEvade = 15;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.weaponName = "Iga Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 15;
			unit.weaponEvade = 10;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
		else if( equipWeapon == 8 )
		{
			unit.weaponName = "Koga Knife";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Ninja Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 15;
			unit.weaponEvade = 5;
			unit.weapon = false;
			unit.weaponEffectBool = false;
			unit.weaponStatusEffect = false;
		}
	}
	else if( equipAction == 14 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Rod";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Thunder Rod";
			unit.weaponEffect = "Lightning, Lightning Up, Add: Bolt";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponBolt1 = true;
			unit.weaponLightning = true;
			unit.weaponLightningUp = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Flame Rod";
			unit.weaponEffect = "Fire, Fire Up, Add: Fire";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponFire1 = true;
			unit.weaponFire= true;
			unit.weaponFireUp = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Ice Rod";
			unit.weaponEffect = "Ice, Ice Up, Add: Ice";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponIce1 = true;
			unit.weaponIce = true;
			unit.weaponIceUp = true;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Poison Rod";
			unit.weaponEffect = "Add: Poison";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponPoison = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Wizard Rod";
			unit.weaponEffect = "";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponMA = 2;
		}
		else if( equipWeapon == 7 )
		{
			unit.weaponName = "Faith Rod";
			unit.weaponEffect = "Add: Faith, Auto Faith";
			unit.weaponType = "Rod";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponFaith = true;
			unit.weaponAutoFaith = true;
		}
	}
	else if( equipAction == 15 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Javelin";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 8;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Spear";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 9;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Mythril Spear";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 10;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Partisan";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 11;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Oberisk";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 12;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Holy Lance";
			unit.weaponEffect = "Holy, Add: Holy";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 14;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponHoly = true;
			unit.weaponHolyCast = true;
		}
		else if( equipWeapon == 7 )
		{
			unit.weaponName = "Dragon Whisker";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 17;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{
			unit.weaponName = "Javelin";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Spear";
			unit.weaponRange = 2;
			unit.weaponPower = 30;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 16 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Oak Staff";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "White Staff";
			unit.weaponEffect = "Cancel: Death Sentence";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 3;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCancelDeathSentence = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Healing Staff";
			unit.weaponEffect = "Restore HP on Attack";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 4;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponHeal = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Rainbow Staff";
			unit.weaponEffect = "";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 5;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Wizard Staff";
			unit.weaponEffect = "";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 5;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponMA = 1;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Gold Staff";
			unit.weaponEffect = "";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 6;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.weaponName = "Mace of Zeus";
			unit.weaponEffect = "";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 6;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponPA = 2;
			unit.weaponMA = 1;
		}
		else if( equipWeapon == 8 )
		{
			unit.weaponName = "Sage Staff";
			unit.weaponEffect = "";
			unit.weaponType = "Staff";
			unit.weaponRange = 1;
			unit.weaponPower = 7;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 17 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.weaponName = "Cypress Rod";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 6;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.weaponName = "Battle Bamboo";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 7;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.weaponName = "Musk Rod";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 8;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.weaponName = "Iron Fan";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 9;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.weaponName = "Gokuu Rod";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 10;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponInnocent = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.weaponName = "Ivory Rod";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 11;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.weaponName = "Octagon Rod";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 12;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponStatusEffect = true;
			unit.weaponCancelDarkness = true;
			unit.weaponCancelSilence = true;
			unit.weaponCancelOil = true;
			unit.weaponCancelFrog = true;
			unit.weaponCancelPoison = true;
			unit.weaponCancelStop = true;
			unit.weaponCancelSlow = true;
			unit.weaponCancelDontMove = true;
			unit.weaponCancelDontAct = true;
		}
		else if( equipWeapon == 8 )
		{
			unit.weaponName = "Whale Whisker";
			unit.weaponType = "Stick";
			unit.weaponRange = 2;
			unit.weaponPower = 16;
			unit.weaponEvade = 20;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
	}
	else if( equipAction == 18 )
	{
		
		if( equipWeapon == 0)
		{
			unit.weaponName = "NONE";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Bare Hands";
			unit.weaponRange = 1;
			unit.weaponPower = 0;
			unit.weaponEvade = 0;
			unit.weapon = false;
			unit.weaponEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			unit.weaponName = "Broad Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 4;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			unit.weaponName = "Long Sword";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 5;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.weaponName = "Iron Sword";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 6;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			unit.weaponName = "Mythril Sword";
			unit.weaponEffect = "NULL";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 7;
			unit.weaponEvade = 8;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon ==  5 )
		{	
			unit.weaponName = "Blood Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 8;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponLifeDrain = true;
		}
		else if( equipWeapon == 6 )
		{	
			unit.weaponName = "Coral Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 8;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponLightning = true;
		}
		else if( equipWeapon == 7 )
		{	
			unit.weaponName = "Ancient Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 9;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponDontMove = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 8 )
		{	
			unit.weaponName = "Sleep Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 9;
			unit.weaponEvade = 5;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponSleep = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 9 )
		{	
			unit.weaponName = "Platinum Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 12;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 10 )
		{	
			unit.weaponName = "Diamond Sword";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 10;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = false;
		}
		else if( equipWeapon == 11 )
		{	
			unit.weaponName = "Ice Brand";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 13;
			unit.weaponEvade = 10;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponCastSpell = true;
			unit.weaponIce2 = true;
			unit.weaponIce = true;
		}
		else if( equipWeapon == 12 )
		{	
			unit.weaponName = "Rune Blade";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 14;
			unit.weaponEvade = 15;
			unit.weapon = true;
			unit.weaponEffectBool = false;
			unit.weaponMA = 2;
		}
		else if( equipWeapon == 13 )
		{	
			unit.weaponName = "Nagrarock";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 1;
			unit.weaponEvade = 50;
			unit.weapon = true;
			unit.weaponEffectBool = true;
			unit.weaponFrog = true;
			unit.weaponStatusEffect = true;
		}
		else if( equipWeapon == 14 )
		{	
			unit.weaponName = "Materia Blade";
			unit.weaponType = "Sword";
			unit.weaponRange = 1;
			unit.weaponPower = 10;
			unit.weaponEvade = 10;
			unit.weapon = true;
		}
	}
}

void quickStartWeapon( Player &unit, vector<string> unitVec )
{
	int tempInt = 0;
	int secInt = 0;
	string tempString = "";
	string secString = "";

	tempString = unitVec[19];
	tempString += unitVec[20];
	tempInt = atoi(tempString.c_str());

	secString = unitVec[21];
	secString += unitVec[22];
	secInt = atoi(secString.c_str());

	quickStartWeaponSelect( unit, tempInt, secInt );

	//add stats from weapon to unit
	unit.ma += unit.weaponMA;
	unit.pa += unit.weaponPA;
	unit.speed += unit.weaponSpeed;

}

//same as weapon except 19 for shield, 0 for tempInt is no weapon
void quickStartOffHandSelect( Player &unit, int tempInt, int secInt )
{
	int equipAction = tempInt;
	int equipWeapon = secInt;

	unit.offHandPhyEvade = 0;
	unit.offHandMagEvade = 0;
	unit.offHand = false;
	unit.offHandWeapon = false;
	unit.offHandEffectBool = false;
	unit.offHandName = "";
	unit.offHandType = "";
	if( unit.twoSwords == true )
		unit.offHandType = "Bare Hands";
	unit.offHandEffect = "";
	unit.offHandRange = 1;
	unit.offHandRangeMin = 1;
	unit.offHandPower = 0;
	unit.offHandEvade = 0;
	unit.offHandMA = 0;
	unit.offHandPA = 0;
	unit.offHandSpeed = 0;
	//unit.offHand add status 25%
	unit.offHandStatusEffect = false; //indicator for attack function
	unit.offHandDarkness = false;
	unit.offHandSilence = false;
	unit.offHandDeathSentence = false;
	unit.offHandSleep = false;
	unit.offHandDontAct = false;
	unit.offHandDontMove = false;
	unit.offHandFrog = false;
	unit.offHandPetrify = false;
	unit.offHandSlow = false;
	unit.offHandFaith = false;
	unit.offHandPoison = false;
	unit.offHandConfusion = false;
	unit.offHandCharm = false;
	unit.offHandInnocent = false;
	unit.offHandCancelDarkness = false;
	unit.offHandCancelSilence = false;
	unit.offHandCancelOil = false;
	unit.offHandCancelFrog = false;
	unit.offHandCancelPoison = false;
	unit.offHandCancelStop = false;
	unit.offHandCancelSlow = false;
	unit.offHandCancelDontMove = false;
	unit.offHandCancelDontAct = false;
	unit.offHandCancelDeathSentence = false;
	//unit.offHand elemental
	unit.offHandWind = false;
	unit.offHandIce = false;
	unit.offHandLightning = false;
	unit.offHandHolyUp = false;
	unit.offHandHolyAbsorb = false;
	unit.offHandFire = false;
	unit.offHandHoly = false;
	unit.offHandAbsorbIce = false;
	unit.offHandAbsorbFire = false;
	unit.offHandWeakLightning = false;
	unit.offHandWeakWater = false;
	unit.offHandHalfLightning = false;
	unit.offHandHalfFire = false;
	unit.offHandHalfIce = false;
	unit.offHandLightningUp = false;
	unit.offHandFireUp = false;
	unit.offHandIceUp = false;
	//special unit.offHand effects
	unit.offHandCastSpell = false;
	unit.offHandLifeDrain = false; //damage converted to HP
	unit.offHandHeal = false; //heals target on damage
	unit.offHandIce2 = false; //casts ice 2
	unit.offHandBolt1 = false;
	unit.offHandFire1 = false;
	unit.offHandIce1 = false;
	unit.offHandFire2 = false;
	unit.offHandHolyCast = false;
	unit.offHandMateriaBlade = false; //cloud subset
	//unit.offHand add status to user
	unit.offHandAutoProtect = false;
	unit.offHandAutoHaste = false;
	unit.offHandAutoShell = false;
	unit.offHandAutoRegen = false;
	unit.offHandAutoFaith = false;
	unit.offHandStartPetrify = false; //start Petrified

	if( equipAction == 0 )
	{
		//empty space on purpose, should keep just main weapon now
	}
	else if( equipAction == 1 )
	{
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		if( equipWeapon == 1 )
		{
			unit.offHandName = "Battle Axe";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Axe";
			unit.offHandRange = 1;
			unit.offHandPower = 9;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		if( equipWeapon == 2 )
		{
			unit.offHandName = "Giant Axe";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Axe";
			unit.offHandRange = 1;
			unit.offHandPower = 12;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		if( equipWeapon == 3 )
		{
			unit.offHandName = "Slasher";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Axe";
			unit.offHandRange = 1;
			unit.offHandPower = 16;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = true;
			unit.offHandSlow = true;
		}
	}
	else if( equipAction == 2 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "C Bag";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bag";
			unit.offHandRange = 1;
			unit.offHandPower = 10;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandMA = 1;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "FS Bag";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bag";
			unit.offHandRange = 1;
			unit.offHandPower = 20;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "P Bag";
			unit.offHandEffect = "Auto Regen";
			unit.offHandType = "Bag";
			unit.offHandRange = 1;
			unit.offHandPower = 12;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAutoRegen = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "H Bag";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bag";
			unit.offHandRange = 1;
			unit.offHandPower = 14;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandSpeed = 1;
		}
	}
	else if( equipAction == 3 )
	{
		
		if( equipWeapon == 0)
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1)
		{	
			unit.offHandName = "Long Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 4;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			unit.offHandName = "Silver Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 5;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.offHandName = "Ice Bow";
			unit.offHandEffect = "Ice";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 5;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandIce;
		}
		else if( equipWeapon == 4)
		{	
			unit.offHandName = "Lightning Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 6;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandLightning = true;
			unit.offHandBolt1 = true;
		}
		else if( equipWeapon == 5 )
		{	
			unit.offHandName = "Windslash Bow";
			unit.offHandEffect = "Wind";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 8;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandWind = true;
		}
		else if( equipWeapon == 6)
		{	
			unit.offHandName = "Mythril Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 7;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 7)
		{	
			unit.offHandName = "Ultimus Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 10;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{	
			unit.offHandName = "Yoichi Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 12;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 9 )
		{	
			unit.offHandName = "Perseus Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bow";
			unit.offHandRange = 5;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 16;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 4 )
	{
		
		if( equipWeapon == 0)
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			unit.offHandName = "Bow Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Crossbow";
			unit.offHandRange = 4;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 3;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		
		}
		else if( equipWeapon == 2)
		{	
			unit.offHandName = "Night Killer";
			unit.offHandEffect = "Darkness";
			unit.offHandType = "Crossbow";
			unit.offHandRange = 4;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 3;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandDarkness = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 3)
		{	
			unit.offHandName = "Cross Bow";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Crossbow";
			unit.offHandRange = 4;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 4;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			unit.offHandName = "Poison Bow";
			unit.offHandEffect = "Poison";
			unit.offHandType = "Crossbow";
			unit.offHandRange = 4;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 4;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandPoison = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 5)
		{	
			unit.offHandName = "Hunting Bow";
			unit.offHandEffect = "";
			unit.offHandType = "Crossbow";
			unit.offHandRange = 4;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 6;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			unit.offHandName = "Gastrafitis";
			unit.offHandEffect = "";
			unit.offHandType = "Crossbow";
			unit.offHandRange = 4;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 10;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 5 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Battle Dict";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Dictionary";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 7;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Monster Dict";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Dictionary";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 8;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Papyrus Plate";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Dictionary";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 9;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Madlemgen";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Dictionary";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 11;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 6 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		if( equipWeapon == 1 )
		{
			unit.offHandName = "Persia";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Fabric";
			unit.offHandRange = 2;
			unit.offHandPower = 8;
			unit.offHandEvade = 50;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		if( equipWeapon == 2 )
		{
			unit.offHandName = "Cashmere";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Fabric";
			unit.offHandRange = 2;
			unit.offHandPower = 10;
			unit.offHandEvade = 50;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		if( equipWeapon == 3 )
		{
			unit.offHandName = "Ryozan Silk";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Fabric";
			unit.offHandRange = 2;
			unit.offHandPower = 15;
			unit.offHandEvade = 50;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 7 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Flail";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Flail";
			unit.offHandRange = 1;
			unit.offHandPower = 9;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Flame Whip";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Flail";
			unit.offHandRange = 1;
			unit.offHandPower = 11;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandFire = true;
			unit.offHandFire2 = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Morning Star";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Flail";
			unit.offHandRange = 1;
			unit.offHandPower = 16;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Scorpion Tail";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Flail";
			unit.offHandRange = 1;
			unit.offHandPower = 23;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 8 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Romanda Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Gun";
			unit.offHandRange = 8;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 6;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Mythril Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Gun";
			unit.offHandRange = 8;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 8;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Stone Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Gun";
			unit.offHandRange = 8;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 16;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandStartPetrify = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Blaze Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Magic Gun";
			unit.offHandRange = 8;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 20;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandIce = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Glacier Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Magic Gun";
			unit.offHandRange = 8;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 21;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandFire = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Blast Gun";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Magic Gun";
			unit.offHandRange = 8;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 22;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandLightning = true;
		}
	}
	else if( equipAction == 9 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Ramia Harp";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Harp";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 10;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandStatusEffect = true;
			unit.offHandConfusion = true;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Bloody Strings";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Harp";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 13;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandLifeDrain = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Fairy Harp";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Harp";
			unit.offHandRange = 3;
			unit.offHandRangeMin = 3;
			unit.offHandPower = 15;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandStatusEffect = true;
			unit.offHandCharm = true;
		}
	}
	else if( equipAction == 10 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Asura Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 7;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Koutetsu Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 8;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Bizen Boat";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 9;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Murasame";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 10;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Heaven's Cloud";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 11;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Kiyomori";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 12;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.offHandName = "Muramasa";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 14;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{
			unit.offHandName = "Kikuichimoji";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 15;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 9 )
		{
			unit.offHandName = "Masamune";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 18;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 10 )
		{
			unit.offHandName = "Chirijiraden";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Katana";
			unit.offHandRange = 1;
			unit.offHandPower = 25;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 11 )
	{
		
		if( equipWeapon == 0)
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			unit.offHandName = "Dagger";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon== 2)
		{	
			unit.offHandName = "Mythril Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 4;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.offHandName = "Blind Knife";
			unit.offHandEffect = "Darkness";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 4;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandDarkness = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 4)
		{	
			unit.offHandName = "Mage Masher";
			unit.offHandEffect = "Silence";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 4;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandSilence = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 5)
		{	
			unit.offHandName = "Platina Dagger";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 5;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			unit.offHandName = "Main Gauche";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 6;
			unit.offHandEvade = 40;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 7)
		{	
			unit.offHandName = "Orichalcum";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 7;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 8)
		{	
			unit.offHandName = "Assassin Dagger";
			unit.offHandEffect = "Add: Death Sentence";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 7;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandDeathSentence = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 9 )
		{	
			unit.offHandName = "Air Knife";
			unit.offHandEffect = "Wind Elemental";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 10;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandWind = true;
		}
		else if( equipWeapon == 10)
		{	
			unit.offHandName = "Zorlin Shape";
			unit.offHandEffect = "Add: Sleep";
			unit.offHandType = "Knife";
			unit.offHandRange = 1;
			unit.offHandPower = 12;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandSleep = true;
			unit.offHandStatusEffect = true;
		}
	}
	else if( equipAction == 12 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Defender";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Knight Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 16;
			unit.offHandEvade = 60;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Save the Queen";
			unit.offHandEffect = "Auto Protect";
			unit.offHandType = "Knight Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 18;
			unit.offHandEvade = 30;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAutoProtect = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Excalibur";
			unit.offHandEffect = "Auto Haste, Absorb Holy, Strengthen Holy";
			unit.offHandType = "Knight Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 21;
			unit.offHandEvade = 35;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAutoHaste = true;
			unit.offHandHolyUp = true;
			unit.offHandHolyAbsorb = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Ragnarok";
			unit.offHandEffect = "Auto Shell";
			unit.offHandType = "Knight Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 24;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAutoShell = true;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Chaos Blade";
			unit.offHandEffect = "Auto Regen, Add Petrify";
			unit.offHandType = "Knight Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 40;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAutoRegen = true;
			unit.offHandPetrify = true;
			unit.offHandStatusEffect = true;
		}
	}
	else if( equipAction == 13 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Hidden Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 8;
			unit.offHandEvade = 5;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Ninja Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 9;
			unit.offHandEvade = 5;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Short Edge";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 10;
			unit.offHandEvade = 5;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Ninja Edge";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 12;
			unit.offHandEvade = 5;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Spell Edge";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 13;
			unit.offHandEvade = 5;
			unit.offHand = false;
			unit.offHandEffectBool = true;
			unit.offHandStatusEffect = true;
			unit.offHandDontAct = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Sasuke Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 14;
			unit.offHandEvade = 15;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.offHandName = "Iga Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 15;
			unit.offHandEvade = 10;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
		else if( equipWeapon == 8 )
		{
			unit.offHandName = "Koga Knife";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Ninja Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 15;
			unit.offHandEvade = 5;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandStatusEffect = false;
		}
	}
	else if( equipAction == 14 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Rod";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Thunder Rod";
			unit.offHandEffect = "Lightning, Lightning Up, Add: Bolt";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandBolt1 = true;
			unit.offHandLightning = true;
			unit.offHandLightningUp = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Flame Rod";
			unit.offHandEffect = "Fire, Fire Up, Add: Fire";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandFire1 = true;
			unit.offHandFire= true;
			unit.offHandFireUp = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Ice Rod";
			unit.offHandEffect = "Ice, Ice Up, Add: Ice";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandIce1 = true;
			unit.offHandIce = true;
			unit.offHandIceUp = true;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Poison Rod";
			unit.offHandEffect = "Add: Poison";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandPoison = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Wizard Rod";
			unit.offHandEffect = "";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandMA = 2;
		}
		else if( equipWeapon == 7 )
		{
			unit.offHandName = "Faith Rod";
			unit.offHandEffect = "Add: Faith, Auto Faith";
			unit.offHandType = "Rod";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandFaith = true;
			unit.offHandAutoFaith = true;
		}
	}
	else if( equipAction == 15 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Javelin";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 8;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Spear";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 9;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Mythril Spear";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 10;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Partisan";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 11;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Oberisk";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 12;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Holy Lance";
			unit.offHandEffect = "Holy, Add: Holy";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 14;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandHoly = true;
			unit.offHandHolyCast = true;
		}
		else if( equipWeapon == 7 )
		{
			unit.offHandName = "Dragon Whisker";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 17;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{
			unit.offHandName = "Javelin";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Spear";
			unit.offHandRange = 2;
			unit.offHandPower = 30;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 16 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Oak Staff";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "White Staff";
			unit.offHandEffect = "Cancel: Death Sentence";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 3;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCancelDeathSentence = true;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Healing Staff";
			unit.offHandEffect = "Restore HP on Attack";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 4;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandHeal = true;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Rainbow Staff";
			unit.offHandEffect = "";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 5;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Wizard Staff";
			unit.offHandEffect = "";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 5;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandMA = 1;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Gold Staff";
			unit.offHandEffect = "";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 6;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.offHandName = "Mace of Zeus";
			unit.offHandEffect = "";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 6;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandPA = 2;
			unit.offHandMA = 1;
		}
		else if( equipWeapon == 8 )
		{
			unit.offHandName = "Sage Staff";
			unit.offHandEffect = "";
			unit.offHandType = "Staff";
			unit.offHandRange = 1;
			unit.offHandPower = 7;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 17 )
	{
		
		if( equipWeapon == 0 )
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			unit.offHandName = "Cypress Rod";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 6;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			unit.offHandName = "Battle Bamboo";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 7;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			unit.offHandName = "Musk Rod";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 8;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			unit.offHandName = "Iron Fan";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 9;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			unit.offHandName = "Gokuu Rod";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 10;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandInnocent = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 6 )
		{
			unit.offHandName = "Ivory Rod";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 11;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			unit.offHandName = "Octagon Rod";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 12;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandStatusEffect = true;
			unit.offHandCancelDarkness = true;
			unit.offHandCancelSilence = true;
			unit.offHandCancelOil = true;
			unit.offHandCancelFrog = true;
			unit.offHandCancelPoison = true;
			unit.offHandCancelStop = true;
			unit.offHandCancelSlow = true;
			unit.offHandCancelDontMove = true;
			unit.offHandCancelDontAct = true;
		}
		else if( equipWeapon == 8 )
		{
			unit.offHandName = "Whale Whisker";
			unit.offHandType = "Stick";
			unit.offHandRange = 2;
			unit.offHandPower = 16;
			unit.offHandEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}
	else if( equipAction == 18 )
	{
		
		if( equipWeapon == 0)
		{
			unit.offHandName = "NONE";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Bare Hands";
			unit.offHandRange = 1;
			unit.offHandPower = 0;
			unit.offHandEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			unit.offHandName = "Broad Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 4;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			unit.offHandName = "Long Sword";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 5;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.offHandName = "Iron Sword";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 6;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			unit.offHandName = "Mythril Sword";
			unit.offHandEffect = "NULL";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 7;
			unit.offHandEvade = 8;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon ==  5 )
		{	
			unit.offHandName = "Blood Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 8;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandLifeDrain = true;
		}
		else if( equipWeapon == 6 )
		{	
			unit.offHandName = "Coral Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 8;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandLightning = true;
		}
		else if( equipWeapon == 7 )
		{	
			unit.offHandName = "Ancient Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 9;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandDontMove = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 8 )
		{	
			unit.offHandName = "Sleep Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 9;
			unit.offHandEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandSleep = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 9 )
		{	
			unit.offHandName = "Platinum Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 12;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 10 )
		{	
			unit.offHandName = "Diamond Sword";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 10;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 11 )
		{	
			unit.offHandName = "Ice Brand";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 13;
			unit.offHandEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandCastSpell = true;
			unit.offHandIce2 = true;
			unit.offHandIce = true;
		}
		else if( equipWeapon == 12 )
		{	
			unit.offHandName = "Rune Blade";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 14;
			unit.offHandEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandMA = 2;
		}
		else if( equipWeapon == 13 )
		{	
			unit.offHandName = "Nagrarock";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 1;
			unit.offHandEvade = 50;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandFrog = true;
			unit.offHandStatusEffect = true;
		}
		else if( equipWeapon == 14 )
		{	
			unit.offHandName = "Materia Blade";
			unit.offHandType = "Sword";
			unit.offHandRange = 1;
			unit.offHandPower = 10;
			unit.offHandEvade = 10;
			unit.offHand = true;
		}
	}
	else if( equipAction == 19 )
	{
		if( equipWeapon == 0)
		{
			unit.offHandName = "NONE";
			unit.offHandPhyEvade = 0;
			unit.offHandMagEvade = 0;
			unit.offHand = false;
			unit.offHandEffectBool = false;
			unit.offHandType = "NULL";
		}
		else if( equipWeapon == 1)
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Escutcheon";
			unit.offHandPhyEvade = 10;
			unit.offHandMagEvade = 3;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Buckler";
			unit.offHandPhyEvade = 13;
			unit.offHandMagEvade = 3;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Bronze Shield";
			unit.offHandPhyEvade = 16;
			unit.offHandMagEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Round Shield";
			unit.offHandPhyEvade = 19;
			unit.offHandMagEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Mythril Shield";
			unit.offHandPhyEvade = 22;
			unit.offHandMagEvade = 5;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Gold Shield";
			unit.offHandPhyEvade = 25;
			unit.offHandMagEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Ice Shield";
			unit.offHandPhyEvade = 28;
			unit.offHandMagEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAbsorbIce = true;
			unit.offHandHalfFire = true;
			unit.offHandWeakLightning = true;
		}
		else if( equipWeapon == 8 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Flame Shield";
			unit.offHandPhyEvade = 31;
			unit.offHandMagEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandAbsorbFire = true;
			unit.offHandHalfIce = true;
			unit.offHandWeakWater = true;
		}
		else if( equipWeapon == 9 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Aegis Shield";
			unit.offHandPhyEvade = 10;
			unit.offHandMagEvade = 50;
			unit.offHand = true;
			unit.offHandEffectBool = false;
			unit.offHandMA = 1;
		}
		else if( equipWeapon == 10 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Diamond Shield";
			unit.offHandPhyEvade = 34;
			unit.offHandMagEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 11 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Platina Shield";
			unit.offHandPhyEvade = 37;
			unit.offHandMagEvade = 10;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 12 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Crystal Shield";
			unit.offHandPhyEvade = 40;
			unit.offHandMagEvade = 15;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 13)
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Genji Shield";
			unit.offHandPhyEvade = 43;
			unit.offHandMagEvade = 0;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
		else if( equipWeapon == 14 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Kaiser Plate";
			unit.offHandPhyEvade = 46;
			unit.offHandMagEvade = 20;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandFireUp = true;
			unit.offHandLightningUp = true;
			unit.offHandIceUp = true;
		}
		else if( equipWeapon == 15 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Venetian Shield";
			unit.offHandPhyEvade = 50;
			unit.offHandMagEvade = 25;
			unit.offHand = true;
			unit.offHandEffectBool = true;
			unit.offHandHalfFire = true;
			unit.offHandHalfIce = true;
			unit.offHandHalfLightning = true;
		}
		else if( equipWeapon == 16 )
		{	
			unit.offHandType = "Shield";
			unit.offHandName = "Escutcheon";
			unit.offHandPhyEvade = 75;
			unit.offHandMagEvade = 50;
			unit.offHand = true;
			unit.offHandEffectBool = false;
		}
	}


	
}


void quickStartOffHand( Player &unit, vector<string> unitVec )
{
	int tempInt = 0;
	int secInt = 0;
	string tempString = "";
	string secString = "";

	tempString = unitVec[23];
	tempString += unitVec[24];
	tempInt = atoi(tempString.c_str());

	secString = unitVec[25];
	secString += unitVec[26];
	secInt = atoi(secString.c_str());

	quickStartOffHandSelect( unit, tempInt, secInt );

	unit.ma += unit.offHandMA;
	unit.pa += unit.offHandPA;
	unit.speed += unit.offHandSpeed;
}

//1 for ribbons, 2 for helmets, 3 for hats
void quickStartHeadSelect( Player &unit, int tempInt, int secInt )
{
	int equipType = tempInt; //outer menu
	int equipAction = secInt; //inner menu
	
	unit.head = false; 
	unit.headName= "NONE";
	unit.headType= "";
	unit.headLife = 0;
	unit.headMP = 0;
	unit.headPA = 0;
	unit.headMA = 0;
	unit.headSpeed = 0;
	unit.headDarknessBlock= false;
	unit.headSleepBlock= false;
	unit.headSilenceBlock= false;
	unit.headDontActBlock= false;
	unit.headDontMoveBlock= false;
	unit.headDeadBlock= false;
	unit.headPetrifyBlock= false;
	unit.headInviteBlock= false;
	unit.headConfusionBlock= false;
	unit.headBloodSuckBlock= false;
	unit.headStopBlock= false;
	unit.headBerserkBlock= false;
	unit.headCharmBlock= false;
	unit.headUndeadBlock= false;
	unit.headFrogBlock= false;
	unit.headPoisonBlock= false;
	unit.headSlowBlock= false;
	unit.headDeathSentenceBlock= false;


	if( equipType == 1 )
	{
		if( equipAction == 1)
		{
			unit.headName = "Cachusha";
			unit.headLife = 20;
			unit.head = true;
				
				
			unit.headDeadBlock = true;
			unit.headPetrifyBlock = true;
			unit.headInviteBlock = true;
			unit.headConfusionBlock = true;
			unit.headBloodSuckBlock = true;
			unit.headStopBlock = true;
			unit.headBerserkBlock = true;
			unit.headCharmBlock = true;
			unit.headSleepBlock = true;

		}
		else if( equipAction == 2)
		{
			unit.headName = "Barette";
			unit.headLife = 20;
			unit.head = true;

			unit.headDarknessBlock = true;
				
			unit.headSilenceBlock = true;
			unit.headDontActBlock = true;
			unit.headDontMoveBlock = true;
			unit.headUndeadBlock = true;
			unit.headFrogBlock = true;
			unit.headPoisonBlock = true;
			unit.headSlowBlock = true;
			unit.headDeathSentenceBlock = true;

		}
		else if( equipAction == 3)
		{
			unit.headName = "Ribbon";
			unit.headLife = 10;
			unit.head = true;
			unit.headDarknessBlock = true;
			unit.headSleepBlock = true;
			unit.headSilenceBlock = true;
			unit.headDontActBlock = true;
			unit.headDontMoveBlock = true;
			unit.headDeadBlock = true;
			unit.headPetrifyBlock = true;
			unit.headInviteBlock = true;
			unit.headConfusionBlock = true;
			unit.headBloodSuckBlock = true;
			unit.headStopBlock = true;
			unit.headBerserkBlock = true;
			unit.headCharmBlock = true;
			unit.headUndeadBlock = true;
			unit.headFrogBlock = true;
			unit.headPoisonBlock = true;
			unit.headSlowBlock = true;
			unit.headDeathSentenceBlock = true;
		}
	}
	else if( equipType == 2 )
	{
		if( equipAction == 0)
		{
			unit.head= false; 
			unit.headName= "NONE";
			unit.headType= "";
			unit.headLife = 0;
			unit.headMP = 0;
			unit.headPA = 0;
			unit.headMA = 0;
			unit.headSpeed = 0;
			unit.headDarknessBlock= false;
			unit.headSleepBlock= false;
			unit.headSilenceBlock= false;
			unit.headDontActBlock= false;
			unit.headDontMoveBlock= false;
			unit.headDeadBlock= false;
			unit.headPetrifyBlock= false;
			unit.headInviteBlock= false;
			unit.headConfusionBlock= false;
			unit.headBloodSuckBlock= false;
			unit.headStopBlock= false;
			unit.headBerserkBlock= false;
			unit.headCharmBlock= false;
			unit.headUndeadBlock= false;
			unit.headFrogBlock= false;
			unit.headPoisonBlock= false;
			unit.headSlowBlock= false;
			unit.headDeathSentenceBlock= false;
		}
		if( equipAction == 1)
		{	
			unit.headName = "Leather Helmet";
			unit.headLife = 10;
			unit.head = true;
		}
		else if( equipAction == 2)
		{	
			unit.headName = "Bronze Helmet";
			unit.headLife = 20;
			unit.head = true;
		}
		else if( equipAction == 3)
		{	
			unit.headName = "Iron Helmet";
			unit.headLife = 30;
			unit.head = true;
		}
		else if( equipAction == 4)
		{	
			unit.headName = "Barbuta";
			unit.headLife = 40;
			unit.head = true;
		}
		else if( equipAction == 5 )
		{	
			unit.headName = "Mythril Helmet";
			unit.headLife = 50;
			unit.head = true;
		}
		else if( equipAction == 6 )
		{	
			unit.headName = "Gold Helmet";
			unit.headLife = 60;
			unit.head = true;
		}
		else if( equipAction == 7 )
		{	
			unit.headName = "Cross Helmet";
			unit.headLife = 70;
			unit.head = true;
		}
		else if( equipAction == 8 )
		{	
			unit.headName = "Diamond Helmet";
			unit.headLife = 80;
			unit.head = true;
		}
		else if( equipAction == 9 )
		{	
			unit.headName = "Platina Helmet";
			unit.headLife = 90;
			unit.head = true;
		}
		else if( equipAction == 10 )
		{	
			unit.headName = "Circlet";
			unit.headLife = 100;
			unit.head = true;
		}
		else if( equipAction == 11 )
		{	
			unit.headName = "Crystal Helmet";
			unit.headLife = 120;
			unit.head = true;
		}
		else if( equipAction == 12 )
		{	
			unit.headName = "Genji Helmet";
			unit.headLife = 130;
			unit.head = true;
		}
		else if( equipAction == 13)
		{	
			unit.headName = "Grand Helmet";
			unit.headLife = 150;
			unit.head = true;
			unit.headDarknessBlock = true;
			unit.headSleepBlock = true;
		}
	}
	else if( equipType == 3 )
	{
		if( equipAction == 0)
		{
			unit.head= false; 
			unit.headName= "NONE";
			unit.headType= "";
			unit.headLife = 0;
			unit.headMP = 0;
			unit.headPA = 0;
			unit.headMA = 0;
			unit.headSpeed = 0;
			unit.headDarknessBlock= false;
			unit.headSleepBlock= false;
			unit.headSilenceBlock= false;
			unit.headDontActBlock= false;
			unit.headDontMoveBlock= false;
			unit.headDeadBlock= false;
			unit.headPetrifyBlock= false;
			unit.headInviteBlock= false;
			unit.headConfusionBlock= false;
			unit.headBloodSuckBlock= false;
			unit.headStopBlock= false;
			unit.headBerserkBlock= false;
			unit.headCharmBlock= false;
			unit.headUndeadBlock= false;
			unit.headFrogBlock= false;
			unit.headPoisonBlock= false;
			unit.headSlowBlock= false;
			unit.headDeathSentenceBlock= false;
		}
		if( equipAction == 1)
		{	
			unit.headName = "Leather Hat";
			unit.head = true;
			unit.headLife = 8;
		}
		else if( equipAction == 2)
		{	
			unit.headName = "Feather Hat";
			unit.head = true;
			unit.headLife = 16;
			unit.headMP = 5;
		}
		else if( equipAction == 3)
		{	
			unit.headName = "Red Hood";
			unit.head = true;
			unit.headLife = 24;
			unit.headMP = 8;
		}
		else if( equipAction == 4 )
		{	
			unit.headName = "Headgear";
			unit.head = true;
			unit.headLife = 32;
			unit.headMP = 0;
			unit.headPA = 1;
		}
		else if( equipAction == 5 )
		{	
			unit.headName = "Triangle Hat";
			unit.head = true;
			unit.headLife = 40;
			unit.headMP = 12;
			unit.headMA = 1;
		}
		else if( equipAction == 6 )
		{	
			unit.headName = "Green Beret";
			unit.head = true;
			unit.headLife = 48;
			unit.headMP = 0;
			unit.headSpeed = 1;
		}
		else if( equipAction == 7 )
		{	
			unit.headName = "Twist Headband";
			unit.head = true;
			unit.headLife = 56;
			unit.headMP = 0;
			unit.headPA = 2;
		}
		else if( equipAction ==  8 )
		{	
			unit.headName = "Holy Miter";
			unit.head = true;
			unit.headLife = 64;
			unit.headMP = 20;
			unit.headMA = 1;
		}
		else if( equipAction == 9 )
		{	
			unit.headName = "Black Hood";
			unit.head = true;
			unit.headLife = 72;
			unit.headMP = 0;
		}
		else if( equipAction == 10 )
		{	
			unit.headName = "Golden Hairpin";
			unit.head = true;
			unit.headLife = 80;
			unit.headMP = 50;
			unit.headSilenceBlock = true;
		}
		else if( equipAction == 11 )
		{	
			unit.headName = "Flash Hat";
			unit.head = true;
			unit.headLife = 88;
			unit.headMP = 15;
			unit.headMA = 1;
			unit.headSpeed = 1;
		}
		else if( equipAction == 12 )
		{	
			unit.headName = "Thief Hat";
			unit.head = true;
			unit.headLife = 100;
			unit.headMP = 0;
			unit.headSpeed = 2;
			unit.headDontActBlock = true;
			unit.headDontMoveBlock = true;
		}
	}
}


void quickStartHead( Player &unit, vector<string> unitVec )
{
	int tempInt = 0;
	int secInt = 0;
	string tempString = "";
	string secString = "";

	tempString = unitVec[27];
	tempString += unitVec[28];
	tempInt = atoi(tempString.c_str());

	secString = unitVec[29];
	secString += unitVec[30];
	secInt = atoi(secString.c_str());

	quickStartHeadSelect( unit, tempInt, secInt );

	unit.maxLife += unit.headLife;
	unit.life += unit.headLife;
	unit.maxMP += unit.headMP;
	unit.mp += unit.headMP;
	unit.pa += unit.headPA;
	unit.ma += unit.headMA;
	unit.speed += unit.headSpeed;

}

void quickStartBodySelect( Player &unit, int tempInt, int secInt )
{
	int equipType = tempInt; //outer menu
	int equipAction = secInt; //inner menu
	
	unit.body = false;
	unit.bodyName = "NONE";
	unit.bodyType = "";
	unit.bodyLife = 0;
	unit.bodyMP = 0;
	unit.bodyPA = 0;
	unit.bodyMA = 0;
	unit.bodySpeed = 0;
	unit.bodyAutoReflect = false;
	unit.bodyDeadBlock = false;
	unit.bodyStopBlock = false;
	unit.bodyLightningBlock = false;
	unit.bodyEarthUp = false;
	unit.bodyEarthAbsorb = false;
	unit.bodyStartTransparent = false;
	unit.bodyHolyAbsorb = false;
	unit.bodyFireHalf = false;
	unit.bodyIceHalf = false;
	unit.bodyLightningHalf = false;
	unit.bodyFireUp = false;
	unit.bodyLightningUp = false;
	unit.bodyIceUp = false;
	unit.bodyAutoProtect = false;
	unit.bodyAutoShell = false;

	if( equipType == 1 )
	{
		if( equipAction == 0)
		{
			unit.bodyName = "NONE";
			unit.bodyLife = 0;
			unit.body = false;
		}
		else if( equipAction == 1)
		{	
			unit.bodyName = "Leather Armor";
			unit.bodyLife = 10;
			unit.body = true;
		}
		else if( equipAction == 2)
		{	
			unit.bodyName = "Linen Cuirass";
			unit.bodyLife = 20;
			unit.body = true;
		}
		else if( equipAction == 3)
		{	
			unit.bodyName = "Bronze Armor";
			unit.bodyLife = 30;
			unit.body = true;
		}
		else if( equipAction == 4)
		{	
			unit.bodyName = "Chain Mail";
			unit.bodyLife = 40;
			unit.body = true;
		}
		else if( equipAction == 5 )
		{	
			unit.bodyName = "Mythril Armor";
			unit.bodyLife = 50;
			unit.body = true;
		}
		else if( equipAction == 6 )
		{	
			unit.bodyName = "Plate Mail";
			unit.bodyLife = 60;
			unit.body = true;
		}
		else if( equipAction == 7 )
		{	
			unit.bodyName = "Gold Armor";
			unit.bodyLife = 70;
			unit.body = true;
		}
		else if( equipAction == 8 )
		{	
			unit.bodyName = "Diamond Armor";
			unit.bodyLife = 80;
			unit.body = true;
		}
		else if( equipAction == 9 )
		{	
			unit.bodyName = "Platina Armor";
			unit.bodyLife = 90;
			unit.body = true;
		}
		else if( equipAction == 10 )
		{	
			unit.bodyName = "Carabini Mail";
			unit.bodyLife = 100;
			unit.body = true;
		}
		else if( equipAction == 11 )
		{	
			unit.bodyName = "Crystal Mail";
			unit.bodyLife = 110;
			unit.body = true;
		}
		else if( equipAction == 12)
		{	
			unit.bodyName = "Genji Armor";
			unit.bodyLife = 150;
			unit.body = true;
		}
		else if( equipAction == 13)
		{	
			unit.bodyName = "Reflect Mail";
			unit.bodyLife = 130;
			unit.body = true;
			unit.bodyAutoReflect = true;
		}
		else if( equipAction == 14)
		{	
			unit.bodyName = "Maximillian";
			unit.bodyLife = 200;
			unit.body = true;
		}
	}
	else if( equipType == 2)
	{
		if( equipAction == 0)
		{
			unit.bodyName = "NONE";
			unit.bodyLife = 0;
			unit.body = false;
			unit.bodyMP = 0;
		}
		else if( equipAction == 1 )
		{
			unit.bodyName = "Clothes";
			unit.bodyLife = 5;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 2 )
		{
			unit.bodyName = "Leather Outfit";
			unit.bodyLife = 10;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 3 )
		{
			unit.bodyName = "Leather Vest";
			unit.bodyLife = 18;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 4 )
		{
			unit.bodyName = "Chain Vest";
			unit.bodyLife = 24;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 5 )
		{
			unit.bodyName = "Mythril Vest";
			unit.bodyLife = 30;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 6 )
		{
			unit.bodyName = "Adaman Vest";
			unit.bodyLife = 36;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 7 )
		{
			unit.bodyName = "Wizard Outfit";
			unit.bodyLife = 42;
			unit.body = true;
			unit.bodyMP = 15;
		}
		else if( equipAction == 8 )
		{
			unit.bodyName = "Brigandine";
			unit.bodyLife = 50;
			unit.body = true;
			unit.bodyMP = 0;
		}
		else if( equipAction == 9 )
		{
			unit.bodyName = "Judo Outfit";
			unit.bodyLife = 60;
			unit.body = true;
			unit.bodyMP = 0;
			unit.bodyPA = 1;
			unit.bodyDeadBlock = true;
		}
		else if( equipAction == 10 )
		{
			unit.bodyName = "Power Sleeve";
			unit.bodyLife = 70;
			unit.body = true;
			unit.bodyPA = 2;
		}
		else if( equipAction == 11 )
		{
			unit.bodyName = "Earth Clothes";
			unit.bodyLife = 85;
			unit.body = true;
			unit.bodyMP = 10;
			unit.bodyEarthAbsorb = true;
			unit.bodyEarthUp = true;
		}
		else if( equipAction == 12 )
		{
			unit.bodyName = "Secret Clothes";
			unit.bodyLife = 20;
			unit.body = true;
			unit.bodySpeed = 2;
			unit.bodyStartTransparent = true;
		}
		else if( equipAction == 13 )
		{
			unit.bodyName = "Black Costume";
			unit.bodyLife = 100;
			unit.body = true;
			unit.bodyStopBlock = true;
		}
		else if( equipAction == 14 )
		{
			unit.bodyName = "Rubber Costume";
			unit.bodyLife = 150;
			unit.body = true;
			unit.bodyLightningBlock = true;
			unit.bodyMP = 50;
		}
	}
	else if( equipType == 3 )
	{
		if( equipAction == 0)
		{
			unit.bodyName = "NONE";
			unit.bodyLife = 0;
			unit.body = false;
			unit.bodyMP = 0;
		}
		else if( equipAction == 1)
		{	
			unit.bodyName = "Linen Robe";
			unit.bodyLife = 10;
			unit.body = true;
			unit.bodyMP = 10;
		}
		else if( equipAction == 2)
		{	
			unit.bodyName = "Silk Robe";
			unit.bodyLife = 20;
			unit.body = true;
			unit.bodyMP = 16;
		}
		else if( equipAction == 3)
		{	
			unit.bodyName = "Wizard Robe";
			unit.bodyLife = 30;
			unit.body = true;
			unit.bodyMP = 22;
			unit.bodyMA = 2;
		}
		else if( equipAction == 4)
		{	
			unit.bodyName = "Chameleon Robe";
			unit.bodyLife = 40;
			unit.body = true;
			unit.bodyMP = 28;
			unit.bodyHolyAbsorb = true;
			unit.bodyDeadBlock = true;
		}
		else if( equipAction == 5 )
		{	
			unit.bodyName = "White Robe";
			unit.bodyLife = 50;
			unit.body = true;
			unit.bodyMP = 34;
			unit.bodyFireHalf = true;
			unit.bodyIceHalf = true;
			unit.bodyLightningHalf = true;
		}
		else if( equipAction == 6 )
		{	
			unit.bodyName = "Black Robe";
			unit.bodyLife = 60;
			unit.body = true;
			unit.bodyMP = 30;
			unit.bodyFireUp = true;
			unit.bodyIceUp = true;
			unit.bodyLightningUp = true;
		}
		else if( equipAction == 7 )
		{	
			unit.bodyName = "White Robe";
			unit.bodyLife = 75;
			unit.body = true;
			unit.bodyMP = 50;
		}
		else if( equipAction == 8 )
		{	
			unit.bodyName = "Robe of Lords";
			unit.bodyLife = 100;
			unit.body = true;
			unit.bodyMP = 80;
			unit.bodyAutoProtect = true;
			unit.bodyAutoShell = true;
			unit.bodyPA = 2;
			unit.bodyMA = 1;
		}
	}//end robe selection

}


void quickStartBody( Player &unit, vector<string> unitVec )
{
	int tempInt = 0;
	int secInt = 0;
	string tempString = "";
	string secString = "";

	tempString = unitVec[31];
	tempString += unitVec[32];
	tempInt = atoi(tempString.c_str());

	secString = unitVec[33];
	secString += unitVec[34];
	secInt = atoi(secString.c_str());

	quickStartBodySelect( unit, tempInt, secInt );

	unit.maxLife += unit.bodyLife;
	unit.life += unit.bodyLife;
	unit.maxMP += unit.bodyMP;
	unit.mp += unit.bodyMP;
	unit.pa += unit.bodyPA;
	unit.ma += unit.bodyMA;
	unit.speed += unit.bodySpeed;

}

void quickStartAccSelect( Player &unit, int tempInt, int secInt )
{
	int equipMenu = tempInt; //outer menu
	int equipAction = secInt; //inner menu
	
	unit.accessory = false; //accessory slot
	unit.accName = "NONE";
	unit.accType = "";
	unit.accPhyEvade = 0;
	unit.accMagEvade = 0;
	unit.accMove = 0;
	unit.accPA = 0;
	unit.accSpeed = 0;
	unit.accMA = 0;
	unit.accJump = 0;
	unit.accDontMoveBlock = false;
	unit.accDontActBlock = false;
	unit.accLightningBlock = false;
	unit.accAutoReflect = false;
	unit.accSleepBlock = false;
	unit.accDeathSentenceBlock = false;
	unit.accSilenceBlock = false;
	unit.accBerserkBlock = false;
	unit.accAutoUndead = false;
	unit.accInviteBlock = false;
	unit.accStartReraise = false;
	unit.accDeadBlock = false;
	unit.accDarknessBlock = false;
	unit.accSlowBlock = false;
	unit.accPetrifyBlock = false;
	unit.accStopBlock = false;
	unit.accUndeadBlock = false;
	unit.accBloodSuckBlock = false;
	unit.accFrogBlock = false;
	unit.accPoisonBlock = false;
	unit.accConfusionBlock = false;
	unit.accCharmBlock = false;
	unit.accFireUp = false;
	unit.accIceUp = false;
	unit.accWaterUp = false;
	unit.accLightningUp = false;
	unit.accEarthUp = false;
	unit.accWindUp = false;
	unit.accHolyUp = false;
	unit.accDarkUp = false;
	unit.accDarkHalf = false;
	unit.accStartTransparent = false;
	unit.accAutoRegen = false;
	unit.accAutoReraise = false;
	unit.accAutoFloat = false;
	unit.accAutoProtect = false;
	unit.accAutoShell = false;
	unit.accAutoHaste = false;
	
	if( equipMenu == 0 )
	{
		unit.accessory = false; //accessory slot
		unit.accName = "NONE";
		unit.accType = "";
		unit.accPhyEvade = 0;
		unit.accMagEvade = 0;
		unit.accMove = 0;
		unit.accPA = 0;
		unit.accSpeed = 0;
		unit.accMA = 0;
		unit.accJump = 0;
		unit.accDontMoveBlock = false;
		unit.accDontActBlock = false;
		unit.accLightningBlock = false;
		unit.accAutoReflect = false;
		unit.accSleepBlock = false;
		unit.accDeathSentenceBlock = false;
		unit.accSilenceBlock = false;
		unit.accBerserkBlock = false;
		unit.accAutoUndead = false;
		unit.accInviteBlock = false;
		unit.accStartReraise = false;
		unit.accDeadBlock = false;
		unit.accDarknessBlock = false;
		unit.accSlowBlock = false;
		unit.accPetrifyBlock = false;
		unit.accStopBlock = false;
		unit.accUndeadBlock = false;
		unit.accBloodSuckBlock = false;
		unit.accFrogBlock = false;
		unit.accPoisonBlock = false;
		unit.accConfusionBlock = false;
		unit.accCharmBlock = false;
		unit.accFireUp = false;
		unit.accIceUp = false;
		unit.accWaterUp = false;
		unit.accLightningUp = false;
		unit.accEarthUp = false;
		unit.accWindUp = false;
		unit.accHolyUp = false;
		unit.accDarkUp = false;
		unit.accDarkHalf = false;
		unit.accStartTransparent = false;
		unit.accAutoRegen = false;
		unit.accAutoReraise = false;
		unit.accAutoFloat = false;
		unit.accAutoProtect = false;
		unit.accAutoShell = false;
		unit.accAutoHaste = false;
	}
	else if( equipMenu == 1 )
	{
		if( equipAction == 0 )
		{
			unit.accessory = false; //accessory slot
			unit.accName = "NONE";
			unit.accType = "";
			unit.accPhyEvade = 0;
			unit.accMagEvade = 0;
			unit.accMove = 0;
			unit.accPA = 0;
			unit.accSpeed = 0;
			unit.accMA = 0;
			unit.accJump = 0;
			unit.accDontMoveBlock = false;
			unit.accDontActBlock = false;
			unit.accLightningBlock = false;
			unit.accAutoReflect = false;
			unit.accSleepBlock = false;
			unit.accDeathSentenceBlock = false;
			unit.accSilenceBlock = false;
			unit.accBerserkBlock = false;
			unit.accAutoUndead = false;
			unit.accInviteBlock = false;
			unit.accStartReraise = false;
			unit.accDeadBlock = false;
			unit.accDarknessBlock = false;
			unit.accSlowBlock = false;
			unit.accPetrifyBlock = false;
			unit.accStopBlock = false;
			unit.accUndeadBlock = false;
			unit.accBloodSuckBlock = false;
			unit.accFrogBlock = false;
			unit.accPoisonBlock = false;
			unit.accConfusionBlock = false;
			unit.accCharmBlock = false;
			unit.accFireUp = false;
			unit.accIceUp = false;
			unit.accWaterUp = false;
			unit.accLightningUp = false;
			unit.accEarthUp = false;
			unit.accWindUp = false;
			unit.accHolyUp = false;
			unit.accDarkUp = false;
			unit.accDarkHalf = false;
			unit.accStartTransparent = false;
			unit.accAutoRegen = false;
			unit.accAutoReraise = false;
			unit.accAutoFloat = false;
			unit.accAutoProtect = false;
			unit.accAutoShell = false;
			unit.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			unit.accessory = true;
			unit.accName = "Battle Boots";
			unit.accMove = 1;
		}
		else if( equipAction == 2 )
		{
			unit.accessory = true;
			unit.accName = "Spike Boots";
			unit.accJump = 1;
		}
		else if( equipAction == 3 )
		{
			unit.accessory = true;
			unit.accName = "Germinas Boots";
			unit.accMove = 1;
			unit.accJump = 1;
		}
		else if( equipAction == 4 )
		{
			unit.accessory = true;
			unit.accName = "Rubber Shoes";
			unit.accDontMoveBlock = true;
			unit.accLightningBlock = true;
		}
		else if( equipAction == 5 )
		{
			unit.accessory = true;
			unit.accName = "Feather Boots";
			unit.accAutoFloat = true;
		}
		else if( equipAction == 6 )
		{
			unit.accessory = true;
			unit.accName = "Sprint Shoes";
			unit.accSpeed = 1;
		}
		else if( equipAction == 7 )
		{
			unit.accessory = true;
			unit.accName = "Red Shoes";
			unit.accMove = 1;
			unit.accMA = 1;
		}
	}
	else if( equipMenu == 2 )
	{

		if( equipAction == 0 )
		{
			unit.accessory = false; //accessory slot
			unit.accName = "NONE";
			unit.accType = "";
			unit.accPhyEvade = 0;
			unit.accMagEvade = 0;
			unit.accMove = 0;
			unit.accPA = 0;
			unit.accSpeed = 0;
			unit.accMA = 0;
			unit.accJump = 0;
			unit.accDontMoveBlock = false;
			unit.accDontActBlock = false;
			unit.accLightningBlock = false;
			unit.accAutoReflect = false;
			unit.accSleepBlock = false;
			unit.accDeathSentenceBlock = false;
			unit.accSilenceBlock = false;
			unit.accBerserkBlock = false;
			unit.accAutoUndead = false;
			unit.accInviteBlock = false;
			unit.accStartReraise = false;
			unit.accDeadBlock = false;
			unit.accDarknessBlock = false;
			unit.accSlowBlock = false;
			unit.accPetrifyBlock = false;
			unit.accStopBlock = false;
			unit.accUndeadBlock = false;
			unit.accBloodSuckBlock = false;
			unit.accFrogBlock = false;
			unit.accPoisonBlock = false;
			unit.accConfusionBlock = false;
			unit.accCharmBlock = false;
			unit.accFireUp = false;
			unit.accIceUp = false;
			unit.accWaterUp = false;
			unit.accLightningUp = false;
			unit.accEarthUp = false;
			unit.accWindUp = false;
			unit.accHolyUp = false;
			unit.accDarkUp = false;
			unit.accDarkHalf = false;
			unit.accStartTransparent = false;
			unit.accAutoRegen = false;
			unit.accAutoReraise = false;
			unit.accAutoFloat = false;
			unit.accAutoProtect = false;
			unit.accAutoShell = false;
			unit.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Power Wrist";
			unit.accPA = 1;
		}
		else if( equipAction == 2 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Genji Gauntlet";
			unit.accPA = 2;
			unit.accMA = 2;
		}
		else if( equipAction == 3 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Magic Gauntlet";
			unit.accMA = 2;
		}
		else if( equipAction == 4 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Bracer";
			unit.accPA = 3;
		}
		else if( equipAction == 5 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Reflect Ring";
			unit.accAutoReflect = true;
		}
		else if( equipAction == 6 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Defense Ring";
			unit.accSleepBlock = true;
			unit.accDeathSentenceBlock = true;
		}
		else if( equipAction == 7 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Magic Ring";
			unit.accSilenceBlock = false;
			unit.accBerserkBlock = false;
		}
		else if( equipAction == 8 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Cursed Ring";
			unit.accPA = 1;
			unit.accMA = 1;
			unit.accSpeed = 1;
			unit.accAutoUndead = true;
			unit.accInviteBlock = true;
		}
		else if( equipAction == 9 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Angel Ring";
			unit.accStartReraise = true;
			unit.accUndeadBlock = true;
			unit.accDarknessBlock = true;

		}
		else if( equipAction == 10 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Diamond Armlet";
			unit.accPA = 1;
			unit.accMA = 1;
			unit.accSlowBlock = true;
		}
		else if( equipAction == 11 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Jade Arlmet";
			unit.accPetrifyBlock = true;
			unit.accStopBlock = true;
		}
		else if( equipAction == 12 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Defense Armlet";
			unit.accDontActBlock = true;
			unit.accDontMoveBlock = true;
		}
		else if( equipAction == 13 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "N-Kai Armlet";
			unit.accConfusionBlock = true;
			unit.accCharmBlock = true;
			unit.accDarkHalf = true;
		}
		else if( equipAction == 14 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "108 Gems";
			unit.accUndeadBlock = true;
			unit.accBloodSuckBlock = true;
			unit.accFrogBlock = true;
			unit.accPoisonBlock = true;
			unit.accFireUp = true;
			unit.accIceUp = true;
			unit.accWaterUp = true;
			unit.accWindUp = true;
			unit.accHolyUp = true;
			unit.accDarkUp = true;
			unit.accEarthUp = true;
			unit.accLightningUp = true;
		}
	}
	else if( equipMenu == 3 )
	{
		
		if( equipAction == 0 )
		{
			unit.accessory = false; //accessory slot
			unit.accName = "NONE";
			unit.accType = "";
			unit.accPhyEvade = 0;
			unit.accMagEvade = 0;
			unit.accMove = 0;
			unit.accPA = 0;
			unit.accSpeed = 0;
			unit.accMA = 0;
			unit.accJump = 0;
			unit.accDontMoveBlock = false;
			unit.accDontActBlock = false;
			unit.accLightningBlock = false;
			unit.accAutoReflect = false;
			unit.accSleepBlock = false;
			unit.accDeathSentenceBlock = false;
			unit.accSilenceBlock = false;
			unit.accBerserkBlock = false;
			unit.accAutoUndead = false;
			unit.accInviteBlock = false;
			unit.accStartReraise = false;
			unit.accDeadBlock = false;
			unit.accDarknessBlock = false;
			unit.accSlowBlock = false;
			unit.accPetrifyBlock = false;
			unit.accStopBlock = false;
			unit.accUndeadBlock = false;
			unit.accBloodSuckBlock = false;
			unit.accFrogBlock = false;
			unit.accPoisonBlock = false;
			unit.accConfusionBlock = false;
			unit.accCharmBlock = false;
			unit.accFireUp = false;
			unit.accIceUp = false;
			unit.accWaterUp = false;
			unit.accLightningUp = false;
			unit.accEarthUp = false;
			unit.accWindUp = false;
			unit.accHolyUp = false;
			unit.accDarkUp = false;
			unit.accDarkHalf = false;
			unit.accStartTransparent = false;
			unit.accAutoRegen = false;
			unit.accAutoReraise = false;
			unit.accAutoFloat = false;
			unit.accAutoProtect = false;
			unit.accAutoShell = false;
			unit.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Small Mantle";
			unit.accPhyEvade = 10;
			unit.accMagEvade = 10;
		}
		else if( equipAction == 2 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Leather Mantle";
			unit.accPhyEvade = 15;
			unit.accMagEvade = 15;
		}
		else if( equipAction == 3 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Wizard Mantle";
			unit.accPhyEvade = 18;
			unit.accMagEvade = 18;
			unit.accMA = 1;
		}
		else if( equipAction == 4 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Elf Mantle";
			unit.accPhyEvade = 25;
			unit.accMagEvade = 25;
		}
		else if( equipAction == 5 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Dracula Mantle";
			unit.accPhyEvade = 28;
			unit.accMagEvade = 28;
		}
		else if( equipAction == 6 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Feather Mantle";
			unit.accPhyEvade = 40;
			unit.accMagEvade = 30;
		}
		else if( equipAction == 7 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Vanish Mantle";
			unit.accPhyEvade = 35;
			unit.accMagEvade = 0;
			unit.accStartTransparent = true;
		}
	}
	else if( equipMenu == 4 )
	{
		if( equipAction == 0 )
		{
			unit.accessory = false; //accessory slot
			unit.accName = "NONE";
			unit.accType = "";
			unit.accPhyEvade = 0;
			unit.accMagEvade = 0;
			unit.accMove = 0;
			unit.accPA = 0;
			unit.accSpeed = 0;
			unit.accMA = 0;
			unit.accJump = 0;
			unit.accDontMoveBlock = false;
			unit.accDontActBlock = false;
			unit.accLightningBlock = false;
			unit.accAutoReflect = false;
			unit.accSleepBlock = false;
			unit.accDeathSentenceBlock = false;
			unit.accSilenceBlock = false;
			unit.accBerserkBlock = false;
			unit.accAutoUndead = false;
			unit.accInviteBlock = false;
			unit.accStartReraise = false;
			unit.accDeadBlock = false;
			unit.accDarknessBlock = false;
			unit.accSlowBlock = false;
			unit.accPetrifyBlock = false;
			unit.accStopBlock = false;
			unit.accUndeadBlock = false;
			unit.accBloodSuckBlock = false;
			unit.accFrogBlock = false;
			unit.accPoisonBlock = false;
			unit.accConfusionBlock = false;
			unit.accCharmBlock = false;
			unit.accFireUp = false;
			unit.accIceUp = false;
			unit.accWaterUp = false;
			unit.accLightningUp = false;
			unit.accEarthUp = false;
			unit.accWindUp = false;
			unit.accHolyUp = false;
			unit.accDarkUp = false;
			unit.accDarkHalf = false;
			unit.accStartTransparent = false;
			unit.accAutoRegen = false;
			unit.accAutoReraise = false;
			unit.accAutoFloat = false;
			unit.accAutoProtect = false;
			unit.accAutoShell = false;
			unit.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Chantage";
			unit.accAutoRegen = true;
			unit.accAutoReraise = true;
		}
		else if( equipAction == 2 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Cherche";
			unit.accAutoFloat = true;
			unit.accAutoReflect = true;
		}
		else if( equipAction == 3 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Salty Rage";
			unit.accAutoProtect = true;
			unit.accAutoShell = true;
		}
		else if( equipAction == 4 )
		{
			unit.accessory = true; //accessory slot
			unit.accName = "Setiemson";
			unit.accAutoHaste = true;
			unit.accStartTransparent = true;
			unit.accMA = 1;
		}
	}

}


void quickStartAcc( Player &unit, vector<string> unitVec )
{
	int tempInt = 0;
	int secInt = 0;
	string tempString = "";
	string secString = "";

	tempString = unitVec[35];
	tempString += unitVec[36];
	tempInt = atoi(tempString.c_str());

	secString = unitVec[37];
	secString += unitVec[38];
	secInt = atoi(secString.c_str());

	quickStartAccSelect( unit, tempInt, secInt );

	unit.pa += unit.accPA;
	unit.ma += unit.accMA;
	unit.speed += unit.accSpeed;
	unit.move += unit.accMove;
	unit.jump += unit.accJump;
}

void quickStartName( Player &unit, vector<string> unitVec )
{
	int tempInt = 0;
	int secInt = 0;
	string tempString = "";


	int i = 41;
	for( i = 41; i < 46; i++ )
	{
		if( i > 42 && unitVec[i] == "0" )
			break;
		tempString += unitVec[i];
	}
	
	unit.playerName = "";
	unit.playerName.append( tempString );

}

void quickStartPosition( Player &unit, vector<string> unitVec )
{
	//starting position
	string tempChar1 = unitVec[39];
	string tempChar2 = unitVec[40];

	unit.currentRow = atoi( tempChar1.c_str() );
	unit.currentCol = atoi( tempChar2.c_str() );

}

//to do:
	//special quick start generator based on level & sex
	//if confirm is no on player details, subtract equipment stats
		//maybe just use equipment destroyers
//dupicate the reaction, support, movement transfer from ability select

void quickStartFunctionBlue1( Player &unit )
{
	vector<string> unitVec (50, "0" );
	string unitCode = "";
	int i = 0;
	string tempString = "";
	int tempInt = 0;
	int secInt = 0;

	ifstream source("blue1.txt");
	source >> unitCode;
	
	//print out for code... for testing
	for( i = 0; i < unitCode.length(); i++ )
	{
		unitVec[i] = unitCode[i];
		unit.quickCode += unitCode[i];
	}
	
	quickStartSex( unit, unitVec ); //0
	quickStartZodiac( unit, unitVec ); //1-2
	quickStartBrave( unit, unitVec ); //3-4
	quickStartFaith( unit, unitVec ); //5-6
	quickStartLevel( unit, unitVec ); //7-8
	quickStartClass( unit, unitVec ); //9-10
	
	quickStartClassBuilder( unit ); //builds the unit

	quickStartSecondary( unit, unitVec ); //11-12
	quickStartReaction( unit, unitVec ); //13-14
	quickStartSupport( unit, unitVec ); //15-16
	quickStartMovement( unit, unitVec ); //17 18
	quickStartWeapon( unit, unitVec ); // 19 20 21 22
	quickStartOffHand( unit, unitVec ); // 23 24 25 26 
	quickStartHead( unit, unitVec ); // 27 28 29 30 
	quickStartBody( unit, unitVec ); // 31 32 33 34
	quickStartAcc( unit, unitVec ); //35 36 37 38
	quickStartPosition( unit, unitVec ); //39 40
	quickStartName( unit, unitVec ); //41 42 43 44 45
	
	
}

void quickStartFunctionRed1( Player &unit )
{
	vector<string> unitVec (50, "0" );
	string unitCode = "";
	int i = 0;
	string tempString = "";
	int tempInt = 0;
	int secInt = 0;

	ifstream source("red1.txt");
	source >> unitCode;
	
	//print out for code... for testing
	for( i = 0; i < unitCode.length(); i++ )
	{
		unitVec[i] = unitCode[i];
		unit.quickCode += unitCode[i];
	}
	
	quickStartSex( unit, unitVec ); //0
	quickStartZodiac( unit, unitVec ); //1-2
	quickStartBrave( unit, unitVec ); //3-4
	quickStartFaith( unit, unitVec ); //5-6
	quickStartLevel( unit, unitVec ); //7-8
	quickStartClass( unit, unitVec ); //9-10
	
	quickStartClassBuilder( unit ); //builds the unit

	quickStartSecondary( unit, unitVec ); //11-12
	quickStartReaction( unit, unitVec ); //13-14
	quickStartSupport( unit, unitVec ); //15-16
	quickStartMovement( unit, unitVec ); //17 18
	quickStartWeapon( unit, unitVec ); // 19 20 21 22
	quickStartOffHand( unit, unitVec ); // 23 24 25 26 
	quickStartHead( unit, unitVec ); // 27 28 29 30 
	quickStartBody( unit, unitVec ); // 31 32 33 34
	quickStartAcc( unit, unitVec ); //35 36 37 38
	quickStartPosition( unit, unitVec ); //39 40
	quickStartName( unit, unitVec ); //41 42 43 44 45
	
	
}

void quickStartFunctionRed2( Player &unit )
{
	vector<string> unitVec (50, "0" );
	string unitCode = "";
	int i = 0;
	string tempString = "";
	int tempInt = 0;
	int secInt = 0;

	ifstream source("red2.txt");
	source >> unitCode;
	
	//print out for code... for testing
	for( i = 0; i < unitCode.length(); i++ )
	{
		unitVec[i] = unitCode[i];
		unit.quickCode += unitCode[i];
	}
	
	quickStartSex( unit, unitVec ); //0
	quickStartZodiac( unit, unitVec ); //1-2
	quickStartBrave( unit, unitVec ); //3-4
	quickStartFaith( unit, unitVec ); //5-6
	quickStartLevel( unit, unitVec ); //7-8
	quickStartClass( unit, unitVec ); //9-10
	
	quickStartClassBuilder( unit ); //builds the unit

	quickStartSecondary( unit, unitVec ); //11-12
	quickStartReaction( unit, unitVec ); //13-14
	quickStartSupport( unit, unitVec ); //15-16
	quickStartMovement( unit, unitVec ); //17 18
	quickStartWeapon( unit, unitVec ); // 19 20 21 22
	quickStartOffHand( unit, unitVec ); // 23 24 25 26 
	quickStartHead( unit, unitVec ); // 27 28 29 30 
	quickStartBody( unit, unitVec ); // 31 32 33 34
	quickStartAcc( unit, unitVec ); //35 36 37 38
	quickStartPosition( unit, unitVec ); //39 40
	quickStartName( unit, unitVec ); //41 42 43 44 45
	
	
}

void quickStartFunctionBlue2( Player &unit )
{
	vector<string> unitVec (50, "0" );
	string unitCode = "";
	int i = 0;
	string tempString = "";
	int tempInt = 0;
	int secInt = 0;

	ifstream source("blue2.txt");
	source >> unitCode;
	
	//print out for code... for testing
	for( i = 0; i < unitCode.length(); i++ )
	{
		unitVec[i] = unitCode[i];
		unit.quickCode += unitCode[i];
	}
	
	quickStartSex( unit, unitVec ); //0
	quickStartZodiac( unit, unitVec ); //1-2
	quickStartBrave( unit, unitVec ); //3-4
	quickStartFaith( unit, unitVec ); //5-6
	quickStartLevel( unit, unitVec ); //7-8
	quickStartClass( unit, unitVec ); //9-10
	
	quickStartClassBuilder( unit ); //builds the unit

	quickStartSecondary( unit, unitVec ); //11-12
	quickStartReaction( unit, unitVec ); //13-14
	quickStartSupport( unit, unitVec ); //15-16
	quickStartMovement( unit, unitVec ); //17 18
	quickStartWeapon( unit, unitVec ); // 19 20 21 22
	quickStartOffHand( unit, unitVec ); // 23 24 25 26 
	quickStartHead( unit, unitVec ); // 27 28 29 30 
	quickStartBody( unit, unitVec ); // 31 32 33 34
	quickStartAcc( unit, unitVec ); //35 36 37 38
	quickStartPosition( unit, unitVec ); //39 40
	quickStartName( unit, unitVec ); //41 42 43 44 45
	
	
}

//quick start confirm display
int innerCharacterSetUp( Player unit, int setUpChar )
{
	cout << " --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " --- Sex: " << unit.sex << "  Map Symbol: " << unit.mapSymbol << "  Zodiac: " << unit.zodiac << "\n"
		<< "\tABILITIES" << setw(35) << "EQUIPMENT\n"
		<< setw(11) << "Primary: " << setw(14) << unit.playerClassName << setw(22) << "Weapon: " << unit.weaponName << "\n"
		<< setw(11) << "Secondary: " << setw(14) << unit.secondary << setw(22) << "Off-Hand: " << unit.offHandName << "\n"
		<< setw(11) << "Reaction: " << setw(14)  << unit.reaction << setw(22) << "Helmet: " << unit.headName << "\n"
		<< setw(11) << "Support: " << setw(14)  << unit.support << setw(22) << "Armor: " << unit.bodyName << "\n"
		<< setw(11) << "Movement: " << setw(14)  << unit.movement << setw(22) << "Accessory: " << unit.accName << "\n"
		<< "\tSTATS\n"
		<< "Life: " << unit.life << "/" << unit.maxLife << setw(10) << "MP: " << unit.mp << "/" << unit.maxMP  << setw(10) << "CT: " << unit.ct << '\n'
		<< "Move: " << unit.move << setw(16) << "Jump: " << unit.jump << setw(15) << "Speed: " << unit.speed << setw(15) << "Level: " << unit.level << '\n'
		<< "Phy Att: " << unit.pa << setw(18) << "Magic Att: " << unit.ma  << setw(15) << "Brave: " << unit.brave  << setw(15) << "Faith: " << unit.faith << '\n'
		<< "Weap Power: " << unit.weaponPower << setw(10) << "Type: "<< unit.weaponType  << setw(20) << "Off-Hand Type: " << unit.offHandType << '\n'
		<< "Class Ev: " << unit.cEvade << setw(13) << "Wp-Ev: " << unit.weaponEvade  << setw(25) << "Shield P-Ev: " << unit.offHandPhyEvade << '\n'
		<< "Shield M-Ev: " << unit.offHandMagEvade  << setw(13) << "Acc P-Ev: " << unit.accPhyEvade << setw(20) << "Acc M-Ev: " << unit.accMagEvade << "\n"
		//<< "Quick Start Code: " << unit.quickCode << '\n' 
		<< "\n";
	setUpChar = confirmFunction( setUpChar );
	return setUpChar;
}


//have to create on of these for each unit due to source
int characterSetUp( Player &unit, int setUpChar )
{

	if( setUpChar == 1 )
	{
		selectSex( unit );
		selectClass( unit );
		abilitySelect( unit );
		equipmentSelect( unit );
		setUpChar = innerCharacterSetUp( unit, setUpChar );
		return setUpChar;
	}
	else if( setUpChar == 2 && unit.turnOrder == 1 )
	{
		quickStartFunctionBlue1( unit );
		setUpChar = innerCharacterSetUp( unit, setUpChar );
	}
	else if( setUpChar == 2 && unit.turnOrder == 2 )
	{
		quickStartFunctionRed1( unit );
		setUpChar = innerCharacterSetUp( unit, setUpChar );
	}
	else if( setUpChar == 2 && unit.turnOrder == 3 )
	{
		quickStartFunctionRed2( unit );
		setUpChar = innerCharacterSetUp( unit, setUpChar );
	}
	else if( setUpChar == 2 && unit.turnOrder == 4 )
	{
		quickStartFunctionBlue2( unit );
		setUpChar = innerCharacterSetUp( unit, setUpChar );
	}
	
	return setUpChar;
}