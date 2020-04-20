/*
    author : Anand
    Given an integer array arr, count element x such that x + 1 is also in arr.

    If there're duplicates in arr, count them seperately.

    

    Example 1:

    Input: arr = [1,2,3]
    Output: 2
    Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
    Example 2:

    Input: arr = [1,1,3,3,5,5,7,7]
    Output: 0
    Explanation: No numbers are counted, cause there's no 2, 4, 6, or 8 in arr.
    Example 3:

    Input: arr = [1,3,2,3,5,0]
    Output: 3
    Explanation: 0, 1 and 2 are counted cause 1, 2 and 3 are in arr.
    Example 4:

    Input: arr = [1,1,2,2]
    Output: 2
    Explanation: Two 1s are counted cause 2 is in arr.
    

    Constraints:

    1 <= arr.length <= 1000
    0 <= arr[i] <= 1000
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

int countElements(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int l = 0, r = 1, ans = 0;
    while (r < n) {
        if (arr[r] != arr[l]) {
            if (arr[r] == arr[l] + 1) {
                ans += r - l;
            }
            l = r;
        }
        r++;
    }
    return ans;
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