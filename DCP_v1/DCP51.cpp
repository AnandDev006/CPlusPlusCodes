/*

Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, write 
a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.

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

// Given function
int randomNum(int k){
    return k;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vi cards;
    for( ll i = 1 ; i <= 52 ; ++i )
        cards.push_back(i);

    srand(time(0));

    for( ll pos = 51 ; pos > 0 ; --pos){
        // filling position cards[pos] with a random pick from positions between 0 and pos
        swap( cards[( rand() % pos )], cards[pos] );
    }

    for( int x : cards)
        cout << x << " ";
    
    return 0;
}