#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
}

vector<vector<int>> g;

void bfs(int s, vector<int> &d) {
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (d[v] == INF) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void solve() {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    --a; --b; --c;

    vector<int> p(m);
    for (int &x : p) cin >> x;
    sort(p.begin(), p.end());
    vector<int> pref(m + 1, 0);
    for (int i = 0 ; i < m; ++i)
        pref[i + 1] = pref[i] + p[i];

    g = vector<vector<int>> (n);
    for (int i = 0; i < m ; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> da(n, INF), db(n, INF), dc(n, INF);
    bfs(a, da);
    bfs(b, db);
    bfs(c, dc);

    ll ans = INF;
    for ( int i = 0 ; i < n ; ++i) {
        if ( da[i] + db[i] + dc[i] > m ) continue;
        ans = min( ans, pref[db[i]] + pref[da[i] + db[i] + dc[i]]);
    }
    cout << ans << '\n';
}

signed main() {
    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}