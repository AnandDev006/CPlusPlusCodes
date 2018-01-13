#include <bits/stdc++.h>

using namespace std;

int prefixSuffix( string S){
    int N = S.size();
    int *DP = new int [N];
    DP[0] = 0;
    int j = 0 , i = 1 ;
    while( i < N ){
        if( S[j] == S[i] ){
            DP[i] = j + 1 ;
            ++j;
            ++i;
        }
        else {
            if( j == 0 ) {
                DP[i] = 0;
                ++i;
            } else{
                j = DP[j-1];
            }
        }
    }
    return DP[N-1];
}

int main() {
    cout << prefixSuffix( "qgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbqqqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbbqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbqqqgqbqgqlqjqgvqgqbqwqgdqgqbqiqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbqqqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbbqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqmqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbqqqgqbqgqlqjqgvqgqbqwqgdqgqbqgtqgqbqgqlqjqgvqgqbqwqgdqgqbqgqlqjqgvqgqbqqqgqbqgqlqjqgvqgq") << endl;
    return 0;
}