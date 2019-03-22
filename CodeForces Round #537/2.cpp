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

int main(){
	
	ll n, k, m;
	cin >> n >> k >> m;

	ll arr[n];
	ll sum = 0;
	for( ll i = 0 ; i < n ; ++i){
		cin >> arr[i];
		sum += arr[i];
	}

	double avg = 0;
	if( k*n >= m){
		avg = (sum + m)/n;
	} else {
		avg = (sum + (k*n))/n;
	}
	
	sort(arr, arr + n);

	for( int i = 1 ; i < n ; ++i){
		if( i > m)
			break;
		if( k*(n-i) >= (m-i)){
			sum -= arr[i-1];
			double val = (sum + (m-i))/(n-i);
			avg = avg > val ? avg : val;
		} else {
			sum -= arr[i-1];
			double val = (sum + (k*(n-i)))/(n-i);
			avg = avg > val ? avg : val;
		}
	}

	cout << avg << endl;

	return 0;
}