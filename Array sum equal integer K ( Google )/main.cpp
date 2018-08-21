#include<bits/stdc++.h>

using namespace std;

int main(){    

    int T, N, K, input;
    cin >> T;
    unordered_set<int> pool;
    bool flag;
    while( T--){
        cin >> N >> K;
        pool.clear();
        flag = false;
        for( int i = 0 ; i < N ; ++i){
            cin >> input;
            if( pool.find( K - input) != pool.end() ){
                flag = true;
                break;
            }
            pool.insert( input);
        }
        if( flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}