/*
 * https://www.hackerrank.com/challenges/even-tree/problem
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adj[100];
bool visited[100];
int count;

void read(){
    int N, M, x, y;
    cin >> N >> M;
    for(int i = 0; i < M; ++i){
        cin >> x >> y;
        adj[y].push_back(x);
    }
}

int fun(int s = 1){
    if( adj[s].empty() )
        return 1;
    queue<int> Q;
    visited[s] = true;
    int subTot = 0, S = 0;
    for( auto v : adj[s])
        Q.push(v);
    int u;
    while( !Q.empty() ){
        u = Q.front();
        Q.pop();
        S = fun(u) ;
        if( S % 2 == 0 ){
            ++count;
            for( auto it = adj[s].begin(); it != adj[s].end() ; ++it ){
                if( *it == u ) {
                    adj[s].erase(it);
                    break;
                }
            }
        }
        else
            subTot += S;
    }

    return subTot+1;
}

int main() {
    read();
    fun();
    cout << count << endl;
    return 0;
}