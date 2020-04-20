/*
    author : Anand
    Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.
    

    Example 1:

    Input
    ["MinStack","push","push","push","getMin","pop","top","getMin"]
    [[],[-2],[0],[-3],[],[],[],[]]

    Output
    [null,null,null,null,-3,null,0,-2]

    Explanation
    MinStack minStack = new MinStack();
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    minStack.getMin(); // return -3
    minStack.pop();
    minStack.top();    // return 0
    minStack.getMin(); // return -2
    

    Constraints:

    Methods pop, top and getMin operations will always be called on non-empty stacks.
*/

#include <bits/stdc++.h>

// #include <math.h>

// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <set>
// #include <stack>
// #include <utility>
// #include <vector>

#define sz(a) int((a).size())
#define ll long long
#define pb push_back
#define mp(a, b) make_pair(ll(a), ll(b))
#define F first
#define S second
#define all(c) (c).begin(), (c).end()
#define PI 3.1415926535897932384626

using namespace std;

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

int DP[N];

class MinStack {
    stack<int> minims;
    stack<int> s;

   public:
    /** initialize your data structure here. */

    void push(int x) {
        this->s.push(x);
        if (this->minims.empty()) {
            this->minims.push(x);
        } else {
            if (this->minims.top() >= x) {
                this->minims.push(x);
            }
        }
    }

    void pop() {
        if (!this->s.empty()) {
            if (this->s.top() == this->minims.top()) {
                this->minims.pop();
            }
            this->s.pop();
        }
    }

    int top() {
        return this->s.top();
    }

    int getMin() {
        return this->minims.top();
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    stack<int> s;
    cout << s.top() << endl;
    return 0;
}