/*
    author : Anand
    Given an array of numbers representing the stock prices of a company in chronological order and an integer k, 
    return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it, 
    and you must sell the stock before you can buy it again.

    For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.
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

ll maximiseProfitBuySellStock_K_Transactions(const vector<ll> &stockPrices, ll numOfTransactions)
{
  ll numOfDays = sz(stockPrices);
  vector<vector<ll>> DP(numOfTransactions + 1, vector<ll>(numOfDays, 0));
  for (ll i = 1; i <= numOfTransactions; ++i)
  {
    for (ll j = 1; j < numOfDays; ++j)
    {
      if (j < i)
      {
        DP[i][j] = DP[i - 1][j];
      }
      else
      {
        DP[i][j] = max(DP[i][j], max(DP[i - 1][j], DP[i][j - 1]));
        for (ll k = 0; k < j; ++k)
        {
          DP[i][j] = max(DP[i][j], DP[i - 1][k] + (stockPrices[j] - stockPrices[k]));
        }
      }
    }
  }
  cout << DP[numOfTransactions][numOfDays - 1] << endl;
  return DP[numOfTransactions][numOfDays - 1];
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(maximiseProfitBuySellStock_K_Transactions({5, 2, 4, 0, 1}, 2) == 3);

  return 0;
}