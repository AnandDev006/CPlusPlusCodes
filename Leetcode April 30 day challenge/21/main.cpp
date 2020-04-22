#include <bits/stdc++.h>

using namespace std;

#define PI 3.1415926535897932384626
#define dbg(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int INF = 1e9 + 5;
const int MOD = 1000000007;
const double ZERO = 10e-9;
const int N = 3e5, M = N;

void fileIO() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	// freopen("out", "w", stdout);
#endif
}

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> sz = binaryMatrix.dimensions();
        int H = sz[0], W = sz[1];
        if(H == 0 || W == 0)
            return -1;
        int h = 0, w = W-1;
        int bestCol = -1;
        while(h < H && w >= 0) {
            int val = binaryMatrix.get(h,w);
            if( val == 0 )
                h++;
            else {
                bestCol = w;
                w--;
            }
        }
        return bestCol;
    }
};

int main() {

	return 0;
}