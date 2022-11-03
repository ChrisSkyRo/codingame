// Solution to the puzzle Rock Paper Scissors Lizard Spock
// https://www.codingame.com/training/easy/rock-paper-scissors-lizard-spock

#include <iostream>
using namespace std;

struct bracket
{
	char sign;
	int index;
}B[1024][1024];

void Opponents(int round, int pos)
{
	if ( round )
	{
		if ( B[round - 1][pos * 2].index == B[round][pos].index )
		{
			Opponents( round - 1, pos * 2 );
			cout << B[round - 1][pos * 2 + 1].index << " ";
		}
		else
		{
			Opponents( round - 1, pos * 2 + 1 );
			cout << B[round - 1][pos * 2].index << " ";
		}
	}
}

int main()
{
	int n, l, round = 0;
	cin >> n;
	for ( int i = 0; i < n; i++ )
		cin >> B[0][i].index >> B[0][i].sign;
	while ( n > 1 )
	{
		l = 0;
		round++;
		for ( int i = 0; i < n; i += 2 )
		{
			char a = B[round - 1][i].sign, b = B[round - 1][i + 1].sign;
			if ( a == b )
			{
				B[round][l].sign = B[round - 1][i].sign;
				B[round][l].index = min( B[round - 1][i].index, B[round - 1][i + 1].index );
			}
			else if ( a == 'R' )
			{
				if ( b == 'P' )
					B[round][l] = B[round - 1][i + 1];
				else if(b == 'C')
					B[round][l] = B[round - 1][i];
				else if ( b == 'L' )
					B[round][l] = B[round - 1][i];
				else B[round][l] = B[round - 1][i + 1];
			}
			else if ( a == 'P' )
			{
				if ( b == 'R' )
					B[round][l] = B[round - 1][i];
				else if ( b == 'C' )
					B[round][l] = B[round - 1][i + 1];
				else if ( b == 'L' )
					B[round][l] = B[round - 1][i + 1];
				else B[round][l] = B[round - 1][i];
			}
			else if ( a == 'C' )
			{
				if ( b == 'R' )
					B[round][l] = B[round - 1][i + 1];
				else if ( b == 'P' )
					B[round][l] = B[round - 1][i];
				else if ( b == 'L' )
					B[round][l] = B[round - 1][i];
				else B[round][l] = B[round - 1][i + 1];
			}
			else if ( a == 'L' )
			{
				if ( b == 'R' )
					B[round][l] = B[round - 1][i + 1];
				else if ( b == 'P' )
					B[round][l] = B[round - 1][i];
				else if ( b == 'C' )
					B[round][l] = B[round - 1][i + 1];
				else B[round][l] = B[round - 1][i];
			}
			else
			{
				if ( b == 'R' )
					B[round][l] = B[round - 1][i];
				else if ( b == 'P' )
					B[round][l] = B[round - 1][i + 1];
				else if ( b == 'C' )
					B[round][l] = B[round - 1][i];
				else B[round][l] = B[round - 1][i + 1];
			}
			l++;
		}
		n /= 2;
	}
	cout << B[round][0].index << '\n';
	if ( B[round - 1][0].index == B[round][0].index )
	{
		Opponents( round - 1, 0 );
		cout << B[round - 1][1].index;
	}
	else
	{
		Opponents( round - 1, 1 );
		cout << B[round - 1][0].index;
	}
	return 0;
}

