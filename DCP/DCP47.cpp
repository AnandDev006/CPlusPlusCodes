/*
Given a array of numbers representing the stock prices of a company in chronological order, write a function that 
calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.
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

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vi arr = {9, 11, 8, 5, 7, 10};
    ll nA = sz(arr), i;
    
    vi minimaPos = {0}, maximaPos = {0};
    for( i = 1 ; i < nA -1 ; ++i){
        // maxima
        if( arr[i-1] < arr[i] && arr[i+1] < arr[i])
            maximaPos.push_back(i);
        
        // minima
        if( arr[i-1] > arr[i] && arr[i+1] > arr[i])
            minimaPos.push_back(i);
    }
    minimaPos.push_back(nA - 1);
    maximaPos.push_back(nA - 1);
    
    ll maxProfit = 0, buy = 0, sell = 0;
    
    for( ll minima : minimaPos){
        for( ll maxima : maximaPos){
            if( maxima <= minima )
                continue;
            if( arr[maxima] - arr[minima] > maxProfit){
                buy = arr[minima];
                sell = arr[maxima];
                maxProfit = arr[maxima] - arr[minima];

            }
        }
    }

    cout << "Buy : " << buy << " \t Sell : " << sell << endl;
    cout << "Profit : " << maxProfit << endl;

    return 0;
}