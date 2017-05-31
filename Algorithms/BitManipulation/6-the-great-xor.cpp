
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/the-great-xor

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
	for( num i = 0; i < testNumber; i <<= 1 )
		numberOfZeros	+= ( ! ( testNumber & i ) ) * i;

	cout << numberOfZeros;

	return	0;
}
////////////////////////////////////////////////////////////////////////////////
