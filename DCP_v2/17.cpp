/*
  author : Anand

    Problem 17
    This problem was asked by Google.

    Suppose we represent our file system by a string in the following manner:

    The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

    dir
        subdir1
        subdir2
            file.ext
    The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

    The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

    dir
        subdir1
            file1.ext
            subsubdir1
        subdir2
            subsubdir2
                file2.ext
    The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file file2.ext.

    We are interested in finding the longest (number of characters) absolute path to a file within our file system. For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its length is 32 (not including the double quotes).

    Given a string representing the file system in the above format, return the length of the longest absolute path to a file in the abstracted file system. If there is no file in the system, return 0.
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

int findLongestPath(string s) {
    cout << s << endl;
    int pos = 0, n = s.size();
    vector<string> path(N);
    path[0] = "dir";
    pos = s.find("\n", pos + 1) + 1;

    int ans = 0;

    while (pos < n) {
        int len = 0;
        while (s[pos + len] == '\t') {
            ++len;
        }
        int l = pos + len;
        int r = s.find("\n", pos);
        if (r == -1) {
            r = n;
        }
        path[len] = s.substr(l, r - l);

        if (path[len].find(".ext") != -1) {
            int pathLen = 0;
            for (int i = 0; i <= len; ++i) {
                pathLen += (int)(path[i].size() + 1);
            }
            ans = max(ans, pathLen - 1);
        }
        pos = r + 1;
    }
    cout << ans << endl;
    return ans;
}

void solve() {
    assert(findLongestPath("dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext") == 32);
    assert(findLongestPath("dir\n\tsubdir1\n\tsubdir2") == 0);
    assert(findLongestPath("dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext") == 20);
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