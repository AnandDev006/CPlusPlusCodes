/*
    author : Anand
    https://www.codechef.com/problems/CHEFST
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
#ifndef ONLINE_JUDGE
    freopen("main.inp", "r", stdin);
    freopen("main.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        ll n1, n2, m;
        cin >> n1 >> n2 >> m;
        ll minim = min(n1, n2);
        ll maxRemovable = m * (m + 1) / 2;
        if (maxRemovable > min(n1, n2))
            cout << max(n1, n2) - min(n1, n2) << '\n';
        else
            cout << n1 + n2 - 2 * maxRemovable << '\n';
    }

    return 0;
}