#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    vector<int> arr(N);
    for( int i = 0 ; i < N ; ++i )
        cin >> arr[i];
    
    set<int> maxHeap;
    vector<int> leftMax(N);
    vector<int> rightMax(N);

    leftMax[0] = 0;
    maxHeap.insert(arr[0]);
    for (int i = 1; i < N; ++i){
        leftMax[i] = *maxHeap.rbegin();
        maxHeap.insert(arr[i]);
    }

    maxHeap.clear();

    rightMax[N-1] = 0;
    maxHeap.insert(arr[N-1]);
    for( int i = N-2 ; i >= 0 ; --i){
        rightMax[i] = *maxHeap.rbegin();
        maxHeap.insert(arr[i]);
    }

    int watercollected = 0;
    int local;
    for( int i = 1 ; i < N-1 ; ++i){
        local = min(leftMax[i], rightMax[i]) - arr[i];
        watercollected += local > 0 ? local : 0;
    }

    cout << watercollected << endl;

    return 0;
}