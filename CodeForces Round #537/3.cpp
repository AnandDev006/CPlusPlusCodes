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

inline void debug(){
	#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt", "r", stdin);
		// for writing output to output.txt
		freopen("output.txt", "w", stdout);
	#endif
}

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

ll n, k, A, B;
vi base;
vi sum;

ll solve( ll left, ll right){
	ll count = sum[right] - sum[left - 1] ;
	if( count == 0 )
		return A;
	if( left == right )
		return B * count ;
	ll mid = ( left + right) / 2 ;
	ll leftSol = solve( left, mid);
	ll rightSol = solve( mid + 1, right);

	return min( leftSol + rightSol, B * count * ( right - left + 1 ) );
}

int main(){
	
	cin >> n >> k >> A >> B;
	
	base.resize( pow(2,n) + 5);
	int pos;
	for( int i = 0 ; i < k ; ++i){
		cin >> pos;
		++base[pos];
	}

	sum.resize( pow(2,n) + 5);
	sum[0] = 0;
	for( int i = 1 ; i <= pow(2,n) ; ++i){
		sum[i] = sum[i-1] + base[i];
	}

	cout << solve( 1, pow(2,n)) <, endl;

	return 0;
}