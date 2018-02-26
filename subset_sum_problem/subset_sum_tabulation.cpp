#include <iostream>
#include <vector>
#include <deque>

using namespace std;


int** allocateMatrix(int rows, int cols){
    //dinamically create array of pointers of size=rows
    int** matrix = new int*[rows];

    //dinamically allocate memory of size=cols for each row
    for(int i=0; i<rows; i++)
        matrix[i] = new int[cols];

    return matrix;
}

void deallocateMatrix(int** matrix, int rows){
    //deallocate memory using delete[] operator
    for(int i=0; i<rows; i++)
        delete[] matrix[i];

    delete[] matrix;
}

//TARGET MUST BE POSITIVE
bool subsetSum_old(vector<int>& input, int target){
    //create matrix of size [input_length][target_length + 1]
    int** matrix = allocateMatrix(input.size(), target+1);

    for(int row=0; row<input.size(); row++){
        for(int col=0; col<= target; col++){
            if(col ==0 ){
                matrix[row][col] = true;
            }
            else if(col == input[row]){
                matrix[row][col] = true;
            }
            else if(row > 0){
                if(col - input[row] > 0 && matrix[row-1][ col-input[row] ])
                    matrix[row][col] = true;
                else
                    matrix[row][col] = false;
            }
            else{
                matrix[row][col] = false;
            }
        }

        if(matrix[row][target])
            return true;
    }

    deallocateMatrix(matrix, input.size());

    return false;
}

//TARGET AND ALL ELEMENTS IN INPUT MUST BE POSITIVE FOR THIS METHOD TO WORK PROPERLY
bool subsetSum(vector<int>& input, int target){
    //create matrix of size [input_length][target_length + 1]
    int** matrix = allocateMatrix(input.size(), target+1);

    int row = 0;

    matrix[0][0] = true;
    for(int col=1; col<=target; col++)
        matrix[row][col] = (col == input[row]) ? true : false;



    for(row=1; row<input.size(); row++){
        for(int col=0; col<=target; col++){
            if(matrix[row-1][col]){

                matrix[row][col] = true;
                //cout << "matrix[" <<row <<"][" <<col <<"] is TRUE because of 1" <<endl;
            }
            else if(col-input[row] >= 0 && matrix[row-1][col-input[row]]){
                matrix[row][col] = true;
                //cout << "matrix[" <<row <<"][" <<col <<"] is TRUE because of 2" <<endl;
            }
            else{
                matrix[row][col] = false;
            }
        }

        if(matrix[row][target])
            return true;
    }

    deallocateMatrix(matrix, input.size());

    return false;
}

struct testCase{
    vector<int> input;
    int target;
    bool expectedResult;
};

int main(){

    deque<testCase> inputs {
//                                    {{1,0,-1}, 0, true},
//                                    {{4,5,-6}, 10, false},
//                                    {{4,4,6}, 10, true},
//                                    {{1,1,1,1,1,1,1,1,1,1,1,0}, 0, true},
                                    {{-6,-4,0,4,6}, 8, false}//,
//                                    {{1,10,100,1000,10000}, 11111, true},
//                                    {{6,10,4}, 40, false},
//                                    {{1,3,6,1,8}, 7, true}

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
