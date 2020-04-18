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

int dfs(const string& s, long k, int i, vector<int>& dp) {
    if (i == s.size()) return 1;  // base case -> Found a valid way
    if (s[i] == '0') return 0;    // all numbers are in range [1, k] and there are no leading zeros -> So numbers starting with 0 mean invalid!
    if (dp[i] != -1) return dp[i];
    int ans = 0;
    long num = 0;
    for (int j = i; j < s.size(); j++) {
        num = num * 10 + s[j] - '0';  // num is the value of the substring s[i..j]
        if (num > k) break;           // num must be in range [1, k]
        ans += dfs(s, k, j + 1, dp);
        ans %= 1000000007;
    }
    return dp[i] = ans;
}

int numberOfArrays(string s, int k) {
    vector<int> dp(s.size(), -1);  // dp[i] is number of ways to print valid arrays from string s start at i
    return dfs(s, k, 0, dp);
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