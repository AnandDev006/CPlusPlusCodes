/*
    author : Anand
    Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

    (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

    You are given a target value to search. If found in the array return its index, otherwise return -1.

    You may assume no duplicate exists in the array.

    Your algorithm's runtime complexity must be in the order of O(log n).

    Example 1:

    Input: nums = [4,5,6,7,0,1,2], target = 0
    Output: 4
    Example 2:

    Input: nums = [4,5,6,7,0,1,2], target = 3
    Output: -1
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

int search(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0)
        return -1;
    int low = 0, high = n - 1;
    int first = nums[0];
    bool targetBig = target >= first;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int value = nums[mid];
        bool valueBig = value >= first;
        if (valueBig == targetBig) {
            if (value == target)
                return mid;
            else if (value < target)
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            if (targetBig)
                high = mid - 1;
            else
                low = mid + 1;
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}