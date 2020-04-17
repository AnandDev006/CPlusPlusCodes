/*
    author : Anand
    Kosaraju - Strongly connected components

    7 10
    1 2
    1 4
    2 1
    2 5
    3 2
    3 7
    5 4
    6 3
    6 5
    7 6
*/

#include <bits/stdc++.h>
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

vector<int> g[N];
vector<int> g_rev[N];
vector<vector<int>> components;
int numOfComponents;
int DP[N];
stack<int> nodes;
vector<bool> visited(N);

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
        g_rev[v].pb(u);
    }
}

void dfs1(int u, int par) {
    for (int v : g[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        dfs1(v, u);
    }
    nodes.push(u);
}

template <typename T>
void printArray(const vector<T> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]\n";
}

void dfs2(int u, int par) {
    for (int v : g_rev[u]) {
        if (visited[v]) continue;
        visited[v] = true;
        components[numOfComponents - 1].push_back(v);
        dfs2(v, u);
    }
}

void kosaraju(int n, int m) {
    visited.resize(n + 1);
    fill(all(visited), false);
    for (int i = 1; i < n; ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        dfs1(i, -1);
    }

    fill(all(visited), false);

    while (!nodes.empty()) {
        int node = nodes.top();
        nodes.pop();
        if (visited[node])
            continue;

        visited[node] = true;
        components.pb({node});
        ++numOfComponents;
        dfs2(node, -1);
    }
    for (vector<int> comp : components) {
        for (int node : comp) {
            cout << node << " ";
        }
        cout << '\n';
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
    kosaraju(n, m);
    return 0;
}