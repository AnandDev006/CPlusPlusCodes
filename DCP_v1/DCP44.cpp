/*
We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements A[i] and A[j] form 
an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). The 
array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

inline void debug(){
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif
}

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

void merge( vi &left, vi &right, vi &arr, ll &inversionsCount){
    ll nL = sz(left);
    ll nR = sz(right);
    ll i = 0, j = 0, k = 0;
    
    while( i < nL && j < nR){
        if( left[i] <= right[j]){
            arr[k++] = left[i++];
        } else {
            inversionsCount += ( nL - i );
            arr[k++] = right[j++];
        }
    }

    while( i < nL ){
        arr[k++] = left[i++];
    }

    while( j < nR ){
        arr[k++] = right[j++];
    }
}

void solveRec( vi &arr, ll &inversionsCount){
    
    ll len = sz(arr);
    if( len < 2 )
        return ;
    ll mid = len/2 ;
    vi left( arr.begin(), arr.begin() + mid);
    vi right( arr.begin() + mid , arr.begin() + len);
    solveRec( left, inversionsCount);
    solveRec( right, inversionsCount);
    merge( left, right, arr, inversionsCount);
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vi input = {5,4,3,2,1};
    ll inversionsCount = 0;
    solveRec( input, inversionsCount);

    cout << inversionsCount << endl;
    
    return 0;
}