/*
    author : Anand
    Given a number represented by a list of digits, find the next greater permutation of a number, 
    in terms of lexicographic ordering. If there is not greater permutation possible, return the 
    permutation with the lowest value/ordering.
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

void printArray( const vector< ll > &arr) {
    cout << "[ ";
    for( ll i = 0 ; i < sz(arr) - 1 ; ++i ){
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << "]" << endl;
}

vector< ll > nextPermutation( vector< ll > &input) {

    if( sz(input) < 2 )
        return input;

    vector< ll > permutation = input;

    ll index;
    for( index = sz(permutation) - 1 ; index > 0 ; --index) {
        if( index > 0 && permutation[index - 1] < permutation[index]) {
            break;
        }
    }

    if( index == 0) {
        reverse( permutation.begin(), permutation.end());
    } else {
        for( ll k = sz(permutation) - 1 ; k >= index ; --k) {
            if( permutation[k] > permutation[index - 1]) {
                swap( permutation[k], permutation[index - 1]);
                break;
            }
        }
        reverse( permutation.begin() + index, permutation.end());
    }
    next_permutation(input.begin(), input.end());
    printArray(permutation);
    return permutation;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< ll > input = { 1, 2, 3};
    vector< ll > permutation = (input);

    printArray(permutation);

    do{ 
        assert( nextPermutation( permutation ) == permutation);
    } while( permutation != input);

    return 0;
}