/*
    author : Anand
    MST Prim
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

vpi g[N];
vector<pair<int, pi>> MST;
int DP[N];

void Prim(int n, int m) {
    priority_queue<pair<int, pi>> q;
    vector<bool> visited(n+1, false);
    vector<int> dist(n+1, INT_MAX);

    q.push({0,{1,1}});
    dist[1] = 0;

    while (!q.empty()) {
        auto e = q.top();
        q.pop();
        int u = e.S.S;

        if(visited[u]) continue;
        visited[u] = true;
        MST.pb({-e.F, e.S});

        for(auto E : g[u]) {
            int w = E.S;
            int v = E.F;

            if(dist[v] > w) {
                dist[v] = w;
                q.push({-w, {u, v}});
            }
        }
    }
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
    Prim(n,m);
    for( auto e : MST) {
        int a = e.S.F;
        int b = e.S.S;
        int w = e.F;
        printf("%d-%d : %d\n", a, b, w);
    }
    return 0;
}

int mpow(int base, int exp) {
    base %= mod;
    int result = 1;
    while (exp > 0) {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m) {
    int i, u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
}