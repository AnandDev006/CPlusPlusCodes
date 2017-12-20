#include <iostream>
#include <vector>

using namespace std ;

string f( vector<int>v , int N , int index ,int ans , string s ){
    if( ans !=0 && ans % 101 == 0 ){

    }
    return f( v , N , , , "+" ) + f( v , N , , , "*" ) + f( v , N , , , "-" ) ;
}

int main() {

    int N , t ;
    cin >> N ;
    vector<int> v ;

    for( int i = 0 ; i < N ; ++i ) {
        cin >> t ;
        v.push_back( t ) ;
    }
    string final = f( v , N , 0 , v[0] , to_string( v[0] ) ) ;

    return 0;
}