/*
    author : Anand
    Implement a bit array.

    A bit array is a space efficient array that holds a value of 1 or 0 at each index.

        init(size): initialize the array with size
        set(i, val): updates index at i with val where val is either 1 or 0.
        get(i): gets the value at index i
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

class BitArray{
    vector< int > arr;
    int length;
    public:
    BitArray(){
        this->length = 0;
    }

    void init(int size){ 
        this->length = size / 32 ;
        if( size % 32 != 0 ){
            ++this->length;
        }
        arr.resize( this->length, 0);
    }

    void set( int i, int val) {
        int arrPos = i / 31 ;
        int offset = i % 31 ;
        if( val == 1){
            arr[arrPos] |= 1 << offset ;
        } else if( val == 0 ) {
            arr[arrPos] &= ~(1 << offset ) ;
        }
    }

    void get( int i){ 
        int arrPos = i / 31 ;
        int offset = i % 31 ;
        cout <<  ( ( arr[arrPos] & ( 1 << offset )  ) != 0 ) << endl;
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

    BitArray A;
    A.init(35);
    A.get( 3);
    A.set( 3, 1);
    A.get( 3);
    A.get( 33);
    A.set( 33, 1);
    A.get( 33);
    A.get( 34);
    A.set( 34, 1);
    A.get( 34);

    return 0;
}