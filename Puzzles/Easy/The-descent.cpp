// Solution to the puzzle The Descent
// https://www.codingame.com/training/easy/the-descent

#include <iostream>
using namespace std;

int main()
{
    // game loop
    while (1) {
        int maxHeight = 0, maxIndex;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            if(mountainH > maxHeight){
                maxHeight = mountainH;
                maxIndex = i;
            }
        }
        cout << maxIndex << endl;
    }
}

