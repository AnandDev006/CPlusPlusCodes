#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    set< char> seen;
    int i;
    for( i = 0 ; i < S.length(); ++i)
        if( seen.count( S[i]))
            break;
        else
            seen.insert( S[i]);
    if( i == S.length() )
        cout << "No repeating characters" << endl;
    else
        cout << "First repeating character = " << S[i];
    return 0;
}