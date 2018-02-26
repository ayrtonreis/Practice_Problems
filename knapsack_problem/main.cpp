#include <iostream>
#include <unordered_map>
#include <utility>
#include <algorithm>

using namespace std;

struct Item{
  int weight;
  int value;
};

struct SimpleHash {
    size_t operator()(const pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

int knapsack(int n, int c, Item input[], unordered_map<pair<int,int>, int, SimpleHash>& memory);


int main() {

   Item input[] {{2,3}, {3,4}, {4,5}, {5,6}};

  unordered_map<pair<int,int>, int, SimpleHash> memory;

  cout << knapsack(sizeof(input)/sizeof(Item), 5, input, memory);

  return 0;
}


int knapsack(int n, int c, Item input[], unordered_map<pair<int,int>, int, SimpleHash>& memory){
  cout << "Knapsack: n = " <<n <<", c = " <<c <<endl;
  auto gotElement = memory.find(pair<int,int>(n,c));

  if(gotElement != memory.end()){
    cout << "repeated"<<endl;
    return gotElement->second;

  }

  //no capacity left or no item left
  if(c == 0 || n == 0)
    return 0;

  int index = n - 1; //array based index starts at 0, n is the number of items

  if(input[index].weight > c)
    return knapsack(n-1, c, input, memory);

  int result = max(knapsack(n-1, c, input, memory),
             knapsack(n-1, c-input[index].weight, input, memory) + input[index].value);

  memory.insert({pair<int,int>(n,c),result});
  cout << "Saved (n= " << n << ", c= " <<c <<")"<<endl;

  return result;

}
