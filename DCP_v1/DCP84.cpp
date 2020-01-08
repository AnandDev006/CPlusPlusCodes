/*
	author : Anand
	Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land
	and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter 
	is surrounded by water.
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

bool isValid( const vector< vector< ll > > &input, const vector< vector< bool > > &visited, ll n, ll m, ll i, ll j) {
	return ( i >= 0 && j >=0 && i < n && j < m && !visited[i][j] && input[i][j] == 1);
}

ll numOfIslands( const vector< vector< ll > > &input) {
	ll n = sz(input);
	ll m = sz(input[0]);
	vector< vector< bool > > visited( n, vector< bool> ( m, false));

	ll numOfIslands = 0;

	int row[] = {0,-1,0,1};
	int col[] = {1,0,-1,0};

	for( ll i = 0 ; i < n ; ++i) {
		for( ll j = 0 ; j < m ; ++j) {
			if( !visited[i][j] && input[i][j] == 1) {
				++numOfIslands;
				visited[i][j] = true;
				
				queue< pair< ll, ll> > Q;
				Q.push( mp( i, j));
				while( !Q.empty()) {
					pair< ll, ll > node = Q.front();
					Q.pop();
					for( int k = 0 ; k < 4 ; ++k) {
						if( isValid( input, visited, n, m, node.X + row[k], node.Y + col[k])) {
							visited[node.X + row[k]][node.Y + col[k]] = true;
							Q.push( mp( node.X + row[k], node.Y + col[k]));
						}
					}
				}
			}
		}
	}
	
	return numOfIslands;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector< vector< ll > > input = {
		{1,0,0,0,0},
		{0,0,1,1,0},
		{0,1,1,0,0},
		{0,0,0,0,0},
		{1,1,0,0,1},
		{1,1,0,0,1}
	};

	assert( numOfIslands( input) == 4 );

	return 0;
}