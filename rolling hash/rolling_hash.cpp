//
// Created by Anand on 14-08-2017.
//

#include "rolling_hash.h"

rolling_hash ::rolling_hash( int base , int prime ) {
    this->b = base ;
    this->p = prime ;
    this->hash_value = 0 ;
    this->magic = 1 ;
    this->ibase = ModInv( base , prime ) ;
}

int rolling_hash :: ModInv( int base , int prime) {
    base = base % prime ;
    for( int i = 1 ; i < prime ; ++i )
        if( ( base * i ) % p == 1 )
            return i ;
}

void rolling_hash :: append( int new_element ) {
    this->hash_value = ( this->hash_value * this->b + new_element ) % this->p ;
    this->magic = ( this->magic * b ) % p ;
}

void rolling_hash :: skip( int old_element ) {
    this->magic = ( this->magic * ibase ) % p ;
    this->hash_value = ( this->hash_value - old_element * magic + this->p * this->b ) % p ;
}

int rolling_hash :: hash() {
    return hash_value ;
}