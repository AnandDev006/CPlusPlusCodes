/*
	author : Anand
	Given a list of possibly overlapping intervals, return a new list of intervals where 
	all overlapping intervals have been merged.
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

void merge_overlaps(vector< pair< ll, ll > > intervals) {
	set< ll > interval_starts, interval_ends;
	for( pair< ll, ll > interval : intervals ) {
		interval_starts.insert( interval.X);
		interval_ends.insert( interval.Y);
	}
	ll minStart = *interval_starts.begin();
	ll maxEnd = *interval_ends.rbegin();
	ll currentActive = 0;
	vector< ll > instantStatus = {currentActive};
	for( ll i = minStart ; i <= maxEnd ; ++i) {
		if( present(interval_starts, i)) {
			++currentActive;
		}
		if( present(interval_ends, i)) {
			--currentActive;
		}
		instantStatus.push_back(currentActive);
	}
	vector< pair< ll, ll > > merged;
	ll begin = 0, end = 0;
	for( ll i = minStart ; i < maxEnd - minStart + 2 ; ++i ) {
		if( instantStatus[i] && !instantStatus[i-1]) {
			begin = i;
		}
		if( !instantStatus[i] && instantStatus[i-1]) {
			end = i;
			merged.push_back( mp(begin, end));
		}
	}
	for( auto p : merged) {
		cout << "( " << p.X << ", " << p.Y <<" ), " ;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	merge_overlaps(vector< pair< ll, ll > > ({ {1, 3}, {5, 8}, {4, 10}, {20, 25} }));

	return 0;
}