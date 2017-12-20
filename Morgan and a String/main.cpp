#include <bits/stdc++.h>

using namespace std;

int main() {

    int n , length , p1 , p2 ;
    string s1 , s2 , s ,test ;
    cin >> n ;
    while( n ){
        s='\0';
        s.pop_back();
        cin >> s1 ;
        cin >> s2 ;
        p1 = p2 = 0 ;
        length = s1.length() + s2.length() ;   // max length of string
        for( int i = 0 ; i < length ; ++i )
            if( p1 == s1.length() ) {          // if s1 is exhausted
                auto *p = & s2[p2] ;
                s += p ;
                break ;
            }
            else if (p2 == s2.length() ){      // if s2 is exhausted
                auto *p = & s1[p1] ;
                s += s1 ;
                break ;
            }
            else{
                if( s1[p1] > s2[p2] )          // find smaller character
                    s.push_back( s2[p2++] ) ;
                else
                    s.push_back( s1[p1++] ) ;
            }
        --n ;
        cout << s <<endl ;
    }
 /*   cin >> test ;
    for(int i=test.length() - 1 ; i >= 0 ; --i )
        if(test[i] - s[i] == 0)
            test.pop_back();
    cout << test ;*/
    return 0;
}