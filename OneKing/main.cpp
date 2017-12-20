// https://www.codechef.com/problems/ONEKING

#include <bits/stdc++.h>

using namespace std;

struct st{
    int l;
    int r;
};

auto comp1= []( st a, st b){ return a.r < b.r ;};
auto comp2= []( st a, st b){ return a.l > b.l ;};


int main(){
    int T;
    cin >> T;
    while( T--) {
        int n;
        st kingdom[100005];
        cin >> n;
        priority_queue< st, vector< st>, decltype( comp2)> PQ(comp2);
        for( int i = 0 ; i < n ; ++i ) {
            cin >> kingdom[i].l >> kingdom[i].r;
            PQ.push( kingdom[i]);
        }
        sort( kingdom, kingdom + n, comp1);

        int counter = 0;
        set< pair< int, int>> seen;

        for( int i = 0 ; i < n ; ++i){
            if( seen.find( make_pair( kingdom[i].l, kingdom[i].r) ) != seen.end() )
                continue;
            ++counter;
            while( !PQ.empty()){
                if( PQ.top().l > kingdom[i].r )
                    break;
                seen.insert( make_pair( PQ.top().l, PQ.top().r));
                PQ.pop();
            }
        }
        cout << counter << endl;
    }
}