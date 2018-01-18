#include<bits/stdc++.h>

using namespace std;

int main(){

	int Ve, Vy, L, T;
	cin >> Ve >> Vy >> L >> T;
	float T1 = float(L/Ve);
	float T2 = float(L/(Ve + Vy));
	if( T1 - T2 >= T ){
		cout << "1.00" << endl;
	}
	else{
		cout << float((T1-T2)/T) << endl;
	}
	
	return 0;
}