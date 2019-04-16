/*
	author : Anand
	We're given a hashmap associating each courseId key with a list of courseIds values, 
	which represents that the prerequisites of courseId are courseIds. Return a sorted 
	ordering of courses such that we can finish all courses.

	Return null if there is no such ordering.

	For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []}, 
	should return ['CSC100', 'CSC200', 'CSCS300']
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

void dfs( ll u, unordered_map< ll, vector< ll > > &preReqTable, unordered_set< ll > &visited, vector< ll > &courseOrder) {
	visited.insert(u);
	for( ll v : preReqTable[u]) {
		if( visited.find(v) != visited.end())
			continue;
		dfs( v, preReqTable, visited, courseOrder);
	}
	courseOrder.push_back(u);
}

void getCourseOrder( unordered_map< ll, vector< ll > > &preReqTable) {
	unordered_set< ll > visited;
	
	vector< ll > courseOrder;

	for( auto x : preReqTable) {
		if( visited.find(x.first) != visited.end())
			continue;
		dfs(x.first, preReqTable, visited, courseOrder);
	}

	for( ll course : courseOrder) {
		cout << course << " : ";
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	unordered_map< ll, vector< ll > > preReqTable = {
		{ 3, { 1, 2}},
		{ 2, {1}},
		{1, {}}
	};

	getCourseOrder( preReqTable);

	return 0;
}