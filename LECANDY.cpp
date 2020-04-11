/*
    author : Anand
    https://www.codechef.com/problems/LECANDY
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int N, C;
        cin >> N >> C;
        int req = 0;
        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            req += val;
        }
        if (req <= C) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}