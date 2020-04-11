/*
	author : Anand

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }
        int pivot = -1;
        for (int i = N - 1; i > 0; --i) {
            if (v[i - 1] < v[i]) {
                pivot = i - 1;
                int swapPos = N - 1;
                for (int j = i; j < N - 1; ++i) {
                    if (v[j] > v[pivot] && v[j + 1] < v[pivot]) {
                        swapPos = j;
                        break;
                    }
                }
                swap(v[pivot], v[swapPos]);
                reverse(v.begin() + i, v.end());
                break;
            }
        }
        if (pivot == -1)
            cout << "-1\n";
        else
            printArray(v);
    }

    return 0;
}