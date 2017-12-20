#include <bits/stdc++.h>

using namespace std;

int N;
int d[100005];

void print_set( int *subset) {
    for( int i = 0 ; i < N ; ++i ) {
        if( subset[i] != INT_MIN )
            cout << subset[i] << ", ";
    }
    cout << endl;
}

void rec( int *subset, int pos) {
    if( pos == N)
        print_set( subset);
    else {
        subset[ pos] = INT_MIN;
        rec( subset, pos +1);
        subset[ pos] = d[pos];
        rec( subset, pos+1);
    }
}

void fun(){
    cout << " ,";
    auto subset = new int[N];
    rec( subset, 0);
}

int main() {
    cin >> N;
    for( int i = 0 ; i < N ; ++i)
        cin >> d[i];
    fun();
    return 0;
}