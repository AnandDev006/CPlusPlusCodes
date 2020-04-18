/*
    author : Anand

*/

#include <bits/stdc++.h>

// #include <math.h>

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <utility>
// #include <vector>

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

string getHappyString(int n, int k) {
    /* 
            max K for given n
            since 1st place can be filled in 3 ways and all other spots in 2 ways, 3 * 2 * ... 
        */
    if (k > 3 * pow(2, n - 1)) {
        return "";
    }

    string s;
    int x = pow(2, n - 1);
    char c = 'a';
    int len = 0;

    while (len < n) {
        int diff = (k - 1) / x;
        s.push_back((len > 0 && (c + diff) == s[len - 1]) ? (c + diff + 1) : c + diff);
        ++len;
        if (c + diff == 'a') {
            c = 'b';
        } else {
            c = 'a';
        }
        k -= (diff * x);
        x /= 2;
    }
    return s;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}