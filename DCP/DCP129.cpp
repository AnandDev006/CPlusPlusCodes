/*
    author : Anand
    Given a real number n, find the square root of n.
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

bool almostEqual(double calculated, double actual)
{
  static double tolerance = 10e-6;
  return ((calculated < actual + tolerance) && (calculated > actual - tolerance));
}

double squareRootHelper(double n, double start, double end)
{
  double mid = (start + end) / 2;
  if (almostEqual(mid * mid, n))
  {
    return mid;
  }
  else if (mid * mid < n)
  {
    return squareRootHelper(n, mid, end);
  }
  else
  {
    return squareRootHelper(n, start, mid);
  }
}

double squareRoot(double n)
{

  if (n == 0 || n == 1)
  {
    return n;
  }

  double ans = squareRootHelper(n, 0, (n < 4) ? n : n / 2);
  cout << setprecision(7) << ans << endl;
  return ans;
}

int main()
{

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  assert(almostEqual(squareRoot(9), 3));
  assert(almostEqual(squareRoot(2), 1.414215));
  assert(almostEqual(squareRoot(10), 3.162279));

  return 0;
}