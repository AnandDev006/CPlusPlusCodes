/*
  author : Anand

    Problem 20
    This problem was asked by Google.

    Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

    For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

    In this example, assume nodes with the same value are the exact same node objects.

    Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.
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

int findInterserction(deque<int> a, deque<int> b) {
    int lenA = 0, lenB = 0;
    auto it = a.begin();
    while (it != a.end()) {
        ++lenA;
        ++it;
    }
    it = b.begin();
    while (it != b.end()) {
        ++lenB;
        ++it;
    }
    auto headA = a.begin();
    auto headB = b.begin();
    if (lenA > lenB) {
        headA = a.begin() + (lenA - lenB);
    } else {
        headB = b.begin() + (lenB - lenA);
    }
    while (*headA != *headB) {
        ++headA;
        ++headB;
    }
    return *headA;
}

void solve() {
    assert(findInterserction({0, 3, 7, 8, 10}, {99, 1, 8, 10}) == 8);
    assert(findInterserction({7, 8, 10}, {99, 1, 8, 10}) == 8);
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