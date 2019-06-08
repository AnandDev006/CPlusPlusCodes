/*
    author : Anand
    You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], 
    and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

    For example, in this matrix

    0 3 1 1
    2 0 0 4
    1 5 3 1
    The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins
*/

#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

void printArray(const vector<ll> &arr)
{
  cout << "[ ";
  for (ll i = 0; i < sz(arr) - 1; ++i)
  {
    cout << arr[i] << ", ";
  }
  cout << arr[sz(arr) - 1] << " ]" << endl;
}

ll findMaxCoinsCollectible(vector<vector<ll>> grid)
{
  for (ll i = 0; i < sz(grid); ++i)
  {
    for (ll j = 0; j < sz(grid[0]); ++j)
    {
      if (i == 0 && j == 0)
      {
        continue;
      }
      else if (i == 0)
      {
        grid[i][j] += grid[i][j - 1];
      }
      else if (j == 0)
      {
        grid[i][j] += grid[i - 1][j];
      }
      else
      {
        grid[i][j] += max(grid[i - 1][j], grid[i][j - 1]);
      }
    }
  }
  cout << grid[sz(grid) - 1][sz(grid[0]) - 1] << endl;
  return grid[sz(grid) - 1][sz(grid[0]) - 1];
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(findMaxCoinsCollectible({{0, 3, 1, 1}, {2, 0, 0, 4}, {1, 5, 3, 1}}) == 12);

  return 0;
}