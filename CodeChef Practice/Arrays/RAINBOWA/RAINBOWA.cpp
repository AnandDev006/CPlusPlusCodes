#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N;
    int front, back;
    bool flag;
    while( T--){
        cin >> N;
        int arr[N];
        back = N-1;
        front = 0;
        while( N--)
            cin >> arr[front++];
        front = 0;
        while( front < back && arr[front++] == arr[back--] )
            ;
        if( front >= back)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}