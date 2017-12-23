#include <bits/stdc++.h>

using namespace std;

auto cmp = []( int a, int b){
    bitset<64> bA = a;
    bitset<64> bB = b;
    if( bA.count() > bB.count() )
        return true;
    else if( bA.count() == bB.count() )
        return a > b ;
    else
        return false;
};

int main() {

    vector< int> V = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    sort( V.begin(), V.end(), cmp);
    for( int i = 0 ; i < V.size() ; ++i )
        cout << V[i] << endl;
    return 0;
}