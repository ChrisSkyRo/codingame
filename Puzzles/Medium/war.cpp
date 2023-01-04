// Solution to the puzzle War
// https://www.codingame.com/training/medium/winamax-battle

#include <iostream>
#include <queue>
using namespace std;

queue <char> p1, p2, c1, c2;
bool pat;

void Winner1( )
{
	while ( !c1.empty( ) )
	{
		p1.push( c1.front( ) );
		c1.pop( );
	}
	while ( !c2.empty( ) )
	{
		p1.push( c2.front( ) );
		c2.pop( );
	}
}

void Winner2( )
{
	while ( !c1.empty( ) )
	{
		p2.push( c1.front( ) );
		c1.pop( );
	}
	while ( !c2.empty( ) )
	{
		p2.push( c2.front( ) );
		c2.pop( );
	}
}

void War( )
{
	int i;
	for ( i = 0; i < 3; i++ )
	{
		if ( p1.empty( ) )
		{
			pat = true;
			return;
		}
		c1.push( p1.front( ) );
		p1.pop( );
	}
	for ( i = 0; i < 3; i++ )
	{
		if ( p2.empty( ) )
		{
			pat = true;
			return;
		}
		c2.push( p2.front( ) );
		p2.pop( );
	}
	char a, b;
	int value1, value2;
	//a = c1.back( );
	//b = c2.back( );

	a = p1.front( );
	p1.pop( );
	b = p2.front( );
	p2.pop( );
	c1.push( a );
	c2.push( b );

	if ( a == '1' )
		value1 = 10;
	else if ( a <= '9' )
		value1 = a - '0';
	else if ( a == 'J' )
		value1 = 11;
	else if ( a == 'Q' )
		value1 = 12;
	else if ( a == 'K' )
		value1 = 13;
	else value1 = 14;

	if ( b == '1' )
		value2 = 10;
	else if ( b <= '9' )
		value2 = b - '0';
	else if ( b == 'J' )
		value2 = 11;
	else if ( b == 'Q' )
		value2 = 12;
	else if ( b == 'K' )
		value2 = 13;
	else value2 = 14;

	if ( value1 == value2 )
		War( );
	else if ( value1 > value2 )
		Winner1( );
	else Winner2( );
}

int main( )
{
	
	int n, m, i, rounds = 0, value1, value2;
	char c, a, b;
	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		cin >> c;
		p1.push( c );
		if ( c == '1' )
			cin >> c;
		cin >> c;
	}
	cin >> m;
	for ( i = 0; i < m; i++ )
	{
		cin >> c;
		p2.push( c );
		if ( c == '1' )
			cin >> c;
		cin >> c;
	}
	while ( !p1.empty( ) && !p2.empty( ) && !pat)
	{
		rounds++;
		a = p1.front( );
		p1.pop( );
		b = p2.front( );
		p2.pop( );
		if ( a == '1' )
			value1 = 10;
		else if ( a <= '9' )
			value1 = a - '0';
		else if ( a == 'J' )
			value1 = 11;
		else if ( a == 'Q' )
			value1 = 12;
		else if ( a == 'K' )
			value1 = 13;
		else value1 = 14;

		if ( b == '1' )
			value2 = 10;
		else if ( b <= '9' )
			value2 = b - '0';
		else if ( b == 'J' )
			value2 = 11;
		else if ( b == 'Q' )
			value2 = 12;
		else if ( b == 'K' )
			value2 = 13;
		else value2 = 14;

		c1.push( a );
		c2.push( b );
		if ( value1 == value2 )
		{
			while ( c1.back( ) == c2.back( ) )
			{
				War( );
			}
		}
		else if ( value1 > value2 )
			Winner1( );
		else Winner2( );

	}
	if ( pat )
		cout << "PAT";
	else
	{
		if ( p1.empty( ) )
			cout << 2 << " " << rounds;
		else cout << 1 << " " << rounds;
	}
	return 0;
}
