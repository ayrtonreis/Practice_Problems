#include <iostream>

using namespace std;

long fibonacci(int position){
    if(position < 1)
        return 0;

    long array_mem[position];
    array_mem[0] = array_mem[1] = 1;

    for(int i = 2; i < position; i++)
        array_mem[i] = array_mem[i-1] + array_mem[i-2];

    return array_mem[position-1];
}

int main(){
    cout << fibonacci(50) <<endl;
    return 0;
}
