// Solution to the puzzle Brackets, extreme edition
// https://www.codingame.com/training/easy/brackets-extreme-edition

#include <iostream>
using namespace std;

int main( )
{
	char stack[2048], c;
	int l = 0;
	while ( cin >> c )
	{
		if ( c == ')' )
		{
			if ( l > 0 && stack[l - 1] == '(' )
				l--;
			else
			{
				cout << "false";
				return 0;
			}
		}
		else if ( c == ']' )
		{
			if ( l > 0 && stack[l - 1] == '[' )
				l--;
			else
			{
				cout << "false";
				return 0;
			}
		}
		else if ( c == '}' )
		{
			if ( l > 0 && stack[l - 1] == '{' )
				l--;
			else
			{
				cout << "false";
				return 0;
			}
		}
		else if ( c == '(' || c == '[' || c == '{' )
			stack[l++] = c;
	}
	if ( !l )
		cout << "true";
	else cout << "false";
	return 0;
}

