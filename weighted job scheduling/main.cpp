#include <bits/stdc++.h>

using namespace std;

int DP[1005];
pair< pair< int, int>, int> input[1005]; // start , finish , value
int N;

auto cmp = []( pair< pair< int, int>, int> a, pair< pair< int, int>, int> b){ return a.first.second < b.first.second; };

bool overlap( int a, int b){
    return input[a].first.second > input[b].first.first;
}

int main() {
    cin >> N;
    int i, j;
    for( i = 0 ; i < N ; ++i )
        cin >> input[i].first.first >> input[i].first.second >> input[i].second ;

    sort( input, input+N, cmp);

    for( i = 0 ; i < N ; ++i )
        DP[i] = input[i].second ;
    for( i = 1 ; i < N ; ++i){
        for( j = 0 ; j < i ; ++j ){
            if( overlap( j, i) )
                continue;
            else
                DP[i] = max( DP[i], DP[j] + input[i].second );
        }
    }
    int result = *max_element(DP, DP + N);
    cout << result << endl;
    return 0;
}