#include <bits/stdc++.h>

using namespace std;

int main() {
    int d[100005];
    int N;
    int pos, temp;
    cin >> N;
    for( int i = 0 ; i < N ; ++i)
        cin >> d[i];
    for( int i = N-1 ; i >0 ; --i ){
        temp = d[i];
        pos = rand()%i ;
        d[i] = d[pos];
        d[pos] = temp;
    }
    for( int i = 0 ; i < N ; ++i )
        cout << d[i] << " " ;
    return 0;
}