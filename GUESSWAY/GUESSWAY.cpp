#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

	ll h, n;
	int T;
	cin >> T;
	while( T--){
		cin >> h >> n;
		ll numNode = ll(pow(2,h+1)) - 1;
		bool visited[numNode+10];
		memset( visited, false, sizeof(visited));

		ll curr = 1;
		bool pos = false; // false = left , true = right
		ll leaf = ll(pow(2,h)) - 1;
		n = n + leaf;
		ll count = 0;
		while(true){
			if( ( visited[curr*2] && visited[curr*2 + 1] ) || curr > leaf ){ 	// if left and right are visited
				curr = curr/2;
			}
			else if( pos == false ){ 		// if L
				if( !visited[2*curr] ){			// if L not visited
					curr = 2*curr;
					pos = !pos;
				}
				else{ 							// if L is visited
					curr = 2*curr + 1;
				}
			}
			else if( pos == true ){ 		// if R
				if( !visited[2*curr + 1]){		// if R not visited
					curr = 2*curr + 1;
					pos = !pos;
				}
				else{							// if R is visited
					curr = 2*curr;
				}
			}
			visited[curr] = true; 			// mark current node as visited
			++count;
			if( curr == n ){
				break;
			}		
		}
		cout << count << endl;
	}
	return 0;
}