/*
  author : Anand
  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2397
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}

template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#define LOCAL

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;


vector<int> tree;
vector<int> lazy;

int combine(int a, int b) { // as per type
    return a + b;
}

void push(int v, int len) {// as per type
    if (lazy[v] != INF)
        switch (lazy[v]) {
        case 0:
            tree[2 * v] = 0;
            tree[2 * v + 1] = 0;
            lazy[2 * v + 1] = lazy[v];
            lazy[2 * v + 2] = lazy[v];
            break;
        case 1:
            tree[2 * v] = len;
            tree[2 * v + 1] = len;
            lazy[2 * v + 1] = lazy[v];
            lazy[2 * v + 2] = lazy[v];
            break;
        case -1:
            tree[2 * v] = len - tree[2 * v];
            tree[2 * v + 1] = len - tree[2 * v + 1];
            lazy[2 * v + 1] = lazy[v];
            lazy[2 * v + 2] = lazy[v];
            break;

        }
    lazy[v] = INF;
}


void buildTree(const string &s, int v, int tl, int tr) {
    if ( tl == tr) {
        tree[v] = (s[tl] == '1' ? 1 : 0);  // as per type
    } else {
        int tm = tl + (tr - tl) / 2;

        buildTree(s, v * 2, tl, tm);
        buildTree(s, v * 2 + 1, tm + 1 , tr);

        tree[v] = combine( tree[2 * v], tree[2 * v + 1]);
    }
}

int getSegTreeData(int v, int tl, int tr, int ql, int qr) {
    if (ql > qr)
        return 0;

    if (ql <= tl && tr <= qr)
        return tree[v];

    push(v, (tr - tl + 1) / 2);

    int tm = tl + (tr - tl) / 2;

    int val = combine(getSegTreeData(v * 2, tl, tm, ql, min(qr, tm)),
                      getSegTreeData(v * 2 + 1, tm + 1, tr, max(ql, tm + 1), qr));

    return val;
}

void updateSegTreeData(int v, int tl, int tr, int ql, int qr, int op) {
    if ( ql > qr) return;

    if (ql == tl && qr == tr) {
        switch (op) {
        case 0:
            tree[v] = 0;
            break;
        case 1:
            tree[v] = (tr - tl + 1);
            break;
        case -1:
            tree[v] = (tr - tl + 1) - tree[v];
            break;

        }
        lazy[v] = op;
    } else {
        push(v, (tr - tl + 1) / 2);

        int tm = tl + (tr - tl) / 2;

        updateSegTreeData(v * 2, tl, tm, ql, min(qr, tm), op);
        updateSegTreeData(v * 2  + 1, tm + 1, tr, max(ql, tm + 1), qr, op);

        tree[v] = combine( tree[2 * v], tree[2 * v + 1]);
    }
    // debug(tree, v);
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.length();
        tree = vector<int>(4 * n, 0); // initialise as per merge operation
        lazy = vector<int>(4 * n, INF);

        buildTree(s, 1, 0, n - 1);

        debug(tree);

        int q;
        cin >> q;
        char op;
        int l , r;
        while (q--) {
            cin >> op >> l >> r;
            if ( op == 'S') {
                cout << getSegTreeData(1, 0, n - 1, l, r) << '\n';
            } else {
                updateSegTreeData(1, 0, n - 1, l, r, (op == 'I' ? -1 : (op == 'F' ? 1 : 0)));
            }
            debug(tree);
        }
    }





    return 0;
}