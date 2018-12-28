#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;

    cin >> n;

    int arr[n];

    for( int i = 0 ; i < n ; ++i)
        cin >> arr[i];

    int t = arr[0], nt = 0;

    for( int i = 1 ; i < n ; ++i){
        int _t = nt + arr[i];
        int _nt = max( t, nt);
        t = _t;
        nt = _nt;
    }

    int ans = max( t, nt);

    cout << ans << endl;

    return 0;
}