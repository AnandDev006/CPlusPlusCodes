/*
    author : Anand
    Given a binary tree of integers, find the maximum path sum between two nodes. 
    The path must go through at least one node, and does not need to go through the root.
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
    ll height;
    node* left;
    node* right;
    node( ll data) {
        this->data = data;
        height = -1;
        left = right = nullptr;
    }
};

ll height( node* root) {
    // leaf node
    if( root == nullptr) {
        return 0;
    }
    // previously visited ?
    if( root-> height != -1) {
        ++cacheRead;
        return root->height;
    }
    root->height = 1 + max( height( root->left), height( root->right));
    ++cacheWrite;
    return root->height;
}

ll maxPathSum( node* root) {
    if( root == nullptr) {
        return 0;
    }
    return max( height( root->left) + height( root->right) + 1, max( maxPathSum( root->left), maxPathSum( root->right) ));
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    node *root1 = new node(1);
    root1->left = new node(2);
    root1->left->left = new node(8);
    root1->right = new node(3);
    root1->right->left = new node(4);
    root1->right->right = new node(5);
    root1->right->left->right = new node(6);
    root1->right->right->right = new node(7);

    assert( maxPathSum( root1) == 6);

    return 0;
}