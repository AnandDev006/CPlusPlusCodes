/*
	author : Anand

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

void findAllCombos(unordered_map< ll, vector< char> > &mapper, vector< ll > digits, vector< char> ans = {}, ll pos = 0) {
	if( sz(ans) == sz(digits)) {
		for( char c : ans) {
			cout << c ;
		}
		cout << endl;
		return;
	}
	for( char c : mapper[digits[pos]]) {
		ans.push_back(c);
		findAllCombos( mapper, digits, ans, pos + 1);
		ans.pop_back();
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map< ll, vector< char> > mapper;
	mapper[2] = {'a', 'b', 'c'};
	mapper[3] = {'d', 'e', 'f'};
	mapper[4] = {'g', 'h', 'i'};

	vector< ll > digits = { 2, 4, 3};

	findAllCombos( mapper, digits);

	return 0;
}