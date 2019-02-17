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

void createSegTree( vi &segTree, vi &input, ll low, ll high, ll pos){
    if( low == high){
        segTree[pos] = input[low];
        return;
    }
    ll mid = ( low + high) / 2;
    createSegTree( segTree, input, low, mid, 2*pos + 1);
    createSegTree( segTree, input, mid + 1, high, 2*pos + 2);
    segTree[pos] = segTree[2*pos + 1] + segTree[2*pos + 2];
}

void updateSegTreeLazy( vi &segTree, vi &lazy, ll queryLow, ll queryHigh, ll delta, ll low, ll high, ll pos){
    if( low > high)
        return;
    if( lazy[pos] != 0){
        segTree[pos] += ( high - low + 1) * lazy[pos];
        if( low != high){
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if( queryLow > high || queryHigh < low)     // no overlap
        return;
    if( queryLow <= low && high <= queryHigh ){ // total overlap
        segTree[pos] += ( high - low + 1 ) * delta ;
        if( low != high){
            lazy[2*pos + 1] += delta;
            lazy[2*pos + 2] += delta;
        }
        return;
    }
    // partial overlap
    ll mid = ( low + high) / 2 ;
    updateSegTreeLazy( segTree, lazy, queryLow, queryHigh, delta, low, mid, 2*pos + 1);
    updateSegTreeLazy( segTree, lazy, queryLow, queryHigh, delta, mid + 1, high, 2*pos + 2);
    segTree[pos] = segTree[2*pos + 1] + segTree[2*pos + 2];
}

ll querySegTreeLazy( vi &segTree, vi &lazy, ll queryLow, ll queryHigh, ll low, ll high, ll pos){
    if( low > high)
        return 0;
    if( lazy[pos] != 0){
        segTree[pos] += ( high - low + 1)*lazy[pos];
        if( low != high){
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if( queryLow > high || queryHigh < low)     // no overlap
        return 0;
    if( queryLow <= low && high <= queryHigh){  // total overlap
        return segTree[pos];
    }
    ll mid = ( high + low) / 2;
    return querySegTreeLazy( segTree, lazy, queryLow, queryHigh, low, mid, 2*pos + 1) + querySegTreeLazy( segTree, lazy, queryLow, queryHigh, mid + 1, high, 2*pos + 2);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    vi input(N, 0);
    for( ll i = 0 ; i < N ; ++i)
        cin >> input[i];

    ll segTreeSize = 2 * ( 1 + pow( 2, log2(N))) - 1 ; 
    vi segTree(segTreeSize, 0);
    vi lazy( segTreeSize, 0);

    createSegTree(segTree, input, 0, N-1, 0);

    ll Q;
    cin >> Q;
    ll T, A, B, X;
    while(Q--){
        cin >> T ;
        if( T == 1 ){           // update
            cin >> A >> B >> X ;
            updateSegTreeLazy( segTree, lazy, A, B, X, 0, N-1, 0);
        } else if ( T == 2 ){   // query
            cin >> A >> B;
            cout << querySegTreeLazy( segTree, lazy, A, B, 0, N-1, 0) << endl;
        }
    }
    
    return 0;
}