//https://www.codechef.com/problems/CODIE

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

int n, K, a, b;

bool isValid( int x, int y, int B){
	if( y < 1 || y > K )
		return false;
	else if( ( x == B ) && ( y <= a || y >= b ) )
		return false;
	else if( x == n  && y != K/2 )
		return false;

	return true;
}

int fun( int x, int y, int B){
	if( x == n && y == K/2 )
		return 1;
	const int moveY[] = { 1, 0, -1};
	int lSum = 0; 
	for( int i = 0 ; i < 3 ; ++i ){
		if( isValid( x + 1, y + moveY[i], B) ){
			lSum += fun( x + 1, y + moveY[i], B);
		}
	}
	return lSum;
}

int caller(){
	int sum = 0;
	for( int i = 2 ; i < n ; ++i ){
		sum += fun( 1, n/2, i);
	}
	return sum;
}

int main(){

	cin >> n >> K >> a >> b;
	cout << caller() << endl;
	return 0;
}