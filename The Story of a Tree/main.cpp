#include <iostream>
#include <set>
#include <unordered_map>

#define MAXN 100000

using namespace std;

set< int> Adj[ MAXN+1];
unordered_map< int, int> parent;
unordered_map< int, int> start;
unordered_map< int, int> finish;
unordered_map< int, int> pos;
int index;

void dfs( int s = 1, int p = -1) {
    ++index;
    start[s] = index;
    pos[index] = s;
    parent[s] = p;
    for( auto v : Adj[s] ) {
        if( parent[v])
            continue;
        dfs( v, s);
    }
    finish[s] = index;
}

int GCD( int a, int b) {
    while ( a != b ) {
        if( a > b )
            a -= b;
        else
            b -= a;
    }
    return a;
}

void game() {
    int n, u , v, q, k, correct = 0;
    unordered_map< int, int> root;
    cin >> n;
    for( int i = 1; i < n; i++) {
        cin >> u >> v;
        Adj[ u].insert( v);
        Adj[ v].insert( u);
    }
    dfs();
    cin >> q >> k;
    for(int i = 0; i < q; ++i) {
        cin >> u >> v;
        if( Adj[u].count( v ) ) {
            int stU = start[u];
            int fiU = finish[u];
            int stV = start[v];
            int fiV = finish[v];
            if ( stV > stU && stV <= fiU ) {
                for( int j = 1; j < stV; ++j)
                    ++root[ pos[j]];
                for( int j = fiV + 1; j <= index; ++j)
                    ++root[ pos[j]];
            }
            else {
                for( int j = stU; j <= fiU; ++j)
                    ++root[ pos[j]];
            }
        }
    }
    for( int i = 1; i <= n; ++i)
        if( root[i] >= k )
            ++correct;
    if( correct == 0 ) {
        cout << "0/1" << endl;
        return;
    }
    int g = GCD( correct, n);
    cout << correct / g << "/" << n / g << endl;
    for( int i = 0 ; i < n ; ++i )
        Adj[i].clear();
    parent.clear();
    start.clear();
    finish.clear();
    pos.clear();
    index = 0;
}

int main() {
    int t;
    cin >> t;
    while( t-- )
        game();
    return 0;
}