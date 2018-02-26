#include <iostream>
#include <vector>

using namespace std;

vector<int> polynomialDerivative(const vector<int>& original_poly){
    //if polynomial has degree 0 i.e. is a constant, then its derivative is 0
    if(original_poly.size() == 1)
        return {0};

    int poly_order = original_poly.size() - 1;
    vector<int> derivative_poly;
    //ensure vector capacity is at least enough to contain "poly_order" elements
    derivative_poly.reserve(poly_order);

    //for each term of the polynomial, EXCEPT the last,
    //multiply its coefficient by its exponent
    for(auto itr = original_poly.cbegin(); itr != original_poly.cend()-1; ++itr){
        derivative_poly.push_back( (*itr)*poly_order );
        poly_order--;
    }

    return derivative_poly;
}

struct testCase{
    vector<int> polynomial;
    vector<int> derivative;
};

int main(){
    vector<testCase> inputs{
                                { {1}, {0} }, // d/dx(1) = 0
                                { {1,0}, {1} }, // d/dx(x) = 1
                                { {1,0,0}, {2, 0} }, // d/dx(x^2) = 2x
                                { {1,0,1,3,0,10}, {5,0,3,6,0} } // d/dx(x^5+x^3+3x^2+10) = 5x^4+3x^2+6x
                            };

    for(const auto &test : inputs){
        //operator== is defined for vectors
        if(polynomialDerivative(test.polynomial) == test.derivative)
            cout << "OK" <<endl;
        else
            cout << "PROBLEM" <<endl;
    }

    return 0;
}
