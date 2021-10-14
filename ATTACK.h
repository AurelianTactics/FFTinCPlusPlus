
void turnAttackDamageDisplay( Player &actor, Player &target, int damage, bool lifeDrain = false )
{
	if( lifeDrain == true )
	{
		if( target.undead == true )
		{
			target.life += abs( damage );
			if( target.life > target.maxLife )
				target.life = target.maxLife;
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains " << abs(damage) << " HP!\n";
			
			actor.life -= abs(damage);
			
			if( actor.life <= 0 )
			{
				statusSetter( actor, "Dead");
				cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< " takes " << abs(damage) << " damage and dies!\n";
			}
			else if( actor.life > 0 )
			{
				cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< " loses " << abs(damage) << " HP!\n";
				confusionOff( actor );
			}
		}
		else
		{
			target.life -= abs(damage);
			if( target.life <= 0 )
			{
				statusSetter( target, "Dead");
				cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " takes " << abs(damage) << " damage and dies!\n";
			}
			else if( target.life > 0 )
			{
				cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " loses " << abs(damage) << " HP!\n";
				confusionOff( target );
			}

			actor.life += abs( damage );
			if( actor.life > actor.maxLife )
				actor.life = actor.maxLife;
			cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< " gains " << abs(damage) << " HP!\n";
		}
	}
	else if( damage < 0 )
	{
		target.life += damage;

		if( target.life <= 0 )
		{
			statusSetter( target, "Dead");
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
			<< " takes " << -damage << " damage and dies!\n";
		}
		else if( target.life > 0 )
		{
			cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " loses " << -damage << " HP!\n";
			confusionOff( target );
		}
	}
	else if( damage > 0 )
	{
		target.life += damage;
		if( target.life > target.maxLife )
			target.life = target.maxLife;
		cout << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
				<< " gains " << damage << " HP!\n";
	}
}


int addSpellAttack( Player &actor, Player &target, bool mainHand = true )
{
	int statusRoll;
	statusRoll = rand() % 100 + 1;

	int damage = 0;
	int hitChance = 0;
	int hitChanceRoll = 0;
	int component = 0;
	bool evade = true;
	bool reflect = true;
	bool fire = false;
	bool ice = false;
	bool lightning = false;
	bool holy = false;

	int damageReturn;

	if( mainHand == true )
	{
		if( actor.weaponCastSpell == true && target.dead == false )
		{
			cout << "\t" << "\t" << "25% chance to cast spell. Random number is... " << statusRoll << "\n";
			if( statusRoll <= 25 )
			{
				if( actor.weaponIce1 == true )
				{
					ice = true;
					component = 14;
				}
				else if( actor.weaponIce2 == true )
				{
					ice = true;
					component = 18;
				}
				else if( actor.weaponBolt1 == true )
				{
					lightning = true;
					component = 14;
				}
				else if( actor.weaponFire1 == true )
				{
					fire = true;
					component = 14;
				}
				else if( actor.weaponFire2 == true )
				{
					fire = true;
					component = 18;
				}
				else if( actor.weaponHolyCast == true )
				{
					holy = true;
					evade = false;
					component = 50;
				}
				damage = -mod5Magic( actor, target, actor.ma, component, fire, ice, false, lightning,
					holy );
				if( evade == false )
					hitChance = magicEvade( 100, actor, target );
				else hitChance = 100;
				hitChanceRoll = rand() % 100 + 1;

				if( hitChanceRoll <= hitChance )
				{
					turnAttackDamageDisplay( actor, target, damage );
					damageReturn = damage;
					return damageReturn;
				}
				else cout << "\t" << "\t" << "Spell is evaded!\n";

			}
			else cout << "\t" << "\t" << "misses!\n";
		}
	}
	else if( mainHand == false )
	{
		if( actor.offHandCastSpell == true && target.dead == false )
		{
			cout << "\t" << "\t" << "25% chance to cast spell. Random number is... " << statusRoll << "\n";
			if( statusRoll <= 25 )
			{
				if( actor.offHandIce1 == true )
				{
					ice = true;
					component = 14;
				}
				else if( actor.offHandIce2 == true )
				{
					ice = true;
					component = 18;
				}
				else if( actor.offHandBolt1 == true )
				{
					lightning = true;
					component = 14;
				}
				else if( actor.offHandFire1 == true )
				{
					fire = true;
					component = 14;
				}
				else if( actor.offHandFire2 == true )
				{
					fire = true;
					component = 18;
				}
				else if( actor.offHandHolyCast == true )
				{
					holy = true;
					evade = false;
					component = 50;
				}
				damage = -mod5Magic( actor, target, actor.ma, component, fire, ice, false, lightning,
					holy );
				if( evade == false )
					hitChance = magicEvade( 100, actor, target );
				else hitChance = 100;

				hitChanceRoll = rand() % 100 + 1;

				if( hitChanceRoll <= hitChance )
				{
					turnAttackDamageDisplay( actor, target, damage );
					damageReturn = damage;
					return damageReturn;
				}
				else cout << "\t" << "\t" << "Spell is evaded!\n";

			}
			else cout << "\t" << "\t" << "misses!\n";
		}
	}
	return 0;
}


void addStatusAttack( Player &actor, Player &target, bool mainHand = true )
{
	int statusRoll;
	statusRoll = rand() % 100 + 1;
	string statusName = "";

	if( mainHand == true )
	{
		if( actor.weaponStatusEffect == true )
		{
			statusName = statusAttackChecker( actor, mainHand );
			cout << "\t" << "\t" << "25% chance to add " << statusName << " random number is... " << statusRoll << "\n";
			if( statusRoll <= 25 )
			{
				statusSetter( target, statusName );
			}
		}
	}
	else if( mainHand == false )
	{
		if( actor.offHandStatusEffect == true )
		{
			statusName = statusAttackChecker( actor, mainHand );
			cout << "\t" << "\t" << "25% chance to add " << statusName << " random number is... " << statusRoll << "\n";
			if( statusRoll <= 25 )
			{
				statusSetter( target, statusName );
			}
			else cout << "\t" << "\t" << "misses!\n";
		}
	}
}


int turnSwingDamage( Player &actor, Player &target, char myArray[][11], Golem &blueGolem,
	Golem &redGolem, bool mainHand = true )
{
	int actualDamage = 0;
	bool golemTest;
	int damageReturn = 0;
	int damageCheck = 0;

	if( mainHand == true )
	{
		actualDamage = -attackDamage( actor, target );
	}
	else
	{
		actualDamage = -offHandDamage( actor, target );
	}

	golemTest = golemTester( target, blueGolem, redGolem );
	if( golemTest == true )
	{
		golemDestroyer( target, blueGolem, redGolem, actualDamage );
		damageReturn = addSpellAttack( actor, target, mainHand );
	}
	else
	{
		damageReturn = actualDamage;
		turnAttackDamageDisplay( actor, target, actualDamage );
		damageCheck = addSpellAttack( actor, target, mainHand );
		lifeDrainWeapon( actor, actualDamage, mainHand );
		if( damageCheck != 0 )
		{
			damageReturn = damageCheck;
		}
		addStatusAttack( actor, target, mainHand );
		if( actor.critKnockback == true )
		{
			knockback( actor, target, myArray );
			actor.critKnockback = false;
		}
	}

	return damageReturn;
}

int turnInnerAttack( Player &actor, Player &target, char myArray[][11], Golem &blueGolem,
	Golem &redGolem )
{
	int damageReturn = 0;
	int damageCheck = 0;
	int hitChance;
	int bladeRoll;
	int attackRoll;
	string tempDirection = "";
	int rowCheck = 0;
	int colCheck = 0;
	bool bladeGraspActive = true;

	tempDirection = target.facingDir;
	rowCheck = target.currentRow; //later check to see if target has not been knocked back
	colCheck = target.currentCol;

	if( target.bladeGrasp == true && bladeGraspActive == true )
		hitChance = (100 - target.brave );
	else if( target.arrowGuard == true && 
		( actor.weaponType == "Bow" || actor.weaponType == "Crossbow" ) )
	{
		hitChance = (100 - target.brave );
	}
	else hitChance = 100;

	bladeRoll = rand() % 100 + 1;

	if( bladeRoll <= hitChance )
	{
		hitChance = evadeFunction( 100, actor, target, "physical", true );
		attackRoll = rand() % 100 + 1;
		if( attackRoll <= hitChance )
		{
			damageReturn = turnSwingDamage( actor, target, myArray, blueGolem,
				redGolem, true );
		}
		else
		{
			cout << "\tATTACK misses!\n";
			if( actor.currentCol > target.currentCol )
				target.facingDir = "EAST";
			else if( actor.currentCol < target.currentCol )
				target.facingDir = "WEST";
			else if( actor.currentRow > target.currentRow )
				target.facingDir = "SOUTH";
			else if( actor.currentRow < target.currentRow )
				target.facingDir = "NORTH";
		}
	}
	else
	{
		bladeGraspActive = false;
		if( target.bladeGrasp == true )
			cout << "\tATTACK is blocked by Blade Grasp!\n";
		if( target.arrowGuard == true )
			cout << "\tATTACK is blocked by Arrow Guard!\n";
		if( actor.currentCol > target.currentCol )
			target.facingDir = "EAST";
		else if( actor.currentCol < target.currentCol )
			target.facingDir = "WEST";
		else if( actor.currentRow > target.currentRow )
			target.facingDir = "SOUTH";
		else if( actor.currentRow < target.currentRow )
			target.facingDir = "NORTH";
	}
	
	if( actor.twoSwords == true &&
		( actor.offHand == true || actor.offHandType == "Bare Hands" ) &&
		actor.offHandType != "Shield" && target.petrify == false && target.dead == false
		&& target.currentRow == rowCheck && target.currentCol == colCheck )
	{
		cout << "\t" << actor.playerName << " has Two Swords and attacks twice...\n";
		if( target.bladeGrasp == true && bladeGraspActive == true )
			hitChance = (100 - target.brave );
		else hitChance = 100;

		if( bladeRoll <= hitChance )
		{
			hitChance = evadeFunction( 100, actor, target, "physical", true );
			attackRoll = rand() % 100 + 1;
			if( attackRoll <= hitChance )
			{
				damageCheck = turnSwingDamage( actor, target, myArray, blueGolem,
					redGolem, false );
				if( damageCheck != 0 )
					damageReturn = damageCheck;
			}
			else
			{
				cout << "\tSecond ATTACK misses!\n";
			}
		}
		else
		{
			cout << "\tSecond ATTACK is blocked by Blade Grasp!\n";
		}
	}

	target.facingDir = tempDirection;
	return damageReturn;
}


void counterGraspReaction( Player &actor, Player &target, char myArray[][11], Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem )
{
	int braveRoll = 0;
	int dashRoll = 0;
	int tempDamage = 0;
	int distance;

	if(  target.bloodSuck == false && target.chicken == false && target.confusion == false
		&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
		&& target.berserk == false && target.dontAct == false && target.sleep == false  ) //can't counter if blood sucked
	{
		//counter tackle, have to be within dash range, brave% of time
		if( target.counterTackle == true )
		{
			if( abs(actor.currentRow - target.currentRow) + abs(actor.currentCol - target.currentCol ) == 1 )
			{
				cout << "\t" << "\t" << target.brave << "% chance to " << target.reaction << "...";
				braveRoll = rand() % 100 + 1;
				if(braveRoll <= target.brave )
				{
					cout << " is triggered!\n";
					dashRoll = ( rand() % 4 ) + 1;
					tempDamage = mod2( target, actor, target.pa ); //yes this is backwards on purpose
					tempDamage = dashRoll * tempDamage;
					actor.life -= tempDamage;
					cout << "\t"; knockback( target, actor, myArray) ; //yes this is backwards on purpose
					if(actor.life <= 0)
					{
						statusSetter( actor, "Dead" );
						cout << "\t" << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
							<< " takes " << tempDamage << " damage and dies!\n";
					}
					else 
					{
						cout << "\t" << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " takes " << tempDamage << " damage!\n";
					}
				}
				else cout << " fails to trigger!\n";
			}
		}
		else if( target.dragonSpirit == true )
		{
			if( target.undead == false )
			{
				cout << "\t" << "\t" << target.brave << "% chance to " << target.reaction << "...";
				braveRoll = rand() % 100 + 1;
				if(braveRoll <= target.brave )
				{
					cout << " is triggered!\n";
					statusSetter( target, "Reraise" );
					
				}
				else cout << " fails to trigger!\n";
			}
		}
		else if( target.sunkenState == true )
		{
			cout << "\t" << "\t" << target.brave << "% chance to " << target.reaction << "...";
			braveRoll = rand() % 100 + 1;
			if( braveRoll <= target.brave )
			{
				cout << " is triggered!\n";
				target.transparent = true;
				cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains Transparent status!\n";
			}
			else cout << " fails to trigger!\n";
		}
		else if( target.braveUp == true )
		{
			cout << "\t" << "\t" << target.brave << "% chance to " << target.reaction << "...";
			braveRoll = rand() % 100 + 1;
			if( braveRoll <= target.brave )
			{
				cout << " is triggered!\n";
				target.brave += 3;
				if ( target.brave > 100 )
					target.brave = 100;
				cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName
					<< " gains 3 Brave!\n";
			}
			else cout << " fails to trigger!\n";
		}
		else if( target.counter == true )
		{
			distance = abs( actor.currentRow - target.currentRow ) + abs( actor.currentCol - target.currentCol );
			if(  distance <= target.weaponRange && distance >= target.weaponRangeMin )
			{
				if( target.weaponType == "Spear" || target.weaponType == "Stick" )
				{
					if( abs( actor.currentRow - target.currentRow ) == 0 || abs( actor.currentCol - target.currentCol ) == 0 )
					{
						cout << "\t" << "\t" << target.brave << "% chance to " << target.reaction << "...";
						braveRoll = rand() % 100 + 1;
						if( braveRoll <= target.brave )
						{
							//target and actor switched on purpose, true since it's a counter immune ability
							turnInnerAttack( target, actor, myArray, blueGolem, redGolem );
						}
						else cout << " fails to trigger!\n";
					}
				}
				else
				{
					cout << "\t" << "\t" << target.brave << "% chance to " << target.reaction << "...";
					braveRoll = rand() % 100 + 1;
					if( braveRoll <= target.brave )
					{
						//target and actor switched on purpose, true since it's a counter immune ability
						turnInnerAttack( target, actor, myArray, blueGolem, redGolem );
					}
					else cout << " fails to trigger!\n";
				}
			}
		}
	}
}


bool hamedoReaction( Player &actor, Player&target, char myArray[][11], Item &blueItem, Item &redItem, Golem &blueGolem,
	Golem &redGolem, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10 )
{
	int braveRoll;
	int distance;

	if( target.hamedo == true )
	{
		if(  target.bloodSuck == false && target.chicken == false && target.confusion == false
			&& target.stop == false && target.petrify == false && target.frog == false && target.dead == false
			&& target.berserk == false && target.dontAct == false && target.sleep == false  ) //can't counter if blood sucked
		{
			
			distance = abs( actor.currentRow - target.currentRow ) + abs( actor.currentCol - target.currentCol );
			if(  distance <= target.weaponRange && distance >= target.weaponRangeMin )
			{
				
				if( target.weaponType == "Spear" || target.weaponType == "Stick" )
				{
					if( abs( actor.currentRow - target.currentRow ) == 0 || abs( actor.currentCol - target.currentCol ) == 0 )
					{
						braveRoll = rand() % 100 + 1;
						if( braveRoll <= target.brave )
						{
							cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName 
								<< "'s Hamedo triggers and interrupts the ATTACK!\n";
							//target and actor switched on purpose, true since it's a counter immune ability
							turnInnerAttack( target, actor, myArray, blueGolem, redGolem );
							return true;
						}
						else cout << "\t" << "\t" << "Hamedo fails to trigger!\n";
						return false;
					}
					return false;
				}
				else
				{
					cout << "inside non spear type\n";
					braveRoll = rand() % 100 + 1;
					if( braveRoll <= target.brave )
					{
						cout << "\t" << "\t" << target.teamName << " " << target.playerClassName << " " << target.playerName 
							<< "'s Hamedo triggers!\n";
						//target and actor switched on purpose, true since it's a counter immune ability
						turnInnerAttack( target, actor, myArray, blueGolem, redGolem );
						return true;
					}
					else cout << " fails to trigger!\n";
					return false;
				}
				return false;
			}
			return false;
		}
	}
	return false;
}


//better attack function, not yet implemented
void turnAttackFunction( Player &actor, Player &player1, Player &player2, Player &player3, Player &player4,
	 Player &player5, Player &player6,  Player &player7, Player &player8, Player &player9, Player &player10,
	 Player &nullPlayer, char myArray[][11], Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem,
	 MimeClass &mimeObject )
{
	string attackString = "ATTACK";
	actor.confirm = 0;
	int attackConfirm = 2;
	int displayAtt = 0;
	int hitChance = 0;
	vector<int> rangeVector (2, 0);
	Player target;
	string display = "-- HP ";
	bool hamedoTest = false;
	int targetDamage = 0;

	vector<int> mimeVector (2, 0);
	mimeObject.mimeAttackConfirm = 0;
	mimeObject.attackSide = 0;
	mimeObject.attackDistance = 0;
	

	do
	{
		rangeVector = rangeTest( actor, actor.weaponRange, attackString,
			actor.weaponRangeMin, true );
		target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
	
		displayAtt = -displayDamage( actor, target );
		hitChance = counterGraspEvade( 100, actor, target );
		attackConfirm = targetDisplay( target, attackString, hitChance, displayAtt,
			display, false );

		
		if ( attackConfirm == 1 )
		{
			rangeVector = rangeCollision( actor.currentRow, actor.currentCol, rangeVector[0], rangeVector[1],
				myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
				player10, nullPlayer, attackString );
			target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
			
			if( target.nullPlayer == true || target.petrify == true || target.dead == true )
			{
				
				if( attackConfirm  == 1 )
				{
					cout << "\t" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<< " targets (" << rangeVector[0]-1 << ", " << rangeVector[1]-1
						<< ") and no one is hit.\n";
				}
				if( attackConfirm == 3 )
				{
					actor.confirm = 3;
				}
			}
			else
			{
			
				if( attackConfirm == 1 )
				{
					hamedoTest = hamedoReaction( actor, target, myArray, blueItem, redItem, blueGolem, redGolem,
						player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

					if( hamedoTest == false )
					{
						targetDamage = turnInnerAttack( actor, target, myArray, blueGolem, redGolem );
						
						hpReaction( target, blueItem, redItem, actor, targetDamage );
						if( targetDamage > 0 )
						{
							distributeReaction( target, actor, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, targetDamage );
						}
						if( actor.weaponType != "Magic Gun" )
						{
							counterGraspReaction( actor, target, myArray, player1, player2, player3, player4,
								player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
							counterFloodReaction( target, actor, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
						}
						else
						{
							magicGunReaction( 0, target, actor, player1, player2, player3, player4, player5,
								player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
						}
					}
					endTarget( target, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer );
				}
				if( attackConfirm == 3 )
				{
					actor.confirm = 3;
				}
			} //ends player target loop
		}
		if( attackConfirm == 1 )
		{
			mimeVector = mimeTargetFunction( rangeVector[0], rangeVector[1], actor );
			mimeObject.mimeAttackConfirm = 1;
			mimeObject.attackSide = mimeVector[0];
			mimeObject.attackDistance = mimeVector[1];
		}
	}while( attackConfirm ==  2);

	if( attackConfirm == 3)
	{
		actor.confirm = 3;
	}
}


void mimeAttackFunction( Player &theMime, Player &mimedUnit, Player &player1, Player &player2, Player &player3, Player &player4,
	 Player &player5, Player &player6,  Player &player7, Player &player8, Player &player9, Player &player10,
	 Player &nullPlayer, char myArray[][11], Item &blueItem, Item &redItem, Golem &blueGolem, Golem &redGolem,
	 MimeClass &mimeObject )
{
	string attackString = "ATTACK";

	vector<int> targetVector (2, 0);
	vector<int> rangeVector (2, 0);
	Player target;

	bool hamedoTest = false;
	int targetDamage = 0;

	

	targetVector = mimeTargetVector( theMime, mimeObject.attackSide, mimeObject.attackDistance );

	rangeVector = rangeCollision( theMime.currentRow, theMime.currentCol, targetVector[0], targetVector[1],
		myArray, player1, player2, player3, player4, player5, player6, player7, player8, player9,
		player10, nullPlayer, attackString );

	target = targetFunction( rangeVector[0], rangeVector[1], player1, player2, player3, player4,
			player5, player6, player7, player8, player9, player10, myArray, nullPlayer );
		
	
	if( target.nullPlayer == true || target.petrify == true || target.dead == true )
	{
		
		cout << "\t" << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
			<< " targets (" << targetVector[0]-1 << ", " << targetVector[1]-1
			<< ") and no one is hit.\n";
	}
	else
	{

		cout << "\t" << theMime.teamName << " " << theMime.playerClassName << " " << theMime.playerName
			<< " Mimics ATTACK and targets (" << targetVector[0]-1 << ", " << targetVector[1]-1
			<< ")\n";

		hamedoTest = hamedoReaction( theMime, target, myArray, blueItem, redItem, blueGolem, redGolem,
			player1, player2, player3, player4, player5, player6, player7, player8, player9, player10 );

		if( hamedoTest == false )
		{
			weaponCopier( theMime, mimedUnit );
			targetDamage = turnInnerAttack( theMime, target, myArray, blueGolem, redGolem );
			weaponUnCopy( theMime );

			hpReaction( target, blueItem, redItem, theMime, targetDamage );
			if( targetDamage > 0 )
			{
				distributeReaction( target, theMime, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, targetDamage );
			}
			if( theMime.weaponType != "Magic Gun" )
			{
				counterGraspReaction( theMime, target, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, blueItem, redItem, blueGolem, redGolem);
				counterFloodReaction( target, theMime, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, myArray );
			}
			else
			{
				magicGunReaction( 0, target, theMime, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, myArray, nullPlayer, blueItem, redItem );
			}
		}
		endTarget( target, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer );
		
	} //ends player target loop
}


