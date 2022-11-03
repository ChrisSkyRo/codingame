// Solution to the puzzle Ghost Legs
// https://www.codingame.com/training/easy/ghost-legs

#include <iostream>
using namespace std;

char a[100][100];

char PairedChar(int x, int y, int w, int h)
{
	while ( y < h )
	{
		if ( x > 0 && a[y][x - 1] == '-' )
			x -= 3;
		else if ( x < w && a[y][x + 1] == '-' )
			x += 3;
		y++;
	}
	return a[y-1][x];
}

int main()
{
	int w, h;
	cin >> w >> h; cin.ignore();
	for ( int i = 0; i < h; i++ )
		cin.getline( a[i], sizeof( a[i] ) );
	for(int i = 0;i < w;i++)
		if ( a[0][i] != ' ' )
		{
			cout << a[0][i] << PairedChar( i, 1, w, h ) << '\n';
		}
	return 0;
}

