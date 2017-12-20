#include <iostream>
#include <queue>

using namespace std ;

template <class T>
class BSTNode{
    int key ;
    T data ;
    BSTNode * left ;
    BSTNode * right ;
public:
    BSTNode(){} ;
    BSTNode * Get_New_Node( int , T ) ;
    BSTNode * Insert ( BSTNode * , int , T ) ;
    BSTNode * Search ( BSTNode * , int ) ;
    BSTNode * Find_Min( BSTNode * ) ;
    BSTNode * Find_Max( BSTNode * ) ;
    int BSTNode_Height( BSTNode * ) ;
    int BSTNode_Depth( BSTNode * , int ) ;
    bool Is_BST( BSTNode * , int min = INT32_MIN , int max = INT32_MAX ) ;
    BSTNode * Delete( BSTNode * , int  ) ;
    BSTNode * Get_Successor( BSTNode * , int ) ;
    void Breadth_First( BSTNode * ) ;
    void DF_Pre_Order( BSTNode * ) ;
    void DF_In_Order( BSTNode * ) ;
    void DF_Post_Order( BSTNode * ) ;
    void Depth_First( BSTNode * ) ;
};

template <class T>
BSTNode < T > * BSTNode < T > :: Get_New_Node( int key , T data ){
    BSTNode * new_node = new BSTNode ;
    new_node->key = key ;
    new_node->data = data ;
    new_node->left = new_node->right = NULL ;
    return new_node ;
}

template <class T>
BSTNode < T >  * BSTNode < T > :: Insert ( BSTNode * root , int key , T data ){
    if( root == NULL )
        root = Get_New_Node( key , data ) ;
    else if ( key < root->key )
        root->left = Insert( root->left , key ,data );
    else
        root->right = Insert( root->right , key , data ) ;
    return root ;
}

template <class T>
BSTNode < T > * BSTNode < T > :: Search ( BSTNode * root , int key ){
    if( root == NULL )
        return NULL ;
    else if ( key == root->key )
        return root ;
    else if( key < root->key )
        return Search( root->left , key ) ;
    else
        return Search( root->right , key ) ;
}

template <class T>
BSTNode < T > * BSTNode < T > :: Find_Min( BSTNode * root ){
    while( root->left )
        root = root->left ;
    return root ;
}

template <class T>
BSTNode < T > * BSTNode < T > ::  Find_Max( BSTNode * root ){
    while( root->right )
        root = root->right ;
    return root ;
}

template <class T>
int BSTNode < T > :: BSTNode_Height( BSTNode * root ){
    if( root == NULL )
        return -1 ;
    T lH = BSTNode_Height( root->left ) + 1 ;
    T rH = BSTNode_Height( root->right ) + 1 ;
    if( lH > rH )
        return lH ;
    else
        return rH ;
}

template <class T>
int BSTNode < T > :: BSTNode_Depth( BSTNode * root , int key ){
    if( root->key == key )
        return 0 ;
    else if( key < root->key && root->left != NULL )
        return BSTNode_Depth( root->left , key ) + 1 ;
    else if ( key > root->key && root->right != NULL )
        return BSTNode_Depth( root->right , key ) + 1 ;
}

template <class T>
bool BSTNode < T > :: Is_BST( BSTNode * root , int min , int max ){
    if( root == NULL )
        return true ;
    if( root->key < max && root->key > min && Is_BST( root->left , min , root->key ) && Is_BST( root->right , root->key , max ) )
        return true ;
    else
        return false ;
}

template <class T>
BSTNode < T > * BSTNode < T > ::  Delete( BSTNode * root , int key ){
    if( root == NULL )
        return NULL ;
    else if( key < root->key )
        root->left = Delete( root->left , key ) ;
    else if( key > root->key )
        root->right = Delete( root->right , key ) ;
    else{
        if( root->left == NULL && root->right == NULL ){
            delete root ;
            root = NULL ;
        }
        else if( root->left == NULL ){
            BSTNode * temp = root ;
            root = root->right ;
            delete temp ;
            temp = NULL ;
        }
        else if( root->right == NULL ){
            BSTNode * temp = root ;
            root = root->right ;
            delete temp ;
            temp = NULL ;
        }
        else{
            BSTNode * temp = Find_Min( root->right ) ;
            root->key = temp->key ;
            root->data = temp->data ;
            root->right = Delete( root->right , temp->key ) ;
            temp = NULL ;
        }
    }
    return root ;
}

template <class T>
BSTNode < T > * BSTNode < T > ::  Get_Successor( BSTNode * root , int key ){
    BSTNode * current = Search( root , key ) ;
    if( current == NULL )
        return NULL ;
    if( current->right != NULL )
        return Find_Min( current->right ) ;
    else{
        BSTNode * successor = NULL ;
        BSTNode * ancestor = root ;
        while( ancestor != current ) {
            if (current->key < ancestor->key) {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
                ancestor = ancestor->right;
        }
        return successor ;
    }
}

template <class T>
void BSTNode < T > :: Breadth_First( BSTNode * root ){
    if( root == NULL )
        return ;
    cout << endl ;
    queue < BSTNode * > Q ;
    Q.push( root ) ;
    while ( !Q.empty() ){
        BSTNode * current = Q.front() ;
        cout << " | " << current->data ;
        if( current->left )
            Q.push( current->left ) ;
        if( current->right )
            Q.push( current->right ) ;
        Q.pop() ;
    }
}

template <class T>
void BSTNode < T > :: DF_Pre_Order( BSTNode * root ){
    if( root == NULL )
        return ;
    cout << " | " << root->data ;
    DF_Pre_Order( root->left ) ;
    DF_Pre_Order( root->right ) ;
}

template <class T>
void BSTNode < T > :: DF_In_Order( BSTNode * root ){
    if( root == NULL )
        return ;
    DF_In_Order( root->left ) ;
    cout << " | " << root->data ;
    DF_In_Order( root->right ) ;
}

template <class T>
void BSTNode < T > :: DF_Post_Order( BSTNode * root ){
    if( root == NULL )
        return ;
    DF_Post_Order( root->left ) ;
    DF_Post_Order( root->right ) ;
    cout << "| " << root->data ;
}

template <class T>
void BSTNode < T > :: Depth_First( BSTNode * root ){
    T opt ;
    cin >> opt ;
    cout << endl ;
    if( opt == 1 )
        DF_Pre_Order( root );
    else if( opt == 2 )
        DF_In_Order( root ) ;
    else if( opt == 3 )
        DF_Post_Order( root ) ;
    else
        cout << endl << " Wrong Input " << endl ;
}

int main(){
    return 1;
}