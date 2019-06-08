/*
    author : Anand
    Given a sorted list of integers, square the elements and give the output in sorted order.
    For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].
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

vector<ll> squareAndSortAscending(vector<ll> input)
{
  ll left = 0, right = sz(input) - 1;
  vector<ll> squareSortedList;
  while (left <= right)
  {
    if (input[left] * input[left] <= input[right] * input[right])
    {
      squareSortedList.push_back(input[right] * input[right--]);
    }
    else
    {
      squareSortedList.push_back(input[left] * input[left++]);
    }
  }
  reverse(all(squareSortedList));
  printArray(squareSortedList);
  return squareSortedList;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(squareAndSortAscending(vector<ll>({-9, -2, 0, 2, 3})) == vector<ll>({0, 4, 4, 9, 81}));

  return 0;
}