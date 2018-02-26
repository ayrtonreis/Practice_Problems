// Print the K closest points to the origin
// ATTENTION: using references to the elements in vector
// will mess up EVERYTHING!

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility> //for pair<>

using namespace std;

void printKClosestPoints(vector<pair<int,int>>& inputVec, int k);

template<typename T>
T magnitudeSquared(T x, T y);

//Binary predicate used for the heap methods
template<typename T>
bool isGreater(const pair<T,T>& a, const pair<T,T>& b);

int main() {

  vector<pair<int,int>> points {{1,1}, {-1,-1}, {2,-1}, {-2,-2}, {1,-3}, {0,5}, {-1,-7}};

  printKClosestPoints(points, 2);

  return 0;
}

//1 - The vector is being changed in this case
//2 - isGreater is used to turn the max_heap into a min_heap
//3 - pop_heap ONLY moves the first element of the heap to the last position
//4 - Time complexity: O( n + k*log(n) )

void printKClosestPoints(vector<pair<int,int>>& inputVec, int k){

    make_heap(inputVec.begin(), inputVec.end(), isGreater<int>); // O(n)

    if(k > 0 && k <= inputVec.size()){
        for(int i = 0; i < k; i++){
            pair<int,int> closestPoint = *inputVec.begin();
            pop_heap(inputVec.begin(), inputVec.end()-i, isGreater<int>); // O(log n)
            cout << magnitudeSquared(closestPoint.first, closestPoint.second) << ": " << closestPoint.first << ", " <<closestPoint.second <<endl;
        }
    }
}

template<typename T>
T magnitudeSquared(T x, T y){
  return x*x + y*y;
}

template<typename T>
bool isGreater(const pair<T,T>& a, const pair<T,T>& b){
    return magnitudeSquared(a.first, a.second) > magnitudeSquared(b.first, b.second);
}
