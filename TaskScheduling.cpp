/*
    author : Anand
    Scheduling tasks
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

int getMaxSchedulesPossible(const vector<pair<int, int>> &schedules) {
    vector<pair<int, int>> v(schedules.begin(), schedules.end());
    sort(v.begin(), v.end(), [](pair<int, int> a, pair<int, int> b) { return a.Y < b.Y; });
    int count = 1;
    int curEnd = v[0].Y;
    for (int i = 1; i < sz(v); ++i) {
        if (v[i].X > curEnd) {
            ++count;
            curEnd = v[i].Y;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    assert(getMaxSchedulesPossible(vector<pair<int, int>>({mp(1, 3), mp(2, 5), mp(3, 9), mp(6, 8)})) == 2);

    return 0;
}