/*
  author : Anand

    Problem 36
    This problem was asked by Dropbox.

    Given the root to a binary search tree, find the second largest node in the tree.
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

struct Node {
    Node* left;
    Node* right;
    int data;
    Node(int _data) {
        left = right = nullptr;
        data = _data;
    }
};

void util(Node* root, int& k, int& ans) {
    if (root == nullptr || k <= 0)
        return;
    util(root->right, k, ans);
    --k;
    if (k == 0) {
        ans = root->data;
    }
    util(root->left, k, ans);
}

int getKthLargest(Node* root, int& k) {
    int ans;
    util(root, k, ans);
    return ans;
}

void solve() {
    int K = 2;
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