/*
    author : Anand
    You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string. Determine whether the parentheses are balanced.
    For example, (()* and (*) are balanced. )*( is not balanced.
    SOLUTION : https://leetcode.com/articles/valid-parenthesis-string/   GREEDY SOLUTION
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
typedef pair< ll, ll > ii;

void printArray(const vector<ll> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

bool isParanthesesBalanced(string S){
    ll lo = 0, hi = 0;
    for( char c : S ) {
        lo = lo + ( c == '(' ? 1 : -1 );
        hi = hi + ( c != ')' ? 1 : -1 );
        if( hi < 0 ){
            break;
        }
        lo = max( lo, ll(0));
    }
    return lo == 0; 
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    assert( isParanthesesBalanced("(()*") );
    assert( isParanthesesBalanced("(()*") );
    assert( !isParanthesesBalanced(")*(")) ;
    assert( isParanthesesBalanced("(()())") );
    assert( isParanthesesBalanced("(***)") );
    assert( !isParanthesesBalanced("(())((())()()(*)(*()(())())())()()((()())((()))(*") );

    return 0;
}