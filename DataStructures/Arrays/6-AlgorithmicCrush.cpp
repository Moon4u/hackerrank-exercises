
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/crush

#include <iostream>

using namespace std;

using llong	= long long;

int	main()
{
	llong	numbersCount;
	llong	numberOfActions;
	cin >> numbersCount;
	cin >> numberOfActions;

	llong*	numbers	= new llong[ numbersCount + 1 ]();
	while( numberOfActions-- )
	{
		llong	rangeStart;
		llong	rangeEnd;
		llong	valueToAdd;

		cin >> rangeStart;
		cin >> rangeEnd;
		cin >> valueToAdd;

		numbers[ rangeStart ]	+= valueToAdd;
		numbers[ rangeEnd + 1 ]	-= valueToAdd;
	}

	llong	maxNumber	= 0;
	llong	sum			= 0;
	for( int i = 1; i <= numbersCount; ++i )
	{
		sum	+= numbers[ i ];
		if( sum > maxNumber )
			maxNumber	= sum;
	}

	cout << maxNumber;
	return	0;
}
