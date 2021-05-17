/*
  author : Anand

    Problem 30
    You are given an array of non-negative integers that represents a two-dimensional elevation map where each element is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

    Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

    For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

    Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index (we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.
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

int waterTrapped(vector<int> v) {
    int n = v.size();
    int lo = 0, hi = n - 1;
    int lMax = 0, rMax = 0;
    int res = 0;
    while (lo <= hi) {
        if (v[lo] < v[hi]) {
            if (v[lo] > lMax) {
                lMax = v[lo];
            } else {
                res += lMax - v[lo];
            }
            ++lo;
        } else {
            if (v[hi] > rMax) {
                rMax = v[hi];
            } else {
                res += rMax - v[hi];
            }
            --hi;
        }
    }
    return res;
}

void solve() {
    assert( waterTrapped({2,1,2}) == 1 );
    assert( waterTrapped({3, 0, 1, 3, 0, 5}) == 8 );
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