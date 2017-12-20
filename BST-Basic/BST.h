//
// Created by Anand on 22-07-2017.
//

#ifndef BST_BASIC_BST_H
#define BST_BASIC_BST_H

class BSTNode{
public:
    int key ;
    BSTNode * left ;
    BSTNode * right ;
    BSTNode * parent ;
    BSTNode(){ left = right = parent = NULL ; }
};

class BST : private BSTNode{
    BSTNode * root ;
public:
    BST(){ root = NULL ; }
    BSTNode * GetNewNode( int , BSTNode * ) ;
    void push( int ) ;
    BSTNode * find( int ) ;
    BSTNode * min( BSTNode * );
    void pop( int ) ;
    void print() ;
};

#endif //BST_BASIC_BST_H