#include <iostream>
#include <unordered_map>
#include <set>
#include <queue>
#define MAXN 6

using namespace std;

struct Node{
    int data;
    int rank;
    Node* parent;
};

class disjointset{
    unordered_map<int,Node*> HashMap;
public:
    void makeset( int data );
    Node* findset(int data);
    bool unionset( int x , int y);
};

void disjointset :: makeset( int data ){
    Node* newnode = new Node;
    newnode->data = data ;
    newnode->parent = newnode;
    newnode->rank = 0;
    HashMap[newnode->data] = newnode;
}

Node* disjointset :: findset( int data ){
    Node* node = HashMap[data] ;
    if( node == node->parent )
        return node ;
    node->parent = findset( node->parent->data );
    return node->parent ;
}

bool disjointset :: unionset( int x , int y){
    Node* parentX = findset( x ) ;
    Node* parentY = findset( y ) ;
    if( parentX == parentY )
        return false;
    if( parentX->rank >= parentY->rank ){
        parentX->rank = parentX->rank == parentY->rank ? parentX->rank + 1 : parentX->rank ;
        parentY->parent = parentX ;
    }
    else{
        parentY->rank = parentY->rank + 1;
        parentX->parent = parentY;
    }
    return true;
}

auto cmp = []( pair< pair< int, int>, int> left, pair< pair< int, int>, int> right) { return left.second > right.second ; };

typedef priority_queue< pair< pair< int, int>, int>, vector< pair< pair< int, int>, int>>, decltype(cmp)> PriQ;

PriQ Q(cmp);
disjointset DJ;

void addEdge( int x, int y, int w){
    Q.push( make_pair( make_pair( x, y), w));
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

void init(){
    for( int i = 0 ; i < MAXN ; ++i )
        DJ.makeset( i );
}

void MST_Kruksal(){
    pair< pair< int, int>, int> E;
    set< pair< int, int>> S;
    init();
    while( !Q.empty() ){
        E = Q.top();
        Q.pop();
        if ( DJ.unionset( E.first.first, E.first.second ) )
            S.insert( E.first ) ;
    }
}

int main() {
    make_graph();
    MST_Kruksal();
    return 0;
}