/*
	author : Anand
	Given a string of parentheses, write a function to compute the minimum number of 
	parentheses to be removed to make the string valid (i.e. each open parenthesis is 
	eventually closed).
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

ll getNumParantheses( string input) {
	ll p_Needed = 0;
	ll open_P = 0;
	for( char c : input ) {
		if( c == '(') {
			++open_P;
		} else if( c ==')') {
			if( open_P == 0) {
				++p_Needed;
			} else {
				--open_P;
			}
		}
	}
	p_Needed += open_P;
	return p_Needed;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	assert( getNumParantheses("()())()") == 1 );
	assert( getNumParantheses(")(") == 2 );

	return 0;
}