/*
    author : Anand
    You are given a string s containing lowercase English letters, and a matrix shift, where shift[i] = [direction, amount]:

    direction can be 0 (for left shift) or 1 (for right shift). 
    amount is the amount by which string s is to be shifted.
    A left shift by 1 means remove the first character of s and append it to the end.
    Similarly, a right shift by 1 means remove the last character of s and add it to the beginning.
    Return the final string after all operations.

    

    Example 1:

    Input: s = "abc", shift = [[0,1],[1,2]]
    Output: "cab"
    Explanation: 
    [0,1] means shift to left by 1. "abc" -> "bca"
    [1,2] means shift to right by 2. "bca" -> "cab"
    Example 2:

    Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
    Output: "efgabcd"
    Explanation:  
    [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
    [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
    [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
    [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"
    

    Constraints:

    1 <= s.length <= 100
    s only contains lower case English letters.
    1 <= shift.length <= 100
    shift[i].length == 2
    0 <= shift[i][0] <= 1
    0 <= shift[i][1] <= 100
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

string stringShift(string s, vector<vector<int>>& shift) {
    int n = s.length(), d = 0;
    for (auto s : shift) {
        d += (s[0] == 0 ? s[1] : -s[1]);
        d = (d + n) % n;
    }
    string ans;
    for (int i = d; i < n; i++)
        ans.push_back(s[i]);
    for (int i = 0; i < d; i++)
        ans.push_back(s[i]);
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