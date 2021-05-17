/*
  author : Anand

    Problem 8
	This problem was asked by Google.

	A unival tree (which stands for "universal value") is a tree where all nodes under it have the same value.

	Given the root to a binary tree, count the number of unival subtrees.

	For example, the following tree has 5 unival subtrees:

	   0
	  / \
	 1   0
	    / \
	   1   0
	  / \
	 1   1
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
		data = _data;
	}
};

struct Res {
	int val;
	bool isUnival;
	int cnt;
};

Res cnt_unival(Node* root) {
	if(!root) return {-1, true, 0};
	bool isUnival = false;
	int cnt = 0;

	Res leftTree = cnt_unival(root->left);
	Res rightTree = cnt_unival(root->right);
	
	cnt = leftTree.cnt + rightTree.cnt;
	if((leftTree.val == root->data || leftTree.val == -1) && (rightTree.val == root->data || rightTree.val == -1) && leftTree.isUnival && rightTree.isUnival) {
		isUnival = true;
		cnt += 1;
	}

	return {root->data, isUnival, cnt};
}

void solve() {
  Node* root = new Node(0);
  root->left = new Node(1);
  root->right = new Node(0);
  root->right->left = new Node(1);
  root->right->right = new Node(0);
  root->right->left->left = new Node(1);
  root->right->left->right = new Node(1);
  assert(cnt_unival(root).cnt == 5);
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