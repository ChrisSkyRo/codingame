// Solution for the Fall Challenge 2020
// https://www.codingame.com/multiplayer/bot-programming/fall-challenge-2020

#include <iostream>
#include <string>
using namespace std;

struct recipe{
    int actionId; // the unique ID of this spell or recipe
    string actionType; // in the first league: BREW; later: CAST, OPPONENT_CAST, LEARN, BREW
    int delta0; // tier-0 ingredient change
    int delta1; // tier-1 ingredient change
    int delta2; // tier-2 ingredient change
    int delta3; // tier-3 ingredient change
    int price; // the price in rupees if this is a potion
    int tomeIndex; // in the first two leagues: always 0; later: the index in the tome if this is a tome spell, equal to the read-ahead tax; For brews, this is the value of the current urgency bonus
    int taxCount; // in the first two leagues: always 0; later: the amount of taxed tier-0 ingredients you gain from learning this spell; For brews, this is how many times you can still gain an urgency bonus
    bool castable; // in the first league: always 0; later: 1 if this is a castable player spell
    bool repeatable; // for the first two leagues: always 0; later: 1 if this is a repeatable player spell
} R[50];

struct inventory{
    int inv0; // tier-0 ingredients in inventory
    int inv1;
    int inv2;
    int inv3;
    int score; // amount of rupees
} I[2];

bool makeCastable[4];
int myNumber = 0;

void MakeTier0(){
    if(makeCastable[0])
        cout << "CAST " << 78 + myNumber*4 - 4 << endl;
    else cout << "REST" << endl;
}

void MakeTier1(int orderIndex){
    if(!I[0].inv0)
        MakeTier0();
    else {
        if(makeCastable[1])
            cout << "CAST " << 79 + myNumber*4 - 4 << endl;
        else cout << "REST" << endl;
    }
}

void MakeTier2(int orderIndex){
    if(!I[0].inv1)
        MakeTier1(orderIndex);
    else {
        if(makeCastable[2])
            cout << "CAST " << 80 + myNumber*4 - 4 << endl;
        else cout << "REST" << endl;
    }
}

void MakeTier3(int orderIndex){
    if(!I[0].inv2)
        MakeTier2(orderIndex);
    else {
        if(makeCastable[3])
            cout << "CAST " << 81 + myNumber*4 - 4 << endl;
        else cout << "REST" << endl;
    }
}

int main(){
    
    // game loop
    while (1) {
        int actionCount; // the number of spells and recipes in play
        cin >> actionCount; cin.ignore();
        for (int i = 0; i < actionCount; i++) {
            cin >> R[i].actionId >> R[i].actionType >> R[i].delta0 >> R[i].delta1 >> R[i].delta2 >> R[i].delta3 >> R[i].price >> R[i].tomeIndex >> R[i].taxCount >> R[i].castable >> R[i].repeatable; cin.ignore();
            if(R[i].actionType == "CAST"){
                if(!myNumber){
                    if(R[i].actionId == 78)
                        myNumber = 1;
                    else myNumber = 2;
                }
            
                if(myNumber ==  1){
                    if(R[i].actionId == 78)
                        makeCastable[0] = R[i].castable;
                    else if(R[i].actionId == 79)
                        makeCastable[1] = R[i].castable;
                    else if(R[i].actionId == 80)
                        makeCastable[2] = R[i].castable;
                    else if(R[i].actionId == 81)
                        makeCastable[3] = R[i].castable;
                    }
                else {
                    if(R[i].actionId == 82)
                        makeCastable[0] = R[i].castable;
                    else if(R[i].actionId == 83)
                        makeCastable[1] = R[i].castable;
                    else if(R[i].actionId == 84)
                        makeCastable[2] = R[i].castable;
                    else if(R[i].actionId == 85)
                        makeCastable[3] = R[i].castable;
                }
            }
        }
        for (int i = 0; i < 2; i++) {
            cin >> I[i].inv0 >> I[i].inv1 >> I[i].inv2 >> I[i].inv3 >> I[i].score; cin.ignore();
        }

        // Find most expensive order
        int maxPrice = 0;
        int maxId = 0;
        int orderIndex = 0;
        string action = "BREW";

        for(int i = 0;i < actionCount;i++){
            if(R[i].price > maxPrice){
                maxPrice = R[i].price;
                maxId = R[i].actionId;
                orderIndex = i;
            }
        }

        // Brew the spell if we can, acquire ingredients if not

        if(!(I[0].inv0+R[orderIndex].delta0 >= 0 && I[0].inv1+R[orderIndex].delta1 >= 0 && I[0].inv2+R[orderIndex].delta2 >= 0 && I[0].inv3+R[orderIndex].delta3 >= 0)){
            if(I[0].inv3+R[orderIndex].delta3 < 0)
                MakeTier3(orderIndex);
            else if(I[0].inv2+R[orderIndex].delta2 < 0)
                MakeTier2(orderIndex);
            else if(I[0].inv1+R[orderIndex].delta1 < 0)
                MakeTier1(orderIndex);
            else MakeTier0();
            continue;
        }

        cout << action << " " << maxId << endl;
    }

}