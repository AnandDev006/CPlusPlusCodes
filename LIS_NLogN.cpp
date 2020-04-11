/*
    author : Anand
    Longest increasing sub-sequence in N*Log(N) run time
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

void LIS(const vector<int> &v) {
    int len = sz(v);
    vector<int> lis;
    int lis_len = 0;
    vector<int> lis_vals;

    lis.push_back(0);
    lis_vals.push_back(v[0]);
    lis_len = 1;

    for (int i = 1; i < len; ++i) {
        if (v[i] > lis_vals[lis_len - 1]) {
            lis.push_back(i);
            lis_vals.push_back(v[i]);
            ++lis_len;
        } else if (v[i] < lis_vals[0]) {
            lis[0] = i;
            lis_vals[0] = v[i];
        } else {
            int pos = upper_bound(all(lis_vals), v[i]) - lis_vals.cbegin();
            lis[pos] = i;
            lis_vals[pos] = v[i];
        }
    }
    printArray(lis_vals);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    LIS(vector<int>({3, 4, -1, 5, 8, 2, 3, 12, 7, 9, 10}));
    return 0;
}