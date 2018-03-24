// https: //www.codechef.com/problems/FLIPCOIN/

#include <bits/stdc++.h>

#define heads true
#define tails false

using namespace std;

void constructSegTree(vector<bool> arr, vector<int> &segTree, int low, int high, int pos)
{
    if (low == high)
    {
        segTree[pos] = arr[low] == heads ? 1 : 0;
        return;
    }

    int mid = (low + high) / 2;
    constructSegTree(arr, segTree, low, mid, 2 * pos + 1);
    constructSegTree(arr, segTree, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

void updateSegTreeLazy(vector<int> &segTree, vector<bool> &lazy, int startRange, int endRange, int low, int high, int pos)
{
    if (low > high)
        return;

    if (lazy[pos])
    {
        segTree[pos] = (high - low + 1) - segTree[pos];
        if (low != high)
        {
            lazy[2 * pos + 1] = true;
            lazy[2 * pos + 2] = true;
        }
        lazy[pos] = false;
    }

    if (startRange > high || endRange < low)
    { // no overlap
        return;
    }

    if (startRange <= low && endRange >= high)
    { // total overlap
        segTree[pos] = (high - low + 1) - segTree[pos];
        if (low != high)
        {
            lazy[2 * pos + 1] = true;
            lazy[2 * pos + 2] = true;
        }
        return;
    }

    // partial overlap
    int mid = (low + high) / 2;
    updateSegTreeLazy(segTree, lazy, startRange, endRange, low, mid, 2 * pos + 1);
    updateSegTreeLazy(segTree, lazy, startRange, endRange, mid + 1, high, 2 * pos + 2);
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int rangeMinQueryLazy(vector<int> &segTree, vector<bool> &lazy, int qLow, int qHigh, int low, int high, int pos)
{
    if (low > high)
        return 0;

    if (lazy[pos])
    {
        segTree[pos] = (high - low + 1) - segTree[pos];
        if (low != high)
        {
            lazy[2 * pos + 1] = true;
            lazy[2 * pos + 2] = true;
        }
        lazy[pos] = false;
    }

    if (qLow > high || qHigh < low)
    { // no overlap
        return 0;
    }

    if (qLow <= low && qHigh >= high)
    { // total overlap
        return segTree[pos];
    }

    // partial overlap
    int mid = (low + high) / 2;
    return rangeMinQueryLazy(segTree, lazy, qLow, qHigh, low, mid, 2 * pos + 1) +
           rangeMinQueryLazy(segTree, lazy, qLow, qHigh, mid + 1, high, 2 * pos + 2);
}

int main()
{

    int N, Q;
    cin >> N >> Q;
    vector<bool> arr(N, tails);

    int segTreeSize = 2 * pow(2, (1 + (int)log2(N))) - 1;
    vector<int> segTree(segTreeSize, 0);
    vector<bool> lazy(segTreeSize, false);
    constructSegTree(arr, segTree, 0, N - 1, 0);
    int x, A, B;
    while (Q--)
    {
        cin >> x >> A >> B;
        if (x == 0)
        { // update segTree
            updateSegTreeLazy(segTree, lazy, A, B, 0, N - 1, 0);
        }
        else if (x == 1)
        { // query segTree
            cout << rangeMinQueryLazy(segTree, lazy, A, B, 0, N - 1, 0) << endl;
        }
    }
    return 0;
}