// Solution to the puzzle Detective Pikaptcha EP1
// https://www.codingame.com/training/easy/detective-pikaptcha-ep1

#include <iostream>
using namespace std;

int passages(char a[][101], int i, int j, int n, int m)
{
	int nr = 0;
	if ( i > 0 && a[i - 1][j] != '#' )
		nr++;
	if ( i < n - 1 && a[i + 1][j] != '#' )
		nr++;
	if ( j > 0 && a[i][j - 1] != '#' )
		nr++;
	if ( j < m - 1 && a[i][j + 1] != '#' )
		nr++;
	return nr;
}

int main()
{
	char a[101][101];
	int n, m;
	cin >> m >> n;
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < m; j++ )
			cin >> a[i][j];
	for ( int i = 0; i < n; i++ )
	{
		for ( int j = 0; j < m; j++ )
			if ( a[i][j] == '#' )
				cout << '#';
			else cout << passages( a, i, j, n, m);
		cout << '\n';
	}
	return 0;
}

