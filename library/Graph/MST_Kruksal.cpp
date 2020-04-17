/*
    author : Anand
    MST Kruksal
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

vector<pair<int, pi>> g; // edgeList
vector<pair<int, pi>> MST; // edgeList
int DP[N];
int link[N];
int set_size[N];

void initUnionFindSet(int n) {
    for( int i = 1 ; i <= n ; ++i ) {
        link[i] = i;
        set_size[i] = 1;
    }
}

int find(int x) {
    while( x != link[x]) x = link[x];
    return x;
}

int same(int a, int b) {
    return find(a) == find(b);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if(set_size[a] < set_size[b]) swap(a,b);
    set_size[a] += set_size[b];
    link[b] = a;
}

void kruksal(int m) {
    sort(g.begin(), g.begin() + m, [](pair<int, pi> a, pair<int, pi> b) { return a.F < b.F; });
    for( auto e : g) {
        int a = e.S.F;
        int b = e.S.S;
        int w = e.F;
        if (!same(a, b)) {
            unite(a, b);
            MST.pb({w, {a, b}});
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
    initUnionFindSet(n);
    kruksal(m);
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
        g.push_back({w, {u, v}});
    }
}