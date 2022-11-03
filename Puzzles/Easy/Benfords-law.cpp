// Solution to the puzzle Benford's law
// https://www.codingame.com/training/easy/benfords-law

#include <iostream>
using namespace std;

int fr[10];

int main( )
{
	float percentage[] = { 0, 30.1, 17.6, 12.5, 9.7, 7.9, 6.7, 5.8, 5.1, 4.6 }, p;
	int n, i, j;
	string t;
	cin >> n; cin.ignore( );
	for ( j = 0; j < n; j++ )
	{
		getline( cin, t );
		i = 0;
		while ( t[i] < '1' || t[i] > '9' )
			i++;
		fr[t[i] - '0']++;
	}
	for ( i = 1; i <= 9; i++ )
	{
		p = fr[i] * 100.0 / n;
		if ( p < percentage[i] - 10 || p > percentage[i] + 10 )
		{
			cout << "true";
			return 0;
		}
	}
	cout << "false";
	return 0;
}

