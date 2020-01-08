/*
    author : Anand
    Given two strings A and B, return whether or not A can be shifted some number of times to get B.
    For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.
*/

#include <bits/stdc++.h>

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

void printArray(const vector<ll> &arr)
{
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

bool isShiftMatchable(string A, string B)
{
    if (A.length() != B.length())
    {
        return false;
    }

    ll len = A.length();

    ll posA = 0, posB = 0;

    while (posB < len)
    {
        if (A[posA] == B[posB++])
        {
            --posB;
            break;
        }
    }

    while (posA < len)
    {
        if (A[posA++] != B[posB++])
        {
            return false;
        }

        if (posB == len)
        {
            posB = 0;
        }
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert(isShiftMatchable("abcde", "cdeab"));
    assert(!isShiftMatchable("abc", "acb"));

    return 0;
}