/*
    author : Anand
    Find the minimum number of coins required to make n cents.
    You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.
    For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.
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

void printArray(const vector<ll> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

ll findMinNumCoinsRequired( ll n){
    vector< ll > givenCoinSet = { 25, 10, 5, 1 };
    ll numOfCoinsReqd = 0;
    for( ll coin : givenCoinSet) {
        numOfCoinsReqd += ( n / coin );
        n %= coin;
        if( n == 0 )
            break;
    }
    cout << numOfCoinsReqd << endl;
    return numOfCoinsReqd;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( findMinNumCoinsRequired(16) == 3 );

    return 0;
}