
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/hackerland-radio-transmitters

#include <iostream>

using namespace std;

const int	MAX_NUMBER_FOR_HOUSE	= 100001;

int	main()
{
	/**
	 * Input Format:
	 * The first line contains two space-separated integers describing the
	 * respective values of (the number of houses in Hackerland) and (the range
	 * of each transmitter).
	 * The second line contains space-separated integers describing the
	 * respective locations of each house (i.e., ).
	 */
	int	numberOfHouses;
	int	rangeOfTransmitters;

	cin >> numberOfHouses;
	cin >> rangeOfTransmitters;

	int	maxHouse							= 0;
	int	minHouse							= MAX_NUMBER_FOR_HOUSE;
	int	housesIndexes[ MAX_NUMBER_FOR_HOUSE ]	= { 0 };
	for( int i = 1; i < numberOfHouses + 1; ++i )
	{
		int	newHouse;
		cin >> newHouse;
		housesIndexes[ newHouse ]++;
		if( newHouse > maxHouse )
			maxHouse	= newHouse;
		if( newHouse < minHouse )
			minHouse	= newHouse;
	}

	if( numberOfHouses == 1 )
	{
		cout << 1;
		return	0;
	}

	int	numberOfTransmitters	= 0;
	int	numberOfHousesCovered	= 0;
	for( int i = minHouse; i <= maxHouse; ++i )
	{
		if( numberOfHousesCovered == 0 && housesIndexes[ i ] == 0 )
			continue;

		if( numberOfHousesCovered > 0 || housesIndexes[ i ] > 0 )
		{
			numberOfHousesCovered++;
			if( numberOfHousesCovered > rangeOfTransmitters )
			{
				bool	foundAHouse	= false;
				for( int j = i; j > i - rangeOfTransmitters - 1; --j )
				{
					if( housesIndexes[ j ] )
					{
						i	= j + rangeOfTransmitters;
						numberOfHousesCovered	= 0;
						numberOfTransmitters++;
						foundAHouse	= true;
					}
				}

				if( foundAHouse )
					continue;

				numberOfHousesCovered	= 0;
				continue;
			}
		}
	}

	if( numberOfHousesCovered > 0 )
	{
		int	maxHouseLookUp	= maxHouse - rangeOfTransmitters + 1;
		for( int i = maxHouse; i > maxHouseLookUp; --i )
			if( housesIndexes[ i ] )
			{
				numberOfTransmitters++;
				break;
			}
	}

	cout << numberOfTransmitters;

	return 0;
}
