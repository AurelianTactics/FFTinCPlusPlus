//need to make confirm menu and have values default if goes back to no

class Reaction
{
public:
	string reactionName;
	bool abandon;
	bool weaponGuard;
	bool aSave;
	bool autoPotion;
	bool caution;
	bool damageSplit;
	bool gilgameHeart;
	bool maSave;
	bool regenerator;
	bool speedSave;
	bool bladeGrasp;
	bool braveUp;
	bool counter;
	bool counterTackle;
	bool dragonSpirit;
	bool sunkenState;
	bool criticalQuick;
	bool hpRestore;
	bool meatboneSlash;
	bool mpRestore;
	bool absorbUsedMP;
	bool arrowGuard;
	bool reactionCatch;
	bool counterFlood;
	bool counterMagic;
	bool distribute;
	bool faceUp;
	bool fingerGuard;
	bool hamedo;
	bool mpSwitch;
	bool reactionReflect; //gameshare only ability

	Reaction()
	{
		reactionName = "";
		abandon = false;
		weaponGuard = false;
		aSave = false;
		autoPotion = false;
		caution = false;
		damageSplit = false;
		gilgameHeart = false;
		maSave = false;
		regenerator = false;
		speedSave = false;
		bladeGrasp = false;
		braveUp = false;
		counter = false;
		counterTackle = false;
		dragonSpirit = false;
		sunkenState = false;
		criticalQuick = false;
		hpRestore = false;
		meatboneSlash = false;
		mpRestore = false;
		absorbUsedMP = false;
		arrowGuard = false;
		reactionCatch = false;
		counterFlood = false;
		counterMagic = false;
		distribute = false;
		faceUp = false;
		fingerGuard = false;
		hamedo = false;
		mpSwitch = false;
		reactionReflect = false;
	}
	~Reaction(){}

	void reactionSelect( Reaction & robj, Player unit );
};

void Reaction::reactionSelect( Reaction & robj, Player unit )
{
	reactionName = "NONE";
	abandon = false;
	weaponGuard = false;
	aSave = false;
	autoPotion = false;
	caution = false;
	damageSplit = false;
	gilgameHeart = false;
	maSave = false;
	regenerator = false;
	speedSave = false;
	bladeGrasp = false;
	braveUp = false;
	counter = false;
	counterTackle = false;
	dragonSpirit = false;
	sunkenState = false;
	criticalQuick = false;
	hpRestore = false;
	meatboneSlash = false;
	mpRestore = false;
	absorbUsedMP = false;
	arrowGuard = false;
	reactionCatch = false;
	counterFlood = false;
	counterMagic = false;
	distribute = false;
	faceUp = false;
	fingerGuard = false;
	hamedo = false;
	mpSwitch = false;
	reactionReflect = false;

	int reactionSelect = 0;
	while( (cout << "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " select Reaction Ability ---\n"
		<< "\n"
		<< " 0.) None                " << " 1.) A Save              " << " 2.) Abandon\n" 
		<< " 3.) Absorb Used MP      " << " 4.) Arrow Guard         " << " 5.) Auto Potion\n" 
		<< " 6.) Blade Grasp         " << " 7.) Brave Up            " << " 8.) Catch\n" 
		<< " 9.) Caution             " << "10.) Counter             " << "11.) Counter Flood \n" 
		<< "12.) Counter Magic       " << "13.) Counter Tackle      " << "14.) Critical Quick \n" 
		<< "15.) Damage Split        " << "16.) Distribute          "  << "17.) Dragon Spirit\n" 
		<< "18.) Face Up             " << "19.) Finger Guard        "  << "20.) Hamedo \n" 
		<< "21.) HP Restore          " << "22.) MA Save             " << "23.) Meatbone Slash \n" 
		<< "24.) MP Restore          " << "25.) MP Switch           "  << "26.) Regenerator\n" 
		<< "27.) Speed Save          " << "28.) Sunken State        "  << "29.) Weapon Guard\n" 
		) 
		&& ( !(cin >> reactionSelect) || reactionSelect < 0 || reactionSelect > 29 ) )
		{
			cout << "Enter a valid integer.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	if( reactionSelect == 0)
	{
		reactionName = "NONE";
		abandon = false;
		weaponGuard = false;
		aSave = false;
		autoPotion = false;
		caution = false;
		damageSplit = false;
		gilgameHeart = false;
		maSave = false;
		regenerator = false;
		speedSave = false;
		bladeGrasp = false;
		braveUp = false;
		counter = false;
		counterTackle = false;
		dragonSpirit = false;
		sunkenState = false;
		criticalQuick = false;
		hpRestore = false;
		meatboneSlash = false;
		mpRestore = false;
		absorbUsedMP = false;
		arrowGuard = false;
		reactionCatch = false;
		counterFlood = false;
		counterMagic = false;
		distribute = false;
		faceUp = false;
		fingerGuard = false;
		hamedo = false;
		mpSwitch = false;
		reactionReflect = false;
	}
	else if( reactionSelect == 1 )
	{
		reactionName = "A Save";
		aSave = true;
	}
	else if( reactionSelect == 2 )
	{
		reactionName = "Abandon";
		abandon = true;
	}
	else if( reactionSelect == 3 )
	{
		reactionName = "Absorb Used MP";
		absorbUsedMP = true;
	}
	else if( reactionSelect == 4)
	{
		reactionName = "Arrow Guard";
		abandon = false;
		weaponGuard = false;
		aSave = false;
		autoPotion = false;
		caution = false;
		damageSplit = false;
		gilgameHeart = false;
		maSave = false;
		regenerator = false;
		speedSave = false;
		bladeGrasp = false;
		braveUp = false;
		counter = false;
		counterTackle = false;
		dragonSpirit = false;
		sunkenState = false;
		criticalQuick = false;
		hpRestore = false;
		meatboneSlash = false;
		mpRestore = false;
		absorbUsedMP = false;
		arrowGuard = true;
		reactionCatch = false;
		counterFlood = false;
		counterMagic = false;
		distribute = false;
		faceUp = false;
		fingerGuard = false;
		hamedo = false;
		mpSwitch = false;
		reactionReflect = false;
	}
	else if( reactionSelect == 5 )
	{
		reactionName = "Auto Potion";
		abandon = false;
		absorbUsedMP = false;
		arrowGuard = false;
		aSave = false;
		autoPotion = true;
		bladeGrasp = false;
		braveUp = false;
		caution = false;
		counter = false;
		counterFlood = false;
		counterMagic = false;
		counterTackle = false;
		criticalQuick = false;
		damageSplit = false;
		distribute = false;
		dragonSpirit = false;
		faceUp = false;
		fingerGuard = false;
		gilgameHeart = false;
		hamedo = false;
		hpRestore = false;
		maSave = false;
		meatboneSlash = false;
		mpRestore = false;
		mpSwitch = false;
		reactionCatch = false;
		reactionReflect = false;
		regenerator = false;
		speedSave = false;
		sunkenState = false;
		weaponGuard = false;
	}
	else if( reactionSelect == 6 )
	{
		reactionName = "Blade Grasp";
		bladeGrasp = true;
	}
	else if( reactionSelect == 7 )
	{
		reactionName = "Brave Up";
		braveUp = true;
	}
	else if( reactionSelect == 8 )
	{
		reactionName = "Catch";
		abandon = false;
		absorbUsedMP = false;
		arrowGuard = false;
		aSave = false;
		autoPotion = false;
		bladeGrasp = false;
		braveUp = false;
		caution = false;
		counter = false;
		counterFlood = false;
		counterMagic = false;
		counterTackle = false;
		criticalQuick = false;
		damageSplit = false;
		distribute = false;
		dragonSpirit = false;
		faceUp = false;
		fingerGuard = false;
		gilgameHeart = false;
		hamedo = false;
		hpRestore = false;
		maSave = false;
		meatboneSlash = false;
		mpRestore = false;
		mpSwitch = false;
		reactionCatch = true;
		reactionReflect = false;
		regenerator = false;
		speedSave = false;
		sunkenState = false;
		weaponGuard = false;
	}
	else if( reactionSelect == 9 )
	{
		reactionName = "Caution";
		abandon = false;
		absorbUsedMP = false;
		arrowGuard = false;
		aSave = false;
		autoPotion = false;
		bladeGrasp = false;
		braveUp = false;
		caution = true;
		counter = false;
		counterFlood = false;
		counterMagic = false;
		counterTackle = false;
		criticalQuick = false;
		damageSplit = false;
		distribute = false;
		dragonSpirit = false;
		faceUp = false;
		fingerGuard = false;
		gilgameHeart = false;
		hamedo = false;
		hpRestore = false;
		maSave = false;
		meatboneSlash = false;
		mpRestore = false;
		mpSwitch = false;
		reactionCatch = false;
		reactionReflect = false;
		regenerator = false;
		speedSave = false;
		sunkenState = false;
		weaponGuard = false;
	}
	else if( reactionSelect == 10 )
	{
		reactionName = "Counter";
		counter = true;
	}
	else if( reactionSelect == 11 )
	{
		reactionName = "Counter Flood";
		counterFlood = true;
	}
	else if( reactionSelect == 12 )
	{
		reactionName = "Counter Magic";
		counterMagic = true;
	}
	else if( reactionSelect == 13 )
	{
		reactionName = "Counter Tackle";
		abandon = false;
		absorbUsedMP = false;
		arrowGuard = false;
		aSave = false;
		autoPotion = false;
		bladeGrasp = false;
		braveUp = false;
		caution = false;
		counter = false;
		counterFlood = false;
		counterMagic = false;
		counterTackle = true;
		criticalQuick = false;
		damageSplit = false;
		distribute = false;
		dragonSpirit = false;
		faceUp = false;
		fingerGuard = false;
		gilgameHeart = false;
		hamedo = false;
		hpRestore = false;
		maSave = false;
		meatboneSlash = false;
		mpRestore = false;
		mpSwitch = false;
		reactionCatch = false;
		reactionReflect = false;
		regenerator = false;
		speedSave = false;
		sunkenState = false;
		weaponGuard = false;
	}
	else if( reactionSelect == 14 )
	{
		reactionName = "Critical Quick";
		criticalQuick = true;
	}
	else if( reactionSelect == 15 )
	{
		reactionName = "Damage Split";
		damageSplit = true;
	}
	else if( reactionSelect == 16 )
	{
		reactionName = "Distribute";
		distribute = true;
	}
	else if( reactionSelect == 17 )
	{
		reactionName = "Dragon Spirit";
		dragonSpirit = true;
	}
	else if( reactionSelect == 18 )
	{
		reactionName = "Face Up";
		faceUp = true;
	}
	else if( reactionSelect == 19 )
	{
		reactionName = "Finger Guard";
		fingerGuard = true;
	}
	else if( reactionSelect == 20 )
	{
		reactionName = "Hamedo";
		hamedo = true;
	}
	else if( reactionSelect == 21 )
	{
		reactionName = "HP Restore";
		hpRestore = true;
	}
	else if( reactionSelect == 22 )
	{
		reactionName = "MA Save";
		maSave = true;
	}
	else if( reactionSelect == 23 )
	{
		reactionName = "Meatbone Slash";
		meatboneSlash = true;
	}
	else if( reactionSelect == 24 )
	{
		reactionName = "MP Restore";
		mpRestore = true;
	}
	else if( reactionSelect == 25 )
	{
		reactionName = "MP Switch";
		mpSwitch = true;
	}
	else if( reactionSelect == 26 )
	{
		reactionName = "Regenerator";
		regenerator = true;
	}
	else if( reactionSelect == 27 )
	{
		reactionName = "Speed Save";
		abandon = false;
		absorbUsedMP = false;
		arrowGuard = false;
		aSave = false;
		autoPotion = false;
		bladeGrasp = false;
		braveUp = false;
		caution = false;
		counter = false;
		counterFlood = false;
		counterMagic = false;
		counterTackle = false;
		criticalQuick = false;
		damageSplit = false;
		distribute = false;
		dragonSpirit = false;
		faceUp = false;
		fingerGuard = false;
		gilgameHeart = false;
		hamedo = false;
		hpRestore = false;
		maSave = false;
		meatboneSlash = false;
		mpRestore = false;
		mpSwitch = false;
		reactionCatch = false;
		reactionReflect = false;
		regenerator = false;
		speedSave = true;
		sunkenState = false;
		weaponGuard = false;
	}
	else if( reactionSelect == 28 )
	{
		reactionName = "Sunken State";
		sunkenState = true;
	}
	else if( reactionSelect == 29)
	{
		reactionName = "Weapon Guard";
		abandon = false;
		absorbUsedMP = false;
		arrowGuard = false;
		aSave = false;
		autoPotion = false;
		bladeGrasp = false;
		braveUp = false;
		caution = false;
		counter = false;
		counterFlood = false;
		counterMagic = false;
		counterTackle = false;
		criticalQuick = false;
		damageSplit = false;
		distribute = false;
		dragonSpirit = false;
		faceUp = false;
		fingerGuard = false;
		gilgameHeart = false;
		hamedo = false;
		hpRestore = false;
		maSave = false;
		meatboneSlash = false;
		mpRestore = false;
		mpSwitch = false;
		reactionCatch = false;
		reactionReflect = false;
		regenerator = false;
		speedSave = false;
		sunkenState = false;
		weaponGuard = true;
	}
}

class Support
{
public:
	string supportName;
	bool attackUp;
	bool concentrate;
	bool defend;
	bool defenseUp;
	bool equipArmor;
	bool equipAxe;
	bool equipChange; //ugg...
	bool equipCrossbow;
	bool equipGun;
	bool equipKnife;
	bool equipShield;
	bool equipSpear;
	bool equipSword;
	bool halfOfMP;
	bool magicAttackUp;
	bool magicDefendUp;
	bool maintenance;
	bool martialArts;
	bool monsterSkill;
	bool monsterTalk;
	bool nonCharge;
	bool secretHunt;
	bool shortCharge;
	bool throwItem;
	bool train;
	bool twoHands;
	bool twoSwords;

	//temp values that will transfer what can be equipped to player class
	bool armorTemp;
	bool axeTemp;
	bool crossbowTemp;
	bool gunTemp;
	bool katanaTemp;
	bool knifeTemp;
	bool shieldTemp;
	bool spearTemp;
	bool swordTemp;


	Support()
	{
		supportName = "";
		attackUp = false;
		concentrate = false;
		defend = false;
		defenseUp = false;
		equipArmor = false;
		equipAxe = false;
		equipChange = false; //ugg...
		equipCrossbow = false;
		equipGun = false;
		equipKnife = false;
		equipShield = false;
		equipSpear = false;
		equipSword = false;
		halfOfMP = false;
		magicAttackUp = false;
		magicDefendUp = false;
		maintenance = false;
		martialArts = false;
		monsterSkill = false;
		monsterTalk = false;
		nonCharge = false;
		secretHunt = false;
		shortCharge = false;
		throwItem = false;
		train = false;
		twoHands = false;
		twoSwords = false;

		armorTemp = false;
		axeTemp = false;
		crossbowTemp = false;
		gunTemp = false;
		katanaTemp = false;
		shieldTemp = false;
		spearTemp = false;
		swordTemp = false;
	}

	~Support(){}

	void supportSelect( Support &sup, Player unit);

};

void Support::supportSelect( Support &sup, Player unit)
{
	supportName = "NONE";
		attackUp = false;
		concentrate = false;
		defend = false;
		defenseUp = false;
		equipArmor = false;
		equipAxe = false;
		equipChange = false;
		equipCrossbow = false;
		equipGun = false;
		equipKnife = false;
		equipShield = false;
		equipSpear = false;
		equipSword = false;
		halfOfMP = false;
		magicAttackUp = false;
		magicDefendUp = false;
		maintenance = false;
		martialArts = false;
		monsterSkill = false;
		monsterTalk = false;
		nonCharge = false;
		secretHunt = false;
		shortCharge = false;
		throwItem = false;
		train = false;
		twoHands = false;
		twoSwords = false;

		armorTemp = false;
		axeTemp = false;
		crossbowTemp = false;
		gunTemp = false;
		katanaTemp = false;
		knifeTemp = false;
		shieldTemp = false;
		spearTemp = false;
		swordTemp = false;

	int supportSelect = 40;
	while( (cout << "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " select Support Ability ---\n"
		<< "\n"
		<< " 0.) None                " << " 1.) Attack UP           " << " 2.) Concentrate\n"
		<< " 3.) Defend              " << " 4.) Defense UP          " << " 5.) Equip Armor\n"
		<< " 6.) Equip Axe           " << " 7.) Equip Crossbow      " << " 8.) Equip Gun\n" 
		<< " 9.) Equip Knife         " << "10.) Equip Shield        " << "11.) Equip Spear\n"
		<< "12.) Equip Sword         " << "13.) Half of MP          " << "14.) Magic AttackUP \n"
		<< "15.) Maintenance         " << "16.) Martial Arts        " << "17.) Monster Skill\n"
		<< "18.) Monster Talk        " << "19.) Short Charge        " << "20.) Throw Item\n"
		<< "21.) Train               " << "22.) Two Hands           " << "23.) Two Swords\n"
		<< "24.) Magic DefendUP      " << "25.) Equip Change\n"
		) 
		&& ( !(cin >> supportSelect) || supportSelect < 0 || supportSelect > 25
		|| ( unit.throwItem == true && supportSelect == 20 )
		|| ( unit.equipArmor == true && supportSelect == 5 )
		|| ( unit.equipAxe == true && supportSelect == 6 )
		|| ( unit.equipCrossbow == true && supportSelect == 7 )
		|| ( unit.equipGun == true && supportSelect == 8 )
		|| ( unit.equipKnife == true && supportSelect == 9 )
		|| ( unit.equipShield == true && supportSelect == 10 )
		|| ( unit.equipSpear == true && supportSelect == 11 )
		|| ( unit.monsterTalk == true && supportSelect == 18 )
		|| ( unit.twoSwords == true && supportSelect == 23 )
		|| ( unit.equipSword == true && supportSelect == 12 ) ) )
		{
			cout << "Enter a valid integer.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	if( supportSelect == 0)
	{
		supportName = "NONE";
		attackUp = false;
		concentrate = false;
		defend = false;
		defenseUp = false;
		equipArmor = false;
		equipAxe = false;
		equipChange = false;
		equipCrossbow = false;
		equipGun = false;
		equipKnife = false;
		equipShield = false;
		equipSpear = false;
		equipSword = false;
		halfOfMP = false;
		magicAttackUp = false;
		magicDefendUp = false;
		maintenance = false;
		martialArts = false;
		monsterSkill = false;
		monsterTalk = false;
		nonCharge = false;
		secretHunt = false;
		shortCharge = false;
		throwItem = false;
		train = false;
		twoHands = false;
		twoSwords = false;

		armorTemp = false;
		axeTemp = false;
		crossbowTemp = false;
		gunTemp = false;
		knifeTemp = false;
		katanaTemp = false;
		shieldTemp = false;
		spearTemp = false;
		swordTemp = false;
	}
	else if( supportSelect == 1)
	{
		supportName = "Attack UP";
		attackUp = true;
	}
	else if( supportSelect == 2)
	{
		supportName = "Concentrate";
		concentrate = true;
	}
	else if( supportSelect == 3)
	{
		supportName = "Defend";
		defend = true;
	}
	else if( supportSelect == 4)
	{
		supportName = "Defense UP";
		defenseUp = true;
	}
	else if( supportSelect == 5)
	{
		supportName = "Equip Armor";
		equipArmor = true;
		armorTemp = true;
	}
	else if( supportSelect == 6)
	{
		supportName = "Equip Axe";
		equipAxe = true;
		axeTemp = true;
	}
	else if( supportSelect == 7)
	{
		supportName = "Equip Crossbow";
		equipCrossbow = true;
		crossbowTemp = true;
	}
	else if( supportSelect == 8)
	{
		supportName = "Equip Gun";
		equipGun = true;
		gunTemp = true;
	}
	else if( supportSelect == 9)
	{
		supportName = "Equip Knife";
		equipKnife = true;
		knifeTemp = true;
	}
	else if( supportSelect == 10)
	{
		supportName = "Equip Shield";
		equipShield = true;
		shieldTemp = true;
	}
	else if( supportSelect == 11)
	{
		supportName = "Equip Spear";
		equipSpear = true;
		spearTemp = true;
	}
	else if( supportSelect == 12)
	{
		supportName = "Equip Sword";
		equipSword = true;
		swordTemp = true;
	}
	else if( supportSelect == 13)
	{
		supportName = "Half of MP";
		halfOfMP = true;
	}
	else if( supportSelect == 14)
	{
		supportName = "Magic AttackUP";
		magicAttackUp = true;
	}
	else if( supportSelect == 15)
	{
		supportName = "Maintenance";
		maintenance = true;
	}
	else if( supportSelect == 16)
	{
		supportName = "Martial Arts";
		martialArts = true;
	}
	else if( supportSelect == 17)
	{
		supportName = "Monster Skill";
		monsterSkill = true;
	}
	else if( supportSelect == 18)
	{
		supportName = "Monster Talk";
		monsterTalk = true;
	}
	else if( supportSelect == 19)
	{
		supportName = "Short Charge";
		shortCharge = true;
	}
	else if( supportSelect == 20)
	{
		supportName = "Throw Item";
		throwItem = true;
	}
	else if( supportSelect == 21 )
	{
		supportName = "Train";
		train = true;
	}
	else if( supportSelect == 22)
	{
		supportName = "Two Hands";
		twoHands = true;
	}
	else if( supportSelect == 23 )
	{
		supportName = "Two Swords";
		twoSwords = true;
	}
	else if( supportSelect == 24 )
	{
		supportName = "Magic DefendUP";
		magicDefendUp = true;
	}
	else if( supportSelect == 25 )
	{
		supportName = "Equip Change";
		equipChange = true;
	}
}

class Movement
{

public:
	string moveAbilityName;
	int move;
	int jump;
	bool floatStatus;
	bool fly;
	bool teleport;
	bool teleport2;
	bool moveHP;
	bool moveMP;
	bool moveLava;
	bool anyGround;
	bool moveInWater;
	bool anyWeather;
	bool ignoreHeight;
	bool walkOnWater;

	Movement()
	{
		moveAbilityName = "";
		move = 0;
		jump = 0;
		floatStatus = false;
		fly = false;
		ignoreHeight = false;
		teleport = false;
		teleport2 = false;
		moveHP = false;
		moveMP = false;
		moveLava = false;
		anyGround = false;
		moveInWater = false;
		anyWeather = false;
		walkOnWater = false;
	}

	~Movement() {}

	void movementSelect(Movement &moveChoice, Player unit);
};

void Movement::movementSelect(Movement &moveChoice, Player unit)
{
	moveAbilityName = "NONE";
	move = 0;
	jump = 0;
	floatStatus = false;
	fly = false;
	ignoreHeight = false;
	teleport = false;
	teleport2 = false;
	moveHP = false;
	moveMP = false;
	moveLava = false;
	anyGround = false;
	moveInWater = false;
	anyWeather = false;
	walkOnWater = false;

	int moveSelect = 40;
	while( (cout << "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " select Movement Ability ---\n"
		<< "\n"
		<< " 0.) None                " << " 1.) Any Ground          " << " 2.) Any Weather\n" 
		<< " 3.) Float               " << " 4.) Fly                 " << " 5.) Ignore Height\n" 
		<< " 6.) Jump +1             " << " 7.) Jump +2             " << " 8.) Jump +3\n" 
		<< " 9.) Move +1             " << "10.) Move +2             " << "11.) Move +3\n" 
		<< "12.) Move-HP Up          " << "13.) Move-MP Up          " << "14.) Move on Lava\n" 
		<< "15.) Move in Water       " << "16.) Teleport            " << "17.) Walk on Water\n" 
		) 
		&& ( !(cin >> moveSelect) || moveSelect < 0 || moveSelect > 18 ) )
		{
			cout << "Enter a valid integer.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( moveSelect == 0 ) //none
		{
			moveAbilityName = "NONE";
			move = 0;
			jump = 0;
			floatStatus = false;
			fly = false;
			ignoreHeight = false;
			teleport = false;
			teleport2 = false;
			moveHP = false;
			moveMP = false;
			moveLava = false;
			anyGround = false;
			moveInWater = false;
			anyWeather = false;
			walkOnWater = false;
		}
		else if( moveSelect == 1 ) //Move +1
		{
			moveAbilityName = "Any Ground";
			anyGround = true;
		}
		else if( moveSelect == 2 ) 
		{
			moveAbilityName = "Any Weather";
			anyWeather = true;
		}
		else if( moveSelect == 3 ) //none
		{
			moveAbilityName = "Float";
			floatStatus = true;
		}
		else if( moveSelect == 4 ) //none
		{
			moveAbilityName = "Fly";
			fly = true;
		}
		else if( moveSelect == 5 ) //none
		{
			moveAbilityName = "Ignore Height";
			ignoreHeight = true;
		}
		else if( moveSelect == 6 ) //none
		{
			moveAbilityName = "Jump +1";
			jump = 1;
		}
		else if( moveSelect == 7 ) //none
		{
			moveAbilityName = "Jump +2";
			jump = 2;
		}
		else if( moveSelect == 8 ) //none
		{
			moveAbilityName = "Jump +3";
			jump = 3;
		}
		else if( moveSelect == 9 ) //none
		{
			moveAbilityName = "Move +1";
			move = 1;
		}
		else if( moveSelect == 10 ) //none
		{
			moveAbilityName = "Move +2";
			move = 2;
		}
		else if( moveSelect == 11 ) //none
		{
			moveAbilityName = "Move +3";
			move = 3;
		}
		else if( moveSelect == 12 ) //none
		{
			moveAbilityName = "Move-HP Up";
			moveHP = true;
		}
		else if( moveSelect == 13 ) //none
		{
			moveAbilityName = "Move-MP Up";
			moveMP = true;
		}
		else if( moveSelect == 14 ) //none
		{
			moveAbilityName = "Move on Lava";
			moveLava = true;
		}
		else if( moveSelect == 15 ) //none
		{
			moveAbilityName = "Move in Water";
			moveInWater = true;
		}
		else if( moveSelect == 16 ) //none
		{
			moveAbilityName = "Teleport";
			teleport = true;
		}
		else if( moveSelect == 17 ) //none
		{
			moveAbilityName = "Walk on Water";
			walkOnWater = true;
		}
		else if( moveSelect == 18 ) //none
		{
			moveAbilityName = "Teleport 2";
			move = 50;
		}
}





