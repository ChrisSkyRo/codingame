// Solution to the puzzle Defibrillators
// https://www.codingame.com/training/easy/defibrillators

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct defibrilator
{
	string address;
	double latitude, longitude;
}D[10000];

double StringToDouble(string coordinate)
{
	for ( unsigned i = 0; i < coordinate.length(); i++ )
		if ( coordinate[i] == ',' )
		{
			coordinate[i] = '.';
			break;
		}
	return stod( coordinate );
}

int main()
{
	string lon;
	cin >> lon; cin.ignore();
	double Lon = StringToDouble( lon );
	string lat;
	cin >> lat; cin.ignore();
	double Lat = StringToDouble( lat );
	int n;
	cin >> n; cin.ignore();
	for ( int i = 0; i < n; i++ )
	{
		string defib;
		getline( cin, defib );
		int j;
		for ( j = 0; defib[j] != ';'; j++ );
		j++;
		while ( defib[j] != ';' )
		{
			D[i].address += defib[j];
			j++;
		}
		j++;
		while ( defib[j] != ';' )
			j++;
		j++;
		while ( defib[j] != ';' )
			j++;
		j++;
		string c = "";
		while ( defib[j] != ';' )
		{
			c += defib[j];
			j++;
		}
		j++;
		D[i].longitude = StringToDouble( c );
		c = "";
		while ( j < defib.length() )
		{
			c += defib[j];
			j++;
		}
		D[i].latitude = StringToDouble( c );
	}

	double mini = 999999999, x, y, d;
	int pMin = 0;

	for ( int i = 0; i < n; i++ )
	{
		x = ( D[i].longitude - Lon )*cos( ( Lat + D[i].latitude ) / 2 );
		y = D[i].latitude - Lat;
		d = sqrt( x*x + y * y ) * 6371;
		if ( d < mini )
		{
			mini = d;
			pMin = i;
		}
	}
	cout << D[pMin].address;
}

