#include <bits/stdc++.h>

using namespace std;

int stringConstruction( string s ){
    int c = 0 ;
    vector <int> arr( 26 , 0 ) ;
    for(int i = 0 ; i < s.length() ; i++ )
        ++arr[s[i]-'a'];

    for(int j = 0 ; j <26 ; j++ )
        if(arr[j]!=0)
            c++;
    return c ;
}

int main() {
    int q ;
    cin >> q ;
    if( q > 5 || q < 1 )
        return 0 ;
    for( int a0 = 0 ; a0 < q ; a0++ ){
        string s ;
        cin >> s ;
        if ( s.size() > 100000 || s.size() < 1 )
            return 0 ;
        int result = stringConstruction( s ) ; // Need to find number of distinct characters in string
        cout << result << endl ;
    }
    return 0;
}