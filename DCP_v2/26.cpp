/*
  author : Anand

    Problem 26
    This problem was asked by Google.

    Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

    The list is very long, so making more than one pass is prohibitively expensive.

    Do this in constant space and in one pass.
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

int removeKthFromLast(list<int> l, int k) {
    auto head = l.begin();
    auto temp = head;
    auto res = head;
    for (int i = 0; i < k; ++i) {
        ++temp;
    }
    while (true) {
        ++temp;
        if (temp == l.end()) {
            break;
        }
        ++res;
    }
    return *res;
}

void solve() {
    assert(removeKthFromLast({0, 3, 7, 8, 10}, 1) == 8);
    assert(removeKthFromLast({0, 3, 7, 8, 10}, 2) == 7);
    assert(removeKthFromLast({0, 3, 7, 8, 10}, 3) == 3);
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