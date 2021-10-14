//jobs, 1 Chemist, 2 Knight, 3 archer, 4 squire, 5 thief, 6 ninja, 7 monk,
	//8 priest, 9 wizard, 10 time mage, 11 summoner, 12 mediator, 13 oracle,
	//14 geomancer, 15 lancer, 16 samurai, 17 calculator, 18 bard, 19 dancer, 20 mime

//zouf charts show HP is off by a bit on male chemist, PA off on Male mime lvl 55

class Chemist
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Chemist() {}
	~Chemist(){}

	void chemistStats( Player &playerObject );
};

void Chemist::chemistStats( Player &playerObject )
{
	//class specific things
	playerObject.playerClass = 4;
	playerObject.playerClassName = "Chemist";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;
	playerObject.throwItem = true;

	//equipable equipment
	playerObject.knife = true;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = true;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	playerObject.lifeM = 80;
	playerObject.lifeC = 12;
	playerObject.mpM = 75;
	playerObject.mpC = 16;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 75;
	playerObject.paC = 75;
	playerObject.maM = 80;
	playerObject.maC = 50;

}

class Knight
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Knight(){}
	~Knight(){}

	void knightStats( Player &playerObject );
};

void Knight::knightStats( Player &playerObject )
{
	playerObject.playerClass = 7;
	playerObject.playerClassName = "Knight";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 10;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = true;
	playerObject.knightSword = true;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = true; //other equips
	playerObject.helmet = true;
	playerObject.hat = false;
	playerObject.ribbon = false;
	playerObject.armor = true;
	playerObject.clothes = false;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//innate support abilities
	playerObject.equipArmor = true;
	playerObject.equipShield = true;
	playerObject.equipSword = true;

	//stat growth
	playerObject.lifeM = 120;
	playerObject.lifeC = 10;
	playerObject.mpM = 80;
	playerObject.mpC = 15;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 120;
	playerObject.paC = 40;
	playerObject.maM = 80;
	playerObject.maC = 50;

}

class Archer
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Archer(){}
	~Archer(){}

	void archerStats( Player &playerObject );
};

void Archer::archerStats( Player &playerObject )
{
	playerObject.playerClass = 1;
	playerObject.playerClassName = "Archer";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 10;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = true;
	playerObject.bow = true;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//innate support abilities
	playerObject.equipCrossbow = true;

		//stat growth
	playerObject.lifeM = 100;
	playerObject.lifeC = 11;
	playerObject.mpM = 65;
	playerObject.mpC = 16;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 110;
	playerObject.paC = 45;
	playerObject.maM = 80;
	playerObject.maC = 50;

}

class Squire
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Squire(){}
	~Squire(){}

	void squireStats( Player &playerObject );
};

void Squire::squireStats( Player &playerObject )
{
	playerObject.playerClass = 16;
	playerObject.playerClassName = "Squire";
	playerObject.move = 4;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = true;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = true;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = true;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = true;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//innate support abilities
	playerObject.equipAxe = true;
	playerObject.equipSword = true;

	//stat growth
	playerObject.lifeM = 100;
	playerObject.lifeC = 11;
	playerObject.mpM = 75;
	playerObject.mpC = 15;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 90;
	playerObject.paC = 60;
	playerObject.maM = 80;
	playerObject.maC = 50;

}

class Thief
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Thief(){}
	~Thief(){}

	void thiefStats( Player &playerObject );
};

void Thief::thiefStats( Player &playerObject )
{
	playerObject.playerClass = 18;
	playerObject.playerClassName = "Thief";
	playerObject.move = 4;
	playerObject.jump = 4;
	playerObject.cEvade = 25;

	//equipable equipment
	playerObject.knife = true;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 90;
	playerObject.lifeC = 11;
	playerObject.mpM = 50;
	playerObject.mpC = 16;
	playerObject.speedM = 110;
	playerObject.speedC = 90;
	playerObject.paM = 100;
	playerObject.paC = 50;
	playerObject.maM = 60;
	playerObject.maC = 50;

}

class Ninja
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Ninja(){}
	~Ninja(){}

	void ninjaStats( Player &playerObject );
};

void Ninja::ninjaStats( Player &playerObject )
{
	playerObject.playerClass = 12;
	playerObject.playerClassName = "Ninja";
	playerObject.move = 4;
	playerObject.jump = 4;
	playerObject.cEvade = 30;

	//equipable equipment
	playerObject.knife = true;	//weapons
	playerObject.ninjaSword = true;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = true;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 70;
	playerObject.lifeC = 12;
	playerObject.mpM = 50;
	playerObject.mpC = 13;
	playerObject.speedM = 120;
	playerObject.speedC = 80;
	playerObject.paM = 120;
	playerObject.paC = 43;
	playerObject.maM = 75;
	playerObject.maC = 50;

	//innate support abilities
	playerObject.twoSwords = true;
	playerObject.offHandWeapon = true;
	playerObject.offHandType = "Bare Hands";

}

class Monk
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Monk(){}
	~Monk(){}

	void monkStats( Player &playerObject );
};

void Monk::monkStats( Player &playerObject )
{
	playerObject.playerClass = 11;
	playerObject.playerClassName = "Monk";
	playerObject.move = 3;
	playerObject.jump = 4;
	playerObject.cEvade = 20;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = false;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 135;
	playerObject.lifeC = 9;
	playerObject.mpM = 80;
	playerObject.mpC = 13;
	playerObject.speedM = 110;
	playerObject.speedC = 100;
	playerObject.paM = 129;
	playerObject.paC = 48;
	playerObject.maM = 80;
	playerObject.maC = 50;

	//innate support abilities
	playerObject.martialArts = true;

}

class Priest
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Priest(){}
	~Priest(){}

	void priestStats( Player &playerObject );
};

void Priest::priestStats( Player &playerObject )
{
	playerObject.playerClass = 14;
	playerObject.playerClassName = "Priest";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = true;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 80;
	playerObject.lifeC = 10;
	playerObject.mpM = 120;
	playerObject.mpC = 10;
	playerObject.speedM = 110;
	playerObject.speedC = 100;
	playerObject.paM = 90;
	playerObject.paC = 50;
	playerObject.maM = 110;
	playerObject.maC = 50;

	//innate support abilities

}

class Wizard
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Wizard(){}
	~Wizard(){}

	void wizardStats( Player &playerObject );
};

void Wizard::wizardStats( Player &playerObject )
{
	playerObject.playerClass = 20;
	playerObject.playerClassName = "Wizard";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = true;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 75;
	playerObject.lifeC = 12;
	playerObject.mpM = 120;
	playerObject.mpC = 9;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 60;
	playerObject.paC = 60;
	playerObject.maM = 150;
	playerObject.maC = 50;

	//innate support abilities

}

class TimeMage
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	TimeMage(){}
	~TimeMage(){}

	void TimeMageStats( Player &playerObject );
};

void TimeMage::TimeMageStats( Player &playerObject )
{
	playerObject.playerClass = 19;
	playerObject.playerClassName = "Time Mage";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = true;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 75;
	playerObject.lifeC = 12;
	playerObject.mpM = 120;
	playerObject.mpC = 10;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 50;
	playerObject.paC = 65;
	playerObject.maM = 130;
	playerObject.maC = 50;

	//innate support abilities

}

class Summoner
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Summoner(){}
	~Summoner(){}

	void summonerStats( Player &playerObject );
};

void Summoner::summonerStats( Player &playerObject )
{
	playerObject.playerClass = 17;
	playerObject.playerClassName = "Summoner";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = true;
	playerObject.staff = true;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 70;
	playerObject.lifeC = 13;
	playerObject.mpM = 125;
	playerObject.mpC = 8;
	playerObject.speedM = 90;
	playerObject.speedC = 100;
	playerObject.paM = 50;
	playerObject.paC = 70;
	playerObject.maM = 125;
	playerObject.maC = 50;

	//innate support abilities

}

class Mediator
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Mediator(){}
	~Mediator(){}

	void mediatorStats( Player &playerObject );
};

void Mediator::mediatorStats( Player &playerObject )
{
	playerObject.playerClass = 9;
	playerObject.playerClassName = "Mediator";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = true;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = true;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 80;
	playerObject.lifeC = 11;
	playerObject.mpM = 70;
	playerObject.mpC = 18;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 75;
	playerObject.paC = 55;
	playerObject.maM = 75;
	playerObject.maC = 50;

	//innate support abilities
	playerObject.equipGun = true;
	playerObject.monsterTalk = true;

}

class Oracle
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Oracle(){}
	~Oracle(){}

	void oracleStats( Player &playerObject );
};

void Oracle::oracleStats( Player &playerObject )
{
	playerObject.playerClass = 13;
	playerObject.playerClassName = "Oracle";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = true;
	playerObject.staff = true;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = true;
	playerObject.spear = false;
	playerObject.stick = true;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 75;
	playerObject.lifeC = 12;
	playerObject.mpM = 110;
	playerObject.mpC = 10;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 50;
	playerObject.paC = 60;
	playerObject.maM = 120;
	playerObject.maC = 50;

	//innate support abilities

}

class Geomancer
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Geomancer(){}
	~Geomancer(){}

	void geomancerStats( Player &playerObject );
};

void Geomancer::geomancerStats( Player &playerObject )
{
	playerObject.playerClass = 6;
	playerObject.playerClassName = "Geomancer";
	playerObject.move = 4;
	playerObject.jump = 3;
	playerObject.cEvade = 10;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = true;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = true;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = true; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 110;
	playerObject.lifeC = 10;
	playerObject.mpM = 95;
	playerObject.mpC = 11;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 110;
	playerObject.paC = 45;
	playerObject.maM = 105;
	playerObject.maC = 50;

	//innate support abilities
	playerObject.equipAxe = true;
	playerObject.equipShield = true;
	playerObject.equipSword = true;

}

class Lancer
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Lancer(){}
	~Lancer(){}

	void lancerStats( Player &playerObject );
};

void Lancer::lancerStats( Player &playerObject )
{
	playerObject.playerClass = 8;
	playerObject.playerClassName = "Lancer";
	playerObject.move = 3;
	playerObject.jump = 4;
	playerObject.cEvade = 15;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = true;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = true; //other equips
	playerObject.helmet = true;
	playerObject.hat = false;
	playerObject.ribbon = false;
	playerObject.armor = true;
	playerObject.clothes = false;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 120;
	playerObject.lifeC = 10;
	playerObject.mpM = 50;
	playerObject.mpC = 15;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 120;
	playerObject.paC = 40;
	playerObject.maM = 50;
	playerObject.maC = 50;

	//innate support abilities
	playerObject.equipArmor = true;
	playerObject.equipShield = true;
	playerObject.equipSpear = true;

}


class Samurai
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Samurai(){}
	~Samurai(){}

	void samuraiStats( Player &playerObject );
};

void Samurai::samuraiStats( Player &playerObject )
{
	playerObject.playerClass = 15;
	playerObject.playerClassName = "Samurai";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 20;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = true;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = true;
	playerObject.hat = false;
	playerObject.ribbon = false;
	playerObject.armor = true;
	playerObject.clothes = false;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 75;
	playerObject.lifeC = 12;
	playerObject.mpM = 75;
	playerObject.mpC = 14;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 128;
	playerObject.paC = 45;
	playerObject.maM = 90;
	playerObject.maC = 50;

	//innate support abilities
	playerObject.equipKnife = true;
	playerObject.equipArmor = true;

}


class Calculator
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Calculator(){}
	~Calculator(){}

	void calculatorStats( Player &playerObject );
};

void Calculator::calculatorStats( Player &playerObject )
{
	playerObject.playerClass = 3;
	playerObject.playerClassName = "Calculator";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = true;
	playerObject.spear = false;
	playerObject.stick = true;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = true;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 65;
	playerObject.lifeC = 14;
	playerObject.mpM = 80;
	playerObject.mpC = 10;
	playerObject.speedM = 50;
	playerObject.speedC = 100;
	playerObject.paM = 50;
	playerObject.paC = 70;
	playerObject.maM = 70;
	playerObject.maC = 50;

	//innate support abilities

}

class Bard
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Bard(){}
	~Bard(){}

	void bardStats( Player &playerObject );
};

void Bard::bardStats( Player &playerObject )
{
	playerObject.playerClass = 2;
	playerObject.playerClassName = "Bard";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = true;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 55;
	playerObject.lifeC = 20;
	playerObject.mpM = 50;
	playerObject.mpC = 20;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 30;
	playerObject.paC = 80;
	playerObject.maM = 115;
	playerObject.maC = 50;

	//innate support abilities

}


class Dancer
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Dancer(){}
	~Dancer(){}

	void dancerStats( Player &playerObject );
};

void Dancer::dancerStats( Player &playerObject )
{
	playerObject.playerClass = 5;
	playerObject.playerClassName = "Dancer";
	playerObject.move = 3;
	playerObject.jump = 3;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = true;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	if( playerObject.sex == "Female" )
		playerObject.bag = true;
	else playerObject.bag = false;
	playerObject.fabric = true;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = true;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = true;
	playerObject.robe = false;
	playerObject.accessoryEquip = true;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 60;
	playerObject.lifeC = 20;
	playerObject.mpM = 50;
	playerObject.mpC = 20;
	playerObject.speedM = 100;
	playerObject.speedC = 100;
	playerObject.paM = 110;
	playerObject.paC = 50;
	playerObject.maM = 95;
	playerObject.maC = 50;

	//innate support abilities

}


class Mime
{

public:
	int playerClass;
	string playerClassName;
	int move;
	int jump;
	int maxLife;
	int life;
	int magicPoints;
	int pa;
	int ma;
	int classEvade;
	int brave;
	int faith;
	int level;
	int sex; //0 for female 1 for male

	//down the line: class equips, off hand equips
	//some other things particular to the class too like throw item, two hands etc
	Mime(){}
	~Mime(){}

	void mimeStats( Player &playerObject );
};

void Mime::mimeStats( Player &playerObject )
{
	playerObject.playerClass = 10;
	playerObject.playerClassName = "Mime";
	playerObject.move = 4;
	playerObject.jump = 4;
	playerObject.cEvade = 5;

	//equipable equipment
	playerObject.knife = false;	//weapons
	playerObject.ninjaSword = false;
	playerObject.sword = false;
	playerObject.knightSword = false;
	playerObject.katana = false;
	playerObject.axe = false;
	playerObject.rod = false;
	playerObject.staff = false;
	playerObject.flail = false;
	playerObject.gun = false;
	playerObject.crossbow = false;
	playerObject.bow = false;
	playerObject.harp = false;
	playerObject.dictionary = false;
	playerObject.spear = false;
	playerObject.stick = false;
	playerObject.bag = false;
	playerObject.fabric = false;
	playerObject.shield = false; //other equips
	playerObject.helmet = false;
	playerObject.hat = false;
	playerObject.ribbon = false;
	playerObject.armor = false;
	playerObject.clothes = false;
	playerObject.robe = false;
	playerObject.accessoryEquip = false;
	playerObject.perfume = false;

	//stat growth
	playerObject.lifeM = 140;
	playerObject.lifeC = 6;
	playerObject.mpM = 50;
	playerObject.mpC = 30;
	playerObject.speedM = 120;
	playerObject.speedC = 100;
	playerObject.paM = 120;
	playerObject.paC = 35;
	playerObject.maM = 115;
	playerObject.maC = 40;

	//innate support abilities
	playerObject.concentrate = true;
	playerObject.martialArts = true;
	playerObject.monsterSkill = true;
}







