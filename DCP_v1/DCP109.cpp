/*
    author : Anand
    Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, 
    the 3rd and 4th bit should be swapped, and so on.

    For example, 10101010 should be 01010101. 11100010 should be 11010001.
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

string shiftOddEven(string input)
{
    ll num = bitset<8>(input).to_ulong();
    ll even = 170; // 10101010
    ll odd = 85;   // 01010101

    num = ((num & even) >> 1) | ((num & odd) << 1);

    return bitset<8>(num).to_string();
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll even = 170;
    ll odd = 85;

    assert(shiftOddEven("10101010").compare("01010101") == 0);
    assert(shiftOddEven("11100010").compare("11010001") == 0);

    return 0;
}