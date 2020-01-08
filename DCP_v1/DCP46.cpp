/*
Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana"
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
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S = "xxabay";
    ll nS = sz(S);

    vector< vi > DP( sz(S), vector< ll > ( sz(S), 1));

    ll l, i, j;

    for( l = 2 ; l <= nS ; ++l ){
        for( i = 0 ; i <= nS - l ; ++i){
            j = i + l - 1;
            if( S[i] == S[j] ){
                if( l == 2 )
                    DP[i][j] = 2;
                else if( DP[i+1][j-1] == ( j - i - 1 ) ){
                    DP[i][j] = 2 + DP[i+1][j-1];
                } else {
                    DP[i][j] = max( DP[i][j-1], DP[i+1][j]);
                }
            } else {
                DP[i][j] = max( DP[i][j-1], DP[i+1][j]);
            }
        }
    }

    i = 0, j = nS - 1;

    while( i <= j && ( S[i] != S[j] || DP[i+1][j-1] != ( j - i  - 1 ) ) && DP[i+1][j] == DP[i][j] ) {
        ++i;
    }

    while( i <= j && ( S[i] != S[j] || DP[i+1][j-1] != ( j - i  - 1 ) ) && DP[i][j-1] == DP[i][j] ) {
        --j;
    }

    cout << S.substr( i, j - i + 1) << endl ;
    
    return 0;
}