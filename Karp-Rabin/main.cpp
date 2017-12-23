#include <iostream>
#include "rolling_hash.h"

const int base = 10 ;
const int prime = 23 ;

using namespace std ;

int main() {

    int count = 0 ;
    bool flag ;
    rolling_hash rM( base , prime ) ;
    rolling_hash rS( base , prime ) ;
    string m , s ;
    cout << "Haystack : " ;
    getline( cin , m ) ;
    cout << "Needle : " ;
    getline( cin , s ) ;

    for( int i = 0 ; i < s.length() ; ++i ){
        rM.append( m[i] ) ;
        rS.append( s[i] ) ;
    }

    for( int i = s.length() ; i < m.length() ; ++i ){

        if( rM.hash() == rS.hash() ) {
            flag = true;
            for (int j = 0; j < s.length(); ++j)
                if (s[j] != m[i - s.length() + j])
                    flag = false;
            if (flag)
                ++count;
        }

        rM.skip( m[ i - s.length() ] ) ;
        rM.append( m[i] ) ;

    }

    cout << endl << endl << "Number of occurrences of \"" << s << "\" in \"" << m << "\" = " << count ;

    return 0;
}