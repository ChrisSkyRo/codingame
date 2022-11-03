// Solution to the puzzle Create the longest sequence of 1s
// https://www.codingame.com/training/easy/create-the-longest-sequence-of-1s

#include <iostream>
#include <string>
using namespace std;

int count( string s, int pos )
{
	int nr = 1;
	for ( int i = pos - 1; i >= 0 && s[i] == '1'; i-- )
		nr++;
	for ( int i = pos + 1; i < s.length() && s[i] == '1'; i++ )
		nr++;
	return nr;
}

int main()
{
	string s;
	cin >> s;
	int k = s.length(), z[1000], l = 0, maxi = 0;
	for ( int i = 0; i < k; i++ )
		if ( s[i] == '0' )
			z[l++] = i;
	for ( int i = 0; i < l; i++ )
	{
		int x = count( s, z[i] );
		if ( x > maxi )
			maxi = x;
	}
	cout << maxi;
	return 0;
}

