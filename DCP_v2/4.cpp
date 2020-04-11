/*
    author : Anand
    Given an array of integers, find the first missing positive integer in linear time and constant space. In other words, find the lowest positive integer that does not exist in the array. The array can contain duplicates and negative numbers as well.

    For example, the input [3, 4, -1, 1] should give 2. The input [1, 2, 0] should give 3.

    You can modify the input array in-place.
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
void printArray(const vector<T> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]\n";
}

vector<ll> getPositiveSubsetArray(const vector<ll> &v) {
    int i = 0, j = sz(v) - 1;
    vector<ll> tempVec = vector<ll>(v.cbegin(), v.cend());
    while (i < j) {
        if (tempVec[i] > 0 && tempVec[j] <= 0) {
            swap(tempVec[i], tempVec[j]);
            ++i;
            --j;
        } else if (tempVec[i] > 0)
            --j;
        else
            ++i;
    }
    int pivot = tempVec[i] > 0 ? i : i + 1;
    return vector<ll>(tempVec.cbegin() + pivot, tempVec.cend());
}

ll getFirstMissingPositiveNumber(const vector<ll> &v) {
    if (sz(v) == 0) return 1;
    vector<ll> v2 = getPositiveSubsetArray(v);
    if (sz(v2) == 0) return 1;
    for (int i = 0; i < sz(v2); ++i)
        if (abs(v2[i]) - 1 < sz(v2) && v2[abs(v2[i]) - 1] > 0) v2[abs(v2[i]) - 1] *= -1;
    for (int i = 0; i < sz(v2); ++i)
        if (v2[i] > 0) return i + 1;
    return sz(v2) + 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    assert(getFirstMissingPositiveNumber(vector<ll>({3, 4, -1, 1})) == 2);
    assert(getFirstMissingPositiveNumber(vector<ll>({1, 2, 0})) == 3);
    assert(getFirstMissingPositiveNumber(vector<ll>({1, 2, 5})) == 3);
    assert(getFirstMissingPositiveNumber(vector<ll>({1})) == 2);
    assert(getFirstMissingPositiveNumber(vector<ll>({-1, -2})) == 1);
    assert(getFirstMissingPositiveNumber(vector<ll>({})) == 1);
    return 0;
}