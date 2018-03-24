#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N;
    cin >> N;

    set<int> primes;

    vector<int> arr(N + 1);
    for (int i = 1; i <= N; ++i)
        arr[i] = i;

    vector<multiset<int>> PF(N + 1);
    bool marked[N + 1];
    memset(marked, false, sizeof(marked));

    marked[1] = true;

    for (int i = 2; i <= N; ++i)
    {
        if (!marked[i])
        {
            marked[i] = true;
            primes.insert(i);
            PF[i].insert(i);
            for (int j = 2 * i; j <= N; j += i)
            {
                marked[j] = true;
                while (arr[j] % i == 0)
                {
                    PF[j].insert(i);
                    arr[j] /= i;
                }
            }
        }
    }
    for (int i = 2; i <= N; ++i)
    {
        cout << endl
             << i << " = ";
        for (auto x = PF[i].begin(); x != PF[i].end(); x = PF[i].upper_bound(*x))
            cout << *x << "^" << PF[i].count(*x) << " * ";
        cout << "1^1";
    }
    return 0;
}