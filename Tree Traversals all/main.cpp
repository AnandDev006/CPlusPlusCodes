// In Order

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

void preOrderRec( node *root){
    if( root == NULL)
        return;
    cout << root->data << endl;
    preOrderRec( root->left);
    preOrderRec( root->right);
}

void preOrderIter( node* root){
    stack< node*> st;
    st.push( root);
    while( !st.empty()){
        node* temp = st.top();
        st.pop();
        cout << temp->data << endl;
        if( temp->right != NULL)
            st.push( temp->right);
        if( temp->left != NULL)
            st.push( temp->left);
    }
}

void inOrderRec( node* root){
    if( root == NULL)
        return;
    inOrderRec( root->left);
    cout << root->data << endl;
    inOrderRec( root->right);
}

void inOrderIter( node* root){
    stack< node*> st;
    node* curr = root;

    while( curr != NULL || !st.empty()){
        while( curr != NULL){
            st.push( curr);
            curr = curr->left;
        }
        
        curr = st.top();
        st.pop();

        cout << curr->data << endl;

        curr = curr->right;
    }
}


void postOrderRec( node* root){
    if( root == NULL)
        return;
    postOrderRec( root->left);
    postOrderRec( root->right);
    cout << root->data << endl;
}

void postOrderIter( node* root){
    stack< node*> st1, st2;
    st1.push( root);
    while( !st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push( temp);
        if( temp->left != NULL )
            st1.push( temp->left);
        if( temp->right != NULL)
            st1.push( temp->right);

    }
    while( !st2.empty() ){
        cout << st2.top()->data << endl;
        st2.pop();
    }
}

void bf( node* root){
    cout << root->left->data << endl;
    cout << root->right->data << endl;
    
}

void breadthFirstRec( node* root){
    cout << root->data << endl;
    bf( root);
}

void breadthFirstIter( node* root){
    queue< node*> Q;
    Q.push(root);
    while( !Q.empty()){
        node* temp = Q.front();
        Q.pop();
        cout << temp->data << endl;
        if( temp->left != NULL )
            Q.push( temp->left);
        if( temp->right != NULL)
            Q.push( temp->right);
    }
}

int main(){

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    cout << "PREORDER" << endl;
    preOrderRec(root);
    cout << endl;
    preOrderIter(root);
    cout << endl;

    cout << "INORDER" << endl;
    inOrderRec(root);
    cout << endl;
    inOrderIter(root);
    cout << endl;

    cout << "POSTORDER" << endl;
    postOrderRec(root);
    cout << endl;
    postOrderIter(root);
    cout << endl;

    cout << "BREADTH FIRST" << endl;
    breadthFirstRec(root);
    cout << endl;
    breadthFirstIter(root);
    cout << endl;

    cin.get();
    return 0;
}