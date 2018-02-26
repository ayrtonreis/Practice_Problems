#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file;
    file.open("values.txt");

    char c;
    string line;

    if(file.is_open())
   {
        getline(file,line,','); //std::getline() is defined in <string>
        cout << line;
    }

    file.close();

    return 0;
}
