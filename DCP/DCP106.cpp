/*
    author : Anand

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

void printArray( const vector< ll > &arr) {
    cout << "[ ";
    for( ll i = 0 ; i < sz(arr) - 1; ++i ){
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

bool isReachable( vector< ll >  arr) {
    ll len = sz(arr);
    vector< ll > res ( len, 0);
    
    for( ll i = 0 ; i < len - 1 ; ++i) {
        if( arr[i] == 0 ) { 
            continue;
        }
        ++res[i + 1];
        if(  i + arr[i] + 1 < len ) {
            --res[i + arr[i] + 1];
        }
    }

    for( ll i = 1 ; i < len ; ++i ) {
        res[i] += res[i - 1];
    }
    return !(res[len-1] == 0);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( isReachable( vector< ll > { 2, 0, 1, 0} ) == true );
    assert( isReachable( vector< ll > { 1, 1, 0, 1} ) == false );

    return 0;
}