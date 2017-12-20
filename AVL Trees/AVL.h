//
// Created by Anand on 23-07-2017.
//

#ifndef AVL_TREES_AVL_H
#define AVL_TREES_AVL_H

class BSTNode{
public:
    int key ;
    BSTNode * left{};
    BSTNode * right{};
    BSTNode * parent{};
    int height ;
    BSTNode();
};

class BST : private BSTNode{
    BSTNode * root ;
	void left_rotate( BSTNode * ) ;
    void right_rotate( BSTNode * ) ;
	void rebalance( BSTNode * ) ;
	int update_height( BSTNode * ) ;
public:
    BST(){ root = nullptr ; }
    int height( BSTNode * ) ;
    BSTNode * GetNewNode( int , BSTNode * ) ;
    void push( int ) ;
    BSTNode * find( int , BSTNode * ) ;
    BSTNode * min( BSTNode * );
    void pop( int , BSTNode * rt = nullptr ) ;
    void print() ;
};

#endif //AVL_TREES_AVL_H