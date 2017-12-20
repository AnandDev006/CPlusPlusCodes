#include <bits/stdc++.h>

using namespace std;

map< list< int>, long long> table;
int N , K;

long long calcBadness( list< int> S) {
    long long bad = 0;
    for( auto i = S.begin(); i != S.end() ; ++i)
        for( auto j = i ; j != S.end() ; ++j )
            bad += abs( *i - *j );
    return bad;
}

long long AC2( list< int> candies, list< int> pick) {

    if( pick.size() == K ) {
        if( table.find( pick) != table.end() )
            table[pick] = calcBadness( pick);
        return table[pick];
    }

    long long minim = INT64_MAX;

    for( auto n = candies.begin(); n != candies.end() ; ++n ) {
        candies.erase( n);
        pick.push_back( *n);
        minim = min(minim, AC2( candies, pick));
        pick.pop_back();
        candies.insert( n, *n);
    }
    return minim;
}

int main() {
    cin >> N;
    cin >> K;
    list< int> candies;
    int x;
    for( int i = 0 ; i < N; ++i) {
        cin >> x;
        candies.push_back( x);
    }
    set< int> pick;
    AC2( candies, pick);
    return 0;
}