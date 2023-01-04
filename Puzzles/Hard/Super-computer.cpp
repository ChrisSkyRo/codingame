// Solution to the puzzle Super Computer
// https://www.codingame.com/training/hard/super-computer

#include <iostream>
#include <algorithm>
using namespace std;

struct calculation
{
	int start, end;
}C[100000];

bool CalculationSorting( calculation x, calculation y )
{
	return x.end < y.end || ( x.end == y.end && x.start > y.start );
}

int main()
{
	int n;
	cin >> n;
	for ( int i = 0; i < n; i++ )
	{
		int j, d;
		cin >> j >> d;
		C[i].start = j;
		C[i].end = j + d - 1;
	}
	sort( C, C + n, CalculationSorting );
	int nr = 1, last = 0;
	for(int i = 1;i < n;i++)
		if ( C[i].start > C[last].end )
		{
			nr++;
			last = i;
		}
	cout << nr;
	return 0;
}

