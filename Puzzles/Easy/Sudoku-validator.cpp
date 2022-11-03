// Solution to the puzzle Sudoku Validator
// https://www.codingame.com/training/easy/sudoku-validator

#include <iostream>
using namespace std;

bool verticalCheck(int a[][9], int i, int j)
{
	int _i = i - 1;
	while ( _i >= 0)
	{
		if ( a[_i][j] == a[i][j] )
			return false;
		_i--;
	}
	return true;
}

bool horizontalCheck(int a[][9], int i, int j )
{
	int _j = j - 1;
	while ( _j >= 0)
	{
		if ( a[i][_j] == a[i][j] )
			return false;
		_j--;
	}
	return true;
}

bool subgridCheck( int a[][9], int i, int j )
{
	int gi = i/3, gj = j/3;
	for ( int _i = gi * 3; _i < ( gi + 1 ) * 3; _i++ )
		for ( int _j = gj * 3; _j < ( gj + 1 ) * 3; _j++ )
			if ( _i != i && _j != j && a[i][j] == a[_i][_j] )
				return false;
	return true;
}

int main()
{
	int a[9][9];
	bool ok = true;
	for ( int i = 0; i < 9 && ok; i++ )
		for ( int j = 0; j < 9 && ok; j++ )
		{
			cin >> a[i][j];
			ok = ( horizontalCheck( a, i, j ) && verticalCheck( a, i, j ) );
		}
	for ( int i = 0; i < 9 && ok; i++ )
		for ( int j = 0; j < 9 && ok; j++ )
			ok = subgridCheck( a, i, j );
	if ( ok )
		cout << "true";
	else cout << "false";
	return 0;
}

