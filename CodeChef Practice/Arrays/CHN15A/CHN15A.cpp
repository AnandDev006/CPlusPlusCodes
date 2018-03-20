#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N, K;
    int temp;
    int count;
    while( T--){
        cin >> N >> K;
        count = 0;
        while( N--){
            cin >> temp;
            if( ( temp + K ) % 7 == 0)
                ++count;
        }
        cout << count << endl;
    }
    return 0;
}