
int innerTopMenu(Player actor )
{
	int topMenu = 0;

	if( actor.dontMove == true )
		cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Move!\n";
	if( actor.dontAct == true )
		cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Act!\n";
	if( actor.charging == true || actor.performing == true )
	{
		cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is casting " << actor.ctrName << ".\n"
			<< "\t" << actor.ctrName << " will cancel if ACT is selected.\n";
	}
	if( actor.charm == true )
	{
		cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is CHARMED!";
		if( actor.teamName == "Blue" )
			cout << " RED Player gets to control the unit!\n";
		else cout << " BLUE Player gets to control the unit!\n";
	}

	while( (cout << "\n" << "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
	<<" '" << actor.mapSymbol <<"' ---\n"
	<< "1.) MOVE" << "          4.) Show Active Turn Menu\n"
	<< "2.) ACT" << "           5.) Show Player Stats\n"
	<< "3.) WAIT" << "          6.) Show Map\n"
	) 
	&&
		(!(cin >> topMenu ) || topMenu < 1 || topMenu > 6 || ( topMenu == 1 && actor.dontMove == true )
		|| ( topMenu == 2 && actor.dontAct == true )
		))
	{
		cout << "That is not a valid menu selection. Enter a valid number.\n";
		if( actor.dontMove == true )
			cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Move!\n";
		if( actor.dontAct == true )
			cout  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Act!\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	return topMenu;

}

//triggered when ct is over 100, add tie breaker
// if you are performing/charging can you continue doing it and still move/change direction?
void turnFunction( Player &actor, char myArray[][11], int &turn, int row,
	int col, int clockTick, Item &blueItem, Item &redItem, BattleSkill &battleSkillObject,
	Charge &chargeObject, BasicSkill &basicSkillObject, Steal &stealObject, Player &player1,
	Player &player2, Player &player3, Player &player4, Player &player5, Player &player6,
	Player &player7, Player &player8, Player &player9, Player &player10,
	Player &nullPlayer, Throw &blueThrow, Throw &redThrow, Song &songObject,
	Dance &danceObject, Jump &jumpObject, PunchArt &punchArtObject, Elemental &elementalObject,
	DrawOut &blueDraw, DrawOut &redDraw, TalkSkill &talkSkillObject, YinYang &yinYangObject,
	White &whiteObject, Black &blackObject, Time &timeObject, Summon &summonObject,
	Golem &blueGolem, Golem &redGolem, MathSkill &mathSkillObject, MimeClass &mimeObject )
{
	int topMenuConfirm = 2;
	int topMenu = 0;
	int moveActConfirm = 2;
	int moveAct = 0;
	int actMoveConfirm = 2;
	int actMove = 0;
	int moveChicken = 0;
	int confusionInt = 0;
	string ctrPause = ""; //pauses action after an act
	
	while(true)
	{
		displayMap( myArray, turn, row, col, clockTick);
		turnUnderMap( player1, player2, player3, player4, player5, player6, player7,
				player8, player9, player10, nullPlayer, myArray );
		outputMap(myArray, turn, row, col, clockTick, player1, player2, player6, player7 );

		outputStats(  player1, player2, player6, player7 );
		outputActiveTurn( player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10 );

		actor.defending = false;
		if( actor.chicken == true )
		{
			actor.brave += 1;
			if( actor.brave >= 10 )
			{
				actor.chicken = false;
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " is no longer a Chicken!\n";
			}
			else
			{
				moveChicken = chickenMove( actor, myArray, player1, player2, player3, player4, player5, player6,
					player7, player8, player9, player10 );
				if( moveChicken == 0 )
				{
					actor.ct -= 60;
					if(actor.ct > 60 )
					{
						actor.ct = 60;
					}
					regenFunction( actor );
					poisonFunction( actor );

					turn++;
					break;
				}
				else
				{
					actor.ct -= 80;
					if(actor.ct > 60 )
					{
						actor.ct = 60;
					}
					regenFunction( actor );
					poisonFunction( actor );

					turn++;
					break;
				}
			}
		}
		
		confusionInt = confusionAction( actor, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, myArray, nullPlayer, blueGolem, redGolem, blueItem,
			redItem );
		
		//berserk has the same outputs as confusion except for the 1 where you can be cured mid turn
		confusionInt = berserkAction( actor, player1, player2, player3, player4, player5, player6,
			player7, player8, player9, player10, myArray, nullPlayer, blueGolem, redGolem, blueItem,
			redItem );

		if( confusionInt == 2 )
		{
			actor.ct -= 100;
			if(actor.ct > 60 )
			{
				actor.ct = 60;
			}
			regenFunction( actor );
			poisonFunction( actor );

			turn++;
			break;
		}
		else if( confusionInt == 3 || confusionInt == 4 || confusionInt == 5  )
		{
			actor.ct -= 80;
			if(actor.ct > 60 )
			{
				actor.ct = 60;
			}
			regenFunction( actor );
			poisonFunction( actor );

			turn++;
			break;
		}
		else if( confusionInt == 6 ) //wait
		{
			actor.ct -= 60;
			if(actor.ct > 60 )
			{
				actor.ct = 60;
			}
			regenFunction( actor );
			poisonFunction( actor );

			turn++;
			break;
		}
		
		if( actor.archerCharging )
		{
			int castingConfirm = 0;
			while( ( cout << "\n" << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " is casting " << actor.ctrName << ".\n1.) Continue casting  2.) Begin a new turn\n" )
				&& (!(cin >> castingConfirm) || castingConfirm < 1 || castingConfirm > 2 ))	
			{
				cout << "That is not a valid menu selection. Enter a valid number.\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
			if( castingConfirm == 1 )
			{
				actor.ct -= 100;
				if(actor.ct > 60 )
				{
					actor.ct = 60;
				}
				cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
				<< " continues to caste " << actor.ctrName << "\n";
				regenFunction( actor );
				poisonFunction( actor );

				turn++;
				break; //should break out of turnFunction
			}
			else if( castingConfirm == 2 )
			{
				actor.charging = false;
				actor.archerCharging = false;
				actor.performing = false;
				actor.ctrCountdownBool = false;
				actor.ctrInput = 0;
				actor.ctrK = 0;
				actor.ctrType = 0;
				actor.ctrCountdown = 0;
				actor.ctrEffect = 0;
				actor.ctrName = "";
			}
		} //archer charging option

		if( confusionInt == 1 ) //confused target acted, confusion broke and now gets to move... ug this is messy
		{
			topMenu = 2;
		}
		else
		{
			do //turn begins
			{
					do
					{
						topMenu = innerTopMenu( actor );
							
						if( topMenu == 4)
						{ //Active Turn Menu: Shows who gets to go on the next 10 turns
							activeTurn( player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, myArray, nullPlayer );
						} //end AT loop and returns to Menu
						//Player Status Menu: need to add equipment, rest of evasion
						if( topMenu == 5)
						{
							statsMenu( player1 );
							statsMenu( player2 );
							statsMenu( player6 );
							statsMenu( player7 );
						}
						if( topMenu == 6)
						{
							displayMap( myArray, turn, row, col, clockTick);
							turnUnderMap( player1, player2, player3, player4, player5, player6, player7,
								player8, player9, player10, nullPlayer, myArray );
							outputMap(myArray, turn, row, col, clockTick, player1, player2, player6, player7 );
						} 
					}while( ( topMenu == 4) || (topMenu == 5) || topMenu == 6 );//loops back if AT, Stat, or map chosen

				if( topMenu == 1) //Top Menu -- Move
				{
					topMenuConfirm = turnMoveFunction( actor, myArray, player1, player2, player3, player4,
						player5, player6, player7, player9, player9, player10 );
				}//end Top Menu -- Move
				else if( topMenu == 2) //Top Menu -- Act
				{
					if( actor.charging == true || actor.performing == true )
					{
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " cancels " << actor.ctrName << ".\n";
						actor.charging = false;
						actor.archerCharging = false;
						actor.performing = false;
						actor.ctrCountdownBool = false;
						actor.ctrInput = 0;
						actor.ctrK = 0;
						actor.ctrType = 0;
						actor.ctrCountdown = 0;
						actor.ctrEffect = 0;
						actor.ctrName = "";
					}
					topMenuConfirm = turnActFunction( actor, blueItem, redItem, battleSkillObject, chargeObject,
						basicSkillObject, stealObject, myArray, blueThrow, redThrow, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, songObject,
						danceObject, jumpObject, punchArtObject, elementalObject, blueDraw, redDraw,
						talkSkillObject, yinYangObject, whiteObject, blackObject, timeObject, summonObject,
						blueGolem, redGolem, mathSkillObject, mimeObject );

					outputStats( player1, player2, player6, player7 );
				}//end Top Menu -- Act
				else if( topMenu == 3) //Top Menu -- Wait
				{
					waitFunction(actor);
					topMenuConfirm = confirmFunction( topMenuConfirm );
				}//end Top Menu -- Wait
			}while(topMenuConfirm == 2); //end top menu loop
		}//end confusion loop

		if( topMenu == 1 ) //player selected Move and confirmed it, rest of turn continues
		{
			displayMap( myArray, turn, row, col, clockTick );
			turnUnderMap( player1, player2, player3, player4, player5, player6, player7,
				player8, player9, player10, nullPlayer, myArray );	
			outputMap(myArray, turn, row, col, clockTick, player1, player2, player6, player7 );
			do
			{
				do
				{
					if( actor.dontAct == true )
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Act!\n";
					if( actor.charging == true || actor.performing == true )
					{
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is casting " << actor.ctrName << ".\n"
							<< "\t" << actor.ctrName << " will cancel if ACT is selected.\n";
					}
					if( actor.charm == true )
					{
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is CHARMED!";
						if( actor.teamName == "Blue" )
							cout << " RED Player gets to control the unit!\n";
						else cout << " BLUE Player gets to control the unit!\n";
					}

					while( (cout << "\n" << "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<<" ---\n"
					<< "1.) ALREADY MOVED" << "     4.) Show Active Turn Menu\n"
					<< "2.) ACT          " << "     5.) Show Player Stats\n"
					<< "3.) WAIT         " << "     6.) Show Map\n"
						 ) &&
						(!(cin >> moveAct ) || moveAct < 1 || moveAct > 6 || moveAct == 1
						|| ( moveAct == 2 && actor.dontAct == true )
						))
					{
						cout << "That is not a valid menu selection.\n";
						if( actor.dontAct == true )
							cout << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Act!\n";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}				
					//Active Turn Menu: Shows who gets to go on the next 10 turns
						if( moveAct == 4)
						{
							activeTurn( player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, myArray, nullPlayer );
						} //end AT loop and returns to Menu

						//Player Status Menu: need to add equipment, rest of evasion
						if( moveAct == 5)
						{
							statsMenu( player1 );
							statsMenu( player2 );
							statsMenu( player6 );
							statsMenu( player7 );
						}
						if( moveAct == 6)
						{
							displayMap( myArray, turn, row, col, clockTick);
							turnUnderMap( player1, player2, player3, player4, player5, player6, player7,
								player8, player9, player10, nullPlayer, myArray );
							outputMap(myArray, turn, row, col, clockTick, player1, player2, player6, player7 );
						}
				}while( ( moveAct == 4) || ( moveAct == 5) || moveAct == 6 );//loops back if AT or Stat menus chosen

				if (moveAct == 2) //move act choice
				{
					if( actor.charging == true || actor.performing == true )
					{
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " cancels " << actor.ctrName << ".\n";
						actor.charging = false;
						actor.archerCharging = false;
						actor.performing = false;
						actor.ctrCountdownBool = false;
						actor.ctrInput = 0;
						actor.ctrK = 0;
						actor.ctrType = 0;
						actor.ctrCountdown = 0;
						actor.ctrEffect = 0;
						actor.ctrName = "";
					}
					moveActConfirm = turnActFunction( actor, blueItem, redItem, battleSkillObject, chargeObject,
						basicSkillObject, stealObject, myArray, blueThrow, redThrow, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, songObject, danceObject, jumpObject,
						punchArtObject, elementalObject, blueDraw, redDraw, talkSkillObject, yinYangObject,
						whiteObject, blackObject, timeObject, summonObject, blueGolem, redGolem, mathSkillObject,
						mimeObject );
					outputStats(  player1, player2, player6, player7 );
				}
				else if( moveAct == 3) //move wait choice
				{
					waitFunction(actor);
					moveActConfirm = confirmFunction( moveActConfirm );
				}
			}while(moveActConfirm == 2); //ends move act choice loop

			if( actor.jumping == true  ) //special exception for jumping
			{
				actor.ct -= 100;
				if(actor.ct > 60 )
				actor.ct = 60;

				++turn;
				break;
			}
					
			if( moveAct == 2) //end move act turn
			{
				if( actor.dead == false && actor.petrify == false && actor.sleep == false && actor.stop == false )
				{
					waitFunction( actor );
				}
				actor.ct -= 100;
				if(actor.ct > 60 )
				actor.ct = 60;
				regenFunction( actor );
				poisonFunction( actor );

				++turn;
				break;
			}

			else if( moveAct == 3) //end move wait turn
			{
				actor.ct -= 80;
				if(actor.dontAct == true )
					actor.ct -= 20;
				if( actor.charging == true || actor.performing == true )
					actor.ct -=20;

				if(actor.ct > 60 )
					actor.ct = 60;

				regenFunction( actor );
				poisonFunction( actor );

				++turn;
				break;
			}
		}

		else if( topMenu == 2 ) //player selected Act, now can move or wait
		{
			//if the actor died etc during their act turn
			if( actor.dead == true || actor.petrify == true || actor.stop == true || actor.sleep == true )
			{
				actor.ct -= 80;
				if(actor.ct > 60 )
					actor.ct = 60;

				regenFunction( actor );
				poisonFunction( actor );

				++turn;
				break;
			}
				
			if( actor.jumping == true ) //special exception for jumping
			{
				actor.ct -= 100;
				if(actor.ct > 60 )
					actor.ct = 60;

				++turn;
				break;
			}

			if( actor.archerCharging == true )
			{
				actor.ct -= 100;
				if(actor.ct > 60 )
				actor.ct = 60;

				waitFunction( actor );
				++turn;
				break;
			}

			cout << "\n";
			cout << "Enter 1 to continue.\n";
			cin >> ctrPause;

			displayMap( myArray, turn, row, col, clockTick );
			turnUnderMap( player1, player2, player3, player4, player5, player6, player7,
				player8, player9, player10, nullPlayer, myArray);
			outputMap(myArray, turn, row, col, clockTick, player1, player2, player6, player7 );		
			do
			{
				do
				{
					if( actor.dontMove == true )
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Move!\n";
					if( actor.charm == true )
					{
						cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is CHARMED!";
						if( actor.teamName == "Blue" )
							cout << " RED Player gets to control the unit!\n";
						else cout << " BLUE Player gets to control the unit!\n";
					}

					while( (cout << "\n" 
						<< "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
						<<" '" << actor.mapSymbol <<"' ---\n"
						<< "1.) MOVE         " << "     4.) Show Active Turn Menu\n"
						<< "2.) ALREADY ACTED" << "     5.) Show Player Stats\n"
						<< "3.) WAIT         " << "     6.) Show Map\n"
						) &&
						(!(cin >> actMove ) || actMove  < 1 || actMove  > 6 || actMove == 2 
						|| ( actMove == 1 && actor.dontMove == true )
						))
					{
						cout << "That is not a valid menu selection. Enter a valid number.\n";
						if( actor.dontMove == true )
							cout << "\n"  << actor.teamName << " " << actor.playerClassName << " " << actor.playerName << " is hit by Don't Move!\n";

						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
					}				
					//Active Turn Menu: Shows who gets to go on the next 10 turns
						if( actMove == 4)
						{
							activeTurn( player1, player2, player3, player4, player5, player6,
								player7, player8, player9, player10, myArray, nullPlayer );
						} //end AT loop and returns to Menu

						//Player Status Menu: need to add equipment, rest of evasion
						if( actMove == 5)
						{
							statsMenu( player1 );
							statsMenu( player2 );
							statsMenu( player6 );
							statsMenu( player7 );
						}
						if( actMove == 6)
						{
							displayMap( myArray, turn, row, col, clockTick);
							turnUnderMap( player1, player2, player3, player4, player5, player6, player7, player8,
								player9, player10, nullPlayer, myArray );
							outputMap(myArray, turn, row, col, clockTick, player1, player2, player6, player7 );
						}
				}while( ( actMove == 4) || ( actMove == 5 ) || actMove == 6 );//loops back if AT or Stat menus chosen

				if ( actMove == 1 ) //act Move choice
				{
					actMoveConfirm = turnMoveFunction( actor, myArray, player1, player2, player3, player4,
					player5, player6, player7, player9, player9, player10  );
				}
				else if( actMove == 3) //act wait choice
				{
					waitFunction(actor);
					actMoveConfirm = confirmFunction( actMoveConfirm );
				}
			}while(actMoveConfirm == 2); //ends act move choice loop
					
			if( actMove == 1) //end act move turn
			{
				waitFunction( actor );
				actor.ct -= 100;
				if(actor.ct > 60 )
				actor.ct = 60;
				regenFunction( actor );
				poisonFunction( actor );

				++turn;
				break;
			}

			else if( actMove == 3) //end act wait turn
			{
				actor.ct -= 80;
				if( actor.dontMove == true )
					actor.ct -= 20; // CT penalty for being hit with don't move

				if(actor.ct > 60 )
				actor.ct = 60;
				regenFunction( actor );
				poisonFunction( actor );

				++turn;
				break;
			}
		}
		else if( topMenu == 3 ) //player selected top menu then wait, breaks out of turn loop
		{
			actor.ct -= 60;
			if( actor.dontAct == true )
				actor.ct -= 20;
			if( actor.dontMove == true )
				actor.ct -= 20;
			if( actor.charging == true || actor.performing == true )
				actor.ct -=20;

			if( actor.ct > 60 )
				actor.ct = 60;
			regenFunction( actor );
			poisonFunction( actor );

			++turn;
			break; //player selected wait, breaks out of turn loop
		}
	} //end while loop
} //end turnFunction



//ct function, can add more players as capabilities are added
void ctFunction( Player &actor, char myArray[][11], int &turn, int row, int col, int clockTick,
	Item &blueItem, Item &redItem, BattleSkill &battleSkillObject, BasicSkill &basicSkillObject, Charge &chargeObject,
	Steal &stealObject, Player &player1, Player &player2, Player &player3, Player &player4,
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10,
	Player &nullPlayer, Throw &blueThrow, Throw &redThrow, Song &songObject, Dance &danceObject,
	Jump &jumpObject, PunchArt &punchArtObject, Elemental &elementalObject,
	DrawOut &blueDraw, DrawOut &redDraw, TalkSkill &talkSkillObject, YinYang &yinYangObject,
	White &whiteObject, Black &blackObject, Time &timeObject, Summon &summonObject,
	Golem &blueGolem, Golem &redGolem, MathSkill &mathSkillObject, MimeClass &mimeObject )
{
	int deadRoll = 0;
	int whoTurn = 0;

	whoTurn = turnDecider( player1, player2, player3, player4, player5, player6, player7,
		player8, player9, player10 );

	if( whoTurn == player1.turnOrder )
	{
		deathSentenceFunction( player1 );
		if( player1.dead == true )
		{
			deadFunction( player1, myArray );
		}
		else if( player1.dead == false )
		{
			turnFunction( player1, myArray, turn, row, col, clockTick, blueItem, redItem,
				battleSkillObject, chargeObject, basicSkillObject, stealObject, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, blueThrow, redThrow, songObject, danceObject, jumpObject,
				punchArtObject, elementalObject, blueDraw, redDraw, talkSkillObject, yinYangObject,
				whiteObject, blackObject, timeObject, summonObject, blueGolem, redGolem, mathSkillObject,
				mimeObject );
		}
	}

	if( whoTurn == player6.turnOrder )
	{
		deathSentenceFunction( player6 );
		if( player6.dead == true )
		{
			deadFunction( player6, myArray );
		}
		if( player6.dead == false )
		{
			turnFunction( player6, myArray, turn, row, col, clockTick, blueItem, redItem,
				battleSkillObject, chargeObject, basicSkillObject, stealObject, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, blueThrow, redThrow, songObject, danceObject, jumpObject,
				punchArtObject, elementalObject, blueDraw, redDraw, talkSkillObject, yinYangObject,
				whiteObject, blackObject, timeObject, summonObject, blueGolem, redGolem, mathSkillObject,
				mimeObject );
		}
	}

	if( whoTurn == player7.turnOrder )
	{
		deathSentenceFunction( player7 );
		if( player7.dead == true )
		{
			deadFunction( player7, myArray );
		}
		if( player7.dead == false )
		{
			turnFunction( player7, myArray, turn, row, col, clockTick, blueItem, redItem,
				battleSkillObject, chargeObject, basicSkillObject, stealObject, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, blueThrow, redThrow, songObject, danceObject, jumpObject,
				punchArtObject, elementalObject, blueDraw, redDraw, talkSkillObject, yinYangObject,
				whiteObject, blackObject, timeObject, summonObject, blueGolem, redGolem, mathSkillObject,
				mimeObject );
		}
	}

	if( whoTurn == player2.turnOrder )
	{
		deathSentenceFunction( player2 );
		if( player2.dead == true )
		{
			deadFunction( player2, myArray );
		}
		if( player2.dead == false )
		{
			turnFunction( player2, myArray, turn, row, col, clockTick, blueItem, redItem,
				battleSkillObject, chargeObject, basicSkillObject, stealObject, player1, player2, player3,
				player4, player5, player6, player7, player8, player9, player10,
				nullPlayer, blueThrow, redThrow, songObject, danceObject, jumpObject,
				punchArtObject, elementalObject, blueDraw, redDraw, talkSkillObject, yinYangObject,
				whiteObject, blackObject, timeObject, summonObject, blueGolem, redGolem, mathSkillObject,
				mimeObject );
		}	
	}
}
						