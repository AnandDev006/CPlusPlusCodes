#include <bits/stdc++.h>

using namespace std ;

class node{
    int data ;
    node * link ;
public:
    void insert( int , int ) ;
    void remove( int ) ;
    void modify( int , int ) ;
    void read ( int ) ;
    void find ( ) ;
    void readRec( node * ) ;
    void readRevRec( node * ) ;
};

node * headPointer = NULL ;
int size = 0 ;

void node ::readRec( node * p = headPointer ) {
    if( p == NULL )
        return ;
    cout << " | " << p->data ;
    readRec( p->link ) ;
}

void node ::readRevRec( node * p = headPointer ) {
    if( p == NULL )
        return ;
    readRevRec( p->link ) ;
    cout << " | " << p->data ;
}


void node :: modify( int x , int pos ) {
    if( size < pos || headPointer == NULL ){
        cout << endl << " Out of Bounds " << endl ;
        return ;
    }
    node * temp = headPointer ;
    for (int i = 0; i < pos - 1 ; ++i)
        temp = temp->link;
    temp->data = x ;
}

void node :: remove ( int pos = 0 ) {

    if( size < pos || headPointer == NULL ){
        cout << endl << " Out of Bounds " << endl ;
        return ;
    }
    node * temp = headPointer ;
    if( pos == 0 ) {
        for (int i = 0; i < size - 2; ++i)
            temp = temp->link;
        free( temp->link ) ;
        temp->link = NULL ;
    }
    else {
        for (int i = 0; i < pos - 2; ++i)
            temp = temp->link;
        node * temp1 = temp->link ;
        temp->link = temp1->link ;
        free( temp1 ) ;
    }
    --size ;
}

void node :: insert( int x , int pos = 0 ) {
    ++size ;
    if( size < pos && headPointer != NULL ){
        cout << endl << " List Overflow " << endl ;
        return ;
    }
    node * temp = new node ;
    temp->data = x ;
    temp->link = NULL ;
    if( pos == 1 || headPointer == NULL ){
        temp->link = headPointer ;
        headPointer = temp ;
        return ;
    }
    node * temp1 = headPointer ;
    if( pos == 0 )
        while( temp1->link != NULL )
            temp1 = temp1->link ;
    else
        for ( int i = 0 ; i < pos - 2 ; ++i )
            temp1 = temp1->link ;
    temp->link = temp1->link ;
    temp1->link = temp ;
}

void node :: read ( int pos = 0 ) {
    if( size < pos && headPointer != NULL ){
        cout << endl << " List Overflow " << endl ;
        return ;
    }
    cout << endl ;
    node * temp = headPointer ;
    if ( pos == 0) {
        while (temp != NULL) {
            cout << " | " << temp->data;
            temp = temp->link;
        }
        cout << " | " << endl ;
        return;
    }
    for( int i = 0 ; i < pos - 1 ; ++i )
        temp = temp->link ;
    cout << " | " << temp->data << " | " << endl ;
}

int main() {
    node a ;
    a.insert ( 2 , 1 ) ;
    a.insert ( 3 , 2 ) ;
    a.insert ( 4 , 1 ) ;
    a.insert( 8 ) ;
    a.read();
    a.insert ( 5 , 2 ) ;
    a.readRec() ;
    a.readRevRec() ;
    a.read( 7 ) ;
    a.modify( 11 , 3 ) ;
    a.read() ;
    a.remove( 2 ) ;
    a.read() ;
    a.remove() ;
    a.read() ;

    return 0 ;
}