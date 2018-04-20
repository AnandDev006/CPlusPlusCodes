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
    else if (qHigh < low || qLow > high) // no overlap
        return INT_MAX;
    int mid = (low + high) / 2;
    return min( rangeMinQuery(segTree, qLow, qHigh, low, mid, 2 * pos + 1),
                rangeMinQuery(segTree, qLow, qHigh, mid + 1, high, 2 * pos + 2));
}

void updateSegTreeLazy( vector<int> segTree, vector<int> lazy, int startRange, int endRange, int delta, int low, int high, int pos){
    if( low > high)
        return;
    
    if(lazy[pos] != 0){     // check if there are pending propogations
        segTree[pos] += lazy[pos];
        if( low != high){   // if not leaf node
            lazy[2*pos +1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if( startRange > high || endRange < low){   // no overlap
        return;
    }

    if( startRange <= low && endRange >= high){ // total overlap
        segTree[pos] += delta;
        if( low != high){
            lazy[2*pos +1] += delta;
            lazy[2*pos + 2] += delta;
        }
        return;
    }

    // partial overlap
    int mid = ( low + high)/2;
    updateSegTreeLazy( segTree, lazy, startRange, endRange, delta, low, mid, 2*pos + 1);
    updateSegTreeLazy( segTree, lazy, startRange, endRange, delta, mid + 1, high, 2*pos + 2);
    segTree[pos] = min( segTree[2*pos + 1], segTree[2*pos + 2]);
}

int rangeMinQueryLazy( vector<int> segTree, vector<int> lazy, int qLow, int qHigh, int low, int high, int pos){
    if( low > high)
        return INT32_MAX;

    if( lazy[pos] != 0){
        segTree[pos] += lazy[pos];
        if( low != high){
            lazy[2*pos + 1] += lazy[pos];
            lazy[2*pos + 2] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    if( qLow > high || qHigh < low){    // no overlap
        return INT32_MAX;
    }

    if( qLow <= low && qHigh >= high){  // total overlap
        return segTree[pos];
    }

    int mid = ( low + high)/2;
    return min( rangeMinQueryLazy( segTree, lazy, qLow, qHigh, low, mid, 2*pos + 1),
                rangeMinQueryLazy( segTree, lazy, qLow, qHigh, mid + 1, high, 2*pos + 2));
}

int main()
{
    int N;
    cin >> N;
    vector<int> inputData(N);
    for (int i = 0; i < N; ++i)
        cin >> inputData[i];
    int segTreeSize = 2 * pow(2, (1 + (int)log2(N))) - 1;
    vector<int> segTree(segTreeSize, INT_MAX);
    constructTree(inputData, segTree, 0, N - 1, 0);
    int qLow, qHigh;
    int T;
    cin >> T;
    while( T--){
        cin >> qLow >> qHigh;
        cout << rangeMinQuery(segTree, qLow, qHigh, 0, N - 1, 0) << endl;
    }
    return 0;
}