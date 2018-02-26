#include <iostream>
using namespace std;
//
//enum Numbers:int { First=1, Second, Third };
//
//Numbers operator++( Numbers& value, int i)
//{
//	if(value == Third)
//        value = First;
//    else
//        value = static_cast<Numbers>( static_cast<char>(value)+1 );
//
//	return value;
//}

enum A {a, b};
enum B {a2, b2};

enum class Numbers { First, Second, Third };

Numbers operator++(Numbers& num)
{
    if(num == Numbers::Third){
        num = Numbers::First;
    }
    else
        num = Numbers(int(num) + 1);
    //num = (num == Numbers::Third) ? Numbers::First : Numbers(int(num) + 1);
    return num;
}

enum class Letters {a,b,c};

Letters& operator++(Letters& l){
    if(l == Letters::c) l = Letters::a;
    else l = static_cast<Letters>(static_cast<int>(l)+1);

    return l;
}

Letters operator++(Letters& l, int){
    Letters old_l = l;
    ++l;
    return old_l;
}

std::ostream &operator<<( std::ostream &os, const Letters& l){
    switch(l){
        case Letters::a:
            os << "a";
            break;
        case Letters::b:
            os << "b";
            break;
        case Letters::c:
            os << "c";
            break;
        default:
            os<<"unknown";
            break;
    }
    return os;
}

int main(){
    Letters my_letters;

//    cout << my_letters <<endl;
//
//    my_letters++;
//    my_letters;

    cout << ++my_letters<<endl;

    return 0;
}

int main2() {
    Numbers numbers {Numbers::First};

    ++numbers;
    ++numbers;

    //cout << numbers <<endl;

    switch(numbers){
        case Numbers::First: cout << "First\n"; break;
        case Numbers::Second: cout << "Second\n"; break;
        case Numbers::Third: cout << "Third\n"; break;
        default: cout<<"Unknown\n"; break;
    }

    bool isEqual = int(Numbers::First)==0;
    cout << "is Equal? " <<isEqual  <<endl;

    A my_a = a;
    B my_b = a2;

    bool isGreater = a==a2;

    cout << "isGreater? " << isGreater <<endl;

    return 0;
}
