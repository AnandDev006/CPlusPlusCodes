#include <bits/stdc++.h>

using namespace std;

struct node{
    int key;
    node *left;
    node *right;
};

node* createNewNode( int key){
    node* newNode = new node;
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

stack< int> pathToX( node *Root, int key){
    stack< int> blank;
    if( Root == NULL )
        return blank;
    if( Root->key == key ){
        blank.push( Root->key);
        return blank;
    }
    stack< int> leftPath = pathToX( Root->left, key);
    if( !leftPath.empty()){
        leftPath.push( Root->key);
        return leftPath;
    }
    stack< int> rightPath = pathToX( Root->right, key);
    if( rightPath.empty() ){
        rightPath.push( Root->key);
        return rightPath;
    }
    return blank;
}

int LCA( node *Root, int X, int Y){
    stack< int> pathY = pathToX( Root, Y);
    stack< int> pathX = pathToX( Root, X);
    int LCA = Root->key;
    while( pathX.top() == pathY.top() ){
        LCA = pathX.top();
        pathX.pop();
        pathY.pop();
    }
    return  LCA;
}

int main() {
    node* root = createNewNode( 1);
    root->left = createNewNode( 3);
    root->right = createNewNode( 2);
    root->left->left = createNewNode( 4);
    root->left->right = createNewNode( 6);
    root->left->right->left = createNewNode( 5);
    root->right = createNewNode( 2);
    cout << LCA( root, 4, 5) << endl;
    return 0;
}