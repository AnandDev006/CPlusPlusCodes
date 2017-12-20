#include <bits/stdc++.h>

using namespace std ;

int check( string x ){
    stack<char> a ;
    char var ;
    for( int i = 0 ; i < x.length() ; ++i ) {
        if (x[i] == '(' || x[i] == '[' || x[i] == '{') {
            a.push(x[i]);
            continue;
        }
        if( a.empty() )
            return 0 ;
        if (x[i] == ')')
            var = '(';
        else if (x[i] == ']')
            var = '[';
        else if (x[i] == '}')
            var = '{';
        
        if( a.top() == var )
            a.pop() ;
        else
            return 0 ;
    }
    if( a.empty() )
        return 1 ;
    else
        return 0 ;
}

int main() {
    string S ;
    cout << " Enter string : " ;
    cin >> S ;
    if ( check( S ) )
        cout << " Balanced " ;
    else
        cout << " Un Balanced " ;
    return 0;
}