a /*
    author : Anand
    Bellman Ford Algo
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
void dijkstra(int x, int n);

vpi g[N];
int parent[N] = {-1};
int dist[N];
int DP[N];

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
    dijkstra(1, n);
    for (int i = 1; i <= n; ++i) {
        cout << i << " : " << dist[i] << '\n';
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
    int i, u, v, w;
    while (m--) {
        cin >> u >> v >> w;
        g[u].pb({v, w});
        g[v].pb({u, w});  // undirected
    }
}

void dijkstra(int x, int n) {
    bool processed[n + 1];
    for (int i = 1; i <= n; ++i) {
        processed[i] = false;
        dist[i] = INT_MAX;
    }

    priority_queue<pi> q;
    q.push({0, x});
    dist[x] = 0;

    while (!q.empty()) {
        int a = q.top().S;
        q.pop();
        if (processed[a]) continue;
        for (auto v : g[a]) {
            int b = v.F;
            int w = v.S;
            if (dist[a] != INT_MAX && w != INT_MAX && dist[b] > dist[a] + w) {
                dist[b] = dist[a] + w;
                parent[b] = a;
                q.push({-dist[b], b});
            }
        }
        processed[a] = true;
    }
}
