/*
    author : Anand
    Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

    For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

    Follow-up: what if you can't use division?
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

template <typename T>
bool isEqual(const vector<T> &v1, const vector<T> &v2) {
    auto pair = std::mismatch(v1.begin(), v1.end(), v2.begin());
    return (pair.first == v1.end() && pair.second == v2.end());
}

vector<ll> getUniqueProduct(const vector<ll> &v) {
    int length = sz(v);
    vector<ll> leftProduct(length, 1), rightProduct(length, 1), ans(length, 1);
    for (int i = 1; i < length; ++i)
        leftProduct[i] = leftProduct[i - 1] * v[i - 1];
    for (int i = length - 2; i >= 0; --i)
        rightProduct[i] = rightProduct[i + 1] * v[i + 1];

    for (int i = 0; i < length; ++i) ans[i] = leftProduct[i] * rightProduct[i];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    assert(isEqual(getUniqueProduct(vector<ll>({1, 2, 3, 4, 5})), vector<ll>({120, 60, 40, 30, 24})));
    assert(isEqual(getUniqueProduct(vector<ll>({3, 2, 1})), vector<ll>({2, 3, 6})));
    return 0;
}