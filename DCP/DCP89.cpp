/*
	author : Anand
	Determine whether a tree is a valid binary search tree.
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

bool isBST(node* root, ll low = INT_MIN, ll high = INT_MAX) {
	if( root == nullptr)
		return true;

	return (root->data < high && root->data > low && isBST( root->left, low, root->data) && isBST( root->right, root->data, high));
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(4);
    root1->left->right = new node(5);
    root1->right->left = new node(6);
    root1->right->right = new node(7);

	node *root2 = new node(5);
    root2->left = new node(2);
    root2->right = new node(8);
    root2->left->left = new node(1);
    root2->left->right = new node(3);
    root2->right->left = new node(6);
    root2->right->right = new node(9);

	assert( isBST( root1) == false);
	assert( isBST( root2) == true);

	return 0;
}