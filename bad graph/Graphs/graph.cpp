//
// Created by Anand on 21-08-2017.
//

#include "graph.h"

int time_count ;

void Initialize( std::map<std::string,std::list<std::string>> &Adj){
    int V , E ;
    std::string v , n ;
    std::cout << "Enter number of vertices : " ;
    std::cin >> V ;
    std::cout << std::endl ;
    for( int x = 0 ; x < V ; ++x ){
        std::cout << std::endl << "Vertex : " ;
        std::cin >> v ;
        std::cout << "Enter number of edges for " << v << " : " ;
        std::cin >> E ;
        std::cout << "Edges : " ;
        for( int y = 0 ; y < E ; ++y ){
            std::cin >> n ;
            Adj[v].push_back( n ) ;
        }
        std::cout << std::endl ;
    }
}

auto BreadthFirstSearch ( std::map<std::string, std::list<std::string> > Adj , std::string start ){
    std::unordered_map <std::string,int> level ;
    std::unordered_map <std::string,std::string> parent ;
    std::vector<std::string> frontier ;
    std::vector<std::string> next ;
    int i = 0 ;
    level[start] = i ;
    parent[start] = "" ;
    ++i ;
    frontier.emplace_back( start ) ;
    while( !frontier.empty() ){                 // O( V + E )
        next.clear() ;
        for( auto u : frontier )                // O( ∑( |Adj[u]| ) ) = O( E )
            for( auto v : Adj[u] )              // O( |Adj[u]| )
                if( level.count(v) == 0u ){
                    level[v] = i ;
                    parent[v] = u ;
                    next.push_back(v) ;
                }
        ++i ;
        frontier = next ;
    }
    return parent ;                             // Change as per need
}

void PrintShortestPath( std::map<std::string , std::list<std::string> > Adj ){
    system("cls") ;
    std::string start , end ;
    std::cout << std::endl << "Enter Start and End points : " ;
    std::cin >> start >> end ;
    auto parent = BreadthFirstSearch( Adj , end ) ;
    for( auto p = start ; p != end ; p = parent[p] )
        std::cout << p << " -> " ;
    std::cout << end << std::endl ;
}

void DFS_Visit( adjacency_list Adj , std::string s , std::unordered_map <std::string,std::string> &parent , std::vector<std::pair<std::string,int>> &timer){
    for( auto v : Adj[s] )
        if( parent.count( v ) == 0u ){
            parent[v] = s ;
            DFS_Visit( Adj , v , parent , timer ) ;
        }
    timer.emplace_back( std::make_pair( s , time_count++ ) ) ;
}

auto DepthFirstSearch( std::map<std::string,std::list<std::string>> Adj ) {
    std::unordered_map<std::string, std::string> parent;
    std::vector<std::pair<std::string,int>> timer ;
    for ( auto s : Adj )
        if (parent.count(s.first) == 0u) {
            parent[s.first] = "";
            DFS_Visit(Adj, s.first, parent, timer);
        }
    return std::make_tuple( parent , timer ) ;
}

void topological_sort( std::map<std::string,std::list<std::string>> Adj ){
    std::cout << std::endl << "Topological sort : " ;
    std::unordered_map<std::string, std::string> parent ;
    std::vector<std::pair<std::string,int>> timer ;
    std::tie( parent , timer ) =  DepthFirstSearch( Adj ) ;
    std::sort( timer.begin() , timer.end() , [](const std::pair<std::string,int> &a , std::pair<std::string,int> &b ){ return a.second > b.second ; } ) ;
    for( auto p : timer )
        std::cout << p.first << " " ;
    std::cout << std::endl ;
}