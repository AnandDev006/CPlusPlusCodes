/*
  author : Anand

    Problem 37
    This problem was asked by Google.

    The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

    For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

    You may also use a list or array to represent a set.
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t" << #__VA_ARGS__ << " : " << (__VA_ARGS__) << endl;
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

void getPowerSet(vector<int> v, int n, vector<int> &cur, int pos = 0) {
    if (pos == n) {
        cout << cur.size() << " : { ";
        for (int x : cur) {
            cout << x << ", ";
        }
        cout << "}\n";
        return;
    }
    cur.push_back(v[pos]);
    getPowerSet(v, n, cur, pos + 1);
    cur.pop_back();
    getPowerSet(v, n, cur, pos + 1);
}

void solve() {
    vector<int> v({1, 2, 3});
    vector<int> cur;
    getPowerSet(v, v.size(), cur);
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}