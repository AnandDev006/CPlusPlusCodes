/*
    author : Anand

    Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways it can be decoded.

    For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.

    You can assume that the messages are decodable. For example, '001' is not allowed.

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

ll numberOfWaysToDecode(const string &s, int pos = 0) {
    ll ans = 0;
    if (pos == sz(s) - 1) return 1;
    if (pos == sz(s) - 2) return (stoi(s.substr(pos, 2)) > 26 ? 1 : 2);
    ans += numberOfWaysToDecode(s, pos + 1);
    if (stoi(s.substr(pos, 2)) <= 26) {
        ans += numberOfWaysToDecode(s, pos + 2);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    assert(numberOfWaysToDecode("111") == 3);
    assert(numberOfWaysToDecode("81") == 1);
    assert(numberOfWaysToDecode("6") == 1);
    assert(numberOfWaysToDecode("21") == 2);

    return 0;
}