/*
 author : Anand
 
 There is an N by M matrix of zeroes. Given N and M, write a function to count the number 
 of ways of starting at the top-left corner and getting to the bottom-right corner. You can 
 only move right or down.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N, M;
    cin >> N >> M;
    ll arr[N][M];

    for( ll i = 0 ; i < N ; ++i ) {
        arr[i][0] = 1;
    }

    for( ll j = 0 ; j < M ; ++j) {
        arr[0][j] = 1;
    }

    for( ll i = 1 ; i < N ; ++i) {
        for( ll j = 1 ; j < M ; ++j) {
            arr[i][j] = arr[i - 1][j] + arr[i][j - 1];
        }
    }

    cout << arr[N - 1][M - 1] << endl;

    return 0;
}