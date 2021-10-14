int innerActMenu( Player actor )
{
	int actMenu = 0;
	string primaryDisplay = "";
	string tempSecondary = actor.secondary;

	if( actor.playerClass == 1 )
		primaryDisplay = "CHARGE";
	else if( actor.playerClass == 2 )
		primaryDisplay = "SING";
	else if( actor.playerClass == 3 )
		primaryDisplay = "MATH SKILL";
	else if( actor.playerClass == 4 )
		primaryDisplay = "ITEM";
	else if( actor.playerClass == 5 )
		primaryDisplay = "DANCE";
	else if( actor.playerClass == 6 )
		primaryDisplay = "ELEMENTAL";
	else if( actor.playerClass == 7 )
		primaryDisplay = "BATTLE SKILL";
	else if( actor.playerClass == 8 )
		primaryDisplay = "JUMP";
	else if( actor.playerClass == 9 )
		primaryDisplay = "TALK SKILL";
	else if( actor.playerClass == 10 )
		primaryDisplay = "MIME";
	else if( actor.playerClass == 11 )
		primaryDisplay = "PUNCH ART";
	else if( actor.playerClass == 12 )
		primaryDisplay = "THROW";
	else if( actor.playerClass == 13 )
		primaryDisplay = "YIN YANG MAGIC";
	else if( actor.playerClass == 14 )
		primaryDisplay = "WHITE MAGIC";
	else if( actor.playerClass == 15 )
		primaryDisplay = "DRAW OUT";
	else if( actor.playerClass == 16 )
		primaryDisplay = "BASIC SKILL";
	else if( actor.playerClass == 17 )
		primaryDisplay = "SUMMON MAGIC";
	else if( actor.playerClass == 18 )
		primaryDisplay = "STEAL";
	else if( actor.playerClass == 19 )
		primaryDisplay = "TIME MAGIC";
	else if( actor.playerClass == 20 )
		primaryDisplay = "BLACK MAGIC";

	if( actor.playerClass == 20 || actor.playerClass == 19 || actor.playerClass == 17||
		actor.playerClass == 14 || actor.playerClass == 13 || actor.playerClass == 9 )
	{
		if( actor.silence == true )
		{
			primaryDisplay = "SILENCED";
		}
	}
	if( actor.secondaryNumber == 20 || actor.secondaryNumber == 19 || actor.secondaryNumber == 17||
		actor.secondaryNumber == 14 || actor.secondaryNumber == 13 || actor.secondaryNumber == 9 )
	{
		if( actor.silence == true )
		{
			primaryDisplay = "SILENCED";
		}
	}

	if( actor.defend == false && actor.equipChange == false )
	{
		while( ( cout << "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " ACT Menu ---\n"
			<< "1.) ATTACK\n"
			<< "2.) " << primaryDisplay << "\n" 
			<< "3.) " << tempSecondary << "\n"
			<< "4.) Return to Menu\n" ) 
			&& ( !(cin>> actMenu ) || actMenu < 1 || actMenu > 4 || ( actMenu == 3 && actor.secondary == "NONE")
			|| ( ( ( actor.frog == true && actor.playerClass != 20 ) || actor.berserk == true || actor.bloodSuck == true) && ( actMenu == 2 ) )
			|| ( ( ( actor.frog == true && actor.secondaryNumber != 20 ) || actor.berserk == true || actor.bloodSuck == true) && ( actMenu == 3 ) )
			|| ( actMenu == 2 && primaryDisplay == "SILENCED" ) || ( actMenu == 3 && tempSecondary == "SILENCED" )
			) )
		{
			cout << "That is not a valid menu selection.\n";
			if( actor.frog == true )
				cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is a Frog and can only Attack!\n";
			if( actor.berserk == true )
				cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is Berserk and can only Attack!\n";
			if( actor.bloodSuck == true )
				cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is a Vampire and can only Attack!\n";
			cout << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else if( actor.defend == true || actor.equipChange == true )
	{
		while( ( cout << "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
			<< " ACT Menu ---\n"
			<< "1.) ATTACK\n"
			<< "2.) " << primaryDisplay << "\n"  
			<< "3.) " << actor.secondary << "\n"
			<< "4.) Return to Menu\n" )
			<< "5.) " << actor.support << "\n"
			&& ( !(cin>> actMenu ) || actMenu < 1 || actMenu > 5 || ( actMenu == 3 && actor.secondary == "NONE")
			|| ( ( ( actor.frog == true && actor.playerClass != 20 ) || actor.berserk == true || actor.bloodSuck == true) && ( actMenu == 2 || actMenu == 5 ) )
			|| ( ( ( actor.frog == true && actor.secondaryNumber != 20 ) || actor.berserk == true || actor.bloodSuck == true) && ( actMenu == 3 || actMenu == 5 ) )
			|| ( actMenu == 2 && primaryDisplay == "SILENCED" ) || ( actMenu == 3 && tempSecondary == "SILENCED" )
			) )
		{
			cout << "That is not a valid menu selection.\n";
			if( actor.frog == true )
				cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is a Frog and can only Attack!\n";
			if( actor.berserk == true )
				cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is Berserk and can only Attack!\n";
			if( actor.bloodSuck == true )
				cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is a Vampire and can only Attack!\n";
			cout << "\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	
	return actMenu;
}

//test the loop with item then copy to other classes
int turnActFunction( Player &actor, Item &blueItem, Item &redItem, BattleSkill &battleSkillObject, Charge &chargeObject,
	BasicSkill &basicSkillObject, Steal &stealObject, char myArray[][11], Throw &blueThrow, Throw &redThrow, Player &player1, Player &player2,
	Player &player3, Player &player4, Player &player5, Player &player6, Player &player7,
	Player &player8, Player &player9, Player &player10, Player &nullPlayer, Song &songObject,
	Dance &danceObject, Jump &jumpObject, PunchArt &punchArtObject, Elemental &elementalObject,
	DrawOut &blueDraw, DrawOut &redDraw, TalkSkill &talkSkillObject, YinYang &yinYangObject,
	White &whiteObject, Black &blackObject, Time &timeObject, Summon &summonObject, Golem &blueGolem,
	Golem &redGolem, MathSkill &mathSkillObject, MimeClass &mimeObject )
{

	int actMenu = 0;

	actMenu = innerActMenu( actor );

	if( actMenu == 1)
	{
		turnAttackFunction( actor, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, nullPlayer, myArray, blueItem,
			redItem, blueGolem, redGolem, mimeObject );
		
		mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
			player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
			redGolem, myArray, false, false, false, false, true );

		if( actor.confirm == 3 )
		{
			actor.confirm = 0;
			actMenu = 2;
			return actMenu;
		}
		else
		{
			actMenu = 1;
			return actMenu;
		}
	}
	else if( actMenu == 2) //player chooses class ability
	{
		if(actor.playerClass == 1) //if player is an Archer
		{
			chargeObject.chargeMenu( chargeObject, actor );
			chargeObject.chargeFunction( chargeObject, myArray, actor, player1, player2,
				player3, player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, mimeObject );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 2 ) //bard
		{
			songObject.songMenu( songObject, actor );
			songObject.songSuccess( songObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray);

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 3 )
		{
			mathSkillObject.mathSkillMenu( mathSkillObject, actor );
			mathSkillObject.mathSkillSuccess( mathSkillObject, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer,
				myArray, blueItem, redItem, mimeObject );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if(actor.playerClass == 4) //if player is a chemist.
		{
			if( actor.teamName == "Blue")
			{
				blueItem.itemMenu( blueItem, actor );
				blueItem.itemSuccess( blueItem, actor, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, nullPlayer, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			else
			{
				redItem.itemMenu( redItem, actor );
				redItem.itemSuccess( redItem, actor, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, nullPlayer, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
		}
		else if( actor.playerClass == 5 ) //dancer
		{
			danceObject.danceMenu( danceObject, actor );
			danceObject.danceSuccess( danceObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray);

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 6 ) //geomancer
		{
			elementalObject.elementalMenu( elementalObject );
			elementalObject.elementalSuccess( elementalObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray, 
				blueItem, redItem, mimeObject );
			
			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, true );
			
			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if(actor.playerClass == 7) //if player is a Knight
		{
			battleSkillObject.battleSkillMenu( battleSkillObject, actor );
			battleSkillObject.battleSkillSuccess( battleSkillObject, actor, myArray, player1,
				player2, player3, player4, player5, player6, player7, player8, player9,
				player10, nullPlayer, blueItem, redItem, blueGolem, redGolem, mimeObject );

			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 8 ) //Lancer
		{
			jumpObject.jumpMenu( jumpObject );
			jumpObject.jumpSuccess( jumpObject, actor, player1, player2, player3, player4, 
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 9 ) //Mediator
		{
			talkSkillObject.talkSkillMenu( talkSkillObject, actor );
			talkSkillObject.talkSkillSuccess( talkSkillObject, actor, player1, player2, player3, player4, 
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray, blueItem, redItem,
				mimeObject );
			
			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
				player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
				redGolem, myArray, false, false, false, false, false, false, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 10 ) //mime
		{
			cout << "Mime Class does not have any abilities to select\n";
			actor.confirm = 0;
			actMenu = 2;
			return actMenu;
		}
		else if( actor.playerClass == 11 ) //monk
		{
			punchArtObject.punchArtMenu( punchArtObject, actor );
			punchArtObject.punchArtSuccess( punchArtObject, actor, player1, player2,
				player3, player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem, mimeObject );

			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, false, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 12) //if player is a Ninja
		{
			if( actor.teamName == "Blue" )
			{
				blueThrow.throwMenu( blueThrow, actor );
				blueThrow.throwSuccess( blueThrow, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, blueGolem, redGolem, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			else
			{
				redThrow.throwMenu( redThrow, actor );
				redThrow.throwSuccess( redThrow, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, blueGolem, redGolem, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
		}
		else if( actor.playerClass == 13 ) //if player is an Oracle
		{
			yinYangObject.yinYangMenu( yinYangObject, actor );
			yinYangObject.yinYangSuccess( yinYangObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 14 ) //if player is a Priest
		{
			whiteObject.whiteMenu( whiteObject, actor );
			whiteObject.whiteSuccess( whiteObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 15 ) //if player is a Samurai
		{
			if( actor.teamName == "Blue" )
			{
				blueDraw.drawOutMenu( blueDraw, actor );
				blueDraw.drawOutSuccess( blueDraw, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, false, false, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			else
			{
				redDraw.drawOutMenu( redDraw, actor );
				redDraw.drawOutSuccess( redDraw, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, false, false, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			
		}
		else if(actor.playerClass == 16) //if player is a Squire
		{
			basicSkillObject.basicSkillMenu( basicSkillObject, actor );
			basicSkillObject.basicSkillSuccess( basicSkillObject, actor, myArray, blueItem, redItem,
				player1, player2, player3, player4, player5, player6, player7, player8,
				player9, player10, nullPlayer, mimeObject );

			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 17 ) //summon
		{
			summonObject.summonMenu( summonObject, actor );
			summonObject.summonSuccess( summonObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 18 ) //if player is a thief
		{
			stealObject.stealMenu( stealObject, actor );
			stealObject.stealSuccess( stealObject, myArray, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer,
				blueGolem, redGolem, blueItem, redItem );

			mimeStealFunction( mimeObject, stealObject, player1, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player6, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player7, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player2, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player3, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player8, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player9, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player4, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player5, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player10, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 19 ) //time mage
		{
			timeObject.timeMenu( timeObject, actor );
			timeObject.timeSuccess( timeObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.playerClass == 20 ) //if player is a Wizard
		{
			blackObject.blackMenu( blackObject, actor );
			blackObject.blackSuccess( blackObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		
		actMenu = 1;
		return actMenu;
	}
	else if( actMenu == 3)
	{
		if(actor.secondaryNumber == 1) //if player is an Archer
		{
			chargeObject.chargeMenu( chargeObject, actor );
			chargeObject.chargeFunction( chargeObject, myArray, actor, player1, player2,
				player3, player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, mimeObject );
			
			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 2 ) //song
		{
			songObject.songMenu( songObject, actor );
			songObject.songSuccess( songObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray);
			
			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 3 )//calculator
		{
			mathSkillObject.mathSkillMenu( mathSkillObject, actor );
			mathSkillObject.mathSkillSuccess( mathSkillObject, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer,
				myArray, blueItem, redItem, mimeObject );
			
			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if(actor.secondaryNumber == 4 ) //if player is a chemist.
		{
			if( actor.teamName == "Blue")
			{
				blueItem.itemMenu( blueItem, actor );
				blueItem.itemSuccess( blueItem, actor, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, nullPlayer, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			else
			{
				redItem.itemMenu( redItem, actor );
				redItem.itemSuccess( redItem, actor, myArray, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10, nullPlayer, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
		}
		else if( actor.secondaryNumber == 5 ) //dance
		{
			danceObject.danceMenu( danceObject, actor );
			danceObject.danceSuccess( danceObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray);
			
			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 6 ) //elemental
		{
			elementalObject.elementalMenu( elementalObject );
			elementalObject.elementalSuccess( elementalObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray, blueItem, redItem,
				mimeObject );
			
			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if(actor.secondaryNumber == 7) //if player is a Knight
		{
			battleSkillObject.battleSkillMenu( battleSkillObject, actor );
			battleSkillObject.battleSkillSuccess( battleSkillObject, actor, myArray, player1,
				player2, player3, player4, player5, player6, player7, player8, player9,
				player10, nullPlayer, blueItem, redItem, blueGolem, redGolem, mimeObject );

			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 8 ) //jump
		{
			jumpObject.jumpMenu( jumpObject );
			jumpObject.jumpSuccess( jumpObject, actor, player1, player2, player3, player4, 
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray );
			
			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 9 ) // mediator
		{
			talkSkillObject.talkSkillMenu( talkSkillObject, actor );
			talkSkillObject.talkSkillSuccess( talkSkillObject, actor, player1, player2, player3, player4, 
				player5, player6, player7, player8, player9, player10, nullPlayer, myArray,
				blueItem, redItem, mimeObject );
			
			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
				player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
				redGolem, myArray, false, false, false, false, false, false, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 11 ) //monk, 10 is mime
		{
			punchArtObject.punchArtMenu( punchArtObject, actor );
			punchArtObject.punchArtSuccess( punchArtObject, actor, player1, player2,
				player3, player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem, mimeObject );

			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, false, false, false, false, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 12 ) //throw
		{
			if( actor.teamName == "Blue" )
			{
				blueThrow.throwMenu( blueThrow, actor );
				blueThrow.throwSuccess( blueThrow, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, blueGolem, redGolem, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, true );

				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			else
			{
				redThrow.throwMenu( redThrow, actor );
				redThrow.throwSuccess( redThrow, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, blueGolem, redGolem, mimeObject );

				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, true );


				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
		}
		else if( actor.secondaryNumber == 13 )//oracle
		{
			yinYangObject.yinYangMenu( yinYangObject, actor );
			yinYangObject.yinYangSuccess( yinYangObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 14 )//priest
		{
			whiteObject.whiteMenu( whiteObject, actor );
			whiteObject.whiteSuccess( whiteObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 15 ) // if secondary is samurai
		{
			if( actor.teamName == "Blue" )
			{
				blueDraw.drawOutMenu( blueDraw, actor );
				blueDraw.drawOutSuccess( blueDraw, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, mimeObject );
				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, false, false, true );


				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
			else
			{
				redDraw.drawOutMenu( redDraw, actor );
				redDraw.drawOutSuccess( redDraw, actor, player1, player2, player3, player4,
					player5, player6, player7, player8, player9, player10,
					nullPlayer, myArray, blueItem, redItem, mimeObject );
				mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, false, false, false, false, false, false, true );


				if( actor.confirm == 3 )
				{
					actor.confirm = 0;
					actMenu = 2;
					return actMenu;
				}
				else
				{
					actMenu = 1;
					return actMenu;
				}
			}
		}
		else if( actor.secondaryNumber == 16 ) //if player is a Squire
		{
			basicSkillObject.basicSkillMenu( basicSkillObject, actor );
			basicSkillObject.basicSkillSuccess( basicSkillObject, actor, myArray, blueItem, redItem,
				player1, player2, player3, player4, player5, player6, player7, player8,
				player9, player10, nullPlayer, mimeObject );
			mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
					player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
					redGolem, myArray, false, false, true );


			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 17 )//summoner
		{
			summonObject.summonMenu( summonObject, actor );
			summonObject.summonSuccess( summonObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if(actor.secondaryNumber == 18 ) //if player is a thief
		{
			stealObject.stealMenu( stealObject, actor );
			stealObject.stealSuccess( stealObject, myArray, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueGolem,
				redGolem, blueItem, redItem );

			mimeStealFunction( mimeObject, stealObject, player1, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player6, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player7, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player2, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player3, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player8, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player9, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player4, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player5, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );
			mimeStealFunction( mimeObject, stealObject, player10, actor, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem,
				blueGolem, redGolem, myArray, true );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 19 )//time mage
		{
			timeObject.timeMenu( timeObject, actor );
			timeObject.timeSuccess( timeObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		else if( actor.secondaryNumber == 20 )//wizard
		{
			blackObject.blackMenu( blackObject, actor );
			blackObject.blackSuccess( blackObject, actor, player1, player2, player3, player4,
				player5, player6, player7, player8, player9, player10,
				nullPlayer, myArray, blueItem, redItem );

			if( actor.confirm == 3 )
			{
				actor.confirm = 0;
				actMenu = 2;
				return actMenu;
			}
			else
			{
				actMenu = 1;
				return actMenu;
			}
		}
		
		actMenu = 1;
		return actMenu;
	}
	else if( actMenu == 4)
	{
		actMenu = 2;
		return actMenu;
	}
	else if( actMenu == 5 )
	{
		if( actor.defend == true )
		{
			actor.defending = true;
		}
		else if( actor.equipChange == true )
		{
			equipmentSelect( actor );
		}
		actMenu = 1;
		return actMenu;
	}
	cout << "error! act function reached a place it shouldn't\n";
	return 0; //this should never trigger
}