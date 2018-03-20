#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    int X, Y, K, N;
    int P, C;
    bool flag;
    while(T--){
        cin >> X >> Y >> K >> N;
        flag = false;
        while( N--){
            cin >> P >> C;
            if( C <= K && P >= ( X - Y ) ){
                flag = true;
                break;
            }
        }
        if( flag)
            cout << "LuckyChef" << endl;
        else
            cout << "UnluckyChef" << endl;
    }
    return 0;
}