/*
    author : Anand
    Given a 2D board of characters and a word, find if the word exists in the grid.

    The word can be constructed from letters of sequentially adjacent cell, where 
    "adjacent" cells are those horizontally or vertically neighboring. The same 
    letter cell may not be used more than once.
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

struct hash_pair { 
    template <class T1, class T2> 
    size_t operator()(const pair<T1, T2>& p) const
    { 
        auto hash1 = hash<T1>{}(p.first); 
        auto hash2 = hash<T2>{}(p.second); 
        return hash1 ^ hash2; 
    } 
};

unordered_map< char, vector< pair< ll, ll > > > startPosMap;
unordered_set< pair< ll, ll >, hash_pair > visited;

void preCompute( const vector< vector< char > > &board) {
    startPosMap.clear();
    ll rows = sz(board);
    ll cols = sz(board[0]);
    for( ll i = 0 ; i < rows ; ++i ) {
        for( ll j = 0 ; j < cols ; ++j ) {
            startPosMap[board[i][j]].push_back( mp( i, j));
        }
    }
}

bool isValid( ll row, ll col, const vector< vector< char > > &board, ll rows, ll cols, char c) {
    return ( !present( visited, mp(row, col)) && row >= 0 && col >= 0 && row < rows && col < cols && board[row][col] == c );
}

bool dfs( pair< ll, ll > u, ll curLen, string word, ll wordLen, const vector< vector< char > > &board, ll rows, ll cols) {
    if( curLen == wordLen) {
        return true;
    }
    visited.insert(u);
    ll R = u.X;
    ll C = u.Y;
    int r[] = { 0, 1, 0, -1};
    int c[] = { 1, 0, -1, 0};
    for( int i = 0 ; i < 4 ; ++i ) {
        if( isValid( R + r[i], C + c[i], board, rows, cols, word[curLen])) {
            if( dfs( mp( R + r[i], C + c[i]), curLen + 1, word, wordLen, board, rows, cols)) {
                return true;
            }
        }
    }
    visited.erase( u);
    return false;
}

bool exists( const vector< vector< char > > &board, string word) {
    ll rows = sz(board);
    ll cols = sz(board[0]);
    vector< pair< ll, ll > > startPos = startPosMap[word[0]];

    for( pair< ll, ll > start : startPos ) {
        visited.clear();
        if( dfs( start, 1, word, word.length(), board, rows, cols)) {
            return true;
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< vector< char > > board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}
    };

    preCompute( board);

    assert( exists(board, "ABCCED"));
    assert( exists(board, "SEE"));
    assert( !exists(board, "ABCB"));

    return 0;
}