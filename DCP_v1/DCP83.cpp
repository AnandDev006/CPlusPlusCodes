/*
	author : Anand
    Invert a binary tree.
    swap( left, right);
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

node* invertTree( node* root) {
	queue < node* > Q;
	Q.push( root);
	while( !Q.empty()) {
		node* top = Q.front();
		Q.pop();
		if( top->left != nullptr) {
			Q.push( top->left);
		}
		if( top->right != nullptr) {
			Q.push( top->right);
		}
		swap( top->left, top->right);
	}
	return root;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node* root = new node(1);
	root->left = new node(2);
	root->right = new node(3);
	root->left->left = new node(4);
	root->left->right = new node(5);
	root->right->left = new node(6);

	root = invertTree( root);

	assert( root->left->data == 3);
	assert( root->left->right->data == 6);
	assert( root->right->data == 2);
	assert( root->right->left->data == 5);

	return 0;
}