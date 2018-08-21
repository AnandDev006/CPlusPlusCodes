// https://codeforces.com/contest/1027/problem/B
// Numbers on the chessboard

#include<bits/stdc++.h>

using namespace std;


int main(){

    int n, q;
    cin >> n >> q ;
    int x, y;
    int last = (n*n + 1)/2;
    while( q--){
        cin >> x >> y;
        x--;
        y--;
        int ans = 1 + (n*x + y)/2 ;
        if( ( x + y ) % 2 != 0 )
            ans += last;
        cout << ans << endl;
    }

    return 0;
}