/*
  author : Anand

    Problem 29
    This problem was asked by Amazon.

    Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

    Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of alphabetic characters. You can assume the string to be decoded is valid.
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

string encode(string s) {
    string e = "";
    int n = s.size();
    char prev = s[0];
    int curCnt = 1;
    for (int i = 1; i < n; ++i) {
        if (s[i] == prev) {
            ++curCnt;
        } else {
            e += to_string(curCnt) + prev;
            curCnt = 1;
            prev = s[i];
        }
    }
    e += to_string(curCnt) + prev;
    return e;
}

string decode(string s) {
    string d = "";
    int cnt;
    char c;
    int n = s.size();
    int pos = 0;
    while (pos < n) {
        int len = 0;
        while (!isalpha(s[pos + len])) {
            ++len;
        }
        cnt = stoi(s.substr(pos, len));
        c = s[pos + len];
        while (cnt--) {
            d += c;
        }
        pos += len + 1;
    }
    return d;
}

void solve() {
    assert(encode("AAAABBBCCDAA") == "4A3B2C1D2A");
    assert(decode("4A3B2C1D2A") == "AAAABBBCCDAA");
    assert( decode(encode("AAAABBBCCDAA")) == "AAAABBBCCDAA" );
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