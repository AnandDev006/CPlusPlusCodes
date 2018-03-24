#include <bits/stdc++.h>

using namespace std;

bool isPrime(int a)
{
    if (a == 1)
        return true;
    for (int i = 2; i <= sqrt(a); ++i)
        if (a % i == 0)
            return false;

    return true;
}

int getSegTreeSize(int N)
{
    if (!(N & (N - 1)))
        return 2 * N - 1;
    else
    {
        return 2 * (pow(2, int(log2(N)) + 1)) - 1;
    }
}

void makeSegTree(vector<int> arr, vector<int> &segTree, int low, int high, int pos)
{
    if (low == high)
    {
        segTree[pos] = isPrime(arr[low]) ? 1 : 0;
        return;
    }
    int mid = (low + high) / 2;
    makeSegTree(arr, segTree, low, mid, 2 * pos + 1);
    makeSegTree(arr, segTree, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

void UpdateSegTree(vector<int> &segTree, int L, int R, int num, int low, int high, int pos)
{
    if (low > high)
        return;

    if (L > high || R < low)
    { // no overlap
        return;
    }

    if (L <= low && R >= high)
    { // total overlap
        segTree[pos] = isPrime(num) ? 1 : 0;
        return;
    }

    // partial overlap
    int mid = (low + high) / 2;
    UpdateSegTree(segTree, L, R, num, low, mid, 2 * pos + 1);
    UpdateSegTree(segTree, L, R, num, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int QuerySegTree(vector<int> segTree, int L, int R, int low, int high, int pos)
{
    if (low > high)
        return 0;

    if (L > high || R < low) // no overlap
        return 0;

    if (L <= low && R >= high) // total overlap
        return segTree[pos];

    // partial overlap
    int mid = (low + high) / 2;
    return QuerySegTree(segTree, L, R, low, mid, 2 * pos + 1) +
           QuerySegTree(segTree, L, R, mid + 1, high, 2 * pos + 2);
}

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i)
        cin >> arr[i];

    int segTreeSize = getSegTreeSize(N);
    vector<int> segTree(segTreeSize, 0);
    makeSegTree(arr, segTree, 0, N - 1, 0);
    int x, A, B;
    while (Q--)
    {
        cin >> x >> A >> B;
        if (x == 0)
        { // update
            UpdateSegTree(segTree, A, A, B, 0, N - 1, 0);
        }
        else if (x == 1)
        { // query
            cout << QuerySegTree(segTree, A, B, 0, N - 1, 0) << endl;
        }
    }
    return 0;
}