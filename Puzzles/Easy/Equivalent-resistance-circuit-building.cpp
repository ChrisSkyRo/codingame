// Solution to the puzzle Equivalent Resistance, Circuit Building
// https://www.codingame.com/training/easy/equivalent-resistance-circuit-building

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
using namespace std;

map <string, float> rezistor;

int main( )
{
	int n, i, k, l = 0, index = 0;
	float v;
	string r, circuit, stack[100];
	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		cin >> r >> v;
		rezistor[r] = v;
	}
	cin.ignore( );
	getline( cin, circuit );
	k = circuit.length( );
	i = 0;
	while ( i < k )
	{
		if ( circuit[i] == '(' )
		{
			stack[l++] = "(";
			i++;
		}
		else if ( circuit[i] == '[' )
		{
			stack[l++] = "[";
			i++;
		}
		else if ( circuit[i] == ')' )
		{
			v = 0;
			while ( stack[l - 1] != "(" )
			{
				v += rezistor[stack[l - 1]];
				l--;
			}
			stack[l - 1] = "result" + to_string( index );
			rezistor[stack[l - 1]] = v;
			index++;
			i++;
		}
		else if ( circuit[i] == ']' )
		{
			v = 0;
			while ( stack[l - 1] != "[" )
			{
				v += 1 / rezistor[stack[l - 1]];
				l--;
			}
			v = 1 / v;
			stack[l - 1] = "result" + to_string( index );
			rezistor[stack[l - 1]] = v;
			index++;
			i++;
		}
		else if ( circuit[i] == ' ' )
			i++;
		else
		{
			r = "";
			while ( circuit[i] != ' ' )
			{
				r += circuit[i];
				i++;
			}
			stack[l++] = r;
		}
	}
	cout << fixed << setprecision( 1 ) << v;
	return 0;
}

