/*
    author : Anand
    Graph
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
void bfs(int u);

vector<int> g[N];
bool visited[N];
int parent[N] = {-1};
int DP[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

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

void dfs(int u, int par = -1) {
    for (int v : g[u]) {
        if (v == par) continue;
        visited[v] = true;
        parent[v] = u;
        dfs(v, u);
    }
}

void bfs(int u) {
    queue<int> Q;
    Q.push(u);
    while (!Q.empty()) {
        int p = Q.front();
        Q.pop();
        for (int v : g[p]) {
            if (v == p) continue;
            visited[v] = true;
            parent[v] = p;
            Q.push(v);
        }
    }
}
