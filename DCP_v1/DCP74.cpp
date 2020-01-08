/*
	author : Anand
	Suppose you have a multiplication table that is N by N. That is, a 2D array where the
	value at the i-th row and j-th column is (i + 1) * (j + 1) (if 0-indexed) or i * j (if 1-indexed).

	Given integers N and X, write a function that returns the number of times X appears as a value 
	in an N by N multiplication table
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

ll getMultTableCount( ll n, ll x) {
	ll count = 0;
	for( ll i = 1 ; i <= x/2 ; ++i) {
		if( !(x % i) && (i * n) >= x ) {
			++count;
		}
	}
	return count;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << getMultTableCount( 6, 12) << endl;

	return 0;
}