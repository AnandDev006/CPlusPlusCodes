#include<bits/stdc++.h>

#define append push_back
#define X first
#define Y second
#define len(a) ((int)a.size())
#define rd(x) scanf("%d", &x)
#define wt(x) printf("%d ", x)

using namespace std;

typedef long long ll;
typedef pair<int,int> pi2;
typedef pair<int,pi2> pi3;
typedef pair<pi2,pi2> pi4;
typedef vector<int> vi;
typedef vector<pi2> vi2;
typedef vector<pi3> vi3;
typedef vector<pi4> vi4;

int solve( set<int> steps, int numOfSteps){
    vi memoTable(numOfSteps + 1, 0);

    memoTable[0] = 1;
    for( int i = 1 ; i <= numOfSteps ; ++i){
        for( auto step :steps){
            if( step > i)
                continue;
            
            memoTable[i] += memoTable[i-step];
        }
    }

    return memoTable[numOfSteps];
}

int main(){
    set<int> steps = {1,3,5};
    int numOfSteps;
    cin >> numOfSteps;

    cout << solve( steps, numOfSteps) << endl;

    return 0;
}