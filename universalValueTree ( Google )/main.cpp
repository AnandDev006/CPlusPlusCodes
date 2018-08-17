// Number of universal value trees
// https://www.youtube.com/watch?v=7HgsS8bRvjo

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    node* left;
    node* right;
    int data;

    node( int data){
        left = right = NULL;
        this->data = data;
    }
};

pair< bool, int> is_uniValCheck( node* root){
    if( root == NULL)
        return make_pair( true, 0);

    bool is_uniVal = true;

    pair< bool, int> leftUniVal = is_uniValCheck( root->left);
    pair< bool, int> rightUniVal = is_uniValCheck( root->right);

    if( !leftUniVal.first || !rightUniVal.first )
        is_uniVal = false;    
    if( root->left != NULL && root->data != root->left->data)
        is_uniVal = false;
    if( root->right != NULL && root->data != root->right->data)
        is_uniVal = false;
    if( is_uniVal)
        return make_pair( true, leftUniVal.second + rightUniVal.second + 1);
    else
        return make_pair( false, leftUniVal.second + rightUniVal.second );

            

}

int main(){

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(2);
    root->left->right = new node(2);
    root->right->left = new node(3);
    root->right->right = new node(3);

    cout << is_uniValCheck(root).second << endl;

    cin.get();
    return 0;
}