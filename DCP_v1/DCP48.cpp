/*

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g

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

struct Node { 
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char data) { 
    struct Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

struct Node* buildTree(char in[], char pre[], int inStrt, int inEnd, unordered_map<char, int>& mp) {
    static int preIndex = 0;

    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Preorder traversal using preIndex
    and increment preIndex */
    int curr = pre[preIndex++];
    struct Node* tNode = newNode(curr);
  
    /* If this node has no children then return */
    if (inStrt == inEnd)
        return tNode;
  
    /* Else find the index of this node in Inorder traversal */
    int inIndex = mp[curr]; 
  
    /* Using index in Inorder traversal, construct left and  
    right subtress */
    tNode->left = buildTree(in, pre, inStrt, inIndex - 1, mp);
    tNode->right = buildTree(in, pre, inIndex + 1, inEnd, mp);
  
    return tNode; 
} 

struct Node* buldTreeWrap(char in[], char pre[], int len) {

    unordered_map<char, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;

    return buildTree(in, pre, 0, len - 1, mp);
} 

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<char> preOrder =  {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
    vector<char> inOrder = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};

    struct Node* root = buldTreeWrap(in, pre, len);
    
    return 0;
}