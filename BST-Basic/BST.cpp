//
// Created by Anand on 22-07-2017.
//

#include <iostream>
#include <queue>
#include "BST.h"

BSTNode * BST ::GetNewNode( int data , BSTNode * parent = NULL ) {
    BSTNode * temp = new BSTNode ;
    temp->right = NULL ;
    temp->left = NULL ;
    temp->parent = parent ;
    temp->key = data ;
    return temp ;
}

void BST :: push( int data ) {
    if( root == NULL ) {
        root = GetNewNode(data);
        return;
    }
    BSTNode * temp = root ;
    while( temp != NULL )
        if( data < temp->key )                              // if new data < data at current node
            if( temp->left != NULL )                        // if there exists a left child
                temp = temp->left ;
            else {
                temp->left = GetNewNode( data , temp );     // if no left child
                break;
            }
        else                                                // if new data > data at current node
        if( temp->right != NULL )                           // if there exists a right child
            temp = temp->right ;
        else{
            temp->right = GetNewNode( data , temp ) ;       // if no right child
            break ;
        }
}

BSTNode * BST :: find( int data ) {
    if( root == NULL )
        return NULL ;
    BSTNode * temp = root ;
    while( temp != NULL )
        if( data < temp->key )
            temp = temp->left ;
        else if( data > temp->key )
            temp = temp->right ;
        else if( data == temp->key )
            return temp ;
    return NULL ;
}

BSTNode * BST :: min( BSTNode * subtree ){
    if( subtree == NULL )
        return NULL ;
    while( subtree->left != NULL )
        subtree = subtree->left ;
    return subtree ;
}

void BST :: pop( int data ) {
    BSTNode * temp = find( data ) ;
    if( temp->left == NULL && temp->right == NULL ){            // Case 1 : if leaf node
        if( temp->key < temp->parent->key )
            temp->parent->left = NULL ;
        else
            temp->parent->right = NULL ;
    }
    else if ( temp->left == NULL )                              // Case 2.a : if no left child
        if( temp->key < temp->parent->key )
            temp->parent->left = temp->right ;
        else
            temp->parent->right = temp->right ;
    else if ( temp->right == NULL )                             // Case 2.b : if no right child
        if( temp->key < temp->parent->key )
            temp->parent->left = temp->left ;
        else
            temp->parent->right = temp->left ;
    else{                                                       // Case 3 : has 2 child nodes
        temp->key = min( temp->right )->key ;
        pop( min( temp->right )->key );
        temp = NULL ;
    }
    delete temp ;
}

void BST :: print(){                                            // Breadth 1st printing
    if( root == NULL )
        return ;
    std::cout << std::endl ;
    std::queue < BSTNode * > Q ;
    Q.push( root ) ;
    while ( !Q.empty() ){
        BSTNode * current = Q.front() ;
        std::cout << " | " << current->key ;
        if( current->left )
            Q.push( current->left ) ;
        if( current->right )
            Q.push( current->right ) ;
        Q.pop() ;
    }
}