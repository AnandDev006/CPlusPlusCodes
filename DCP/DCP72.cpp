/*
	author : Anand
	In a directed graph, each node is assigned an uppercase letter. We define a path's value as 
	the number of most frequently-occurring letter along that path. For example, if a path in the
	graph goes through "ABACA", the value of the path is 3, since there are 3 occurrences of 'A' on the path.

	Given a graph with n nodes and m directed edges, return the largest value path of the graph. If the 
	largest value is infinite, then return null.

	The graph is represented with a string and an edge list. The i-th character represents the uppercase 
	letter of the i-th node. Each tuple in the edge list (i, j) means there is a directed edge from the 
	i-th node to the j-th node. Self-edges are possible, as well as multi-edges.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair(a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;

#define unVisited 0
#define visiting 1
#define visited 2

void mergeCustom(vector< ll > &pathValues, const vector< ll > &pathValuesTemp ) {
	for( ll i = 0 ; i < 26 ; ++i){
		pathValues[i] = max( pathValues[i], pathValuesTemp[i]);
	}
}

vector< ll > maxValuePathFinder( ll u, unordered_map< ll, vector< ll > > &adjList, const string &g, unordered_map< ll, vector< ll > > &cache, vector< ll> &status) {
	// If already visited cell, take form cache
	if( status[u] == visited) {
		return cache[u];
	}
	// if going in loop => infinite => null answer
	if( status[u] == visiting) {
		cout << "null" << endl;
		exit(0);
	}

	status[u] = visiting;
	vector< ll > pathValues(26, 0);
	ll maxVal = INT_MIN;
	for( auto v : adjList[u]) {
		vector< ll > pathValuesTemp = maxValuePathFinder( v, adjList, g, cache, status);
		mergeCustom( pathValues, pathValuesTemp);
	}
	++pathValues[ g[u] - 'A'];
	// cache result for current node
	cache[u] = pathValues;
	status[u] = visited;
	return pathValues;
}

void maxValuePathFinder_Helper( const vector< pair< ll, ll> > edgeList, const string &g){
	unordered_map< ll, vector< ll > > adjList;
	for( auto edge: edgeList) {
		adjList[ edge.X].push_back( edge.Y);
	}
	unordered_map< ll, vector< ll > > cache;
	ll n = g.length();
	vector< ll> status( n, unVisited);
	ll root, maxVal = INT_MIN;
	char maxValChar;
	for( ll start = 0 ; start < n ; ++start) {
		if( status[start] == unVisited) {
			vector< ll > pathValuesTemp = maxValuePathFinder( start, adjList, g, cache, status);
			auto maxValTemp = max_element(pathValuesTemp.begin(), pathValuesTemp.end());
			if( *maxValTemp > maxVal ) {
				maxVal = *maxValTemp;
				maxValChar = 'A' + (maxValTemp - pathValuesTemp.begin());
				root = start;
			}
		}
	}
	cout << "Root : " << root << endl;
	cout << "MaxVal : " << maxVal << endl;
	cout << "MaxValChar : " << maxValChar << endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector< pair< ll, ll > > edgeList = { {0,3}, {2,0}, {2,1}, {3,4}, {3,6}, {4,5}, {6,7}, {7,5} };
	string g = "CBACABAA";

	maxValuePathFinder_Helper(edgeList, g);

	return 0;
}