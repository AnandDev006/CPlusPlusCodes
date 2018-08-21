// https://codeforces.com/contest/1027/problem/D
// Minimum Value Rectangle 

#include<bits/stdc++.h>

#define ll long long
#define F first
#define S second
#define MAX 1000005

using namespace std;

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for( int i = 0 ; i < N ; ++i){
        cin >> arr[i];
        if( arr[i] <= 0){
            --i;
            --N;
        }
    }

    // idea is to use the array indexes to keep track of +ve numbers seen.
    // since we need the smallest positive integer, the answer has to be a 
    // number between 1 to N. So th array indexes can be used as a pseudo 
    // hash map.
    // the skill is in identifying hte fact that since ur solution is always
    // between 1 to N,  we can use the array indexes

    for( int i = 0 ; i < N ; ++i){
        if( ( abs(arr[i]) - 1 ) < N && arr[ abs( arr[i]) - 1 ] > 0 )
            arr[ abs(arr[i]) - 1] = - arr[ abs(arr[i]) - 1]; 
    }

    bool flag = true;
    for( int i = 0 ; i < N ; ++i){
        if( arr[i] > 0){
            cout << i + 1 << endl;
            flag = false;
            break;
        }
    }

    if( flag){
        cout << N + 1 << endl;
    }

    cin >> ws;
    cin.get();
    return 0;
}