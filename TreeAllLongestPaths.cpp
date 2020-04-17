/*
    author : Anand
    Logest path from all nodes
6 5
1 2
1 3
1 4
2 5
2 6
*/

#include <bits/stdc++.h>

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

const int mod = 1000000007;
const double zero = 10e-9;
const int N = 3e5, M = N;

int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

vector<int> g[N];
pi maxLen[N][2];
int DP[N];

void dfs_getFarthestNodeDistanceThroughChild(int u, int par) {
    maxLen[u][0] = {0, -1};
    maxLen[u][1] = {0, -1};
    for (int v : g[u]) {
        if (v == par) continue;
        dfs_getFarthestNodeDistanceThroughChild(v, u);
        if (maxLen[u][0].F <= 1 + maxLen[v][0].F) {
            maxLen[u][1] = maxLen[u][0];
            maxLen[u][0] = {1 + maxLen[v][0].F, v};
        } else if (maxLen[u][1].F < 1 + maxLen[v][0].F) {
            maxLen[u][1] = {1 + maxLen[v][0].F, v};
        }
    }
}

void dfs_getFarthestNodeDistanceThroughParent(int u, int par) {
    if (par != -1) {
        if (maxLen[u][0].F < 1 + maxLen[par][0].F) {
            if (maxLen[par][0].S == u) {
                if (maxLen[u][0].F < 1 + maxLen[par][1].F) {
                    maxLen[u][0] = {1 + maxLen[par][1].F, par};
                }
            } else {
                maxLen[u][0] = {1 + maxLen[par][0].F, par};
            }
        }
    }
    for (int v : g[u]) {
        if (v == par) continue;
        dfs_getFarthestNodeDistanceThroughParent(v, u);
    }
}
void calcAllLongestPaths() {
    dfs_getFarthestNodeDistanceThroughChild(1, -1);
    dfs_getFarthestNodeDistanceThroughParent(1, -1);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    ipgraph(n, m);
    calcAllLongestPaths();
    for (int i = 1; i <= n; ++i) {
        printf("Node : %d, maxDist : %d\n", i, maxLen[i][0].F);
    }

    return 0;
}

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
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par) {
    for (int v : g[u]) {
        if (v == par) continue;
        dfs(v, u);
    }
}