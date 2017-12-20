#include <bits/stdc++.h>

using namespace std;

string convert ( string x ){
    string s ;
    int num = 0 ;
    s.push_back( 65 + num++ );
    for (int i = 1 ; i < x.length() ; ++i ){
        if( x.rfind( x[i] , i - 1 ) != x.npos ){
            s.push_back( s[ x.rfind( x[i] , i - 1 ) ] ) ;
        }
        else
            s.push_back( 65 + num++ ) ;
    }
    return s ;
}

int main(){

    int n , q , l , r , count , length ;
    string S ;
    cin >> n >> q ;
    cin >> S ;
    while ( q-- ){
        count = 0 ;
        cin >> l >> r ;
        string subS = S.substr( l - 1, r - l + 1 ) ;
        length = subS.length();
        string x = convert( subS ) ;
        string y ;
        for( int i = 0 ; i < S.length() - length + 1 ; ++i ){
            y = convert( S.substr( i , length ) ) ;
            if( y.find( x , 0 ) !=y.npos )
                ++count ;
        }
        cout << count << endl ;
    }
    return 0;
}