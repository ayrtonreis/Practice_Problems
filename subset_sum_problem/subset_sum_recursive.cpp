#include <iostream>

using namespace std;

bool subsetSumRecursive(int start, int end, int* inputArray, int target){
    if(target == 0)
        return true;
    //no element left to check
    if(start > end)
        return false;

    //try a solution WITH and WITHOUT array at index=start
    return (subsetSumRecursive(start+1, end, inputArray, target-inputArray[start]) ||
            subsetSumRecursive(start+1, end, inputArray, target));
}

bool subsetSum(int* inputArray, int arraySize, int target){
    return subsetSumRecursive(0, arraySize, inputArray, target);
}

int main(){

    int input[] {4,-6,4,2};
    int arraySize = sizeof(input)/sizeof(int);
    int target = 10;

    cout << subsetSum(input, arraySize, target) <<endl;


    return 0;
}
