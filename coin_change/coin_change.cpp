#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#define INFINITY 99999

using namespace std;

int coinChangeRecursive(int value, const vector<int>& coinValues, unordered_map<int,int>& memTable){
    //edge cases
    if(value == 0)
        return 0;
    else if(value < 0)
        return INFINITY;

    //check if the value already exists in the hash table
    auto valuePos = memTable.find(value);
    if(valuePos != memTable.end())
        return valuePos->second;

    int minNumberCoins = INFINITY;

    //find the min number of coins needed for each case
    for(int v : coinValues)
        minNumberCoins = min(minNumberCoins, 1+coinChangeRecursive(value - v, coinValues, memTable));

    //insert the result into the hash table
    memTable.insert({value, minNumberCoins});

    return minNumberCoins;
}

int coinChange(int value){
    static const vector<int> coinValues {1, 2, 5};
    unordered_map<int,int> memTable;

    return coinChangeRecursive(value, coinValues, memTable);
}

int main(){

    cout << coinChange(5003) <<endl;

    return 0;
}
