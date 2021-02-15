/*
  author : Anand

    Problem 35
    This problem was asked by Google.

    Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

    Do this in linear time and in-place.

    For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
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

vector<char> RGB(vector<char> v) {
    int n = v.size();
    int insPos = 0, curPos = 0;
    while (curPos < n) {
        if (v[curPos] == 'R') {
            swap(v[insPos++], v[curPos]);
        }
        ++curPos;
    }
    curPos = insPos;
    while (curPos < n) {
        if (v[curPos] == 'G') {
            swap(v[insPos++], v[curPos]);
        }
        ++curPos;
    }
    return v;
}

template <typename T>
bool isVectorEqual(vector<T> v1, vector<T> v2) { return v1 == v2; }

void solve() {
    assert(isVectorEqual(RGB({'G', 'B', 'R', 'R', 'B', 'R', 'G'}), {'R', 'R', 'R', 'G', 'G', 'B', 'B'}));
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