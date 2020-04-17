/*
    author : Anand
    Binary Indexed Tree / Fenwick Tree
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

template <typename T>
class BIT {
    vector<T> tree;
    int p(int k) { return (k & (-k)); };

   public:
    BIT(const vector<T>& arr) {
        int arrLen = sz(arr);
        this->tree = vector<T>(arrLen + 1, 0);
        for (int i = 0; i < arrLen; ++i) {
            updateBIT(arr[i], i);
        }
    }
    void updateBIT(int val, int idx) {
        ++idx;
        if (idx >= sz(this->tree)) return;

        while (idx <= sz(this->tree)) {
            (this->tree)[idx] += val;
            idx += p(idx);
        }
    }
    T getBITSum(int idx) {
        ++idx;
        if (idx >= sz(this->tree)) idx = sz(this->tree) - 1;

        T sum = 0;
        while (idx > 0) {
            sum += (this->tree)[idx];
            idx -= p(idx);
        }
        return sum;
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vi inputArr({1, 2, 3, 4, 5});
    BIT<int> tree(inputArr);
    cout << tree.getBITSum(5) << '\n';
    tree.updateBIT(3, 2);
    cout << tree.getBITSum(5) << '\n';
    tree.updateBIT(3, 4);
    cout << tree.getBITSum(5) << '\n';

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