#include <iostream>
#include <cstdlib>
#include <array>
#include <vector>
#include <string>
#include <limits>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

/* to do

falcon815:
	http://falcon.sandwich.net/

http://www.gamefaqs.com/ps/197339-final-fantasy-tactics/faqs/30462
	for when chapter equips become available

ranged collision
	tested in throw, attack
		added into mimeattack, mime throw, throw stone (and mime ), wave fist? (and the mime equivalents ), battle skill & battle skill mime, item, mime item,
			but not tested
		
	assuming petrified units block collisions...
	assuming wave fist can be intercepted
	assuming attack damage if battle skill is intercepted if no according equipment

Mime Rough Notes:
	message when nothing hits...
	tested:
		song, math skill, item, charge, white magic, dance, elemental, jump, talk skill
		throw, punch art, yin yang, draw out, basic skill, summon magic, time, steal

	can mimes who are brought back to life then duplicate the action?

		charge,
			
		jump:
			need to see if the weapon is duplicated
		throw:
			
		item:
			undead and elixir, what happens to target's MP?
			none crash, not sure about the effect
			need better messages for when things don't work (like phoenx on an alive target)
		dance
			
		battle Skill:
			i'm assuming the weapon is copied over
			need to add counter magic reaction when attacking 
		mime attack
			add counter magic reaction for magic guns
		elemental

		spells
			how the heck does counter magic/absorb used MP work with MP for mimed spells...
				face up should be no problem...
		yin yang
			silence and blind rage fixed but not tested
		talk skill
			
		punch art
			need to test earth slash
		draw out
			need to test kiku
		Attack:
			tested, seems to work, ahve to try it with more equipment
	
 
- If there is more than one Mime on a given team, each attack executed
  by that team will be mimicked individually by each Mime.

For more details on the impact of Mimes on gameflow, see sections A.3 and
A.4 of the gameflow appendix.

answers:

Not sure, I believe that Frogs can use defensive or passive reaction abilities. I would have to do some testing to be sure.

3. Stats cannot go below a base of 1. If a unit is wearing a Thief Hat, their speed cannot be reduced below 3 while they continue to wear the Thief Hat.

2.) Is CT Math Skill for units with CT over 100 based on the units' actual CT or the CT of 100?
2) 100.
3.) What main hand weapons prevent you from equipping a shield? Like can you carry a gun/bag and a shield?
3) If the weapon requires two hands, you can't use a shield. The BMG says the only such weapons are Axes/Longbows.
undead and elixir, what happens to target's MP? not known

status things to fix:

	make sure confusion off is in all the relevant damage places

	implemented: charging, defending, performing, float, haste, slow, protect, regen,
	reraise, shell, darkness, oil (game bug), poison, faith, innocent, invite, silence,
	death sentence, don't move, don't act, sleep, frog

	float
		replace statusFloat with moveFloat where applicable
	reflect
		what does % look like on reflected target? any indicator in action?
		how does it work when you target yourself?
	silence
		can't use white, time, black, summon, yin yang or talk skill: reflect this
	faith
		when it gets over 95, what happens?
	sleep:
		what happens to charged abilities (they halt or what?) (same with stop)
	performing/charging what is shown prior to person choosing to cancel the action?
	floating targets dodge all earth elemental attacks... add to ability or mods?
		going with mods for now...
	regen:
		after landing from a jump it increments right? (assuming it does)
	reraise
		if you die then get hit by raise before rerais goes, reraise remains active?
	critical... when to check for this... displayStatus?
	transparent: not implemented
	bloodsuck:
		need the AI
	jumping:
		dodge song and dances
		Normal jumpers will land 
			with ~50 CT; Hasted jumpers will land with ~75 CT. (not sure about slow)
	charm:
		just a display message saying the other team can control... I'm not doing an AI for this
	chicken... 
		can chickens use reaction abilities? assumed no, got counter hp and evade ones
		assuming chickens cannot fly or ignore height but +move remains
		know I need better move function so ignores collisions for now
		do chickens only lose move CT or lose act CT too? for now assuming no
		if chicken mid way through turn (talk skill) need to revert to AI
	confusion:
		turned off in hpdamage function, also need it in other damage functions
		need to turn off abandon and weapon evade
		need to implement the AI
		what happens to slow abilities?
		how does the wait work for confusion
		confusion AI assumes target always moves, may want to change this...
	berserk
		maybe remove "but blocked from moving from this and confusion"
	petrify
		
	undead:
		hpDamage may not be working correctly
	
	quick
		may not loop through correctly... (or it may )
		set target CT to 100 when hit by it, weird mimed glitch if you ever get to it
		i'm not doing the true mime cycle quick, will have to read the BMG to set it up
		should check after every players turn to see if there is flag and before decrementing
			status effects and before going throw slow reactions
	reflect
		reflect entire spell or just panels?
		assuming mimes mimic where spell targeted on reflect not where it hit
	dont act:

	poison:
		assuming it can kill you

	sleep: d
		
	stop:
		turn ends if hit with stop mid turn... how much CT to subtract?
	leave battlefield faith status
	transparent:
		when you act it goes away
	frog:
		when frog, set attack range to 1, 1
		can frogs use reaction abilities? if so which ones?
		frogs cannot use any secondary except frog in black magic
		assuming being a frog cancels charged abilities?
		can frogs evade?
		can you charge a spell but just not cast it?
		assuming being a frog cancels charged abilities?
	if equipment has initial status, need to set it in the display status
		just start petrify, start transparent (body/acc)
		need startpetrify to work at start but not if equip changed
	if someone is over 100 CT then hit with petrify/sleep/stop need to keep them from going

Questions:
	magic guns: subject to counter magic, what about absorb used MP and face up?
	reflect: reflect target the entire spell or the panel?
		what hit % is shown

	spell guns and counter magic, how does it work w/ MP?

	what % message displays if brave faith PA, etc is at min/max?
	how much damage does repeating fist show on display?

Assumptions
	can elemental allies but not yourself
	add spell cast
		assuming no MP cost, no silence, one panel, can evade/reflect,
		does not trigger magic evade reactions only attack reactions
		assuming can't spell cast on golem... goes straight to target
	counter magic, absorb magic and face up
		probably can't react to your own spells on this... confirmed on absorb but not
		sure about the others, assuming for now that you can't
		what about raise & raise 2? works if dead when it's cast?
			assuming face up and absorb mp are triggered by the same things... though face up may
		be triggered by magic guns too
	counter flood
		magic gun attacks,
			assuming battle skill when it attacks...
	math skill
		assuming for now that it DOES NOT trigger face up, counter magic, absorb used MP etc but am not certain
		can math skill trigger any of your own reactions? assuming yes for the HP ones but not distribute
		miss message when it hits no one? 
	faith and brave can't go below 1?
		assuming mime doesn't copy spells that are silenced/don't cast due to no MP
	slow is like haste in that it effects CT while jumping

Other:
	chance loop from game over to continue game
	cancel out of attack option?
	when a target dies for good what to do with it...
	if slow action, don't ask for press 1 to continue
	crystal move onto: works for absorb, not sure about not

	add chapter selections for abilities and equipment
	game doesn't end until it gets to bottom of the loop, not when victory conditions are met
	if you kill yourself, stop yourself, petrify yourself turn ends... (stupid math skill)
		...reaction abilities too
	make sure for elemental attacks on HP damage that life is restored
	magic evade: what status's make evade 0?
	include all targets on multi-target abilities
	ctr can be over 100 but can't display it over 100
	hpdamage function needs to be tested with undead... don't think it is working
	
	test crit hit function... had it trigger twice in a row on two hands and not do extra damage
	add healing hit staff
	
	collisions
		if a collision is coming what is the hit % shown?

	add spell cast
		assuming no MP cost, no silence, one panel, can evade/reflect,
		does not trigger magic evade reactions only attack reactions
		assuming can't spell cast on golem... goes straight to target


Active Turn
	see if charged abilities can be outputted too

Reaction
	tested: up through counter tackle

	counter magic, absorb magic and face up
		probably can't react to your own spells on this... confirmed on absorb but not
		sure about the others, assuming for now that you can't
		what about raise & raise 2? works if dead when it's cast?
			assuming face up and absorb mp are triggered by the same things... though face up may
		be triggered by magic guns too
	counter magic
			need special messages and effects for life drain and spell absorb
			Counter Magic cannot counter Calculated spells, nor can it counter
			spells which have already been Reflected.  Similarly, a spell cast by
			Counter Magic cannot be Reflected.
			spell guns and counter magic, how does it work w/ MP?
	damage split:
			only last damage is split, need to do this
	distribute
		split to dead/petrified targets? assuming no
		how does it work on undead units? assuming heals like normal
		does it have to be a heal type or just positive HP?
	counter flood
		magic gun attacks,
			assuming battle skill when it attacks...

	mpSwitch
		works on poison damage
	
	further indent reaction abilities?
	maybe indent/space in displays... maybe not

	auto potion: potion inventory, undead targets with AP take further damage

Support Abilities
	equip change: deactivate old equipment, then add stats of the new one
	do half of MP and Short charge reflect changes in menu?

	equip change: weapon doesn't work, some of teh stats don't add from other things...
			might need to run status setter after it...
	two swords: doesn't work with quick start

Movement
	more collision detection
	change move function confirm to after a valid move is entered
	no move +3 for women? no jump +3 for men?
	

Charge
	tested all charges
	
	add more random numbers and displays for when blade grasp is active

Item:
	HP restore and PD work, rest of abilities target but need to verify effect
	is their collision detection with item?
	add HP amount restored with phoenix down
	can item target an empty square

Math Skill
	which CT is used for calulations "actual" if over 100 or treated as 100?
	tested: white magic, time magic, yin yang
		didn't test esuna, raise, raise 2
	assuming for now that it DOES NOT trigger face up, counter magic, absorb used MP etc but am not certain
	can math skill trigger any of your own reactions? assuming yes for the HP ones but not distribute
	miss message when it hits no one? 
	die w/ demi 2 etc form math skill, no death message

Sing
	no charm functionality
	such a pain to alter due to each ability being written in like 10 places
	tested, looks like all abilities work
	if you continue performing, can you move? when can you break out of a perform?
		only beginning of turn or at any point in the turn?


Dance
	such a bitch to alter this, have to replicate every change 10 times
	if you continue performing, can you move? when can you break out of a perform?
		only beginning of turn or at any point in the turn?
	can wiznaibus trigger HP reactions?
	how low can speed, pa and ma go? depend upon equipment?
		only to 1 + equipment amount... need to reflect this, same in battle skill

	

Elemental
	not a huge fan of the display
	does it take into account elemental weaknesses?
	can you unpetrify someone with elemental?
	adding status before dieing... don't think it's an issue except for petrify...
	sometimes (maybe when targetting off the array ) attacks a null player
		think it is like this with multiple skill sets

battle skill
	need to add a message for attack swings when equipment is broken
	tested all abilities, tested with gun/crossbow
	does shield break work on off hands?
		probably like steal weapon
	do all equipment breaks cause HP damage if no item?
	two swords break: add second swing
	maintenance on a target with no helmet protect against the attack portion of helm break?
	can you break to off hand weapon through weapon break or shield break?
	probably can't go lower then min values, make it so weapon destroyers reflect this
	add all correct counter types on this

Jump
	works, can't landon jumping target

talk skill:
	tested, all abilities work
	finger guard, what is meant by base success %? before or after it goes through mod1?
	roll like a normal reaction ability or just lower the base %?
	cannot use talk skill if silenced or is it just 0%?
	what % message displays if brave or faith is at min/max?
	to upper/lower on invite?
	can use talk skill on empty square?

Punch Art
	tested, all abilities work,
		need to test all restore effects of stigma, MP restore of chakra
	earth slash sends a zodiac message on display...
		earth slash doesn't hit floating targets but need a message
	temp damage in punch art ability needs a dummy target
		can punch arts hit own teammates (earth slash)
			assuming yes
	concentrate: work with punch art?
	chakra heal both sides?
	stigma on both sides?
	add targets to spin fist and earth slash
	how much damage does repeating fist show on display?

	
Throw
	tested, works
	can you add status with a throw hit on an item taht adds status?
	elemental cannot be strengthend but can be defended against
	need to add collision
	easter egg: 1 javelin and 1 chaos blade... may want to add more
	align the remaining on the throw

yin yang
	can drain MP from target with no MP?
	can Yin Yang target a panel or a unit?
	shell/magic defend up work against pray faith?
	can brave go down to 0?


white magic
	tested, appears to work
	need to test undead, add elemental to Holy
	if holy heals, + if damage then -
	if undead units are healed, do their HP reaction abilities trigger?
	raise/raise 2 can only target map squares right? or can it follow unit?

draw out:
	miss message if nothing is hit

basic skill
	tested and works
	need to confirm heal gets silence and darkness I guess...
	

summon
	golem surviving HP ever known?
	lich and how dark up/block leads to changes
	
steal
	tested everything but steal shield, steal off hand weapon

time magic


black magic
	let you cast frog when frog'd
	fire4/ice4/bolt4 are caster immune?
		dealt with it in Mime function

math skill
	math skill and evade... may have hot fixed it


Attack:
	add status has a weird RNG display for chance to add darkness...
equiping items:

damage split and two swords: how much damage is split?

how does performing work? display menu of options or jsut continue to perform/not

fix AT menu to include charge and CTR times
output menu outputs some fill between characters

choose brave/faith?

tab for menu displays?... how to present the info better

arrange player stats better

long term:
	height, elementals, number of units, two users enter inputs

BMG corrections: ninja sword damage is incorrect in section 2.1
	not sure how mod3 attacks work in BMG, no step to add back in the base hit
	where does two hands figure in?
		
*/

using namespace std;

#include "Player.h"
#include "zodiac.h"
#include "move.h"
#include "mw.h"
#include "equip.h"
#include "atk.h"
#include "throw.h"
#include "classes.h"
#include "react.h"
#include "ATTACK.h"
#include "secondary.h"
#include "sec2.h"
#include "sec3.h"
#include "sec4.h"
#include "sec5.h"
#include "sec6.h"
#include "abil.h"
#include "AI.h"
#include "turn.h"
#include "charSelect.h"
#include "srphase.h"
#include "quickstart.h"
#include "qsCode.h"


int main()
{
	
	//sets random seed
	using std::srand;
	using std::time;
	srand((unsigned)time(0));
	using std::rand;

	welcome();

	//Initialize players
	//turn order blue: 1,4,5,8,9
	Player blue1;
	Player red1;
	Player blue2; Player blue3; Player blue4; Player blue5;
	Player red2; Player red3; Player red4; Player red5;
	Player nullPlayer; nullPlayer.nullPlayer = true;

	blue1.teamName = "Blue"; blue1.mapSymbol = 'b'; blue1.turnOrder = 1; blue1.activePlayer = true;
	red1.teamName = "Red"; red1.mapSymbol = 'R'; red1.turnOrder = 2; red1.activePlayer = true;
	red2.teamName = "Red"; red2.mapSymbol = 'E'; red2.turnOrder = 3; red2.activePlayer = true; 
	blue2.teamName = "Blue"; blue2.mapSymbol = 'u'; blue2.turnOrder = 4; blue2.activePlayer = true;


	/*quickStartFunctionBlue1( blue1 );
	quickStartFunctionRed1( red1 );
	quickStartFunctionRed2( red2 );
	quickStartFunctionBlue2( blue2 );*/

	//player select attributes
	
	cout << "\n";

	int setUpChar = 1;
	do
	{
		setUpChar = quickStartMenu( blue1, "FIRST" );
		setUpChar = characterSetUp( blue1, setUpChar );
	} while( setUpChar == 2 );

	do
	{
		setUpChar = quickStartMenu( red1, "FIRST" );
		setUpChar = characterSetUp( red1, setUpChar );
	} while( setUpChar == 2 );

	do
	{
		setUpChar = quickStartMenu( red2, "SECOND" );
		setUpChar = characterSetUp( red2, setUpChar );
	} while( setUpChar == 2 );

	do
	{
		setUpChar = quickStartMenu( blue2, "SECOND" );
		setUpChar = characterSetUp( blue2, setUpChar );
	} while( setUpChar == 2 );

	//cout << "\n" << "   --- Blue Team select your FIRST character ---\n" << "\n";
	//selectSex( blue1 );
	//selectClass( blue1 );
	//abilitySelect( blue1 );
	//equipmentSelect( blue1 );

	//cout << "\n" << "   --- Red Team select your FIRST character ---\n" << "\n";
	//selectSex( red1 );
	//selectClass( red1 ); 
	//abilitySelect( red1 );
	//equipmentSelect( red1 );

	//cout << "\n"  << "   --- Red Team select your SECOND character ---\n" << "\n";
	//selectSex( red2 );
	//selectClass( red2 ); 
	//abilitySelect( red2 );
	//equipmentSelect( red2 );

	//cout << "\n" << "   --- Blue Team select your SECOND character ---\n" << "\n";
	//selectSex( blue2 );
	//selectClass( blue2 );
	//abilitySelect( blue2 );
	//equipmentSelect( blue2 );

	vector<string> blue1QS (50, "0");
	vector<string> blue2QS (50, "0");
	vector<string> blue3QS (50, "0");
	vector<string> blue4QS (50, "0");
	vector<string> blue5QS (50, "0");
	vector<string> red1QS (50, "0");
	vector<string> red2QS (50, "0");
	vector<string> red3QS (50, "0");
	vector<string> red4QS (50, "0");
	vector<string> red5QS (50, "0");

	quickStartCodeMaker( blue1, blue1QS );
	quickStartCodeMaker( blue2, blue2QS );
	quickStartCodeMaker( red1, red1QS );
	quickStartCodeMaker( red2, red2QS );

	qsOutputBlue1( blue1QS );
	qsOutputBlue2( blue2QS );
	qsOutputRed1( red1QS );
	qsOutputRed2( red2QS );
	

	// secondary and primary objects
	Item blueItem; Item redItem;
	Charge chargeObject; MathSkill mathSkillObject; Song songObject; Dance danceObject;
	Elemental elementalObject; BattleSkill battleSkillObject;
	Jump jumpObject; TalkSkill talkSkillObject; MimeClass mimeObject;
	PunchArt punchArtObject; Throw blueThrow; Throw redThrow;
	YinYang yinYangObject; White whiteObject; DrawOut blueDraw; DrawOut redDraw;
	BasicSkill basicSkillObject; Summon summonObject; Golem blueGolem; Golem redGolem;
	Steal stealObject; Time timeObject; Black blackObject;
	
	//generates the qs codes
	
	

	
	

	//quickStartCodeMaker( blue3, blue3QS );
	//quickStartCodeMaker( blue4, blue4QS );
	//quickStartCodeMaker( blue5, blue5QS );
	//quickStartCodeMaker( red3, red3QS );
	//quickStartCodeMaker( red4, red4QS );
	//quickStartCodeMaker( red5, red5QS );

	

	//initializes the gameboard
	char myArray[11][11] = {
	{' ','0','1','2','3','4','5','6','7','8','9',},
	{'0','O','O','O','O','O','O','O','O','O','O',},
	{'1','O','O','O','O','O','O','O','O','O','O',},
	{'2','O','O','O','O','O','O','O','O','O','O',},
	{'3','O','O','O','O','O','O','O','O','O','O',},
	{'4','O','O','O','O','O','O','O','O','O','O',},
	{'5','O','O','O','O','O','O','O','O','O','O',},
	{'6','O','O','O','O','O','O','O','O','O','O',},
	{'7','O','O','O','O','O','O','O','O','O','O',},
	{'8','O','O','O','O','O','O','O','O','O','O',},
	{'9','O','O','O','O','O','O','O','O','O','O',},
	};
//blue and red's starting spots, initial directions and team names
	blue1.currentRow = 1; blue1.currentCol = 2; blue1.facingDir = "SOUTH";
	red1.currentRow = 10; red1.currentCol = 9; red1.facingDir = "NORTH";
	myArray[blue1.currentRow][blue1.currentCol] = blue1.mapSymbol;
	myArray[red1.currentRow][red1.currentCol] = red1.mapSymbol;

	blue2.currentRow = 2; blue2.currentCol = 1; blue2.facingDir = "SOUTH";
	myArray[blue2.currentRow][blue2.currentCol] = blue2.mapSymbol;
	red2.currentRow = 9; red2.currentCol = 10; red2.facingDir = "NORTH";
	myArray[red2.currentRow][red2.currentCol] = red2.mapSymbol;

	int turn = 1;
	int clockTick = 0;


	//begins the game loop. as long as one team is alive, game continues
	while(
		( (red1.dead == false && red1.petrify == false && red1.undead == false && red1.invite == false && red1.undead == false )
		|| (red2.dead == false && red2.petrify == false && red2.undead == false && red2.invite == false && red2.undead == false ) 
		) 
		&& ( 
		(blue1.dead == false && blue1.petrify == false && blue1.undead == false && blue1.invite == false && blue1.undead == false ) 
		|| (blue2.dead == false && blue2.petrify == false && blue2.undead == false && blue2.invite == false && blue2.undead == false ) 
		) 
		) 
	{
		
		//status check phase, deducts status number then cures it when reaches 0
		statusCheckPhase( blue1, blue1, blue2, blue3, blue4, blue5, red1, red2, red3,
			red4, red5 );
		statusCheckPhase( red1, blue1, blue2, blue3, blue4, blue5, red1, red2, red3,
			red4, red5  );
		statusCheckPhase( red2, blue1, blue2, blue3, blue4, blue5, red1, red2, red3,
			red4, red5  );
		statusCheckPhase( blue2, blue1, blue2, blue3, blue4, blue5, red1, red2, red3,
			red4, red5  );

		//implement slow action, alternative way may be to set ctr actual clocktick for activation then activate when player ctr == actual ctr
		srPhase( blue1, blue1, blue2, blue3, blue4, blue5, red1, red2, red3, red4, red5,
			nullPlayer, myArray, blueItem, redItem, yinYangObject, whiteObject, blackObject, timeObject,
			summonObject, blueGolem, redGolem, mimeObject, jumpObject  );
		srPhase( red1, blue1, blue2, blue3, blue4, blue5, red1, red2, red3, red4, red5,
			nullPlayer, myArray, blueItem, redItem, yinYangObject, whiteObject, blackObject, timeObject,
			summonObject, blueGolem, redGolem, mimeObject, jumpObject  );
		srPhase( red2, blue1, blue2, blue3, blue4, blue5, red1, red2, red3, red4, red5,
			nullPlayer, myArray, blueItem, redItem, yinYangObject, whiteObject, blackObject, timeObject,
			summonObject, blueGolem, redGolem, mimeObject, jumpObject  );
		srPhase( blue2, blue1, blue2, blue3, blue4, blue5, red1, red2, red3, red4, red5,
			nullPlayer, myArray, blueItem, redItem, yinYangObject, whiteObject, blackObject, timeObject,
			summonObject, blueGolem, redGolem, mimeObject, jumpObject );

		//increments players speed until someone reaches 100 CT
		ctTickOuter( clockTick, blue1, blue2, blue3, blue4, blue5, red1, red2, red3,
			red4, red5 );

		//players with 100 CT act
		ctFunction( blue1, myArray, turn, 11, 11, clockTick, blueItem, redItem,
			battleSkillObject, basicSkillObject, chargeObject, stealObject, blue1, blue2,
			blue3, blue4, blue5, red1, red2, red3, red4, red5, nullPlayer, blueThrow,
			redThrow, songObject, danceObject, jumpObject, punchArtObject, elementalObject,
			blueDraw, redDraw, talkSkillObject, yinYangObject, whiteObject, blackObject,
			timeObject, summonObject, blueGolem, redGolem, mathSkillObject, mimeObject );

	} // ends game while loop

	cout << "\n";
	if( 
		( red1.petrify == true || red1.dead == true || red1.bloodSuck == true || red1.undead == true || red1.invite == true )
		&& 
		( red2.petrify == true || red2.dead == true || red2.bloodSuck == true || red2.undead == true || red2.invite == true )
		)
	{
		cout << "Blue Team Wins!\n" << "GAME OVER\n" << endl;
	}
	else
	{
		cout << "Red Team Wins!\n" << "GAME OVER\n" << endl;
	}
	int pauseMenu = 0;
	while( ( cout << "Enter 1 to Exit Game" )
		&& (!(cin >> pauseMenu) || pauseMenu < 1 || pauseMenu > 1 ) )	
	{
		cin.clear();
	}
	return 0;
} //ends main loop
