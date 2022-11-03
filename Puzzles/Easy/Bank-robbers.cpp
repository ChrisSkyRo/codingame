// Solution to the puzzle Bank robbers
// https://www.codingame.com/training/easy/bank-robbers

#include <iostream>
using namespace std;

int main( )
{
	int r, v, c, n, t[20], i, T = 0, iV, w[5], maxi = 0, mini;
	cin >> r >> v;
	for ( i = 0; i < v; i++ )
	{
		if ( i < r )
			w[i] = i;
		cin >> c >> n;
		t[i] = 1;
		c -= n;
		while ( n )
		{
			t[i] *= 10;
			n--;
		}
		while ( c )
		{
			t[i] *= 5;
			c--;
		}
	}
	iV = r;
	while ( iV < v )
	{
		mini = 999999999;
		for ( i = 0; i < r; i++ )
			if ( t[w[i]] < mini )
				mini = t[w[i]];
		for ( i = 0; i < r; i++ )
		{
			t[w[i]] -= mini;
			if ( iV < v && !t[w[i]] )
			{
				w[i] = iV;
				iV++;
			}
		}
		T += mini;
	}
	for ( i = 0; i < r; i++ )
		if ( t[w[i]] > maxi )
			maxi = t[w[i]];
	T += maxi;
	cout << T;
	return 0;
}

