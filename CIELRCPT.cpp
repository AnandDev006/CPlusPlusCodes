/*
    author : Anand
    https://www.codechef.com/problems/CIELRCPT
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

    int menu[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
    int T;
    cin >> T;
    while (T--) {
        int p;
        cin >> p;
        int menuSize = 0;
        for (int i = 12 - 1; i >= 0; --i) {
            if (p >= menu[i]) {
                menuSize += p / menu[i];
                p %= menu[i];
            }
        }
        cout << menuSize << "\n";
    }

    return 0;
}