#include <iostream>
#include <vector>
#include<map>

#define INFINITY 99999

using namespace std;

int coinChangeBottomUp(int value);
void printResultHistogram(const int* lastCoinArray, int value);

int main(){

    int value = 54;
    cout <<"Min number of coins needed for $" <<value <<": "
         <<coinChangeBottomUp(value) <<endl;

    //2 couts<< AND THE PRINTING RESULT WILL BE TOTALLY DIFFERENT

    return 0;
}

//STILL DOESN'T ACCOUNT FOR SOME EDGE CASES
int coinChangeBottomUp(int value){
    static const vector<int> coinValues {1, 5, 13, 48, 49, 51};

    if(value <= 0)
        return 0;

    int* memArray = new int[value+1];
    int* lastCoinArray = new int[value+1];

    memArray[0] = 0;

    for(int index = 1; index <= value; index++){
        int minNumberCoins = INFINITY;
        int currentNumberCoins, lastCoin;

        for(int v : coinValues){
            if(index-v >= 0){
                currentNumberCoins = 1+memArray[index-v];

                if(currentNumberCoins < minNumberCoins){
                    minNumberCoins = currentNumberCoins;
                    lastCoin = v;
                }
            }
        }

        memArray[index] = minNumberCoins;
        lastCoinArray[index] = lastCoin;
    }

    printResultHistogram(lastCoinArray, value);

    int coinsCounter = memArray[value];

    delete[] memArray;
    delete[] lastCoinArray;

    return coinsCounter;

}

void printResultHistogram(const int* lastCoinArray, int value){
    map<int,int> chosenCoinsHistogram;
    int index = value;

    while(index > 0){
        // MISTAKE: NOT NEEDED if(lastCoinArray[index] != lastCoinArray[index-1]){
            //try inserting a new "key" (coin) into the map
            //returns pair<iterator,bool>, where pair->second == true if a new element was added
            auto insertionResult = chosenCoinsHistogram.insert({lastCoinArray[index],1});

            //if the "key" (coin) was already in the map, then just increment its value by 1
            if(!insertionResult.second)
                ++(insertionResult.first->second);

            //decrement the "value position" in the array to find the next chosen coin
            index -= lastCoinArray[index];
        //}
    }

    for(auto coin : chosenCoinsHistogram)
        cout << "$" <<coin.first <<": " <<coin.second <<endl;
    cout <<endl;
}
