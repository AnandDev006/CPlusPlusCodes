/*
  author : Anand

    Problem 27
    This problem was asked by Facebook.

    Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

    For example, given the string "([])", you should return true.

    Given the string "([)]" or "((()", you should return false.
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

bool bracketBalance(string s) {
    stack<char> b;
    for (char c : s) {
        if (c == '(')
            b.push('(');
        else if (c == '[')
            b.push('[');
        else if (c == ')' && !b.empty() && b.top() == '(')
            b.pop();
        else if (c == ']' && !b.empty() && b.top() == '[')
            b.pop();
        else
            return false;
    }
    return b.empty();
}

void solve() {
    assert(bracketBalance("([])"));
    assert(!bracketBalance("([)]"));
    assert(!bracketBalance("((()"));
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