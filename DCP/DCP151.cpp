/*
    author : Anand
    Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given 
    pixel and all adjacent same colored pixels with C.

    For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:

    B B W
    W W W
    W W W
    B B B
    Becomes

    B B G
    G G G
    G G G
    B B B
*/

#include<bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a,b) make_pair( a, b)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair< ll, ll > ii;

template<typename T>
void printArray(const vector<T> &arr) {
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i) {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

template<typename T>
bool isEqual(const vector<T> &v1, const vector<T> &v2) {
    auto pair = std::mismatch(v1.begin(), v1.end(), v2.begin());
    return (pair.first == v1.end() && pair.second == v2.end());
}

bool isValid( vector< vector< char > > matrix, char color, ll x, ll y, set< pair< ll, ll > > visited) {
    ll rows = sz(matrix);
    ll cols = sz(matrix[0]);

    return ( x >= 0 && x < rows && y >=0 && y < cols && matrix[x][y] == color && !present( visited, mp( x, y)) );
}

void reColor( vector< vector< char > > &matrix, char color, pair< ll, ll> loc) {

    queue< pair< ll, ll> > pos;
    pos.push( loc);
    
    int nX[]= { 0, 1, 0, -1};
    int nY[] = { 1, 0, -1, 0};

    set< pair< ll, ll > > visited;

    while( !pos.empty()) {
        pair< ll, ll > pixel = pos.front();
        visited.insert( pixel);
        pos.pop();
        for( int i = 0 ; i < 4 ; ++i ) {
            if( isValid( matrix, matrix[pixel.X][pixel.Y], pixel.X + nX[i], pixel.Y + nY[i], visited)) {
                pos.push( mp( pixel.X + nX[i], pixel.Y + nY[i]));
            }
        }
        matrix[pixel.X][pixel.Y] = color;
    }

    for( vector< char > arr : matrix) {
        printArray( arr);
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector< vector< char > > matrix = { { 'B', 'B', 'W' }, { 'W', 'W', 'W' }, { 'W', 'W', 'W' }, { 'B', 'B', 'B' } };

    reColor( matrix, 'G', mp( 2, 2));

    return 0;
}