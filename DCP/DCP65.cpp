/*
 author : Anand
 Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.
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

typedef long long ll;
typedef vector< ll > vi;
typedef vector< vi > vvi;
typedef pair< ll,ll > ii;

void printSpiral( const vector< vector< ll > > &mat, ll rows, ll cols) {
    ll top = 0, bottom = rows - 1, left = 0, right = cols - 1;
    while( top < bottom && left < right ) {
        for( ll j = left ; j <= right ; ++j ) {
            cout << mat[top][j] << endl;
        }
        ++top;
        for( ll i = top ; i <= bottom ; ++i ) {
            cout << mat[i][right] << endl;
        }
        --right;
        for( ll j = right ; j >= left ; --j ) {
            cout << mat[bottom][j] << endl;
        }
        --bottom;
        for( ll i = bottom ; i >= top ; --i ) {
            cout << mat[i][left] << endl ;
        }
        ++left;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< vector< ll > > mat = {
                            {1,  2,  3,  4,  5},
                            {6,  7,  8,  9,  10},
                            {11, 12, 13, 14, 15},
                            {16, 17, 18, 19, 20}
                            };

    printSpiral(mat, sz(mat), sz(mat[0]));

    return 0;
}