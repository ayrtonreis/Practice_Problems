#include <iostream>
#include <map>

using namespace std;

/* Returns the median of an array of values
** returns double (array of ints with even number of elements won't have int median)
** Runtime complexity O(N log K), K is the number of unique values in the array
*/
template<typename T>
double median(T values[], int values_size){

    if(values_size == 1)
        return values[0];

    map<T,int> frequencies;

    for(int i=0; i<values_size; i++){
        auto valuePos = frequencies.find(values[i]); //O(log K)
        if(valuePos == frequencies.end())
            frequencies.insert({values[i],1}); //O(log K)
        else
            ++(valuePos->second);
    }

    bool isSizeEven = values_size%2 == 0;
    int currentPos = 0;
    auto currentItr = frequencies.cbegin();
    double result;

    while(currentPos < values_size/2){
        currentPos += currentItr->second;
        result = currentItr->first;
        ++currentItr;
    }

    if(currentPos == values_size/2){
        if(isSizeEven)
            result = (result+currentItr->first)/2.0;
        else
            result = currentItr->first;
    }
    // else currentPos > half_size and result is already correct

    return result;
}

int main(){
    int input[] = {-2, -2, -2, 1, 2, 2};
    int input_size = sizeof(input)/sizeof(int);
    cout << "Result: " <<median(input, input_size) <<endl;
    return 0;
}
