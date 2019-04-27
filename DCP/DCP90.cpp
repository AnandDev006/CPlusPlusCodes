/*
	author : Anand
    Given an integer n and a list of integers l, write a function that randomly 
    generates a number from 0 to n-1 that isn't in l (uniform)
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

vector< ll > finalNumPool;
ll finalNumPoolLen;


void generateRandomNumSeed( ll n, const vector< ll > &excludeList ) {
	unordered_set< ll > numSet;
	for( ll i = 0 ; i < n ; ++i) {
		numSet.insert( i);
	}
	for( ll num : excludeList) {
		numSet.erase( num);
	}
	srand (time(NULL));
	copy( numSet.begin(), numSet.end(), back_inserter( finalNumPool));
	finalNumPoolLen = sz(finalNumPool);
}

ll generateRandomNum() {
	return finalNumPool[ rand() % finalNumPoolLen];
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	generateRandomNumSeed( 15, vector< ll > ({ 1,5,6,9,8,3,2}));

	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;
	cout << generateRandomNum() << endl;

	return 0;
}