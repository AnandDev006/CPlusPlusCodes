//
// Created by Anand on 14-08-2017.
//

#ifndef ROLLING_HASH_ROLLING_HASH_H
#define ROLLING_HASH_ROLLING_HASH_H


class rolling_hash {
        int hash_value ;
        int b ;
        int p ;
        int magic ;
        int ibase ;
    public:
        rolling_hash( int base , int prime ) ;
        int ModInv( int base , int prime ) ;
        void append( int new_element ) ;
        void skip( int old_element ) ;
        int hash() ;
};


#endif //ROLLING_HASH_ROLLING_HASH_H
