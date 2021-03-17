/*
  author : Anand
*/

#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct Node{
	Node *left, *right;
	ll data;
	Node(ll _data) : left(nullptr), right(nullptr), data(_data) {}
};

int getLongestPathSum(Node *node, ll &longestPathSum) {
	if(!node) return 0;
	
	ll L = getLongestPathSum(node->left, longestPathSum);
	ll R = getLongestPathSum(node->right, longestPathSum);
	
	ll sum1 = max(node->data, max(L, R) + node->data);
	ll sum2 = max(sum1, L + R + node->data);
	
	longestPathSum = max(longestPathSum, sum2);
	
	return sum1;
}

void solve(int tc = 1) {
	ll longestPathSum = LLONG_MIN;
	Node *root = new Node(-10);
	root->left = new Node(9);
	root->right = new Node(20);
	root->right->left = new Node(15);
	root->right->right = new Node(7);
	
	getLongestPathSum(root, longestPathSum);
	cout << longestPathSum << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; ++t) solve(t);

  return 0;
}