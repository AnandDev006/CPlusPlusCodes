#include <bits/stdc++.h>

using namespace std;

int Kadane( int Ar[], int N){
    int globMax = 0, locMax = 0;
    globMax = locMax = Ar[0];
    for( int i = 1 ; i < N ; ++i){
        locMax = max( locMax + Ar[i], Ar[i]);
        globMax = max( globMax, locMax);
    }
    return globMax;
}

int main(){
    int Ar[1000];
    int N;
    cin >> N;
    for( int i = 0 ; i < N ; ++i)
        cin >> Ar[i];
    cout << Kadane( Ar, N) << endl;
    return 0;
}