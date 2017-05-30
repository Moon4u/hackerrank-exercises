
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/morgan-and-a-string

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////

using namespace std;

using num	= unsigned long long;

////////////////////////////////////////////////////////////////////////////////

num	getXOR( num index );
num	getXORProg( num index );

////////////////////////////////////////////////////////////////////////////////

int	main()
{
	num	testCases;
	cin >> testCases;

	while( testCases-- )
	{
		num	L;
		num	R;

		cin >> L;
		cin >> R;

		num	answer	= getXOR( R ) ^ getXOR( L - 1 );

		cout << answer << endl;
	}

	return	0;
}
////////////////////////////////////////////////////////////////////////////////

/**
 * This method returns the value for the index in the XOR progression.
 *
 * \note see explanation at top comment.
 *
 * @param index	The index for the progression.
 * @return		The value for that index.
 */
num	getXOR( num index )
{
	switch( index % 4 )
	{
		case	0: return	index;
		case	1: return	1;
		case	2: return	index+1;
		case	3: return	0;
	}

	return	0;
}
////////////////////////////////////////////////////////////////////////////////

/**
 * This method returns the sum of all elements from the begining of the
 * progression to the given index.
 *
 * @param index	The final index.
 * @return		The sum of all values up till the index.
 */
num	getXORProg( num index )
{
	switch( index % 8 )
	{
		case	0:
		case	1:
			return	index;
		case	2:
		case	3:
			return	2;
		case	4:
		case	5:
			return	index + 2;
		case	6:
		case	7:
			return	0;
	}

	return	0;
}
////////////////////////////////////////////////////////////////////////////////
