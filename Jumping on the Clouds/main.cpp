#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    int k;
    int E=100;
    int i=0;

    cin >> n >> k;

    vector<int> c(n);

    for(int c_i = 0;c_i < n;c_i++){
        cin >> c[c_i];
    }

    do{
        i=(i+k)%n;
        --E;
        if(c[i]==1)
            E-=2;
    }while (i!=0);

    cout << E;

    return 0;
}
