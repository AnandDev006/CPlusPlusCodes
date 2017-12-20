#include <iostream>
#include <list>
#include <set>
#include <cmath>

using namespace std ;

typedef pair<double,double> pt ;
typedef pt tri[3] ;
typedef list<pair<double ,double >>::iterator it ;
list<pt> points ;

set<tri> triangles ;

double distance( pt A , pt B ){
    double res = sqrt( pow( A.first - B.first , 2 ) + pow( A.second - B.second , 2 ) ) ;
    return res ;
}
/*
void getPts( it &start , it &mid , it &end , set<it> P ){
    double minD = INT32_MAX ;
    for( it s : P ){
        if( distance( *s , *(s.+2) ) < minD ){
            start = s ;
            mid = s.+1 ;
            end = s.+2 ;
            minD = distance( *s , *(s.+2) ) ;
        }
        if( ( distance( *s , *(s.-2) )) < minD ){
            start = s ;
            mid = s.-1 ;
            end = s.-2 ;
            minD = distance( *s , *(s.-2) ) ;
        }
    }
}
*/
void makeTriangles( it start , it mid ,it end ){
    tri temp ;
    temp[0].first = start->first ;
    temp[1].first = mid->first ;
    temp[2].first = end->first ;
    temp[0].second = start->first ;
    temp[1].second = mid->second ;
    temp[2].second = end->second ;
    triangles.insert( temp ) ;
}

void getEdge( set<it> &P ){
    it start , mid , end ;
   // getPts( start , mid , end , P ) ;
    P.insert( end ) ;
    P.erase( mid ) ;
    points.erase( mid ) ;

}

void Tri(){
    set<it> P ;
    P.insert( points.begin() ) ;
    while( points.size() > 3 )
        getEdge(P) ;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}