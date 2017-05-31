
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/sum-vs-xor

#include <iostream>

////////////////////////////////////////////////////////////////////////////////

using num	= long long;

using namespace std;

////////////////////////////////////////////////////////////////////////////////

int	main()
{
	num	testNumber;
	cin >> testNumber;

	num	numberOfZeros	= 0;
	while( testNumber )
	{
		numberOfZeros	+= ( testNumber & 0x1 ) == 0;
		testNumber		>>= 1;
	}

	cout << ( 1L << numberOfZeros );

	return	0;
}
////////////////////////////////////////////////////////////////////////////////
