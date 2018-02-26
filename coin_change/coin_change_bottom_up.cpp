#include <iostream>
#include <vector>
#include<algorithm>

#define INFINITY 99999

using namespace std;

int coinChangeBottomUp(int value){
    static const vector<int> coinValues {1, 2, 5};

    if(value <= 0)
        return 0;

    int* memArray = new int[value+1];

    memArray[0] = 0;

    for(int index = 1; index <= value; index++){
        int minNumberCoins = INFINITY;

        for(int v : coinValues)
            if(index-v >= 0)
                minNumberCoins = min(minNumberCoins, 1+memArray[index-v]);

        memArray[index] = minNumberCoins;
    }

    int result = memArray[value];

    delete[] memArray;

    return result;

}

int main(){

    cout << coinChangeBottomUp(5003) <<endl;

    return 0;
}
