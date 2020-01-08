/*
	author : Anand
	Given an array of numbers, find the length of the longest increasing subsequence in 
	the array. The subsequence does not necessarily have to be contiguous.
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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector< ll > input = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	ll N = sz(input);
	vector< ll > DP(N, 1);

	for( ll  i = 0 ; i < N ; ++i )
        DP[i] = 1;              // long increasing sub seq is atleast of length 1 at each position
    for( ll i = 1 ; i < N ; ++i){
        for( ll j = 0; j < i ; ++j )
            if( input[j] < input[i] )               // if inp[j] < inp [i] , then adding inp[i] to the longest sub
                DP[i] = max( DP[i], 1 + DP[j] );    // seq upto j will increase size of the sub sez till j by 1
    }

    cout << DP[N-1] << endl;

	return 0;
}