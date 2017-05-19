
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/weighted-uniform-string

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

////////////////////////////////////////////////////////////////////////////////

using namespace std;

////////////////////////////////////////////////////////////////////////////////

int main() {
	std::string	str;
	cin >> str;

	std::vector< int >	strNumbers;
	int					sequence	= 1;
	for( int i = 0; i < str.size(); ++i )
	{
		if( str[ i ] == str[ i - 1] )
			sequence++;
		else
			sequence	= 1;

		strNumbers.push_back( sequence * ( str[ i ] - 'a' + 1 ) );
	}

	int	testCases;
	cin >> testCases;
	while( testCases-- )
	{
		int	testNumber;
		cin >> testNumber;
		if( std::find( strNumbers.begin(), strNumbers.end(), testNumber ) != strNumbers.end() )
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
////////////////////////////////////////////////////////////////////////////////
