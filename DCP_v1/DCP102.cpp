/*
    author : Anand
    Given a list of integers and a number K, return which contiguous elements of the list sum to K.
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
    for( ll i = 0 ; i < sz(arr) - 1; ++i ){ 
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

vector< ll > sumSubArray( vector< ll > input, ll k) {
    ll left = 0, right = 1;
    ll currentSum = input[left];
    vector< ll > ans;
    while( right < sz(input) ) {
        if( currentSum == k) {
            ans = vector< ll > ( input.begin() + left, input.begin() + right);
            break;
        }
        currentSum += input[right++];
        while( currentSum > k ) {
            currentSum -= input[left++];
        }
    }
    printArray( ans);
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( sumSubArray( vector< ll > ({ 1, 2, 3, 4, 5}), 9) == vector< ll > ({ 2, 3, 4}) );
    assert( sumSubArray( vector< ll > ({ 1, 2, 3, 4, 5, 6, 7 , 8}), 12) == vector< ll > ({ 3, 4, 5}) );

    return 0;
}