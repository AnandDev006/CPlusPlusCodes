#include <bits/stdc++.h>

using namespace std;

int counter ;

long long fast_exp( int b, int p){
    ++counter ;
    if( p == 0 )
        return 1;
    else if( b == 0 )
        return 0;
    else if( b == 1 )
        return 1;
    else{
        long long R = fast_exp( b, p/2);
        if( p % 2 == 0 )
            return R*R;
        else
            return R*b*R;
    }
}

int main() {
    cout << fast_exp( 2, 10) << endl << counter;
    return 0;
}