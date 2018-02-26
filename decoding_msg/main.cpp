/*  "Decoding message"
**  Think Like a Programmer, p. 41
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//only works for positive ints
int strToInt(const string& str){
    int result = 0;

    for(int i=0; i<str.size(); i++){
        result *= 10;
        result += str[i] -'0';

    }

    return result;
}

char upperCaseMode(int n){
    return 'A' -1 + n;
}

char lowerCaseMode(int n){
    return 'a' -1 + n;
}

char punctuationMode(int n){
    switch(n){
        case 1: return '!';
        case 2: return '?';
        case 3: return ',';
        case 4: return '.';
        case 5: return ' ';
        case 6: return ';';
        case 7: return '"';
        case 8: return '\'';
    }
}

string decodeFile(string file_name){

    ifstream file;
    file.open(file_name);

    if(file.is_open()){
        int mode = 0;
        char c;
        string final_msg, str_num;

        while(!file.eof()){

            file.get(c);

            if(c != ',' && !file.eof()){
                str_num += c;
            }
            else{
                int num = strToInt(str_num);

                //num is the remainder of num divided by 27 or 9, depeding on the current mode
                num %= (mode==0 || mode==1) ? 27 : 9;

                if(num == 0){
                    mode = (mode+1)%3;
                    //cout << "mode: " <<mode <<endl;
                }
                else{
                    switch(mode){
                        case 0:
                            //cout << num << ": "<<upperCaseMode(num) <<endl;
                            final_msg += upperCaseMode(num);
                            break;
                        case 1:
                            //cout << num << ": "<< lowerCaseMode(num) <<endl;
                            final_msg += lowerCaseMode(num);
                            break;
                        case 2:
                            //cout << num << ": "<< punctuationMode(num) <<endl;
                            final_msg += punctuationMode(num);
                            break;
                    }
                }
                str_num = "";
            }
        }
        return final_msg;
    }
    return "";
}

int main(){
    string decoded_msg = decodeFile("values.txt");

    cout << decoded_msg <<endl;

    return 0;
}
