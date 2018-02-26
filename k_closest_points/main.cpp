// Print the K closest points to the origin
// ATTENTION: using references to the elements in vector
// will mess up EVERYTHING!


#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <utility> //for pair<>

using namespace std;

void printKClosestPoints(const vector<pair<int,int>>& inputVec, int k);

template<typename T>
T magnitudeSquared(T x, T y);


int main() {

  vector<pair<int,int>> points {{1,1}, {-1,-1}, {2,-1}, {-2,-2}, {1,-3}, {0,5}, {-1,-7}};

  printKClosestPoints(points, 7);

  return 0;
}

void printKClosestPoints(const vector<pair<int,int>>& inputVec, int k){

  //multimap allows pairs with the same key (magnitude)
  multimap<int,pair<int,int>> orderedPoints;

  for(auto point : inputVec){
    int magnitude = magnitudeSquared(point.first, point.second);

    orderedPoints.insert({magnitude,point});

  }


  if(k > 0 && k <= (int)inputVec.size()){

    auto itr = orderedPoints.begin();

    for(int i=0; i < k; i++){
      cout << itr->first <<": (" <<itr->second.first << " , " <<itr->second.second <<")" <<endl;

      ++itr;
    }
  }

}

template<typename T>
T magnitudeSquared(T x, T y){
  return x*x + y*y;
}
