/*
Given the root to a binary search tree, find the second largest node in the tree.
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

struct node{
    int data;
    node* left;
    node* right;
}

void find_Kth_Largest(node* root, int k, int &count){
    if( root == null || count == k )
        return;
    find_Kth_Largest( root->right, k, count);
    
    if( count == k )
        return;

    ++count;

    if( count == k ){
        cout << root->data << endl;
        return;
    }
    
    find_Kth_Largest( root->left, k, count);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
    
    return 0;
}