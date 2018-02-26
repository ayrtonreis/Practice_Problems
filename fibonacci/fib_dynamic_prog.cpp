#include <iostream>
#include <vector>

using namespace std;

long fibonacciRecursive(int position, vector<long>& array_mem){
    if(position < 1)
        return 0;
    if(position == 1 || position == 2)
        return 1;

    if(array_mem[position-1] !=0 ){
        return array_mem[position-1];
    }
    else{
        long result = fibonacciRecursive(position-1, array_mem)+fibonacciRecursive(position-2, array_mem);
        array_mem[position-1] = result;
        return result;
    }
}

long fibonacci(int position){
    if(position < 1)
        return 0;

    vector<long> array_memoization(position,0); //initialize all elements to 0
    return fibonacciRecursive(position, array_memoization);
}

int main(){
    cout << fibonacci(50) <<endl;
    return 0;
}
