/*
    author : Anand
    Given a list of points, a central point, and an integer k, find the nearest k points from the central point.

    For example, given the list of points [(0, 0), (5, 4), (3, 1)], the central point (1, 2), and k = 2, return [(0, 0), (3, 1)].
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
typedef pair< ll, ll > ii;

void printArray(const vector< pair< ll, ll> > &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << "( " << arr[i].X << ", " << arr[i].Y << "), ";
    }
    cout << "( " << arr[sz(arr) - 1].X << ", " << arr[sz(arr) - 1].Y << ")" << " ]" << endl;
}

template<typename T>
bool isEqual(std::vector<T> const &v1, std::vector<T> const &v2)
{
    auto pair = std::mismatch(v1.begin(), v1.end(), v2.begin());
    return (pair.first == v1.end() && pair.second == v2.end());
}

vector< pair< ll, ll> > getClosestKPoints( const vector< pair< ll, ll> > &points, pair< ll, ll > centre, ll k){
    vector< pair< ll, pair< ll, ll> > > pointsByDistance;
    ll distance;

    for( auto point : points ){
        distance = (point.X - centre.X) * (point.X - centre.X) + (point.Y - centre.Y) * (point.Y - centre.Y) ;
        pointsByDistance.push_back( mp( distance, point) );
    }

    sort( all( pointsByDistance ) );

    vector< pair< ll, ll> > closestKPoints;
    for( ll i = 0 ; i < k ; ++i){
        closestKPoints.push_back( pointsByDistance[i].second );
    }
    printArray( closestKPoints);

    return closestKPoints;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( isEqual( getClosestKPoints( vector< pair< ll, ll> >({ { 0, 0}, { 5, 4}, {3, 1} }), { 1, 2}, 2 ) , vector< pair< ll, ll> >({ {0,0}, {3,1} }) ) );

    return 0;
}