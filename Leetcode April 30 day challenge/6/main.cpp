/*
    author : Anand
    
    Say you have an array prices for which the ith element is the price of a given stock on day i.

    Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
    (i.e., buy one and sell one share of the stock multiple times).

    Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before 
    you buy again).

    Example 1:

    Input: [7,1,5,3,6,4]
    Output: 7
    Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
                Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
    Example 2:

    Input: [1,2,3,4,5]
    Output: 4
    Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
                Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
                engaging multiple transactions at the same time. You must sell before buying again.
    Example 3:

    Input: [7,6,4,3,1]
    Output: 0
    Explanation: In this case, no transaction is done, i.e. max profit = 0.
    

    Constraints:

    1 <= prices.length <= 3 * 10 ^ 4
    0 <= prices[i] <= 10 ^ 4
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

int maxProfit(const vector<int>& prices) {
    int stock = INT_MIN, noStock = 0;
    for (int price : prices) {
        stock = max(stock, noStock - price);
        noStock = max(noStock, stock + price);
    }
    return noStock;
}

int main() {
    // #ifndef ONLINE_JUDGE
    //     freopen("main.inp", "r", stdin);
    //     freopen("main.out", "w", stdout);
    // #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    assert(maxProfit({7, 1, 5, 3, 6, 4}) == 7);
    assert(maxProfit({1, 2, 3, 4, 5}) == 4);
    assert(maxProfit({7, 6, 4, 3, 1}) == 0);
    return 0;
}