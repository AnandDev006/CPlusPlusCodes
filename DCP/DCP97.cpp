/*
    author : Anand
    Write a map implementation with a get function that lets you retrieve the value of a key at a particular time.

    It should contain the following methods:

    set(key, value, time): sets key to value for t = time.
    get(key, time): gets the key at t = time.

    The map should work like this. If we set a key at a particular time, it will maintain that value forever 
    or until it gets set at a later time. In other words, when we get a key at a time, it should return the 
    value that was set for that key set at the most recent time.
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair(a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;

class newMap {
    unordered_map< ll, map< ll, ll > > table;
    public:
    void set( ll key, ll value, ll time) {
        table[key][time] = value;
    }
    ll get( ll key, ll time) {
        auto x = table[key].lower_bound(time);
        if( table[key].find( time) == table[key].end()) {
            --x;
            if( (*x).first > time ) {
                return NULL;
            }
        }
        return (*x).second;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    newMap* m1 = new newMap();
    m1->set( 1, 1, 0);
    m1->set( 1, 2, 2);
    assert( m1->get( 1, 1) == 1 );
    assert( m1->get( 1, 3) == 2 );

    newMap* m2 = new newMap();
    m2->set( 1, 1, 5);
    assert( m2->get( 1, 0) == NULL );
    assert( m2->get( 1, 10) == 1 );

    newMap* m3 = new newMap();
    m3->set( 1, 1, 0);
    m3->set( 1, 2, 0);
    assert( m3->get( 1, 0) == 2 );

    return 0;
}