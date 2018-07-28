#include <bits/stdc++.h>

using namespace std;

/*
        Solution logic

        1) The 2 given strings can be valid for swapping/have a solution
           only if
            - length of both strings are same.
            - count of 1s and 0s in both strings are same.
            - count of wrongly matched positions is even.
              ( internal swapping requires even number of errors)
        2) For each swap 2 positions get corrected, therefore solution is half of the number
           of worngly placed bits.
           To calculate wrong placed bits, we use binary XOR operation.
*/

int main(){

    string A, B;
    cin >> A >> ws >> B;

    bitset<1000007> a(A), b(B);
    bitset<1000007> xorVal = a.to_ulong() ^ b.to_ulong();

    if( A.length() == B.length() && a.count() == b.count() && xorVal.count() % 2 == 0){

        cout << xorVal.count() / 2 << endl;
    }
    else                            // no solution
        cout << -1 << endl;
    
    return 0;
}