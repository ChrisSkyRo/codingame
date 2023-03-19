// Solution for the Code of Kutulu challenge
// https://www.codingame.com/multiplayer/bot-programming/code-of-kutulu

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define player Entities[0]
#define currentEntity Entities[i]

struct enitity
{
    string type;    // EXPLORER | WANDERER | EFFECT_PLAN | EFFECT_LIGHT
    int id;         // -1 for effect
    int x, y;       // position
    
    int param0;     // EXPLORER: sanity
                    // Spawning WANDERER: time before spawn
                    // WANDERER: time before being recalled
                    // EFFECT: time before fading out 
    
    int param1;     // EXPLORER: plans left
                    // WANDERER: state (SPAWNING = 0, WANDERING = 1)
                    // EFFECT: id of the explorer that started it

    int param2;     // EXPLORER: lights left
                    // WANDERER: target id (-1 if no target)
    
    int distanceToExplorers[4]; // distance on map to each EXPLORER
} Entities[100];

// direction arrays used for fill
int V[] = { 0,  1,  0, -1};
int H[] = { 1,  0, -1,  0};

// fill algorithm
void floodFill(int temple[][20], int floodMap[][20], int width, int height, int x, int y)
{
    for(int k = 0; k < 4; k++){
        int nextX = x+H[k], nextY = y+V[k];
        if(nextX >= 0 && nextX < width && nextY >= 0 && nextY < height && temple[nextX][nextY] != 1)
            if(floodMap[nextX][nextY] == 0 || floodMap[nextX][nextY] > floodMap[x][y]+1)
            {
                floodMap[nextX][nextY] = floodMap[x][y]+1;
                floodFill(temple, floodMap, width, height, nextX, nextY);
            }
    }
}

// calculates distance to each explorer for current entity
void calculateDistanceToExplorers(int temple[][20], int i, int width, int height, int entityCount)
{
    int floodMap[24][20] = {};
    floodMap[currentEntity.x][currentEntity.y] = 1;
    floodFill(temple, floodMap, width, height, currentEntity.x, currentEntity.y);
    for(int j = 0;j < entityCount; j++)
        if(Entities[j].type == "EXPLORER")
            currentEntity.distanceToExplorers[j] = floodMap[Entities[j].x][Entities[j].y]-1;
}

// return the Manhattan distance
int ManhattanDistance(int a, int b){
    return abs(Entities[a].x-Entities[b].x) + abs(Entities[a].y-Entities[b].y);
}

// checks whether an enemy can be warded to target a different EXPLORER
bool canBeWarded(int i, int entityCount){
    for(int j = 1; j < entityCount; j++)
        if(Entities[j].type == "EXPLORER" && currentEntity.distanceToExplorers[j] < currentEntity.distanceToExplorers[0]+8)
            return true;
    return false;
}

// checks whether there is any EXPLORER alive (except the player)
bool areExplorersAlive(int entityCount){
    for(int i = 1; i < entityCount; i++)
        if(currentEntity.type == "EXPLORER")
            return true;
    return false;
}

// returns the index of the closest EXPLORER
int closestExplorer(int enitityCount){
    int closest = 0;
    for(int i = 1; i < enitityCount; i++)
        if(currentEntity.type == "EXPLORER" && (closest == 0 || player.distanceToExplorers[i] < player.distanceToExplorers[closest]))
            closest = i;
    return closest;
}

// marks the LoS for the SLASHER
void slasherDanger(int temple[][20], int x, int y){
    temple[x][y] = -2;
    int _x = x+1;
    while(temple[_x][y] != 1)
    {
        if(temple[_x][y] == 0)
            temple[_x][y] = -2;
        _x++;
    }
    _x = x-1;
    while(temple[_x][y] != 1)
    {
        if(temple[_x][y] == 0)
            temple[_x][y] = -2;
        _x--;
    }
    int _y = y+1;
    while(temple[x][_y] != 1)
    {
        if(temple[x][_y] == 0)
            temple[x][_y] = -2;
        _y++;
    }
    _y = y-1;
    while(temple[x][_y] != 1)
    {
        if(temple[x][_y] == 0)
            temple[x][_y] = -2;
        _y--;
    }
}

// checks whether a cell is safe
bool isSafeCell(int temple[][20], int x, int y)
{
    for(int k = 0; k < 4; k++)
        if(temple[x+H[k]][y+V[k]] == -1)
            return false;
    return true;
}

bool wandererDanger(int temple[][20])
{
    // WANDERER about to attack
    if(temple[player.x+1][player.y] == -1 || temple[player.x-1][player.y] == -1 || temple[player.x][player.y+1] == -1 || temple[player.x][player.y-1] == -1)
        return true;
    return false;
}

bool slasherDanger(int temple[][20])
{
    // SLASHER LoS
    if(temple[player.x][player.y] == -2)
        return true;
    return false;
}

struct position
{
    int x, y;
};

position searchSafeCell(int temple[][20], int width, int height)
{
    position Q[500];
    int left = 0, right = 1;
    int searchMap[24][20] = {};
    searchMap[player.x][player.y] = 1;
    Q[0].x = player.x;
    Q[0].y = player.y;
    while(left < right)
    {
        for(int k = 0; k < 4; k++)
        {
            position nextPos = Q[left];
            nextPos.x += H[k];
            nextPos.y += V[k];
            if(nextPos.x >= 0 && nextPos.x < width && nextPos.y >= 0 && nextPos.y < height && searchMap[nextPos.x][nextPos.y] == 0 && temple[nextPos.x][nextPos.y] != 1 && temple[nextPos.x][nextPos.y] != -1)
            {
                if(temple[nextPos.x][nextPos.y] == 0 && isSafeCell(temple, nextPos.x, nextPos.y))
                    return nextPos;
                Q[right++] = nextPos;
                searchMap[nextPos.x][nextPos.y] = searchMap[Q[left].x][Q[left].y]+1;
            }
        }
        left++;
    }
    return Q[0];
}

int main()
{
    int temple[24][20] = {};
    int width;
    cin >> width; cin.ignore();
    int height;
    cin >> height; cin.ignore();
    for (int i = 0; i < height; i++) {
        string line;
        getline(cin, line);
        for(int j = 0; j < width; j++)
            if(line[j] == '#')
                temple[j][i] = 1;
            else if(line[j] == 'U')
                temple[i][j] = 2;
            //else if(line[j] == 'w')
            //    temple[i][j] = 3;
    }
    int sanity_loss_lonely; // how much sanity you lose every turn when alone, always 3 until wood 1
    int sanity_loss_group; // how much sanity you lose every turn when near another player, always 1 until wood 1
    int wanderer_spawn_time; // how many turns the wanderer take to spawn, always 3 until wood 1
    int wanderer_life_time; // how many turns the wanderer is on map after spawning, always 40 until wood 1
    cin >> sanity_loss_lonely >> sanity_loss_group >> wanderer_spawn_time >> wanderer_life_time; cin.ignore();

    int effectCooldown = 0;
    // game loop
    while (1) {
        bool yell = true;
        int wardable = 0;
        int expNearby = 0;
        int entity_count; // the first given entity corresponds to your explorer
        cin >> entity_count; cin.ignore();
        for (int i = 0; i < entity_count; i++)
        {
            cin >> currentEntity.type >> currentEntity.id >> currentEntity.x >> currentEntity.y >> currentEntity.param0 >> currentEntity.param1 >> currentEntity.param2; cin.ignore();
            
            if(i == 0)
                calculateDistanceToExplorers(temple, i, width, height, entity_count);
            else if(currentEntity.type == "WANDERER")
            {
                calculateDistanceToExplorers(temple, i, width, height, entity_count);
                temple[currentEntity.x][currentEntity.y] = -1;
                if(currentEntity.param2 == player.id && canBeWarded(i, entity_count))
                    wardable++;
            }
            else if(currentEntity.type == "EXPLORER")
            {
                if(ManhattanDistance(0, i) <= 2)
                    expNearby++;
            }
            else if(currentEntity.type == "SLASHER")
            {
                slasherDanger(temple, currentEntity.x, currentEntity.y);
            }
        }
        // run from wanderer about to spook
        if(wandererDanger(temple))
        {
            if(temple[player.x+1][player.y] == 0 && isSafeCell(temple, player.x+1, player.y))
                cout << "MOVE " << player.x+1 << " " << player.y << endl;
            else if(temple[player.x-1][player.y] == 0 && isSafeCell(temple, player.x-1, player.y))
                cout << "MOVE " << player.x-1 << " " << player.y << endl;
            else if(temple[player.x][player.y+1] == 0 && isSafeCell(temple, player.x, player.y+1))
                cout << "MOVE " << player.x << " " << player.y+1 << endl;
            else if(temple[player.x][player.y-1] == 0 && isSafeCell(temple, player.x, player.y-1))
                cout << "MOVE " << player.x << " " << player.y-1 << endl;
            else if(areExplorersAlive(entity_count) && ManhattanDistance(0, closestExplorer(entity_count)) > 0)
                cout << "MOVE " << Entities[closestExplorer(entity_count)].x << " " << Entities[closestExplorer(entity_count)].y << endl;
            else
                cout << "WAIT Danger" << endl;
        }
        // run from slasher LoS
        else if(slasherDanger(temple))
        {
            position safePos = searchSafeCell(temple, width, height);
            if(safePos.x == player.x && safePos.y == player.y){
                // move to the closest EXPLORER
                if(areExplorersAlive(entity_count) && ManhattanDistance(0, closestExplorer(entity_count)) > 1)
                    cout << "MOVE " << Entities[closestExplorer(entity_count)].x << " " << Entities[closestExplorer(entity_count)].y << endl;
                // RIP
                else
                    cout << "WAIT" << endl;
            }
            else
            {
                cout << "MOVE " << safePos.x << " " << safePos.y << endl;
            }
        }
        // ward if 2 or more WANDERERS can be warded
        else if(!effectCooldown && wardable > 1 && player.param2)
        {
            effectCooldown = 2;
            cout << "LIGHT" << endl;
        }
        // move to the closest EXPLORER
        else if(areExplorersAlive(entity_count) && ManhattanDistance(0, closestExplorer(entity_count)) > 1)
        {
            cout << "MOVE " << Entities[closestExplorer(entity_count)].x << " " << Entities[closestExplorer(entity_count)].y << endl;
        }
        // plan if there are 2 or more explorers nearby
        else if(!effectCooldown && expNearby > 2 && player.param1 && player.param0 < 200)
        {
            effectCooldown = 4;
            cout << "PLAN" << endl;
        }
        else if(!effectCooldown && expNearby > 1 && yell && player.param0 < 100)
        {
            yell = false;
            effectCooldown = 2;
            cout << "YELL" << endl;
        }
        else
            cout << "WAIT Else" << endl;
        // clear the map
        for(int i = 0; i < width; i++)
            for(int j = 0; j < height; j++)
                if(temple[i][j] == -1)
                    temple[i][j] = 0;
        if(effectCooldown)
            effectCooldown--;
    }
}
