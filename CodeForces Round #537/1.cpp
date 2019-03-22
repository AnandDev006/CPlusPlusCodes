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
	
	unordered_set< char > vowels;
	vowels.insert('a');
	vowels.insert('e');
	vowels.insert('i');
	vowels.insert('o');
	vowels.insert('u');

	string s, t;
	cin >> s >> t;

	if( sz(s) == sz(t)){
		for( int pos = 0 ; pos < sz(s) ; ++pos){
			if( ( present(vowels,s[pos]) && !present(vowels,t[pos]) ) || ( !present(vowels,s[pos]) && present(vowels,t[pos]) ) ){
				cout << "No" << endl;
				return 0;
			}
		}
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	
	return 0;
}