/*
	author : Anand
	a) Given a tree, find the largest tree/subtree that is a BST.
	b) Given a tree, return the size of the largest tree/subtree that is a BST.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair(a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;

class node {
	public:
	ll data;
	node* left;
	node* right;
	node( ll data) {
		this->data = data;
		this->left = this->right = nullptr;
	}
};

unordered_map< node*, pair< bool, ll > > memoTable;

pair< bool, ll > isBST( node* root, ll low = INT_MIN, ll high = INT_MAX) {

	if( memoTable.find( root) != memoTable.end()) {
		return memoTable[root];
	}
	if( root == nullptr) {
		return mp(true, 0);
	}

	pair< bool, ll> left = isBST( root->left, low, root->data);
	pair< bool, ll> right = isBST( root->right, root->data, high);

	bool isValid = root->data > low && root->data < high && left.X && right.X ;
	ll size = 1 + left.Y + right.Y ;
	memoTable[root]  = mp( isValid, size);
	return mp( isValid, size);
}

void findLargestBST( node* root) {
	pair< node*, ll > maxBST = mp( nullptr, 0);

	queue< node* > Q;
	Q.push( root);
	while( !Q.empty()) {
		node* tmp = Q.front();
		Q.pop();
		pair< bool, ll > res = isBST( tmp);
		if( res.X && res.Y > maxBST.Y) {
			maxBST = mp( tmp, res.Y);
		}
		if( res.X == false && res.Y > maxBST.Y ) {
			Q.push( tmp->left);
			Q.push( tmp->right);
		}
	}
	cout << maxBST.X->data << " : " << maxBST.Y << endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *root1 = new node(5);
    root1->left = new node(2);
    root1->right = new node(1);
    root1->left->left = new node(1);
    root1->left->right = new node(3);
    root1->right->right = new node(9);
    root1->right->right->left = new node(8);
    root1->right->right->right = new node(12);
    root1->right->right->right->left = new node(10);

	node *root2 = new node(5);
    root2->left = new node(2);
    root2->right = new node(8);
    root2->left->left = new node(1);
    root2->left->right = new node(3);
    root2->right->left = new node(7);
    root2->right->right = new node(9);

	findLargestBST( root1);
	findLargestBST( root2);

	return 0;
}