/*
  author : Anand

    Problem 21
    This problem was asked by Snapchat.

    Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

    For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.
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

int getMinClassReqd(vector<pair<int, int> > intervals) {
    sort(intervals.begin(), intervals.end());
    multiset<int> endTimes;
    int ans = 0;
    for (auto interval : intervals) {
        ans = max(ans, (int)distance(endTimes.lower_bound(interval.first), endTimes.end()) + 1);
        endTimes.insert(interval.second);
    }
    return ans;
}

void solve() {
    assert(getMinClassReqd({}) == 0);
    assert(getMinClassReqd({{30, 75}, {0, 50}, {60, 150}}) == 2);
    assert(getMinClassReqd({{30, 75}, {0, 50}, {10, 60}, {60, 150}}) == 3);
    assert(getMinClassReqd({{60, 150}}) == 1);
    assert(getMinClassReqd({{60, 150}, {150, 70}}) == 2);
    assert(getMinClassReqd({{60, 150}, {60, 150}, {150, 70}}) == 3);
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