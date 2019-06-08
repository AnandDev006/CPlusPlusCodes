/*
    author : Anand
    Given a list, sort it using this method: reverse(lst, i, j), which reverses lst from i to j.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair(a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair< ll, ll > ii;

void printArray(const vector<ll> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

ll maxInRange_Pos( const vector< ll > &arr, ll len){
    ll max = arr[0];
    ll maxPos = 0;
    for( ll i = 1 ; i < len ; ++i ){
        if( arr[i] > max){
            max = arr[i];
            maxPos = i;
        }
    }
    return maxPos;
}

void reverseRange( vector< ll > &arr, ll i, ll j){
    reverse(arr.begin() + i, arr.begin() + j);
}

vector< ll > swapWithReverse( vector< ll > arr){
    
    ll length = sz(arr);
    
    for( ll i = 0 ; i < length ; ++i ) {
        ll maxPos = maxInRange_Pos( arr, length - i);
        if( maxPos == length - i - 1){
            continue;
        }
        reverseRange( arr, maxPos, length - i);
        
    }
    printArray( arr);
    return arr;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( swapWithReverse(vector< ll > ({ 1, 4, 3, 5, 2})) == vector< ll > ({ 1, 2, 3, 4, 5}) );
    assert( swapWithReverse(vector< ll > ({ 8, 7, 6, 5, 4, 3, 2, 1})) == vector< ll > ({ 1, 2, 3, 4, 5, 6, 7, 8}) );

    return 0;
}