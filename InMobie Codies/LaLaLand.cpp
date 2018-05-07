/*
A kingdom is in the form of a connected graph with N city and N-1 roads. The king is being a drunk shuts down 1 road everyday
with uniform randomness. Each city in LaLaLand has certain number of shops and Lily wants to visit LaLaLand N*(N-1) times. She will
visit all shops reachable from the city including starting city. Since any road can be blocked at random, she also decides to start 
each of her visit in uniform randomness of starting city.

Find the number of shops Lily wil visit in these N*(N-1) visits.

Sample 1:
    Input :
        4
        1 1 0 2
        0 1
        0 2
        1 3
    Output :
        28

Sampel 2:
    Input :
        7
        1 1 1 2 2 2 3
        0 3
        1 4
        2 5
        3 4
        3 6
        4 5
    Output :
        351

*/

#include <bits/stdc++.h>

using namespace std;

struct pair_hash{
    template <class T1, class T2>
    size_t operator()( pair< T1, T2> const &pair ) const{
        size_t h1 = hash<T1>()(pair.first);
        size_t h2 = hash<T2>()(pair.second);
        return h1^h2;
    }
};

int N;
vector<int> shops;
int totalShops;
vector< vector<int>> G;
unordered_set<int> visited;
unordered_set< pair< int, int>, pair_hash> edgeVisited;
unordered_set< pair< int, int>, pair_hash> edges;
vector<int> path;

void inputData(){
    cin >> N;
    G.resize(N);
    shops.resize(N);
    for( int i = 0 ; i < N ; ++i){
        cin >> shops[i];
        totalShops += shops[i];
    }
    int x, y;
    for( int i = 0 ; i < N-1 ; ++i){
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        edges.insert( make_pair( x, y));
        edges.insert( make_pair( y, x));
    }
}

void DFS( int node){
    visited.insert(node);
    for( auto child : G[node]){
        if( visited.find( child) != visited.end())
            continue;
        DFS( child);
    }
    path.push_back( node);
}

inline void usePath( int &G, int &S){
    G = S = 0;
    for( auto node : path){
        S += shops[node];
        ++G;
    }
}

void fun(){
    int ans = 0;
    int x = 0;
    int G1, S1, G2, S2;
    for( auto u : G){
        for( auto v : u){
            if( edges.find( make_pair( x, v)) == edges.end()
                || edgeVisited.find( make_pair( x, v)) != edgeVisited.end()
                || edgeVisited.find( make_pair( v, x)) != edgeVisited.end() )
                continue;

            path.clear();
            visited.clear();
            visited.insert( v);
            DFS( x);
            usePath( G1, S1);

            G2 = N - G1;
            S2 = totalShops - S1;

            ans += G1*S1 +  G2*S2;
            edgeVisited.insert( make_pair( x, v));
            edgeVisited.insert( make_pair( v, x));

        }
        ++x;
    }
    cout << ans << endl;
}

int main(){

    #ifndef ONLINE_JUDGE
       freopen( "input.txt", "r", stdin);
       freopen( "output.txt", "w", stdout);
    #endif
    inputData();
    fun();
    return 0;
}