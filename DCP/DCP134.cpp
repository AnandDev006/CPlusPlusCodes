/*
    author : Anand
    You have a large array with most of the elements as zero.

    Use a more space-efficient data structure, SparseArray, that implements the same interface:

    init(arr, size): initialize with the original large array and size.
    set(i, val): updates index at i with val.
    get(i): gets the value at index i.
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

class SparseArray{
    unordered_map< ll, ll> storage;
    public:
    void init( const vector< ll > &arr, ll size ) {
        for( ll i = 0 ; i < size ; ++i) {
            if( arr[i] != 0 ){
                this->storage[i] = arr[i];
            }
        }
    }
    void set( ll pos, ll val) {
        if( val == 0 ){
            this->storage.erase(pos);
        } else {
            this->storage[pos] = val;
        }
    }
    ll get( ll pos) {
        return storage[pos];
    }
};

void printArray(const vector<ll> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    SparseArray arr;
    arr.init(vector<ll> ({1, 0, 0, 0, 3, 0, 2}), 7);

    assert( arr.get(2) == 0 );
    arr.set(2, 4);
    assert( arr.get(2) == 4 );
    arr.set(4,1);
    assert( arr.get(4) == 1 );
    arr.set(0,0);
    assert( arr.get(0) == 0 );

    return 0;
}