/*
    author : Anand
    Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"
    Follow-up: given a mutable string representation, can you perform this operation in-place?
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

string reverseOrderOfWords(string input)
{
  reverse(all(input));
  ll inputLen = input.length();
  for (ll left = 0, right = 0; right <= inputLen; ++right)
  {
    if (input[right] == ' ' || right == inputLen)
    {
      reverse(input.begin() + left, input.begin() + right);
      left = right + 1;
    }
  }
  cout << input << endl;
  return input;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(reverseOrderOfWords("hello world here").compare("here world hello") == 0);

  return 0;
}
