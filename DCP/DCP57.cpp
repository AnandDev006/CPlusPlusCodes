/*

Given a string s and an integer k, break up the string into multiple texts such 
that each text has a length of k or less. You must break it up so that words don't 
break across lines. If there's no way to break the text up, then return null.

*/

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

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    ll k;
    getline( cin, s);
    cin >> k;

    vector< string> ans;

    ll pos, start, end;
    for( pos = start = end = 0 ; pos < s.length() ; ++pos ){
        if( s[pos] == ' ') {
            end = pos - 1;
        }

        if( ( pos - start + 1 ) > k ) {
            if(start == end) {
                ans.clear();
                break;
            }
            ans.push_back( s.substr(start, end - start + 1));
            start = end = end + 2;
        }
    }

    if( pos == s.length() ) {
        ans.push_back( s.substr( start, pos - start));
    }

    for( string sol : ans) {
        cout << sol << endl;
    }

    return 0;
}