#include <iostream>

using namespace std;

long fibonacci(int position){
    if(position < 1)
        return 0;

    long prev = 1,
         prev_prev = 1,
         result = 1;

    for(int i = 3; i <= position; i++){
        result = prev + prev_prev;
        prev_prev = prev;
        prev = result;
    }
    return result;
}

int main(){
    cout << fibonacci(92);
    return 0;
}
