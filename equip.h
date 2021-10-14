//equipment classes


class WeaponSlot //creates weapon
{
public:
	//weapon slot
	bool weapon;
	bool weaponEffectBool;
	string weaponName;
	string weaponType;
	string weaponEffect;
	int weaponRange;
	int weaponRangeMin;
	int weaponPower;
	int weaponEvade;
	int weaponMA;
	int weaponPA;
	int weaponSpeed;
	//weapon add status 25%
	bool weaponStatusEffect; //indicator for attack function
	bool weaponDarkness;
	bool weaponSilence;
	bool weaponDeathSentence;
	bool weaponSleep;
	bool weaponDontAct;
	bool weaponDontMove;
	bool weaponFrog;
	bool weaponPetrify;
	bool weaponSlow;
	bool weaponFaith;
	bool weaponPoison;
	bool weaponConfusion;
	bool weaponCharm;
	bool weaponInnocent;
	bool weaponCancelDarkness;
	bool weaponCancelSilence;
	bool weaponCancelOil;
	bool weaponCancelFrog;
	bool weaponCancelPoison;
	bool weaponCancelStop;
	bool weaponCancelSlow;
	bool weaponCancelDontMove;
	bool weaponCancelDontAct;
	bool weaponCancelDeathSentence;
	//weapon elemental
	bool weaponWind;
	bool weaponIce;
	bool weaponLightning;
	bool weaponHolyUp;
	bool weaponFire;
	bool weaponHoly;
	bool weaponFireUp;
	bool weaponIceUp;
	bool weaponLightningUp;
	//special weapon effects
	bool weaponCastSpell;
	bool weaponLifeDrain; //damage converted to HP
	bool weaponHeal; //heals target on damage
	bool weaponIce2; //casts ice 2
	bool weaponBolt1;
	bool weaponFire1;
	bool weaponIce1;
	bool weaponFire2;
	bool weaponHolyCast;
	bool weaponMateriaBlade; //cloud subset
	bool weaponHolyAbsorb;
	//weapon add status to user
	bool weaponAutoProtect;
	bool weaponAutoHaste;
	bool weaponAutoShell;
	bool weaponAutoRegen;
	bool weaponAutoFaith;
	bool weaponStartPetrify; //start Petrified

	WeaponSlot()
	{
		//weapon slot
		weapon = false;
		weaponEffectBool= false;
		string weaponName= "";
		string weaponType= "";
		string weaponEffect= "";
		int weaponRange= 1;
		int weaponRangeMin= 1;
		int weaponPower= 0;
		int weaponEvade= 0;
		int weaponMA= 0;
		int weaponPA= 0;
		int weaponSpeed= 0;
		//weapon add status 25%
		weaponStatusEffect= false; //indicator for attack function
		weaponDarkness= false;
		weaponSilence= false;
		weaponDeathSentence= false;
		weaponSleep= false;
		weaponDontAct= false;
		weaponDontMove= false;
		weaponFrog= false;
		weaponPetrify= false;
		weaponSlow= false;
		weaponFaith= false;
		weaponPoison= false;
		weaponConfusion= false;
		weaponCharm= false;
		weaponInnocent= false;
		weaponCancelDarkness= false;
		weaponCancelSilence= false;
		weaponCancelOil= false;
		weaponCancelFrog= false;
		weaponCancelPoison= false;
		weaponCancelStop= false;
		weaponCancelSlow= false;
		weaponCancelDontMove= false;
		weaponCancelDontAct= false;
		weaponCancelDeathSentence= false;
		//weapon elemental
		weaponWind= false;
		weaponIce= false;
		weaponLightning= false;
		weaponHolyUp= false;
		weaponFire= false;
		weaponHoly= false;
		//special weapon effects
		weaponLifeDrain= false; //damage converted to HP
		weaponHeal= false; //heals target on damage
		weaponIce2= false; //casts ice 2
		weaponBolt1= false;
		weaponFire1= false;
		weaponIce1= false;
		weaponFire2= false;
		weaponHolyCast= false;
		weaponMateriaBlade= false; //cloud subset
		//weapon add status to user
		weaponAutoProtect= false;
		weaponAutoHaste= false;
		weaponAutoShell= false;
		weaponAutoRegen= false;
		weaponAutoFaith= false;
		weaponStartPetrify= false; //start Petrified
	}

	void weaponEquip( WeaponSlot &playerWeapon, Player unit );
};
// probably a better way to do the menu using some sort of iterator and list/map
void WeaponSlot::weaponEquip( WeaponSlot &playerWeapon, Player unit )
{
	//weapon slot
		playerWeapon.weapon = false;
		playerWeapon.weaponEffectBool= false;
		playerWeapon.weaponName= "";
		playerWeapon.weaponType= "";
		playerWeapon.weaponEffect= "";
		playerWeapon.weaponRange= 1;
		playerWeapon.weaponRangeMin= 1;
		playerWeapon.weaponPower= 0;
		playerWeapon.weaponEvade= 0;
		playerWeapon.weaponMA= 0;
		playerWeapon.weaponPA= 0;
		playerWeapon.weaponSpeed= 0;
		//playerWeapon.weapon add status 25%
		playerWeapon.weaponStatusEffect= false; //indicator for attack function
		playerWeapon.weaponDarkness= false;
		playerWeapon.weaponSilence= false;
		playerWeapon.weaponDeathSentence= false;
		playerWeapon.weaponSleep= false;
		playerWeapon.weaponDontAct= false;
		playerWeapon.weaponDontMove= false;
		playerWeapon.weaponFrog= false;
		playerWeapon.weaponPetrify= false;
		playerWeapon.weaponSlow= false;
		playerWeapon.weaponFaith= false;
		playerWeapon.weaponPoison= false;
		playerWeapon.weaponConfusion= false;
		playerWeapon.weaponCharm= false;
		playerWeapon.weaponInnocent= false;
		playerWeapon.weaponCancelDarkness= false;
		playerWeapon.weaponCancelSilence= false;
		playerWeapon.weaponCancelOil= false;
		playerWeapon.weaponCancelFrog= false;
		playerWeapon.weaponCancelPoison= false;
		playerWeapon.weaponCancelStop= false;
		playerWeapon.weaponCancelSlow= false;
		playerWeapon.weaponCancelDontMove= false;
		playerWeapon.weaponCancelDontAct= false;
		playerWeapon.weaponCancelDeathSentence= false;
		//playerWeapon.weapon elemental
		playerWeapon.weaponWind= false;
		playerWeapon.weaponIce= false;
		playerWeapon.weaponLightning= false;
		playerWeapon.weaponHolyUp= false;
		playerWeapon.weaponFire= false;
		playerWeapon.weaponHoly= false;
		playerWeapon.weaponIceUp = false;
		playerWeapon.weaponFireUp = false;
		playerWeapon.weaponLightningUp = false;
		//special playerWeapon.weapon effects
		playerWeapon.weaponCastSpell = false;
		playerWeapon.weaponLifeDrain= false; //damage converted to HP
		playerWeapon.weaponHeal= false; //heals target on damage
		playerWeapon.weaponIce2= false; //casts ice 2
		playerWeapon.weaponBolt1= false;
		playerWeapon.weaponFire1= false;
		playerWeapon.weaponIce1= false;
		playerWeapon.weaponFire2= false;
		playerWeapon.weaponHolyCast= false;
		playerWeapon.weaponMateriaBlade = false; //cloud subset
		playerWeapon.weaponHolyAbsorb = false;
		//playerWeapon.weapon add status to user
		playerWeapon.weaponAutoProtect= false;
		playerWeapon.weaponAutoHaste= false;
		playerWeapon.weaponAutoShell= false;
		playerWeapon.weaponAutoRegen= false;
		playerWeapon.weaponAutoFaith= false;
		playerWeapon.weaponStartPetrify= false; //start Petrified

	cout << "\n"
		<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " can equip: ";
	if( unit.axe == true || unit.equipAxe == true )
		cout << "Axe, ";
	if( unit.bag == true )
		cout << "Bag, ";
	if( unit.bow == true )
		cout << "Bow, ";
	if( unit.crossbow == true || unit.equipCrossbow == true )
		cout << "Crossbow, ";
	if( unit.dictionary == true )
		cout << "Dictionary, ";
	if( unit.fabric == true )
		cout << "Fabric, ";
	if( unit.flail == true )
		cout << "Flail, ";
	if( unit.gun == true || unit.equipGun == true )
		cout << "Gun, ";
	if( unit.harp == true )
		cout << "Harp, ";
	if( unit.katana == true || unit.equipKnife == true )
		cout << "Katana, ";
	if( unit.knife == true )
		cout << "Knife, ";
	if( unit.knightSword == true )
		cout << "Knight Sword, ";
	if( unit.ninjaSword == true )
		cout << "Ninja Sword, ";
	if( unit.rod == true )
		cout << "Rod, ";
	if( unit.spear == true || unit.equipSpear == true )
		cout << "Spear, ";
	if( unit.staff == true )
		cout << "Staff, ";
	if( unit.stick == true )
		cout << "Stick, ";
	if( unit.sword == true || unit.equipSword == true )
		cout << "Sword";
	int equipAction = 0;
	cout << "\n"; 
	while( (cout << "   --- Select Weapon Type ---\n"
		<< "\n"
		<< "0.) Bare Hands" << setw(21) << "1.) Axe" << setw(25) << "2.) Bag\n"
		<< "3.) Bow" << setw(33) << "4.) Crossbow" << setw(27) << "5.) Dictionary\n"
		<< "6.) Fabric" << setw(27) << "7.) Flail" << setw(23) << "8.) Gun\n"
		<< "9.) Harp" << setw(31) << "10.) Katana" << setw(24) << "11.) Knife\n"
		<< "12.) Knight Sword" << setw(27) << "13.) Ninja Sword" << setw(17) << "14.) Rod\n"
		<< "15.) Spear" << setw(28) << "16.) Staff" << setw(25) << "17.) Stick\n"
		<< "18.) Sword\n" )
		&& ( !(cin >> equipAction) || equipAction < 0 || equipAction > 18
		|| ( equipAction == 1 && unit.axe == false  && unit.equipAxe == false ) || ( equipAction == 2 && unit.bag == false )
		|| ( equipAction == 3 && unit.bow == false ) || ( equipAction == 4 && unit.crossbow == false && unit.equipCrossbow == false )
		|| ( equipAction == 5 && unit.dictionary == false ) || ( equipAction == 6 && unit.fabric == false )
		|| ( equipAction == 7 && unit.flail == false ) || ( equipAction == 8 && unit.gun == false  && unit.equipGun == false )
		|| ( equipAction == 9 && unit.harp == false ) || ( equipAction == 10 && unit.katana == false  && unit.equipKnife == false )
		|| ( equipAction == 11 && unit.knife == false ) || ( equipAction == 12 && unit.knightSword == false )
		|| ( equipAction == 13 && unit.ninjaSword == false ) || ( equipAction == 14 && unit.rod == false )
		|| ( equipAction == 15 && unit.spear == false && unit.equipSpear == false ) || ( equipAction == 16 && unit.staff == false )
		|| ( equipAction == 17 && unit.stick == false ) || ( equipAction == 18 && unit.sword == false  && unit.equipSword == false )
		) ) 
	{
		cout << "\n";
		cout << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " can equip: ";
		if( unit.axe == true || unit.equipAxe == true )
			cout << "Axe, ";
		if( unit.bag == true )
			cout << "Bag, ";
		if( unit.bow == true )
			cout << "Bow, ";
		if( unit.crossbow == true || unit.equipCrossbow == true )
			cout << "Crossbow, ";
		if( unit.dictionary == true )
			cout << "Dictionary, ";
		if( unit.fabric == true )
			cout << "Fabric, ";
		if( unit.flail == true )
			cout << "Flail, ";
		if( unit.gun == true || unit.equipGun == true )
			cout << "Gun, ";
		if( unit.harp == true )
			cout << "Harp, ";
		if( unit.katana == true || unit.equipKnife == true )
			cout << "Katana, ";
		if( unit.knife == true )
			cout << "Knife, ";
		if( unit.knightSword == true )
			cout << "Knight Sword, ";
		if( unit.ninjaSword == true )
			cout << "Ninja Sword, ";
		if( unit.rod == true )
			cout << "Rod, ";
		if( unit.spear == true || unit.equipSpear == true )
			cout << "Spear, ";
		if( unit.staff == true )
			cout << "Staff, ";
		if( unit.stick == true )
			cout << "Stick, ";
		if( unit.sword == true || unit.equipSword == true )
			cout << "Sword";
		cout << "\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	if( equipAction == 0 )
	{
		playerWeapon.weaponName = "NONE";
		playerWeapon.weaponEffect = "NULL";
		playerWeapon.weaponType = "Bare Hands";
		playerWeapon.weaponRange = 1;
		playerWeapon.weaponPower = 0;
		playerWeapon.weaponEvade = 0;
		playerWeapon.weapon = false;
		playerWeapon.weaponEffectBool = false;
	}
	else if( equipAction == 1 )
	{
		int equipWeapon = 0;
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Axe ---\n"
				<< "\n"
			<< "0.) Bare Hands\n" << setw(40) 
			<< "1.) Battle Axe --  9 WP\n"
			<< "2.) Giant Axe  -- 12 WP\n" << setw(41) 
			<< "3.) Slasher    -- 16 WP, Add: Slow\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 3 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Battle Axe";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Axe";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Giant Axe";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Axe";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Slasher";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Axe";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 16;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = true;
			playerWeapon.weaponSlow = true;
		}
	}
	else if( equipAction == 2 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Bag ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"
			<< "1.) C Bag  -- 10 WP, +1 MA\n"
			<< "2.) FS Bag -- 20 WP\n" 
			<< "3.) P Bag  -- 16 WP, Auto Regen\n"
			<< "4.) H Bag  -- 14 WP, +1 Speed\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 4 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "C Bag";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bag";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponMA = 1;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "FS Bag";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bag";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 20;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "P Bag";
			playerWeapon.weaponEffect = "Auto Regen";
			playerWeapon.weaponType = "Bag";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponAutoRegen = true;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "H Bag";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bag";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 14;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponSpeed = 1;
		}
	}
	else if( equipAction == 3 )
	{
		int equipWeapon = 0;
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Bow ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"   
			<< "1.) Long Bow      --  4 WP\n"
			<< "2.) Silver Bow    --  5 WP\n"  
			<< "3.) Ice Bow       --  5 WP, Ice Elemental\n"
			<< "4.) Lightning Bow --  6 WP, Lightning Elemental, Add: Bolt\n" 
			<< "5.) Windslash Bow --  8 WP, Wind Elemental\n"
			<< "6.) Mythril Bow   --  7 WP\n"  
			<< "7.) Ultimus Bow   -- 10 WP\n"
			<< "8.) Yoichi Bow    -- 12 WP\n" 
			<< "9.) Perseus Bow   -- 16 WP\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 9 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0)
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1)
		{	
			playerWeapon.weaponName = "Long Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			playerWeapon.weaponName = "Silver Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 5;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			playerWeapon.weaponName = "Ice Bow";
			playerWeapon.weaponEffect = "Ice";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 5;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponIce;
		}
		else if( equipWeapon == 4)
		{	
			playerWeapon.weaponName = "Lightning Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponLightning = true;
			playerWeapon.weaponBolt1 = true;
		}
		else if( equipWeapon == 5 )
		{	
			playerWeapon.weaponName = "Windslash Bow";
			playerWeapon.weaponEffect = "Wind";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponWind = true;
		}
		else if( equipWeapon == 6)
		{	
			playerWeapon.weaponName = "Mythril Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 7)
		{	
			playerWeapon.weaponName = "Ultimus Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{	
			playerWeapon.weaponName = "Yoichi Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 9 )
		{	
			playerWeapon.weaponName = "Perseus Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bow";
			playerWeapon.weaponRange = 5;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 16;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 4 )
	{
		int equipWeapon = 0;
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Crossbow ---\n"
				<< "\n"
			<< "0.) Bare Hands\n" 
			<< "1.) Bow Gun       --  3 WP\n"
			<< "2.) Night Killer  --  3 WP, Add: Darkness\n" 
			<< "3.) Cross Bow     --  4 WP\n"
			<< "4.) Poison Bow    --  4 WP, Add: Poison\n" 
			<< "5.) Hunting Bow   --  6 WP\n"
			<< "6.) Gastrafitis   -- 10 WP\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 6 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0)
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			playerWeapon.weaponName = "Bow Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Crossbow";
			playerWeapon.weaponRange = 4;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		
		}
		else if( equipWeapon == 2)
		{	
			playerWeapon.weaponName = "Night Killer";
			playerWeapon.weaponEffect = "Darkness";
			playerWeapon.weaponType = "Crossbow";
			playerWeapon.weaponRange = 4;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponDarkness = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 3)
		{	
			playerWeapon.weaponName = "Cross Bow";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Crossbow";
			playerWeapon.weaponRange = 4;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			playerWeapon.weaponName = "Poison Bow";
			playerWeapon.weaponEffect = "Poison";
			playerWeapon.weaponType = "Crossbow";
			playerWeapon.weaponRange = 4;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponPoison = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 5)
		{	
			playerWeapon.weaponName = "Hunting Bow";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Crossbow";
			playerWeapon.weaponRange = 4;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			playerWeapon.weaponName = "Gastrafitis";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Crossbow";
			playerWeapon.weaponRange = 4;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 5 )
	{
		int equipWeapon = 0;
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Dictionary ---\n"
				<< "\n"
				<< "0.) Bare Hands\n"  
				<< "1.) Battle Dict   --  7 WP\n"
				<< "2.) Monster Dict  --  8 WP\n"  
				<< "3.) Papyrus Plate --  9 WP\n"
				<< "4.) Madlemgen     -- 11 WP\n" 
				<< "Weapon Power (WP)\n"
				)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 4 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Battle Dict";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Dictionary";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Monster Dict";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Dictionary";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Papyrus Plate";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Dictionary";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Madlemgen";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Dictionary";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 11;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 6 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Fabric ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"  
			<< "1.) Persia      --  8 WP\n"
			<< "2.) Cashmere    -- 10 WP\n"  
			<< "3.) Ryozan Silk -- 15 WP\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 3 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Persia";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Fabric";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 50;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Cashmere";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Fabric";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 50;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Ryozan Silk";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Fabric";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 15;
			playerWeapon.weaponEvade = 50;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 7 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Flail ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"
			<< "1.) Flail         --  9 WP\n"
			<< "2.) Flame Whip    -- 11 WP, Fire Elemental, Add: Fire 2\n" 
			<< "3.) Morning Star  -- 16 WP\n"
			<< "4.) Scorpion Tail -- 23 WP\n"
			<< "Weapon Power (WP)"
			 )
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 4 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Flail";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Flail";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Flame Whip";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Flail";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 11;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponFire = true;
			playerWeapon.weaponFire2 = true;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Morning Star";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Flail";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 16;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Scorpion Tail";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Flail";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 23;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 8 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Gun ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"
			<< "1.) Romanda Gun  --  6 WP\n"
			<< "2.) Mythril Gun  --  8 WP\n" 
			<< "3.) Stone Gun    -- 16 WP -- Start: Petrify\n"
			<< "4.) Blaze Gun    -- 20 WP -- Ice Elemental\n"
			<< "5.) Glacier Gun  -- 21 WP -- Fire Elemental\n"
			<< "6.) Blast Gun    -- 22 WP -- Lightning Elemental\n"
			<< "Weapon Power (WP)\n"
			) && ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 6 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Romanda Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Gun";
			playerWeapon.weaponRange = 8;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Mythril Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Gun";
			playerWeapon.weaponRange = 8;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Stone Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Gun";
			playerWeapon.weaponRange = 8;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 16;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStartPetrify = true;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Blaze Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Magic Gun";
			playerWeapon.weaponRange = 8;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 20;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponIce = true;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Glacier Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Magic Gun";
			playerWeapon.weaponRange = 8;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 21;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponFire = true;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Blast Gun";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Magic Gun";
			playerWeapon.weaponRange = 8;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 22;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponLightning = true;
		}
	}
	else if( equipAction == 9 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Harp ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"
			<< "1.) Ramia Harp     -- 10 WP, Add: Confusion\n"
			<< "2.) Bloody Strings -- 13 WP, Life Drain\n"
			<< "3.) Fairy Harp     -- 15 WP, Add: Charm\n"
			<< "Weapon Power\n"
			 )
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 3 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Ramia Harp";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Harp";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponStatusEffect = true;
			playerWeapon.weaponConfusion = true;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Bloody Strings";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Harp";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 13;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponLifeDrain = true;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Fairy Harp";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Harp";
			playerWeapon.weaponRange = 3;
			playerWeapon.weaponRangeMin = 3;
			playerWeapon.weaponPower = 15;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponStatusEffect = true;
			playerWeapon.weaponCharm = true;
		}
	}
	else if( equipAction == 10 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Katana ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"  
			<< "1.) Asura Knife -- 7 WP\n"
			<< "2.) Koutetsu Knife -- 8 WP\n" 
			<< "3.) Bizen Boat -- 15 WP\n"
			<< "4.) Murasame -- 10 WP\n" 
			<< "5.) Heaven's Cloud -- 11 WP\n"
			<< "6.) Kiyomori -- 12 WP\n" 
			<< "7.) Muramasa -- 14 WP\n"
			<< "8.) Kikuichimoji -- 15 WP\n"
			<< "9.) Masamune -- 18 WP\n"
			<< "10.) Chirijiradaen -- 25 WP\n"
			<< "Weapon Power\n"
			  )
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 10 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Asura Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Koutetsu Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Bizen Boat";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Murasame";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Heaven's Cloud";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 11;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Kiyomori";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			playerWeapon.weaponName = "Muramasa";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 14;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{
			playerWeapon.weaponName = "Kikuichimoji";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 15;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 9 )
		{
			playerWeapon.weaponName = "Masamune";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 18;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 10 )
		{
			playerWeapon.weaponName = "Chirijiraden";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Katana";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 25;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 11 )
	{
		int equipWeapon = 0;
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Knife ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"
			<< "1.) Dagger          --  3 WP\n"
			<< "2.) Mythril Knife   --  4 WP\n" 
			<< "3.) Blind Knife     --  4 WP, Add: Darkness\n"
			<< "4.) Mage Masher     --  4 WP, Add: Silence\n" 
			<< "5.) Platina Dagger  --  5 WP\n"
			<< "6.) Main Gauche     --  6 WP\n"  
			<< "7.) Orichalcum      --  7 WP\n"
			<< "8.) Assassin Dagger --  7 WP, Add: Death Sentence\n" 
			<< "9.) Air Knife       -- 10 WP, Wind Elemental\n"
			<< "10.) Zorlin Shape   -- 12 WP, Add: Sleep\n"
			<< "Weapon Power (WP)\n"
			 )
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 10 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0)
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			playerWeapon.weaponName = "Dagger";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon== 2)
		{	
			playerWeapon.weaponName = "Mythril Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			playerWeapon.weaponName = "Blind Knife";
			playerWeapon.weaponEffect = "Darkness";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponDarkness = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 4)
		{	
			playerWeapon.weaponName = "Mage Masher";
			playerWeapon.weaponEffect = "Silence";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponSilence = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 5)
		{	
			playerWeapon.weaponName = "Platina Dagger";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 5;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 6)
		{	
			playerWeapon.weaponName = "Main Gauche";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 40;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 7)
		{	
			playerWeapon.weaponName = "Orichalcum";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 8)
		{	
			playerWeapon.weaponName = "Assassin Dagger";
			playerWeapon.weaponEffect = "Add: Death Sentence";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponDeathSentence = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 9 )
		{	
			playerWeapon.weaponName = "Air Knife";
			playerWeapon.weaponEffect = "Wind Elemental";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponWind = true;
		}
		else if( equipWeapon == 10)
		{	
			playerWeapon.weaponName = "Zorlin Shape";
			playerWeapon.weaponEffect = "Add: Sleep";
			playerWeapon.weaponType = "Knife";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponSleep = true;
			playerWeapon.weaponStatusEffect = true;
		}
	}
	else if( equipAction == 12 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Knight Sword ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"  
			<< "1.) Defender       -- 16 WP, 60 Weapon Evade\n"
			<< "2.) Save the Queen -- 18 WP, Protect\n" 
			<< "3.) Excalibur      -- 21 WP, Haste, Holy Elemental\n"
			<< "4.) Ragnarok       -- 24 WP, Shell\n" 
			<< "5.) Chaos Blade    -- 40 WP, Regen, Add: Petrify\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 5 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Defender";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Knight Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 16;
			playerWeapon.weaponEvade = 60;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Save the Queen";
			playerWeapon.weaponEffect = "Auto Protect";
			playerWeapon.weaponType = "Knight Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 18;
			playerWeapon.weaponEvade = 30;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponAutoProtect = true;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Excalibur";
			playerWeapon.weaponEffect = "Auto Haste, Absorb Holy, Strengthen Holy";
			playerWeapon.weaponType = "Knight Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 21;
			playerWeapon.weaponEvade = 35;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponAutoHaste = true;
			playerWeapon.weaponHolyUp = true;
			playerWeapon.weaponHolyAbsorb = true;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Ragnarok";
			playerWeapon.weaponEffect = "Auto Shell";
			playerWeapon.weaponType = "Knight Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 24;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponAutoShell = true;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Chaos Blade";
			playerWeapon.weaponEffect = "Auto Regen, Add Petrify";
			playerWeapon.weaponType = "Knight Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 40;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponAutoRegen = true;
			playerWeapon.weaponPetrify = true;
			playerWeapon.weaponStatusEffect = true;
		}
	}
	else if( equipAction == 13 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Ninja Sword ---\n"
				<< "\n"
				<< "0.) Bare Hands\n"  
				<< "1.) Hidden Knife --  8 WP\n"
				<< "2.) Ninja Knife  --  9 WP\n"  
				<< "3.) Short Edge   -- 10 WP\n"
				<< "4.) Ninja Edge   -- 12 WP\n" 
				<< "5.) Spell Edge   -- 13 WP, Add: Don't Act\n"
				<< "6.) Sasuke Knife -- 14 WP\n" 
				<< "7.) Iga Knife    -- 15 WP\n"
				<< "8.) Koga Knife   -- 15 WP\n"
				<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 8 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Hidden Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Ninja Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Short Edge";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Ninja Edge";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Spell Edge";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 13;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponStatusEffect = true;
			playerWeapon.weaponDontAct = true;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Sasuke Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 14;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 7 )
		{
			playerWeapon.weaponName = "Iga Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 15;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
		else if( equipWeapon == 8 )
		{
			playerWeapon.weaponName = "Koga Knife";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Ninja Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 15;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponStatusEffect = false;
		}
	}
	else if( equipAction == 14 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Rod ---\n"
				<< "\n"
			<< "0.) Bare Hands\n" 
			<< "1.) Rod         -- 3 WP\n"
			<< "2.) Thunder Rod -- 3 WP, Lightning Elemental, Add: Bolt\n"  
			<< "3.) Flame Rod   -- 3 WP, Fire Elemental, Add: Fire\n"
			<< "4.) Ice Rod     -- 3 WP, Ice Elemental, Add: Ice\n"  
			<< "5.) Poison Rod  -- 3 WP, Add: Poison\n"
			<< "6.) Wizard Rod  -- 4 WP, MA +2\n" 
			<< "7.) Dragon Rod  -- 5 WP\n"
			<< "8.) Faith Rod   -- 5 WP, Faith, Add: Faith\n"  
			<< "Weapon Power (WP) \n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 8 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Rod";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Thunder Rod";
			playerWeapon.weaponEffect = "Lightning, Lightning Up, Add: Bolt";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponBolt1 = true;
			playerWeapon.weaponLightning = true;
			playerWeapon.weaponLightningUp = true;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Flame Rod";
			playerWeapon.weaponEffect = "Fire, Fire Up, Add: Fire";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponFire1 = true;
			playerWeapon.weaponFire= true;
			playerWeapon.weaponFireUp = true;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Ice Rod";
			playerWeapon.weaponEffect = "Ice, Ice Up, Add: Ice";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponIce1 = true;
			playerWeapon.weaponIce = true;
			playerWeapon.weaponIceUp = true;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Poison Rod";
			playerWeapon.weaponEffect = "Add: Poison";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponPoison = true;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Wizard Rod";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponMA = 2;
		}
		else if( equipWeapon == 7 )
		{
			playerWeapon.weaponName = "Faith Rod";
			playerWeapon.weaponEffect = "Add: Faith, Auto Faith";
			playerWeapon.weaponType = "Rod";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponFaith = true;
			playerWeapon.weaponAutoFaith = true;
		}
	}
	else if( equipAction == 15 )
	{
		int equipWeapon = 0;
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Spear ---\n"
				<< "\n"
				<< "0.) Bare Hands\n"  
				<< "1.) Javelin        --  8 WP\n"
				<< "2.) Spear          --  9 WP\n" 
				<< "3.) Mythril Spear  -- 10 WP\n"
				<< "4.) Partisan       -- 11 WP\n" 
				<< "5.) Oberisk        -- 12 WP\n"
				<< "6.) Holy Lance     -- 14 WP, Holy Elemental, Add: Holy\n" 
				<< "7.) Dragon Whisker -- 17 WP\n"
				<< "8.) Javelin 2      -- 30 WP\n" 
				<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 8 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Javelin";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Spear";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Mythril Spear";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Partisan";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 11;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Oberisk";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Holy Lance";
			playerWeapon.weaponEffect = "Holy, Add: Holy";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 14;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponHoly = true;
			playerWeapon.weaponHolyCast = true;
		}
		else if( equipWeapon == 7 )
		{
			playerWeapon.weaponName = "Dragon Whisker";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 17;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 8 )
		{
			playerWeapon.weaponName = "Javelin 2";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Spear";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 30;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 16 )
	{
		int equipWeapon = 0;
		while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Staff ---\n"
				<< "\n"
			<< "0.) Bare Hands\n" 
			<< "1.) Oak Staff     -- 3 WP\n"
			<< "2.) White Staff   -- 3 WP, Cancel: Death Sentence\n" 
			<< "3.) Healing Staff -- 4 WP, (Heals)\n"
			<< "4.) Rainbow Staff -- 5 WP\n"
			<< "5.) Wizard Staff  -- 4 WP, MA +1\n"
			<< "6.) Gold Staff    -- 6 WP, Holy Elemental, Add: Holy\n"  
			<< "7.) Mace of Zeus  -- 6 WP, PA +2, MA +1\n"
			<< "8.) Sage Staff    -- 7 WP\n" 
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 8 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Oak Staff";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "White Staff";
			playerWeapon.weaponEffect = "Cancel: Death Sentence";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 3;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCancelDeathSentence = true;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Healing Staff";
			playerWeapon.weaponEffect = "Restore HP on Attack";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponHeal = true;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Rainbow Staff";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 5;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Wizard Staff";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 5;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponMA = 1;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Gold Staff";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			playerWeapon.weaponName = "Mace of Zeus";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponPA = 2;
			playerWeapon.weaponMA = 1;
		}
		else if( equipWeapon == 8 )
		{
			playerWeapon.weaponName = "Sage Staff";
			playerWeapon.weaponEffect = "";
			playerWeapon.weaponType = "Staff";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 17 )
	{
		int equipWeapon = 0;
		while( (
			cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Stick ---\n"
				<< "\n"
			<< "0.) Bare Hands\n" 
			<< "1.) Cypress Rod   -- 6 WP\n"
			<< "2.) Battle Bamboo -- 7 WP\n" 
			<< "3.) Musk Rod      -- 8 WP\n"
			<< "4.) Iron Fan      -- 9 WP\n" 
			<< "5.) Gokuu Rod     -- 10 WP, Add: Innocent\n"
			<< "6.) Ivory Rod     -- 11 WP\n" 
			<< "7.) Octagon Rod   -- 12 WP, Cancel: Various\n"
			<< "8.) Whale Whisker -- 16 WP\n"
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 8 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0 )
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 1 )
		{
			playerWeapon.weaponName = "Cypress Rod";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2 )
		{
			playerWeapon.weaponName = "Battle Bamboo";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3 )
		{
			playerWeapon.weaponName = "Musk Rod";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4 )
		{
			playerWeapon.weaponName = "Iron Fan";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 5 )
		{
			playerWeapon.weaponName = "Gokuu Rod";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponInnocent = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 6 )
		{
			playerWeapon.weaponName = "Ivory Rod";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 11;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 7 )
		{
			playerWeapon.weaponName = "Octagon Rod";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponStatusEffect = true;
			playerWeapon.weaponCancelDarkness = true;
			playerWeapon.weaponCancelSilence = true;
			playerWeapon.weaponCancelOil = true;
			playerWeapon.weaponCancelFrog = true;
			playerWeapon.weaponCancelPoison = true;
			playerWeapon.weaponCancelStop = true;
			playerWeapon.weaponCancelSlow = true;
			playerWeapon.weaponCancelDontMove = true;
			playerWeapon.weaponCancelDontAct = true;
		}
		else if( equipWeapon == 8 )
		{
			playerWeapon.weaponName = "Whale Whisker";
			playerWeapon.weaponType = "Stick";
			playerWeapon.weaponRange = 2;
			playerWeapon.weaponPower = 16;
			playerWeapon.weaponEvade = 20;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
	}
	else if( equipAction == 18 )
	{
		int equipWeapon = 0;
		while( (
			cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Sword ---\n"
				<< "\n"
			<< "0.) Bare Hands\n"
			<< "1.) Broad Sword    --  4 WP\n"
			<< "2.) Long Sword     --  5 WP\n"
			<< "3.) Iron Sword     --  6 WP\n"
			<< "4.) Mythril Sword  --  7 WP\n"
			<< "5.) Blood Sword    --  8 WP, Life Drain\n"
			<< "6.) Coral Sword    --  8 WP, Lightning Elemental\n"  
			<< "7.) Ancient Sword  --  9 WP, Add: Don't Move\n"
			<< "8.) Sleep Sword    --  9 WP, Add: Sleep\n" 
			<< "9.) Platinum Sword -- 12 WP\n"
			<< "10.) Diamond Sword -- 10 WP\n" 
			<< "11.) Ice Brand     -- 13 WP, Ice Elemental, Add: Ice 2\n"
			<< "12.) Rune Blade    -- 14 WP, MA +2\n" 
			<< "13.) Nagrarock     --  1 WP, Add: Frog\n"
			<< "14.) Materia Blade -- 10 WP\n" 
			<< "Weapon Power (WP)\n"
			)
		&& ( !(cin >> equipWeapon) || equipWeapon < 0 || equipWeapon > 14 ) ) 
		{
			cout << "Invalid answer. Enter a valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipWeapon == 0)
		{
			playerWeapon.weaponName = "NONE";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Bare Hands";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 0;
			playerWeapon.weaponEvade = 0;
			playerWeapon.weapon = false;
			playerWeapon.weaponEffectBool = false;
		}
		if( equipWeapon == 1)
		{	
			playerWeapon.weaponName = "Broad Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 4;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 2)
		{	
			playerWeapon.weaponName = "Long Sword";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 5;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 3)
		{	
			playerWeapon.weaponName = "Iron Sword";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 6;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 4)
		{	
			playerWeapon.weaponName = "Mythril Sword";
			playerWeapon.weaponEffect = "NULL";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 7;
			playerWeapon.weaponEvade = 8;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon ==  5 )
		{	
			playerWeapon.weaponName = "Blood Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponLifeDrain = true;
		}
		else if( equipWeapon == 6 )
		{	
			playerWeapon.weaponName = "Coral Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 8;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponLightning = true;
		}
		else if( equipWeapon == 7 )
		{	
			playerWeapon.weaponName = "Ancient Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponDontMove = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 8 )
		{	
			playerWeapon.weaponName = "Sleep Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 9;
			playerWeapon.weaponEvade = 5;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponSleep = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 9 )
		{	
			playerWeapon.weaponName = "Platinum Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 12;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 10 )
		{	
			playerWeapon.weaponName = "Diamond Sword";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
		}
		else if( equipWeapon == 11 )
		{	
			playerWeapon.weaponName = "Ice Brand";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 13;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponCastSpell = true;
			playerWeapon.weaponIce2 = true;
			playerWeapon.weaponIce = true;
		}
		else if( equipWeapon == 12 )
		{	
			playerWeapon.weaponName = "Rune Blade";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 14;
			playerWeapon.weaponEvade = 15;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = false;
			playerWeapon.weaponMA = 2;
		}
		else if( equipWeapon == 13 )
		{	
			playerWeapon.weaponName = "Nagrarock";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 1;
			playerWeapon.weaponEvade = 50;
			playerWeapon.weapon = true;
			playerWeapon.weaponEffectBool = true;
			playerWeapon.weaponFrog = true;
			playerWeapon.weaponStatusEffect = true;
		}
		else if( equipWeapon == 14 )
		{	
			playerWeapon.weaponName = "Materia Blade";
			playerWeapon.weaponType = "Sword";
			playerWeapon.weaponRange = 1;
			playerWeapon.weaponPower = 10;
			playerWeapon.weaponEvade = 10;
			playerWeapon.weapon = true;
		}
	}
}

class OffHandSlot //creates offHand
{
public:
	 //offhand slot
	int offHandPhyEvade;
	int offHandMagEvade;
	bool offHand;
	bool offHandWeapon;
	bool offHandEffectBool;
	string offHandName;
	string offHandType;
	string offHandEffect;
	int offHandRange;
	int offHandRangeMin;
	int offHandPower;
	int offHandEvade;
	int offHandMA;
	int offHandPA;
	int offHandSpeed;
	//offHand add status 25%
	bool offHandStatusEffect; //indicator for attack function
	bool offHandDarkness;
	bool offHandSilence;
	bool offHandDeathSentence;
	bool offHandSleep;
	bool offHandDontAct;
	bool offHandDontMove;
	bool offHandFrog;
	bool offHandPetrify;
	bool offHandSlow;
	bool offHandFaith;
	bool offHandPoison;
	bool offHandConfusion;
	bool offHandCharm;
	bool offHandInnocent;
	bool offHandCancelDarkness;
	bool offHandCancelSilence;
	bool offHandCancelOil;
	bool offHandCancelFrog;
	bool offHandCancelPoison;
	bool offHandCancelStop;
	bool offHandCancelSlow;
	bool offHandCancelDontMove;
	bool offHandCancelDontAct;
	bool offHandCancelDeathSentence;
	//offHand elemental
	bool offHandWind;
	bool offHandIce;
	bool offHandLightning;
	bool offHandHolyUp;
	bool offHandFire;
	bool offHandHoly;
	bool offHandHolyAbsorb;
	bool offHandAbsorbIce;
	bool offHandAbsorbFire;
	bool offHandWeakLightning;
	bool offHandWeakWater;
	bool offHandHalfLightning;
	bool offHandHalfFire;
	bool offHandHalfIce;
	bool offHandLightningUp;
	bool offHandFireUp;
	bool offHandIceUp;
	//special offHand effects
	bool offHandCastSpell;
	bool offHandLifeDrain; //damage converted to HP
	bool offHandHeal; //heals target on damage
	bool offHandIce2; //casts ice 2
	bool offHandBolt1;
	bool offHandFire1;
	bool offHandIce1;
	bool offHandFire2;
	bool offHandHolyCast;
	bool offHandMateriaBlade; //cloud subset
	//offHand add status to user
	bool offHandAutoProtect;
	bool offHandAutoHaste;
	bool offHandAutoShell;
	bool offHandAutoRegen;
	bool offHandAutoFaith;
	bool offHandStartPetrify; //start Petrified

	OffHandSlot()
	{
		offHand = false;
	}

	void offHandEquip( OffHandSlot &playerOffHand, Player unit, WeaponSlot &offHandWeapon,
		WeaponSlot mainWeapon );
};

void OffHandSlot::offHandEquip( OffHandSlot &playerOffHand, Player unit,
	WeaponSlot &offHandWeapon, WeaponSlot mainWeapon )
{
	 //offhand slot
	playerOffHand.offHandPhyEvade = 0;
	playerOffHand.offHandMagEvade = 0;
	playerOffHand.offHand = false;
	playerOffHand.offHandWeapon = false;
	playerOffHand.offHandEffectBool = false;
	playerOffHand.offHandName = "";
	playerOffHand.offHandType = "";
	playerOffHand.offHandEffect = "";
	playerOffHand.offHandRange = 1;
	playerOffHand.offHandRangeMin = 1;
	playerOffHand.offHandPower = 0;
	playerOffHand.offHandEvade = 0;
	playerOffHand.offHandMA = 0;
	playerOffHand.offHandPA = 0;
	playerOffHand.offHandSpeed = 0;
	//playerOffHand.offHand add status 25%
	playerOffHand.offHandStatusEffect = false; //indicator for attack function
	playerOffHand.offHandDarkness = false;
	playerOffHand.offHandSilence = false;
	playerOffHand.offHandDeathSentence = false;
	playerOffHand.offHandSleep = false;
	playerOffHand.offHandDontAct = false;
	playerOffHand.offHandDontMove = false;
	playerOffHand.offHandFrog = false;
	playerOffHand.offHandPetrify = false;
	playerOffHand.offHandSlow = false;
	playerOffHand.offHandFaith = false;
	playerOffHand.offHandPoison = false;
	playerOffHand.offHandConfusion = false;
	playerOffHand.offHandCharm = false;
	playerOffHand.offHandInnocent = false;
	playerOffHand.offHandCancelDarkness = false;
	playerOffHand.offHandCancelSilence = false;
	playerOffHand.offHandCancelOil = false;
	playerOffHand.offHandCancelFrog = false;
	playerOffHand.offHandCancelPoison = false;
	playerOffHand.offHandCancelStop = false;
	playerOffHand.offHandCancelSlow = false;
	playerOffHand.offHandCancelDontMove = false;
	playerOffHand.offHandCancelDontAct = false;
	playerOffHand.offHandCancelDeathSentence = false;
	//playerOffHand.offHand elemental
	playerOffHand.offHandWind = false;
	playerOffHand.offHandIce = false;
	playerOffHand.offHandLightning = false;
	playerOffHand.offHandHolyUp = false;
	playerOffHand.offHandHolyAbsorb = false;
	playerOffHand.offHandFire = false;
	playerOffHand.offHandHoly = false;
	playerOffHand.offHandAbsorbIce = false;
	playerOffHand.offHandAbsorbFire = false;
	playerOffHand.offHandWeakLightning = false;
	playerOffHand.offHandWeakWater = false;
	playerOffHand.offHandHalfLightning = false;
	playerOffHand.offHandHalfFire = false;
	playerOffHand.offHandHalfIce = false;
	playerOffHand.offHandLightningUp = false;
	playerOffHand.offHandFireUp = false;
	playerOffHand.offHandIceUp = false;
	//special playerOffHand.offHand effects
	playerOffHand.offHandCastSpell = false;
	playerOffHand.offHandLifeDrain = false; //damage converted to HP
	playerOffHand.offHandHeal = false; //heals target on damage
	playerOffHand.offHandIce2 = false; //casts ice 2
	playerOffHand.offHandBolt1 = false;
	playerOffHand.offHandFire1 = false;
	playerOffHand.offHandIce1 = false;
	playerOffHand.offHandFire2 = false;
	playerOffHand.offHandHolyCast = false;
	playerOffHand.offHandMateriaBlade = false; //cloud subset
	//playerOffHand.offHand add status to user
	playerOffHand.offHandAutoProtect = false;
	playerOffHand.offHandAutoHaste = false;
	playerOffHand.offHandAutoShell = false;
	playerOffHand.offHandAutoRegen = false;
	playerOffHand.offHandAutoFaith = false;
	playerOffHand.offHandStartPetrify = false; //start Petrified


	int equipAction = 0;
	int equipType = 0;

	if( 
		( unit.shield == true || unit.equipShield == true ) &&
		( unit.twoSwords == true || unit.playerClass == 12 )
		)
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Off Hand Type ---\n"
				<< "\n"
			<< "0.) NONE" << setw(25) << "1.) Weapon" << setw(25) << "2.) Shield\n")
			&& ( !(cin >> equipType ) || equipType < 0 || equipType > 2 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else if( unit.twoSwords == true &&
		( mainWeapon.weaponType == "Bare Hands" || mainWeapon.weaponType == "Knife"
		|| mainWeapon.weaponType == "Ninja Sword" || mainWeapon.weaponType == "Sword"
		|| mainWeapon.weaponType == "Knight Sword" || mainWeapon.weaponType == "Katana"
		|| mainWeapon.weaponType == "Rod" || mainWeapon.weaponType == "Staff"
		|| mainWeapon.weaponType == "Flail" )
		)
	{
		equipType = 1;
	}
	else if( unit.shield == true || unit.equipShield == true )
	{
		equipType = 2;
	}
	else equipType = 0;

	if( equipType == 0 ) //will bypass remainder of this
	{

	}
	else if( equipType == 1 ) //begin weapon equip
	{
		cout << "\n"
			<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Off Hand Weapon ---\n"
			<< "\n";
		offHandWeapon.weaponEquip( offHandWeapon, unit); 
			//offhand slot
		playerOffHand.offHand = offHandWeapon.weapon;
		playerOffHand.offHandWeapon = offHandWeapon.weapon;
		playerOffHand.offHandEffectBool = offHandWeapon.weaponEffectBool;
		playerOffHand.offHandName = offHandWeapon.weaponName;
		playerOffHand.offHandType = offHandWeapon.weaponType;
		playerOffHand.offHandEffect = offHandWeapon.weaponEffect;
		playerOffHand.offHandRange = offHandWeapon.weaponRange;
		playerOffHand.offHandRangeMin = offHandWeapon.weaponRangeMin;
		playerOffHand.offHandPower = offHandWeapon.weaponPower;
		playerOffHand.offHandEvade = offHandWeapon.weaponEvade;
		playerOffHand.offHandMA = offHandWeapon.weaponMA;
		playerOffHand.offHandPA = offHandWeapon.weaponPA;
		playerOffHand.offHandSpeed = offHandWeapon.weaponSpeed;
		//playerOffHand.offHand add status 25%
		playerOffHand.offHandStatusEffect = offHandWeapon.weaponStatusEffect; //indicator for attack function
		playerOffHand.offHandDarkness = offHandWeapon.weaponDarkness;
		playerOffHand.offHandSilence = offHandWeapon.weaponSilence;
		playerOffHand.offHandDeathSentence = offHandWeapon.weaponDeathSentence;
		playerOffHand.offHandSleep = offHandWeapon.weaponSleep;
		playerOffHand.offHandDontAct = offHandWeapon.weaponDontAct;
		playerOffHand.offHandDontMove = offHandWeapon.weaponDontMove;
		playerOffHand.offHandFrog = offHandWeapon.weaponFrog;
		playerOffHand.offHandPetrify = offHandWeapon.weaponPetrify;
		playerOffHand.offHandSlow = offHandWeapon.weaponSlow;
		playerOffHand.offHandFaith = offHandWeapon.weaponFaith;
		playerOffHand.offHandPoison = offHandWeapon.weaponPoison;
		playerOffHand.offHandConfusion = offHandWeapon.weaponConfusion;
		playerOffHand.offHandCharm = offHandWeapon.weaponCharm;
		playerOffHand.offHandInnocent = offHandWeapon.weaponInnocent;
		playerOffHand.offHandCancelDarkness = offHandWeapon.weaponCancelDarkness;
		playerOffHand.offHandCancelSilence = offHandWeapon.weaponCancelSilence;
		playerOffHand.offHandCancelOil = offHandWeapon.weaponCancelOil;
		playerOffHand.offHandCancelFrog = offHandWeapon.weaponCancelFrog;
		playerOffHand.offHandCancelPoison = offHandWeapon.weaponCancelPoison;
		playerOffHand.offHandCancelStop = offHandWeapon.weaponCancelStop;
		playerOffHand.offHandCancelSlow = offHandWeapon.weaponCancelSlow;
		playerOffHand.offHandCancelDontMove = offHandWeapon.weaponCancelDontMove;
		playerOffHand.offHandCancelDontAct = offHandWeapon.weaponCancelDontAct;
		playerOffHand.offHandCancelDeathSentence = offHandWeapon.weaponCancelDeathSentence;
		//playerOffHand.offHand elemental
		playerOffHand.offHandWind = offHandWeapon.weaponWind;
		playerOffHand.offHandIce = offHandWeapon.weaponIce;
		playerOffHand.offHandLightning = offHandWeapon.weaponLightning;
		playerOffHand.offHandHolyUp = offHandWeapon.weaponHolyUp;
		playerOffHand.offHandHolyAbsorb = offHandWeapon.weaponHolyAbsorb;
		playerOffHand.offHandFire = offHandWeapon.weaponFire;
		playerOffHand.offHandHoly = offHandWeapon.weaponHoly;
		playerOffHand.offHandLightningUp = offHandWeapon.weaponLightningUp;
		playerOffHand.offHandFireUp = offHandWeapon.weaponFireUp;
		playerOffHand.offHandIceUp = offHandWeapon.weaponIceUp;
		//special playerOffHand.offHand effects
		playerOffHand.offHandCastSpell = offHandWeapon.weaponCastSpell;
		playerOffHand.offHandLifeDrain = offHandWeapon.weaponLifeDrain; //damage converted to HP
		playerOffHand.offHandHeal = offHandWeapon.weaponHeal; //heals target on damage
		playerOffHand.offHandIce2 = offHandWeapon.weaponIce2; //casts ice 2
		playerOffHand.offHandBolt1 = offHandWeapon.weaponBolt1;
		playerOffHand.offHandFire1 = offHandWeapon.weaponFire1;
		playerOffHand.offHandIce1 = offHandWeapon.weaponIce1;
		playerOffHand.offHandFire2 = offHandWeapon.weaponFire2;
		playerOffHand.offHandHolyCast = offHandWeapon.weaponHolyCast;
		playerOffHand.offHandMateriaBlade = offHandWeapon.weaponMateriaBlade; //cloud subset
		//playerOffHand.offHand add status to user
		playerOffHand.offHandAutoProtect = offHandWeapon.weaponAutoProtect;
		playerOffHand.offHandAutoHaste = offHandWeapon.weaponAutoHaste;
		playerOffHand.offHandAutoShell = offHandWeapon.weaponAutoShell;
		playerOffHand.offHandAutoRegen = offHandWeapon.weaponAutoRegen;
		playerOffHand.offHandAutoFaith = offHandWeapon.weaponAutoFaith;
		playerOffHand.offHandStartPetrify = offHandWeapon.weaponStartPetrify; //start Petrified
	}
	else if( equipType == 2 )//shield select
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Shield ---\n"
				<< "\n"
			<< "0.) NONE\n"
			<< "1.) Escutcheon       -- 10 P Ev, 3 M Ev\n"
			<< "2.) Buckler          -- 11 P Ev, 3 M Ev\n" 
			<< "3.) Bronze Shield    -- 16 P Ev\n"
			<< "4.) Round Shield     -- 19 P Ev\n"
			<< "5.) Mythril Shield   -- 22 P Ev, 5 M Ev\n"
			<< "6.) Gold Shield      -- 25 P Ev\n"
			<< "7.) Ice Shield       -- 28 P Ev,  A: Ice,  H: Fire,  W: Lit\n"
			<< "8.) Flame Shield     -- 31 P Ev,  A: Fire,  H: Ice,  W: Water\n"
			<< "9.) Aegis Shield     -- 10 P Ev,  50 M Ev, MA +1\n"
			<< "10.) Diamond Shield  -- 34 P Ev,  15 M Ev\n"
			<< "11.) Platina Shield  -- 37 P Ev,  10 M Ev\n"
			<< "12.) Crystal Shield  -- 40 P Ev, 15 M Ev\n"
			<< "13.) Genji Shield    -- 43 P Ev\n"
			<< "14.) Kaiser Plate    -- 46 P Ev,  20 M Ev,  S: Fire/Ice/Lit\n"
			<< "15.) Venetian Shield -- 50 P Ev,  25 M Ev,  H: Fire/Lit/Ice\n"
			<< "16.) Escutcheon 2    -- 75 P Ev,  50 M Ev\n"
			<< "Phy Evade (P Ev), Magic Evade (M Ev), Half (H), Strengthen (S), Absorb (A), Weak (W)\n" 
			)
			&& ( !(cin >> equipAction) ||  equipAction < 0 || equipAction > 16 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0)
		{
			playerOffHand.offHandName = "NONE";
			playerOffHand.offHandPhyEvade = 0;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = false;
			playerOffHand.offHandEffectBool = false;
			offHandType = "NULL";
		}
		else if( equipAction == 1)
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Escutcheon";
			playerOffHand.offHandPhyEvade = 10;
			playerOffHand.offHandMagEvade = 3;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 2)
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Buckler";
			playerOffHand.offHandPhyEvade = 13;
			playerOffHand.offHandMagEvade = 3;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 3)
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Bronze Shield";
			playerOffHand.offHandPhyEvade = 16;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 4)
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Round Shield";
			playerOffHand.offHandPhyEvade = 19;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 5 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Mythril Shield";
			playerOffHand.offHandPhyEvade = 22;
			playerOffHand.offHandMagEvade = 5;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 6)
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Gold Shield";
			playerOffHand.offHandPhyEvade = 25;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 7 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Ice Shield";
			playerOffHand.offHandPhyEvade = 28;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = true;
			playerOffHand.offHandAbsorbIce = true;
			playerOffHand.offHandHalfFire = true;
			playerOffHand.offHandWeakLightning = true;
		}
		else if( equipAction == 8 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Flame Shield";
			playerOffHand.offHandPhyEvade = 31;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = true;
			playerOffHand.offHandAbsorbFire = true;
			playerOffHand.offHandHalfIce = true;
			playerOffHand.offHandWeakWater = true;
		}
		else if( equipAction == 9 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Aegis Shield";
			playerOffHand.offHandPhyEvade = 10;
			playerOffHand.offHandMagEvade = 50;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
			playerOffHand.offHandMA = 1;
		}
		else if( equipAction == 10 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Diamond Shield";
			playerOffHand.offHandPhyEvade = 34;
			playerOffHand.offHandMagEvade = 15;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 11 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Platina Shield";
			playerOffHand.offHandPhyEvade = 37;
			playerOffHand.offHandMagEvade = 10;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 12 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Crystal Shield";
			playerOffHand.offHandPhyEvade = 40;
			playerOffHand.offHandMagEvade = 15;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 13)
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Genji Shield";
			playerOffHand.offHandPhyEvade = 43;
			playerOffHand.offHandMagEvade = 0;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
		else if( equipAction == 14 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Kaiser Plate";
			playerOffHand.offHandPhyEvade = 46;
			playerOffHand.offHandMagEvade = 20;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = true;
			playerOffHand.offHandFireUp = true;
			playerOffHand.offHandLightningUp = true;
			playerOffHand.offHandIceUp = true;
		}
		else if( equipAction == 15 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Venetian Shield";
			playerOffHand.offHandPhyEvade = 50;
			playerOffHand.offHandMagEvade = 25;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = true;
			playerOffHand.offHandHalfFire = true;
			playerOffHand.offHandHalfIce = true;
			playerOffHand.offHandHalfLightning = true;
		}
		else if( equipAction == 16 )
		{	
			offHandType = "Shield";
			playerOffHand.offHandName = "Escutcheon 2";
			playerOffHand.offHandPhyEvade = 75;
			playerOffHand.offHandMagEvade = 50;
			playerOffHand.offHand = true;
			playerOffHand.offHandEffectBool = false;
		}
	}
}


//need to fix this is when ribbons are added
class HeadSlot //creates head equipment items
{
public:
	
	bool head; 
	string headName;
	string headType;
	int headLife;
	int headMP;
	int headPA;
	int headMA;
	int headSpeed;
	bool headDarknessBlock;
	bool headSleepBlock;
	bool headSilenceBlock;
	bool headDontActBlock;
	bool headDontMoveBlock;
	bool headDeadBlock;
	bool headPetrifyBlock;
	bool headInviteBlock;
	bool headConfusionBlock;
	bool headBloodSuckBlock;
	bool headStopBlock;
	bool headBerserkBlock;
	bool headCharmBlock;
	bool headUndeadBlock;
	bool headFrogBlock;
	bool headPoisonBlock;
	bool headSlowBlock;
	bool headDeathSentenceBlock;

	HeadSlot()
	{
		head= false; 
		headName= "";
		headType= "";
		headLife = 0;
		headMP = 0;
		headPA = 0;
		headMA = 0;
		headSpeed = 0;
		headDarknessBlock= false;
		headSleepBlock= false;
		headSilenceBlock= false;
		headDontActBlock= false;
		headDontMoveBlock= false;
		headDeadBlock= false;
		headPetrifyBlock= false;
		headInviteBlock= false;
		headConfusionBlock= false;
		headBloodSuckBlock= false;
		headStopBlock= false;
		headBerserkBlock= false;
		headCharmBlock= false;
		headUndeadBlock= false;
		headFrogBlock= false;
		headPoisonBlock= false;
		headSlowBlock= false;
		headDeathSentenceBlock= false;
	}

	void headEquip( HeadSlot &playerHead, Player unit );
};

void HeadSlot::headEquip( HeadSlot &playerHead, Player unit )
{
	playerHead.head= false; 
	playerHead.headName= "NONE";
	playerHead.headType= "";
	playerHead.headLife = 0;
	playerHead.headMP = 0;
	playerHead.headPA = 0;
	playerHead.headMA = 0;
	playerHead.headSpeed = 0;
	playerHead.headDarknessBlock= false;
	playerHead.headSleepBlock= false;
	playerHead.headSilenceBlock= false;
	playerHead.headDontActBlock= false;
	playerHead.headDontMoveBlock= false;
	playerHead.headDeadBlock= false;
	playerHead.headPetrifyBlock= false;
	playerHead.headInviteBlock= false;
	playerHead.headConfusionBlock= false;
	playerHead.headBloodSuckBlock= false;
	playerHead.headStopBlock= false;
	playerHead.headBerserkBlock= false;
	playerHead.headCharmBlock= false;
	playerHead.headUndeadBlock= false;
	playerHead.headFrogBlock= false;
	playerHead.headPoisonBlock= false;
	playerHead.headSlowBlock= false;
	playerHead.headDeathSentenceBlock= false;

	int equipAction = 0;
	int equipRibbon = 0;

	if( unit.sex == "Female" )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " Helmet Select ---\n"
				<< "\n" << "Equip Ribbon?   1.) Yes   2.) No\n" )
			&& ( !(cin >> equipRibbon) || equipRibbon < 1 || equipRibbon > 2  ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipRibbon == 1 )
		{
			while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Ribbon ---\n"
				<< "\n"
				<< "1.) Cachusha -- HP +20" << "   Block: Dead, Petrify, Invite, Confusion, "
				<< "Blood Suck, Stop, Berserk, Charm, Sleep\n" << "\n"
				<< "2.) Barette -- HP +20" << "   Block: Undead, Darkness, Silence, Frog, Poison, "
				<< "Slow, Don't Act, Don't Move, Death Sentence\n" << "\n"
				<< "3.) Ribbon -- HP +10" << "   Block: Dead, Undead, Petrify, Invite, Darkness, Confusion, Silence, Blood Suck, Frog, Poison, "
				<< "Slow, Stop, Berserk, Charm, Sleep, Don't Move, Don't Act, Death Sentence\n" << "\n"
				<< "4.) Select Hat/Helmet\n"
				)
				&& ( !(cin >> equipAction) || 
				equipAction < 1 || equipAction > 4 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if( equipAction == 1)
			{
				playerHead.headName = "Cachusha";
				playerHead.headLife = 20;
				playerHead.head = true;
				
				
				playerHead.headDeadBlock = true;
				playerHead.headPetrifyBlock = true;
				playerHead.headInviteBlock = true;
				playerHead.headConfusionBlock = true;
				playerHead.headBloodSuckBlock = true;
				playerHead.headStopBlock = true;
				playerHead.headBerserkBlock = true;
				playerHead.headCharmBlock = true;
				playerHead.headSleepBlock = true;

			}
			else if( equipAction == 2)
			{
				playerHead.headName = "Barette";
				playerHead.headLife = 20;
				playerHead.head = true;

				playerHead.headDarknessBlock = true;
				
				playerHead.headSilenceBlock = true;
				playerHead.headDontActBlock = true;
				playerHead.headDontMoveBlock = true;
				playerHead.headUndeadBlock = true;
				playerHead.headFrogBlock = true;
				playerHead.headPoisonBlock = true;
				playerHead.headSlowBlock = true;
				playerHead.headDeathSentenceBlock = true;

			}
			else if( equipAction == 3)
			{
				playerHead.headName = "Ribbon";
				playerHead.headLife = 10;
				playerHead.head = true;
				playerHead.headDarknessBlock = true;
				playerHead.headSleepBlock = true;
				playerHead.headSilenceBlock = true;
				playerHead.headDontActBlock = true;
				playerHead.headDontMoveBlock = true;
				playerHead.headDeadBlock = true;
				playerHead.headPetrifyBlock = true;
				playerHead.headInviteBlock = true;
				playerHead.headConfusionBlock = true;
				playerHead.headBloodSuckBlock = true;
				playerHead.headStopBlock = true;
				playerHead.headBerserkBlock = true;
				playerHead.headCharmBlock = true;
				playerHead.headUndeadBlock = true;
				playerHead.headFrogBlock = true;
				playerHead.headPoisonBlock = true;
				playerHead.headSlowBlock = true;
				playerHead.headDeathSentenceBlock = true;
			}
		}
	}

	if( unit.sex == "Male" || equipRibbon == 2 || equipAction == 4 )
	{
		if( ( unit.helmet == true ) && ( unit.hat == false ) )
		{
			while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Helmet ---\n"
				<< "\n"
				<< " 0.) NONE\n"
				<< " 1.) Leather Helmet  --  HP  +10\n" 
				<< " 2.) Bronze Helmet   --  HP  +20\n"
				<< " 3.) Iron Helmet     --  HP  +30\n"  
				<< " 4.) Barbuta         --  HP  +40\n"
				<< " 5.) Mythril Helmet  --  HP  +50\n"  
				<< " 6.) Gold Helmet     --  HP  +60\n"
				<< " 7.) Cross Helmet    --  HP  +70\n" 
				<< " 8.) Diamond Helmet  --  HP  +80\n"
				<< " 9.) Platina Helmet  --  HP  +90\n"  
				<< "10.) Circlet         --  HP +100\n"
				<< "11.) Crystal Helmet  --  HP +120\n"  
				<< "12.) Genji Helmet    --  HP +130\n"
				<< "13.) Grand Helmet    --  HP +150, Block: Darkness & Sleep\n" 
				)
				&& ( !(cin >> equipAction) || 
				equipAction < 0 || equipAction > 13 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if( equipAction == 0)
			{
				playerHead.head= false; 
				playerHead.headName= "NONE";
				playerHead.headType= "";
				playerHead.headLife = 0;
				playerHead.headMP = 0;
				playerHead.headPA = 0;
				playerHead.headMA = 0;
				playerHead.headSpeed = 0;
				playerHead.headDarknessBlock= false;
				playerHead.headSleepBlock= false;
				playerHead.headSilenceBlock= false;
				playerHead.headDontActBlock= false;
				playerHead.headDontMoveBlock= false;
				playerHead.headDeadBlock= false;
				playerHead.headPetrifyBlock= false;
				playerHead.headInviteBlock= false;
				playerHead.headConfusionBlock= false;
				playerHead.headBloodSuckBlock= false;
				playerHead.headStopBlock= false;
				playerHead.headBerserkBlock= false;
				playerHead.headCharmBlock= false;
				playerHead.headUndeadBlock= false;
				playerHead.headFrogBlock= false;
				playerHead.headPoisonBlock= false;
				playerHead.headSlowBlock= false;
				playerHead.headDeathSentenceBlock= false;
			}
			if( equipAction == 1)
			{	
				playerHead.headName = "Leather Helmet";
				playerHead.headLife = 10;
				playerHead.head = true;
			}
			else if( equipAction == 2)
			{	
				playerHead.headName = "Bronze Helmet";
				playerHead.headLife = 20;
				playerHead.head = true;
			}
			else if( equipAction == 3)
			{	
				playerHead.headName = "Iron Helmet";
				playerHead.headLife = 30;
				playerHead.head = true;
			}
			else if( equipAction == 4)
			{	
				playerHead.headName = "Barbuta";
				playerHead.headLife = 40;
				playerHead.head = true;
			}
			else if( equipAction == 5 )
			{	
				playerHead.headName = "Mythril Helmet";
				playerHead.headLife = 50;
				playerHead.head = true;
			}
			else if( equipAction == 6 )
			{	
				playerHead.headName = "Gold Helmet";
				playerHead.headLife = 60;
				playerHead.head = true;
			}
			else if( equipAction == 7 )
			{	
				playerHead.headName = "Cross Helmet";
				playerHead.headLife = 70;
				playerHead.head = true;
			}
			else if( equipAction == 8 )
			{	
				playerHead.headName = "Diamond Helmet";
				playerHead.headLife = 80;
				playerHead.head = true;
			}
			else if( equipAction == 9 )
			{	
				playerHead.headName = "Platina Helmet";
				playerHead.headLife = 90;
				playerHead.head = true;
			}
			else if( equipAction == 10 )
			{	
				playerHead.headName = "Circlet";
				playerHead.headLife = 100;
				playerHead.head = true;
			}
			else if( equipAction == 11 )
			{	
				playerHead.headName = "Crystal Helmet";
				playerHead.headLife = 120;
				playerHead.head = true;
			}
			else if( equipAction == 12 )
			{	
				playerHead.headName = "Genji Helmet";
				playerHead.headLife = 130;
				playerHead.head = true;
			}
			else if( equipAction == 13)
			{	
				playerHead.headName = "Grand Helmet";
				playerHead.headLife = 150;
				playerHead.head = true;
				playerHead.headDarknessBlock = true;
				playerHead.headSleepBlock = true;
			}
		}
		else if( ( unit.helmet == false ) && ( unit.hat == true ) ) 
		{
			while( ( cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Hat ---\n"
				<< "\n"
				<< "0.) NONE\n"
				<< "1.) Leather Hat     -- HP  +10\n" 
				<< "2.) Feather Hat     -- HP  +16, MP +5\n"
				<< "3.) Red Hood        -- HP  +24, MP +8\n"
				<< "4.) Headgear        -- HP  +32, PA +1\n"
				<< "5.) Triangle Hat    -- HP  +40, MP +12, MA +1\n"
				<< "6.) Green Beret     -- HP  +48, Speed +1\n"
				<< "7.) Twist Headband  -- HP  +56, PA +2\n"
				<< "8.) Holy Miter      -- HP  +64, MP +20, MA +1\n"
				<< "9.) Black Hood      -- HP  +72\n"
				<< "10.) Golden Hairpin -- HP  +80, MP +50, Block: Silence\n"
				<< "11.) Flash Hat      -- HP  +88, MP +15, MA +1, Speed +1\n"
				<< "12.) Thief Hat      -- HP +100, Speed +2, Block: Don't Move Don't Act\n"
				) && ( !(cin >> equipAction) || 
				equipAction < 0 || equipAction > 12 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if( equipAction == 0)
			{
				playerHead.head= false; 
				playerHead.headName= "NONE";
				playerHead.headType= "";
				playerHead.headLife = 0;
				playerHead.headMP = 0;
				playerHead.headPA = 0;
				playerHead.headMA = 0;
				playerHead.headSpeed = 0;
				playerHead.headDarknessBlock= false;
				playerHead.headSleepBlock= false;
				playerHead.headSilenceBlock= false;
				playerHead.headDontActBlock= false;
				playerHead.headDontMoveBlock= false;
				playerHead.headDeadBlock= false;
				playerHead.headPetrifyBlock= false;
				playerHead.headInviteBlock= false;
				playerHead.headConfusionBlock= false;
				playerHead.headBloodSuckBlock= false;
				playerHead.headStopBlock= false;
				playerHead.headBerserkBlock= false;
				playerHead.headCharmBlock= false;
				playerHead.headUndeadBlock= false;
				playerHead.headFrogBlock= false;
				playerHead.headPoisonBlock= false;
				playerHead.headSlowBlock= false;
				playerHead.headDeathSentenceBlock= false;
			}
			if( equipAction == 1)
			{	
				playerHead.headName = "Leather Hat";
				playerHead.head = true;
				playerHead.headLife = 8;
			}
			else if( equipAction == 2)
			{	
				playerHead.headName = "Feather Hat";
				playerHead.head = true;
				playerHead.headLife = 16;
				playerHead.headMP = 5;
			}
			else if( equipAction == 3)
			{	
				playerHead.headName = "Red Hood";
				playerHead.head = true;
				playerHead.headLife = 24;
				playerHead.headMP = 8;
			}
			else if( equipAction == 4 )
			{	
				playerHead.headName = "Headgear";
				playerHead.head = true;
				playerHead.headLife = 32;
				playerHead.headMP = 0;
				playerHead.headPA = 1;
			}
			else if( equipAction == 5 )
			{	
				playerHead.headName = "Triangle Hat";
				playerHead.head = true;
				playerHead.headLife = 40;
				playerHead.headMP = 12;
				playerHead.headMA = 1;
			}
			else if( equipAction == 6 )
			{	
				playerHead.headName = "Green Beret";
				playerHead.head = true;
				playerHead.headLife = 48;
				playerHead.headMP = 0;
				playerHead.headSpeed = 1;
			}
			else if( equipAction == 7 )
			{	
				playerHead.headName = "Twist Headband";
				playerHead.head = true;
				playerHead.headLife = 56;
				playerHead.headMP = 0;
				playerHead.headPA = 2;
			}
			else if( equipAction ==  8 )
			{	
				playerHead.headName = "Holy Miter";
				playerHead.head = true;
				playerHead.headLife = 64;
				playerHead.headMP = 20;
				playerHead.headMA = 1;
			}
			else if( equipAction == 9 )
			{	
				playerHead.headName = "Black Hood";
				playerHead.head = true;
				playerHead.headLife = 72;
				playerHead.headMP = 0;
			}
			else if( equipAction == 10 )
			{	
				playerHead.headName = "Golden Hairpin";
				playerHead.head = true;
				playerHead.headLife = 80;
				playerHead.headMP = 50;
				playerHead.headSilenceBlock = true;
			}
			else if( equipAction == 11 )
			{	
				playerHead.headName = "Flash Hat";
				playerHead.head = true;
				playerHead.headLife = 88;
				playerHead.headMP = 15;
				playerHead.headMA = 1;
				playerHead.headSpeed = 1;
			}
			else if( equipAction == 12 )
			{	
				playerHead.headName = "Thief Hat";
				playerHead.head = true;
				playerHead.headLife = 100;
				playerHead.headMP = 0;
				playerHead.headSpeed = 2;
				playerHead.headDontActBlock = true;
				playerHead.headDontMoveBlock = true;
			}
		}
	}
}


//need to think more about how to add equipment effects
class BodySlot //creates armor equipment object
{
public:
	bool body;
	string bodyName;
	string bodyType;
	int bodyLife;
	int bodyMP;
	int bodyMA;
	int bodyPA;
	int bodySpeed;
	bool bodyAutoReflect;
	bool bodyDeadBlock;
	bool bodyStopBlock;
	bool bodyLightningBlock;
	bool bodyEarthUp;
	bool bodyEarthAbsorb;
	bool bodyStartTransparent;
	bool bodyHolyAbsorb;
	bool bodyFireHalf;
	bool bodyIceHalf;
	bool bodyLightningHalf;
	bool bodyFireUp;
	bool bodyLightningUp;
	bool bodyIceUp;
	bool bodyAutoProtect;
	bool bodyAutoShell;

	BodySlot()
	{
		bodyName = "NONE";
		bodyLife = 0;
		bodyMP = 0;
		body = false;
		bodyPA = 0;
		bodyMA = 0;
		bodySpeed = 0;
	}

	void bodyEquip( BodySlot &playerBody, Player unit );
};

void BodySlot::bodyEquip( BodySlot &playerBody, Player unit )
{

	playerBody.body = false;
	playerBody.bodyName = "NONE";
	playerBody.bodyType = "";
	playerBody.bodyLife = 0;
	playerBody.bodyMP = 0;
	playerBody.bodyPA = 0;
	playerBody.bodyMA = 0;
	playerBody.bodySpeed = 0;
	playerBody.bodyAutoReflect = false;
	playerBody.bodyDeadBlock = false;
	playerBody.bodyStopBlock = false;
	playerBody.bodyLightningBlock = false;
	playerBody.bodyEarthUp = false;
	playerBody.bodyEarthAbsorb = false;
	playerBody.bodyStartTransparent = false;
	playerBody.bodyHolyAbsorb = false;
	playerBody.bodyFireHalf = false;
	playerBody.bodyIceHalf = false;
	playerBody.bodyLightningHalf = false;
	playerBody.bodyFireUp = false;
	playerBody.bodyLightningUp = false;
	playerBody.bodyIceUp = false;
	playerBody.bodyAutoProtect = false;
	playerBody.bodyAutoShell = false;

	int equipAction = 0;
	int equipType = 0;

	cout << "\n"
		<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " can equip: ";
	if( unit.armor == true || unit.equipArmor == true )
		cout << "Armor, ";
	if( unit.clothes == true )
		cout << "Clothes, ";
	if( unit.robe == true )
		cout << "Robe, ";

	while( (cout << "\n"
			<< "   --- Select Armor Type ---\n"
			<< "\n" 
			<< "0.) NONE" << setw(20) << "1.) Armor\n" 
			<< "2.) Clothes" << setw(17) << "3.) Robes\n" )
			&& ( !(cin >> equipType ) || equipType < 0 || equipType > 3
			|| equipType == 1 && unit.armor == false  && unit.equipArmor == false 
			|| equipType == 2 && unit.clothes == false
			|| equipType == 3 && unit.robe == false
			) )
			{
				
				cout << "\n"
					<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " can equip: ";
				if( unit.armor == true || unit.equipArmor == true )
					cout << "Armor, ";
				if( unit.clothes == true )
					cout << "Clothes, ";
				if( unit.robe == true )
					cout << "Robe, ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}

	if( equipType == 1 )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Armor ---\n"
				<< "\n"
			 << " 0.) NONE\n"
			 << " 1.) Leather Armor -- HP  +10\n"
			 << " 2.) Linen Cuirass -- HP  +20\n" 
			 << " 3.) Bronze Armor  -- HP  +30\n"
			 << " 4.) Chain Mail    -- HP  +40\n" 
			 << " 5.) Mythril Armor -- HP  +50\n"
			 << " 6.) Plate Mail    -- HP  +60\n" 
			 << " 7.) Gold Armor    -- HP  +70\n"
			 << " 8.) Diamond Armor -- HP  +80\n" 
			 << " 9.) Platina Armor -- HP  +90\n"
			 << "10.) Carabini Mail -- HP +100\n" 
			 << "11.) Crystal Mail  -- HP +110\n"
			 << "12.) Genji Armor   -- HP +150\n"  
			 << "13.) Reflect Armor -- HP +130, Reflect\n"
			 << "14.) Maximillian   -- HP +200\n"
			) && ( !(cin >> equipAction) || equipAction < 0 || equipAction > 14 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0)
		{
			playerBody.bodyName = "NONE";
			playerBody.bodyLife = 0;
			playerBody.body = false;
		}
		else if( equipAction == 1)
		{	
			playerBody.bodyName = "Leather Armor";
			playerBody.bodyLife = 10;
			playerBody.body = true;
		}
		else if( equipAction == 2)
		{	
			playerBody.bodyName = "Linen Cuirass";
			playerBody.bodyLife = 20;
			playerBody.body = true;
		}
		else if( equipAction == 3)
		{	
			playerBody.bodyName = "Bronze Armor";
			playerBody.bodyLife = 30;
			playerBody.body = true;
		}
		else if( equipAction == 4)
		{	
			playerBody.bodyName = "Chain Mail";
			playerBody.bodyLife = 40;
			playerBody.body = true;
		}
		else if( equipAction == 5 )
		{	
			playerBody.bodyName = "Mythril Armor";
			playerBody.bodyLife = 50;
			playerBody.body = true;
		}
		else if( equipAction == 6 )
		{	
			playerBody.bodyName = "Plate Mail";
			playerBody.bodyLife = 60;
			playerBody.body = true;
		}
		else if( equipAction == 7 )
		{	
			playerBody.bodyName = "Gold Armor";
			playerBody.bodyLife = 70;
			playerBody.body = true;
		}
		else if( equipAction == 8 )
		{	
			playerBody.bodyName = "Diamond Armor";
			playerBody.bodyLife = 80;
			playerBody.body = true;
		}
		else if( equipAction == 9 )
		{	
			playerBody.bodyName = "Platina Armor";
			playerBody.bodyLife = 90;
			playerBody.body = true;
		}
		else if( equipAction == 10 )
		{	
			playerBody.bodyName = "Carabini Mail";
			playerBody.bodyLife = 100;
			playerBody.body = true;
		}
		else if( equipAction == 11 )
		{	
			playerBody.bodyName = "Crystal Mail";
			playerBody.bodyLife = 110;
			playerBody.body = true;
		}
		else if( equipAction == 12)
		{	
			playerBody.bodyName = "Genji Armor";
			playerBody.bodyLife = 150;
			playerBody.body = true;
		}
		else if( equipAction == 13)
		{	
			playerBody.bodyName = "Reflect Mail";
			playerBody.bodyLife = 130;
			playerBody.body = true;
			playerBody.bodyAutoReflect = true;
		}
		else if( equipAction == 14)
		{	
			playerBody.bodyName = "Maximillian";
			playerBody.bodyLife = 200;
			playerBody.body = true;
		}
	}
	else if( equipType == 2)
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Clothes ---\n"
				<< "\n"
			<< " 0.) NONE\n"  
			<< " 1.) Clothes        -- HP   +5\n"
			<< " 2.) Leather Outfit -- HP  +10\n"  
			<< " 3.) Leather Vest   -- HP  +18\n"
			<< " 4.) Chain Vest     -- HP  +24\n"    
			<< " 5.) Mythril Vest   -- HP  +30\n"
			<< " 6.) Adaman Vest    -- HP  +36\n"  
			<< " 7.) Wizard Outfit  -- HP  +42, MP +15\n"
			<< " 8.) Brigandine     -- HP  +50\n"  
			<< " 9.) Judo Outfit    -- HP  +60, PA +1, Block: Dead\n"
			<< "10.) Power Sleeve   -- HP  +70, PA +2\n" 
			<< "11.) Earth Clothes  -- HP  +85, MP +10, Absorb/Strengthen: Earth\n"
			<< "12.) Secret Clothes -- HP  +20, Speed +2\n"
			<< "13.) Black Costume  -- HP +100, Block: Stop\n"
			<< "14.) Rubber Costume -- HP +150, MP +50, Block: Lightning\n" 
			) && ( !(cin >> equipAction) || equipAction < 0 || equipAction > 14 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0)
		{
			playerBody.bodyName = "NONE";
			playerBody.bodyLife = 0;
			playerBody.body = false;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 1 )
		{
			playerBody.bodyName = "Clothes";
			playerBody.bodyLife = 5;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 2 )
		{
			playerBody.bodyName = "Leather Outfit";
			playerBody.bodyLife = 10;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 3 )
		{
			playerBody.bodyName = "Leather Vest";
			playerBody.bodyLife = 18;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 4 )
		{
			playerBody.bodyName = "Chain Vest";
			playerBody.bodyLife = 24;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 5 )
		{
			playerBody.bodyName = "Mythril Vest";
			playerBody.bodyLife = 30;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 6 )
		{
			playerBody.bodyName = "Adaman Vest";
			playerBody.bodyLife = 36;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 7 )
		{
			playerBody.bodyName = "Wizard Outfit";
			playerBody.bodyLife = 42;
			playerBody.body = true;
			playerBody.bodyMP = 15;
		}
		else if( equipAction == 8 )
		{
			playerBody.bodyName = "Brigandine";
			playerBody.bodyLife = 50;
			playerBody.body = true;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 9 )
		{
			playerBody.bodyName = "Judo Outfit";
			playerBody.bodyLife = 60;
			playerBody.body = true;
			playerBody.bodyMP = 0;
			playerBody.bodyPA = 1;
			playerBody.bodyDeadBlock = true;
		}
		else if( equipAction == 10 )
		{
			playerBody.bodyName = "Power Sleeve";
			playerBody.bodyLife = 70;
			playerBody.body = true;
			playerBody.bodyPA = 2;
		}
		else if( equipAction == 11 )
		{
			playerBody.bodyName = "Earth Clothes";
			playerBody.bodyLife = 85;
			playerBody.body = true;
			playerBody.bodyMP = 10;
			playerBody.bodyEarthAbsorb = true;
			playerBody.bodyEarthUp = true;
		}
		else if( equipAction == 12 )
		{
			playerBody.bodyName = "Secret Clothes";
			playerBody.bodyLife = 20;
			playerBody.body = true;
			playerBody.bodySpeed = 2;
			playerBody.bodyStartTransparent = true;
		}
		else if( equipAction == 13 )
		{
			playerBody.bodyName = "Black Costume";
			playerBody.bodyLife = 100;
			playerBody.body = true;
			playerBody.bodyStopBlock = true;
		}
		else if( equipAction == 14 )
		{
			playerBody.bodyName = "Rubber Costume";
			playerBody.bodyLife = 150;
			playerBody.body = true;
			playerBody.bodyLightningBlock = true;
			playerBody.bodyMP = 50;
		}
	}
	else if( equipType == 3 )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Robe ---\n"
				<< "\n" 
			<< "0.) NONE\n"
			<< "1.) Linen Robe     -- HP  +10, MP +10\n"
			<< "2.) Silk Robe      -- HP  +20, MP +16\n"  
			<< "3.) Wizard Robe    -- HP  +30, MP +22, MA +2\n"
			<< "4.) Chameleon Robe -- HP  +40, MP +28, Block: Dead, Absorb: Holy\n" 
			<< "5.) White Robe     -- HP  +50, MP +34, Half: Fire/Ice/Lit\n"
			<< "6.) Black Robe     -- HP  +60, MP +30, Strengthen: Fire/Ice/Lit\n"  
			<< "7.) Light Robe     -- HP  +75, MP +50\n"
			<< "8.) Robe of Lords  -- HP +100, MP +80, PA +2, MA +1, Protect, Shell\n"
			) && ( !(cin >> equipAction) || equipAction < 0 || equipAction > 8 ) )
		{
			cout << "Invalid answer. Enter a valid number.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0)
		{
			playerBody.bodyName = "NONE";
			playerBody.bodyLife = 0;
			playerBody.body = false;
			playerBody.bodyMP = 0;
		}
		else if( equipAction == 1)
		{	
			playerBody.bodyName = "Linen Robe";
			playerBody.bodyLife = 10;
			playerBody.body = true;
			playerBody.bodyMP = 10;
		}
		else if( equipAction == 2)
		{	
			playerBody.bodyName = "Silk Robe";
			playerBody.bodyLife = 20;
			playerBody.body = true;
			playerBody.bodyMP = 16;
		}
		else if( equipAction == 3)
		{	
			playerBody.bodyName = "Wizard Robe";
			playerBody.bodyLife = 30;
			playerBody.body = true;
			playerBody.bodyMP = 22;
			playerBody.bodyMA = 2;
		}
		else if( equipAction == 4)
		{	
			playerBody.bodyName = "Chameleon Robe";
			playerBody.bodyLife = 40;
			playerBody.body = true;
			playerBody.bodyMP = 28;
			playerBody.bodyHolyAbsorb = true;
			playerBody.bodyDeadBlock = true;
		}
		else if( equipAction == 5 )
		{	
			playerBody.bodyName = "White Robe";
			playerBody.bodyLife = 50;
			playerBody.body = true;
			playerBody.bodyMP = 34;
			playerBody.bodyFireHalf = true;
			playerBody.bodyIceHalf = true;
			playerBody.bodyLightningHalf = true;
		}
		else if( equipAction == 6 )
		{	
			playerBody.bodyName = "Black Robe";
			playerBody.bodyLife = 60;
			playerBody.body = true;
			playerBody.bodyMP = 30;
			playerBody.bodyFireUp = true;
			playerBody.bodyIceUp = true;
			playerBody.bodyLightningUp = true;
		}
		else if( equipAction == 7 )
		{	
			playerBody.bodyName = "White Robe";
			playerBody.bodyLife = 75;
			playerBody.body = true;
			playerBody.bodyMP = 50;
		}
		else if( equipAction == 8 )
		{	
			playerBody.bodyName = "Robe of Lords";
			playerBody.bodyLife = 100;
			playerBody.body = true;
			playerBody.bodyMP = 80;
			playerBody.bodyAutoProtect = true;
			playerBody.bodyAutoShell = true;
			playerBody.bodyPA = 2;
			playerBody.bodyMA = 1;
		}
	}//end robe selection

}


class AccSlot //creates Accessory
{
public:
	
	bool accessory; //accessory slot
	string accName;
	string accType;
	int accPhyEvade;
	int accMagEvade;
	int accMove;
	int accPA;
	int accSpeed;
	int accMA;
	int accJump;
	bool accDontMoveBlock;
	bool accDontActBlock;
	bool accLightningBlock;
	bool accAutoReflect;
	bool accSleepBlock;
	bool accDeathSentenceBlock;
	bool accSilenceBlock;
	bool accBerserkBlock;
	bool accAutoUndead;
	bool accInviteBlock;
	bool accStartReraise;
	bool accDeadBlock;
	bool accDarknessBlock;
	bool accSlowBlock;
	bool accPetrifyBlock;
	bool accStopBlock;
	bool accUndeadBlock;
	bool accBloodSuckBlock;
	bool accFrogBlock;
	bool accPoisonBlock;
	bool accConfusionBlock;
	bool accCharmBlock;
	bool accFireUp;
	bool accIceUp;
	bool accWaterUp;
	bool accLightningUp;
	bool accEarthUp;
	bool accWindUp;
	bool accHolyUp;
	bool accDarkUp;
	bool accDarkHalf;
	bool accStartTransparent;
	bool accAutoRegen;
	bool accAutoReraise;
	bool accAutoFloat;
	bool accAutoProtect;
	bool accAutoShell;
	bool accAutoHaste;

	AccSlot()
	{

		accessory = false; //accessory slot
		accName = "NONE";
		accType = "";
		accPhyEvade = 0;
		accMagEvade = 0;
		accMove = 0;
		accPA = 0;
		accSpeed = 0;
		accMA = 0;
		accJump = 0;
		accDontMoveBlock = false;
		accDontActBlock = false;
		accLightningBlock = false;
		accAutoReflect = false;
		accSleepBlock = false;
		accDeathSentenceBlock = false;
		accSilenceBlock = false;
		accBerserkBlock = false;
		accAutoUndead = false;
		accInviteBlock = false;
		accStartReraise = false;
		accDeadBlock = false;
		accDarknessBlock = false;
		accSlowBlock = false;
		accPetrifyBlock = false;
		accStopBlock = false;
		accUndeadBlock = false;
		accBloodSuckBlock = false;
		accFrogBlock = false;
		accPoisonBlock = false;
		accConfusionBlock = false;
		accCharmBlock = false;
		accFireUp = false;
		accIceUp = false;
		accWaterUp = false;
		accLightningUp = false;
		accEarthUp = false;
		accWindUp = false;
		accHolyUp = false;
		accDarkUp = false;
		accDarkHalf = false;
		accStartTransparent = false;
		accAutoRegen = false;
		accAutoReraise = false;
		accAutoFloat = false;
		accAutoProtect = false;
		accAutoShell = false;
		accAutoHaste = false;

	}

	void accEquip( AccSlot &playerAcc, Player unit );
};

void AccSlot::accEquip( AccSlot &playerAcc, Player unit )
{
	playerAcc.accessory = false; //accessory slot
	playerAcc.accName = "NONE";
	playerAcc.accType = "";
	playerAcc.accPhyEvade = 0;
	playerAcc.accMagEvade = 0;
	playerAcc.accMove = 0;
	playerAcc.accPA = 0;
	playerAcc.accSpeed = 0;
	playerAcc.accMA = 0;
	playerAcc.accJump = 0;
	playerAcc.accDontMoveBlock = false;
	playerAcc.accDontActBlock = false;
	playerAcc.accLightningBlock = false;
	playerAcc.accAutoReflect = false;
	playerAcc.accSleepBlock = false;
	playerAcc.accDeathSentenceBlock = false;
	playerAcc.accSilenceBlock = false;
	playerAcc.accBerserkBlock = false;
	playerAcc.accAutoUndead = false;
	playerAcc.accInviteBlock = false;
	playerAcc.accStartReraise = false;
	playerAcc.accDeadBlock = false;
	playerAcc.accDarknessBlock = false;
	playerAcc.accSlowBlock = false;
	playerAcc.accPetrifyBlock = false;
	playerAcc.accStopBlock = false;
	playerAcc.accUndeadBlock = false;
	playerAcc.accBloodSuckBlock = false;
	playerAcc.accFrogBlock = false;
	playerAcc.accPoisonBlock = false;
	playerAcc.accConfusionBlock = false;
	playerAcc.accCharmBlock = false;
	playerAcc.accFireUp = false;
	playerAcc.accIceUp = false;
	playerAcc.accWaterUp = false;
	playerAcc.accLightningUp = false;
	playerAcc.accEarthUp = false;
	playerAcc.accWindUp = false;
	playerAcc.accHolyUp = false;
	playerAcc.accDarkUp = false;
	playerAcc.accDarkHalf = false;
	playerAcc.accStartTransparent = false;
	playerAcc.accAutoRegen = false;
	playerAcc.accAutoReraise = false;
	playerAcc.accAutoFloat = false;
	playerAcc.accAutoProtect = false;
	playerAcc.accAutoShell = false;
	playerAcc.accAutoHaste = false;

	int equipMenu = 0;
	int equipAction = 0;
	
	while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Accesory Type ---\n"
				<< "\n"
		<< "0.) NONE" << setw(35) << "1.) Shoes\n"
		<< "2.) Gauntlet/Ring/Armlet" << setw(21) << "3.) Mantles\n"
		<< "4.) Perfumes\n"
		) && ( !( cin >> equipMenu ) || equipMenu < 0 || equipMenu > 4
		|| ( equipMenu == 4 && unit.sex == "Male" ) ) )
	{
		cout << "Invalid answer. Only Females can equip Perfumes.\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	if( equipMenu == 0 )
	{
		playerAcc.accessory = false; //accessory slot
		playerAcc.accName = "NONE";
		playerAcc.accType = "";
		playerAcc.accPhyEvade = 0;
		playerAcc.accMagEvade = 0;
		playerAcc.accMove = 0;
		playerAcc.accPA = 0;
		playerAcc.accSpeed = 0;
		playerAcc.accMA = 0;
		playerAcc.accJump = 0;
		playerAcc.accDontMoveBlock = false;
		playerAcc.accDontActBlock = false;
		playerAcc.accLightningBlock = false;
		playerAcc.accAutoReflect = false;
		playerAcc.accSleepBlock = false;
		playerAcc.accDeathSentenceBlock = false;
		playerAcc.accSilenceBlock = false;
		playerAcc.accBerserkBlock = false;
		playerAcc.accAutoUndead = false;
		playerAcc.accInviteBlock = false;
		playerAcc.accStartReraise = false;
		playerAcc.accDeadBlock = false;
		playerAcc.accDarknessBlock = false;
		playerAcc.accSlowBlock = false;
		playerAcc.accPetrifyBlock = false;
		playerAcc.accStopBlock = false;
		playerAcc.accUndeadBlock = false;
		playerAcc.accBloodSuckBlock = false;
		playerAcc.accFrogBlock = false;
		playerAcc.accPoisonBlock = false;
		playerAcc.accConfusionBlock = false;
		playerAcc.accCharmBlock = false;
		playerAcc.accFireUp = false;
		playerAcc.accIceUp = false;
		playerAcc.accWaterUp = false;
		playerAcc.accLightningUp = false;
		playerAcc.accEarthUp = false;
		playerAcc.accWindUp = false;
		playerAcc.accHolyUp = false;
		playerAcc.accDarkUp = false;
		playerAcc.accDarkHalf = false;
		playerAcc.accStartTransparent = false;
		playerAcc.accAutoRegen = false;
		playerAcc.accAutoReraise = false;
		playerAcc.accAutoFloat = false;
		playerAcc.accAutoProtect = false;
		playerAcc.accAutoShell = false;
		playerAcc.accAutoHaste = false;
	}
	else if( equipMenu == 1 )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Shoes ---\n"
				<< "\n"
		<< "0.) NONE\n"  
		<< "1.) Battle Boots   -- Move +1\n"
		<< "2.) Spike Boots    -- Jump +1\n" 
		<< "3.) Germinas Boots -- Move +1, Jump +1\n"
		<< "4.) Rubber Shoes   -- Block: Don't Move Lightning\n"  
		<< "5.) Feather Boots  -- Auto-Float\n"
		<< "6.) Sprint Shoes   -- Speed +1\n" 
		<< "7.) Red Shoes      -- Move +1, MA +1\n"
		) && ( !( cin >> equipAction ) || equipAction < 0 || equipAction > 7 ) )
		{
			cout << "Invalid answer. Select valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0 )
		{
			playerAcc.accessory = false; //accessory slot
			playerAcc.accName = "NONE";
			playerAcc.accType = "";
			playerAcc.accPhyEvade = 0;
			playerAcc.accMagEvade = 0;
			playerAcc.accMove = 0;
			playerAcc.accPA = 0;
			playerAcc.accSpeed = 0;
			playerAcc.accMA = 0;
			playerAcc.accJump = 0;
			playerAcc.accDontMoveBlock = false;
			playerAcc.accDontActBlock = false;
			playerAcc.accLightningBlock = false;
			playerAcc.accAutoReflect = false;
			playerAcc.accSleepBlock = false;
			playerAcc.accDeathSentenceBlock = false;
			playerAcc.accSilenceBlock = false;
			playerAcc.accBerserkBlock = false;
			playerAcc.accAutoUndead = false;
			playerAcc.accInviteBlock = false;
			playerAcc.accStartReraise = false;
			playerAcc.accDeadBlock = false;
			playerAcc.accDarknessBlock = false;
			playerAcc.accSlowBlock = false;
			playerAcc.accPetrifyBlock = false;
			playerAcc.accStopBlock = false;
			playerAcc.accUndeadBlock = false;
			playerAcc.accBloodSuckBlock = false;
			playerAcc.accFrogBlock = false;
			playerAcc.accPoisonBlock = false;
			playerAcc.accConfusionBlock = false;
			playerAcc.accCharmBlock = false;
			playerAcc.accFireUp = false;
			playerAcc.accIceUp = false;
			playerAcc.accWaterUp = false;
			playerAcc.accLightningUp = false;
			playerAcc.accEarthUp = false;
			playerAcc.accWindUp = false;
			playerAcc.accHolyUp = false;
			playerAcc.accDarkUp = false;
			playerAcc.accDarkHalf = false;
			playerAcc.accStartTransparent = false;
			playerAcc.accAutoRegen = false;
			playerAcc.accAutoReraise = false;
			playerAcc.accAutoFloat = false;
			playerAcc.accAutoProtect = false;
			playerAcc.accAutoShell = false;
			playerAcc.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Battle Boots";
			playerAcc.accMove = 1;
		}
		else if( equipAction == 2 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Spike Boots";
			playerAcc.accJump = 1;
		}
		else if( equipAction == 3 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Germinas Boots";
			playerAcc.accMove = 1;
			playerAcc.accJump = 1;
		}
		else if( equipAction == 4 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Rubber Shoes";
			playerAcc.accDontMoveBlock = true;
			playerAcc.accLightningBlock = true;
		}
		else if( equipAction == 5 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Feather Boots";
			playerAcc.accAutoFloat = true;
		}
		else if( equipAction == 6 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Sprint Shoes";
			playerAcc.accSpeed = 1;
		}
		else if( equipAction == 7 )
		{
			playerAcc.accessory = true;
			playerAcc.accName = "Red Shoes";
			playerAcc.accMove = 1;
			playerAcc.accMA = 1;
		}
	}
	else if( equipMenu == 2 )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Accessory ---\n"
				<< "\n"
				<< " 0.) NONE\n"  
				<< " 1.) Power Wrist    -- PA +1\n"
				<< " 2.) Genji Gauntlet -- PA +2, MA +2\n" 
				<< " 3.) Magic Gauntlet -- MA +2\n"
				<< " 4.) Bracer         -- PA +3\n" 
				<< " 5.) Reflect Ring   -- Auto Reflect\n"
				<< " 6.) Defense Ring   -- Block: Sleep, Death Sentence\n"  
				<< " 7.) Magic Ring     -- Block: Silence Berserk\n"
				<< " 8.) Cursed Ring    -- PA +1, MA +1, Speed +1, Auto Undead\n"
				<< " 9.) Angel Ring     -- Reraise, Block: Dead Darkness\n"
				<< "10.) Diamond Armlet -- PA +1, MA +1, Block: Slow\n"  
				<< "11.) Jade Armlet    -- Block: Petrify Stop\n"
				<< "12.) Defense Armlet -- Block: Don't Move Don't Act\n"  
				<< "13.) N-Kai Armlet   -- Half: Dark, Block: Confusion Charm\n"
				<< "14.) 108 Gems       -- Strengthen: All Elements,  Block: Undead, BS, Frog, Pois\n"
		) && ( !( cin >> equipAction ) || equipAction < 0 || equipAction > 14 ) )
		{
			cout << "Invalid answer. Select valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0 )
		{
			playerAcc.accessory = false; //accessory slot
			playerAcc.accName = "NONE";
			playerAcc.accType = "";
			playerAcc.accPhyEvade = 0;
			playerAcc.accMagEvade = 0;
			playerAcc.accMove = 0;
			playerAcc.accPA = 0;
			playerAcc.accSpeed = 0;
			playerAcc.accMA = 0;
			playerAcc.accJump = 0;
			playerAcc.accDontMoveBlock = false;
			playerAcc.accDontActBlock = false;
			playerAcc.accLightningBlock = false;
			playerAcc.accAutoReflect = false;
			playerAcc.accSleepBlock = false;
			playerAcc.accDeathSentenceBlock = false;
			playerAcc.accSilenceBlock = false;
			playerAcc.accBerserkBlock = false;
			playerAcc.accAutoUndead = false;
			playerAcc.accInviteBlock = false;
			playerAcc.accStartReraise = false;
			playerAcc.accDeadBlock = false;
			playerAcc.accDarknessBlock = false;
			playerAcc.accSlowBlock = false;
			playerAcc.accPetrifyBlock = false;
			playerAcc.accStopBlock = false;
			playerAcc.accUndeadBlock = false;
			playerAcc.accBloodSuckBlock = false;
			playerAcc.accFrogBlock = false;
			playerAcc.accPoisonBlock = false;
			playerAcc.accConfusionBlock = false;
			playerAcc.accCharmBlock = false;
			playerAcc.accFireUp = false;
			playerAcc.accIceUp = false;
			playerAcc.accWaterUp = false;
			playerAcc.accLightningUp = false;
			playerAcc.accEarthUp = false;
			playerAcc.accWindUp = false;
			playerAcc.accHolyUp = false;
			playerAcc.accDarkUp = false;
			playerAcc.accDarkHalf = false;
			playerAcc.accStartTransparent = false;
			playerAcc.accAutoRegen = false;
			playerAcc.accAutoReraise = false;
			playerAcc.accAutoFloat = false;
			playerAcc.accAutoProtect = false;
			playerAcc.accAutoShell = false;
			playerAcc.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Power Wrist";
			playerAcc.accPA = 1;
		}
		else if( equipAction == 2 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Genji Gauntlet";
			playerAcc.accPA = 2;
			playerAcc.accMA = 2;
		}
		else if( equipAction == 3 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Magic Gauntlet";
			playerAcc.accMA = 2;
		}
		else if( equipAction == 4 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Bracer";
			playerAcc.accPA = 3;
		}
		else if( equipAction == 5 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Reflect Ring";
			playerAcc.accAutoReflect = true;
		}
		else if( equipAction == 6 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Defense Ring";
			playerAcc.accSleepBlock = true;
			playerAcc.accDeathSentenceBlock = true;
		}
		else if( equipAction == 7 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Magic Ring";
			playerAcc.accSilenceBlock = false;
			playerAcc.accBerserkBlock = false;
		}
		else if( equipAction == 8 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Cursed Ring";
			playerAcc.accPA = 1;
			playerAcc.accMA = 1;
			playerAcc.accSpeed = 1;
			playerAcc.accAutoUndead = true;
			playerAcc.accInviteBlock = true;
		}
		else if( equipAction == 9 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Angel Ring";
			playerAcc.accStartReraise = true;
			playerAcc.accUndeadBlock = true;
			playerAcc.accDarknessBlock = true;

		}
		else if( equipAction == 10 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Diamond Armlet";
			playerAcc.accPA = 1;
			playerAcc.accMA = 1;
			playerAcc.accSlowBlock = true;
		}
		else if( equipAction == 11 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Jade Arlmet";
			playerAcc.accPetrifyBlock = true;
			playerAcc.accStopBlock = true;
		}
		else if( equipAction == 12 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Defense Armlet";
			playerAcc.accDontActBlock = true;
			playerAcc.accDontMoveBlock = true;
		}
		else if( equipAction == 13 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "N-Kai Armlet";
			playerAcc.accConfusionBlock = true;
			playerAcc.accCharmBlock = true;
			playerAcc.accDarkHalf = true;
		}
		else if( equipAction == 14 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "108 Gems";
			playerAcc.accUndeadBlock = true;
			playerAcc.accBloodSuckBlock = true;
			playerAcc.accFrogBlock = true;
			playerAcc.accPoisonBlock = true;
			playerAcc.accFireUp = true;
			playerAcc.accIceUp = true;
			playerAcc.accWaterUp = true;
			playerAcc.accWindUp = true;
			playerAcc.accHolyUp = true;
			playerAcc.accDarkUp = true;
			playerAcc.accEarthUp = true;
			playerAcc.accLightningUp = true;
		}
	}
	else if( equipMenu == 3 )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Mantle ---\n"
				<< "\n"
				<< "0.) NONE\n" 
				<< "1.) Small Mantle   -- P Ev 10, M Ev 10\n"
				<< "2.) Leather Mantle -- P Ev 15, M Ev 15\n" 
				<< "3.) Wizard Mantle  -- P Ev 18, M Ev 18, MA +1\n"
				<< "4.) Elf Mantle     -- P Ev 25, M Ev 25\n" 
				<< "5.) Dracula Mantle -- P Ev 28, M Ev 28\n"
				<< "6.) Feather Mantle -- P Ev 40, M Ev 30\n" 
				<< "7.) Vanish Mantle  -- P Ev 35, Start: Transparent\n"
				<< "Phy Evade (P Ev), Magic Evade (M Ev)\n"
		) && ( !( cin >> equipAction ) || equipAction < 0 || equipAction > 7 ) )
		{
			cout << "Invalid answer. Select valid number.\n"<< "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0 )
		{
			playerAcc.accessory = false; //accessory slot
			playerAcc.accName = "NONE";
			playerAcc.accType = "";
			playerAcc.accPhyEvade = 0;
			playerAcc.accMagEvade = 0;
			playerAcc.accMove = 0;
			playerAcc.accPA = 0;
			playerAcc.accSpeed = 0;
			playerAcc.accMA = 0;
			playerAcc.accJump = 0;
			playerAcc.accDontMoveBlock = false;
			playerAcc.accDontActBlock = false;
			playerAcc.accLightningBlock = false;
			playerAcc.accAutoReflect = false;
			playerAcc.accSleepBlock = false;
			playerAcc.accDeathSentenceBlock = false;
			playerAcc.accSilenceBlock = false;
			playerAcc.accBerserkBlock = false;
			playerAcc.accAutoUndead = false;
			playerAcc.accInviteBlock = false;
			playerAcc.accStartReraise = false;
			playerAcc.accDeadBlock = false;
			playerAcc.accDarknessBlock = false;
			playerAcc.accSlowBlock = false;
			playerAcc.accPetrifyBlock = false;
			playerAcc.accStopBlock = false;
			playerAcc.accUndeadBlock = false;
			playerAcc.accBloodSuckBlock = false;
			playerAcc.accFrogBlock = false;
			playerAcc.accPoisonBlock = false;
			playerAcc.accConfusionBlock = false;
			playerAcc.accCharmBlock = false;
			playerAcc.accFireUp = false;
			playerAcc.accIceUp = false;
			playerAcc.accWaterUp = false;
			playerAcc.accLightningUp = false;
			playerAcc.accEarthUp = false;
			playerAcc.accWindUp = false;
			playerAcc.accHolyUp = false;
			playerAcc.accDarkUp = false;
			playerAcc.accDarkHalf = false;
			playerAcc.accStartTransparent = false;
			playerAcc.accAutoRegen = false;
			playerAcc.accAutoReraise = false;
			playerAcc.accAutoFloat = false;
			playerAcc.accAutoProtect = false;
			playerAcc.accAutoShell = false;
			playerAcc.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Small Mantle";
			playerAcc.accPhyEvade = 10;
			playerAcc.accMagEvade = 10;
		}
		else if( equipAction == 2 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Leather Mantle";
			playerAcc.accPhyEvade = 15;
			playerAcc.accMagEvade = 15;
		}
		else if( equipAction == 3 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Wizard Mantle";
			playerAcc.accPhyEvade = 18;
			playerAcc.accMagEvade = 18;
			playerAcc.accMA = 1;
		}
		else if( equipAction == 4 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Elf Mantle";
			playerAcc.accPhyEvade = 25;
			playerAcc.accMagEvade = 25;
		}
		else if( equipAction == 5 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Dracula Mantle";
			playerAcc.accPhyEvade = 28;
			playerAcc.accMagEvade = 28;
		}
		else if( equipAction == 6 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Feather Mantle";
			playerAcc.accPhyEvade = 40;
			playerAcc.accMagEvade = 30;
		}
		else if( equipAction == 7 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Vanish Mantle";
			playerAcc.accPhyEvade = 35;
			playerAcc.accMagEvade = 0;
			playerAcc.accStartTransparent = true;
		}
	}
	else if( equipMenu == 4 )
	{
		while( (cout << "\n"
				<< "   --- " << unit.teamName << " " << unit.playerClassName << " " << unit.playerName << " select Perfume ---\n"
				<< "\n"
		<< "0.) NONE\n" 
		<< "1.) Chantage   -- Auto Regen, Auto Reraise\n"
		<< "2.) Cherche    -- Auto Float, Auto Reflect\n" 
		<< "3.) Salty Rage -- Auto Protect, Auto Shell\n"
		<< "4.) Setiemson  -- Auto Haste, MA +1, Start Transparent\n" 
		) && ( !( cin >> equipAction ) || equipAction < 0 || equipAction > 4 ) )
		{
			cout << "Invalid answer. Select valid number.\n" << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		if( equipAction == 0 )
		{
			playerAcc.accessory = false; //accessory slot
			playerAcc.accName = "NONE";
			playerAcc.accType = "";
			playerAcc.accPhyEvade = 0;
			playerAcc.accMagEvade = 0;
			playerAcc.accMove = 0;
			playerAcc.accPA = 0;
			playerAcc.accSpeed = 0;
			playerAcc.accMA = 0;
			playerAcc.accJump = 0;
			playerAcc.accDontMoveBlock = false;
			playerAcc.accDontActBlock = false;
			playerAcc.accLightningBlock = false;
			playerAcc.accAutoReflect = false;
			playerAcc.accSleepBlock = false;
			playerAcc.accDeathSentenceBlock = false;
			playerAcc.accSilenceBlock = false;
			playerAcc.accBerserkBlock = false;
			playerAcc.accAutoUndead = false;
			playerAcc.accInviteBlock = false;
			playerAcc.accStartReraise = false;
			playerAcc.accDeadBlock = false;
			playerAcc.accDarknessBlock = false;
			playerAcc.accSlowBlock = false;
			playerAcc.accPetrifyBlock = false;
			playerAcc.accStopBlock = false;
			playerAcc.accUndeadBlock = false;
			playerAcc.accBloodSuckBlock = false;
			playerAcc.accFrogBlock = false;
			playerAcc.accPoisonBlock = false;
			playerAcc.accConfusionBlock = false;
			playerAcc.accCharmBlock = false;
			playerAcc.accFireUp = false;
			playerAcc.accIceUp = false;
			playerAcc.accWaterUp = false;
			playerAcc.accLightningUp = false;
			playerAcc.accEarthUp = false;
			playerAcc.accWindUp = false;
			playerAcc.accHolyUp = false;
			playerAcc.accDarkUp = false;
			playerAcc.accDarkHalf = false;
			playerAcc.accStartTransparent = false;
			playerAcc.accAutoRegen = false;
			playerAcc.accAutoReraise = false;
			playerAcc.accAutoFloat = false;
			playerAcc.accAutoProtect = false;
			playerAcc.accAutoShell = false;
			playerAcc.accAutoHaste = false;
		}
		else if( equipAction == 1 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Chantage";
			playerAcc.accAutoRegen = true;
			playerAcc.accAutoReraise = true;
		}
		else if( equipAction == 2 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Cherche";
			playerAcc.accAutoFloat = true;
			playerAcc.accAutoReflect = true;
		}
		else if( equipAction == 3 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Salty Rage";
			playerAcc.accAutoProtect = true;
			playerAcc.accAutoShell = true;
		}
		else if( equipAction == 4 )
		{
			playerAcc.accessory = true; //accessory slot
			playerAcc.accName = "Setiemson";
			playerAcc.accAutoHaste = true;
			playerAcc.accStartTransparent = true;
			playerAcc.accMA = 1;
		}
	}


}


	//equipment selection function
// need to add MP and other stats to equipment
void equipmentSelect( Player &unit )
{
	if( unit.playerClass != 10 )
	{
		WeaponSlot weaponObject;
		WeaponSlot offHandWeapon;
		HeadSlot headObject;
		BodySlot bodyObject;
		OffHandSlot offHandObject;
		AccSlot accObject;

		int blueEquipConfirm = 0;

		do{
			weaponObject.weaponEquip( weaponObject, unit );
			unit.weaponName = weaponObject.weaponName;

			offHandObject.offHandEquip( offHandObject, unit, offHandWeapon, weaponObject );
			unit.offHandName = offHandObject.offHandName;

			headObject.headEquip( headObject, unit );
			unit.headName = headObject.headName;

			bodyObject.bodyEquip( bodyObject, unit );
			unit.bodyName = bodyObject.bodyName;

			accObject.accEquip( accObject, unit );
			unit.accName = accObject.accName;
		
			int equipConfirm = 0;
			while ( (cout << "Weapon: " << unit.weaponName << '\n'
				<< "Off Hand: " << unit.offHandName << '\n'
				<< "Head Equip: " << unit.headName << '\n'
				<< "Body Equip: " << unit.bodyName << '\n'
				<< "Accessory: " << unit.accName << '\n'
				<< "\nConfirm: 1.) Yes 2.) No\n") &&
				( !(cin >> equipConfirm) || equipConfirm < 1 || equipConfirm > 2 ) )
			{
				cout << "Invalid answer. Enter a valid number.\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if(equipConfirm == 1) //simplify this into a function with call by reference
			{
				// doesn't alter base stats until confirm = 1
				blueEquipConfirm = 1;

					//weapon slot
			unit.weapon  =  weaponObject.weapon;
			unit.weaponEffectBool =  weaponObject.weaponEffectBool;
			unit.weaponName =  weaponObject.weaponName;
			unit.weaponType =  weaponObject.weaponType;
			unit.weaponEffect =  weaponObject.weaponEffect;
			unit.weaponRange =  weaponObject.weaponRange;
			unit.weaponRangeMin =  weaponObject.weaponRangeMin;
			unit.weaponPower =  weaponObject.weaponPower;
			unit.weaponEvade =  weaponObject.weaponEvade;
			unit.weaponMA =  weaponObject.weaponMA;
			unit.weaponPA =  weaponObject.weaponPA;
			unit.weaponSpeed =  weaponObject.weaponSpeed;

			unit.ma += unit.weaponMA;
			unit.pa += unit.weaponPA;
			unit.speed += unit.weaponSpeed;

			//unit.weapon add status 25%
			unit.weaponStatusEffect =  weaponObject.weaponStatusEffect; //indicator for attack function
			unit.weaponDarkness =  weaponObject.weaponDarkness;
			unit.weaponSilence =  weaponObject.weaponSilence;
			unit.weaponDeathSentence =  weaponObject.weaponDeathSentence;
			unit.weaponSleep =  weaponObject.weaponSleep;
			unit.weaponDontAct =  weaponObject.weaponDontAct;
			unit.weaponDontMove =  weaponObject.weaponDontMove;
			unit.weaponFrog =  weaponObject.weaponFrog;
			unit.weaponPetrify =  weaponObject.weaponPetrify;
			unit.weaponSlow =  weaponObject.weaponSlow;
			unit.weaponFaith =  weaponObject.weaponFaith;
			unit.weaponPoison =  weaponObject.weaponPoison;
			unit.weaponConfusion =  weaponObject.weaponConfusion;
			unit.weaponCharm =  weaponObject.weaponCharm;
			unit.weaponInnocent =  weaponObject.weaponInnocent;
			unit.weaponCancelDarkness =  weaponObject.weaponCancelDarkness;
			unit.weaponCancelSilence =  weaponObject.weaponCancelSilence;
			unit.weaponCancelOil =  weaponObject.weaponCancelOil;
			unit.weaponCancelFrog =  weaponObject.weaponCancelFrog;
			unit.weaponCancelPoison =  weaponObject.weaponCancelPoison;
			unit.weaponCancelStop =  weaponObject.weaponCancelStop;
			unit.weaponCancelSlow =  weaponObject.weaponCancelSlow;
			unit.weaponCancelDontMove =  weaponObject.weaponCancelDontMove;
			unit.weaponCancelDontAct =  weaponObject.weaponCancelDontAct;
			unit.weaponCancelDeathSentence =  weaponObject.weaponCancelDeathSentence;
			//unit.weapon elemental
			unit.weaponWind =  weaponObject.weaponWind;
			unit.weaponIce =  weaponObject.weaponIce;
			unit.weaponLightning =  weaponObject.weaponLightning;
			unit.weaponHolyUp =  weaponObject.weaponHolyUp;
			unit.weaponFire =  weaponObject.weaponFire;
			unit.weaponHoly =  weaponObject.weaponHoly;
			unit.weaponIceUp  =  weaponObject.weaponIceUp;
			unit.weaponFireUp  =  weaponObject.weaponFireUp;
			unit.weaponLightningUp  =  weaponObject.weaponLightningUp;
			//special unit.weapon effects
			unit.weaponCastSpell = weaponObject.weaponCastSpell;
			unit.weaponLifeDrain =  weaponObject.weaponLifeDrain; //damage converted to HP
			unit.weaponHeal =  weaponObject.weaponHeal; //heals target on damage
			unit.weaponIce2 =  weaponObject.weaponIce2; //casts ice 2
			unit.weaponBolt1 =  weaponObject.weaponBolt1;
			unit.weaponFire1 =  weaponObject.weaponFire1;
			unit.weaponIce1 =  weaponObject.weaponIce1;
			unit.weaponFire2 =  weaponObject.weaponFire2;
			unit.weaponHolyCast =  weaponObject.weaponHolyCast;
			unit.weaponMateriaBlade  =  weaponObject.weaponMateriaBlade; //cloud subset
			unit.weaponHolyAbsorb  =  weaponObject.weaponHolyAbsorb;
			//unit.weapon add status to user
			unit.weaponAutoProtect =  weaponObject.weaponAutoProtect;
			unit.weaponAutoHaste =  weaponObject.weaponAutoHaste;
			unit.weaponAutoShell =  weaponObject.weaponAutoShell;
			unit.weaponAutoRegen =  weaponObject.weaponAutoRegen;
			unit.weaponAutoFaith =  weaponObject.weaponAutoFaith;
			unit.weaponStartPetrify =  weaponObject.weaponStartPetrify; //start Petrified


					//offHand slot
			unit.offHandMagEvade = offHandObject.offHandMagEvade;
			unit.offHandPhyEvade = offHandObject.offHandPhyEvade;
			unit.offHand  =  offHandObject.offHand;
			unit.offHandEffectBool =  offHandObject.offHandEffectBool;
			unit.offHandName =  offHandObject.offHandName;
			unit.offHandType =  offHandObject.offHandType;
			unit.offHandEffect =  offHandObject.offHandEffect;
			unit.offHandRange =  offHandObject.offHandRange;
			unit.offHandRangeMin =  offHandObject.offHandRangeMin;
			unit.offHandPower =  offHandObject.offHandPower;
			unit.offHandEvade =  offHandObject.offHandEvade;
			unit.offHandMA =  offHandObject.offHandMA;
			unit.offHandPA =  offHandObject.offHandPA;
			unit.offHandSpeed =  offHandObject.offHandSpeed;
			//unit.offHand add status 25%
			unit.offHandStatusEffect =  offHandObject.offHandStatusEffect; //indicator for attack function
			unit.offHandDarkness =  offHandObject.offHandDarkness;
			unit.offHandSilence =  offHandObject.offHandSilence;
			unit.offHandDeathSentence =  offHandObject.offHandDeathSentence;
			unit.offHandSleep =  offHandObject.offHandSleep;
			unit.offHandDontAct =  offHandObject.offHandDontAct;
			unit.offHandDontMove =  offHandObject.offHandDontMove;
			unit.offHandFrog =  offHandObject.offHandFrog;
			unit.offHandPetrify =  offHandObject.offHandPetrify;
			unit.offHandSlow =  offHandObject.offHandSlow;
			unit.offHandFaith =  offHandObject.offHandFaith;
			unit.offHandPoison =  offHandObject.offHandPoison;
			unit.offHandConfusion =  offHandObject.offHandConfusion;
			unit.offHandCharm =  offHandObject.offHandCharm;
			unit.offHandInnocent =  offHandObject.offHandInnocent;
			unit.offHandCancelDarkness =  offHandObject.offHandCancelDarkness;
			unit.offHandCancelSilence =  offHandObject.offHandCancelSilence;
			unit.offHandCancelOil =  offHandObject.offHandCancelOil;
			unit.offHandCancelFrog =  offHandObject.offHandCancelFrog;
			unit.offHandCancelPoison =  offHandObject.offHandCancelPoison;
			unit.offHandCancelStop =  offHandObject.offHandCancelStop;
			unit.offHandCancelSlow =  offHandObject.offHandCancelSlow;
			unit.offHandCancelDontMove =  offHandObject.offHandCancelDontMove;
			unit.offHandCancelDontAct =  offHandObject.offHandCancelDontAct;
			unit.offHandCancelDeathSentence =  offHandObject.offHandCancelDeathSentence;
			//unit.offHand elemental
			unit.offHandWind =  offHandObject.offHandWind;
			unit.offHandIce =  offHandObject.offHandIce;
			unit.offHandLightning =  offHandObject.offHandLightning;
			unit.offHandHolyUp =  offHandObject.offHandHolyUp;
			unit.offHandFire =  offHandObject.offHandFire;
			unit.offHandHoly =  offHandObject.offHandHoly;
			unit.offHandIceUp  =  offHandObject.offHandIceUp;
			unit.offHandFireUp  =  offHandObject.offHandFireUp;
			unit.offHandLightningUp  =  offHandObject.offHandLightningUp;
			//special unit.offHand effects
			unit.offHandCastSpell = offHandObject.offHandCastSpell;
			unit.offHandLifeDrain =  offHandObject.offHandLifeDrain; //damage converted to HP
			unit.offHandHeal =  offHandObject.offHandHeal; //heals target on damage
			unit.offHandIce2 =  offHandObject.offHandIce2; //casts ice 2
			unit.offHandBolt1 =  offHandObject.offHandBolt1;
			unit.offHandFire1 =  offHandObject.offHandFire1;
			unit.offHandIce1 =  offHandObject.offHandIce1;
			unit.offHandFire2 =  offHandObject.offHandFire2;
			unit.offHandHolyCast =  offHandObject.offHandHolyCast;
			unit.offHandMateriaBlade  =  offHandObject.offHandMateriaBlade; //cloud subset
			unit.offHandHolyAbsorb  =  offHandObject.offHandHolyAbsorb;
			//unit.offHand add status to user
			unit.offHandAutoProtect =  offHandObject.offHandAutoProtect;
			unit.offHandAutoHaste =  offHandObject.offHandAutoHaste;
			unit.offHandAutoShell =  offHandObject.offHandAutoShell;
			unit.offHandAutoRegen =  offHandObject.offHandAutoRegen;
			unit.offHandAutoFaith =  offHandObject.offHandAutoFaith;
			unit.offHandStartPetrify =  offHandObject.offHandStartPetrify; //start Petrified
			
			unit.ma += unit.offHandMA;
			unit.pa += unit.offHandPA;
			unit.speed += unit.offHandSpeed;

			//head slot
			unit.head= headObject.head; 
			unit.headName= headObject.headName;
			unit.headType= headObject.headType;
			unit.headLife = headObject.headLife;
			unit.headMP = headObject.headMP;
			unit.headPA = headObject.headPA;
			unit.headMA = headObject.headMA;
			unit.headSpeed = headObject.headSpeed;
			
			unit.maxLife += unit.headLife;
			unit.life += unit.headLife;
			unit.maxMP += unit.headMP;
			unit.mp += unit.headMP;
			unit.pa += unit.headPA;
			unit.ma += unit.headMA;
			unit.speed += unit.headSpeed;

			unit.headDarknessBlock= headObject.headDarknessBlock;
			unit.headSleepBlock= headObject.headSleepBlock;
			unit.headSilenceBlock= headObject.headSilenceBlock;
			unit.headDontActBlock= headObject.headDontActBlock;
			unit.headDontMoveBlock= headObject.headDontMoveBlock;
			unit.headDeadBlock= headObject.headDeadBlock;
			unit.headPetrifyBlock= headObject.headPetrifyBlock;
			unit.headInviteBlock= headObject.headInviteBlock;
			unit.headConfusionBlock= headObject.headConfusionBlock;
			unit.headBloodSuckBlock= headObject.headBloodSuckBlock;
			unit.headStopBlock= headObject.headStopBlock;
			unit.headBerserkBlock= headObject.headBerserkBlock;
			unit.headCharmBlock= headObject.headCharmBlock;
			unit.headUndeadBlock= headObject.headUndeadBlock;
			unit.headFrogBlock= headObject.headFrogBlock;
			unit.headPoisonBlock= headObject.headPoisonBlock;
			unit.headSlowBlock= headObject.headSlowBlock;
			unit.headDeathSentenceBlock= headObject.headDeathSentenceBlock;


			//body
			unit.body = bodyObject.body;
			unit.bodyName = bodyObject.bodyName;
			unit.bodyType = bodyObject.bodyType;
			unit.bodyLife = bodyObject.bodyLife;
			unit.bodyMP = bodyObject.bodyMP;
			unit.bodyPA = bodyObject.bodyPA;
			unit.bodyMA = bodyObject.bodyMA;
			unit.bodySpeed = bodyObject.bodySpeed;

			unit.maxLife += unit.bodyLife;
			unit.life += unit.bodyLife;
			unit.maxMP += unit.bodyMP;
			unit.mp += unit.bodyMP;
			unit.pa += unit.bodyPA;
			unit.ma += unit.bodyMA;
			unit.speed += unit.bodySpeed;

			unit.bodyAutoReflect = bodyObject.bodyAutoReflect;
			unit.bodyDeadBlock = bodyObject.bodyDeadBlock;
			unit.bodyStopBlock = bodyObject.bodyStopBlock;
			unit.bodyLightningBlock = bodyObject.bodyLightningBlock;
			unit.bodyEarthUp = bodyObject.bodyEarthUp;
			unit.bodyEarthAbsorb = bodyObject.bodyEarthAbsorb;
			unit.bodyStartTransparent = bodyObject.bodyStartTransparent;
			unit.bodyHolyAbsorb = bodyObject.bodyHolyAbsorb;
			unit.bodyFireHalf = bodyObject.bodyFireHalf;
			unit.bodyIceHalf = bodyObject.bodyIceHalf;
			unit.bodyLightningHalf = bodyObject.bodyLightningHalf;
			unit.bodyFireUp = bodyObject.bodyFireUp;
			unit.bodyLightningUp = bodyObject.bodyLightningUp;
			unit.bodyIceUp = bodyObject.bodyIceUp;
			unit.bodyAutoProtect = bodyObject.bodyAutoProtect;
			unit.bodyAutoShell = bodyObject.bodyAutoShell;


			//acc
			unit.accessory = accObject.accessory; //accessory slot
			unit.accName = accObject.accName;
			unit.accType = accObject.accType;
			unit.accPhyEvade = accObject.accPhyEvade;
			unit.accMagEvade = accObject.accMagEvade;
			unit.accMove = accObject.accMove;
			unit.accPA = accObject.accPA;
			unit.accSpeed = accObject.accSpeed;
			unit.accMA = accObject.accMA;
			unit.accJump = accObject.accJump;

			unit.pa += unit.accPA;
			unit.ma += unit.accMA;
			unit.speed += unit.accSpeed;
			unit.move += unit.accMove;
			unit.jump += unit.accJump;

			unit.accDontMoveBlock = accObject.accDontMoveBlock;
			unit.accDontActBlock = accObject.accDontActBlock;
			unit.accLightningBlock = accObject.accLightningBlock;
			unit.accAutoReflect = accObject.accAutoReflect;
			unit.accSleepBlock = accObject.accSleepBlock;
			unit.accDeathSentenceBlock = accObject.accDeathSentenceBlock;
			unit.accSilenceBlock = accObject.accSilenceBlock;
			unit.accBerserkBlock = accObject.accBerserkBlock;
			unit.accAutoUndead = accObject.accAutoUndead;
			unit.accInviteBlock = accObject.accInviteBlock;
			unit.accStartReraise = accObject.accStartReraise;
			unit.accDeadBlock = accObject.accDeadBlock;
			unit.accDarknessBlock = accObject.accDarknessBlock;
			unit.accSlowBlock = accObject.accSlowBlock;
			unit.accPetrifyBlock = accObject.accPetrifyBlock;
			unit.accStopBlock = accObject.accStopBlock;
			unit.accUndeadBlock = accObject.accUndeadBlock;
			unit.accBloodSuckBlock = accObject.accBloodSuckBlock;
			unit.accFrogBlock = accObject.accFrogBlock;
			unit.accPoisonBlock = accObject.accPoisonBlock;
			unit.accConfusionBlock = accObject.accConfusionBlock;
			unit.accCharmBlock = accObject.accCharmBlock;
			unit.accFireUp = accObject.accFireUp;
			unit.accIceUp = accObject.accIceUp;
			unit.accWaterUp = accObject.accWaterUp;
			unit.accLightningUp = accObject.accLightningUp;
			unit.accEarthUp = accObject.accEarthUp;
			unit.accWindUp = accObject.accWindUp;
			unit.accHolyUp = accObject.accHolyUp;
			unit.accDarkUp = accObject.accDarkUp;
			unit.accDarkHalf = accObject.accDarkHalf;
			unit.accStartTransparent = accObject.accStartTransparent;
			unit.accAutoRegen = accObject.accAutoRegen;
			unit.accAutoReraise = accObject.accAutoReraise;
			unit.accAutoFloat = accObject.accAutoFloat;
			unit.accAutoProtect = accObject.accAutoProtect;
			unit.accAutoShell = accObject.accAutoShell;
			unit.accAutoHaste = accObject.accAutoHaste;
				 
			}
			else
			{
				blueEquipConfirm = 0;
			}
		}while(blueEquipConfirm == 0);
	}
}


//equipment deactivators for when equipment is broken... probably need this for equip change too
void weaponDestroyer( Player &unit)
{
	cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " has lost " << unit.weaponName << "!\n";

	unit.speed -= unit.weaponSpeed;
	unit.pa -= unit.weaponPA;
	unit.ma -= unit.weaponMA;


	unit.weapon = false;
	unit.weaponEffectBool= false;
	unit.weaponName= "Bare Hands";
	unit.weaponType= "Bare Hands";
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

	}

void shieldDestroyer( Player &unit)
{
	cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " has lost " << unit.offHandName << "!\n";

	unit.shield = false;
	unit.pa -= unit.offHandPA;
	unit.ma -= unit.offHandMA;
	unit.offHandName = "NONE";
	unit.speed -= unit.offHandSpeed;

	 //offhand slot
	unit.offHandPhyEvade = 0;
	unit.offHandMagEvade = 0;
	unit.offHand = false;
	unit.offHandWeapon = false;
	unit.offHandEffectBool = false;
	unit.offHandName = "NONE";
	unit.offHandType = "";
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

	//if two swords, now their off hand becomes bare hands
	if( unit.twoSwords == true )
	{
		unit.offHandName = "Bare Hands";
		unit.offHandType = "Bare Hands";
	}
}

void helmetDestroyer( Player &unit )
{
	cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " has lost " << unit.headName << "!\n";

	unit.maxLife -= unit.headLife;
	if( unit.life > unit.maxLife )
		unit.life = unit.maxLife;
	unit.maxMP -= unit.headMP;
	if( unit.mp > unit.maxMP )
		unit.mp = unit.maxMP;
	unit.pa -= unit.headPA;
	unit.ma -= unit.headMA;
	unit.speed -= unit.headSpeed;

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
}

void armorDestroyer( Player &unit )
{
	cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " has lost " << unit.bodyName << "!\n";

	unit.maxLife -= unit.bodyLife;
	if( unit.life > unit.maxLife )
		unit.life = unit.maxLife;
	unit.maxMP -= unit.bodyMP;
	if( unit.mp > unit.maxMP )
		unit.mp = unit.maxMP;
	unit.pa -= unit.bodyPA;
	unit.ma -= unit.bodyMA;
	unit.speed -= unit.bodySpeed;

	unit.body = false;
	unit.bodyName = "NONE";
	unit.bodyType = "";
	unit.bodyLife = 0;
	unit.bodyMP = 0;
	unit.bodyPA = 0;
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
}

void accessoryDestroyer( Player &unit)
{
	cout << "\t" << unit.teamName << " " << unit.playerClassName << " " << unit.playerName
		<< " has lost " << unit.accName << "!\n";

	unit.move -= unit.accMove;
	unit.speed -= unit.accSpeed;
	unit.pa -= unit.accPA;
	unit.ma -= unit.accMA;
	unit.jump -= unit.accJump;

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

void weaponCopier( Player &theMime, Player &mimedUnit )
{
	theMime.weapon = mimedUnit.weapon ;
	theMime.weaponEffectBool = mimedUnit.weaponEffectBool ;
	theMime.weaponName = mimedUnit.weaponName ;
	theMime.weaponType = mimedUnit.weaponType ;
	theMime.weaponEffect = mimedUnit.weaponEffect ;
	theMime.weaponRange = mimedUnit.weaponRange ;
	theMime.weaponRangeMin = mimedUnit.weaponRangeMin ;
	theMime.weaponPower = mimedUnit.weaponPower ;
	theMime.weaponEvade = mimedUnit.weaponEvade ;
	theMime.weaponMA = mimedUnit.weaponMA ;
		theMime.ma += mimedUnit.weaponMA;
	theMime.weaponPA= mimedUnit.weaponPA ;
		theMime.pa += mimedUnit.weaponPA;
	theMime.weaponSpeed= mimedUnit.weaponSpeed ;
		theMime.speed += mimedUnit.weaponSpeed;
	//theMime.weapon add status 25%
	theMime.weaponStatusEffect= mimedUnit.weaponStatusEffect ; //indicator for attack function
	theMime.weaponDarkness= mimedUnit.weaponDarkness ;
	theMime.weaponSilence= mimedUnit.weaponSilence ;
	theMime.weaponDeathSentence= mimedUnit.weaponDeathSentence ;
	theMime.weaponSleep= mimedUnit.weaponSleep ;
	theMime.weaponDontAct= mimedUnit.weaponDontAct ;
	theMime.weaponDontMove= mimedUnit.weaponDontMove ;
	theMime.weaponFrog= mimedUnit.weaponFrog ;
	theMime.weaponPetrify= mimedUnit.weaponPetrify ;
	theMime.weaponSlow= mimedUnit.weaponSlow ;
	theMime.weaponFaith= mimedUnit.weaponFaith ;
	theMime.weaponPoison= mimedUnit.weaponPoison ;
	theMime.weaponConfusion= mimedUnit.weaponConfusion ;
	theMime.weaponCharm= mimedUnit.weaponCharm ;
	theMime.weaponInnocent= mimedUnit.weaponInnocent ;
	theMime.weaponCancelDarkness= mimedUnit.weaponCancelDarkness ;
	theMime.weaponCancelSilence= mimedUnit.weaponCancelSilence ;
	theMime.weaponCancelOil= mimedUnit.weaponCancelOil ;
	theMime.weaponCancelFrog= mimedUnit.weaponCancelFrog ;
	theMime.weaponCancelPoison= mimedUnit.weaponCancelPoison ;
	theMime.weaponCancelStop= mimedUnit.weaponCancelStop ;
	theMime.weaponCancelSlow= mimedUnit.weaponCancelSlow ;
	theMime.weaponCancelDontMove= mimedUnit.weaponCancelDontMove ;
	theMime.weaponCancelDontAct= mimedUnit.weaponCancelDontAct ;
	theMime.weaponCancelDeathSentence= mimedUnit.weaponCancelDeathSentence ;
	//theMime.weapon elemental
	theMime.weaponWind= mimedUnit.weaponWind ;
	theMime.weaponIce= mimedUnit.weaponIce ;
	theMime.weaponLightning= mimedUnit.weaponLightning ;
	theMime.weaponHolyUp= mimedUnit.weaponHolyUp ;
	theMime.weaponFire= mimedUnit.weaponFire ;
	theMime.weaponHoly= mimedUnit.weaponHoly ;
	theMime.weaponIceUp = mimedUnit.weaponIceUp ;
	theMime.weaponFireUp = mimedUnit.weaponFireUp ;
	theMime.weaponLightningUp = mimedUnit.weaponLightningUp ;
	//special theMime.weapon effects
	theMime.weaponCastSpell = mimedUnit.weaponCastSpell;
	theMime.weaponLifeDrain= mimedUnit.weaponLifeDrain ; //damage converted to HP
	theMime.weaponHeal= mimedUnit.weaponHeal ; //heals target on damage
	theMime.weaponIce2= mimedUnit.weaponIce2 ; //casts ice 2
	theMime.weaponBolt1= mimedUnit.weaponBolt1 ;
	theMime.weaponFire1 = mimedUnit.weaponFire1 ;
	theMime.weaponIce1 = mimedUnit.weaponIce1 ;
	theMime.weaponFire2 = mimedUnit.weaponFire2 ;
	theMime.weaponHolyCast= mimedUnit.weaponHolyCast ;
	theMime.weaponMateriaBlade = mimedUnit.weaponMateriaBlade ; //cloud subset
	theMime.weaponHolyAbsorb = mimedUnit.weaponHolyAbsorb ;
	//theMime.weapon add status to user
	theMime.weaponAutoProtect= mimedUnit.weaponAutoProtect ;
	theMime.weaponAutoHaste= mimedUnit.weaponAutoHaste ;
	theMime.weaponAutoShell= mimedUnit.weaponAutoShell ;
	theMime.weaponAutoRegen= mimedUnit.weaponAutoRegen ;
	theMime.weaponAutoFaith= mimedUnit.weaponAutoFaith ;
	theMime.weaponStartPetrify= mimedUnit.weaponStartPetrify ; //start Petrified

}

void weaponUnCopy( Player &unit )
{

	unit.speed -= unit.weaponSpeed;
	unit.pa -= unit.weaponPA;
	unit.ma -= unit.weaponMA;

	unit.weapon = false;
	unit.weaponEffectBool= false;
	unit.weaponName= "Bare Hands";
	unit.weaponType= "Bare Hands";
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

	}