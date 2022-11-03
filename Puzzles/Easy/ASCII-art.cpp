// Solution to the puzzle ASCII Art
// https://www.codingame.com/training/easy/ascii-art

#include <iostream>
#include <cstring>
using namespace std;

char alphabet[35][1005];

int main()
{
    int l, h;
    cin >> l >> h;cin.ignore();
    char t[201];
    cin.getline(t, sizeof(t));
    for(int i = 0;i < strlen(t);i++)
        if(t[i] >= 'a' && t[i] <= 'z')
            t[i] -= 32;
    for (int i = 0; i < h; i++)
        cin.getline(alphabet[i], sizeof(alphabet[i]));
    for(int i = 0;i < h;i++){
        for(int j = 0;j < strlen(t);j++){
            if(t[j] >= 'A' && t[j] <= 'Z'){
                for(int k = (t[j]-'A')*l;k < (t[j]-'A'+1)*l;k++)
                    cout << alphabet[i][k];
            }
            else {
                for(int k = 26*l;k < 27*l;k++)
                    cout << alphabet[i][k];
            }
        }
        cout << '\n';
    }
}

