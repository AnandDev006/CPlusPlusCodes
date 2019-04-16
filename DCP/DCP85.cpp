/*
	author : Anand
	Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, 
	using only mathematical or bit operations. You can assume b can only be 1 or 0.
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

ll getNum( ll x, ll y, ll b) {
	return b * x + y * ( 1 - b);
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	assert( getNum( 3, 4, 1) == 3 );
	assert( getNum( 3, 4, 0) == 4 );

	return 0;
}