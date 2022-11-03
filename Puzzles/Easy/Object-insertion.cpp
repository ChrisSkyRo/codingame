// Solution to the puzzle Object insertion
// https://www.codingame.com/training/easy/object-insertion

#include <iostream>
using namespace std;

char object[10][10], grid[10][10];
int nO, mO, nG, mG, nr;

bool Check( int i, int j)
{
	int _i, _j;
	if ( i + nO > nG )
		return false;
	if ( j + mO > mG )
		return false;
	for ( _i = i; _i < i + nO; _i++ )
		for ( _j = j; _j < j + mO; _j++ )
			if ( grid[_i][_j] == '#' && object[_i - i][_j - j] == '*' )
				return false;
	return true;
}

void Insert( int i, int j )
{
	int _i, _j;
	for ( _i = i; _i < i + nO && _i < nG; _i++ )
		for ( _j = j; _j < j + mO && _j < mG; _j++ )
			if ( object[_i - i][_j - j] == '*' )
				grid[_i][_j] = '*';
}

int main( )
{
	int i, j;
	cin >> nO >> mO;
	for ( i = 0; i < nO; i++ )
		for ( j = 0; j < mO; j++ )
			cin >> object[i][j];
	cin >> nG >> mG;
	for ( i = 0; i < nG; i++ )
		for ( j = 0; j < mG; j++ )
			cin >> grid[i][j];
	for ( i = 0; i < nG; i++ )
		for ( j = 0; j < mG; j++ )
		{
			if ( Check( i, j ) )
			{
				nr++;
				if ( nr == 1 )
					Insert( i, j );
			}
		}
	cout << nr;
	if ( nr == 1 )
	{
		cout << '\n';
		for ( i = 0; i < nG; i++ )
		{
			for ( j = 0; j < mG; j++ )
				cout << grid[i][j];
			cout << '\n';
		}
	}
	return 0;
}

