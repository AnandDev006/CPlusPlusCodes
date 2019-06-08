/*
    author : Anand
    Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two 
    becomes [3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list. How many swap or 
    move operations do you need?
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

vector<ll> rotateListByK(vector<ll> input, ll k)
{
  printArray(input);
  k %= sz(input);
  list<ll> data(all(input));

  cout << k << " swap operations will be required" << endl;

  while (k-- != 0)
  {
    ll temp = data.front();
    data.pop_front();
    data.push_back(temp);
  }

  printArray(vector<ll>(all(data)));

  return vector<ll>(all(data));
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(rotateListByK({1, 2, 3, 4, 5, 6}, 2) == vector<ll>({3, 4, 5, 6, 1, 2}));

  return 0;
}