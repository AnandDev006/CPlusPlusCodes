/*
    author : Anand
    Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.

    For example, the inorder successor of 22 is 30.

        10
       /  \
      5    30
          /  \
        22    35
    You can assume each node has a parent pointer.
    HERE DONE WITHOUT PARENT POINTER
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
typedef pair< ll, ll > ii;

class Node{
    public:
    Node* left;
    Node* right;
    ll data = 0;
    Node( ll data) {
        this->left = this->right = nullptr;
        this->data = data;
    }
};

void printArray(const vector<ll> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

Node* findNode(Node* root, ll data){
    if(root == nullptr){
        return nullptr;
    }
    if( data == root->data ){
        return root;
    } else if( data < root->data ){
        return findNode(root->left, data);
    } else {
        return findNode(root->right, data);
    }
}

Node* smallest( Node* root) {
    while( root->left != nullptr){ 
        root = root->left;
    }
    return root;
}

Node* findInOrderSuccessor(Node* root, ll data) {
    Node* dataNode = findNode(root, data);
    if( dataNode->right != nullptr) {
        return smallest(dataNode->right);
    }
    Node* predecessor = root;
    Node* node = root;
    while( node != dataNode ){
        if( node->data < dataNode->data && node->right != nullptr ) {
            node = node->right;
        } else if( node->data > dataNode->data && node->left != nullptr ) {
            predecessor = node;
            node = node->left;
        }
    }
    return predecessor;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(22);
    root->right->right = new Node(35);

    assert( findInOrderSuccessor(root, 10)->data == 22);
    assert( findInOrderSuccessor(root, 5)->data == 10);
    assert( findInOrderSuccessor(root, 30)->data == 35);
    assert( findInOrderSuccessor(root, 22)->data == 30);
    assert( findInOrderSuccessor(root, 35)->data == 10);

    return 0;
}