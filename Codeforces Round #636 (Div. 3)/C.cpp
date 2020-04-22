#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define pwp(x, y) fixed << setprecision(y) << x
#define PI 3.1415926535897932384626

using namespace std;

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void FIO() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);
}

int main() {
    FIO();
    
    int t;
    cin >> t;
    while(t--) {
    	int n;
    	cin >> n;
    	vector<ll> arr(n);
    	for (int i = 0; i < n; ++i)
    	{
    		cin >> arr[i];
    	}
    	ll m = -INF;
    	ll sum = 0;
    	for (int i = 0; i < n; ++i)
    	{
    		if( i != 0 && ((arr[i] ^ arr[i-1]) < 0)) {
    			sum += m;
    			m = arr[i];
    		} else {
    			m = max(m, arr[i]);
    		}
    	}
    	sum += m;
    	cout << sum << '\n';
    }

    return 0;
}