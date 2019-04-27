/*
    author : Anand
    You are in an infinite 2D grid where you can move in any of the 8 directions.
    You are given a sequence of points and the order in which you need to cover the points.
    Give the minimum number of steps in which you can achieve it. You start from the first point.

    for only horizontal and vertical movement dist(a,b) = MANHATTAN DISTANCE = abs( a.x - b.x) + abs( a.y - b.y)
    for horizontal, vertical and diagonal movement dist( a, b) = max( abs( a.x - b.x), abs( a.y - b.y))s
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair(a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;

ll getDist( const vector< pair< ll, ll > > &input ) {
    if( sz( input) == 0 ) {
        return 0;
    }
    ll distanceSum = 0;
    for( ll i = 1 ; i < sz(input) ; ++i) {
        distanceSum += max( abs( input[i].X - input[i - 1].X ), abs( input[i].Y - input[i - 1].Y ) );
    }
    return distanceSum;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( getDist( vector< pair< ll, ll > > ( { { 0, 0}, { 1, 1}, { 1, 2} } ) ) == 2 );
    assert( getDist( vector< pair< ll, ll > > ( { { 2, 1}, { 4, 4}, { 7, 2} } ) ) == 6 );

    return 0;
}