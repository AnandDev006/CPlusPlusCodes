/*

Given a list of integers S and a target number k, write a function that returns a subset of S 
that adds up to k. If such a subset cannot be made, then return null.

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

vector< int > findSubSet( const int &n, const int &k, const vector< int > &S){
    vector< int > result;

    vector< vector< bool > >  DP( n+1, vector < bool > ( k+1, true));

    DP[0].assign( k+1, false);
    DP[0][0] = true;

    int i, j;

    for( i = 1 ; i <= n ; ++i){
        for( j = 1 ; j <= k ; ++j ){
            if( S[i-1] > j ){
                DP[i][j] = DP[i-1][j];
            } else {
                DP[i][j] = DP[i-1][j] || DP[i-1][j-S[i-1]];
            }
        }
    }

    i = n, j = k;

    if( DP[n][k] == false){
        return result;
    }

    while( i && j){
        while( DP[i-1][j]){
            --i;
        }
        result.push_back(S[i-1]);
        j -= S[i-1];
        --i;
    }

    return result;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector< int > S = {2,3,5,7,4,1};
    int n = S.size();
    int k = 15;

    vector< int > result = findSubSet( n, k, S);
    
    for( auto x : result){
        cout << x << " ";
    }

    return 0;
}