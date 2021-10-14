

void qsReaction( Player unit, vector<string> &qsVec )
{
	if( unit.reaction == "" || unit.reaction == "NONE" )
	{
		qsVec[13] = "0";
		qsVec[14] = "0";
	}
	else if( unit.aSave == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "1";
	}
	else if( unit.abandon == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "2";
	}
	else if( unit.absorbUsedMP == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "3";
	}
	else if( unit.arrowGuard == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "4";
	}
	else if( unit.autoPotion == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "5";
	}
	else if( unit.bladeGrasp == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "6";
	}
	else if( unit.braveUp == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "7";
	}
	else if( unit.reactionCatch == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "8";
	}
	else if( unit.caution == true )
	{
		qsVec[13] = "0";
		qsVec[14] = "9";
	}
	else if( unit.counter == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "0";
	}
	else if( unit.counterFlood == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "1";
	}
	else if( unit.counterMagic == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "2";
	}
	else if( unit.counterTackle == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "3";
	}
	else if( unit.criticalQuick == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "4";
	}
	else if( unit.damageSplit == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "5";
	}
	else if( unit.distribute == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "6";
	}
	else if( unit.dragonSpirit == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "7";
	}
	else if( unit.faceUp == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "8";
	}
	else if( unit.fingerGuard == true )
	{
		qsVec[13] = "1";
		qsVec[14] = "9";
	}
	else if( unit.hamedo == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "0";
	}
	else if( unit.hpRestore == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "1";
	}
	else if( unit.maSave == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "2";
	}
	else if( unit.meatboneSlash == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "3";
	}
	else if( unit.mpRestore == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "4";
	}
	else if( unit.mpSwitch == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "5";
	}
	else if( unit.regenerator == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "6";
	}
	else if( unit.speedSave == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "7";
	}
	else if( unit.sunkenState == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "8";
	}
	else if( unit.weaponGuard == true )
	{
		qsVec[13] = "2";
		qsVec[14] = "9";
	}
}

void qsSupport( Player unit, vector<string> &qsVec )
{
	if( unit.support == "" || unit.support == "NONE" )
	{
		qsVec[15] = "0";
		qsVec[16] = "0";
	}
	else if( unit.attackUp == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "1";
	}
	else if( unit.concentrate == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "2";
	}
	else if( unit.defend == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "3";
	}
	else if( unit.defenseUp == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "4";
	}
	else if( unit.equipArmor == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "5";
	}
	else if( unit.equipAxe == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "6";
	}
	else if( unit.equipCrossbow == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "7";
	}
	else if( unit.equipGun == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "8";
	}
	else if( unit.equipKnife == true )
	{
		qsVec[15] = "0";
		qsVec[16] = "9";
	}
	else if( unit.equipShield == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "0";
	}
	else if( unit.equipSpear == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "1";
	}
	else if( unit.equipSword == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "2";
	}
	else if( unit.halfOfMP == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "3";
	}
	else if( unit.magicAttackUp == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "4";
	}
	else if( unit.maintenance == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "5";
	}
	else if( unit.martialArts == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "6";
	}
	else if( unit.monsterSkill == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "7";
	}
	else if( unit.monsterTalk == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "8";
	}
	else if( unit.shortCharge == true )
	{
		qsVec[15] = "1";
		qsVec[16] = "9";
	}
	else if( unit.throwItem == true )
	{
		qsVec[15] = "2";
		qsVec[16] = "0";
	}
	else if( unit.train == true )
	{
		qsVec[15] = "2";
		qsVec[16] = "1";
	}
	else if( unit.twoHands == true )
	{
		qsVec[15] = "2";
		qsVec[16] = "2";
	}
	else if( unit.twoSwords == true )
	{
		qsVec[15] = "2";
		qsVec[16] = "3";
	}
	else if( unit.magicDefendUp == true )
	{
		qsVec[15] = "2";
		qsVec[16] = "4";
	}
	else if( unit.equipChange == true )
	{
		qsVec[15] = "2";
		qsVec[16] = "5";
	}
	
}

void qsMovement( Player unit, vector<string> &qsVec )
{
	if( unit.movement == "" || unit.movement == "NONE" )
	{
		qsVec[17] = "0";
		qsVec[18] = "0";
	}
	else if( unit.anyGround == true )
	{
		qsVec[17] = "0";
		qsVec[18] = "1";
	}
	else if( unit.anyWeather == true )
	{
		qsVec[17] = "0";
		qsVec[18] = "2";
	}
	else if( unit.moveFloat == true )
	{
		qsVec[17] = "0";
		qsVec[18] = "3";
	}
	else if( unit.fly == true )
	{
		qsVec[17] = "0";
		qsVec[18] = "4";
	}
	else if( unit.ignoreHeight == true )
	{
		qsVec[17] = "0";
		qsVec[18] = "5";
	}
	else if( unit.movement == "Jump +1"  )
	{
		qsVec[17] = "0";
		qsVec[18] = "6";
	}
	else if( unit.movement == "Jump +2" )
	{
		qsVec[17] = "0";
		qsVec[18] = "7";
	}
	else if( unit.movement == "Jump +3"  )
	{
		qsVec[17] = "0";
		qsVec[18] = "8";
	}
	else if( unit.movement == "Move +1"  )
	{
		qsVec[17] = "0";
		qsVec[18] = "9";
	}
	else if( unit.movement == "Move +2"  )
	{
		qsVec[17] = "1";
		qsVec[18] = "0";
	}
	else if( unit.movement == "Move +3"  )
	{
		qsVec[17] = "1";
		qsVec[18] = "1";
	}
	else if( unit.moveHP == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "2";
	}
	else if( unit.moveMP == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "3";
	}
	else if( unit.moveLava == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "4";
	}
	else if( unit.moveInWater == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "5";
	}
	else if( unit.teleport == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "6";
	}
	else if( unit.walkOnWater == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "7";
	}
	else if( unit.teleport2 == true )
	{
		qsVec[17] = "1";
		qsVec[18] = "8";
	}
	
}

void qsWeapon( Player unit, vector<string> &qsVec )
{
	//19-22
	if( unit.weapon == false )
	{
		qsVec[19] = "0";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "0";
	}
	else if( unit.weaponType == "Bare Hands" )
	{
		qsVec[19] = "0";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "0";
	}
	else if( unit.weaponName == "Battle Axe" )
	{
		qsVec[19] = "0";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Giant Axe" )
	{
		qsVec[19] = "0";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Slasher" )
	{
		qsVec[19] = "0";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "C Bag" )
	{
		qsVec[19] = "0";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "FS Bag" )
	{
		qsVec[19] = "0";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "P Bag" )
	{
		qsVec[19] = "0";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "H Bag" )
	{
		qsVec[19] = "0";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Long Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Silver Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Ice Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Lightning Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Windslash Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}	
	else if( unit.weaponName == "Mythril Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}	
	else if( unit.weaponName == "Ultimus Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "7";
	}
	else if( unit.weaponName == "Yoichi Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "8";
	}	
	else if( unit.weaponName == "Perseus Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "9";
	}		
	else if( unit.weaponName == "Bow Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Night Killer" )
	{
		qsVec[19] = "0";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Cross Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Poison Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Hunting Bow" )
	{
		qsVec[19] = "0";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}
	else if( unit.weaponName == "Gastrafitis" )
	{
		qsVec[19] = "0";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}
	else if( unit.weaponName == "Battle Dict" )
	{
		qsVec[19] = "0";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Monster Dict" )
	{
		qsVec[19] = "0";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Papyrus Plate" )
	{
		qsVec[19] = "0";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Madlemgem" )
	{
		qsVec[19] = "0";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Persia" )
	{
		qsVec[19] = "0";
		qsVec[20] = "6";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Cashmere" )
	{
		qsVec[19] = "0";
		qsVec[20] = "6";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Ryozan Silk" )
	{
		qsVec[19] = "0";
		qsVec[20] = "6";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Flail" )
	{
		qsVec[19] = "0";
		qsVec[20] = "7";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}	
	else if( unit.weaponName == "Flame Whip" )
	{
		qsVec[19] = "0";
		qsVec[20] = "7";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Morning Star" )
	{
		qsVec[19] = "0";
		qsVec[20] = "7";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Scorpion Tail" )
	{
		qsVec[19] = "0";
		qsVec[20] = "7";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Romanda Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "8";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Mythril Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "8";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Stone Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "8";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Blaze Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "8";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}	
	else if( unit.weaponName == "Glacier Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "8";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}	
	else if( unit.weaponName == "Blast Gun" )
	{
		qsVec[19] = "0";
		qsVec[20] = "8";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}
	else if( unit.weaponName == "Ramia Harp" )
	{
		qsVec[19] = "0";
		qsVec[20] = "9";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Bloody Strings" )
	{
		qsVec[19] = "0";
		qsVec[20] = "9";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Fairy Harp" )
	{
		qsVec[19] = "0";
		qsVec[20] = "9";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Asura Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Koutetsu Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Bizen Boat" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Murasame" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Heaven's Cloud" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}
	else if( unit.weaponName == "Kiyomori" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}
	else if( unit.weaponName == "Muramasa" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "7";
	}	
	else if( unit.weaponName == "Kikuichimoji" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "8";
	}
	else if( unit.weaponName == "Masamune" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "0";
		qsVec[22] = "9";
	}	
	else if( unit.weaponName == "Chirijiraden" )
	{
		qsVec[19] = "1";
		qsVec[20] = "0";
		qsVec[21] = "1";
		qsVec[22] = "0";
	}	
	else if( unit.weaponName == "Dagger" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Mythril Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Blind Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Mage Masher" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Platina Dagger" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}	
	else if( unit.weaponName == "Main Gauche" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}
	else if( unit.weaponName == "Orichalcum" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "7";
	}
	else if( unit.weaponName == "Assassin Dagger" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "8";
	}
	else if( unit.weaponName == "Air Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "0";
		qsVec[22] = "9";
	}	
	else if( unit.weaponName == "Zorlin Shape" )
	{
		qsVec[19] = "1";
		qsVec[20] = "1";
		qsVec[21] = "1";
		qsVec[22] = "0";
	}
	else if( unit.weaponName == "Defender" )
	{
		qsVec[19] = "1";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Save the Queen" )
	{
		qsVec[19] = "1";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Excalibur" )
	{
		qsVec[19] = "1";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Ragnarok" )
	{
		qsVec[19] = "1";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Chaos Blade" )
	{
		qsVec[19] = "1";
		qsVec[20] = "2";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}
	else if( unit.weaponName == "Hidden Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Ninja Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Short Edge" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Ninja Edge" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Spell Edge" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}
	else if( unit.weaponName == "Sasuke Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}
	else if( unit.weaponName == "Iga Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "7";
	}
	else if( unit.weaponName == "Koga Knife" )
	{
		qsVec[19] = "1";
		qsVec[20] = "3";
		qsVec[21] = "0";
		qsVec[22] = "8";
	}
	else if( unit.weaponName == "Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Thunder Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Flame Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Ice Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "4";
	}
	else if( unit.weaponName == "Poison Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "5";
	}
	else if( unit.weaponName == "Wizard Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "6";
	}
	else if( unit.weaponName == "Faith Rod" )
	{
		qsVec[19] = "1";
		qsVec[20] = "4";
		qsVec[21] = "0";
		qsVec[22] = "7";
	}
	else if( unit.weaponName == "Javelin" )
	{
		qsVec[19] = "1";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "1";
	}
	else if( unit.weaponName == "Spear" )
	{
		qsVec[19] = "1";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "2";
	}
	else if( unit.weaponName == "Mythril Spear" )
	{
		qsVec[19] = "1";
		qsVec[20] = "5";
		qsVec[21] = "0";
		qsVec[22] = "3";
	}
	else if( unit.weaponName == "Partisan" )
	{
		qsVec[19] = "1"; qsVec[20] = "5"; qsVec[21] = "0"; qsVec[22] = "4";
	}
	else if( unit.weaponName == "Oberisk" )
	{
		qsVec[19] = "1"; qsVec[20] = "5"; qsVec[21] = "0"; qsVec[22] = "5";
	}
	else if( unit.weaponName == "Holy Lance" )
	{
		qsVec[19] = "1"; qsVec[20] = "5"; qsVec[21] = "0"; qsVec[22] = "6";
	}	
	else if( unit.weaponName == "Dragon Whisker" )
	{
		qsVec[19] = "1"; qsVec[20] = "5"; qsVec[21] = "0"; qsVec[22] = "7";
	}	
	else if( unit.weaponName == "Javelin 2" )
	{
		qsVec[19] = "1"; qsVec[20] = "5"; qsVec[21] = "0"; qsVec[22] = "8";
	}	
	else if( unit.weaponName == "Oak Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "1";
	}
	else if( unit.weaponName == "White Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "2";
	}
	else if( unit.weaponName == "Healing Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "3";
	}
	else if( unit.weaponName == "Rainbow Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "4";
	}
	else if( unit.weaponName == "Wizard Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "5";
	}
	else if( unit.weaponName == "Gold Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "6";
	}	
	else if( unit.weaponName == "Mace of Zeus" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "7";
	}
	else if( unit.weaponName == "Sage Staff" )
	{
		qsVec[19] = "1"; qsVec[20] = "6"; qsVec[21] = "0"; qsVec[22] = "8";
	}
	else if( unit.weaponName == "Cypress Rod" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "1";
	}	
	else if( unit.weaponName == "Battle Bamboo" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "2";
	}
	else if( unit.weaponName == "Musk Rod" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "3";
	}
	else if( unit.weaponName == "Iron Rod" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "4";
	}
	else if( unit.weaponName == "Gokuu Rod" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "5";
	}
	else if( unit.weaponName == "Ivory Rod" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "6";
	}
	else if( unit.weaponName == "Octagon Rod" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "7";
	}
	else if( unit.weaponName == "Whale Whisker" )
	{
		qsVec[19] = "1"; qsVec[20] = "7"; qsVec[21] = "0"; qsVec[22] = "8";
	}
	else if( unit.weaponName == "Broad Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "1";
	}	
	else if( unit.weaponName == "Long Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "2";
	}
	else if( unit.weaponName == "Iron Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "3";
	}
	else if( unit.weaponName == "Mythril Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "4";
	}
	else if( unit.weaponName == "Blood Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "5";
	}
	else if( unit.weaponName == "Coral Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "6";
	}
	else if( unit.weaponName == "Ancient Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "7";
	}
	else if( unit.weaponName == "Sleep Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "8";
	}
	else if( unit.weaponName == "Platinum Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "0"; qsVec[22] = "9";
	}	
	else if( unit.weaponName == "Diamond Sword" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "1"; qsVec[22] = "0";
	}
	else if( unit.weaponName == "Ice Brand" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "1"; qsVec[22] = "1";
	}
	else if( unit.weaponName == "Rune Blade" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "1"; qsVec[22] = "2";
	}	
	else if( unit.weaponName == "Nagrarock" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "1"; qsVec[22] = "3";
	}
	else if( unit.weaponName == "Materia Blade" )
	{
		qsVec[19] = "1"; qsVec[20] = "8"; qsVec[21] = "1"; qsVec[22] = "4";
	}

}

void qsOffHand( Player unit, vector<string> &qsVec )
{
	//23 - 26
	//0 1 0 0 for bare hands 0000 for nothing at all
	if( unit.offHand == false && unit.offHandType != "Bare Hands" )
	{
		qsVec[23] = "0";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "0";
	}
	else if( unit.offHand == false && unit.offHandType == "Bare Hands" )
	{
		qsVec[23] = "0";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "0";
	}
	else if( unit.offHandName == "Battle Axe" )
	{
		qsVec[23] = "0";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Giant Axe" )
	{
		qsVec[23] = "0";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Slasher" )
	{
		qsVec[23] = "0";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "C Bag" )
	{
		qsVec[23] = "0";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "FS Bag" )
	{
		qsVec[23] = "0";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "P Bag" )
	{
		qsVec[23] = "0";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "H Bag" )
	{
		qsVec[23] = "0";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Long Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Silver Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Ice Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Lightning Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Windslash Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}	
	else if( unit.offHandName == "Mythril Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}	
	else if( unit.offHandName == "Ultimus Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "7";
	}
	else if( unit.offHandName == "Yoichi Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "8";
	}	
	else if( unit.offHandName == "Perseus Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "9";
	}		
	else if( unit.offHandName == "Bow Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Night Killer" )
	{
		qsVec[23] = "0";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Cross Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Poison Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Hunting Bow" )
	{
		qsVec[23] = "0";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}
	else if( unit.offHandName == "Gastrafitis" )
	{
		qsVec[23] = "0";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}
	else if( unit.offHandName == "Battle Dict" )
	{
		qsVec[23] = "0";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Monster Dict" )
	{
		qsVec[23] = "0";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Papyrus Plate" )
	{
		qsVec[23] = "0";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Madlemgem" )
	{
		qsVec[23] = "0";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Persia" )
	{
		qsVec[23] = "0";
		qsVec[24] = "6";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Cashmere" )
	{
		qsVec[23] = "0";
		qsVec[24] = "6";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Ryozan Silk" )
	{
		qsVec[23] = "0";
		qsVec[24] = "6";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Flail" )
	{
		qsVec[23] = "0";
		qsVec[24] = "7";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}	
	else if( unit.offHandName == "Flame Whip" )
	{
		qsVec[23] = "0";
		qsVec[24] = "7";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Morning Star" )
	{
		qsVec[23] = "0";
		qsVec[24] = "7";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Scorpion Tail" )
	{
		qsVec[23] = "0";
		qsVec[24] = "7";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Romanda Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "8";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Mythril Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "8";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Stone Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "8";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Blaze Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "8";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}	
	else if( unit.offHandName == "Glacier Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "8";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}	
	else if( unit.offHandName == "Blast Gun" )
	{
		qsVec[23] = "0";
		qsVec[24] = "8";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}
	else if( unit.offHandName == "Ramia Harp" )
	{
		qsVec[23] = "0";
		qsVec[24] = "9";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Bloody Strings" )
	{
		qsVec[23] = "0";
		qsVec[24] = "9";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Fairy Harp" )
	{
		qsVec[23] = "0";
		qsVec[24] = "9";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Asura Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Koutetsu Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Bizen Boat" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Murasame" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Heaven's Cloud" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}
	else if( unit.offHandName == "Kiyomori" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}
	else if( unit.offHandName == "Muramasa" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "7";
	}	
	else if( unit.offHandName == "Kikuichimoji" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "8";
	}
	else if( unit.offHandName == "Masamune" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "0";
		qsVec[26] = "9";
	}	
	else if( unit.offHandName == "Chirijiraden" )
	{
		qsVec[23] = "1";
		qsVec[24] = "0";
		qsVec[25] = "1";
		qsVec[26] = "0";
	}	
	else if( unit.offHandName == "Dagger" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Mythril Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Blind Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Mage Masher" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Platina Dagger" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}	
	else if( unit.offHandName == "Main Gauche" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}
	else if( unit.offHandName == "Orichalcum" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "7";
	}
	else if( unit.offHandName == "Assassin Dagger" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "8";
	}
	else if( unit.offHandName == "Air Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "0";
		qsVec[26] = "9";
	}	
	else if( unit.offHandName == "Zorlin Shape" )
	{
		qsVec[23] = "1";
		qsVec[24] = "1";
		qsVec[25] = "1";
		qsVec[26] = "0";
	}
	else if( unit.offHandName == "Defender" )
	{
		qsVec[23] = "1";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Save the Queen" )
	{
		qsVec[23] = "1";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Excalibur" )
	{
		qsVec[23] = "1";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Ragnarok" )
	{
		qsVec[23] = "1";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Chaos Blade" )
	{
		qsVec[23] = "1";
		qsVec[24] = "2";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}
	else if( unit.offHandName == "Hidden Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Ninja Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Short Edge" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Ninja Edge" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Spell Edge" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}
	else if( unit.offHandName == "Sasuke Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}
	else if( unit.offHandName == "Iga Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "7";
	}
	else if( unit.offHandName == "Koga Knife" )
	{
		qsVec[23] = "1";
		qsVec[24] = "3";
		qsVec[25] = "0";
		qsVec[26] = "8";
	}
	else if( unit.offHandName == "Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Thunder Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Flame Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Ice Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "4";
	}
	else if( unit.offHandName == "Poison Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "5";
	}
	else if( unit.offHandName == "Wizard Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "6";
	}
	else if( unit.offHandName == "Faith Rod" )
	{
		qsVec[23] = "1";
		qsVec[24] = "4";
		qsVec[25] = "0";
		qsVec[26] = "7";
	}
	else if( unit.offHandName == "Javelin" )
	{
		qsVec[23] = "1";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "1";
	}
	else if( unit.offHandName == "Spear" )
	{
		qsVec[23] = "1";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "2";
	}
	else if( unit.offHandName == "Mythril Spear" )
	{
		qsVec[23] = "1";
		qsVec[24] = "5";
		qsVec[25] = "0";
		qsVec[26] = "3";
	}
	else if( unit.offHandName == "Partisan" )
	{
		qsVec[23] = "1"; qsVec[24] = "5"; qsVec[25] = "0"; qsVec[26] = "4";
	}
	else if( unit.offHandName == "Oberisk" )
	{
		qsVec[23] = "1"; qsVec[24] = "5"; qsVec[25] = "0"; qsVec[26] = "5";
	}
	else if( unit.offHandName == "Holy Lance" )
	{
		qsVec[23] = "1"; qsVec[24] = "5"; qsVec[25] = "0"; qsVec[26] = "6";
	}	
	else if( unit.offHandName == "Dragon Whisker" )
	{
		qsVec[23] = "1"; qsVec[24] = "5"; qsVec[25] = "0"; qsVec[26] = "7";
	}	
	else if( unit.offHandName == "Javelin 2" )
	{
		qsVec[23] = "1"; qsVec[24] = "5"; qsVec[25] = "0"; qsVec[26] = "8";
	}	
	else if( unit.offHandName == "Oak Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "1";
	}
	else if( unit.offHandName == "White Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "2";
	}
	else if( unit.offHandName == "Healing Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "3";
	}
	else if( unit.offHandName == "Rainbow Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "4";
	}
	else if( unit.offHandName == "Wizard Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "5";
	}
	else if( unit.offHandName == "Gold Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "6";
	}	
	else if( unit.offHandName == "Mace of Zeus" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "7";
	}
	else if( unit.offHandName == "Sage Staff" )
	{
		qsVec[23] = "1"; qsVec[24] = "6"; qsVec[25] = "0"; qsVec[26] = "8";
	}
	else if( unit.offHandName == "Cypress Rod" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "1";
	}	
	else if( unit.offHandName == "Battle Bamboo" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "2";
	}
	else if( unit.offHandName == "Musk Rod" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "3";
	}
	else if( unit.offHandName == "Iron Rod" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "4";
	}
	else if( unit.offHandName == "Gokuu Rod" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "5";
	}
	else if( unit.offHandName == "Ivory Rod" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "6";
	}
	else if( unit.offHandName == "Octagon Rod" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "7";
	}
	else if( unit.offHandName == "Whale Whisker" )
	{
		qsVec[23] = "1"; qsVec[24] = "7"; qsVec[25] = "0"; qsVec[26] = "8";
	}
	else if( unit.offHandName == "Broad Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "1";
	}	
	else if( unit.offHandName == "Long Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "2";
	}
	else if( unit.offHandName == "Iron Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "3";
	}
	else if( unit.offHandName == "Mythril Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "4";
	}
	else if( unit.offHandName == "Blood Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "5";
	}
	else if( unit.offHandName == "Coral Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "6";
	}
	else if( unit.offHandName == "Ancient Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "7";
	}
	else if( unit.offHandName == "Sleep Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "8";
	}
	else if( unit.offHandName == "Platinum Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "0"; qsVec[26] = "9";
	}	
	else if( unit.offHandName == "Diamond Sword" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "1"; qsVec[26] = "0";
	}
	else if( unit.offHandName == "Ice Brand" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "1"; qsVec[26] = "1";
	}
	else if( unit.offHandName == "Rune Blade" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "1"; qsVec[26] = "2";
	}	
	else if( unit.offHandName == "Nagrarock" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "1"; qsVec[26] = "3";
	}
	else if( unit.offHandName == "Materia Blade" )
	{
		qsVec[23] = "1"; qsVec[24] = "8"; qsVec[25] = "1"; qsVec[26] = "4";
	}
	if( unit.offHandName == "Escutcheon" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "1";
	}
	else if( unit.offHandName == "Buckler" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "2";
	}
	else if( unit.offHandName == "Bronze Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "3";
	}
	else if( unit.offHandName == "Round Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "4";
	}
	else if( unit.offHandName == "Mythril Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "5";
	}
	else if( unit.offHandName == "Gold Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "6";
	}
	else if( unit.offHandName == "Ice Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "7";
	}
	else if( unit.offHandName == "Flame Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "8";
	}
	else if( unit.offHandName == "Aegis Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "0"; qsVec[26] = "9";
	}
	else if( unit.offHandName == "Diamond Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "0";
	}
	else if( unit.offHandName == "Platina Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "1";
	}
	else if( unit.offHandName == "Crystal Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "2";
	}
	else if( unit.offHandName == "Genji Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "3";
	}
	else if( unit.offHandName == "Kaiser Plate" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "4";
	}
	else if( unit.offHandName == "Venetian Shield" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "5";
	}
	else if( unit.offHandName == "Escutcheon 2" )
	{
		qsVec[23] = "1"; qsVec[24] = "9"; qsVec[25] = "1"; qsVec[26] = "6";
	}

}

void qsHead( Player unit, vector<string> &qsVec )
{

	if( unit.head == false )
	{
		qsVec[27] = "0";
		qsVec[28] = "0";
		qsVec[29] = "0";
		qsVec[30] = "0";
	}
	else if( unit.headName == "Cachusha" )
	{
		qsVec[27] = "0"; qsVec[28] = "1"; qsVec[29] = "0"; qsVec[30] = "1";
	}
	else if( unit.headName == "Barette" )
	{
		qsVec[27] = "0"; qsVec[28] = "1"; qsVec[29] = "0"; qsVec[30] = "2";
	}
	else if( unit.headName == "Ribbon" )
	{
		qsVec[27] = "0"; qsVec[28] = "1"; qsVec[29] = "0"; qsVec[30] = "3";
	}
	else if( unit.headName == "Leather Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "1";
	}
	else if( unit.headName == "Bronze Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "2";
	}
	else if( unit.headName == "Iron Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "3";
	}
	else if( unit.headName == "Barbuta" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "4";
	}
	else if( unit.headName == "Mythril Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "5";
	}
	else if( unit.headName == "Gold Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "6";
	}
	else if( unit.headName == "Cross Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "7";
	}
	else if( unit.headName == "Diamond Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "8";
	}
	else if( unit.headName == "Platina Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "0"; qsVec[30] = "9";
	}
	else if( unit.headName == "Circlet Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "1"; qsVec[30] = "0";
	}
	else if( unit.headName == "Crystal Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "1"; qsVec[30] = "1";
	}
	else if( unit.headName == "Genji Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "1"; qsVec[30] = "2";
	}
	else if( unit.headName == "Grand Helmet" )
	{
		qsVec[27] = "0"; qsVec[28] = "2"; qsVec[29] = "1"; qsVec[30] = "3";
	}
	else if( unit.headName == "Leather Hat" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "1";
	}
	else if( unit.headName == "Feather Hat" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "2";
	}
	else if( unit.headName == "Red Hood" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "3";
	}
	else if( unit.headName == "Headgear" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "4";
	}
	else if( unit.headName == "Triangle Hat" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "5";
	}
	else if( unit.headName == "Green Beret" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "6";
	}
	else if( unit.headName == "Twist Headband" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "7";
	}
	else if( unit.headName == "Holy Miter" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "8";
	}
	else if( unit.headName == "Black Hood" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "0"; qsVec[30] = "9";
	}
	else if( unit.headName == "Golden Hairpin" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "1"; qsVec[30] = "0";
	}
	else if( unit.headName == "Flash Hat" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "1"; qsVec[30] = "1";
	}
	else if( unit.headName == "Thief Hat" )
	{
		qsVec[27] = "0"; qsVec[28] = "3"; qsVec[29] = "1"; qsVec[30] = "2";
	}
	
}

void qsBody( Player unit, vector<string> &qsVec )
{
	if( unit.body == false )
	{
		qsVec[31] = "0";
		qsVec[32] = "0";
		qsVec[33] = "0";
		qsVec[34] = "0";
	}
	else if( unit.bodyName == "Leather Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "1";
	}
	else if( unit.bodyName == "Linen Cuirass" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "2";
	}
	else if( unit.bodyName == "Bronze Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "3";
	}
	else if( unit.bodyName == "Chain Mail" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "4";
	}
	else if( unit.bodyName == "Mythril Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "5";
	}
	else if( unit.bodyName == "Plate Mail" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "6";
	}
	else if( unit.bodyName == "Gold Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "7";
	}
	else if( unit.bodyName == "Diamond Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "8";
	}
	else if( unit.bodyName == "Platina Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "0"; qsVec[34] = "9";
	}
	else if( unit.bodyName == "Carabini Mail" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "1"; qsVec[34] = "0";
	}
	else if( unit.bodyName == "Crystal Mail" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "1"; qsVec[34] = "1";
	}
	else if( unit.bodyName == "Genji Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "1"; qsVec[34] = "2";
	}
	else if( unit.bodyName == "Reflect Armor" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "1"; qsVec[34] = "3";
	}
	else if( unit.bodyName == "Maximillian" )
	{
		qsVec[31] = "0"; qsVec[32] = "1"; qsVec[33] = "1"; qsVec[34] = "4";
	}
	else if( unit.bodyName == "Clothes" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "1";
	}
	else if( unit.bodyName == "Leather Outfit" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "2";
	}
	else if( unit.bodyName == "Leather Vest" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "3";
	}
	else if( unit.bodyName == "Chain Vest" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "4";
	}
	else if( unit.bodyName == "Mythril Vest" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "5";
	}
	else if( unit.bodyName == "Adaman Vest" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "6";
	}
	else if( unit.bodyName == "Wizard Outfit" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "7";
	}
	else if( unit.bodyName == "Brigandine" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "8";
	}
	else if( unit.bodyName == "Judo Outfit" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "0"; qsVec[34] = "9";
	}
	else if( unit.bodyName == "Power Sleeve" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "1"; qsVec[34] = "0";
	}
	else if( unit.bodyName == "Earth Clothes" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "1"; qsVec[34] = "1";
	}
	else if( unit.bodyName == "Secret Clothes" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "1"; qsVec[34] = "2";
	}
	else if( unit.bodyName == "Black Costume" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "1"; qsVec[34] = "3";
	}
	else if( unit.bodyName == "Rubber Costume" )
	{
		qsVec[31] = "0"; qsVec[32] = "2"; qsVec[33] = "1"; qsVec[34] = "4";
	}
	else if( unit.bodyName == "Linen Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "1";
	}
	else if( unit.bodyName == "Silk Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "2";
	}
	else if( unit.bodyName == "Wizard Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "3";
	}
	else if( unit.bodyName == "Chameleon Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "4";
	}
	else if( unit.bodyName == "White Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "5";
	}
	else if( unit.bodyName == "Black Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "6";
	}
	else if( unit.bodyName == "Light Robe" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "7";
	}
	else if( unit.bodyName == "Robe of Lords" )
	{
		qsVec[31] = "0"; qsVec[32] = "3"; qsVec[33] = "0"; qsVec[34] = "8";
	}

}

void qsAcc( Player unit, vector<string> &qsVec )
{
	//35 - 38

	if( unit.accessory == false )
	{
		qsVec[35] = "0";
		qsVec[36] = "0";
		qsVec[37] = "0";
		qsVec[38] = "0";
	}
	else if( unit.accName == "Battle Boots" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "1";
	}
	else if( unit.accName == "Spike Boots" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "2";
	}
	else if( unit.accName == "Germinas Boots" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "3";
	}
	else if( unit.accName == "Rubber Shoes" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "4";
	}
	else if( unit.accName == "Feather Boots" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "5";
	}
	else if( unit.accName == "Sprint Shoes" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "6";
	}
	else if( unit.accName == "Red Shoes" )
	{
		qsVec[35] = "0"; qsVec[36] = "1"; qsVec[37] = "0"; qsVec[38] = "7";
	}
	else if( unit.accName == "Power Wrist" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "1";
	}
	else if( unit.accName == "Genji Gauntlet" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "2";
	}
	else if( unit.accName == "Magic Gauntlet" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "3";
	}
	else if( unit.accName == "Bracer" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "4";
	}
	else if( unit.accName == "Reflect Ring" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "5";
	}
	else if( unit.accName == "Defense Ring" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "6";
	}
	else if( unit.accName == "Magic Ring" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "7";
	}
	else if( unit.accName == "Cursed Ring" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "8";
	}
	else if( unit.accName == "Angel Ring" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "0"; qsVec[38] = "9";
	}
	else if( unit.accName == "Diamond Armlet" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "1"; qsVec[38] = "0";
	}
	else if( unit.accName == "Jade Armlet" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "1"; qsVec[38] = "1";
	}
	else if( unit.accName == "Defense Armlet" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "1"; qsVec[38] = "2";
	}
	else if( unit.accName == "N-Kai Armlet" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "1"; qsVec[38] = "3";
	}
	else if( unit.accName == "108 Gems" )
	{
		qsVec[35] = "0"; qsVec[36] = "2"; qsVec[37] = "1"; qsVec[38] = "4";
	}
	else if( unit.accName == "Small Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "1";
	}
	else if( unit.accName == "Leather Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "2";
	}
	else if( unit.accName == "Wizard Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "3";
	}
	else if( unit.accName == "Elf Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "4";
	}
	else if( unit.accName == "Dracula Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "5";
	}
	else if( unit.accName == "Feather Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "6";
	}
	else if( unit.accName == "Vanish Mantle" )
	{
		qsVec[35] = "0"; qsVec[36] = "3"; qsVec[37] = "0"; qsVec[38] = "7";
	}
	else if( unit.accName == "Chantage" )
	{
		qsVec[35] = "0"; qsVec[36] = "4"; qsVec[37] = "0"; qsVec[38] = "1";
	}
	else if( unit.accName == "Cherche" )
	{
		qsVec[35] = "0"; qsVec[36] = "4"; qsVec[37] = "0"; qsVec[38] = "2";
	}
	else if( unit.accName == "Salty Rage" )
	{
		qsVec[35] = "0"; qsVec[36] = "4"; qsVec[37] = "0"; qsVec[38] = "3";
	}
	else if( unit.accName == "Setiemson" )
	{
		qsVec[35] = "0"; qsVec[36] = "4"; qsVec[37] = "0"; qsVec[38] = "4";
	}
}

void quickStartCodeMaker( Player unit, vector<string> &qsVec )
{
	
	char buffer[100];
	string tempString = "  ";
	int i = 0;

	if( unit.sex == "Male" )
		qsVec[0] = "1";
	else qsVec[0] = "2";
	
	tempString = itoa( unit.zodiacInt, buffer, 10 );
	if( unit.zodiacInt < 10 )
	{
		qsVec[1] = "0";
		qsVec[2] = tempString[0];
	}
	else
	{
		qsVec[1] = tempString[0];
		qsVec[2] = tempString[1];
	}

	tempString = itoa( unit.brave, buffer, 10 );
	if( unit.brave < 10 )
	{
		qsVec[3] = "0";
		qsVec[4] = tempString[0];
	}
	else
	{
		qsVec[3] = tempString[0];
		qsVec[4] = tempString[1];
	}

	tempString = itoa( unit.faith, buffer, 10 );
	if( unit.faith < 10 )
	{
		qsVec[5] = "0";
		qsVec[6] = tempString[0];
	}
	else
	{
		qsVec[5] = tempString[0];
		qsVec[6] = tempString[1];
	}
	
	tempString = itoa( unit.level, buffer, 10 );
	if( unit.level < 10 )
	{
		qsVec[7] = "0";
		qsVec[8] = tempString[0];
	}
	else
	{
		qsVec[7] = tempString[0];
		qsVec[8] = tempString[1];
	}


	//player class
	tempString = itoa( unit.playerClass, buffer, 10 );
	if( unit.playerClass < 10 )
	{
		qsVec[9] = "0";
		qsVec[10] = tempString[0];
	}
	else
	{
		qsVec[9] = tempString[0];
		qsVec[10] = tempString[1];
	}

	tempString = itoa( unit.secondaryNumber, buffer, 10 );
	if( unit.secondaryNumber < 10 )
	{
		qsVec[11] = "0";
		qsVec[12] = tempString[0];
	}
	else
	{
		qsVec[11] = tempString[0];
		qsVec[12] = tempString[1];
	}
	
	qsReaction( unit, qsVec ); //13-14
	qsSupport( unit, qsVec ); //15 16
	qsMovement( unit, qsVec ); //17 18
	
	qsWeapon( unit, qsVec ); //19-22
	qsOffHand( unit, qsVec ); //23-26
	qsHead( unit, qsVec ); //27-30
	qsBody( unit, qsVec ); //31-34
	qsAcc( unit, qsVec ); //35-38

	
	//position... can't really do it since units move
	//tempString = itoa( unit.currentRow, buffer, 10 );
	qsVec[39] = "0";
	//tempString = itoa( unit.currentCol, buffer, 10 );
	
	qsVec[40] = "0";

	//name
	for( i = 0; i < unit.playerName.size(); i++ )
	{
		qsVec[41 + i] = unit.playerName[i];
	}
	
}

void qsOutputBlue1( vector<string> vec )
{
	ofstream destination("blue1.txt");
	int i = 0;
	string *scr;
	scr = new string[vec.size()];
	for(int i=0; i< vec.size()-1; i++)
	{
		scr[i] = vec[i];//Copy the vector to the string
		destination << scr[i];
	}
	
}

void qsOutputBlue2( vector<string> vec )
{
	ofstream destination("blue2.txt");
	int i = 0;
	string *scr;
	scr = new string[vec.size()];
	for(int i=0; i< vec.size()-1; i++)
	{
		scr[i] = vec[i];//Copy the vector to the string
		destination << scr[i];
	}
	
}

void qsOutputRed1( vector<string> vec )
{
	ofstream destination("red1.txt");
	int i = 0;
	string *scr;
	scr = new string[vec.size()];
	for(int i=0; i< vec.size()-1; i++)
	{
		scr[i] = vec[i];//Copy the vector to the string
		destination << scr[i];
	}
	
}

void qsOutputRed2( vector<string> vec )
{
	ofstream destination("red2.txt");
	int i = 0;
	string *scr;
	scr = new string[vec.size()];
	for(int i=0; i< vec.size()-1; i++)
	{
		scr[i] = vec[i];//Copy the vector to the string
		destination << scr[i];
	}
	
}