/*
    author : Anand
    Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. For example,
    given "hello/world:here", return "here/world:hello"

    Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"
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

string reverseOrderOfWordsWithAnyPossibleDelimiterCharacter(string input)
{

  cout << input << " : ";

  ll inputLen = input.length();
  ll rBegin, rEnd, delimiterPos;

  rEnd = inputLen - 1;
  delimiterPos = 0;

  string reversedString = "";

  while (!isalpha(input[rEnd]))
  {
    --rEnd;
  }

  rBegin = rEnd;

  while (rEnd >= 0)
  {
    if (!isalpha(input[rEnd]))
    {
      reversedString += input.substr(rEnd + 1, rBegin - rEnd);
      while (isalpha(input[delimiterPos]))
      {
        ++delimiterPos;
      }
      ll left = delimiterPos;
      while (!isalpha(input[delimiterPos]))
      {
        ++delimiterPos;
      }
      reversedString += input.substr(left, delimiterPos - left);
      while (!isalpha(input[rEnd]))
      {
        --rEnd;
      }
      rBegin = rEnd;
    }
    --rEnd;
  }

  reversedString += input.substr(rEnd + 1, rBegin - rEnd);
  while (isalpha(input[delimiterPos]))
  {
    ++delimiterPos;
  }
  reversedString += input.substr(delimiterPos, inputLen - delimiterPos);

  cout << reversedString << endl;
  return reversedString;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(reverseOrderOfWordsWithAnyPossibleDelimiterCharacter("here/world:hello").compare("hello/world:here") == 0);
  assert(reverseOrderOfWordsWithAnyPossibleDelimiterCharacter("hello/world:here/").compare("here/world:hello/") == 0);
  assert(reverseOrderOfWordsWithAnyPossibleDelimiterCharacter("hello//world:here").compare("here//world:hello") == 0);

  return 0;
}