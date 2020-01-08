/*
	author : Anand
	You are given an N by M 2D matrix of lowercase letters. Determine the minimum number 
	of columns that can be removed to ensure that each row is ordered from top to bottom 
	lexicographically. That is, the letter at each column is lexicographically later as 
	you go down each row. It does not matter whether each row itself is ordered lexicographically.
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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll N, M;
	cin >> N >> M;
	char input[N][M];

	for( ll i = 0 ; i < N ; ++i) {
		for( ll j = 0 ; j < M ; ++j) {
			cin >> input[i][j];
		}
	}

	unordered_set< ll > cols;
	for( ll col = 0 ; col < M ; ++col) {
		cols.insert( col);
	}

	for( ll row = 1 ; row < N ; ++row) {
		for( ll col = 0 ; col < M && !cols.empty() ; ++col) {
			if( input[row][col] < input[row - 1][col]) {
				cols.erase( col);
			}
		}
	}

	cout << M - sz(cols) << endl;

	return 0;
}