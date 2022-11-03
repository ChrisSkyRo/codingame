// Solution to the puzzle Horse-racing Duals
// https://www.codingame.com/training/easy/horse-racing-duals

#include <iostream>
using namespace std;

char fr[10000001];

int main(){
    int n, mini = 100000, maxi = 0;
    cin >> n; cin.ignore();
    for (int i = 0; i < n; i++) {
        int Pi;
        cin >> Pi; cin.ignore();
        if(fr[Pi]){
            cout << 0;
            return 0;
        }
        if(Pi > maxi)
            maxi = Pi;
        fr[Pi] = 1;
    }
    int last = 0;
    while(!fr[last])
        last++;
    for(int i = last+1;i <= maxi;i++){
        if(fr[i]){
            if(i-last < mini)
                mini = i-last;
            last = i;
        }
    }
    cout << mini;
}

