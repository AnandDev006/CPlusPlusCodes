#include <iostream>
#include <vector>
#include <map>
#include <queue>

#define MAXN 5

using namespace std ;

vector<int> g[MAXN] ;
map<int,int> p;
map<pair<int,int>,int> w;
vector<int> d( MAXN , INT32_MAX ) ;
int i = 0;

auto cmp = [](pair<int,int*> left , pair<int,int*> right){ return ( *left.second > *right.second ) ; } ;

typedef priority_queue<pair<int,int*>,vector<pair<int,int*>>, decltype(cmp)> PriQ ;

void relax( int u, int v, bool state[MAXN] ){
    if( d[v] > d[u] + w[make_pair(u,v)] )
        d[v] = d[u] + w[make_pair(u,v)];
    state[v] = !state[u];
    p[v] = u;
}

void init_dijkstra( int s , PriQ &Q, bool state[MAXN] ){
    d[s] = 0 ;
    state[s] = true;
    for( auto i = 0 ; i < MAXN ; ++i ){
        Q.push( make_pair( i , &d[i] ) ) ;
    }
}

void dijkstra( int s , int e ) {
    PriQ Q(cmp) ;
    bool state[MAXN] = {};
    init_dijkstra( s , Q , state) ;
    int u ;
    while( !Q.empty() ){
        u = Q.top().first ;
        for( auto v : g[u] ){
            if( v == e && state[u] != state[s] )
                continue ;
            relax( u , v , state);
        }
        Q.pop();
    }
    if( d[e] != INT32_MAX )
        cout << endl << "Shortest distance : " << d[e] << endl ;
    else
        cout << endl << "No path exists " << endl ;
}


void make_graph(){
    g[0] = {1,2};
    g[1] = {0,2,3,4};
    g[2] = {0,1,3};
    g[3] = {1,2,4};
    g[4] = {1,3};
    w[make_pair(0,1)] = 4 ;
    w[make_pair(0,2)] = 2 ;
    w[make_pair(1,0)] = 4 ;
    w[make_pair(1,2)] = 1 ;
    w[make_pair(1,3)] = 3 ;
    w[make_pair(1,4)] = 5 ;
    w[make_pair(2,0)] = 2 ;
    w[make_pair(2,1)] = 1 ;
    w[make_pair(2,3)] = 2 ;
    w[make_pair(3,1)] = 3 ;
    w[make_pair(3,2)] = 2 ;
    w[make_pair(3,4)] = 2 ;
    w[make_pair(4,1)] = 5 ;
    w[make_pair(4,3)] = 2 ;
}

int main(){
    make_graph() ;
    dijkstra( 0 , 4 ) ;
    return 0 ;
}