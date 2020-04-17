/*
    author : Anand
    Tree Diameter
7 6
1 2
1 3
1 4
2 5
2 6
4 7
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
void dfs_calcMaxLens(int u, int par);
void dfs_getFarthestNode(int u, int par, int dist, pi &node);

vector<int> g[N];
int DP[N];
int toLeaf[N][2];
int maxLen[N];

int getDiameter1() {
    dfs_calcMaxLens(1, -1);
    return maxLen[1];
}

int getDiameter2() {
    pi farthestNode = {0, 1};  // dist , node
    dfs_getFarthestNode(1, -1, 0, farthestNode);
    dfs_getFarthestNode(farthestNode.S, -1, 0, farthestNode = {0, farthestNode.S});
    return farthestNode.F;
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
    // int diameter = getDiameter1();
    int diameter = getDiameter2();
    cout << diameter << '\n';
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

void dfs_calcMaxLens(int u, int par) {
    toLeaf[u][0] = 0;
    toLeaf[u][1] = 0;
    for (int v : g[u]) {
        if (v == par) continue;
        dfs_calcMaxLens(v, u);
        if (toLeaf[u][0] < 1 + toLeaf[v][0]) {
            toLeaf[u][1] = toLeaf[u][0];
            toLeaf[u][0] = 1 + toLeaf[v][0];
        } else if (toLeaf[u][1] < 1 + toLeaf[v][0]) {
            toLeaf[u][1] = 1 + toLeaf[v][0];
        }
    }
    maxLen[u] = toLeaf[u][0] + toLeaf[u][1];
}

void dfs_getFarthestNode(int u, int par, int dist, pi &node) {
    if (node.F < dist) {
        node = {dist, u};
    }
    for (int v : g[u]) {
        if (v == par) continue;
        dfs_getFarthestNode(v, u, dist + 1, node);
    }
}