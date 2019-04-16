/*
	author : Anand
	Given a list of integers, return the largest product that can be made by multiplying any three integers.
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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector< ll> input = { -10, -10, 5, 2};

	ll maxA, maxB, maxC, minA, minB;
	maxA = maxB = maxC = INT_MIN;
	minA = minB = INT_MAX;
	for( int i = 0 ; i < sz(input) ; ++i ) {
		if( input[i] > maxA) {
			maxC = maxB;
			maxB = maxA;
			maxA = input[i];
		} else if( input[i] > maxB) {
			maxC = maxB;
			maxB = input[i];
		} else if( input[i] > maxC) {
			maxC = input[i];
		}

		if( input[i] < minA){
			minB = minA;
			minA = input[i];
		} else if( input[i] < minB) {
			minB = input[i];
		}
	}

	cout << max( minA * minB * maxA, maxA * maxB * maxC) << endl;

	return 0;
}