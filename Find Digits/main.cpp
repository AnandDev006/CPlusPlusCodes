#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t , d , count , n , *p;
    cin >> t;
    p = new int [t];
    for( int a0 = 0 , d = 0 ; a0 < t; a0++ ){
        cin >> p[a0];
        n=p[a0];
        for( count = 0 ; n > 0 ; n/=10 ){
            d = n%10;
            if ( d!=0 && ( p[a0] % d ) == 0 )
                ++count;
        }

        cout<< count << endl ;

    }

    delete(p);

    return 0;
}