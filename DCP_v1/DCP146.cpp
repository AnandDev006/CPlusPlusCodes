/*
    author : Anand
    Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.

    For example, given the following tree:

       0
      / \
     1   0
        / \
       1   0
      / \
     0   0

    should be pruned to:

       0
      / \
     1   0
        /
       1
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
    ll data;
    Node(ll data){
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

bool filterTree(Node* root){

    if( root == nullptr ){
        return true;
    }

    bool left = filterTree(root->left);
    bool right = filterTree(root->right);

    if( left){
        root->left = nullptr;
    }

    if( right){
        root->right = nullptr;
    }

    return left && right && root->data == 0 ;

}

void printBFS(Node* root){
    queue< Node* > Q;
    Q.push(root);
    ll count = 1 ;
    while( !Q.empty()){
        Node* top = Q.front();
        Q.pop();
        if( count && ( !( count & ( count - 1 ) ) ) ){
            cout << endl;
        }
        ++count;

        if( top == nullptr ){
            continue;
        }

        cout << top->data << " ";
        Q.push( top->left);
        Q.push( top->right);
    }
    cout << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->right->right = new Node(0);
    root->right->left = new Node(1);
    root->right->left->left = new Node(0);
    root->right->left->right = new Node(0);

    printBFS(root);
    filterTree(root);
    printBFS(root);

    return 0;
}