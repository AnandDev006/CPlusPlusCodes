/*
    author : Anand
    Given an integer array nums, find the contiguous subarray (containing at least one number) which has 
    the largest sum and return its sum.

    Input: [-2,1,-3,4,-1,2,1,-5,4],
    Output: 6
    Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include <bits/stdc++.h>
// #include <math.h>

// #include <iostream>
// #include <vector>
// #include <stack>
// #include <queue>
// #include <set>
// #include <map>
// #include <algorithm>
// #include <functional>
// #include <utility>

#define sz(a) int((a).size())
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define PI 3.1415926535897932384626
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())

using namespace std;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;

const int INF = 1e9 + 5;
const int mod = 1000000007;
const double zero = 10e-9;
const int N = 3e5, M = N;

int maxSubArray(const vector<int>& nums) {
    int bestSum = INT_MIN, sum = 0;
    for (int num : nums) {
        sum += num;
        bestSum = max(bestSum, sum);
        sum = max(sum, 0);
    }
    return bestSum;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    assert(maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) == 6);
    return 0;
}