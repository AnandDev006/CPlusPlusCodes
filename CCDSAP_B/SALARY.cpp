/*
  author : Anand
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

vector<int> a(N);
vector<int> dp(N);
int n;

void solve() {
  cin >> n;
  int sum = 0;
  int minim = INF;
  int temp;
  for(int i = 0 ; i < n ; ++i) {
  	cin >> temp;
  	sum += temp;
  	minim = min(minim, temp);
  }
  cout << sum - n * minim << endl;
}

signed main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int T = 1;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}