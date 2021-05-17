/*
  author : Anand
  https://leetcode.com/problems/the-skyline-problem/
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

struct node {
    int x, h, t;
};

void solve(vector<vector<int>> buildings) {
    int n = buildings.size();
    vector<node> nodes;
    for (int i = 0; i < n; ++i) {
        nodes.push_back({buildings[i][0], buildings[i][2], 0});
        nodes.push_back({buildings[i][1], buildings[i][2], 1});
    }
    sort(nodes.begin(), nodes.end(), [&](node A, node B) {
         if(A.x != B.x) return A.x < B.x;
         if(A.t == 0 && B.t == 0) return A.h > B.h;
         if(A.t == 1 && B.t == 1) return A.h < B.h;
         return A.t == 0;

    });
    multiset<int> m;
    m.insert(0);
    int prevMax = 0;
    vector<pair<int, int>> ans;
    for (node X : nodes) {
    	cerr << "\t x : " << X.x << " h : " << X.h << " t : " << X.t << endl;
	    if (X.t == 0) {
	    	m.insert(-X.h);
	    } else {
	        m.erase(m.find(-X.h));
	    }
	    int curMax = -(*m.begin());
	    debug(curMax);
	    if(prevMax !=  curMax) {
	    	ans.push_back({X.x, curMax});
	    	prevMax = curMax;
	    }
    }
    for(auto pt : ans) {
    	cout << pt.first << " " << pt.second << endl;
    }
}

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int T = 1;
    // cin >> T;
    while (T--) {
        // solve({{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}});
        // solve({{0, 2, 3},{0, 1, 2}});
        // solve({{3, 5, 3},{4, 5, 2}});
        // solve({{7, 8, 3},{6, 7, 2}});
        solve({{0, 2, 3},{2, 5, 3}});
    }

    return 0;
}