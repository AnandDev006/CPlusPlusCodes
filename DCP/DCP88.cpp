/*
	author : Anand
	Implement division of two positive integers without using the division, 
	multiplication, or modulus operators. Return the quotient as an integer, 
	ignoring the remainder.
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

ll divide( ll dividend, ll divisor) {
	if( divisor == 0) {
		return INT_MAX;
	}
	
	ll sum = 0;
	ll quotient = 0;
	while( sum <= dividend) {
		++quotient;
		sum += divisor;
	}
	return quotient - 1;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	assert( divide(1, 0) == INT_MAX);
	assert( divide(1, 1) == 1);
	assert( divide(0, 1) == 0);
	assert( divide(12, 3) == 4);
	assert( divide(13, 3) == 4);
	assert( divide(25, 5) == 5);
	assert( divide(25, 7) == 3);

	return 0;
}