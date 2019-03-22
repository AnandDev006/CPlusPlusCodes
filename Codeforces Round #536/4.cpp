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

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef long long ll;

vi g[100005];
bool visited[100005];

int main(){

	debug();

	int n, m;
	cin >> n >> m;

	int u, v;
	for( int i = 0 ; i < m ; ++i ){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	priority_queue< int, vi, greater<int> > q;

	q.push(1);
	visited[1] = true;

	while( !q.empty()){
		cout << q.top() << " ";
		int u = q.top();
		q.pop();
		for( int v : g[u]){
			if( !visited[v]){
				q.push(v);
				visited[v] = true;
			}
		}
	}
	
    return 0;
}