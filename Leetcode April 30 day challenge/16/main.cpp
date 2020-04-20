/*
    author : Anand
    Given a string containing only three types of characters: '(', ')' and '*', write a function to check 
    whether this string is valid. We define the validity of a string by these rules:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
    An empty string is also valid.
    Example 1:
    Input: "()"
    Output: True
    Example 2:
    Input: "(*)"
    Output: True
    Example 3:
    Input: "(*))"
    Output: True
    Note:
    The string size will be in the range [1, 100].
*/

// #include <bits/stdc++.h>

#include <math.h>

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

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

bool checkValidString(string s) {
    int count = 0;
    for (char c : s) {
        if (c == '(' || c == '*')
            count++;
        else if (count > 0)
            count--;
        else
            return false;
    }
    reverse(s.begin(), s.end());
    count = 0;
    for (char c : s) {
        if (c == ')' || c == '*')
            count++;
        else if (count > 0)
            count--;
        else
            return false;
    }
    return true;
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