/*
    author : Anand
    Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.

    Note that after backspacing an empty text, the text will continue empty.

    Example 1:

    Input: S = "ab#c", T = "ad#c"
    Output: true
    Explanation: Both S and T become "ac".
    Example 2:

    Input: S = "ab##", T = "c#d#"
    Output: true
    Explanation: Both S and T become "".
    Example 3:

    Input: S = "a##c", T = "#a#c"
    Output: true
    Explanation: Both S and T become "c".
    Example 4:

    Input: S = "a#c", T = "b"
    Output: false
    Explanation: S becomes "c" while T becomes "b".
    Note:

    1 <= S.length <= 200
    1 <= T.length <= 200
    S and T only contain lowercase letters and '#' characters.
    Follow up:

    Can you solve it in O(N) time and O(1) space?
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

bool backspaceCompare(string S, string T) {
    int n1 = S.length(), n2 = T.length();
    int p1 = 0, p2 = 0;
    for (int i = 0; i < n1; ++i) {
        if (S[i] == '#') {
            p1 = max(p1 - 1, 0);
        } else {
            S[p1++] = S[i];
        }
    }
    for (int i = 0; i < n2; ++i) {
        if (T[i] == '#') {
            p2 = max(p2 - 1, 0);
        } else {
            T[p2++] = T[i];
        }
    }
    bool flag = p1 == p2;
    for (int i = 0; i < p1; ++i) {
        if (S[i] != T[i]) {
            flag = false;
            break;
        }
    }
    return flag;
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