#include <bits/stdc++.h>

using namespace std;

int main() {
    pair< char, int> ans;
    string S;
    cin >> S;
    int counter;
    char prev = S[0];
    ans.first = prev;
    ans.second = 1;
    counter = 1;
    for( int i = 1 ; i < S.length() ; ++i) {
        if( S[i] != prev ) {
            if( counter > ans.second){
                ans.second = counter;
                ans.first = prev;
            }
            counter = 1;
        }
        else
            ++counter;
        prev = S[i];
    }
    cout << ans.first << " : " << ans.second << endl;
    return 0;
}