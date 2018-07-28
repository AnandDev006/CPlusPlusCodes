#include <bits/stdc++.h>

using namespace std;

/*
        Solution Logic

        1) For any differential number system based on number N, the count of
           unique numbers with i digits is given by N raised to i.
        2) For any natural numbers n and x,
           n power x is strictly greater than sum of all powers of n less than x.
        3) From (1) and (2) we also see that the index N of any number can be seen as the
           summation of a GP + random number ( less than the next sequence of the GP ).
            N = GP_sum + randomNum
            N <= GP_sum
            solving this equation gives us the max GP power as
            power = floor( log( 2*N + 1) base 3 )
            the max GP power here corresponds to the number of digits in the number
            as per (1)
*/

int main(){

    int X, Y;
    cin >> X;

    while( X--){

        cin >> Y;

        Y = 2*Y + 1;
        Y = int( float( log(Y) ) / float( log(3) ) );
        
        cout << Y << endl;
    }
    return 0;
}