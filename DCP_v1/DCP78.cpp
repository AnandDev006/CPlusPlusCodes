/*
	author : Anand
	Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.
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

void makeMergedList( vector< ll > input [], ll k) {
	vector< ll > headList( k, 0);

	vector< ll > mergedList;
	ll completed = 0;
	while(completed < k) {
		ll minim = INT_MAX;
		ll minHead = -1;
		for( ll i = 0 ; i < k ; ++i ) {
			if( headList[i] < sz(input[i]) && input[i][headList[i]] < minim) {
				minim = input[i][headList[i]];
				minHead = i;
			}
		}
		mergedList.push_back(minim);
		++headList[minHead];
		if( headList[minHead] >= sz(input[minHead])) {
			++completed;
		}
	}
	for( ll x : mergedList ){ 
		cout << x << " -> ";
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll k = 3;
	vector< ll > input [k] = {
		{ 1, 2, 3, 4},
		{ 3, 4, 5},
		{ 2, 4, 6, 9}
	};

	makeMergedList( input, k);

	return 0;
}