/*
    author : Anand
    Range Min Query Sparse table
*/

#include <bits/stdc++.h>
// #include <math.h>

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <set>
// #include <map>
// #include <algorithm>

#define sz(a) int((a).size())
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int INF = 1e9 + 5;
const int mod = 1000000007;
const double zero = 10e-9;
const int N = 3e5, M = N;

int DP[N];
vector<int> _log(N + 1);
vector<vector<int>> st(N, vector<int>((int)log2(N) + 1));

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void precompute(const vector<int> &arr) {
    int n = sz(arr);
    int k = log2(n) + 1;
    _log.resize(n + 1);
    st.resize(n + 1);

    _log[1] = 0;

    for (int i = 2; i <= n; i++)
        _log[i] = _log[i / 2] + 1;

    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    for (int j = 1; j <= k; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}

int getMin(int l, int r) {
    int j = _log[r - l + 1];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    precompute({1, 2, 3, 2, 3, 4, 3, 2, 1, 2, 1, 2, 3, 2, 1});

    cout << getMin(4, 6) << '\n';

    return 0;
}