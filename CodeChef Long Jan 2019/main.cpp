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

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef long long ll;

void fun1(){
    int n;
    cin >> n;
    cin >> ws;
    string s;
    
    while(n--){
        getline( cin, s);
        s = " " + s + " ";
        if( s.find(" not ") == string::npos )
            cout << "regularly fancy" << endl;
        else
            cout << "Real Fancy" << endl;
    }
}

int main(){

    return 0;
}