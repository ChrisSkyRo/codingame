// Solution to the puzzle 7-segment scanner
// https://www.codingame.com/training/easy/7-segment-scanner

#include <iostream>
using namespace std;

int main()
{
	char display[3][901],
		one[3][3] = { {' ', ' ', ' '},
						{' ', ' ', '|' },
						{' ', ' ', '|' } },
		two[3][3] = { {' ','_',' '},
						{' ','_','|'},
						{'|','_',' '} },
		three[3][3] = { {' ','_',' '},
						{' ','_','|'},
						{' ','_','|'} },
		four[3][3] = { {' ',' ',' '},
						{'|','_','|'},
						{' ',' ','|'} },
		five[3][3] = { {' ','_',' '},
						{'|','_',' '},
						{' ','_','|'} },
		six[3][3] = { {' ','_',' '},
						{'|','_',' '},
						{'|','_','|'} },
		seven[3][3] = { {' ','_',' '},
						{' ',' ','|'},
						{' ',' ','|'} },
		eight[3][3] = { {' ','_',' '},
						{'|','_','|'},
						{'|','_','|'} },
		nine[3][3] = { {' ','_',' '},
						{'|','_','|'},
						{' ','_','|'} };
	int k, i, j, sum;
	for ( i = 0; i < 3; i++ )
		cin.getline( display[i], sizeof( display[i] ) );
	for ( k = 0; display[0][k * 3] != '\0'; k++ )
	{
		bool number[10] = {};
		sum = 45;
		for ( i = 0; i < 3; i++ )
			for ( j = 0; j < 3; j++ )
			{
				if ( !number[1] && display[i][k * 3 + j] != one[i][j] )
				{
					number[1] = true;
					sum -= 1;
				}
				if ( !number[2] && display[i][k * 3 + j] != two[i][j] )
				{
					number[2] = true;
					sum -= 2;
				}
				if ( !number[3] && display[i][k * 3 + j] != three[i][j] )
				{
					number[3] = true;
					sum -= 3;
				}
				if ( !number[4] && display[i][k * 3 + j] != four[i][j] )
				{
					number[4] = true;
					sum -= 4;
				}
				if ( !number[5] && display[i][k * 3 + j] != five[i][j] )
				{
					number[5] = true;
					sum -= 5;
				}
				if ( !number[6] && display[i][k * 3 + j] != six[i][j] )
				{
					number[6] = true;
					sum -= 6;
				}
				if ( !number[7] && display[i][k * 3 + j] != seven[i][j] )
				{
					number[7] = true;
					sum -= 7;
				}
				if ( !number[8] && display[i][k * 3 + j] != eight[i][j] )
				{
					number[8] = true;
					sum -= 8;
				}
				if ( !number[9] && display[i][k * 3 + j] != nine[i][j] )
				{
					number[9] = true;
					sum -= 9;
				}
			}
		cout << sum;
	}
	return 0;
}

