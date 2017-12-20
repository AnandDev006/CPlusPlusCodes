#include <iostream>
#include "AVL.h"

int main(){

    BST a ;
    for( int i = 0 ; i < 7 ; ++i ){
        a.push( rand() ) ;
    }
    a.print() ;
    a.push(23);
    a.print() ;
    a.push(65);
    a.print();
    a.pop(41);
    a.print();
    return 0 ;
}