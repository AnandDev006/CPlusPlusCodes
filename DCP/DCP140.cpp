/*
    author : Anand
    Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.
    For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

    Follow-up: Can you do this in linear time and constant space?
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

pair< ll, ll > find2NonRepeatingNos( const vector< ll > arr){
    ll xored = arr[0];
    ll length = sz(arr);

    // Get XOR of all values : repeating values cancel off in XOR
    for( ll i = 1 ; i < length ; ++i) {
        xored ^= arr[i];
    }

    /**
     * get rightmost set bit of xored value
     * this set bit is guaranteed to be set in only 1 of the 2 non repeating numbers;
     */
    ll rightmostSetBit_XOR = xored & ~(xored - 1) ;

    pair< ll, ll > ans(0,0);

    // now divide the array into 2 sets based on if they have same rightmost set bit
    for( ll i = 0 ; i < length ; ++i ){

        // only X and other PAIRS will have this & XOR of PAIRS is 0
        if( arr[i] & rightmostSetBit_XOR) {
            ans.X = ans.X ^ arr[i];
        } else { // only Y and other PAIRS will have this case & XOR of PAIRS is 0
            ans.Y = ans.Y ^ arr[i];
        }
    }
    cout << ans.X << " " << ans.Y << endl;
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( find2NonRepeatingNos(vector< ll >({2, 4, 6, 8, 10, 2, 6, 10})) == mp( ll(4),ll(8) ) );
    assert( find2NonRepeatingNos(vector< ll >({2, 4, 7, 9, 2, 4})) == mp( ll(7),ll(9) ) );

    return 0;
}