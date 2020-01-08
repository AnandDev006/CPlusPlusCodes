/*
    author : Anand
    Given a string which we can delete at most k, return whether you can make a palindrome.

    For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.
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

// longest common subsequence between input and its reverse
bool canBeMadePalindromeInKDeleteions(string input, ll k)
{
  ll inputLen = input.length();
  string a = input;
  reverse(all(input));
  string b = input;
  vector<vector<ll>> DP(inputLen + 1, vector<ll>(inputLen + 1, 0));

  for (ll i = 1; i <= inputLen; ++i)
  {
    for (ll j = 1; j <= inputLen; ++j)
    {
      if (a[j - 1] == b[i - 1])
      {
        DP[i][j] = 1 + DP[i - 1][j - 1];
      }
      else
      {
        DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
      }
    }
  }
  cout << inputLen - DP[inputLen][inputLen] << endl;
  return ((inputLen - DP[inputLen][inputLen]) <= k);
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(canBeMadePalindromeInKDeleteions("waterrfetawx", 2));
  assert(canBeMadePalindromeInKDeleteions("abac", 2));

  return 0;
}