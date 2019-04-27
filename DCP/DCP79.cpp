/*
	author : Anand
	Given an array of integers, write a function to determine whether the array could become 
	non-decreasing by modifying at most 1 element.
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

bool canEdit( vector< ll> arr) {
	ll editCount = 0;
	for( ll i = 1 ; i < sz(arr) ; ++i) {
		if( arr[i] < arr[i-1]) {
			++editCount;
			arr[i] = arr[i-1]; // to reflect the edit so that 2 consecutive same nums less than a local peak isn't taken as level top
		}
	}
	return (editCount <= 1);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	assert( canEdit( vector< ll> ({1,2,3,2,4,6}) ) == 1 );
	assert( canEdit( vector< ll> ({1,2,3,2,2,6}) ) == 0 );

	return 0;
}