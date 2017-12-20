//
// Created by Anand on 22-07-2017.
//

#include <iostream>
#include <queue>
#include "AVL.h"

BSTNode::BSTNode(){ left = right = parent = nullptr ; height = key = -1 ; }

BSTNode * BST ::GetNewNode( int data , BSTNode * parent ) {
    auto * temp = new BSTNode ;
    temp->right = nullptr ;
    temp->left = nullptr ;
    temp->parent = parent ;
    temp->height = 0 ;
    temp->key = data ;
    return temp ;
}

int BST :: height ( BSTNode * node ){
    if( node == nullptr )
        return -1 ;
    return node->height ;
}

int BST :: update_height( BSTNode * node ) {
    node->height = 1 + ( height( node->left ) > height( node->right ) ? height( node->left ) : height( node->right ) ) ;
}

void BST :: left_rotate( BSTNode * x ){
    BSTNode * y = x->right ;
    y->parent = x->parent ;
    if( y->parent == nullptr )
        root = y ;
    else
    if ( y->parent->left == x )
        y->parent->left = y ;
    else if ( y->parent->right == x )
        y->parent->right = y ;
    x->right = y->left ;
    if( x->right != nullptr )
        x->right->parent = x ;
    y->left = x ;
    x->parent = y ;
    update_height( x ) ;
    update_height( y ) ;
}

void BST :: right_rotate( BSTNode * x ) {
    BSTNode * y = x->left ;
    y->parent = x->parent ;
    if ( y->parent == nullptr )
        root = y ;
    else
    if( y->parent->left == x )
        y->parent->left = y ;
    else if ( y->parent->right == x )
        y->parent->right = y ;
    x->left = y->right ;
    if( x->left != nullptr )
        x->left->parent = x ;
    y->right = x ;
    x->parent = y ;
    update_height( x ) ;
    update_height( y ) ;
}

void BST :: rebalance ( BSTNode * node ){
    while ( node != nullptr ){
        update_height( node ) ;
        if ( height( node->left ) >= 2 + height( node->right ) )
            if( height( node->left->left ) >= height( node->left->right ) )
                right_rotate( node ) ;
            else{
                left_rotate( node->left ) ;
                right_rotate( node ) ;
            }
        else if ( height( node->right ) >= 2 + height( node->left ) )
            if( height( node->right->right) >= height( node->right->left ) )
                left_rotate( node ) ;
            else{
                right_rotate( node->right ) ;
                left_rotate( node ) ;
            }
        node = node->parent ;
    }
}

void BST :: push( int data ) {

    if( root == nullptr ) {
        root = GetNewNode( data , nullptr ) ;
        return;
    }
    BSTNode * temp = root ;
    while( true )
        if( data < temp->key )                              // if new data < data at current node
            if( temp->left != nullptr )                        // if there exists a left child
                temp = temp->left ;
            else {
                temp->left = GetNewNode( data , temp );     // if no left child
                break;
            }
        else                                                // if new data > data at current node
        if( temp->right != nullptr )                           // if there exists a right child
            temp = temp->right ;
        else{
            temp->right = GetNewNode( data , temp ) ;       // if no right child
            break ;
        }
    rebalance( temp ) ;
}

BSTNode * BST :: find( int data , BSTNode * rt ) {
    if( root == nullptr )
        return nullptr ;
    BSTNode * temp = rt ;
    while( temp != nullptr )
        if( data < temp->key )
            temp = temp->left ;
        else if( data > temp->key )
            temp = temp->right ;
        else if( data == temp->key )
            return temp ;
    return nullptr ;
}

BSTNode * BST :: min( BSTNode * subtree ){
    if( subtree == nullptr )
        return nullptr ;
    while( subtree->left != nullptr )
        subtree = subtree->left ;
    return subtree ;
}

void BST :: pop( int data , BSTNode * rt ) {
    if( rt == nullptr )
        rt = root ;
    BSTNode * temp = find( data , rt ) ;
    if ( temp != nullptr )
        if( temp->left == nullptr && temp->right == nullptr ){            // Case 1 : if leaf node
            if( temp->key < temp->parent->key )
                temp->parent->left = nullptr ;
            else
                temp->parent->right = nullptr ;
        }
        else if ( temp->left == nullptr )                              // Case 2.a : if no left child
            if( temp->key < temp->parent->key )
                temp->parent->left = temp->right ;
            else
                temp->parent->right = temp->right ;
        else if ( temp->right == nullptr )                             // Case 2.b : if no right child
            if( temp->key < temp->parent->key )
                temp->parent->left = temp->left ;
            else
                temp->parent->right = temp->left ;
        else{                                                       // Case 3 : has 2 child nodes
            temp->key = min( temp->right )->key ;
            pop( min( temp->right )->key , temp->right );
            temp = nullptr ;
        }
    rebalance( temp ) ;
    delete temp ;
}

void BST :: print(){                                            // Breadth 1st printing
    if( root == nullptr )
        return ;
    std::cout << std::endl ;
    std::queue < BSTNode * > Q ;
    Q.push( root ) ;
    while ( !Q.empty() ){
        BSTNode * current = Q.front() ;
        std::cout << " | " << current->key ;
        if( current->left != nullptr )
            Q.push( current->left ) ;
        if( current->right != nullptr )
            Q.push( current->right ) ;
        Q.pop() ;
    }
}