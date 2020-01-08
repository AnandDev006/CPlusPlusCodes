/*
    author : Anand
    This question was asked by Apple.

    Given a binary tree, find a minimum path sum from root to a leaf.

    For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.

        10
       /  \
      5    5
      \     \
       2    1
           /
        - 1
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

void helper(Node* root, vector<ll> path, ll sum, vector<ll> &minPath, ll &minSum){
    if( root == nullptr){
        return;
    }

    path.push_back(root->data);
    sum += root->data;

    if( root->left == nullptr && root->right == nullptr) {
        if( sum < minSum ) {
            minSum = sum;
            minPath = path;
        }
        return;
    }

    helper( root->left, path, sum, minPath, minSum);
    helper( root->right, path, sum, minPath, minSum);
    path.pop_back();
    sum -= root->data;
}

ll findMinimumPathSum( Node* root) {
    
    vector<ll> path, minPath;
    ll sum = 0, minSum = INT_MAX;
    helper( root, path, sum, minPath, minSum );
    printArray( minPath);
    cout << minSum << endl;
    return minSum;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(5);
    root->left->right = new Node(2);
    root->right->right = new Node(1);
    root->right->right->left = new Node(-1);

    assert( findMinimumPathSum(root) == 15 );

    return 0;
}