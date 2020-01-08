/*
	author : Anand
    Given the root of a binary tree, return a deepest node
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

class node{
	public:

	ll data;
	node* left;
	node* right;
	
	node(ll data){
		this->data = data;
		this->left = this->right = nullptr;
	}
};



ll findDeepestNode( node* root) {
	queue< node* > Q;
	Q.push( root);
	node* deepestNode = nullptr;
	while( !Q.empty()){
		deepestNode = Q.front();
		Q.pop();
		if( deepestNode->left != nullptr) {
			Q.push( deepestNode->left);
		}
		if( deepestNode->right != nullptr) {
			Q.push( deepestNode->right);
		}
	}
	return deepestNode->data;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
	root->right->left->left = new node(10);

	assert( findDeepestNode( root) == 10 );

	return 0;
}