#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <utility>
#include <boost/functional/hash.hpp>

using namespace std;
using intHashTable = unordered_map<pair<int,int>, bool, boost::hash<pair<int,int>>>; //type alias

bool subsetSumRecursive(int start, vector<int>& inputVec, int target,intHashTable& memory){
    if(target == 0)
        return true;
    //no element left to check
    if(start > inputVec.size())
        return false;

    //try a solution WITH the array element at index=start
    auto itr = memory.find(make_pair(start,target));

    bool resultWithElement;

    if(itr != memory.end()){
        resultWithElement = itr->second;
    }
    else{
        resultWithElement = subsetSumRecursive(start+1, inputVec, target-inputVec[start], memory);
    }

    if(resultWithElement){
        memory.emplace(make_pair(start, target), true); //"same" as memory.insert({{start,target},true});
        return true;
    }

    //try a solution WITHOUT the array element at index=start
     bool resultWithoutElement = resultWithElement = subsetSumRecursive(start+1, inputVec, target, memory);

    memory.emplace(make_pair(start,target), resultWithoutElement);

    return resultWithoutElement;

}

bool subsetSum(vector<int>& inputVec, int target){
    intHashTable memory;
    return subsetSumRecursive(0, inputVec, target, memory);
}

struct testCase{
    vector<int> input;
    int target;
    bool expectedResult;
};

int main(){

    deque<testCase> inputs {
                                    {{1,0,-1}, 0, true},
                                    {{4,5,-6}, 10, false},
                                    {{4,4,6}, 10, true},
                                    {{1,1,1,1,1,1,1,1,1,1,1,0}, 0, true},
                                    {{-6,-4,0,4,6}, 8, false},
                                    {{1,10,100,1000,10000}, 11111, true},
                                    {{6,10,4}, 40, false},
                                    {{1,3,6,1,8}, 7, true}

                            };

    for(auto &test : inputs){
        bool result = subsetSum(test.input, test.target);
        //without parentheses, <<operator will not work as expected
        cout << ((test.expectedResult == result) ? "OK" : "ERROR")
             << " Expected: " <<test.expectedResult
             <<", Result: " <<result <<endl;
    }

    return 0;
}
