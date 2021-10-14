//player class creator

class Player{

public:

	//needed for coding
	int turnOrder; //tie breaker when multiple units over 100 CT
	string teamName; //red versus blue
	string playerName; 
	string facingDir; //which way player is facing
	int playerNumber; //keep same as tie breaker?
	char mapSymbol; //how the player is represented on the board
	int currentRow; //coordinates of where player is on board
	int currentCol;
	bool critKnockback; //indicates a knockback for attack function
	int attackRow;
	int attackCol;
	bool nullPlayer; //not a real player, just a dummy for target finding
	bool activePlayer;
	int magicGunStrength;
	int showCT;
	string quickCode;

	//used to resolve slow action
	int ctrCountdown; // countdown for slow actions which require CTR to resolve
	bool ctrCountdownBool; //whether player has a slow action pending
	int ctrType; 
	string ctrName;
	int ctrRow;
	int ctrCol;
	int ctrEffect; //size of radius
	int ctrFollow; //is ctr attack following target?
	int ctrFollowNumber; //player number that the spell is following
	int ctrInput;
	int ctrK; // k value from charge
	bool quickFlag;

	//player stats
	int playerClass;
	string playerClassName;
	string sex;
	string zodiac;
	int zodiacInt;
	int move;
	int speed;
	int ct;
	int chargeTime; //implement this later
	int maxLife; //add this functionality versus life later
	int life;
	int pa;
	int brave;
	double cEvade;
	int ma;
	long int faith;
	int mp;
	int maxMP;
	int jump;
	int level;
	int confirm;

	//player equipment

	//weapon slot
	bool weapon;
	bool weaponEffectBool;
	string weaponName;
	string weaponType;
	string weaponEffect;
	int weaponRange;
	int weaponRangeMin;
	int weaponPower;
	double weaponEvade;
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


	 //offhand slot
	double offHandPhyEvade;
	long int offHandMagEvade;
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


	//head slot
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

	 //body slot
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

	bool accessory; //accessory slot
	string accName;
	string accType;
	double accPhyEvade;
	long int accMagEvade;
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

	//equipped abilities
	string primary;
	string secondary;
	string reaction;
	string support;
	string movement;
	string inherited1; //some classed inherit certain abilities
	string inherited2;
	string inherited3;

	//secondary
	int secondaryNumber;

	//reaction bools
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

	//support bools
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

	//movement bools
	bool teleport;
	bool teleport2;
	bool moveMP;
	bool moveHP;
	bool fly;
	bool ignoreHeight;
	bool moveLava;
	bool anyGround;
	bool anyWeather;
	bool moveInWater;
	bool walkOnWater;
	bool moveFloat;

	//equipable equipment
	bool knife;	//weapons
	bool ninjaSword;
	bool sword;
	bool knightSword;
	bool katana;
	bool axe;
	bool rod;
	bool staff;
	bool flail;
	bool gun;
	bool crossbow;
	bool bow;
	bool harp;
	bool dictionary;
	bool spear;
	bool stick;
	bool bag;
	bool fabric;
	bool shield; //other equips
	bool helmet;
	bool hat;
	bool ribbon;
	bool armor;
	bool clothes;
	bool robe;
	bool accessoryEquip;
	bool perfume;

	//status ailments
	bool crystal;
	bool darkness;
	bool silence;
	bool petrify;
	bool bloodSuck;
	bool confusion;
	bool charging;
	bool jumping;
	bool archerCharging;
	bool defending;
	bool performing;
	bool oil;
	bool berserk;
	bool quick; //ugg....
	bool statusFloat;
	bool deathSentence;
	bool dead;
	bool frog;
	bool undead;
	bool morbol;
	bool transparent; //ugg...
	bool critical;
	bool invite;
	bool chicken;
	bool reraise;

	//status ailments with timers
	bool poison;
	bool dontMove;
	bool dontAct;
	bool stop;
	bool slow;
	bool haste;
	bool charm;
	bool sleep;
	bool protect;
	bool shell;
	bool regen;
	bool statusFaith;
	bool innocent;
	bool statusReflect;

	int deadTimer;
	int deathSentenceTimer;
	int poisonTimer;
	int dontMoveTimer;
	int dontActTimer;
	int stopTimer;
	int slowTimer;
	int hasteTimer;
	int charmTimer;
	int sleepTimer;
	int protectTimer;
	int shellTimer;
	int regenTimer;
	int statusFaithTimer;
	int innocentTimer;
	int statusReflectTimer;
	

	//stats that player level uses to calculate base stats
	long int lifeM;
	long int lifeC;
	long int mpM;
	long int mpC;
	long int speedM;
	long int speedC;
	long int paM;
	long int paC;
	long int maM;
	long int maC;

	//elements defense
	bool fireWeak;
	bool fireHalf;
	bool fireBlock;
	bool fireAbsorb;
	bool iceWeak;
	bool iceHalf;
	bool iceBlock;
	bool iceAbsorb;
	bool lightningWeak;
	bool lightningHalf;
	bool lightningBlock;
	bool lightningAbsorb;
	bool waterWeak;
	bool waterHalf;
	bool waterBlock;
	bool waterAbsorb;
	bool earthWeak;
	bool earthHalf;
	bool earthBlock;
	bool earthAbsorb;
	bool windWeak;
	bool windHalf;
	bool windBlock;
	bool windAbsorb;
	bool darkWeak;
	bool darkHalf;
	bool darkBlock;
	bool darkAbsorb;
	bool holyWeak;
	bool holyHalf;
	bool holyBlock;
	bool holyAbsorb;

	//elements offense
	bool fireWeapon;
	bool fireUp;
	bool iceWeapon;
	bool iceUp;
	bool waterWeapon;
	bool waterUp;
	bool lightningWeapon;
	bool lightningUp;
	bool darkWeapon;
	bool darkUp;
	bool holyWeapon;
	bool holyUp;
	bool earthWeapon;
	bool earthUp;
	bool windWeapon;
	bool windUp;
	bool offHandFireWeapon;
	bool offHandIceWeapon;
	bool offHandWaterWeapon;
	bool offHandLightningWeapon;
	bool offHandDarkWeapon;
	bool offHandHolyWeapon;
	bool offHandEarthWeapon;
	bool offHandWindWeapon;

	//default constructor. initializes as Archer with Archer stats. user input changes stats
	Player()
	{
		playerName = "";
		ctrCountdown = 0;
		ctrCountdownBool = false;
		ctrName = "";
		ctrK = 0;
		ctrFollow = 0;
		ctrRow = 1;
		ctrCol = 1;
		currentRow = 40;
		currentCol = 40;
		nullPlayer = false;
		quickFlag = false;
		activePlayer = false; //not an active player
		quickCode = "";

		playerClass = 0;
		playerClassName = "";
		sex = "Male";
		zodiac = "Taurus";
		zodiacInt = 5;
		move = 3;
		speed = 0;
		ct = 0;
		maxLife = 0; //add this functionality versus life later
		life = 0;
		pa = 0;
		brave = 70;
		cEvade = 5;
		ma = 0;
		faith = 70;
		mp = 0;
		maxMP = 0;
		jump = 3;
		magicGunStrength = 1;
		level = 23;
		showCT = 0;

		//weapon slot
	weapon = false;
	weaponEffectBool = false;
	weaponName = "Bare Hands";
	weaponType = "Bare Hands";
	weaponEffect = "";
	weaponRange = 1;
	weaponRangeMin = 1;
	weaponPower = 0;
	weaponEvade = 0;
	weaponMA = 0;
	weaponPA = 0;
	weaponSpeed = 0;
	//weapon add status 25%
	weaponStatusEffect = false; //indicator for attack function
	weaponDarkness = false;
	weaponSilence = false;
	weaponDeathSentence = false;
	weaponSleep = false;
	weaponDontAct = false;
	weaponDontMove = false;
	weaponFrog = false;
	weaponPetrify = false;
	weaponSlow = false;
	weaponFaith = false;
	weaponPoison = false;
	weaponConfusion = false;
	weaponCharm = false;
	weaponInnocent = false;
	weaponCancelDarkness = false;
	weaponCancelSilence = false;
	weaponCancelOil = false;
	weaponCancelFrog = false;
	weaponCancelPoison = false;
	weaponCancelStop = false;
	weaponCancelSlow = false;
	weaponCancelDontMove = false;
	weaponCancelDontAct = false;
	weaponCancelDeathSentence = false;
	//weapon elemental
	weaponWind = false;
	weaponIce = false;
	weaponLightning = false;
	weaponHolyUp = false;
	weaponFire = false;
	weaponHoly = false;
	weaponFireUp = false;
	weaponIceUp = false;
	weaponLightningUp = false;
	//special weapon effects
	weaponCastSpell = false;
	weaponLifeDrain = false; //damage converted to HP
	weaponHeal = false; //heals target on damage
	weaponIce2 = false; //casts ice 2
	weaponBolt1 = false;
	weaponFire1 = false;
	weaponIce1 = false;
	weaponFire2 = false;
	weaponHolyCast = false;
	weaponMateriaBlade = false; //cloud subset
	weaponHolyAbsorb = false;
	//weapon add status to user
	weaponAutoProtect = false;
	weaponAutoHaste = false;
	weaponAutoShell = false;
	weaponAutoRegen = false;
	weaponAutoFaith = false;
	weaponStartPetrify = false; //start Petrified

		offHand = false; //offhand slot
		offHandName = "NONE";
		offHandType = "NULL";
		offHandRange = 0;
		offHandPower = 0;
		offHandPhyEvade = 0;
		offHandMagEvade = 0;
		offHandEvade = 0;

		head = false; //head slot
		headName = "NONE";
		headType = "NULL";
		headLife = 0;
		headMP = 0;

		body = false; //head slot
		bodyName = "NONE";
		bodyType = "NULL";
		bodyLife = 0;
		bodyMP = 0;
		bodyMA = 0;

		accessory = false; //accessory slot
		accName = "NONE";
		accType = "NULL";
		accPhyEvade = 0;
		accMagEvade = 0;
		accMove = 0;
		accPA = 0;

		//equipped abilities
		primary = "";
		secondary = "NONE";
		reaction = "";
		support = "";
		movement = "";
		inherited1 = "";
		inherited2 = "";
		inherited3 = "";

		//secondary
		secondaryNumber = 0;

		//reaction bools
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

		//support bools
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

		//movement bools
		fly = false;
		ignoreHeight = false;
		teleport = false;
		teleport2 = true;
		moveHP = false;
		moveMP = false;
		moveLava = false;
		anyGround = false;
		moveInWater = false;
		anyWeather = false;

		//equipable equipment
		knife = false;	//weapons
		ninjaSword = false;
		sword = false;
		knightSword = false;
		katana = false;
		axe = false;
		rod = false;
		staff = false;
		flail = false;
		gun = false;
		crossbow = false;
		bow = false;
		harp = false;
		dictionary = false;
		spear = false;
		stick = false;
		bag = false;
		fabric = false;
		shield = false; //other equips
		helmet = false;
		hat = false;
		ribbon = false;
		armor = false;
		clothes = false;
		robe = false;
		accessoryEquip = false;
		perfume = false;

			//status ailments
		jumping = false;
		archerCharging = false;
		darkness = false;
		silence = false;
		petrify = false;
		bloodSuck = false;
		confusion = false;
		charging = false;
		defending = false;
		performing = false;
		oil = false;
		berserk = false;
		quick = false; //ugg....
		statusFloat = false;
		deathSentence = false;
		dead = false;
		frog = false;
		undead = false;
		morbol = false;
		transparent = false; //ugg...
		critical = false;
		invite = false;

		//status ailments with timers
		poison = false;
		dontMove = false;
		dontAct = false;
		stop = false;
		slow = false;
		haste = false;
		charm = false;
		sleep = false;
		protect = false;
		shell = false;
		reraise = false;
		regen = false;
		statusFaith = false;
		innocent = false;
		chicken = false;
		statusReflect = false;

		//elements
		 fireWeak = false;
		 fireHalf = false;
		 fireBlock = false;
		 fireAbsorb = false;
		 iceWeak = false;
		 iceHalf = false;
		 iceBlock = false;
		 iceAbsorb = false;
		 lightningWeak = false;
		 lightningHalf = false;
		 lightningBlock = false;
		 lightningAbsorb = false;
		 waterWeak = false;
		 waterHalf = false;
		 waterBlock = false;
		 waterAbsorb = false;
		 earthWeak = false;
		 earthHalf = false;
		 earthBlock = false;
		 earthAbsorb = false;
		 windWeak = false;
		 windHalf = false;
		 windBlock = false;
		 windAbsorb = false;
		 darkWeak = false;
		 darkHalf = false;
		 darkBlock = false;
		 darkAbsorb = false;
		 holyWeak = false;
		 holyHalf = false;
		 holyBlock = false;
		 holyAbsorb = false;

		 //elements offense
		fireWeapon = false;
		fireUp = false;
		iceWeapon = false;
		iceUp = false;
		waterWeapon = false;
		waterUp = false;
		lightningWeapon = false;
		lightningUp = false;
		darkWeapon = false;
		darkUp = false;
		holyWeapon = false;
		holyUp = false;
		earthWeapon = false;
		earthUp = false;
		windWeapon = false;
		windUp = false;
		offHandFireWeapon = false;
		offHandIceWeapon = false;
		offHandWaterWeapon = false;
		offHandLightningWeapon = false;
		offHandDarkWeapon = false;
		offHandHolyWeapon = false;
		offHandEarthWeapon = false;
		offHandWindWeapon = false;

		bodyDeadBlock = false;
		headDeadBlock = false;
		accDeadBlock = false;

	}

	//destructor
	~Player(){}
protected:

};







