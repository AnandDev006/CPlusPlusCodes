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

ll rand5(){
    return rand()%5 + 1;
}

ll rand7(){

    // give random value from 1 to 25 ( both inclusive )
    ll randomVal = 5 * rand5() + rand5() - 5;
    if( randomVal < 22){
        cout << r1 << " : " << r2 << endl;
        return randomVal % 7 + 1 ;
    }
    return rand7();
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    srand(time(NULL));
    cout << rand7() << endl;
    
    return 0;
}