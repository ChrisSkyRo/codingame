// Solution to the puzzle Egyptian multiplication
// https://www.codingame.com/training/hard/egyptian-multiplication

#include <iostream>
using namespace std;

int main()
{
	int a, b, x, y, z[100], lz = 0;
	cin >> a >> b;
	if ( b > a )
		swap( a, b );
	cout << a << " * " << b << '\n';
	if ( b == 0 )
	{
		cout << "= 0";
		return 0;
	}
	if ( b % 2 )
	{
		x = a;
		z[lz++] = a;
		y = b - 1;
	}
	else
	{
		x = a * 2;
		y = b / 2;
	}
	if ( lz )
	{
		cout << "= " << x << " * " << y;
		for ( int i = 0; i < lz; i++ )
			cout << " + " << z[i];
		cout << '\n';
	}
	else cout << "= " << x << " * " << y << '\n';
	while ( y > 1 )
	{
		if ( y % 2 )
		{
			z[lz++] = x;
			y--;
		}
		else
		{
			y /= 2;
			x *= 2;
		}
		if ( lz )
		{
			cout << "= " << x << " * " << y;
			for ( int i = 0; i < lz; i++ )
				cout << " + " << z[i];
			cout << '\n';
		}
		else cout << "= " << x << " * " << y << '\n';
	}
	if ( lz )
	{
		cout << "= " << x << " * 0";
		for ( int i = 0; i < lz; i++ )
			cout << " + " << z[i];
		cout << " + " << x << '\n';
	}
	else cout << "= " << x << " * 0" << " + " << x << '\n';
	cout << "= " << a * b;
	return 0;
}

