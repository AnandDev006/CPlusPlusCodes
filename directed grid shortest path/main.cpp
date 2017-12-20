#include <iostream>
#include <map>
#include <vector>

#define n 4
#define m 5

using namespace std;

vector<int> d(n*m , INT32_MAX);
map<pair<int,int>,int> w;

void read() {
    for( int i = 0 ; i < (m-1)*n + (n-1)*m ; ++i ){
        cin >> w[make_pair(i,i+1)] >> w[make_pair(i,i+m)];
        if( i+1 % 5 != 0 )
            w.erase(make_pair(i,i+1));
        if( i+1 > (n-1)*m )
            w.erase(make_pair(i,i+m));
    }
}

void sPath(pair<int,int> s){
    int dTop, dLeft;
    for( int i = 0 ; i < n ; ++i ){
        for( int j = 0 ; j < m ; ++j ) {
            if ( i == 0 )
                dTop = 0;
            else
                dTop = d[(i-1)*m + j] + w[make_pair( (i-1)*m + j , i*m + j ) ];
            if( j == 0 )
                dLeft = 0 ;
            else
                dLeft = d[i*m + j - 1] + w[make_pair( i*m + j - 1 , i*m + j )];
            d[i*m + j] = min( dTop, dLeft) ;
            if( i == s.first && j == s.second ) {
                cout << d[i * m + j] << endl;
                return;
            }
        }
    }
}

int main() {
    read();
    pair<int,int> x ;
    cin >> x.first >> x.second ;
    sPath(x);
    return 0;
}