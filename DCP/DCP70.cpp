/*
	author : Anand
    A number is considered perfect if its digits sum up to exactly 10.

    Given a positive integer n, return the n-th perfect number.
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

	/*
		the sequence 19, 28, 37 .... is an AP with a = 19 and d = 9
		so we need to find nth element of AP.
		but there are anomalies like 100, 1000, ... multiples fo 10.
		no of anomalies = floor(log10(n) - 1)
		=> ans = (19 * (n-1) * 9) + 9 * floor(log10(n) - 1)
	*/

	ll n = 11;
	cout << ( 19 + ( n - 1 ) * 9 ) + 9 * ((int)(log10(n))) << endl;

	return 0;
}