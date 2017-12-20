#include <iostream>
#include <math.h>

/*#include <vector>
#include <conio.h>
*/
using namespace std ;

void print( long long l , long long k , long long m ){
    long long count , i = 1 , pos = 0 ;
    i = log2( k ) > 1 ? (long long)log2( k ) : 1 ;
    if( k == 0 ){
        cout << '(' ;
        ++k ;
        --m;
    }

    pos = (long long)pow(2,i) - 1 ;

    for( ; i < l ; ++i ){
        print( i , abs( (long long)pow(2,i) - 1 - k )  ,  ) ;
        pos += (long long)pow(2,i) ;
        k += count ;
        m -= count ;
    }

    if( k + m == (long long)pow(2,l) ){
        cout << ')' ;
    }
}

int main(){
    long long L , K , M ;
    cin >> L >> K >> M ;
    print( L , K , M );
    return 0 ;
}

///////////////////////////////////// TEMP = O(N^2) \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

/*
int main() {

    int l , k ,m ;
    cin >> l >> k >> m ;
    print( l , k , m ) ;
    vector<string> s ;
    string final ;
    while( l || k || m ) {
        s.clear() ;
        s.push_back("()") ;
        for ( int i = 1 ; i < l ; ++i ) {
            s.push_back("(") ;
            for ( int j = 0 ; j < i ; ++j )
                s[i] += s[j] ;
            s[i] += ")" ;
        }
        final = s[l - 1] ;
        for( int x = k ; x < k + m ; ++x )
            cout << final[x] ;
        cout << endl << s[l-1] << endl ;
        _getch() ;
        system("cls") ;
        cin >> ws ;
        cin >> l >> k >> m ;
    }
    return 0;
}*/