// Solution to the puzzle 1D Spreadsheet
// https://www.codingame.com/training/easy/1d-spreadsheet

#include <iostream>
#include <string>
#define pos1 a[PositionConversion( arg1 )]
#define pos2 a[PositionConversion( arg2 )]
#define val1 ValueConversion( arg1 )
#define val2 ValueConversion( arg2 )
using namespace std;

struct
{
	string op, a1, a2;
	int cell;
} O[100];

bool cells[100];

int ValueConversion( string x )
{
	int y = 0;
	if ( x[0] == '-' )
	{
		for ( int i = 1; i < x.length( ); i++ )
			y = y * 10 + x[i] - '0';
		return -y;
	}
	else
	{
		for ( int i = 0; i < x.length( ); i++ )
			y = y * 10 + x[i] - '0';
		return y;
	}
}

int PositionConversion( string x )
{
	int y = 0;
	for ( int i = 1; i < x.length( ); i++ )
		y = y * 10 + x[i] - '0';
	return y;
}

int main( )
{
	int n, a[100], i, j, l = 0;
	string operation, arg1, arg2;
	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		cin >> operation >> arg1 >> arg2;
		if ( arg1[0] == '$' || arg2[0] == '$' )
		{
			O[l].op = operation;
			O[l].a1 = arg1;
			O[l].a2 = arg2;
			O[l].cell = i;
			l++;
		}
		else
		{
			cells[i] = true;
			if ( operation == "VALUE" )
			{
				if ( arg1[0] == '$' )
					a[i] = pos1;
				else a[i] = val1;
			}
			else if ( operation == "ADD" )
			{
				int left, right;
				if ( arg1[0] == '$' )
					left = pos1;
				else left = val1;
				if ( arg2[0] == '$' )
					right = pos2;
				else right = val2;
				a[i] = left + right;
			}
			else if ( operation == "SUB" )
			{
				int left, right;
				if ( arg1[0] == '$' )
					left = pos1;
				else left = val1;
				if ( arg2[0] == '$' )
					right = pos2;
				else right = val2;
				a[i] = left - right;
			}
			else if ( operation == "MULT" )
			{
				int left, right;
				if ( arg1[0] == '$' )
					left = pos1;
				else left = val1;
				if ( arg2[0] == '$' )
					right = pos2;
				else right = val2;
				a[i] = left * right;
			}
		}
	}
	bool ok = true;
	if ( l )
	{
		while ( ok )
		{
			ok = false;
			for ( j = 0; j < l; j++ )
			{
				if ( cells[O[j].cell] == false )
				{
					ok = true;
					operation = O[j].op;
					arg1 = O[j].a1;
					arg2 = O[j].a2;
					i = O[j].cell;
					if ( arg1[0] == '$' && cells[PositionConversion( arg1 )] == false )
						continue;
					if ( arg2[0] == '$' && cells[PositionConversion( arg2 )] == false )
						continue;
					cells[i] = true;
					if ( operation == "VALUE" )
					{
						if ( arg1[0] == '$' )
							a[i] = pos1;
						else a[i] = val1;
						O[j].cell = -1;
					}
					else if ( operation == "ADD" )
					{
						int left, right;
						if ( arg1[0] == '$' )
							left = pos1;
						else left = val1;
						if ( arg2[0] == '$' )
							right = pos2;
						else right = val2;
						a[i] = left + right;
						O[j].cell = -1;
					}
					else if ( operation == "SUB" )
					{
						int left, right;
						if ( arg1[0] == '$' )
							left = pos1;
						else left = val1;
						if ( arg2[0] == '$' )
							right = pos2;
						else right = val2;
						a[i] = left - right;
						O[j].cell = -1;
					}
					else if ( operation == "MULT" )
					{
						int left, right;
						if ( arg1[0] == '$' )
							left = pos1;
						else left = val1;
						if ( arg2[0] == '$' )
							right = pos2;
						else right = val2;
						a[i] = left * right;
						O[j].cell = -1;
					}
				}
			}
		}
	}
	for ( i = 0; i < n; i++ )
		cout << a[i] << '\n';
    return 0;
}

