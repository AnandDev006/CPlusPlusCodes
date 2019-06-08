/*
    author : Anand
    Given a pivot x, and a list lst, partition the list into three parts.

    The first part contains all elements in lst that are less than x
    The second part contains all elements in lst that are equal to x
    The third part contains all elements in lst that are larger than x
    Ordering within a part can be arbitrary.

    For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].
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

vector< ll > partition( vector<ll> arr, ll x) {
    ll pivot = 0;
    for( ll i = 0 ; i < sz(arr) ; ++i ){ 
        if( arr[i] < x ) {
            swap( arr[pivot], arr[i]);
            ++pivot;
        }
    }
    for( ll i = pivot; i < sz(arr) ; ++i ) {
        if( arr[i] == x ) {
            swap( arr[i], arr[pivot]);
            ++pivot;
        }
    }
    printArray(arr);
    return arr;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( partition(vector< ll > ({9, 12, 3, 5, 14, 10, 10}), 10 ) == vector< ll > ({9, 3, 5, 10, 10, 12, 14}) );

    return 0;
}