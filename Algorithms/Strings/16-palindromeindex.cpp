
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/palindrome-index

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////

int	main()
{
	int	numberOfTests;
	cin >> numberOfTests;
	while( numberOfTests-- )
	{
		std::string	inputString;
		cin >> inputString;

		int	leftSide	= 0;
		int	rightSide	= inputString.size() - 1;
		while( leftSide < rightSide )
		{
			if( inputString[ leftSide ] == inputString[ rightSide ] )
			{
				leftSide++;
				rightSide--;
				continue;
			}

			goto	differenceFound;
		}

		cout << "-1" << endl;
		continue;

		differenceFound:

		int	leftSideIndex	= leftSide;
		int	rightSideIndex	= rightSide;

		leftSide++;
		while( leftSide < rightSide )
		{
			if( inputString[ leftSide ] == inputString[ rightSide ] )
			{
				leftSide++;
				rightSide--;

				continue;
			}

			leftSideIndex	= -1;
			break;
		}

		cout << ( ( leftSideIndex == -1 ) ? rightSideIndex : leftSideIndex ) << endl;
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
