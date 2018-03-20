#include <bits/stdc++.h>

using namespace std;

void constructTree(vector<int> inputData, vector<int> &segTree, int low, int high, int pos)
{
    if (low == high)
    {
        segTree[pos] = inputData[low];
        return;
    }
    int mid = (low + high) / 2;
    constructTree(inputData, segTree, low, mid, 2 * pos + 1);
    constructTree(inputData, segTree, mid + 1, high, 2 * pos + 2);
    segTree[pos] = min(segTree[2 * pos + 1], segTree[2 * pos + 2]);
}

int rangeMinQuery(vector<int> segTree, int qLow, int qHigh, int low, int high, int pos)
{
    if (qLow <= low && qHigh >= high) // total overlap
        return segTree[pos];
    else if (qHigh < low && qLow > high) // no overlap
        return INT_MAX;
    int mid = (low + high) / 2;
    return min(rangeMinQuery(segTree, qLow, qHigh, low, mid, 2*pos + 1), rangeMinQuery(segTree, qLow, qHigh, mid + 1, high, 2*pos + 2));
}

int main()
{
    int N;
    cin >> N;
    vector<int> inputData ( N);
    for (int i = 0; i < N; ++i)
        cin >> inputData[i];
    int segTreeSize = 2 * pow(2, (1 + (int)log2(N))) - 1;
    vector<int> segTree(segTreeSize, INT_MAX);
    constructTree(inputData, segTree, 0, N - 1, 0);
    int qLow, qHigh;
    cin >> qLow >> qHigh;
    cout << rangeMinQuery(segTree, 1, 2, 0, N - 1, 0) << endl;
    system("pause");
    return 0;
}