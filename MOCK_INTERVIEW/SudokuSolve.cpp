#include <iostream>
#include <vector>

using namespace std;

vector<char> getCandidates(vector<vector<char>>& board, int r, int c) {
  vector<char> candidates;
  for( char op = '1' ; op <= '9' ; op++) {
    bool valid = true;
    for(int i = 0 ; i < 9 ; i++) {
      if( board[r][i] == op || board[i][c] == op || board[r - r%3 + i/3][c - c%3 + i/3] == op) {
        valid = false;
        break;
      }
    }
    if(valid) {
      candidates.push_back(op);
    }
  }
  return candidates;
}

bool sudokuSolve(const vector<vector<char>>& board ) 
{
  // your code goes here
  int row = -1, col = -1;
  vector<char> candidates;
  for( int r = 0 ; r < 9 ; ++r) {
    for( int c = 0 ; c < 9 ; ++c ) {
      if( board[r][c] == '.') {
        vector<char> newCandidates = getCandidates(board, r, c);
        if(candidates.size() > newCandidates.size()) {
          candidates = newCandidates;
          row = r;
          col = c;
        }
      }
    }
  }
  
  if( row == -1 ) {
    return true;
  }
  
  for( char op : candidates) {
    board[row][col] = op;
    if(sudokuSolve(board)) {
      return true;
    }
    board[row][col] = '.';
  }
  return false;
}

int main() {
  return 0;
