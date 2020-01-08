/*
 author : Anand

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

char toss_0_or_1_biased();

char toss_0_or_1_unbiased() {
	char prev = toss_0_or_1_biased();
	char curr;
	while( true) {
		curr = toss_0_or_1_biased();
		if( prev == '0' && curr = '1' ) {
			return '0';
		}
		if( prev = '1' && curr = '0' ) {
			return '1';
		}
		prev = curr;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/* 	let probability of 0 = x ( x != 0.5 );
		=> P(0) = x , P(1) = 1-x
		Therefore in 2 consecutives tosses
		=> P(00) = x^2, P(11) = (1-x)^2, P(01) = P(10) = x(1-x)
		We have 2 distinguishable events with same probability
		Suppose event 01 is takes as 0 and 10 as 1
		=> Make multiple tosses and scan through to find the first 01 or 10 sequence,
			since they are equally likely, their initial occurance is quivalent to a single toss to find 0 or 1
	*/

	cout << toss_0_or_1_unbiased() << endl;

	return 0;
}