#include<bits/stdc++.h>

using namespace std ;

template < class T , class U >
class asd{
public:
    T a , b ;
    U c ,d ;
    asd() ;
    void add() ;
};

template <class T , class U>
asd< T , U > :: asd(){
    cin >> a >> b ;
    cin >> c >> d ;
}

template <class T , class U>
void asd < T , U > ::  add(){
    cout << a+b << endl << c + d ;
}

int main(){
    asd< int , string > x ;
    x.add() ;
    return 1 ;
}