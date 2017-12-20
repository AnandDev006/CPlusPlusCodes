#include <stdlib.h>
#include <iostream>
#include "BST.h"

int main(){

    BST a;
    int t ;
    for( int i = 0 ; i < 10 ; ++i ){
        t =rand() ;
        std::cout << " | " << t ;
        a.push( t ) ;
    }
    a.print() ;
    return 0 ;
}