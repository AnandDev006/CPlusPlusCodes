/*
  author : Anand

    Problem 18
    This problem was asked by Google.

    Given an array of integers and a number k, where 1 <= k <= length of the array, compute the maximum values of each subarray of length k.

    For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

    10 = max(10, 5, 2)
    7 = max(5, 2, 7)
    8 = max(2, 7, 8)
    8 = max(7, 8, 7)
    Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not need to store the results. You can simply print them out as you compute them.
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

vector<int> getMaxInWindows(vector<int> v, int k) {
    int n = v.size();
    deque<int> maxs;
    int pos;
    while (pos < k) {
        while (!maxs.empty() && maxs.back() < v[pos]) {
            maxs.pop_back();
        }
        maxs.push_back(v[pos++]);
    }
    vector<int> ans;
    while (pos < n) {
        ans.push_back(maxs.front());
        if (maxs.front() == v[pos - k]) {
            maxs.pop_front();
        }
        while (!maxs.empty() && maxs.back() < v[pos]) {
            maxs.pop_back();
        }
        maxs.push_back(v[pos++]);
    }
    ans.push_back(maxs.front());
    return ans;
}

template <typename T>
bool isVectorEqual(vector<T> v1, vector<T> v2) { return v1 == v2; }

void solve() {
    assert(isVectorEqual(getMaxInWindows({10, 5, 2, 7, 8, 7}, 3), {10, 7, 8, 8}));
    assert(isVectorEqual(getMaxInWindows({5, 2, 1}, 2), {5, 2}));
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