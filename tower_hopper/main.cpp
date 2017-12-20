#include <bits/stdc++.h>

using namespace std;

bool is_hoppable(int tower[], int N , int pos){
    if( tower[0] == 0 && pos < N )
        return false;
    if( pos >= N)
        return true;
    for( int i = tower[0] ; i > 0 ; --i){
        if( is_hoppable( tower + i, N, pos + i ) ) {
            cout << pos + i + 1<< ", ";
            return true;
        }
    }
    return false;
}

int main() {
    int tower[100005];
    int N;
    cin >> N;
    for( int i = 0 ; i < N ; ++i)
        cin >> tower[i];
    if( is_hoppable( tower, N, 0))
        cout << '1' << endl;
    else
        cout << "Not hoppable " << endl;
    return 0;
}