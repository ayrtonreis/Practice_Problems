#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

map<string,string> assignFriendPairs(const vector<string> names);

void shuffleIndexes(vector<int>& v);

int main(){
    vector<string> names {"John", "Chris", "Mary", "Tyler"};

    map<string,string> friendPairs = assignFriendPairs(names);

    for(auto elem : friendPairs){
        cout << elem.first << " - " << elem.second <<endl;
    }

    return 0;
}

map<string,string> assignFriendPairs(const vector<string> names){

    srand(time(0));

    vector<int> shuffledIndexes;
    map<string,string> friendPairs;

    for(int i=0; i<names.size(); i++)
        shuffledIndexes.push_back(i);

    shuffleIndexes(shuffledIndexes);

    auto itr_1 = names.cbegin();
    auto itr_2 = shuffledIndexes.cbegin();

    while(itr_1 != names.cend()){
        friendPairs.insert({*itr_1, names[*itr_2]});

        ++itr_1;
        ++itr_2;
    }

    return friendPairs;

}

void shuffleIndexes(vector<int>& v){
    if(v.size() > 1){
        random_shuffle(v.begin(), v.end());

        for(int i=0; i<v.size(); i++){
            if(v[i] == i){
                if(i == v.size()-1)
                    swap(v[i], v[i-1]);
                else
                    swap(v[i], v[i+1]);
            }
        }
    }
}
