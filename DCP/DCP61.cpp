/*
 author : Anand
 Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y 
 are integers and returns x^y.

 Do this faster than the naive method of repeated multiplication.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

ll count = 0;

ll fastExponentiation( ll base, ll power) {
    ++::count;
    if( power == 1 ) { 
        return base;
    }

    ll halfPowered = fastExponentiation( base, power / 2 );
    halfPowered *= halfPowered;
    if( power % 2 == 0 ) {
        return halfPowered;
    } else {
        return halfPowered * base;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll base, power;
    cin >> base >> power;
    cout << fastExponentiation( base, power) << endl << ::count << endl;

    return 0;
}