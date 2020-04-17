/*
    author : Anand
    find kth ancestor
    9 8
    1 2
    1 3
    1 4
    1 5
    2 6
    4 7
    4 8
    4 9
*/

#include <bits/stdc++.h>
// #include <iostream>
// #include <math.h>
// #include <algorithm>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <vector>

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
const int N = 10, M = N;

vector<int> g[N];
vector<vector<int>> ancestor(N, vector<int>(N, 0));
int DP[N];

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

void ipgraph(int n, int m) {
    int i, u, v;
    while (m--) {
        cin >> u >> v;
        ancestor[v][0] = u;
        g[u].pb(v);
    }
}

void precalcAncestors(int n, int m) {
    for (int i = 1; i < (int)log2(n) + 1; ++i) {
        for (int node = 1; node <= n; ++node) {
            ancestor[node][i] = ancestor[ancestor[node][i - 1]][i - 1];
        }
    }
}

int getAncestor(int node, int level) {
    while (level > 0) {
        node = ancestor[node][(int)log2(level)];
        level -= (int)pow(2, (int)log2(level));
    }
    return node;
}

int main() {
// #ifndef ONLINE_JUDGE
//     freopen("main.inp", "r", stdin);
//     freopen("main.out", "w", stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    ipgraph(n, m);

    precalcAncestors(n, m);

    cout << getAncestor(6, 2) << '\n';

    return 0;
}