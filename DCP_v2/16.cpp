/*
  author : Anand

    Problem 16
    This problem was asked by Twitter.

    You run an e-commerce website and want to record the last N order ids in a log. Implement a data structure to accomplish this, with the following API:

    record(order_id): adds the order_id to the log get_last(i): gets the ith last element from the log. i is guaranteed to be smaller than or equal to N. You should be as efficient with time and space as possible.
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

class Logger {
    int size;
    vector<int> logs;

   public:
    Logger(int _size) {
        size = _size;
    }
    void record(int order_id) { // ammortised O(1);
        logs.push_back(order_id);
        int n = logs.size();
        if (n == 2 * size) {
            logs.assign(logs.end() - size, logs.end());
        }
    }
    int get_last(int i) { // O(1)
        int n = logs.size();
        return logs[n - i];
    }
    vector<int> getLogs() {
        int n = logs.size();
        if(n > size) {
            logs.assign(logs.end() - size, logs.end());
        }
        return logs;
    }
};

template <typename T>
bool isVectorEqual(vector<T> v1, vector<T> v2) { return v1 == v2; }

void solve() {
    Logger log(5);
    log.record(1);
    log.record(2);
    assert(isVectorEqual(log.getLogs(), {1, 2}));
    log.record(3);
    log.record(4);
    log.record(5);
    assert(isVectorEqual(log.getLogs(), {1, 2, 3, 4, 5}));
    log.record(6);
    log.record(7);
    log.record(8);
    assert(isVectorEqual(log.getLogs(), {4, 5, 6, 7, 8}));
    assert(log.get_last(4) == 5);
    assert(log.get_last(1) == 8);
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