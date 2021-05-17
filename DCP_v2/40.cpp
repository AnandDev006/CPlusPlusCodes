/*
  author : Anand

  Problem 40
  This problem was asked by Google.

  Given an array of integers where every integer occurs three times except for one integer, which only occurs once, find and return the non-duplicated integer.

  For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

  Do this in O(N) time and O(1) space.
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

int getSolo(vector<int> v) {
    int ans = 0;
    int n = v.size();
    for (int i = 0; i < 64; ++i) {
        int mask = 1 << i;
        int bitPosCnt = 0;
        for (int j = 0; j < n; ++j) {
            if (v[j] & mask) {
                ++bitPosCnt;
            }
        }

        if (bitPosCnt % 3 != 0) {
            ans |= mask;
        }
    }
    return ans;
}

void solve() {
    assert(getSolo({6, 1, 3, 3, 3, 6, 6}) == 1);
    assert(getSolo({13, 13, 13, 19}) == 19);
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