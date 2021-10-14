

void srPhase( Player &actor, Player &player1, Player &player2, Player &player3, Player &player4, 
	Player &player5, Player &player6, Player &player7, Player &player8, Player &player9, Player &player10, 
	Player &nullPlayer, char myArray[][11], Item &blueItem, Item &redItem, YinYang &yinYangObject, White &whiteObject,
	Black &blackObject, Time &timeObject, Summon &summonObject, Golem &blueGolem, Golem &redGolem, MimeClass &mimeObject,
	Jump &jumpObject )
{
	string ctrPause = "";

	if( 
		( player1.ct < 100 || ( player1.ct >= 100 && ( player1.petrify == true || player1.stop == true || player1.sleep == true ) ) )
		&& ( player2.ct < 100 || ( player2.ct >= 100 && ( player2.petrify == true || player2.stop == true || player2.sleep == true ) ) )
		&& ( player3.ct < 100 || ( player3.ct >= 100 && ( player3.petrify == true || player3.stop == true || player3.sleep == true ) ) )
		&& ( player4.ct < 100 || ( player4.ct >= 100 && ( player4.petrify == true || player4.stop == true || player4.sleep == true ) ) )
		&& ( player5.ct < 100 || ( player5.ct >= 100 && ( player5.petrify == true || player5.stop == true || player5.sleep == true ) ) )
		&& ( player6.ct < 100 || ( player6.ct >= 100 && ( player6.petrify == true || player6.stop == true || player6.sleep == true ) ) )
		&& ( player7.ct < 100 || ( player7.ct >= 100 && ( player7.petrify == true || player7.stop == true || player7.sleep == true ) ) )
		&& ( player8.ct < 100 || ( player8.ct >= 100 && ( player8.petrify == true || player8.stop == true || player8.sleep == true ) ) )
		&& ( player9.ct < 100 || ( player9.ct >= 100 && ( player9.petrify == true || player9.stop == true || player9.sleep == true ) ) )
		&& ( player10.ct < 100 || ( player10.ct >= 100 && ( player10.petrify == true || player10.stop == true || player10.sleep == true ) ) )
	)
	{
		if( actor.ctrCountdownBool == true && actor.stop == false )
		{
			--actor.ctrCountdown;
			if( actor.ctrCountdown == 0 )
			{
				cout << "\n" << "   --- " << actor.teamName << " " << actor.playerClassName << " " << actor.playerName
					<< "'s " << actor.ctrName << " is cast! ---\n";

				if( actor.ctrType == 1 )
				{
					chargeResolve( actor, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, nullPlayer, myArray, blueItem, redItem,
						blueGolem, redGolem, mimeObject );

					mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, false, false, false, false, false, true );

					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.charging = false;
					actor.archerCharging = false;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					actor.ctrK = 0;

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 2 )
				{
					songResolve( actor, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10 );
					//using the turn order
					mimeSongFunction( mimeObject, player1, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player6, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player7, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player2, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player3, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player8, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player9, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player4, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player5, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );
					mimeSongFunction( mimeObject, player10, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, true );

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 5 )
				{
					danceResolve( actor, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, blueItem, redItem );

					mimeDanceFunction( mimeObject, player1, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player6, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player7, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player2, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player3, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player8, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player9, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player4, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player5, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );
					mimeDanceFunction( mimeObject, player10, actor, player1, player2, player3, player4,
						player5, player6, player7, player8, player9, player10, blueItem, redItem, true );

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 8 )
				{
				
					jumpResolve( actor, player1, player2, player3, player4, player5, player6,
						player7, player8, player9, player10, blueItem, redItem, myArray, nullPlayer,
						blueGolem, redGolem, jumpObject );

					myArray[actor.currentRow][actor.currentCol] = actor.mapSymbol; //returns person to the map
					actor.jumping = false;

					mimeJumpFunction( mimeObject, jumpObject, player1, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player6, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player7, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player2, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player3, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player8, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player9, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player4, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player5, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );
					mimeJumpFunction( mimeObject, jumpObject, player10, actor, player1, player2, player3,
						player4, player5, player6, player7, player8, player9, player10, nullPlayer, blueItem,
						redItem, blueGolem, redGolem, myArray, true );

					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 13 )
				{
					yinYangResolve( yinYangObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player9, player9, player10, blueItem, redItem, myArray,
						nullPlayer, mimeObject );

					mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
						redGolem, myArray, false, false, false, false, false, false, false, true );


					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.charging = false;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					actor.ctrFollow = 2;
					actor.ctrFollowNumber = 0;

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 14 )
				{
					whiteResolve( whiteObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player9, player9, player10, blueItem, redItem, myArray,
						nullPlayer, mimeObject );

					mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
						redGolem, myArray, false, false, false, false, false, false, false, true );


					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.charging = false;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					actor.ctrFollow = 2;
					actor.ctrFollowNumber = 0;

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 17 )
				{
					summonResolve( summonObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player9, player9, player10, blueItem, redItem, myArray, nullPlayer, blueGolem,
						redGolem, mimeObject );

					mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
						redGolem, myArray, false, false, false, false, false, false, false, true );


					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.charging = false;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					actor.ctrFollow = 2;
					actor.ctrFollowNumber = 0;

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 19 )
				{
					timeResolve( timeObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player9, player9, player10, blueItem, redItem, myArray,
						nullPlayer, mimeObject );

					mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
						redGolem, myArray, false, false, false, false, false, false, false, true );


					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.charging = false;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					actor.ctrFollow = 2;
					actor.ctrFollowNumber = 0;

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
				else if( actor.ctrType == 20 )
				{
					blackResolve( blackObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player9, player9, player10, blueItem, redItem, myArray,
						nullPlayer, mimeObject );

					mimeOuterCondenser( mimeObject, actor, player1, player2, player3, player4, player5,
						player6, player7, player8, player9, player10, nullPlayer, blueItem, redItem, blueGolem,
						redGolem, myArray, false, false, false, false, false, false, false, true );


					actor.ctrCountdownBool = false;
					actor.ctrName = "";
					actor.ctrType = 0;
					actor.charging = false;
					actor.ctrRow = 0;
					actor.ctrCol = 0;
					actor.ctrFollow = 2;
					actor.ctrFollowNumber = 0;

					cout << "\n";
					cout << "Enter 1 to continue.\n";
					cin >> ctrPause;
				}
			
			}
		}
	}//end check for active turn loop
}



void statusCheckPhase( Player &unit, Player player1, Player player2, Player player3, Player player4,
	Player player5, Player player6, Player player7, Player player8, Player player9, Player player10 )
{
	string ctrPause = "";
	int messageCheck = 0;

	if( 
		( player1.ct < 100 || ( player1.ct >= 100 && ( player1.petrify == true || player1.stop == true || player1.sleep == true ) ) )
		&& ( player2.ct < 100 || ( player2.ct >= 100 && ( player2.petrify == true || player2.stop == true || player2.sleep == true ) ) )
		&& ( player3.ct < 100 || ( player3.ct >= 100 && ( player3.petrify == true || player3.stop == true || player3.sleep == true ) ) )
		&& ( player4.ct < 100 || ( player4.ct >= 100 && ( player4.petrify == true || player4.stop == true || player4.sleep == true ) ) )
		&& ( player5.ct < 100 || ( player5.ct >= 100 && ( player5.petrify == true || player5.stop == true || player5.sleep == true ) ) )
		&& ( player6.ct < 100 || ( player6.ct >= 100 && ( player6.petrify == true || player6.stop == true || player6.sleep == true ) ) )
		&& ( player7.ct < 100 || ( player7.ct >= 100 && ( player7.petrify == true || player7.stop == true || player7.sleep == true ) ) )
		&& ( player8.ct < 100 || ( player8.ct >= 100 && ( player8.petrify == true || player8.stop == true || player8.sleep == true ) ) )
		&& ( player9.ct < 100 || ( player9.ct >= 100 && ( player9.petrify == true || player9.stop == true || player9.sleep == true ) ) )
		&& ( player10.ct < 100 || ( player10.ct >= 100 && ( player10.petrify == true || player10.stop == true || player10.sleep == true ) ) )
	)
	{
		if( unit.jumping == false )
		{
			if( unit.charm == true )
			{
				--unit.charmTimer;
				if( unit.charmTimer <= 0 )
				{
					unit.charm = false;
					cout << "Charm fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
					messageCheck = 1;
				}
			}
			if( unit.dontAct == true )
			{
				--unit.dontActTimer;
				if( unit.dontActTimer <= 0 )
				{
					messageCheck = 1;
					unit.dontAct = false;
					cout << "Don't Act fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.dontMove == true )
			{
				--unit.dontMoveTimer;
				if( unit.dontMoveTimer <= 0 )
				{
					messageCheck = 1;
					unit.dontMove = false;
					cout << "Don't Move fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.statusFaith == true )
			{
				--unit.statusFaithTimer;
				if( unit.statusFaithTimer <= 0 )
				{
					messageCheck = 1;
					unit.statusFaith = false;
					cout << "Faith fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.haste == true )
			{
				--unit.hasteTimer;
				if( unit.hasteTimer <= 0 )
				{
					messageCheck = 1;
					unit.haste = false;
					cout << "Haste fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.innocent == true )
			{
				--unit.innocentTimer;
				if( unit.innocentTimer <= 0 )
				{
					messageCheck = 1;
					unit.innocent = false;
					cout << "Innocent fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.poison == true )
			{
				--unit.poisonTimer;
				if( unit.poisonTimer <= 0 )
				{
					messageCheck = 1;
					unit.poison = false;
					cout << "Poison fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.protect == true )
			{
				--unit.protectTimer;
				if( unit.protectTimer <= 0 )
				{
					messageCheck = 1;
					unit.protect = false;
					cout << "Protect fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.regen == true )
			{
				--unit.regenTimer;
				if( unit.regenTimer <= 0 )
				{
					messageCheck = 1;
					unit.regen = false;
					cout << "Regen fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.statusReflect == true )
			{
				--unit.statusReflectTimer;
				if( unit.statusReflectTimer <= 0 )
				{
					messageCheck = 1;
					unit.statusReflect = false;
					cout << "Reflect fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.shell == true )
			{
				--unit.shellTimer;
				if( unit.shellTimer <= 0 )
				{
					messageCheck = 1;
					unit.shell = false;
					cout << "Shell fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.slow == true )
			{
				--unit.slowTimer;
				if( unit.slowTimer <= 0 )
				{
					messageCheck = 1;
					unit.slow = false;
					cout << "Slow fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.sleep == true )
			{
				--unit.sleepTimer;
				if( unit.sleepTimer <= 0 )
				{
					messageCheck = 1;
					unit.sleep = false;
					cout << "Sleep fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( unit.stop == true )
			{
				--unit.stopTimer;
				if( unit.stopTimer <= 0 )
				{
					messageCheck = 1;
					unit.stop = false;
					cout << "Stop fades from "
						<< unit.teamName << " " << unit.playerClassName << " " << unit.playerName << "\n";
				}
			}
			if( messageCheck == 1 )
			{
				cout << "\n";
				cout << "\tEnter 1 to continue.\n";
				cin >> ctrPause;
			}
		}//check to see if unit is jumping
	}//end check to see if someone has fast action turn loop
}





