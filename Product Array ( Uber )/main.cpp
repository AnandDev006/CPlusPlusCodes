#include<bits/stdc++.h>

using namespace std;

int main(){

    int T, N;
    cin >> T;

    while( T--){
        
        cin >> N;
        
        int arr[N];
        int leftArr[N], rightArr[N];
        leftArr[0] = rightArr[N-1] = 1;
        
        for( int i = 0 ; i < N ; ++i)
            cin >> arr[i];
        
        for( int i = 1 ; i < N ; ++i)
            leftArr[i] = leftArr[i-1]*arr[i-1];

        for( int i = N-2 ; i >= 0 ; --i)
            rightArr[i] = rightArr[i+1]*arr[i+1];
    
        for( int i = 0 ; i < N ; ++i)
            cout << leftArr[i]*rightArr[i] << " ";
        
        cout << endl;

    }

    return 0;
}