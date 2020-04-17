/*
    author : Anand
    DisjointSet with path compression
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
int DP[N];

template <typename T>
class Node {
    public:
    T data;
    int rank;
    Node* parent;
    Node(T data) {
        this->data = data;
        this->rank = 0;
        this->parent = this;
    }
};

template <typename T>
class DisjointSet {
    unordered_map<int, Node<T>*> hashMap;
    public:
    DisjointSet(const vector<T> &arr) {
        for(T x: arr){
            makeSet(x);
        }
    }
    void makeSet(T data) {
        Node<T>* newNode = new Node<T>(data);
        hashMap[data] = newNode;
    }
    Node<T>* findSet(T data) {
        Node<T>* node = hashMap[data];
        if(node == node->parent) return node;
        node->parent = findSet(node->parent->data);
        return node->parent;
    }
    bool unionSet(T a, T b) {
        Node<T>* Pa = findSet(a);
        Node<T>* Pb = findSet(b);
        if(Pa == Pb) return false;
        if(Pa->rank == Pb->rank)
            ++(Pb->rank);
        else if (Pa->rank > Pb->rank)
            swap(Pa, Pb);
        Pa->parent = Pb;
        return true;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> inputArr({1,2,3,4,5,6,7});
    DisjointSet<int> d(inputArr);

    d.unionSet(1,2);
    d.unionSet(1,3);
    d.unionSet(4,5);
    d.unionSet(5,6);
    d.unionSet(6,7);
    d.unionSet(7,3);
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