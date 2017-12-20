#include <iostream>
#include <vector>
#include <set>

using namespace std ;

int main() {

    vector<int> v ;
    set<int> presum ;
    int n , m ;
    int x ;
    int maxim = 0 , sum = 0 ;
    cin >> n >> m ;
    presum.insert( 0 ) ;

    for( int i = 0 ; i < n ; ++i ){
        cin >> x ;
        sum = ( sum + x ) % m ;
        maxim = max( maxim , sum ) ;
        auto it = presum.lower_bound( sum + 1 ) ;
        if( it != presum.end() )
            maxim = max( maxim , ( sum - *it + m ) % m ) ;
        presum.insert( sum ) ;
    }
    cout << maxim ;

    return 0;
}