/*
    author : Anand

    Given a word W and a string S, find all starting indices in S which are anagrams of W.
    For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.
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

vector<ll> getAnagramPositions(string W, string S)
{
  vector<ll> positions;
  ll patternLen = S.length();
  ll textLen = W.length();
  multiset<char> pattern(all(S));
  multiset<char> text(W.begin(), W.begin() + patternLen);

  for (ll pos = patternLen; pos < textLen; ++pos)
  {
    if (pattern == text)
    {
      positions.push_back(pos - patternLen);
    }
    text.erase(text.find(W[pos - patternLen]));
    text.insert(W[pos]);
  }
  if (pattern == text)
  {
    positions.push_back(textLen - patternLen);
  }
  printArray(positions);
  return positions;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(getAnagramPositions("abxaba", "ab") == vector<ll>({0, 3, 4}));

  return 0;
}