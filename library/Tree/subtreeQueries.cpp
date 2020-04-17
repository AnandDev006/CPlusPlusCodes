/*
    author : Anand
    subtree queries
*/

// #include <bits/stdc++.h>
#include <math.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

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
unordered_map<int, int> nodeWeight;
unordered_map<int, pi> table;
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
    int i, u, v, w;
    while (m--) {
        cin >> u >> v;
        g[u].pb(v);
    }
    while (n--) {
        cin >> u >> w;
        nodeWeight[u] = w;
    }
}

void dfs(int u, int par, vector<int> &inputArr) {
    inputArr.pb(nodeWeight[u]);
    table[u] = {sz(inputArr) - 1, 1};
    for (int v : g[u]) {
        if (v == par) continue;
        dfs(v, u, inputArr);
        table[u].S += table[v].S;
    }
}

template <typename T>
class SegmentTree {
    vector<T> tree;
    int treeLen;

   public:
    SegmentTree(const vector<T> &inputArr) {
        int inputArrLen = sz(inputArr);
        this->treeLen = 2 * pow(2, int(ceil(log2(inputArrLen)))) - 1;

        this->tree = vector<T>(this->treeLen, 0);  // initialise as per merge operation

        for (int i = inputArrLen - 1; i >= 0; --i) {
            this->tree[this->treeLen / 2 + i] = inputArr[i];
        }

        for (int i = (this->treeLen / 2) - 1; i >= 0; --i) {
            // create tree nodes based on tree type ( sum, min, max ....)
            this->tree[i] = this->tree[2 * i + 1] + this->tree[2 * i + 2];
        }
    }
    T getSegTreeData(int a, int b) {
        a += this->treeLen / 2;
        b += this->treeLen / 2;
        if (a >= this->treeLen || b < 0) return 0;
        if (a < 0) a = 0;
        if (b >= this->treeLen) b = this->treeLen - 1;

        // initialise based on tree type ( sum, min, max ....)
        T result = 0;
        while (a <= b) {
            // if right node on left pointer, take value and move right
            if (a % 2 == 0) result += this->tree[a++];

            // if left node on right pointer, take value and move left
            if (b % 2 == 1) result += this->tree[b--];

            // go to parent
            a = (a - 1) / 2;
            b = (b - 1) / 2;
        }
        return result;
    }
    void updateSegTreeData(T val, int pos) {
        pos += this->treeLen / 2;
        if (pos < 0 || pos >= this->treeLen) return;

        this->tree[pos] += val;
        for (int i = pos / 2; i >= 1; i /= 2) {
            // update logic based on tree type ( sum, min, max ....)
            this->tree[i] = this->tree[2 * i + 1] + this->tree[2 * i + 2];
        }
    }
};

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
    vector<int> inputArr;
    dfs(1, -1, inputArr);
    SegmentTree<int> tree(inputArr);
    cout << tree.getSegTreeData(table[2].F, table[2].F + table[2].S - 1) << '\n';

    return 0;
}