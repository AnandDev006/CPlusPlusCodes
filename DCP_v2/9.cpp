/*
    author : Anand

    Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

    For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

    Follow-up: Can you do this in O(N) time and constant space?

*/

#include <bits/stdc++.h>

#define zero 10e-9
#define sz(a) int((a).size())
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int largestSumNonAdjacentNums(const vector<int> &v) {
    int sumWith = 0, sumWithout = 0, temp = 0;
    for (int x : v) {
        temp = sumWith;
        sumWith = sumWithout + x;
        sumWithout = max(temp, sumWithout);
    }
    return max(sumWith, sumWithout);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    assert(largestSumNonAdjacentNums(vector<int>({2, 4, 6, 2, 5})) == 13);
    assert(largestSumNonAdjacentNums(vector<int>({5, 1, 1, 5})) == 10);

    return 0;
}