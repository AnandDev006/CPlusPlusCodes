#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N;
    int minim, sum;
    while( T--){
        cin >> N;
        int W[N];
        minim = INT32_MAX;
        sum = 0;
        for( int i = 0 ; i < N ; ++i){
            cin >> W[i];
            minim = min( minim, W[i]);
            sum += W[i];
        }
        cout << sum - N*minim << endl;
    }
    return 0;
}
