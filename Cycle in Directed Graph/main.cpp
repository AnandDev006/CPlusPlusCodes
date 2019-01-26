#include <bits/stdc++.h>
#define MAXN 7

using namespace std;

vector<int> Adj[MAXN];
map<int,int> Parent;
set<int> white, gray, black;

void dfs_visit( int s ){
    white.erase(s);
    gray.insert( s );
    for( auto v : Adj[s] ){
        if( black.find( v ) != black.end() )
            continue;
        if( gray.find( v ) != gray.end() ){
            cout << "Cycle detected" << endl ;
            Parent[v] = s ;
            cout << v << " <- ";
            while( s != v ){
                cout << s << " <- ";
                s = Parent[s];
            }
            cout << v << endl;
            exit(0);
        }
        Parent[v] = s ;
        dfs_visit( v );
    }
    gray.erase( s );
    black.insert( s );
}

void init(){
    for( int i = 0 ; i < MAXN ; ++i )
        white.insert( i );
}

void dfs(){
    init();
    for( int i = 0; i < MAXN ; ++i){
        if( black.find(i) != black.end() )
            continue;
        dfs_visit( i );
    }
}

void addEdge( int x, int y){
    Adj[x].push_back(y);
}

void read_graph(){
    addEdge( 1 ,2);
    addEdge( 1, 3);
    addEdge( 2, 3);
    addEdge( 4, 1);
    addEdge( 4 ,5);
    addEdge( 5 ,6);
    addEdge( 6, 4);
}

int main() {
    read_graph();
    dfs();
    return 0;
}