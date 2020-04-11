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

int N = 4;
int count = 0;

vector<int> col(N, 0);
vector<int> diag1(2 * N - 1, 0);
vector<int> diag2(2 * N - 1, 0);

void findNQueenSolution(int y) {
    if (y == N) {
        ++::count;
        return;
    }
    for (int x = 0; x < N; ++x) {
        if (col[x] || diag1[x + y] || diag2[x - y + N - 1]) continue;

        col[x] = diag1[x + y] = diag2[x - y + N - 1] = 1;
        findNQueenSolution(y + 1);
        col[x] = diag1[x + y] = diag2[x - y + N - 1] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    findNQueenSolution(0);
    cout << ::count << endl;
    return 0;
}