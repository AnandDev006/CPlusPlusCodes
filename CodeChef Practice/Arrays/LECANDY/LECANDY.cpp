#include<bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    int N, C;
    int temp, sum;
    while( T--){
    	cin >> N >> C;
    	sum = 0;
    	while( N--){
    		cin >> temp;
    		sum += temp;
    	}
    	if( sum > C)
    		cout << "NO" << endl;
    	else
    		cout << "YES" << endl;
    }
    return 0;
}