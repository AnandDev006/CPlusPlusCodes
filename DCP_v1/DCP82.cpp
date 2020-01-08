/*
	author : Anand
    Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.
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

class newString{
	public:
	string s;
	ll offset;
	newString(string s) {
		this->s = s;
		this->offset = 0;
	}

	string read7() {
		ll start = this->offset;
		ll end = min(start + 7, ll(this->s.length()));
		offset = end;
		return s.substr( start, end - start);
	}

	string readN(ll n) {
		string ans = "";
		ll prevOffset = this->offset;
		while( ans.length() < n) {
			string newChars = read7();
			if( newChars == "") {
				break;
			}
			ans += newChars;
		}
		this->offset = prevOffset + n;
		return ans.substr( 0, n);
	}
};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	newString* S1 = new newString("Hello World");
	assert( S1->read7().compare("Hello W") == 0 );
	assert( S1->read7().compare("orld") == 0 );
	assert( S1->read7().compare("") == 0 );

	newString* S2 = new newString("Hello World");
	assert( S2->readN(4).compare("Hell") == 0 );
	assert( S2->readN(4).compare("o Wo") == 0 );
	assert( S2->readN(4).compare("rld") == 0 );

	return 0;
}