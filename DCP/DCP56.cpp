/*

Given an undirected graph represented as an adjacency matrix and an integer k, write a function to determine
 whether each vertex in the graph can be colored such that no two adjacent vertices share the same color using at most k colors.

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

#define V 4

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

bool isSafe (int v, bool graph[V][V], vi &colors, int c) { 
    for ( int i = 0 ; i < V ; i++ )
        if (graph[v][i] && c == colors[i])
            return false;
    return true;
}

bool graphColoringUtil( bool graph[V][V], int m, vi &colors, const int &v){

    if( v == V)
        return true;
    
    for (ll c = 1; c <= m; c++)
    { 
        if (isSafe(v, graph, colors, c))
        { 
           colors[v] = c;
  
           if (graphColoringUtil (graph, m, colors, v+1))
             return true;

           colors[v] = 0;
        }
    }

    return false; 
}

void printSolution(vi colors) {

    cout << "Solution Exists: Following are the assigned colors" << endl ; 
    
    for( int color : colors)
        cout << color << " : ";
}

bool graphColoring(bool graph[V][V], int m) {

    vi colors(V, 0);

    if (!graphColoringUtil(graph, m, colors, 0)) {
        cout << "Solution does not exist" << endl;
        return false;
    }
  
    printSolution(colors);
    
    return true; 
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    bool graph[V][V] = {{0, 1, 1, 1}, 
                        {1, 0, 1, 0}, 
                        {1, 1, 0, 1}, 
                        {1, 0, 1, 0},
                        };

    int m = 3;
    graphColoring (graph, m);

    return 0;
}