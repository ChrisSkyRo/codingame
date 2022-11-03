// Solution to the puzzle A child's play
// https://www.codingame.com/training/easy/a-childs-play

#include <iostream>
using namespace std;

int V[] = { -1, 0, +1, 0 };
int O[] = { 0, +1, 0, -1 };
char M[] = { '^', '>', 'v', '<' };

int main( )
{
	char a[11][21];
	long long n, m, t, i, j, time = 1, ri, rj, si, sj, dir = 0;
	bool ok = false;
	cin >> m >> n >> t; cin.ignore( );
	for ( i = 0; i < n; i++ )
		cin.getline( a[i], sizeof( a[i] ) );
	for(i = 0;i < n && !ok;i++)
		for(j = 0;j < m && !ok;j++)
			if ( a[i][j] == 'O' )
			{
				si = i; ri = i;
				sj = j; rj = j;
				a[i][j] = '.';
				ok = true;
			}
	if ( a[ri - 1][rj] == '.' )
		ri--;
	else if ( a[ri][rj + 1] == '.' )
	{
		rj++;
		dir = 1;
	}
	else if ( a[ri + 1][rj] == '.' )
	{
		ri++;
		dir = 2;
	}
	else
	{
		rj--;
		dir = 3;
	}
	a[si][sj] = M[dir];
	t--;
	while ( t )
	{
		while ( a[ri + V[dir]][rj + O[dir]] == '#' )
			dir = ( dir + 1 ) % 4;
		if ( a[ri][rj] == M[dir] )
		{
			si = ri;
			sj = rj;
			break;
		}
		else a[ri][rj] = M[dir];
		ri += V[dir];
		rj += O[dir];
		t--;
	}
	if ( t )
	{
		if ( a[ri - 1][rj] != '#' )
			ri--;
		else if ( a[ri][rj + 1] != '#' )
		{
			rj++;
			dir = 1;
		}
		else if ( a[ri + 1][rj] != '#' )
		{
			ri++;
			dir = 2;
		}
		else
		{
			rj--;
			dir = 3;
		}
		a[si][sj] = M[dir];
		t--;
		while ( t && ( ri != si || rj != sj ) )
		{
			while ( a[ri + V[dir]][rj + O[dir]] == '#' )
				dir = ( dir + 1 ) % 4;
			a[ri][rj] = M[dir];
			ri += V[dir];
			rj += O[dir];
			t--;
			time++;
		}
		t = t % time;
		while ( t )
		{
			while ( a[ri + V[dir]][rj + O[dir]] == '#' )
				dir = ( dir + 1 ) % 4;
			ri += V[dir];
			rj += O[dir];
			t--;
		}
	}
	cout << rj << " " << ri;
	return 0;
}

