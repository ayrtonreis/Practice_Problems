#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//int knapsack(int n, int c, int weight[], int value[], );

int knapsackBottomUp(int weight[], int value[], int n, int capacity);


int main() {

    int weight_array[] = {2,3,4,5};
    int value_array[] = {3,4,5,6};
    int n = sizeof(weight_array)/sizeof(weight_array[0]);
    int capacity = 5;

    cout << "Result: " << knapsackBottomUp(weight_array, value_array, n, capacity) <<endl;

    //cout << knapsack(sizeof(input)/sizeof(Item), 5, input, memory);

    return 0;
}


int knapsackBottomUp(int weight[], int value[], int n, int capacity){
    int K[n+1][capacity+1];
    vector<int> bag;

    for(int i=0; i<=n; i++){
        for(int left_capacity=0; left_capacity<=capacity; left_capacity++){
            if( i == 0 || left_capacity == 0){
                K[i][left_capacity] = 0;
            }
            else{
                /* i is the number of elements from 0 to n,
                ** while item is the index of each element from 0 to n-1*/
                int item = i-1;

                if(weight[item] > left_capacity){
                    K[i][left_capacity] = K[i-1][left_capacity];
                }
                else{
                    int value_item_included = K[i-1][left_capacity-weight[item]] + value[item];
                    int value_item_excluded = K[i-1][left_capacity];

                    K[i][left_capacity] = max(value_item_included, value_item_excluded);
                }
            }
        }
    }

    // Find the selected items
    int i = n, left_capacity = capacity;

    while(i > 0){
        if(K[i][left_capacity] != K[i-1][left_capacity]){
            int item_index = i-1;
            bag.push_back(item_index);
            left_capacity -= weight[item_index];
        }

        i--;
    }

    cout << "Items Selected: ";
    for(int item : bag)
        cout << item << " ";

    cout <<endl <<endl;

    return K[n][capacity];

}


