/*
  author : Anand

    Problem 14
    This problem was asked by Google.

    The area of a circle is defined as r^2. Estimate \pi to 3 decimal places using a Monte Carlo method.

    Hint: The basic equation of a circle is x^2 + y^2 = r^2.
*/

#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define int long long
#define ll long long

#ifndef ONLINE_JUDGE
#define debug(...) cerr << "\t" << #__VA_ARGS__ << " : " << (__VA_ARGS__) << endl;
#else
#define debug(...) 42
#endif

const int INF = 1e18 + 5;
const int MOD = 1000000007;
const int N = 1e7;
const int K = 25;

double estimatePI(int iterations) {
    double cirPts = 0, sqPts = 0;
    srand(time(NULL));
    double x, y;
    for(int i = 0 ; i < iterations ; ++i) {
        x = ((double) rand() / (RAND_MAX));
        y = ((double) rand() / (RAND_MAX));
        if(x*x + y*y <= 1) {
            ++cirPts;
        }
        ++sqPts;
    }
    return 4 * (cirPts) / sqPts;
}

void solve() {
  cout << estimatePI(1e2) << endl;
  cout << estimatePI(1e3) << endl;
  cout << estimatePI(1e4) << endl;
  cout << estimatePI(1e5) << endl;
  cout << estimatePI(1e6) << endl;
  cout << estimatePI(1e7) << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  // cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}