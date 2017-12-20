// http://www.spoj.com/problems/PARADOX/

#include <bits/stdc++.h>

using namespace std;

int main() {
    pair < int, bool> input[101];
    int n;
    cin >> n;
    string s;
    for( int i = 1 ; i <= n ; ++i) {
        cin >> input[i].first >> s;
        if( s == "false" )
            input[i].second = false;
        else if( s == "true" )
            input[i].second = true;
    }

    bool visited[101] ;
    bool visit_set_pos[101];

    for( int i = 0 ; i <= 101 ; ++i)
        visited[i] = false;

    visited[1] = true;
    visit_set_pos[1] = true;

    int prev = 1;
    int next = input[1].first;

    while( true ){
        if( visited[next] ){
            if( visit_set_pos[next] != input[prev].second )
                cout << "PARADOX" << endl;
            else
                cout << "NOT PARADOX" << endl;
            break;
        }

        visit_set_pos[next] = input[prev].second;
        visited[next] = true;

        if(!input[prev].second)
            input[next].second = !input[next].second ;

        prev = next;
        next = input[prev].first;
    }
    return 0;
}