#include<bits/stdc++.h>

#define mp(x,y) make_pair(x,y)
#define all(c) (c).begin(),(c).end()
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

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef long long ll;

int main(){

	debug();

	int n, m;
	cin >> n >> m;

	int a[n];
	for( int i = 0 ; i < n ; ++i)
		cin >> a[i];

	set< ii > costHeap;
	int c[n];
	for( int i = 0 ; i < n ; ++i){
		cin >> c[i];
		costHeap.insert( mp( c[i], i));
	}

	int cost = 0;

	int t, d;
	while( m--){
		cin >> t >> d;
		--t;
		cost = 0;
		if( a[t] > 0 ){
			if( a[t] >= d){
				a[t] -= d;
				cost += c[t] * d;
				d = 0;
			} else {
				d -= a[t];
				cost += c[t] * a[t];
				a[t] = 0;
			}
		}

		if( a[t] == 0)
			costHeap.erase( mp(c[t], t));

		int pos;

		while( d > 0 && !costHeap.empty()){
			pos = (*costHeap.begin()).Y;
			if( a[pos] >= d){
				a[pos] -= d;
				cost += c[pos] * d;
				d = 0;
			} else {
				d -= a[pos];
				cost += c[pos] * a[pos];
				a[pos] = 0;
			}
			if( a[pos] == 0)
				costHeap.erase( mp(c[pos],pos));
		}
		if( d > 0)
			cost = 0;

		cout << cost << endl;

	}

    return 0;
}