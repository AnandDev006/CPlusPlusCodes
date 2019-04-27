#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define X first
#define Y second

using namespace std;

inline void debug()
{
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
}

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T;
    cin >> T;
    while (T--)
    {
        ll X, Y, K, N;
        cin >> X >> Y >> K >> N;
        bool flag = false;
        while (N--)
        {
            ll P, C;
            cin >> P >> C;
            if (P >= (X - Y) && C <= K)
            {
                flag = true;
                break;
            }
        }
        if (flag)
        {
            cout << "LuckyChef" << endl;
        }
        else
        {
            cout << "UnluckyChef" << endl;
        }
    }

    return 0;
}