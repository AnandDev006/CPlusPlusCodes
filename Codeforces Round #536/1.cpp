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

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef long long ll;

int main(){

	debug();

	int n;
	cin >> n;

	char arr[n][n];
	for( int i = 0 ; i < n ; ++i)
		for( int j = 0 ; j < n ; ++j)
			cin >> arr[i][j];

	int posI[4] = {-1, 1, 1, -1};
	int posJ[4] = {-1, -1, 1, 1};

	int count = 0;

	for( int i = 1; i < n-1 ; ++i){
		for( int j = 1 ; j < n-1 ; ++j){
			bool flag = false;
			if( arr[i][j] == 'X'){
				flag = true;
				for( int k = 0 ; k < 4 ; ++k){
					flag = flag && ( arr[i + posI[k]][j + posJ[k]] == 'X' );
				}
				if( flag)
					++count;
			}
		}
	}

	cout << count;
	
    return 0;
}