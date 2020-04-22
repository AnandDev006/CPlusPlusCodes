#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
#endif
}

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int n = nums.size();
        int curSum = 0, ans = 0;
        for( int i = 0 ; i < n ; ++i) {
            curSum += nums[i];
            if( curSum == k) {
                ans++;
            }
            if( m.find(curSum - k) != m.end() ) {
                ans += m[curSum - k];
            }
            m[curSum]++;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}