// https://codeforces.com/contest/1027/problem/C
// Minimum Value Rectangle 

#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second

using namespace std;

ll cnt[10010];

int main(){

    ll T;
    cin >> T;

    while( T--){
        memset( cnt, 0, sizeof(ll));
        ll n;
        cin >> n;
        set<ll> valid, input;
        valid.clear();
        input.clear();
        while( n--){
            ll x;
            cin >> x;
            input.insert(x);
            ++cnt[x] ;
        }

        // find all edges which can be used as side of rectangle
        for( auto x : input )
            if( cnt[x] >= 2)
                valid.insert( x);

        // worst case answer edges are as different as possible hence min = 1 and max = 1e5
        pair<int,int> res = { 1, 1e5};

        for( set<ll>::iterator it = valid.begin() ; it != valid.end() ; ++it){
            ll x = *it;
            // perimeter/area is max for square
            if( cnt[x] >= 4){
                res = make_pair( x, x);
                break;
            }

            // if 1st edge
            if( it == valid.begin())
                continue;

            set<ll>::iterator it2 = it;
            --it2;
            ll y = *it2;

            // if to have value minimal, then for given sides a & b, a has to be
            // as close to b as possible
            // check if current x y pair better than result
            if( ( ( x*x + 2*x*y + y*y ) * res.F * res.S  ) < ( res.F*res.F + 2*res.F*res.S + res.S*res.S ) * x * y )
                res = make_pair( x, y);
        }

        cout << res.F << ' ' << res.F << ' ' << res.S << ' ' << res.S << '\n';

    }

    return 0;
}