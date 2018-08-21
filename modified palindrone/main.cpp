#include<bits/stdc++.h>

using namespace std;

int main(){

    int T, N;

    cin >> T;
    
    string S;
    bool flag;

    while( T--){
        cin >> N;
        S.clear();
        cin >> S;
        flag = true;
        for( int i = 0 ; i < N/2 ; ++i){
            if( abs(S[i] - S[N-i-1]) != 0 && abs(S[i] - S[N-i-1]) != 2 ){
                flag = false;
                break;
            }
        }
        if( flag)
            cout <<"YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}