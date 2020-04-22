/*
    author : Anand

*/

#include <bits/stdc++.h>

// #include <math.h>

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <utility>
// #include <vector>

#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define PI 3.1415926535897932384626
#define pp(x, y) fixed << setprecision(y) << x

using namespace std;

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

int DP[N];

void FIO() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    FIO();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int low = 1, high = log2(n);
        int p = 4;
        for (int i = 0; i < (int)(log2(n) + 1); i++) {
            if (n % (p - 1) == 0) {
                break;
            }
            p *= 2;
        }
        cout << n / (p - 1) << '\n';
    }

    return 0;
}