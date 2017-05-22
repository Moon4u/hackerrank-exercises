
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/anagram

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////

using	uint	= unsigned int;

////////////////////////////////////////////////////////////////////////////////

int	main()
{
	int	numberOfTestCases;
	cin >> numberOfTestCases;

	for( int tests = 0; tests < numberOfTestCases; ++tests )
	{
		string	inputString;
		cin >> inputString;

		int	stringSize	= inputString.size();
		if( stringSize % 2 == 1 )
		{
			cout << "-1" << endl;
			continue;
		}

		int		stringHalfSize						= stringSize / 2;
		bool	charactersFound[ stringHalfSize ]	= { false };
		uint	charactersNotFound					= 0;
		for( int i = 0; i < stringHalfSize; ++i )
		{
			for( int j = stringHalfSize; j < stringSize; ++j )
			{
				int	characterFoundIndex	= j - stringHalfSize;
				if( charactersFound[ characterFoundIndex ] )
					continue;

				if( inputString[ i ] == inputString[ j ] )
				{
					charactersFound[ characterFoundIndex ]	= true;
					goto	nextIIteration;
				}
			}

			charactersNotFound++;

			nextIIteration: continue;
		}

		cout << charactersNotFound << endl;
	}

	return	0;
}
////////////////////////////////////////////////////////////////////////////////
