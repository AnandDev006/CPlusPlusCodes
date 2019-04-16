/*
	author : Anand
	On our special chessboard, two bishops attack each other if they share the same diagonal. 
	This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.
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
typedef pair< ll, ll> ii;

void addNewBishop( ii newBishopPosition, ll boardSize,  vector< ii > &attackPositions, ll &count) {
	
	for( ii attackPosition : attackPositions) {
		if( attackPosition == newBishopPosition) {
			++count;
		}
	}

	ii pos = newBishopPosition;
	while( pos.X > 0 && pos.Y > 0 ) {
		--pos.X;
		--pos.Y;
		attackPositions.push_back( pos);
	}
	ii pos = newBishopPosition;
	while( pos.X > 0 && pos.Y < boardSize - 1 ) {
		--pos.X;
		++pos.Y;
		attackPositions.push_back( pos);
	}
	ii pos = newBishopPosition;
	while( pos.X < boardSize - 1 && pos.Y > 0 ) {
		++pos.X;
		--pos.Y;
		attackPositions.push_back( pos);
	}
	ii pos = newBishopPosition;
	while( pos.X < boardSize - 1 && pos.Y < boardSize - 1 ) {
		++pos.X;
		++pos.Y;
		attackPositions.push_back( pos);
	}
}

ll numOfBishopAttacks( const vector< pi > &bishopPositions, ll boardSize) {
	vector< ii > attackPositions;
	ll count = 0;
	for( ii position : bishopPositions) {
		addNewBishop( position, boardSize, attackPositions, count);
	}
	return count;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector< ii > bishopPositions = { (0, 0), (1, 2), (2, 2), (4, 0) };
	ll boardSize = 5;

	cout << numOfBishopAttacks( bishopPositions, boardSize) << endl;

	return 0;
}