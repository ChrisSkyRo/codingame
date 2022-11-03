// Solution to the puzzle Treasure hunt
// https://www.codingame.com/training/easy/treasure-hunt

#include <iostream>
using namespace std;

struct pos
{
	int i, j;

} dir[4] = { {-1, 0}, {0, +1}, {+1, 0}, {0, -1} };

void bkt( pos currPos, int h, int w, int map[100][100], int sum, int &maxSum )
{
	int i;
	for ( i = 0; i < 4; i++ )
	{
		pos nextPos;
		nextPos.i = currPos.i + dir[i].i;
		nextPos.j = currPos.j + dir[i].j;
		if ( nextPos.i >= 0 && nextPos.i < h && nextPos.j >= 0 && nextPos.j < w && map[nextPos.i][nextPos.j] > -1 )
		{
			int cmap = map[nextPos.i][nextPos.j];
			sum += cmap;
			map[nextPos.i][nextPos.j] = -1;
			if ( sum > maxSum )
				maxSum = sum;
			bkt( nextPos, h, w, map, sum, maxSum );
			sum -= cmap;
			map[nextPos.i][nextPos.j] = cmap;
		}
	}
}

int main()
{
	int h, w, i, j, sum = 0;
	pos currPos;
	char map[100][100];
	int translatedMap[100][100];
	cin >> h >> w; cin.ignore();
	for ( i = 0; i < h; i++ )
		cin.getline( map[i], sizeof( map[i] ) );
	for ( i = 0; i < h; i++ )
		for ( j = 0; j < w; j++ )
		{
			if ( map[i][j] == '#' )
				translatedMap[i][j] = -1;
			else if ( map[i][j] >= '1' && map[i][j] <= '9' )
				translatedMap[i][j] = map[i][j] - '0';
			else if ( map[i][j] == 'X' )
			{
                translatedMap[i][j] = -1;
				currPos.i = i;
				currPos.j = j;
			}
			else translatedMap[i][j] = 0;
		}
	bkt( currPos, h, w, translatedMap, 0, sum );
	cout << sum;
	return 0;
}

