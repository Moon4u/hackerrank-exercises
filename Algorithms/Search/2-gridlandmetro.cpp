
// Hackerranked exercies:
// https://www.hackerrank.com/challenges/gridland-metro

#include <vector>
#include <tuple>
#include <iostream>

using namespace std;

const int	TUPLE_ROW_INDEX				= 0;
const int	TUPLE_COLUMN_START_INDEX	= 1;
const int	TUPLE_COLUMN_END_INDEX		= 2;

using	guint	= unsigned long long;

int	main()
{
	guint	gridWidth;
	guint	gridHeight;
	guint	numberOfTrainTracks;

	cin >> gridWidth;
	cin >> gridHeight;
	cin >> numberOfTrainTracks;

	guint						inputIndex	= 0;
	tuple< guint, guint, guint >	inputs[ numberOfTrainTracks ];
	for( guint i = 0; i < numberOfTrainTracks; ++i )
	{
		guint	gridRow;
		guint	gridColumnStart;
		guint	gridColumnEnd;

		cin >> gridRow;
		cin >> gridColumnStart;
		cin >> gridColumnEnd;

		for( guint j = 0; j < i; ++j )
		{
			if( gridRow == get< TUPLE_ROW_INDEX >( inputs[ j ] ) )
			{
				guint&	jColumnStart	= get< TUPLE_COLUMN_START_INDEX >( inputs[ j ] );
				guint&	jColumnEnd		= get< TUPLE_COLUMN_END_INDEX >( inputs[ j ] );

				bool	columnStartInBetween	=  gridColumnStart >= jColumnStart
												&& gridColumnStart <= jColumnEnd;
				bool	columnEndInBetween		=  gridColumnEnd >= jColumnStart
												&& gridColumnEnd <= jColumnEnd;

				if( columnStartInBetween && columnEndInBetween )
					goto	continueOuterIf;

				if( columnStartInBetween )
					if( gridColumnEnd >= jColumnEnd )
					{
						jColumnEnd	= gridColumnEnd;
						goto	continueOuterIf;;
					}

				if( columnEndInBetween )
					if( gridColumnStart <= jColumnStart )
					{
						jColumnStart	= gridColumnStart;
						goto	continueOuterIf;
					}
			}
		}

		inputs[ inputIndex++ ]	= make_tuple( gridRow, gridColumnStart, gridColumnEnd );

		continueOuterIf: continue;
	}

	guint	takenLamppostPlaces	= 0;
	for( guint i = 0; i < inputIndex; ++i )
	{
		guint	columnStart	= get< TUPLE_COLUMN_START_INDEX >( inputs[ i ] );
		guint	columnEnd	= get< TUPLE_COLUMN_END_INDEX >( inputs[ i ] );

		takenLamppostPlaces	+= ( columnEnd - columnStart ) + 1;
	}

	cout << gridWidth * gridHeight - takenLamppostPlaces;

	return	0;
}
