// Solution to the puzzle Lumen
// https://www.codingame.com/training/easy/lumen

#include <iostream>
using namespace std;

int a[25][25], n;
char m[25][25];

void Enlighten( int i, int j, int light )
{
	if ( i >= 0 && i < n && j >= 0 && j < n && light > 0 && a[i][j] < light)
	{
		a[i][j] = light;
		light--;
		Enlighten( i - 1, j, light );
		Enlighten( i + 1, j, light );
		Enlighten( i, j - 1, light );
		Enlighten( i, j + 1, light );
		Enlighten( i + 1, j + 1, light );
		Enlighten( i - 1, j + 1, light );
		Enlighten( i + 1, j - 1, light );
		Enlighten( i - 1, j - 1, light );
	}
}

int main( )
{
	int l, i, j;
	cin >> n >> l; cin.ignore( );
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < n; j++ )
		{
			cin >> m[i][j];
			if ( m[i][j] == 'C' )
				Enlighten( i, j, l );
		}
	l = 0;
	for ( i = 0; i < n; i++ )
		for ( j = 0; j < n; j++ )
			if ( a[i][j] == 0 )
				l++;
	cout << l;
	return 0;
}

