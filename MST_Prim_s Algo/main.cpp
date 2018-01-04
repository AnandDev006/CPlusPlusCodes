#include <iostream>
#include <queue>
#include <map>
#include <set>

#define MAXN 6
using namespace std;

vector<int> Adj[MAXN];
vector<pair<int,int>> Res;
map<pair<int,int>,int> W;
map<int,int> Parent;
vector<int> d( MAXN, INT32_MAX);

void addEdge(int x, int y, int w){
    Adj[x].push_back(y);
    Adj[y].push_back(x);
    W[make_pair(x,y)] = w;
    W[make_pair(y,x)] = w;
}

auto cmp = [](pair<int,int> left , pair<int,int> right){ return ( left.second > right.second ) ; } ;

typedef priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> PriQ ;

void init( int s , PriQ &Q ){
    d[s] = 0 ;
    Q.push(make_pair( s, d[s]));
}

void relax( int u , int v , PriQ &Q){
    if( d[v] > W[make_pair(u,v)] ){
        d[v] = W[make_pair(u,v)] ;
        Parent[v] = u ;
        Q.push(make_pair( v, d[v]));
    }
}

void MST_Prim(int s){
    PriQ Q(cmp) ;
    set<int> S;
    init( s, Q);
    int u;
    while( S.size() < MAXN ){
        u = Q.top().first;
        Q.pop();
        if( S.count( u ) )
            continue;
        S.insert( u );
        Res.emplace_back( u, Parent[u]);
        for( auto v : Adj[u] ){
            relax( u, v, Q);
        }
    }
}

int main() {
    addEdge( 0, 3, 1);
    addEdge( 0, 1, 3);
    addEdge( 3, 1, 3);
    addEdge( 3, 2, 1);
    addEdge( 1, 2, 1);
    addEdge( 3, 4, 1);
    addEdge( 4, 2, 5);
    addEdge( 4, 5, 2);
    addEdge( 2, 5, 4);
    MST_Prim( 0 );
    return 0;
}