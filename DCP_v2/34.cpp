/*
  author : Anand

    Problem 34
    This problem was asked by Quora.

    Given a string, find the palindrome that can be made by inserting the fewest number of characters as possible anywhere in the word. If there is more than one palindrome of minimum length that can be made, return the lexicographically earliest one (the first one alphabetically).

    For example, given the string "race", you should return "ecarace", since we can add three letters to it (which is the smallest amount to make a palindrome). There are seven other palindromes that can be made from "race" by adding three letters, but "ecarace" comes first alphabetically.

    As another example, given the string "google", you should return "elgoogle".


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

bool isPalindrome(string s) {
    return s == string(s.rbegin(), s.rend());
}

string getNearestPalindrome(string s) {
    int n = s.size();
    if (isPalindrome(s)) return s;
    if (s[0] == s[n - 1]) {
        return s[0] + getNearestPalindrome(s.substr(1, n - 2)) + s[n - 1];
    } else {
        string a = s[0] + getNearestPalindrome(s.substr(1)) + s[0];
        string b = s[n - 1] + getNearestPalindrome(s.substr(0, n - 1)) + s[n - 1];
        int len1 = a.size();
        int len2 = b.size();
        if (len1 < len2) return a;
        if (len2 < len1) return b;
        return min(a, b);
    }
}

void solve() {
    assert(getNearestPalindrome("race") == "ecarace");
    assert(getNearestPalindrome("google") == "elgoogle");
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