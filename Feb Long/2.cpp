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

const int MAX_CHAR = 26; 

ll commonCharacters(string str[], ll n) 
{ 
    // primary array for common characters  
    // we assume all characters are seen before. 
    bool prim[MAX_CHAR]; 
    memset(prim, true, sizeof(prim)); 
  
    // for each string 
    for (ll i = 0; i < n; i++) { 
  
        // secondary array for common characters 
        // Initially marked false 
        bool sec[MAX_CHAR] = { false }; 
  
        // for every character of ith string 
        for (ll j = 0; str[i][j]; j++) { 
  
            // if character is present in all  
            // strings before, mark it. 
            if (prim[str[i][j] - 'a']) 
                sec[str[i][j] - 'a'] = true;  
        } 
  
        // copy whole secondary array into primary 
        memcpy(prim, sec, MAX_CHAR); 
    } 
  

	ll count = 0;
    // count common characters 
    for (ll i = 0; i < 26; i++) 
        if (prim[i]) 
            ++count;

	return count;
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll T;
	cin >> T;
	while( T--){
		ll N;
		cin >> N;
		string s[N];
		for( ll i = 0 ; i < N ; ++i){
			cin >> s[i];
		}
		cout << commonCharacters( s, N) << endl;
	}
	
	return 0;
}