// http://www.spoj.com/problems/PARADOX/

#include <bits/stdc++.h>

using namespace std;

bool check( bool start, pair<int, bool> input[] ) {
    bool visited[100001];
    bool visit_set_pos[100001];

    memset( visited, false, sizeof( visited ));

    visited[1] = true;
    visit_set_pos[1] = start;

    int prev = 1;
    int next = input[1].first;

    while (true) {
        if (visited[next]) {
            if (visit_set_pos[next] != input[prev].second)
                return true;
            return false;
        }

        visit_set_pos[next] = input[prev].second;
        visited[next] = true;

        if (!input[prev].second)
            input[next].second = !input[next].second;

        prev = next;
        next = input[prev].first;

    }
}

int main() {
    pair<int, bool> input[101];
    int n;
    bool paradox = false;
    while (true) {
        cin >> n;
        if( n == 0 )
            break;
        string s;
        for (int i = 1; i <= n; ++i) {
            cin >> input[i].first >> s;
            if (s == "false")
                input[i].second = false;
            else if (s == "true")
                input[i].second = true;
        }
        paradox = check( true, input);
        if( !paradox )
            paradox = check( false, input);
        if( paradox )
            cout << "PARADOX" << endl;
        else
            cout << "NOT PARADOX" << endl;
    }

    return 0;
}