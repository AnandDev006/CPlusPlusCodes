/*
    author : Anand
    We have a collection of stones, each stone has a positive integer weight.

    Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

    If x == y, both stones are totally destroyed;
    If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
    At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

    

    Example 1:

    Input: [2,7,4,1,8,1]
    Output: 1
    Explanation: 
    We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
    we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
    we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
    we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
    

    Note:

    1 <= stones.length <= 30
    1 <= stones[i] <= 1000
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
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define PI 3.1415926535897932384626

using namespace std;

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

int DP[N];

int lastStoneWeight_multiset(vector<int>& stones) {
    multiset<int, greater<int>> s;
    for (int x : stones) {
        s.insert(x);
    }
    auto pop_max = [&]() {
        int x = *s.begin();
        s.erase(s.begin());
        return x;
    };
    while ((int)s.size() > 1) {
        int a = pop_max();
        int b = pop_max();
        s.insert(abs(a - b));
    }
    if ((int)s.size() == 0) {
        return 0;
    } else {
        return pop_max();
    }
}

int lastStoneWeight_priorityQ(vector<int>& stones) {
    priority_queue<int> q;
    for (int x : stones) {
        q.push(x);
    }
    auto popTop = [&]() {
        int x = q.top();
        q.pop();
        return x;
    };
    while ((int)q.size() > 1) {
        int a = popTop();
        int b = popTop();
        q.push(abs(a - b));
    }
    if ((int)q.size() == 0) {
        return 0;
    } else {
        return popTop();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> q;
    q.t

        return 0;
}