/*
    author : Anand
    Given a string, return whether it represents a number. Here are the different kinds of numbers:

    "10", a positive integer
    "-10", a negative integer
    "10.1", a positive real number
    "-10.1", a negative real number
    "1e5", a number in scientific notation
    And here are examples of non-numbers:

    "a"
    "x 1"
    "a -2"
    "-"
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

bool checkIfNumber(string num)
{
  ll numLen = sz(num);
  if (numLen == 0)
  {
    return false;
  }

  bool isPositive = true, isInteger = true, isScientific = false;
  ll pos = 0;
  if (num[pos] == '-')
  {
    if (numLen == 1)
    {
      return false;
    }
    isPositive = false;
    ++pos;
  }

  for (; pos < numLen; ++pos)
  {
    // Only 1 '.' allowed
    if (num[pos] == '.')
    {
      if (isInteger && ((isPositive && pos != 0) || (!isPositive && pos != 1)) && pos != (numLen - 1))
      {
        isInteger = false;
      }
      else
      {
        return false;
      }
      continue;
    }

    if (num[pos] == 'e')
    {
      if (!isScientific && ((isPositive && pos != 0) || (!isPositive && pos != 1)) && pos != (numLen - 1))
      {
        isScientific = true;
      }
      else
      {
        return false;
      }
      continue;
    }

    if ((num[pos] - '0') < 0 || (num[pos] - '0') > 9)
    {
      return false;
    }
  }
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(checkIfNumber("22"));
  assert(!checkIfNumber("22."));
  assert(!checkIfNumber("-.22"));
  assert(checkIfNumber("22.22"));
  assert(checkIfNumber("-22.22"));
  assert(checkIfNumber("-1.23e6"));
  assert(!checkIfNumber("-1.2e3e6"));
  assert(!checkIfNumber("-1.2-3e6"));
  assert(!checkIfNumber("-1.2.3e6"));

  return 0;
}