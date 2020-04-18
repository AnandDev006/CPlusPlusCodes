/*
    author : Anand
    Write an algorithm to determine if a number n is "happy".

    A happy number is a number defined by the following process: Starting with any positive 
    integer, replace the number by the sum of the squares of its digits, and repeat the process 
    until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does 
    not include 1. Those numbers for which this process ends in 1 are happy numbers.

    Return True if n is a happy number, and False if not.

    Sol Credits : https://www.youtube.com/watch?v=umt7t1_X8Rc
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

int getDigitSqSum(int n) {
    int ans = 0;
    while (n > 0) {
        int digit = n % 10;
        n /= 10;
        ans += digit * digit;
    }
    return ans;
}

bool isHappy(int n) {
    for (int rep = 0; rep < 20; ++rep) {  // https://www.youtube.com/watch?v=lgjWXi21IAg
        n = getDigitSqSum(n);
        if (n == 1) {
            return true;
        }
    }
    return false;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    assert(isHappy(19));
    return 0;
}