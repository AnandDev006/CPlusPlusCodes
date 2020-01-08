/*
* author : Anand
An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster 
than linear time. If the element doesn't exist in the array, return null.
*
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

int search( ll arr[], ll l, ll r, ll key) {
    
    if( l > r ) return -1;

    ll mid = ( l + r ) / 2 ;

    if( arr[mid] == key ) {
        return mid;
    }

    if( arr[l] <= arr[mid]) {
        if( key >= arr[l] && key <= arr[mid]) {
            return search( arr, l, mid - 1, key);
        }
        return search ( arr, mid + 1, r, key);
    }

    if( key >= arr[mid] && key <= arr[r]) {
        return search( arr, mid + 1, r, key);
    }

    return search( arr, l, mid -1, key);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;
    ll arr[N];
    for( ll i = 0 ; i < N ; ++i) {
        cin >> arr[i];
    }

    ll key;
    cin >> key;

    cout << search( arr, 0, N-1, key) + 1 << endl;

    return 0;
}