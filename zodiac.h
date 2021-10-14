/*<< " select Zodiac:\n" << "1.) Capricorn\t2.) Aquarius\n"
		<< "3.) Pisces\t4.) Aries\n"
		<< "5.) Taurus\t6.) Gemini\n"
		<< "7.) Cancer\t8.) Leo\n"
		<< "9.) Virgo\t10.) Libra\n"
		<< "11.) Scorpio\t12.) Sagittarius\n")*/


int zodiac( int xa, Player actor, Player target )
{
	if( target.nullPlayer == true )
		return xa;
	//best zodiac
	else if( 
			( actor.zodiacInt == 1 && target.zodiacInt == 7 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 2 && target.zodiacInt == 8 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 3 && target.zodiacInt == 9 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 4 && target.zodiacInt == 10 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 5 && target.zodiacInt == 11 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 6 && target.zodiacInt == 12 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 7 && target.zodiacInt == 1 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 8 && target.zodiacInt == 2 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 9 && target.zodiacInt == 3 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 10 && target.zodiacInt == 4 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 11 && target.zodiacInt == 5 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 12 && target.zodiacInt == 6 && actor.sex != target.sex )
		)
	{
		cout << "\tBest Zodiac Compatibility!\n";
		xa += xa/2;
		return xa;
	}
	//worst zodiac
	else if( 
		   ( actor.zodiacInt == 1 && target.zodiacInt == 7 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 2 && target.zodiacInt == 8 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 3 && target.zodiacInt == 9 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 4 && target.zodiacInt == 10 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 5 && target.zodiacInt == 11 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 6 && target.zodiacInt == 12 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 7 && target.zodiacInt == 1 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 8 && target.zodiacInt == 2 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 9 && target.zodiacInt == 3 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 10 && target.zodiacInt == 4 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 11 && target.zodiacInt == 5 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 12 && target.zodiacInt == 6 && actor.sex == target.sex )
		)
	{
		cout << "\tWorst Zodiac Compatibility!\n";
		xa -= xa/2;
		return xa;
	}
	//good zodiac
	else if( ( actor.zodiacInt == 1 && ( target.zodiacInt == 5 || target.zodiacInt == 9 ) )
		|| ( actor.zodiacInt == 2 && ( target.zodiacInt == 6 || target.zodiacInt == 10 ) )
		|| ( actor.zodiacInt == 3 && ( target.zodiacInt == 7 || target.zodiacInt == 11 ) )
		|| ( actor.zodiacInt == 4 && ( target.zodiacInt == 8 || target.zodiacInt == 12 ) )
		|| ( actor.zodiacInt == 5 && ( target.zodiacInt == 9 || target.zodiacInt == 1 ) )
		|| ( actor.zodiacInt == 6 && ( target.zodiacInt == 10 || target.zodiacInt == 2 ) )
		|| ( actor.zodiacInt == 7 && ( target.zodiacInt == 11 || target.zodiacInt == 3 ) )
		|| ( actor.zodiacInt == 8 && ( target.zodiacInt == 12 || target.zodiacInt == 4 ) )
		|| ( actor.zodiacInt == 9 && ( target.zodiacInt == 1 || target.zodiacInt == 5 ) )
		|| ( actor.zodiacInt == 10 && ( target.zodiacInt == 2 || target.zodiacInt == 6 ) )
		|| ( actor.zodiacInt == 11 && ( target.zodiacInt == 3 || target.zodiacInt == 7 ) )
		|| ( actor.zodiacInt == 12 && ( target.zodiacInt == 4 || target.zodiacInt == 8 ) )
		)
	{
		cout << "\tGood Zodiac Compatibility!\n";
		xa += xa/4;
		return xa;
	}
	//bad zodiac
	else if( ( actor.zodiacInt == 1 && ( target.zodiacInt == 4 || target.zodiacInt == 10 ) )
		|| ( actor.zodiacInt == 2 && ( target.zodiacInt == 5 || target.zodiacInt == 11 ) )
		|| ( actor.zodiacInt == 3 && ( target.zodiacInt == 6 || target.zodiacInt == 12 ) )
		|| ( actor.zodiacInt == 4 && ( target.zodiacInt == 7 || target.zodiacInt == 1 ) )
		|| ( actor.zodiacInt == 5 && ( target.zodiacInt == 8 || target.zodiacInt == 2 ) )
		|| ( actor.zodiacInt == 6 && ( target.zodiacInt == 9 || target.zodiacInt == 3 ) )
		|| ( actor.zodiacInt == 7 && ( target.zodiacInt == 10 || target.zodiacInt == 4 ) )
		|| ( actor.zodiacInt == 8 && ( target.zodiacInt == 11 || target.zodiacInt == 5 ) )
		|| ( actor.zodiacInt == 9 && ( target.zodiacInt == 12 || target.zodiacInt == 6 ) )
		|| ( actor.zodiacInt == 10 && ( target.zodiacInt == 1 || target.zodiacInt == 7 ) )
		|| ( actor.zodiacInt == 11 && ( target.zodiacInt == 2 || target.zodiacInt == 8 ) )
		|| ( actor.zodiacInt == 12 && ( target.zodiacInt == 3 || target.zodiacInt == 9 ) )
		)
	{
		cout << "\tBad Zodiac Compatibility!\n";
		xa -= xa/4;
		return xa;
	}
	//neutral zodiac
	else return xa;
}

int mod3Zodiac( int xa, int baseHit, Player actor, Player target, int weaponPower = 0 )
{
	if( target.nullPlayer == true )
		return xa;
	//best zodiac
	else if(
			( actor.zodiacInt == 1 && target.zodiacInt == 7 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 2 && target.zodiacInt == 8 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 3 && target.zodiacInt == 9 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 4 && target.zodiacInt == 10 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 5 && target.zodiacInt == 11 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 6 && target.zodiacInt == 12 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 7 && target.zodiacInt == 1 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 8 && target.zodiacInt == 2 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 9 && target.zodiacInt == 3 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 10 && target.zodiacInt == 4 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 11 && target.zodiacInt == 5 && actor.sex != target.sex )
		|| ( actor.zodiacInt == 12 && target.zodiacInt == 6 && actor.sex != target.sex )
		)
	{
		cout << "\tBest Zodiac Compatibility!\n";
		xa = xa + xa/2 + baseHit/2 + weaponPower/2;
		return xa;
	}
	//worst zodiac
	else if( 
		   ( actor.zodiacInt == 1 && target.zodiacInt == 7 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 2 && target.zodiacInt == 8 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 3 && target.zodiacInt == 9 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 4 && target.zodiacInt == 10 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 5 && target.zodiacInt == 11 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 6 && target.zodiacInt == 12 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 7 && target.zodiacInt == 1 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 8 && target.zodiacInt == 2 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 9 && target.zodiacInt == 3 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 10 && target.zodiacInt == 4 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 11 && target.zodiacInt == 5 && actor.sex == target.sex )
		|| ( actor.zodiacInt == 12 && target.zodiacInt == 6 && actor.sex == target.sex )
		)
	{
		cout << "\tWorst Zodiac Compatibility!\n";
		xa = xa - xa/2 - baseHit/2 - weaponPower/2;
		return xa;
	}
	//good zodiac
	else if( 
		   ( actor.zodiacInt == 1 && ( target.zodiacInt == 5 || target.zodiacInt == 9 ) )
		|| ( actor.zodiacInt == 2 && ( target.zodiacInt == 6 || target.zodiacInt == 10 ) )
		|| ( actor.zodiacInt == 3 && ( target.zodiacInt == 7 || target.zodiacInt == 11 ) )
		|| ( actor.zodiacInt == 4 && ( target.zodiacInt == 8 || target.zodiacInt == 12 ) )
		|| ( actor.zodiacInt == 5 && ( target.zodiacInt == 9 || target.zodiacInt == 1 ) )
		|| ( actor.zodiacInt == 6 && ( target.zodiacInt == 10 || target.zodiacInt == 2 ) )
		|| ( actor.zodiacInt == 7 && ( target.zodiacInt == 11 || target.zodiacInt == 3 ) )
		|| ( actor.zodiacInt == 8 && ( target.zodiacInt == 12 || target.zodiacInt == 4 ) )
		|| ( actor.zodiacInt == 9 && ( target.zodiacInt == 1 || target.zodiacInt == 5 ) )
		|| ( actor.zodiacInt == 10 && ( target.zodiacInt == 2 || target.zodiacInt == 6 ) )
		|| ( actor.zodiacInt == 11 && ( target.zodiacInt == 3 || target.zodiacInt == 7 ) )
		|| ( actor.zodiacInt == 12 && ( target.zodiacInt == 4 || target.zodiacInt == 8 ) )
		)
	{
		cout << "\tGood Zodiac Compatibility!\n";
		xa = xa + xa/4 + baseHit/4 + weaponPower/4;
		return xa;
	}
	//bad zodiac
	else if( ( actor.zodiacInt == 1 && ( target.zodiacInt == 4 || target.zodiacInt == 10 ) )
		|| ( actor.zodiacInt == 2 && ( target.zodiacInt == 5 || target.zodiacInt == 11 ) )
		|| ( actor.zodiacInt == 3 && ( target.zodiacInt == 6 || target.zodiacInt == 12 ) )
		|| ( actor.zodiacInt == 4 && ( target.zodiacInt == 7 || target.zodiacInt == 1 ) )
		|| ( actor.zodiacInt == 5 && ( target.zodiacInt == 8 || target.zodiacInt == 2 ) )
		|| ( actor.zodiacInt == 6 && ( target.zodiacInt == 9 || target.zodiacInt == 3 ) )
		|| ( actor.zodiacInt == 7 && ( target.zodiacInt == 10 || target.zodiacInt == 4 ) )
		|| ( actor.zodiacInt == 8 && ( target.zodiacInt == 11 || target.zodiacInt == 5 ) )
		|| ( actor.zodiacInt == 9 && ( target.zodiacInt == 12 || target.zodiacInt == 6 ) )
		|| ( actor.zodiacInt == 10 && ( target.zodiacInt == 1 || target.zodiacInt == 7 ) )
		|| ( actor.zodiacInt == 11 && ( target.zodiacInt == 2 || target.zodiacInt == 8 ) )
		|| ( actor.zodiacInt == 12 && ( target.zodiacInt == 3 || target.zodiacInt == 9 ) )
		)
	{
		cout << "\tBad Zodiac Compatibility!\n";
		xa = xa - xa/4 - baseHit/4 - weaponPower/4;
		return xa;
	}
	//neutral zodiac
	else return xa;
}

