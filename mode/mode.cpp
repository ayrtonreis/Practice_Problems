#include <iostream>
#include <unordered_map>

using namespace std;

/* Returns the mode from an array of values
** If multiples values in the array have the same frequency,
** only one of them will be returned (randomly)
** Runtime Complexity: O(n)
*/
template<typename T>
T mode(T values[], int values_size){
    unordered_map<T,int> frequencies;
    T highestFreqValue = 0; //instead of highestFreqValue = values[0];
    int highestFreq = 0;

    for(int i=0; i<values_size; i++){
        auto valuePos = frequencies.find(values[i]); //Avg O(1)

        int currentFreq = 1;

        if(valuePos == frequencies.end())
            frequencies.insert({values[i],1}); //Avg O(1)
        else
            currentFreq = ++(valuePos->second);

        if(currentFreq > highestFreq){
            highestFreq = currentFreq;
            highestFreqValue = values[i];
        }
    }

    for(auto elem : frequencies)
        cout <<elem.first <<": " <<elem.second <<endl;

    return highestFreqValue;
}

int main(){

    double input[] = {8.1,8.1,1,2,-1,5,5.1,6,6,8.1,9,8};
    double input_size = sizeof(input)/sizeof(double);

    cout << "Result: " <<mode(input, input_size) <<endl;

    return 0;
}
