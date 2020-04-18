/*
    author : Anand
    Given an array nums, write a function to move all 0's to the end of it while maintaining the 
    relative order of the non-zero elements.
    Input: [0,1,0,3,12]
    Output: [1,3,12,0,0]
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

void moveZeroes(vector<int> &nums) {
    int pos = 0, n = nums.size();
    for (int num : nums) {
        if (num != 0) {
            nums[pos++] = num;
        }
    }
    for (; pos < n; ++pos)
        nums[pos] = 0;
}

template <typename T>
bool isEqual(const vector<T> &v1, const vector<T> &v2) {
    auto pair = std::mismatch(v1.begin(), v1.end(), v2.begin());
    return (pair.first == v1.end() && pair.second == v2.end());
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vi arr({0, 1, 0, 3, 12});
    moveZeroes(arr);
    assert(isEqual(arr, {1, 3, 12, 0, 0}));
    return 0;
}