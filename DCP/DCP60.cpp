/*
* author : Anand
* Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.
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

bool make2EqualSumSubsets( ll arr[], ll N, ll sum) {
    if( sum % 2 == 1 ) {
        return false;
    }
    sum /= 2;

    bool sol[N][sum + 1];
    memset( sol, false, sizeof(sol));
    for( ll i = 0 ; i < N ; ++i ) {
        sol[i][0] = true;
    }

    for( ll i = 0 ; i < N ; ++i ) {
        for( ll j = 1 ; j <= sum ; ++j ) {
            if( arr[i] < j ) {
                if( i == 0 ) {
                    sol[i][j] = false;
                } else {
                    sol[i][j] = sol[i-1][j];
                }
            }
            sol[i][j] = sol[i-1][j] || sol[i-1][j - arr[i]];
        }
    }

    return sol[N-1][sum];

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    cin >> N;
    ll arr[N];
    
    ll sum = 0;
    for( ll i = 0 ; i < N ; ++i ) {
        cin >> arr[i];
        sum += arr[i];
    }

    if( make2EqualSumSubsets( arr, N, sum) ) {
        cout << "True" << endl ;
    } else {
        cout << "False" << endl;
    }    

    return 0;
}