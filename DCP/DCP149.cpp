/*
    author : Anand
    Given a list of numbers L, implement a method sum(i, j) which returns the sum from the sublist L[i:j] (including i, excluding j).

    For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

    You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step.
*/

#include<bits/stdc++.h>

#define sz(a) ll((a).size())
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

class FastRangeSumArray{
    vector< ll > cumSumArr;
    public:
    FastRangeSumArray( vector< ll > arr){
        this->cumSumArr.push_back( 0);
        for( ll i = 0 ; i < sz(arr) ; ++i){
            this->cumSumArr.push_back( this->cumSumArr[i] + arr[i] );
        }
    }
    ll sum( ll left, ll right){
        left = left < 0 ? 0 : left;
        right = right > sz(this->cumSumArr) - 1 ? sz(this->cumSumArr) - 1 : right;

        cout << this->cumSumArr[right] - this->cumSumArr[left] << endl ;

        return this->cumSumArr[right] - this->cumSumArr[left];
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

    FastRangeSumArray* arr = new FastRangeSumArray( vector< ll > ({ 1, 2, 3, 4, 5}) );
    
    assert( arr->sum( 1, 3) == 5 );

    return 0;
}