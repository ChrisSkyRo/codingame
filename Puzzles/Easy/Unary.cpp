// Solution to the puzzle Unary
// https://www.codingame.com/training/easy/unary

#include <iostream>
#include <string>
using namespace std;

int a[1005], l;

int main(){
    string MESSAGE;
    getline(cin, MESSAGE);
    for(int i = 0;i < MESSAGE.length();i++){
        int x = MESSAGE[i];
        l += 7;
        for(int j = l-1;x;j--){
            a[j] = x%2;
            x /= 2;
        }
    }
    int c = a[0], f = 1;
    if(c == 1)
        cout << 0 << " ";
    else cout << "00" << " ";
    for(int i = 1;i < l;i++){
        if(a[i] != c){
            while(f){
                cout << 0;
                f--;
            }
            cout << " ";
            c = a[i];
            f = 1;
            if(c == 1)
                cout << 0 << " ";
            else cout << "00" << " ";
        }
        else f++;
    }
    while(f){
        cout << 0;
        f--;
    }
}

