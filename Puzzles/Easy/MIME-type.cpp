// Solution to the puzzle MIME Type
// https://www.codingame.com/training/easy/mime-type

#include <iostream> 
#include <string>
#include <cstring>
#include <map> 
using namespace std;

int main()
{
	map<string, string> hash;
	int n, q;
	cin >> n >> q; cin.ignore();
	for ( int i = 0; i < n; i++ )
	{
		string a, b;
		cin >> a >> b;
		for ( int j = 0; j < a.length(); j++ )
			a[j] = tolower( a[j] );
		hash[a] = b;
	}
	for ( int i = 0; i < q; i++ )
	{
		char file[256];
		cin >> file;
		char *p = strrchr( file, '.' );
		if ( p )
		{
			string ext = p + 1;
			for ( int j = 0; j < ext.length(); j++ )
				ext[j] = tolower( ext[j] );
			if ( hash.find( ext ) == hash.end() )
				cout << "UNKNOWN\n";
			else 
				cout << hash[ext] << '\n';
		}
		else cout << "UNKNOWN\n";
	}
}

