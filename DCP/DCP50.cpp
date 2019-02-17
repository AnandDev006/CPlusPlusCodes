/*

Suppose an arithmetic expression is given as a binary tree. Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5

You should return 45, as it is (3 + 2) * (4 + 5).

*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

inline void debug(){
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
}

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

class node{
    public:
    node* left;
    node* right;
    string data;

    node( string data){
        left = right = NULL;
        this->data = data;
    }
};

ll calc(node* root){
    
    if( root->left == NULL && root->right == NULL)
        return stoi(root->data);
    
    ll left = calc( root->left);
    ll right = calc( root->right);
    ll result;
    switch( root->data[0]){
        case '+':
            result = left + right;
            break;
        case '-':
            result = left - right;
            break;
        case '*':
            result = left * right;
            break;
        case '/':
            result = left / right;
            break;
    }
    return result;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    node* root = new node("*");
    root->left = new node("+");
    root->right = new node("+");
    root->left->left = new node("3");
    root->left->right = new node("2");
    root->right->left = new node("4");
    root->right->right = new node("5");

    cout << calc( root) << endl;
    
    return 0;
}