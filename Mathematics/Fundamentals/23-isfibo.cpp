
#include <assert.h>
#include <iostream>

////////////////////////////////////////////////////////////////////////////////

const int			MAX_FIBO		= 50;

const char* const	IS_FIBO			= "IsFibo";
const char* const	IS_NOT_FIBO		= "IsNotFibo";

////////////////////////////////////////////////////////////////////////////////

using num	= unsigned long long;

////////////////////////////////////////////////////////////////////////////////

template< int stage >
struct	Fib
{
	static const num	value	= Fib< stage - 1 >::value + Fib< stage - 2 >::value;

	static inline num	getValue( int i )
	{
		if( i == stage )
			return	value;

		return	Fib< stage - 1 >::getValue( i );
	}
};
////////////////////////////////////////////////////////////////////////////////

template<>
struct	Fib< 0 >
{
	static const num	value	= 1;

	static inline num	getValue( int i )
	{
		assert( i == 0 );

		return	1;
	}
};
////////////////////////////////////////////////////////////////////////////////

template<>
struct	Fib< 1 >
{
	static const num	value	= 1;
	static inline num	getValue( int i )
	{
		if( i == 1 )
			return	value;

		return	Fib< 0 >::getValue( i );
	}
};
////////////////////////////////////////////////////////////////////////////////

int	main()
{
	int	T;
	std::cin >> T;
	while( T-- )
	{
		num	inputNum;
		std::cin >> inputNum;
		for( int i = 0; i < MAX_FIBO; i++ )
		{
			if( Fib< MAX_FIBO >::getValue( i ) == inputNum )
			{
				std::cout << IS_FIBO << std::endl;
				goto	continueWhile;
			}
		}

		std::cout << IS_NOT_FIBO << std::endl;

		continueWhile:	continue;
	}
}
////////////////////////////////////////////////////////////////////////////////
