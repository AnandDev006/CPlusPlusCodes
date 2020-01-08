/*
    author : Anand
    Write a function that prints out all the steps necessary to complete the Tower of Hanoi. You should assume that the rods are numbered, with the first rod being 1, the second (auxiliary) rod being 2, and the last (goal) rod being 3.

    For example, with n = 3, we can do this in 7 moves:

    Move 1 to 3
    Move 1 to 2
    Move 3 to 2
    Move 1 to 3
    Move 2 to 1
    Move 2 to 3
    Move 1 to 3
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

void towerOfHanoi(ll n, char from = 'A', char aux = 'B', char to = 'C')
{
  if (n == 1)
  {
    cout << "Move disk 1 from " << from << " to " << to << endl;
    return;
  }
  towerOfHanoi(n - 1, from, to, aux);
  cout << "Move disc " << n << " from " << from << " to " << to << endl;
  towerOfHanoi(n - 1, aux, from, to);
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  towerOfHanoi(4);

  return 0;
}