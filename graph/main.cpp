#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <stack>

#define MAXN 5

using namespace std ;

vector<int> g[MAXN] ;
map<int,int> p;
map<pair<int,int>,int> w;
stack<int> topSort ;
vector<int> d( MAXN , INT32_MAX ) ;

void bfs( int s ){
    int u ;
    queue<int> Q ;
    p[s] = -1;
    Q.push( s );
    while( !Q.empty() ) {
        u = Q.front();
        Q.pop();
        for (auto v : g[u]) {
            if ( p.count(v) == 1u )
                continue;
            p[v] = u;
            Q.push(v);
        }
    }
}

void dfs_visit( int s ){
    for( auto v : g[s] ){
        if( p.count(v) == 1u)
            continue ;
        p[v] = s ;
        dfs_visit( v ) ;
    }
    topSort.push( s ) ;
}

void dfs(){
    for( int u = 0 ; u < MAXN ; ++u  ){
        if( p.count(u) == 1u)
            continue ;
        p[u] = -1 ;
        dfs_visit( u );
    }
}

auto cmp = [](pair<int,int> left , pair<int,int> right){ return ( left.second > right.second ) ; } ;

typedef priority_queue<pair<int,int>,vector<pair<int,int>>, decltype(cmp)> PriQ ;

void init( int s , PriQ &Q ){
    d[s] = 0 ;
    Q.push(make_pair( s, 0));
}

void relax( int u , int v , PriQ &Q ){
    if( d[v] > d[u] + w[make_pair(u,v)] ){
        d[v] = d[u] + w[make_pair(u,v)] ;
        p[v] = u ;
        Q.push(make_pair( v, d[v]));
    }
}

void dijkstra( int s , int e = MAXN) {
    PriQ Q(cmp) ;
    init( s , Q ) ;
    int u ;
    while( !Q.empty() ){
        u = Q.top().first ;
        Q.pop();
        for( auto v : g[u] )
            relax( u , v , Q);
    }
    if( d[e] != INT32_MAX )
        cout << endl << "Shortest distance : " << d[e] << endl ;
    else
        cout << endl << "No path exists " << endl ;
}
/*
void bellman_ford( int s ){
    d[s] = 0 ;
    int u = 0 ;
    for( int i = 0; i < MAXN ; ++i){
        for( auto e : g ) {
            for (auto v : e)
                relax(u, v);
            ++u ;
        }
    }
    u = 0 ;
    for( auto e : g ) {
        for (auto v : e)
            if (d[v] > d[u] + w[make_pair(u, v)] && d[v] != INT32_MAX)
                cout << endl << " Graph contains negetive weight cycles" << endl;
        return ;
        ++u;
    }
}
*/
void addEdge(int x, int y, int W){
    g[x].push_back(y);
    g[y].push_back(x);
    w[make_pair(x,y)] = W;
    w[make_pair(y,x)] = W;
}

void make_graph(){
    addEdge( 0, 3, 1);
    addEdge( 0, 1, 3);
    addEdge( 3, 1, 3);
    addEdge( 3, 2, 1);
    addEdge( 1, 2, 1);
    addEdge( 3, 4, 6);
    addEdge( 4, 2, 5);
    addEdge( 4, 5, 2);
    addEdge( 2, 5, 4);
}

int main(){
    make_graph() ;
    dijkstra( 0 );
    return 0 ;
}