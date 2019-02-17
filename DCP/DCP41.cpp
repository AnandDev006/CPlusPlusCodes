/*
Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, and a starting airport, 
compute the person's itinerary. If no such itinerary exists, return null. If there are multiple possible itineraries, return the 
lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and starting airport 
'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', you should return the 
list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. However, the first one is lexicographically 
smaller.
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

void dfs_util( unordered_map< string, set< string > > &G, const string &src, vector< string > path, unordered_map< pair< string, string >, bool > visited, int numOfFlights){
    
    if( sz(path) == numOfFlights){
        for( auto loc : path){
            cout << loc << " " ;
        }
    }

    for( auto dest : G[src]){
        if( visited[make_pair(src,dest)] )
            continue;
        
        visited[make_pair(src,dest)] = true;
        path.push_back(dest);

        dfs_util( G, dest, path, visited, numOfFlights);

        visited[make_pair(src,dest)] = false;
        path.pop_back();
    }
}

void dfs( unordered_map< string, set< string > > &G, string src, int numOfFlights){
    vector< string > path;
    unordered_map< pair< string, string >, bool > visited;
    path.push_back(src);
    for( auto dest : G[src]){
        visited[make_pair(src,dest)] = true;
        path.push_back(dest);
        
        dfs_util( G, dest, path, visited, numOfFlights);

        visited[make_pair(src,dest)] = false;
        path.pop_back();
    }
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // vector< pair< string, string > > input = { {"SFO", "HKO"}, {"YYZ", "SFO"}, {"YUL", "YYZ"}, {"HKO", "ORD"} };
    vector< pair< string, string > > input = { {"A", "B"}, {"A", "C"}, {"B", "C"}, {"C", "A"} };
    int numOfFlights = sz(input) + 1;
    string start = "A";

    unordered_map< string, set< string > > G;
    
    for( auto flight : input){
        G[flight.X].insert(flight.Y);
    }

    dfs(G, start, numOfFlights);

    return 0;
}